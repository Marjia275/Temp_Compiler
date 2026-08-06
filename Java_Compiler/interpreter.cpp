
#include "interpreter.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>

using namespace std;

std::string Value::toDisplayString() const {
    if (type == "String")  return sval;
    if (type == "boolean") return ival ? "true" : "false";
    if (type == "char")    return std::string(1, cval);
    if (type == "float" || type == "double") {
        ostringstream ss; ss << fval; return ss.str();
    }
    return to_string(ival);
}

void Interpreter::run(ASTNode* program, SymbolTable& finalTable) {
    table = &finalTable;
    try {
        execBlock(program);
    } catch (ReturnSignal&) {
        // "return" inside main() simply ends the program.
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
        throw runtime_error("Runtime error: variable '" + name + "' not declared.");
    }
    if (sym->type == "int") {
        sym->value.ival = (v.type == "float" || v.type == "double") ? (int)v.fval :
                           (v.type == "char")  ? (int)v.cval : v.ival;
    } else if (sym->type == "float" || sym->type == "double") {
        sym->value.fval = v.asDouble();
    } else if (sym->type == "char") {
        sym->value.cval = (v.type == "char") ? v.cval : (char)(int)v.asDouble();
    } else if (sym->type == "boolean") {
        sym->value.ival = (v.asDouble() != 0.0) ? 1 : 0;
    } else if (sym->type == "String") {
        sym->value.sval = v.toDisplayString();
    }
}

void Interpreter::printValue(const Value& v) {
    // Matches java.lang.String.valueOf()'s behavior for the types we support.
    if (v.type == "int")               cout << v.ival;
    else if (v.type == "float" || v.type == "double") cout << v.fval;
    else if (v.type == "char")         cout << v.cval;
    else if (v.type == "boolean")      cout << (v.ival ? "true" : "false");
    else if (v.type == "String")       cout << v.sval;
}

