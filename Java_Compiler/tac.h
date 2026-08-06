
#ifndef TAC_H
#define TAC_H

#include "ast.h"
#include <string>
#include <vector>
#include <utility>

class TACGenerator {
public:
    // Returns the generated TAC, one instruction per vector entry.
    std::vector<std::string> generate(ASTNode* program);

private:
    std::vector<std::string> lines;
    int tempCount = 0;
    int labelCount = 0;

    // (continueTargetLabel, breakTargetLabel) for the loop currently being generated
    std::vector<std::pair<std::string, std::string>> loopLabels;

    std::string newTemp();
    std::string newLabel();
    void emit(const std::string& instr);

    void genBlock(ASTNode* block);
    void genStatement(ASTNode* stmt);
    std::string genExpr(ASTNode* expr); // returns the operand holding the result
};

#endif // TAC_H
