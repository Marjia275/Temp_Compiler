
#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "ast.h"
#include "symbol_table.h"
#include <string>

// A runtime value. Only the field(s) matching 'type' are meaningful.
struct Value {
    std::string type; // "int","float","double","char","boolean","String"
    int    ival = 0;  // also doubles as the boolean value (0/1)
    double fval = 0.0;
    char   cval = 0;
    std::string sval;

    double asDouble() const {
        if (type == "float" || type == "double") return fval;
        if (type == "char")  return (double)cval;
        return (double)ival; // int and boolean
    }

    // A human readable stringification, used for String concatenation
    // and for storing a non-String value into a String variable.
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
    void printValue(const Value& v); // used by System.out.print/println
};

#endif // INTERPRETER_H
