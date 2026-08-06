
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
    void checkAssignTarget(const std::string& name);
};

#endif // SEMANTIC_H
