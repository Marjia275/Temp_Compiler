
#include "interpreter.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>

using namespace std;

std::string Value::toDisplayString() const {
    if (type == "string") return sval;
    if (type == "bool")   return ival ? "1" : "0";
    if (type == "char")   return std::string(1, cval);
    if (type == "float" || type == "double") {
        ostringstream ss; ss << fval; return ss.str();
    }
    return to_string(ival);
}


static string combineIntType(const string& a, const string& b) {
    auto rank = [](const string& t) -> int {
        if (t == "unsigned long long") return 4;
        if (t == "long long") return 3;
        if (t == "long") return 2;
        return 1; 
    };
    return rank(a) >= rank(b) ? a : b;
}

static string runtimeErrAt(ASTNode* node, const string& msg) {
    string prefix = "Runtime Error:\n";
    if (node && node->line > 0) prefix += "Line " + to_string(node->line) + ":\n";
    return prefix + msg;
}

void Interpreter::run(ASTNode* program, SymbolTable& finalTable) {
    table = &finalTable;
    std::cout << std::unitbuf;
    try {
        execBlock(program);
    } catch (ReturnSignal&) {
        
    }
}

void Interpreter::execBlock(ASTNode* block) {
    if (!block) return;
    for (auto stmt : block->children) {
        execStatement(stmt);
    }
}

void Interpreter::assignTo(const std::string& name, const Value& v) {
    Symbol* sym = table->lookup(name);
    if (!sym) {
        throw runtime_error("Runtime Error:\nVariable '" + name + "' not declared.");
    }
    if (sym->type == "int" || sym->type == "unsigned int") {
        sym->value.ival = (long long)(int)v.asLongLong();
    } else if (sym->type == "long" || sym->type == "long long" || sym->type == "unsigned long long") {
        sym->value.ival = v.asLongLong();
    } else if (sym->type == "float" || sym->type == "double") {
        sym->value.fval = v.asDouble();
    } else if (sym->type == "char") {
        sym->value.cval = (v.type == "char") ? v.cval : (char)(int)v.asDouble();
    } else if (sym->type == "bool") {
        sym->value.ival = (v.asDouble() != 0.0) ? 1 : 0;
    } else if (sym->type == "string") {
        sym->value.sval = v.toDisplayString();
    }
}

void Interpreter::printValue(const Value& v) {
    
    if (v.type == "int" || v.type == "unsigned int")  cout << (int)v.ival;
    else if (v.type == "long" || v.type == "long long") cout << v.ival;
    else if (v.type == "unsigned long long") cout << (unsigned long long)v.ival;
    else if (v.type == "float" || v.type == "double") cout << v.fval;
    else if (v.type == "char")         cout << v.cval;
    else if (v.type == "bool")         cout << (v.ival ? 1 : 0); 
    else if (v.type == "string")       cout << v.sval;
}

void Interpreter::readValue(const std::string& varName) {
    Symbol* sym = table->lookup(varName);
    if (!sym) throw runtime_error("Runtime Error:\nVariable '" + varName + "' not declared.");

    if (sym->type == "int" || sym->type == "unsigned int") { int x; cin >> x; sym->value.ival = x; }
    else if (sym->type == "long" || sym->type == "long long" || sym->type == "unsigned long long") { cin >> sym->value.ival; }
    else if (sym->type == "float" || sym->type == "double") { cin >> sym->value.fval; }
    else if (sym->type == "char") { cin >> sym->value.cval; }
    else if (sym->type == "bool") { int x; cin >> x; sym->value.ival = (x != 0); }
    else if (sym->type == "string") { cin >> sym->value.sval; }
}

