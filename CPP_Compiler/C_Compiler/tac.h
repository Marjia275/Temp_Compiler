// ============================================================
// tac.h
// Generates Three Address Code (TAC) from the AST.
// This is purely for the --debug educational output; it does
// NOT run the program (the Interpreter does that separately).
// ============================================================
#ifndef TAC_H
#define TAC_H

#include "ast.h"
#include <string>
#include <vector>

class TACGenerator {
public:
    // Returns the generated TAC, one instruction per vector entry.
    std::vector<std::string> generate(ASTNode* program);

private:
    std::vector<std::string> lines;
    int tempCount = 0;
    int labelCount = 0;

    std::string newTemp();
    std::string newLabel();
    void emit(const std::string& instr);

    void genBlock(ASTNode* block);
    void genStatement(ASTNode* stmt);
    std::string genExpr(ASTNode* expr); // returns the operand holding the result
};

#endif // TAC_H
