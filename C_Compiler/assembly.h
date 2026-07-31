// ============================================================
// assembly.h
// Translates Three Address Code into readable pseudo x86 assembly.
// Educational only — used in --debug output.
// ============================================================
#ifndef ASSEMBLY_H
#define ASSEMBLY_H

#include <string>
#include <vector>

class AssemblyGenerator {
public:
    std::vector<std::string> generate(const std::vector<std::string>& tac);
};

#endif // ASSEMBLY_H
