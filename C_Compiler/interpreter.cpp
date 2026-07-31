// ============================================================
// interpreter.cpp
// ============================================================
#include "interpreter.h"
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <stdexcept>

using namespace std;

void Interpreter::run(ASTNode* program, SymbolTable& finalTable) {
    table = &finalTable;
    try {
        execBlock(program);
    } catch (ReturnSignal&) {
        
    } catch (BreakSignal&) {
        
    } catch (ContinueSignal&) {
        
    }
}

void Interpreter::execBlock(ASTNode* block) {
    if (!block) return;
    for (auto stmt : block->children) {
        execStatement(stmt);
    }
}

int Interpreter::typeSize(const std::string& type) {
    if (type == "int")    return 4;
    if (type == "float")  return 4;
    if (type == "double") return 8;
    if (type == "char")   return 1;
    if (type == "long")   return 8;
    return 4;
}

void Interpreter::assignTo(const std::string& name, const Value& v) {
    Symbol* sym = table->lookup(name);
    if (!sym) {
        throw runtime_error("Runtime Error:\nVariable '" + name + "' not declared.");
    }
    if (sym->isConst && sym->initialized) {
        throw runtime_error("Runtime Error:\nCannot modify constant variable '" + name + "'.");
    }
    if (sym->type == "int") {
        sym->value.ival = (v.type == "float" || v.type == "double") ? (int)v.fval :
                           (v.type == "char")  ? (int)v.cval :
                           (v.type == "long")  ? (int)v.lval : v.ival;
    } else if (sym->type == "float" || sym->type == "double") {
        sym->value.fval = v.asDouble();
    } else if (sym->type == "char") {
        sym->value.cval = (v.type == "char") ? v.cval : (char)(int)v.asDouble();
    } else if (sym->type == "long") {
        sym->value.lval = v.asLongLong();
    }
    sym->initialized = true;
}

Value Interpreter::doSizeof(ASTNode* node) {
    Value result; result.type = "int";
    if (!node->datatype.empty()) {
        result.ival = typeSize(node->datatype);
    } else {
        Value v = evalExpr(node->children[0]);
        result.ival = typeSize(v.type);
    }
    return result;
}

Value Interpreter::doCall(ASTNode* node) {
    Value result;
    if (node->sval == "pow") {
        Value a = evalExpr(node->children[0]);
        Value b = evalExpr(node->children[1]);
        result.type = "double";
        result.fval = pow(a.asDouble(), b.asDouble());
        return result;
    }

    Value a = evalExpr(node->children[0]);
    if (node->sval == "sqrt") {
        if (a.asDouble() < 0) throw runtime_error("Runtime Error:\nsqrt() of a negative number.");
        result.type = "double";
        result.fval = sqrt(a.asDouble());
    } else if (node->sval == "abs") {
        if (a.isFloatingType()) { result.type = a.type; result.fval = fabs(a.fval); }
        else if (a.type == "long") { result.type = "long"; result.lval = llabs(a.lval); }
        else { result.type = "int"; result.ival = std::abs(a.ival); }
    } else if (node->sval == "ceil") {
        result.type = "double";
        result.fval = ceil(a.asDouble());
    } else if (node->sval == "floor") {
        result.type = "double";
        result.fval = floor(a.asDouble());
    }
    return result;
}

