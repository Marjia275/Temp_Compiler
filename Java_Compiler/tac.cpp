
#include "tac.h"

using namespace std;

std::string TACGenerator::newTemp()  { return "t" + to_string(++tempCount); }
std::string TACGenerator::newLabel() { return "L" + to_string(++labelCount); }
void TACGenerator::emit(const std::string& instr) { lines.push_back(instr); }

// Makes a string literal safe to display on a single TAC line
// (turns a real embedded newline/tab back into visible "\n"/"\t").
static std::string escapeForDisplay(const std::string& s) {
    string out;
    for (char c : s) {
        if (c == '\n') out += "\\n";
        else if (c == '\t') out += "\\t";
        else if (c == '"') out += "\\\"";
        else out += c;
    }
    return out;
}

std::vector<std::string> TACGenerator::generate(ASTNode* program) {
    lines.clear();
    tempCount = 0;
    labelCount = 0;
    loopLabels.clear();
    genBlock(program);
    return lines;
}

void TACGenerator::genBlock(ASTNode* block) {
    if (!block) return;
    for (auto stmt : block->children) genStatement(stmt);
}

std::string TACGenerator::genExpr(ASTNode* node) {
    switch (node->type) {
        case NODE_NUM_INT:   return to_string(node->ival);
        case NODE_NUM_FLOAT: return to_string(node->fval);
        case NODE_CHAR:      return string("'") + node->cval + "'";
        case NODE_STRING:    return "\"" + escapeForDisplay(node->sval) + "\"";
        case NODE_BOOL:      return node->ival ? "true" : "false";
        case NODE_ID:        return node->sval;

        case NODE_UNOP: {
            string operand = genExpr(node->children[0]);
            string t = newTemp();
            emit(t + " = " + node->op + " " + operand);
            return t;
        }

        case NODE_PREINC: case NODE_POSTINC:
            emit(node->sval + " = " + node->sval + " + 1");
            return node->sval;

        case NODE_PREDEC: case NODE_POSTDEC:
            emit(node->sval + " = " + node->sval + " - 1");
            return node->sval;

        case NODE_BINOP: {
            string l = genExpr(node->children[0]);
            string r = genExpr(node->children[1]);
            string t = newTemp();
            emit(t + " = " + l + " " + node->op + " " + r);
            return t;
        }

        default:
            return "?";
    }
}

void TACGenerator::genStatement(ASTNode* stmt) {
    switch (stmt->type) {
        case NODE_VARDECL: {
            if (!stmt->children.empty()) {
                string v = genExpr(stmt->children[0]);
                emit(stmt->sval + " = " + v);
            }
            break;
        }

        case NODE_ASSIGN: {
            string v = genExpr(stmt->children[0]);
            emit(stmt->sval + " = " + v);
            break;
        }

        case NODE_COMPOUND_ASSIGN: {
            string v = genExpr(stmt->children[0]);
            string baseOp = stmt->op.substr(0, 1); // "+=" -> "+"
            emit(stmt->sval + " = " + stmt->sval + " " + baseOp + " " + v);
            break;
        }

        case NODE_IF: {
            string cond = genExpr(stmt->children[0]);
            bool hasElse = stmt->children.size() > 2 && stmt->children[2];
            string Lelse = hasElse ? newLabel() : "";
            string Lend = newLabel();

            emit("if " + cond + " == 0 goto " + (hasElse ? Lelse : Lend));
            genBlock(stmt->children[1]);
            if (hasElse) {
                emit("goto " + Lend);
                emit(Lelse + ":");
                genBlock(stmt->children[2]);
            }
            emit(Lend + ":");
            break;
        }

        case NODE_WHILE: {
            string Lstart = newLabel();
            string Lend = newLabel();
            emit(Lstart + ":");
            string cond = genExpr(stmt->children[0]);
            emit("if " + cond + " == 0 goto " + Lend);
            loopLabels.push_back({Lstart, Lend}); // continue -> Lstart, break -> Lend
            genBlock(stmt->children[1]);
            loopLabels.pop_back();
            emit("goto " + Lstart);
            emit(Lend + ":");
            break;
        }

        case NODE_FOR: {
            if (stmt->children[0]) genStatement(stmt->children[0]);
            string Lstart = newLabel();
            string Lcontinue = newLabel(); // where "continue" jumps: right before the update step
            string Lend = newLabel();
            emit(Lstart + ":");
            if (stmt->children[1]) {
                string cond = genExpr(stmt->children[1]);
                emit("if " + cond + " == 0 goto " + Lend);
            }
            loopLabels.push_back({Lcontinue, Lend});
            genBlock(stmt->children[3]);
            loopLabels.pop_back();
            emit(Lcontinue + ":");
            if (stmt->children[2]) genStatement(stmt->children[2]);
            emit("goto " + Lstart);
            emit(Lend + ":");
            break;
        }

        case NODE_BREAK:
            if (!loopLabels.empty()) emit("goto " + loopLabels.back().second);
            break;

        case NODE_CONTINUE:
            if (!loopLabels.empty()) emit("goto " + loopLabels.back().first);
            break;

        case NODE_PRINT: {
            string v = stmt->children.empty() ? "" : genExpr(stmt->children[0]);
            if (stmt->ival) {
                emit(v.empty() ? "println" : "println " + v);
            } else {
                emit("print " + v);
            }
            break;
        }

        case NODE_RETURN: {
            if (!stmt->children.empty()) {
                string v = genExpr(stmt->children[0]);
                emit("return " + v);
            } else {
                emit("return");
            }
            break;
        }

        case NODE_BLOCK:
            genBlock(stmt);
            break;

        default:
            // Bare expression statement, e.g. "a++;"
            genExpr(stmt);
            break;
    }
}
