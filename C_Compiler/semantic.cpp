// ============================================================
// semantic.cpp
// ============================================================
#include "semantic.h"
#include <sstream>

using namespace std;

bool SemanticAnalyzer::analyze(ASTNode* program, std::vector<std::string>& errs) {
    errors = &errs;
    visit(program);
    return errs.empty();
}

void SemanticAnalyzer::error(ASTNode* node, const std::string& msg) {
    stringstream ss;
    if (node && node->line > 0) ss << "Line " << node->line << ": " << msg;
    else ss << msg;
    errors->push_back(ss.str());
}


std::string SemanticAnalyzer::inferType(ASTNode* node) {
    if (!node) return "int";
    switch (node->type) {
        case NODE_NUM_INT:   return node->datatype == "long" ? "long" : "int";
        case NODE_NUM_FLOAT: return "float";
        case NODE_CHAR:      return "char";
        case NODE_ID: {
            Symbol* sym = table.lookup(node->sval);
            return sym ? sym->type : "int";
        }
        case NODE_UNOP:       return inferType(node->children[0]);
        case NODE_TERNARY:    return inferType(node->children[1]);
        case NODE_PREINC: case NODE_PREDEC:
        case NODE_POSTINC: case NODE_POSTDEC: {
            Symbol* sym = table.lookup(node->sval);
            return sym ? sym->type : "int";
        }
        case NODE_SIZEOF:     return "int";
        case NODE_CALL:       return (node->sval == "abs") ? inferType(node->children[0]) : "double";
        case NODE_BINOP: {
            string l = inferType(node->children[0]);
            string r = inferType(node->children[1]);
            if (l == "double" || r == "double") return "double";
            if (l == "float" || r == "float") return "float";
            if (l == "long" || r == "long") return "long";
            return "int";
        }
        default: return "int";
    }
}

void SemanticAnalyzer::checkExpr(ASTNode* node) {
    if (!node) return;

    switch (node->type) {
        case NODE_ID: {
            if (table.lookup(node->sval) == nullptr) {
                error(node, "Variable '" + node->sval + "' used before declaration.");
            }
            break;
        }
        case NODE_BINOP: {
            checkExpr(node->children[0]);
            checkExpr(node->children[1]);

            if (node->op == "/" || node->op == "%") {
                ASTNode* rhs = node->children[1];
                bool isZero = (rhs->type == NODE_NUM_INT && rhs->ival == 0 && rhs->llit == 0) ||
                              (rhs->type == NODE_NUM_FLOAT && rhs->fval == 0.0);
                if (isZero) {
                    error(node, "Division by zero detected in expression.");
                }
            }
   
            if (node->op == "&" || node->op == "|" || node->op == "^" ||
                node->op == "<<" || node->op == ">>") {
                string lt = inferType(node->children[0]);
                string rt = inferType(node->children[1]);
                if (lt == "float" || lt == "double" || rt == "float" || rt == "double") {
                    error(node, "Bitwise operator '" + node->op + "' requires integer operands.");
                }
            }
            break;
        }
        case NODE_UNOP:
            checkExpr(node->children[0]);
            if (node->op == "~") {
                string t = inferType(node->children[0]);
                if (t == "float" || t == "double") {
                    error(node, "Bitwise operator '~' requires an integer operand.");
                }
            }
            break;
        case NODE_TERNARY:
            checkExpr(node->children[0]);
            checkExpr(node->children[1]);
            checkExpr(node->children[2]);
            break;
        case NODE_PREINC:
        case NODE_PREDEC:
        case NODE_POSTINC:
        case NODE_POSTDEC: {
            checkLValue(node);
            break;
        }
        case NODE_SIZEOF:
            if (!node->children.empty()) checkExpr(node->children[0]);
            break;
        case NODE_CALL:
            for (auto c : node->children) checkExpr(c);
            break;
        default:
            break;
    }
}

void SemanticAnalyzer::checkLValue(ASTNode* node) {
    Symbol* sym = table.lookup(node->sval);
    if (sym == nullptr) {
        error(node, "Variable '" + node->sval + "' used before declaration.");
        return;
    }
    if (sym->isConst) {
        error(node, "Cannot modify constant variable '" + node->sval + "'");
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
                error(node, "Const variable '" + node->sval + "' must be initialized.");
            }
            if (!table.declare(node->sval, node->datatype, node->isConst)) {
                error(node, "Duplicate declaration of variable '" + node->sval + "'.");
            }
            if (!node->children.empty()) checkExpr(node->children[0]);
            break;
        }

        case NODE_ASSIGN: {
            checkLValue(node);
            if (!node->children.empty()) checkExpr(node->children[0]);
            break;
        }

        case NODE_COMPOUND_ASSIGN: {
            checkLValue(node);
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
            if (node->children[0]) visit(node->children[0]);
            if (node->children[1]) checkExpr(node->children[1]);
            if (node->children[2]) visit(node->children[2]);
            loopDepth++;
            visit(node->children[3]);
            loopDepth--;
            table.popScope();
            break;
        }

        case NODE_SWITCH: {
            checkExpr(node->children[0]);
            switchDepth++;
            for (size_t i = 1; i < node->children.size(); i++) visit(node->children[i]);
            switchDepth--;
            break;
        }

        case NODE_CASE:
        case NODE_DEFAULT:
            if (!node->children.empty()) visit(node->children[0]);
            break;

        case NODE_BREAK:
            if (loopDepth == 0 && switchDepth == 0) {
                error(node, "break statement not inside loop or switch.");
            }
            break;

        case NODE_CONTINUE:
            if (loopDepth == 0) {
                error(node, "continue statement not inside loop.");
            }
            break;

        case NODE_PRINTF:
            for (auto c : node->children) checkExpr(c);
            break;

        case NODE_SCANF:
            for (auto c : node->children) {
                if (table.lookup(c->sval) == nullptr) {
                    error(node, "Variable '" + c->sval + "' used before declaration.");
                } else {
                    Symbol* sym = table.lookup(c->sval);
                    if (sym->isConst) error(node, "Cannot modify constant variable '" + c->sval + "'");
                }
            }
            break;

        case NODE_RETURN:
            if (!node->children.empty()) checkExpr(node->children[0]);
            break;

        default:
            checkExpr(node);
            break;
    }
}
