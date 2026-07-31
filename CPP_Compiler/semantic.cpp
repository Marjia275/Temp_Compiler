// ============================================================
// semantic.cpp
// ============================================================
#include "semantic.h"
#include <sstream>

using namespace std;

static string atLine(ASTNode* node) {
    if (node && node->line > 0) return "Line " + to_string(node->line) + ": ";
    return "";
}

bool SemanticAnalyzer::analyze(ASTNode* program, std::vector<std::string>& errs) {
    errors = &errs;
    visit(program);
    return errs.empty();
}

bool SemanticAnalyzer::isCinChain(ASTNode* node) {
    if (!node) return false;
    if (node->type == NODE_CIN) return true;
    if (node->type == NODE_BINOP && node->op == ">>") return isCinChain(node->children[0]);
    return false;
}

void SemanticAnalyzer::checkExpr(ASTNode* node) {
    if (!node) return;

    switch (node->type) {
        case NODE_ID: {
            if (table.lookup(node->sval) == nullptr) {
                stringstream ss;
                ss << atLine(node) << "Variable '" << node->sval << "' used before declaration.";
                errors->push_back(ss.str());
            }
            break;
        }
        case NODE_BINOP: {
            // "cin >> x" requires x to be a plain, declared variable.
            if (node->op == ">>" && isCinChain(node->children[0])) {
                checkExpr(node->children[0]);
                if (node->children[1]->type != NODE_ID) {
                    errors->push_back(atLine(node) + "Invalid cin usage: right-hand side of '>>' must be a variable.");
                } else {
                    checkExpr(node->children[1]);
                }
                break;
            }

            checkExpr(node->children[0]);
            checkExpr(node->children[1]);

            if (node->op == "/" || node->op == "%") {
                ASTNode* rhs = node->children[1];
                bool isZero = (rhs->type == NODE_NUM_INT && rhs->ival == 0) ||
                              (rhs->type == NODE_NUM_FLOAT && rhs->fval == 0.0);
                if (isZero) {
                    errors->push_back(atLine(node) + "Division by zero detected in expression.");
                }
            }
            break;
        }
        case NODE_UNOP:
            checkExpr(node->children[0]);
            break;
        case NODE_TERNARY:
            checkExpr(node->children[0]);
            checkExpr(node->children[1]);
            checkExpr(node->children[2]);
            break;
        case NODE_SIZEOF:
            // sizeof(variable) form: the variable must be declared.
            if (node->datatype.empty() && !node->sval.empty()) {
                if (table.lookup(node->sval) == nullptr) {
                    stringstream ss;
                    ss << atLine(node) << "Variable '" << node->sval << "' used before declaration.";
                    errors->push_back(ss.str());
                }
            }
            break;
        case NODE_PREINC:
        case NODE_PREDEC:
        case NODE_POSTINC:
        case NODE_POSTDEC: {
            Symbol* sym = table.lookup(node->sval);
            if (sym == nullptr) {
                stringstream ss;
                ss << atLine(node) << "Variable '" << node->sval << "' used before declaration.";
                errors->push_back(ss.str());
            } else if (sym->isConst) {
                stringstream ss;
                ss << atLine(node) << "Cannot modify constant variable '" << node->sval << "'.";
                errors->push_back(ss.str());
            }
            break;
        }
        default:
            // literals, cout/cin/endl markers need no checking here
            break;
    }
}

void SemanticAnalyzer::visit(ASTNode* node) {
    if (!node) return;

    switch (node->type) {
        case NODE_PROGRAM:
        case NODE_BLOCK:
            for (auto c : node->children) visit(c);
            break;

        case NODE_VARDECL: {
            if (node->isConst && node->children.empty()) {
                errors->push_back(atLine(node) + "Constant variable '" + node->sval + "' must be initialized.");
            }
            if (!table.declare(node->sval, node->datatype, node->isConst)) {
                stringstream ss;
                ss << atLine(node) << "Duplicate declaration of variable '" << node->sval << "'.";
                errors->push_back(ss.str());
            }
            if (!node->children.empty()) checkExpr(node->children[0]);
            break;
        }

        case NODE_ASSIGN: {
            Symbol* sym = table.lookup(node->sval);
            if (sym == nullptr) {
                stringstream ss;
                ss << atLine(node) << "Variable '" << node->sval << "' used before declaration.";
                errors->push_back(ss.str());
            } else if (sym->isConst) {
                stringstream ss;
                ss << atLine(node) << "Cannot modify constant variable '" << node->sval << "'.";
                errors->push_back(ss.str());
            }
            if (!node->children.empty()) checkExpr(node->children[0]);
            break;
        }

        case NODE_COMPOUND_ASSIGN: {
            Symbol* sym = table.lookup(node->sval);
            if (sym == nullptr) {
                stringstream ss;
                ss << atLine(node) << "Variable '" << node->sval << "' used before declaration.";
                errors->push_back(ss.str());
            } else if (sym->isConst) {
                stringstream ss;
                ss << atLine(node) << "Cannot modify constant variable '" << node->sval << "'.";
                errors->push_back(ss.str());
            }
            if (!node->children.empty()) checkExpr(node->children[0]);
            break;
        }

        case NODE_IF:
            checkExpr(node->children[0]);
            visit(node->children[1]);
            if (node->children.size() > 2 && node->children[2]) visit(node->children[2]);
            break;

        case NODE_WHILE:
            checkExpr(node->children[0]);
            loopDepth++;
            visit(node->children[1]);
            loopDepth--;
            break;

        case NODE_DOWHILE:
            loopDepth++;
            visit(node->children[0]);
            loopDepth--;
            checkExpr(node->children[1]);
            break;

        case NODE_FOR: {
            table.pushScope("for");
            loopDepth++;
            if (node->children[0]) visit(node->children[0]);
            if (node->children[1]) checkExpr(node->children[1]);
            if (node->children[2]) visit(node->children[2]);
            visit(node->children[3]);
            loopDepth--;
            table.popScope();
            break;
        }

        case NODE_BREAK:
            if (loopDepth == 0) errors->push_back(atLine(node) + "'break' statement not inside loop or switch.");
            break;

        case NODE_CONTINUE:
            if (loopDepth == 0) errors->push_back(atLine(node) + "'continue' statement not inside loop.");
            break;

        case NODE_RETURN:
            if (!node->children.empty()) checkExpr(node->children[0]);
            break;

        default:
            // A bare expression statement, e.g. "cout << a << endl;"
            checkExpr(node);
            break;
    }
}
