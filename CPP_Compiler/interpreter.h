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

// A runtime value. Only the field(s) matching 'type' are meaningful.
// "cout" / "cin" / "endl" are special marker types used only while
// evaluating a stream expression like "cout << a << endl;" - they are
// never stored in a variable.
struct Value {
    std::string type; // "int","float","double","char","bool","string","long","long long","unsigned long long","cout","cin","endl"
    long long ival = 0; // also doubles as the bool value (0/1); widened for long/long long
    double fval = 0.0;
    char   cval = 0;
    std::string sval;

    double asDouble() const {
        if (type == "float" || type == "double") return fval;
        if (type == "char")  return (double)cval;
        return (double)ival; // int, bool, long, long long, unsigned long long
    }

    // Integer-domain accessor: avoids round-tripping large integers
    // through a double (which only has 53 bits of exact precision).
    long long asLongLong() const {
        if (type == "float" || type == "double") return (long long)fval;
        if (type == "char") return (long long)cval;
        return ival; // int, bool, long, long long, unsigned long long
    }

    // True for any of the integral (non-floating, non-string) types.
    bool isIntegral() const {
        return type == "int" || type == "bool" || type == "char" ||
               type == "long" || type == "long long" || type == "unsigned long long" ||
               type == "unsigned int";
    }

    // A human readable stringification, used for string concatenation
    // and for storing a non-string value into a string variable.
    std::string toDisplayString() const;
};

// Thrown internally to unwind the tree when "return" runs.
struct ReturnSignal {
    Value value;
};

// Thrown internally to unwind out of the nearest loop body.
struct BreakSignal {};
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
    Value evalExpr(ASTNode* expr);
    void assignTo(const std::string& name, const Value& v);
    void printValue(const Value& v);   // used by "cout << v"
    void readValue(const std::string& varName); // used by "cin >> var"
};

#endif // INTERPRETER_H