Value Interpreter::evalExpr(ASTNode* node) {
    Value result;

    switch (node->type) {
        case NODE_NUM_INT:
            result.type = "int";
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
            result.type = "String";
            result.sval = node->sval;
            return result;

        case NODE_BOOL:
            result.type = "boolean";
            result.ival = node->ival;
            return result;

        case NODE_ID: {
            Symbol* sym = table->lookup(node->sval);
            if (!sym) throw runtime_error("Runtime error: variable '" + node->sval + "' not declared.");
            result.type = sym->type;
            result.ival = sym->value.ival;
            result.fval = sym->value.fval;
            result.cval = sym->value.cval;
            result.sval = sym->value.sval;
            return result;
        }

        case NODE_UNOP: {
            Value v = evalExpr(node->children[0]);
            if (node->op == "-") {
                if (v.type == "float" || v.type == "double") { result.type = v.type; result.fval = -v.fval; }
                else { result.type = "int"; result.ival = -(int)v.asDouble(); }
            } else if (node->op == "!") {
                result.type = "boolean";
                result.ival = (v.asDouble() == 0.0) ? 1 : 0;
            } else if (node->op == "~") {
                result.type = "int";
                result.ival = ~(int)v.asDouble();
            }
            return result;
        }

        case NODE_TERNARY: {
            Value cond = evalExpr(node->children[0]);
            return (cond.asDouble() != 0.0) ? evalExpr(node->children[1]) : evalExpr(node->children[2]);
        }

        case NODE_NEW_SCANNER:
            result.type = "Scanner";
            return result;

        case NODE_SYSTEM_IN:
            // Only meaningful as a "new Scanner(System.in)" constructor argument,
            // which is discarded at parse time; evaluated here only as a safety net.
            result.type = "int";
            result.ival = 0;
            return result;

        case NODE_METHOD_CALL: {
            ASTNode* objNode = node->children[0];
            const string& method = node->sval;

            // Methods called directly on a Scanner-typed variable 
            if (objNode->type == NODE_ID) {
                Symbol* sym = table->lookup(objNode->sval);
                if (sym && sym->type == "Scanner") {
                    if (method == "nextInt") {
                        int v;
                        if (!(cin >> v)) throw runtime_error("Runtime error: Scanner ran out of input for nextInt().");
                        result.type = "int"; result.ival = v; return result;
                    } else if (method == "nextFloat") {
                        float v;
                        if (!(cin >> v)) throw runtime_error("Runtime error: Scanner ran out of input for nextFloat().");
                        result.type = "float"; result.fval = v; return result;
                    } else if (method == "nextDouble") {
                        double v;
                        if (!(cin >> v)) throw runtime_error("Runtime error: Scanner ran out of input for nextDouble().");
                        result.type = "double"; result.fval = v; return result;
                    } else if (method == "next") {
                        string v;
                        if (!(cin >> v)) throw runtime_error("Runtime error: Scanner ran out of input for next().");
                        result.type = "String"; result.sval = v; return result;
                    } else if (method == "nextLine") {
                        string v;
                        std::getline(cin, v);
                        result.type = "String"; result.sval = v; return result;
                    } else if (method == "close") {
                        result.type = "boolean"; result.ival = 1; return result; // no real resource to release
                    } else {
                        throw runtime_error("Runtime error: unsupported Scanner method '" + method + "'.");
                    }
                }
            }

            //  Otherwise evaluate the object and dispatch on its runtime type 
            Value obj = evalExpr(objNode);
            if (obj.type == "String") {
                if (method == "charAt") {
                    if (node->children.size() < 2)
                        throw runtime_error("Runtime error: charAt() requires an index argument.");
                    int idx = (int)evalExpr(node->children[1]).asDouble();
                    if (idx < 0 || idx >= (int)obj.sval.size())
                        throw runtime_error("Runtime error: String index out of range in charAt().");
                    result.type = "char"; result.cval = obj.sval[idx]; return result;
                } else if (method == "length") {
                    result.type = "int"; result.ival = (int)obj.sval.size(); return result;
                }
            }
            throw runtime_error("Runtime error: method '" + method + "' is not supported on this type.");
        }

        case NODE_PREINC: case NODE_PREDEC:
        case NODE_POSTINC: case NODE_POSTDEC: {
            Symbol* sym = table->lookup(node->sval);
            if (!sym) throw runtime_error("Runtime error: variable '" + node->sval + "' not declared.");

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
            Value l = evalExpr(node->children[0]);
            Value r = evalExpr(node->children[1]);

            // String concatenation (Java: "+" concatenates whenever
            // either operand is a String, exactly like real Java) 
            if (op == "+" && (l.type == "String" || r.type == "String")) {
                result.type = "String";
                result.sval = l.toDisplayString() + r.toDisplayString();
                return result;
            }

            bool useFloat = (l.type == "float" || l.type == "double" ||
                              r.type == "float" || r.type == "double");
            string floatType = (l.type == "double" || r.type == "double") ? "double" : "float";
            double a = l.asDouble(), b = r.asDouble();

            // Bitwise / shift operators: always operate on integer values 
            if (op == "&" || op == "|" || op == "^" || op == "<<" || op == ">>") {
                int ai = (int)a, bi = (int)b;
                int v = (op == "&")  ? (ai & bi) :
                        (op == "|")  ? (ai | bi) :
                        (op == "^")  ? (ai ^ bi) :
                        (op == "<<") ? (ai << bi) : (ai >> bi);
                result.type = "int";
                result.ival = v;
                return result;
            }

            if (op == "+" || op == "-" || op == "*" || op == "/" || op == "%") {
                if (op == "/" && b == 0.0) throw runtime_error("Runtime error: division by zero.");
                if (op == "%") {
                    int ai = (int)a, bi = (int)b;
                    if (bi == 0) throw runtime_error("Runtime error: modulo by zero.");
                    result.type = "int";
                    result.ival = ai % bi;
                    return result;
                }
                double v = (op == "+") ? a + b :
                           (op == "-") ? a - b :
                           (op == "*") ? a * b : a / b;
                if (useFloat) { result.type = floatType; result.fval = v; }
                else          { result.type = "int";     result.ival = (int)v; }
                return result;
            }

            // relational / logical operators always produce a boolean
            int v = 0;
            if (op == ">")  v = a > b;
            else if (op == "<")  v = a < b;
            else if (op == ">=") v = a >= b;
            else if (op == "<=") v = a <= b;
            else if (op == "==") v = a == b;
            else if (op == "!=") v = a != b;
            else if (op == "&&") v = (a != 0.0) && (b != 0.0);
            else if (op == "||") v = (a != 0.0) || (b != 0.0);
            result.type = "boolean";
            result.ival = v;
            return result;
        }

        default:
            throw runtime_error("Runtime error: cannot evaluate this expression node.");
    }
}