Value Interpreter::evalExpr(ASTNode* node) {
    Value result;

    switch (node->type) {
        case NODE_NUM_INT:
            result.type = (node->ival >= -2147483648LL && node->ival <= 2147483647LL) ? "int" : "long long";
            result.ival = node->ival;
            return result;

        case NODE_NUM_FLOAT:
            result.type = "double";
            result.fval = node->fval;
            return result;

        case NODE_CHAR:
            result.type = "char";
            result.cval = node->cval;
            return result;

        case NODE_STRING:
            result.type = "string";
            result.sval = node->sval;
            return result;

        case NODE_BOOL:
            result.type = "bool";
            result.ival = node->ival;
            return result;

        case NODE_COUT:
            result.type = "cout";
            return result;

        case NODE_CIN:
            result.type = "cin";
            return result;

        case NODE_ENDL:
            result.type = "endl";
            return result;

        case NODE_ID: {
            Symbol* sym = table->lookup(node->sval);
            if (!sym) throw runtime_error(runtimeErrAt(node, "Variable '" + node->sval + "' not declared."));
            result.type = sym->type;
            result.ival = sym->value.ival;
            result.fval = sym->value.fval;
            result.cval = sym->value.cval;
            result.sval = sym->value.sval;
            return result;
        }

        case NODE_SIZEOF: {
            string ty = node->datatype;
            if (ty.empty()) {
                Symbol* sym = table->lookup(node->sval);
                if (!sym) throw runtime_error(runtimeErrAt(node, "Variable '" + node->sval + "' not declared."));
                ty = sym->type;
            }
            long long size = 4; 
            if (ty == "char" || ty == "bool") size = 1;
            else if (ty == "int" || ty == "unsigned int" || ty == "float") size = 4;
            else if (ty == "double" || ty == "long" || ty == "long long" || ty == "unsigned long long") size = 8;
            else if (ty == "string") size = 32; 
            result.type = "unsigned long long";
            result.ival = size;
            return result;
        }

        case NODE_TERNARY: {
            Value cond = evalExpr(node->children[0]);
            return evalExpr(cond.asDouble() != 0.0 ? node->children[1] : node->children[2]);
        }

        case NODE_UNOP: {
            Value v = evalExpr(node->children[0]);
            if (node->op == "-") {
                if (v.type == "float" || v.type == "double") { result.type = v.type; result.fval = -v.fval; }
                else if (v.isIntegral()) { result.type = v.type; result.ival = -v.asLongLong(); }
                else { result.type = "int"; result.ival = -(long long)v.asDouble(); }
            } else if (node->op == "!") {
                result.type = "bool";
                result.ival = (v.asDouble() == 0.0) ? 1 : 0;
            } else if (node->op == "~") {
                result.type = v.isIntegral() ? v.type : "int";
                result.ival = ~v.asLongLong();
            }
            return result;
        }

        case NODE_PREINC: case NODE_PREDEC:
        case NODE_POSTINC: case NODE_POSTDEC: {
            Symbol* sym = table->lookup(node->sval);
            if (!sym) throw runtime_error(runtimeErrAt(node, "Variable '" + node->sval + "' not declared."));
            if (sym->isConst) throw runtime_error(runtimeErrAt(node, "Cannot modify constant variable '" + node->sval + "'."));

            Value oldVal;
            oldVal.type = sym->type; oldVal.ival = sym->value.ival;
            oldVal.fval = sym->value.fval; oldVal.cval = sym->value.cval;

            int delta = (node->type == NODE_PREINC || node->type == NODE_POSTINC) ? 1 : -1;
            if (sym->type == "float" || sym->type == "double") sym->value.fval += delta;
            else if (sym->type == "char") sym->value.cval += delta;
            else sym->value.ival += delta;

            if (node->type == NODE_PREINC || node->type == NODE_PREDEC) {
                result.type = sym->type;
                result.ival = sym->value.ival; result.fval = sym->value.fval; result.cval = sym->value.cval;
            } else {
                result = oldVal;
            }
            return result;
        }

        case NODE_BINOP: {
            const string& op = node->op;

            if (op == "<<") {
                Value l = evalExpr(node->children[0]);
                if (l.type == "cout") {
                    ASTNode* rhsNode = node->children[1];
                    if (rhsNode->type == NODE_ENDL) {
                        cout << "\n";
                    } else {
                        Value r = evalExpr(rhsNode);
                        printValue(r);
                    }
                    result.type = "cout";
                    return result; 
                }
                Value r = evalExpr(node->children[1]);
                result.type = l.isIntegral() ? l.type : "int";
                result.ival = l.asLongLong() << r.asLongLong();
                return result;
            }

            if (op == ">>") {
                Value l = evalExpr(node->children[0]);
                if (l.type == "cin") {
                    ASTNode* rhsNode = node->children[1];
                    if (rhsNode->type != NODE_ID) {
                        throw runtime_error(runtimeErrAt(node, "cin >> requires a variable."));
                    }
                    readValue(rhsNode->sval);
                    result.type = "cin";
                    return result; 
                }
                Value r = evalExpr(node->children[1]);
                result.type = l.isIntegral() ? l.type : "int";
                result.ival = l.asLongLong() >> r.asLongLong();
                return result;
            }

            Value l = evalExpr(node->children[0]);
            Value r = evalExpr(node->children[1]);

            if (op == "+" && (l.type == "string" || r.type == "string")) {
                result.type = "string";
                result.sval = l.toDisplayString() + r.toDisplayString();
                return result;
            }

            bool useFloat = (l.type == "float" || l.type == "double" ||
                              r.type == "float" || r.type == "double");
            string floatType = (l.type == "double" || r.type == "double") ? "double" : "float";

            if (op == "+" || op == "-" || op == "*" || op == "/" || op == "%") {
                if (useFloat) {
                    double a = l.asDouble(), b = r.asDouble();
                    if (op == "/" && b == 0.0) throw runtime_error(runtimeErrAt(node, "Division by zero."));
                    double v = (op == "+") ? a + b :
                               (op == "-") ? a - b :
                               (op == "*") ? a * b :
                               (op == "%") ? fmod(a, b) : a / b;
                    result.type = floatType; result.fval = v;
                    return result;
                }
                
                long long a = l.asLongLong(), b = r.asLongLong();
                if ((op == "/" || op == "%") && b == 0) {
                    throw runtime_error(runtimeErrAt(node, op == "/" ? "Division by zero." : "Modulo by zero."));
                }
                long long v = (op == "+") ? a + b :
                              (op == "-") ? a - b :
                              (op == "*") ? a * b :
                              (op == "%") ? a % b : a / b;
                result.type = combineIntType(l.isIntegral() ? l.type : "int", r.isIntegral() ? r.type : "int");
                result.ival = v;
                return result;
            }

            if (op == "&" || op == "|" || op == "^") {
                long long a = l.asLongLong(), b = r.asLongLong();
                result.type = combineIntType(l.isIntegral() ? l.type : "int", r.isIntegral() ? r.type : "int");
                result.ival = (op == "&") ? (a & b) : (op == "|") ? (a | b) : (a ^ b);
                return result;
            }

            double a = l.asDouble(), b = r.asDouble();
            int v = 0;
            if (op == ">")  v = a > b;
            else if (op == "<")  v = a < b;
            else if (op == ">=") v = a >= b;
            else if (op == "<=") v = a <= b;
            else if (op == "==") v = a == b;
            else if (op == "!=") v = a != b;
            else if (op == "&&") v = (a != 0.0) && (b != 0.0);
            else if (op == "||") v = (a != 0.0) || (b != 0.0);
            result.type = "bool";
            result.ival = v;
            return result;
        }

        default:
            throw runtime_error(runtimeErrAt(node, "Cannot evaluate this expression."));
    }
}

