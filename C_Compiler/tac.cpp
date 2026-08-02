// ============================================================
// tac.cpp
// ============================================================
#include "tac.h"

using namespace std;

std::string TACGenerator::newTemp()  { return "t" + to_string(++tempCount); }
std::string TACGenerator::newLabel() { return "L" + to_string(++labelCount); }
void TACGenerator::emit(const std::string& instr) { lines.push_back(instr); }

std::vector<std::string> TACGenerator::generate(ASTNode* program) {
    lines.clear();
    tempCount = 0;
    labelCount = 0;
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
        case NODE_ID:        return node->sval;

        case NODE_UNOP: {
            string operand = genExpr(node->children[0]);
            string t = newTemp();
            emit(t + " = " + node->op + operand);
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
            string baseOp = stmt->op.substr(0, 1); 
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
            genBlock(stmt->children[1]);
            emit("goto " + Lstart);
            emit(Lend + ":");
            break;
        }

        case NODE_FOR: {
            if (stmt->children[0]) genStatement(stmt->children[0]);
            string Lstart = newLabel();
            string Lend = newLabel();
            emit(Lstart + ":");
            if (stmt->children[1]) {
                string cond = genExpr(stmt->children[1]);
                emit("if " + cond + " == 0 goto " + Lend);
            }
            genBlock(stmt->children[3]);
            if (stmt->children[2]) genStatement(stmt->children[2]);
            emit("goto " + Lstart);
            emit(Lend + ":");
            break;
        }

        case NODE_PRINTF: {
            const string& fmt = stmt->sval;
            size_t argIndex = 0;
            string literalBuf;

            auto flushLiteral = [&]() {
                if (!literalBuf.empty()) {
                    emit("print \"" + literalBuf + "\"");
                    literalBuf.clear();
                }
            };

            for (size_t i = 0; i < fmt.size(); i++) {
                if (fmt[i] == '%' && i + 1 < fmt.size() &&
                    (fmt[i+1] == 'd' || fmt[i+1] == 'f' || fmt[i+1] == 'c' || fmt[i+1] == 's')) {
                    flushLiteral();
                    if (fmt[i+1] == 's' && stmt->children[argIndex]->type == NODE_STRING) {
                        emit("print \"" + stmt->children[argIndex]->sval + "\"");
                        argIndex++;
                    } else {
                        string v = genExpr(stmt->children[argIndex++]);
                        emit("print " + v);
                    }
                    i++;
                } else if (fmt[i] == '\n') {
                    literalBuf += "\\n";
                } else {
                    literalBuf += fmt[i];
                }
            }
            flushLiteral();
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
            genExpr(stmt);
            break;
    }
}