void Interpreter::execStatement(ASTNode* stmt) {
    if (!stmt) return;

    switch (stmt->type) {
        case NODE_VARDECL: {
            table->declare(stmt->sval, stmt->datatype, stmt->isFinal);
            if (!stmt->children.empty()) {
                Value v = evalExpr(stmt->children[0]);
                assignTo(stmt->sval, v);
            }
            break;
        }

        case NODE_ASSIGN: {
            Value v = evalExpr(stmt->children[0]);
            assignTo(stmt->sval, v);
            break;
        }

    case NODE_COMPOUND_ASSIGN: {
            Symbol* sym = table->lookup(stmt->sval);
            if (!sym) throw runtime_error("Runtime error: variable '" + stmt->sval + "' not declared.");
            Value cur;
            cur.type = sym->type; cur.ival = sym->value.ival;
            cur.fval = sym->value.fval; cur.cval = sym->value.cval; cur.sval = sym->value.sval;

            Value rhs = evalExpr(stmt->children[0]);

            if (sym->type == "String") {
                // Only "+=" (concatenation) makes sense for String.
                Value result;
                result.type = "String";
                result.sval = cur.sval + rhs.toDisplayString();
                assignTo(stmt->sval, result);
                break;
            }

            double a = cur.asDouble(), b = rhs.asDouble();
            double v = 0;
            if (stmt->op == "+=") v = a + b;
            else if (stmt->op == "-=") v = a - b;
            else if (stmt->op == "*=") v = a * b;
            else if (stmt->op == "/=") {
                if (b == 0.0) throw runtime_error("Runtime error: division by zero.");
                v = a / b;
            }
            else if (stmt->op == "%=") {
                if (b == 0.0) throw runtime_error("Runtime error: division by zero.");
                v = fmod(a, b);
            }
            Value result;
            if (sym->type == "float" || sym->type == "double") { result.type = sym->type; result.fval = v; }
            else { result.type = "int"; result.ival = (int)v; }
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
                    continue; // re-checks the condition immediately, correct for while
                } catch (BreakSignal&) {
                    break;
                }
            }
            break;
        }

        case NODE_FOR: {
            table->pushScope("for");
            if (stmt->children[0]) execStatement(stmt->children[0]);
            while (stmt->children[1] == nullptr || evalExpr(stmt->children[1]).asDouble() != 0.0) {
                try {
                    execBlock(stmt->children[3]);
                } catch (ContinueSignal&) {
                    // fall through: the update step below must still run
                } catch (BreakSignal&) {
                    break;
                }
                if (stmt->children[2]) execStatement(stmt->children[2]);
            }
            table->popScope();
            break;
        }

        case NODE_DO_WHILE: {
            do {
                try {
                    execBlock(stmt->children[0]);
                } catch (ContinueSignal&) {
                    // fall through: the condition below is checked next, exactly
                    // like a real do-while's "continue" jumping to the test.
                } catch (BreakSignal&) {
                    break;
                }
            } while (evalExpr(stmt->children[1]).asDouble() != 0.0);
            break;
        }

        case NODE_SWITCH: {
            Value sel = evalExpr(stmt->children[0]);
            int startIndex = -1;
            int defaultIndex = -1;

            for (size_t i = 1; i < stmt->children.size(); i++) {
                ASTNode* clause = stmt->children[i];
                if (clause->type == NODE_DEFAULT) { defaultIndex = (int)i; continue; }

                bool eq = false;
                if (clause->caseKind == "int") {
                    if (sel.type == "char") eq = ((int)sel.cval == clause->ival);
                    else if (sel.type != "String") eq = ((int)sel.asDouble() == clause->ival);
                } else if (clause->caseKind == "char") {
                    eq = (sel.type == "char" && sel.cval == clause->cval);
                } else if (clause->caseKind == "String") {
                    eq = (sel.type == "String" && sel.sval == clause->sval);
                }
                if (eq) { startIndex = (int)i; break; }
            }
            if (startIndex == -1) startIndex = defaultIndex; // no case matched -> fall back to default (any position)

            if (startIndex != -1) {
                try {
                    // Java "fall-through" semantics: once a case matches, execution
                    // continues through subsequent clauses until a break.
                    for (size_t i = (size_t)startIndex; i < stmt->children.size(); i++) {
                        execBlock(stmt->children[i]);
                    }
                } catch (BreakSignal&) {
                    // handled: stop falling through
                }
            }
            break;
        }

        case NODE_IMPORT:
            // no runtime effect
            break;

        case NODE_BREAK:
            throw BreakSignal{};

        case NODE_CONTINUE:
            throw ContinueSignal{};

        case NODE_PRINT: {
            if (!stmt->children.empty()) {
                Value v = evalExpr(stmt->children[0]);
                printValue(v);
            }
            if (stmt->ival) cout << "\n"; // println adds the trailing newline
            break;
        }

        case NODE_RETURN: {
            ReturnSignal sig;
            if (!stmt->children.empty()) sig.value = evalExpr(stmt->children[0]);
            throw sig;
        }

        case NODE_BLOCK:
            execBlock(stmt);
            break;

        default:
            // A bare expression statement, e.g. "a++;"
            evalExpr(stmt);
            break;
    }
}
