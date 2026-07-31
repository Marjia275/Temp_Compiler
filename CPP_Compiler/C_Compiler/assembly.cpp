// ============================================================
// assembly.cpp
// ============================================================
#include "assembly.h"
#include <sstream>

using namespace std;

static string mnemonic(const string& op) {
    if (op == "+")  return "ADD";
    if (op == "-")  return "SUB";
    if (op == "*")  return "IMUL";
    if (op == "/")  return "IDIV";
    if (op == "%")  return "IMOD";
    if (op == ">")  return "CMPGT";
    if (op == "<")  return "CMPLT";
    if (op == ">=") return "CMPGE";
    if (op == "<=") return "CMPLE";
    if (op == "==") return "CMPEQ";
    if (op == "!=") return "CMPNE";
    if (op == "&&") return "AND";
    if (op == "||") return "OR";
    return "OP";
}

static vector<string> tokenize(const string& s) {
    vector<string> out;
    stringstream ss(s);
    string tok;
    while (ss >> tok) out.push_back(tok);
    return out;
}

std::vector<std::string> AssemblyGenerator::generate(const std::vector<std::string>& tac) {
    vector<string> out;

    for (const string& line : tac) {
        if (!line.empty() && line.back() == ':') {
            out.push_back(line);
            continue;
        }

        if (line.rfind("goto ", 0) == 0) {
            out.push_back("JMP " + line.substr(5));
            continue;
        }

        if (line.rfind("if ", 0) == 0) {
            size_t gotoPos = line.find(" goto ");
            string condPart = line.substr(3, line.find(" == 0") - 3);
            string label = line.substr(gotoPos + 6);
            out.push_back("CMP " + condPart + ", 0");
            out.push_back("JE " + label);
            continue;
        }

        if (line.rfind("print ", 0) == 0) {
            string arg = line.substr(6);
            if (!arg.empty() && arg.front() == '"') {
                out.push_back("; push format string " + arg);
            } else {
                out.push_back("MOV eax, " + arg);
            }
            out.push_back("CALL printf");
            continue;
        }

        if (line.rfind("return", 0) == 0) {
            if (line.size() > 6) out.push_back("MOV eax, " + line.substr(7));
            out.push_back("RET");
            continue;
        }

        size_t eqPos = line.find(" = ");
        if (eqPos != string::npos) {
            string dest = line.substr(0, eqPos);
            string rhs = line.substr(eqPos + 3);
            vector<string> toks = tokenize(rhs);

            if (toks.size() == 1) {
                out.push_back("MOV eax, " + toks[0]);
                out.push_back("MOV " + dest + ", eax");
            } else if (toks.size() == 2) {
                out.push_back("MOV eax, " + toks[1]);
                out.push_back("NEG eax");
                out.push_back("MOV " + dest + ", eax");
            } else if (toks.size() == 3) {
                out.push_back("MOV eax, " + toks[0]);
                out.push_back("MOV ebx, " + toks[2]);
                out.push_back(mnemonic(toks[1]) + " eax, ebx");
                out.push_back("MOV " + dest + ", eax");
            }
            continue;
        }

        out.push_back("; " + line);
    }

    return out;
}
