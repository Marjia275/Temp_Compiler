// ============================================================
// semantic.h
// Static checks performed BEFORE the program is executed:
//   - undeclared variable used
//   - duplicate declaration in the same scope
//   - division by a literal zero
//   - modification of a const variable
//   - break/continue used outside a loop/switch
//   - bitwise operators used on non-integer operands
// ============================================================
#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "ast.h"
#include "symbol_table.h"

class SemanticAnalyzer {
public:
    // Returns true if no semantic errors were found.
    // Fills 'errors' with human readable messages otherwise.
    bool analyze(ASTNode* program, std::vector<std::string>& errors);

private:
    SymbolTable table;
    std::vector<std::string>* errors;
    int loopDepth = 0;
    int switchDepth = 0;

    void visit(ASTNode* node);
    void checkExpr(ASTNode* node);
    void checkLValue(ASTNode* node); // checks a name is declared and not const, used for assignments
    std::string inferType(ASTNode* node); // best-effort static type inference
    void error(ASTNode* node, const std::string& msg);
};

#endif // SEMANTIC_H
