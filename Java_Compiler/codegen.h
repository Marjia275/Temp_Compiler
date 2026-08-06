
#ifndef CODEGEN_H
#define CODEGEN_H

#include <string>
#include <vector>

class CodeGenerator {
public:
    std::vector<std::string> generate(const std::vector<std::string>& tac);
};

#endif // CODEGEN_H
