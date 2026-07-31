// ============================================================
// semantic.h
// Static checks performed BEFORE the program is executed:
//   - undeclared variable used
//   - duplicate declaration in the same scope
//   - division by a literal zero
//   - very basic type compatibility (char used where clearly wrong)
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

    void visit(ASTNode* node);
    void checkExpr(ASTNode* node);
    bool isCinChain(ASTNode* node); // true if node is "cin" or "(...>> ...) >> ..." rooted at cin
};

#endif // SEMANTIC_H
