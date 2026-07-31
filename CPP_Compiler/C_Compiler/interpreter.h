// ============================================================
// interpreter.h
// Executes the AST directly (tree-walking interpreter) and
// produces the actual program output — the same thing gcc
// would print if you compiled and ran the real input.c
// ============================================================
#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "ast.h"
#include "symbol_table.h"
#include <string>

// A runtime value. Only one of ival/fval/cval/lval is meaningful,
// selected by 'type'. "double" reuses the fval slot (same as "float").
struct Value {
    std::string type; // "int", "float", "double", "char", "long"
    int       ival = 0;
    double    fval = 0.0;
    char      cval = 0;
    long long lval = 0;

    double asDouble() const {
        if (type == "float" || type == "double") return fval;
        if (type == "char")  return (double)cval;
        if (type == "long")  return (double)lval;
        return (double)ival;
    }

    long long asLongLong() const {
        if (type == "float" || type == "double") return (long long)fval;
        if (type == "char")  return (long long)cval;
        if (type == "long")  return lval;
        return (long long)ival;
    }

    bool isFloatingType() const { return type == "float" || type == "double"; }
};

// Thrown internally to unwind the tree when control-flow statements run.
struct ReturnSignal   { Value value; };
struct BreakSignal    {};
struct ContinueSignal {};

class Interpreter {
public:
    // Executes the whole program. Writes SymbolTable snapshot in
    // 'finalTable' so main.cpp can print it in --debug mode.
    void run(ASTNode* program, SymbolTable& finalTable);

private:
    SymbolTable* table;

    void execBlock(ASTNode* block);
    void execStatement(ASTNode* stmt);
    void execLoopBody(ASTNode* body); // runs a loop body, letting Break/Continue propagate to the caller
    Value evalExpr(ASTNode* expr);
    void doPrintf(ASTNode* node);
    void doScanf(ASTNode* node);
    Value doCall(ASTNode* node);
    Value doSizeof(ASTNode* node);
    void assignTo(const std::string& name, const Value& v);
    int typeSize(const std::string& type);
};

#endif // INTERPRETER_H