Value Interpreter::evalExpr(ASTNode* node) {
    Value result;

    switch (node->type) {
        case NODE_NUM_INT:
            if (node->datatype == "long") { result.type = "long"; result.lval = node->llit; }
            else { result.type = "int"; result.ival = node->ival; }
            return result;

        case NODE_NUM_FLOAT:
            result.type = "float";
            result.fval = node->fval;
            return result;

        case NODE_CHAR:
            result.type = "char";
            result.cval = node->cval;
            return result;

        case NODE_STRING:
            result.type = "string"; 
            return result;

        case NODE_ID: {
            Symbol* sym = table->lookup(node->sval);
            if (!sym) throw runtime_error("Runtime Error:\nVariable '" + node->sval + "' not declared.");
            result.type = sym->type;
            result.ival = sym->value.ival;
            result.fval = sym->value.fval;
            result.cval = sym->value.cval;
            result.lval = sym->value.lval;
            return result;
        }

        case NODE_UNOP: {
            Value v = evalExpr(node->children[0]);
            if (node->op == "-") {
                if (v.isFloatingType()) { result.type = v.type; result.fval = -v.fval; }
                else if (v.type == "long") { result.type = "long"; result.lval = -v.lval; }
                else { result.type = "int"; result.ival = -(int)v.asLongLong(); }
            } else if (node->op == "!") {
                result.type = "int";
                result.ival = (v.asDouble() == 0.0) ? 1 : 0;
            } else if (node->op == "~") {
                long long nv = ~v.asLongLong();
                if (v.type == "long") { result.type = "long"; result.lval = nv; }
                else { result.type = "int"; result.ival = (int)nv; }
            }
            return result;
        }

        case NODE_TERNARY: {
            Value c = evalExpr(node->children[0]);
            return (c.asDouble() != 0.0) ? evalExpr(node->children[1]) : evalExpr(node->children[2]);
        }

        case NODE_SIZEOF:
            return doSizeof(node);

        case NODE_CALL:
            return doCall(node);

        case NODE_PREINC: case NODE_PREDEC:
        case NODE_POSTINC: case NODE_POSTDEC: {
            Symbol* sym = table->lookup(node->sval);
            if (!sym) throw runtime_error("Runtime Error:\nVariable '" + node->sval + "' not declared.");
            if (sym->isConst) throw runtime_error("Runtime Error:\nCannot modify constant variable '" + node->sval + "'.");

            Value oldVal;
            oldVal.type = sym->type; oldVal.ival = sym->value.ival;
            oldVal.fval = sym->value.fval; oldVal.cval = sym->value.cval; oldVal.lval = sym->value.lval;

            int delta = (node->type == NODE_PREINC || node->type == NODE_POSTINC) ? 1 : -1;
            if (sym->type == "float" || sym->type == "double") sym->value.fval += delta;
            else if (sym->type == "char") sym->value.cval += delta;
            else if (sym->type == "long") sym->value.lval += delta;
            else sym->value.ival += delta;

            if (node->type == NODE_PREINC || node->type == NODE_PREDEC) {
                result.type = sym->type;
                result.ival = sym->value.ival; result.fval = sym->value.fval;
                result.cval = sym->value.cval; result.lval = sym->value.lval;
            } else {
                result = oldVal;
            }
            return result;
        }

        case NODE_BINOP: {
            Value l = evalExpr(node->children[0]);
            Value r = evalExpr(node->children[1]);
            const string& op = node->op;

            if (op == "&" || op == "|" || op == "^" || op == "<<" || op == ">>") {
                long long a = l.asLongLong(), b = r.asLongLong();
                long long v;
                if (op == "&") v = a & b;
                else if (op == "|") v = a | b;
                else if (op == "^") v = a ^ b;
                else if (op == "<<") v = a << b;
                else v = a >> b;
                if (l.type == "long" || r.type == "long") { result.type = "long"; result.lval = v; }
                else { result.type = "int"; result.ival = (int)v; }
                return result;
            }

            bool useFloat = l.isFloatingType() || r.isFloatingType();

            if (op == "+" || op == "-" || op == "*" || op == "/" || op == "%") {
                if (useFloat) {
                    double a = l.asDouble(), b = r.asDouble();
                    if ((op == "/" || op == "%") && b == 0.0) {
                        throw runtime_error("Runtime Error:\nDivision by zero.");
                    }
                    double v = (op == "+") ? a + b :
                               (op == "-") ? a - b :
                               (op == "*") ? a * b :
                               (op == "/") ? a / b : fmod(a, b);
                    result.type = (l.type == "double" || r.type == "double") ? "double" : "float";
                    result.fval = v;
                    return result;
                } else {
                    long long a = l.asLongLong(), b = r.asLongLong();
                    if ((op == "/" || op == "%") && b == 0) {
                        throw runtime_error(string("Runtime Error:\n") + (op == "/" ? "Division by zero." : "Modulo by zero."));
                    }
                    long long v = (op == "+") ? a + b :
                                  (op == "-") ? a - b :
                                  (op == "*") ? a * b :
                                  (op == "/") ? a / b : a % b;
                    if (l.type == "long" || r.type == "long") { result.type = "long"; result.lval = v; }
                    else { result.type = "int"; result.ival = (int)v; }
                    return result;
                }
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
            result.type = "int";
            result.ival = v;
            return result;
        }

        default:
            throw runtime_error("Runtime Error:\nCannot evaluate this expression node.");
    }
}

void Interpreter::doPrintf(ASTNode* node) {
    const string& fmt = node->sval;
    size_t argIndex = 0;

    for (size_t i = 0; i < fmt.size(); i++) {
        if (fmt[i] == '%' && i + 1 < fmt.size()) {
            if (fmt.compare(i + 1, 3, "lld") == 0) {
                Value v = evalExpr(node->children[argIndex++]);
                cout << v.asLongLong();
                i += 3;
                continue;
            }
            if (fmt.compare(i + 1, 2, "ld") == 0) {
                Value v = evalExpr(node->children[argIndex++]);
                cout << v.asLongLong();
                i += 2;
                continue;
            }
            if (fmt.compare(i + 1, 2, "lf") == 0) {
                Value v = evalExpr(node->children[argIndex++]);
                printf("%f", v.asDouble());
                i += 2;
                continue;
            }
            char spec = fmt[i + 1];
            if (spec == 'd') {
                Value v = evalExpr(node->children[argIndex++]);
                cout << (int)v.asLongLong();
                i++;
                continue;
            } else if (spec == 'f') {
                Value v = evalExpr(node->children[argIndex++]);
                printf("%f", v.asDouble());
                i++;
                continue;
            } else if (spec == 'c') {
                Value v = evalExpr(node->children[argIndex++]);
                cout << (char)(v.type == "char" ? v.cval : (int)v.asDouble());
                i++;
                continue;
            } else if (spec == 's') {
                
                ASTNode* argNode = node->children[argIndex++];
                if (argNode->type == NODE_STRING) cout << argNode->sval;
                i++;
                continue;
            } else if (spec == '%') {
                cout << '%';
                i++;
                continue;
            }
        }
        cout << fmt[i];
    }
}

void Interpreter::doScanf(ASTNode* node) {
    const string& fmt = node->sval;
    size_t argIndex = 0;

    for (size_t i = 0; i < fmt.size(); i++) {
        if (fmt[i] != '%' || i + 1 >= fmt.size()) continue;

        string expectedType;
        size_t skip;
        if (fmt.compare(i + 1, 3, "lld") == 0)      { expectedType = "long";   skip = 3; }
        else if (fmt.compare(i + 1, 2, "ld") == 0)  { expectedType = "long";   skip = 2; }
        else if (fmt.compare(i + 1, 2, "lf") == 0)  { expectedType = "double"; skip = 2; }
        else if (fmt[i + 1] == 'd')                 { expectedType = "int";    skip = 1; }
        else if (fmt[i + 1] == 'f')                 { expectedType = "float";  skip = 1; }
        else if (fmt[i + 1] == 'c')                 { expectedType = "char";   skip = 1; }
        else { continue; }

        i += skip;
        if (argIndex >= node->children.size()) continue;

        const string& varName = node->children[argIndex++]->sval;
        Symbol* sym = table->lookup(varName);
        if (!sym) throw runtime_error("Runtime Error:\nVariable '" + varName + "' not declared.");
        if (sym->isConst) throw runtime_error("Runtime Error:\nCannot modify constant variable '" + varName + "'.");
        if (sym->type != expectedType) {
            throw runtime_error("Runtime Error:\nFormat specifier does not match variable type.");
        }

        bool ok = true;
        if (expectedType == "int") { int x; ok = (bool)(cin >> x); if (ok) sym->value.ival = x; }
        else if (expectedType == "float" || expectedType == "double") { double x; ok = (bool)(cin >> x); if (ok) sym->value.fval = x; }
        else if (expectedType == "char") { char c; ok = (bool)(cin >> c); if (ok) sym->value.cval = c; }
        else if (expectedType == "long") { long long x; ok = (bool)(cin >> x); if (ok) sym->value.lval = x; }

        if (!ok) throw runtime_error("Runtime Error:\nInvalid input provided to scanf().");
        sym->initialized = true;
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
            Value v = evalExpr(stmt->children[0]);
            assignTo(stmt->sval, v);
            break;
        }

        case NODE_COMPOUND_ASSIGN: {
            Symbol* sym = table->lookup(stmt->sval);
            if (!sym) throw runtime_error("Runtime Error:\nVariable '" + stmt->sval + "' not declared.");
            if (sym->isConst) throw runtime_error("Runtime Error:\nCannot modify constant variable '" + stmt->sval + "'.");
            Value cur;
            cur.type = sym->type; cur.ival = sym->value.ival;
            cur.fval = sym->value.fval; cur.cval = sym->value.cval; cur.lval = sym->value.lval;

            Value rhs = evalExpr(stmt->children[0]);
            double a = cur.asDouble(), b = rhs.asDouble();
            double v = 0;
            if (stmt->op == "+=") v = a + b;
            else if (stmt->op == "-=") v = a - b;
            else if (stmt->op == "*=") v = a * b;
            else if (stmt->op == "/=") {
                if (b == 0.0) throw runtime_error("Runtime Error:\nDivision by zero.");
                v = a / b;
            }
            Value result;
            if (sym->type == "float" || sym->type == "double") { result.type = sym->type; result.fval = v; }
            else if (sym->type == "long") { result.type = "long"; result.lval = (long long)v; }
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
                } catch (BreakSignal&) {
                    break;
                } catch (ContinueSignal&) {
             
                }
            }
            break;
        }

        case NODE_DOWHILE: {
            bool cont = true;
            do {
                try {
                    execBlock(stmt->children[0]);
                } catch (BreakSignal&) {
                    cont = false;
                    break;
                } catch (ContinueSignal&) {
                    
                }
            } while (cont && evalExpr(stmt->children[1]).asDouble() != 0.0);
            break;
        }

        case NODE_FOR: {
            table->pushScope("for");
            if (stmt->children[0]) execStatement(stmt->children[0]);
            while (stmt->children[1] == nullptr || evalExpr(stmt->children[1]).asDouble() != 0.0) {
                bool doBreak = false;
                try {
                    execBlock(stmt->children[3]);
                } catch (BreakSignal&) {
                    doBreak = true;
                } catch (ContinueSignal&) {
    
                }
                if (doBreak) break;
                if (stmt->children[2]) execStatement(stmt->children[2]);
            }
            table->popScope();
            break;
        }

        case NODE_SWITCH: {
            Value v = evalExpr(stmt->children[0]);
            long long switchVal = v.asLongLong();
            int matchIdx = -1, defaultIdx = -1;
            for (size_t i = 1; i < stmt->children.size(); i++) {
                ASTNode* c = stmt->children[i];
                if (c->type == NODE_CASE && c->ival == (int)switchVal) { matchIdx = (int)i; break; }
                if (c->type == NODE_DEFAULT) defaultIdx = (int)i;
            }
            int startIdx = (matchIdx != -1) ? matchIdx : defaultIdx;
            if (startIdx != -1) {
                try {
                    for (size_t i = (size_t)startIdx; i < stmt->children.size(); i++) {
                        execBlock(stmt->children[i]->children[0]);
                    }
                } catch (BreakSignal&) {
                    
                }
            }
            break;
        }

        case NODE_BREAK:
            throw BreakSignal();

        case NODE_CONTINUE:
            throw ContinueSignal();

        case NODE_PRINTF:
            doPrintf(stmt);
            break;

        case NODE_SCANF:
            doScanf(stmt);
            break;

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
