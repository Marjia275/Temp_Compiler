// ============================================================
// codegen.cpp
// ============================================================
#include "codegen.h"
#include <sstream>
#include <cctype>

using namespace std;

static string opName(const string& op) {
    if (op == "+")  return "ADD";
    if (op == "-")  return "SUB";
    if (op == "*")  return "MUL";
    if (op == "/")  return "DIV";
    if (op == "%")  return "MOD";
    if (op == ">")  return "CMPGT";
    if (op == "<")  return "CMPLT";
    if (op == ">=") return "CMPGE";
    if (op == "<=") return "CMPLE";
    if (op == "==") return "CMPEQ";
    if (op == "!=") return "CMPNE";
    if (op == "&&") return "AND";
    if (op == "||") return "OR";
    if (op == "&")  return "BAND";
    if (op == "|")  return "BOR";
    if (op == "^")  return "BXOR";
    if (op == "<<") return "SHL";
    if (op == ">>") return "SHR";
    if (op == "-u") return "NEG";
    if (op == "!u") return "NOT";
    if (op == "~u") return "BNOT";
    return "OP";
}

static vector<string> tokenize(const string& s) {
    vector<string> out;
    size_t i = 0, n = s.size();
    while (i < n) {
        while (i < n && isspace((unsigned char)s[i])) i++;
        if (i >= n) break;
        if (s[i] == '"') {
            size_t j = i + 1;
            while (j < n && s[j] != '"') j++;
            if (j < n) j++; // include the closing quote
            out.push_back(s.substr(i, j - i));
            i = j;
        } else {
            size_t j = i;
            while (j < n && !isspace((unsigned char)s[j])) j++;
            out.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return out;
}

std::vector<std::string> CodeGenerator::generate(const std::vector<std::string>& tac) {
    vector<string> out;

    for (const string& line : tac) {
        // Label definition, e.g. "L1:"
        if (!line.empty() && line.back() == ':') {
            out.push_back(line);
            continue;
        }

        if (line.rfind("goto ", 0) == 0) {
            out.push_back("JMP " + line.substr(5));
            continue;
        }

        if (line.rfind("if ", 0) == 0) {
            // "if <cond> == 0 goto <label>"
            size_t gotoPos = line.find(" goto ");
            string condPart = line.substr(3, line.find(" == 0") - 3);
            string label = line.substr(gotoPos + 6);
            out.push_back("CMP " + condPart + ", 0");
            out.push_back("JE " + label);
            continue;
        }

        if (line.rfind("return", 0) == 0) {
            if (line.size() > 6) out.push_back("LOAD " + line.substr(7));
            out.push_back("RET");
            continue;
        }

        // Generic assignment: "x = a"  or  "x = a op b"
        size_t eqPos = line.find(" = ");
        if (eqPos != string::npos) {
            string dest = line.substr(0, eqPos);
            string rhs = line.substr(eqPos + 3);
            vector<string> toks = tokenize(rhs);

            if (toks.size() == 1) {
                out.push_back("LOAD " + toks[0]);
                out.push_back("STORE " + dest);
            } else if (toks.size() == 2) {
                // unary operator, e.g. "t1 = - a" or "t1 = ~ a"
                out.push_back("LOAD " + toks[1]);
                out.push_back(opName(toks[0] + "u"));
                out.push_back("STORE " + dest);
            } else if (toks.size() == 3) {
                out.push_back("LOAD " + toks[0]);
                out.push_back("LOAD " + toks[2]);
                out.push_back(opName(toks[1]));
                out.push_back("STORE " + dest);
            }
            continue;
        }

        // Anything unrecognized is passed through as a comment.
        out.push_back("; " + line);
    }

    return out;
}
