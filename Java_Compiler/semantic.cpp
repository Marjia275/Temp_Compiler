
#include "semantic.h"
#include <sstream>

using namespace std;

bool SemanticAnalyzer::analyze(ASTNode* program, std::vector<std::string>& errs) {
    errors = &errs;
    visit(program);
    return errs.empty();
}

void SemanticAnalyzer::checkAssignTarget(const std::string& name) {
    Symbol* sym = table.lookup(name);
    if (sym == nullptr) {
        stringstream ss;
        ss << "Variable '" << name << "' used before declaration.";
        errors->push_back(ss.str());
    } else if (sym->isFinal) {
        stringstream ss;
        ss << "Cannot assign a value to final variable '" << name << "'.";
        errors->push_back(ss.str());
    }
}

void SemanticAnalyzer::checkExpr(ASTNode* node) {
    if (!node) return;

    switch (node->type) {
        case NODE_ID: {
            if (table.lookup(node->sval) == nullptr) {
                stringstream ss;
                ss << "Variable '" << node->sval << "' used before declaration.";
                errors->push_back(ss.str());
            }
            break;
        }
        case NODE_BINOP: {
            checkExpr(node->children[0]);
            checkExpr(node->children[1]);

            if (node->op == "/" || node->op == "%") {
                ASTNode* rhs = node->children[1];
                bool isZero = (rhs->type == NODE_NUM_INT && rhs->ival == 0) ||
                              (rhs->type == NODE_NUM_FLOAT && rhs->fval == 0.0);
                if (isZero) {
                    errors->push_back("Division by zero detected in expression.");
                }
            }
            break;
        }
        case NODE_UNOP:
            checkExpr(node->children[0]);
            break;
        case NODE_PREINC:
        case NODE_PREDEC:
        case NODE_POSTINC:
        case NODE_POSTDEC: {
            checkAssignTarget(node->sval);
            break;
        }
        case NODE_TERNARY:
            checkExpr(node->children[0]);
            checkExpr(node->children[1]);
            checkExpr(node->children[2]);
            break;
        case NODE_METHOD_CALL: {
            // children[0] = object expr; only check it if it isn't a bare
            // Scanner/String variable reference already validated below,
            // and check every call argument.
            checkExpr(node->children[0]);
            for (size_t i = 1; i < node->children.size(); i++) checkExpr(node->children[i]);
            break;
        }
        case NODE_SYSTEM_IN:
        case NODE_NEW_SCANNER:
            // no identifiers to resolve
            break;
        default:
            // literals need no checking here
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
            // Check the initializer BEFORE declaring the name itself, so that
            // "int x = x;" is still correctly flagged as using 'x' before
            // it exists, while "int MAX = 100;" (a literal, no self-reference)
            // is unaffected either way.
            if (!node->children.empty()) checkExpr(node->children[0]);
            if (!table.declare(node->sval, node->datatype, node->isFinal)) {
                stringstream ss;
                ss << "Duplicate declaration of variable '" << node->sval << "'.";
                errors->push_back(ss.str());
            }
            break;
        }

        case NODE_ASSIGN: {
            checkAssignTarget(node->sval);
            if (!node->children.empty()) checkExpr(node->children[0]);
            break;
        }

        case NODE_COMPOUND_ASSIGN: {
            checkAssignTarget(node->sval);
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

        case NODE_DO_WHILE: {
            loopDepth++;
            visit(node->children[0]);
            loopDepth--;
            checkExpr(node->children[1]);
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
            for (auto c : node->children) visit(c);
            break;

        case NODE_IMPORT:
            // no semantic effect: import statements only affect name resolution
            // in a full Java compiler, which this mini-compiler doesn't model.
            break;

        case NODE_BREAK:
            if (loopDepth == 0 && switchDepth == 0) errors->push_back("'break' used outside of a loop or switch.");
            break;

        case NODE_CONTINUE:
            if (loopDepth == 0) errors->push_back("'continue' used outside of a loop.");
            break;

        case NODE_PRINT:
            // "invalid print statements": System.out.print() with no
            // argument is not valid Java (only println() may be empty).
            if (node->children.empty() && !node->ival) {
                errors->push_back("Invalid print statement: System.out.print() requires an argument.");
            }
            if (!node->children.empty()) checkExpr(node->children[0]);
            break;

        case NODE_RETURN:
            if (!node->children.empty()) checkExpr(node->children[0]);
            break;

        default:
            checkExpr(node);
            break;
    }
}
