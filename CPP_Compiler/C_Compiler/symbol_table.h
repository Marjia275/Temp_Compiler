// ============================================================
// symbol_table.h
// Stores variable name, datatype, scope, const-ness and current value.
// ============================================================
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <vector>
#include <unordered_map>

struct SymbolValue {
    std::string type;   // "int", "float", "double", "char", "long"
    int       ival = 0;
    double    fval = 0.0;   // also used for "double"
    char      cval = 0;
    long long lval = 0;     // used for "long" (covers long int / long long / unsigned long long)
};

struct Symbol {
    std::string name;
    std::string type;
    std::string scope;
    bool isConst = false;
    bool initialized = false;
    SymbolValue value;
};

// A single scope = one map of name -> Symbol.
// The SymbolTable is a stack of scopes so "for(int i ...)" gets its
// own scope that disappears once the loop is done, while variables
// declared directly inside main() live in the "main" (global-ish) scope.
class SymbolTable {
public:
    SymbolTable();

    void pushScope(const std::string& scopeName);
    void popScope();
    std::string currentScopeName() const;

    // Declares a new variable in the CURRENT scope.
    // Returns false if it already exists in the current scope (duplicate declaration).
    bool declare(const std::string& name, const std::string& type, bool isConst = false);

    // Looks up a variable across all active scopes (innermost first).
    // Returns nullptr if not found (undeclared variable).
    Symbol* lookup(const std::string& name);

    // Prints the full table for --debug mode.
    void print() const;

private:
    std::vector<std::string> scopeNames;
    std::vector<std::unordered_map<std::string, Symbol>> scopes;
};

#endif // SYMBOL_TABLE_H