void Interpreter::execStatement(ASTNode* stmt) {
    if (!stmt) return;

    switch (stmt->type) {
        case NODE_VARDECL: {
            table->declare(stmt->sval, stmt->datatype, stmt->isConst);
            if (!stmt->children.empty()) {
                Value v = evalExpr(stmt->children[0]);
                assignTo(stmt->sval, v);
            }
            break;
        }

        case NODE_ASSIGN: {
            Symbol* sym = table->lookup(stmt->sval);
            if (!sym) throw runtime_error(runtimeErrAt(stmt, "Variable '" + stmt->sval + "' not declared."));
            if (sym->isConst) throw runtime_error(runtimeErrAt(stmt, "Cannot modify constant variable '" + stmt->sval + "'."));
            Value v = evalExpr(stmt->children[0]);
            assignTo(stmt->sval, v);
            break;
        }

case NODE_COMPOUND_ASSIGN: {
            Symbol* sym = table->lookup(stmt->sval);
            if (!sym) throw runtime_error(runtimeErrAt(stmt, "Variable '" + stmt->sval + "' not declared."));
            if (sym->isConst) throw runtime_error(runtimeErrAt(stmt, "Cannot modify constant variable '" + stmt->sval + "'."));
            Value cur;
            cur.type = sym->type; cur.ival = sym->value.ival;
            cur.fval = sym->value.fval; cur.cval = sym->value.cval; cur.sval = sym->value.sval;

            Value rhs = evalExpr(stmt->children[0]);

            if (sym->type == "string") {
                Value result;
                result.type = "string";
                result.sval = cur.sval + rhs.toDisplayString();
                assignTo(stmt->sval, result);
                break;
            }

            bool useFloat = (sym->type == "float" || sym->type == "double");
            Value result;
            if (useFloat) {
                double a = cur.asDouble(), b = rhs.asDouble();
                double v = 0;
                if (stmt->op == "+=") v = a + b;
                else if (stmt->op == "-=") v = a - b;
                else if (stmt->op == "*=") v = a * b;
                else if (stmt->op == "/=") {
                    if (b == 0.0) throw runtime_error(runtimeErrAt(stmt, "Division by zero."));
                    v = a / b;
                }
                else if (stmt->op == "%=") {
                    if (b == 0.0) throw runtime_error(runtimeErrAt(stmt, "Division by zero."));
                    v = fmod(a, b);
                }
                result.type = sym->type; result.fval = v;
            } else {
                long long a = cur.asLongLong(), b = rhs.asLongLong();
                long long v = 0;
                if (stmt->op == "+=") v = a + b;
                else if (stmt->op == "-=") v = a - b;
                else if (stmt->op == "*=") v = a * b;
                else if (stmt->op == "/=") {
                    if (b == 0) throw runtime_error(runtimeErrAt(stmt, "Division by zero."));
                    v = a / b;
                }
                else if (stmt->op == "%=") {
                    if (b == 0) throw runtime_error(runtimeErrAt(stmt, "Division by zero."));
                    v = a % b;
                }
                result.type = sym->type; result.ival = v;
            }
            assignTo(stmt->sval, result);
            break;
        }

        case NODE_IF: {
            Value cond = evalExpr(stmt->children[0]);
            if (cond.asDouble() != 0.0) {
                execBlock(stmt->children[1]);
            } else if (stmt->children.size() > 2 && stmt->children[2]) {
                execBlock(stmt->children[2]);
            }
            break;
        }

        case NODE_WHILE: {
            while (evalExpr(stmt->children[0]).asDouble() != 0.0) {
                try {
                    execBlock(stmt->children[1]);
                } catch (ContinueSignal&) {
                    continue; 
                } catch (BreakSignal&) {
                    break;
                }
            }
            break;
        }

        case NODE_DOWHILE: {
            bool brk = false;
            do {
                try {
                    execBlock(stmt->children[0]);
                } catch (ContinueSignal&) {
                } catch (BreakSignal&) {
                    brk = true;
                }
                if (brk) break;
            } while (evalExpr(stmt->children[1]).asDouble() != 0.0);
            break;
        }

        case NODE_FOR: {
            table->pushScope("for");
            if (stmt->children[0]) execStatement(stmt->children[0]);
            while (stmt->children[1] == nullptr || evalExpr(stmt->children[1]).asDouble() != 0.0) {
                try {
                    execBlock(stmt->children[3]);
                } catch (ContinueSignal&) {
                } catch (BreakSignal&) {
                    break;
                }
                if (stmt->children[2]) execStatement(stmt->children[2]);
            }
            table->popScope();
            break;
        }

        case NODE_SWITCH: {
            // children[0] = switch expr, children[1] = NODE_BLOCK of NODE_CASE / NODE_DEFAULT
            Value swVal = evalExpr(stmt->children[0]);
            ASTNode* caseList = stmt->children[1];

            long long target = swVal.asLongLong();
            int matchIndex = -1;
            int defaultIndex = -1;

            // First pass: find the matching case (or remember default's position)
            for (size_t i = 0; i < caseList->children.size(); i++) {
                ASTNode* c = caseList->children[i];
                if (c->type == NODE_CASE) {
                    Value caseVal = evalExpr(c->children[0]);
                    if (caseVal.asLongLong() == target) {
                        matchIndex = (int)i;
                        break;
                    }
                } else if (c->type == NODE_DEFAULT) {
                    defaultIndex = (int)i;
                }
            }

            int startIndex = (matchIndex != -1) ? matchIndex : defaultIndex;

            if (startIndex != -1) {
                try {
                    for (size_t i = startIndex; i < caseList->children.size(); i++) {
                        ASTNode* c = caseList->children[i];
                        ASTNode* body = (c->type == NODE_CASE) ? c->children[1] : c->children[0];
                        execBlock(body);
                    }
                } catch (BreakSignal&) {
                    // break exits the switch only
                }
            }
            break;
        }

        case NODE_BREAK:
            throw BreakSignal{};

        case NODE_CONTINUE:
            throw ContinueSignal{};

        case NODE_RETURN: {
            ReturnSignal sig;
            if (!stmt->children.empty()) sig.value = evalExpr(stmt->children[0]);
            throw sig;
        }

        case NODE_BLOCK:
            execBlock(stmt);
            break;

        default:
           
            evalExpr(stmt);
            break;
    }
}