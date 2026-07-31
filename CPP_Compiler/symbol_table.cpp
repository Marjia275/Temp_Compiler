// ============================================================
// symbol_table.cpp
// ============================================================
#include "symbol_table.h"
#include <iostream>
#include <iomanip>

using namespace std;

SymbolTable::SymbolTable() {
    // "main" is the outermost scope of our single-function programs.
    pushScope("main");
}

void SymbolTable::pushScope(const std::string& scopeName) {
    scopeNames.push_back(scopeName);
    scopes.push_back(unordered_map<string, Symbol>());
}

void SymbolTable::popScope() {
    if (!scopes.empty()) {
        scopes.pop_back();
        scopeNames.pop_back();
    }
}

std::string SymbolTable::currentScopeName() const {
    if (scopeNames.empty()) return "";
    return scopeNames.back();
}

bool SymbolTable::declare(const std::string& name, const std::string& type, bool isConst) {
    auto& current = scopes.back();
    if (current.find(name) != current.end()) {
        return false; // duplicate declaration in this scope
    }
    Symbol s;
    s.name = name;
    s.type = type;
    s.scope = currentScopeName();
    s.value.type = type;
    s.isConst = isConst;
    current[name] = s;
    return true;
}

Symbol* SymbolTable::lookup(const std::string& name) {
    // Search innermost scope outward so inner "for" scopes shadow outer ones.
    for (int i = (int)scopes.size() - 1; i >= 0; i--) {
        auto it = scopes[i].find(name);
        if (it != scopes[i].end()) {
            return &it->second;
        }
    }
    return nullptr;
}

void SymbolTable::print() const {
    cout << left << setw(10) << "Name" << setw(20) << "Type"
         << setw(15) << "Value" << setw(10) << "Scope" << endl;
    cout << "----------------------------------------------" << endl;
    for (auto& scope : scopes) {
        for (auto& pair : scope) {
            const Symbol& s = pair.second;
            cout << left << setw(10) << s.name << setw(20) << s.type;
            if (s.type == "int" || s.type == "long" || s.type == "long long" || s.type == "unsigned long long")
                                                cout << setw(15) << s.value.ival;
            else if (s.type == "float" || s.type == "double") cout << setw(15) << s.value.fval;
            else if (s.type == "char")         cout << setw(15) << s.value.cval;
            else if (s.type == "bool")         cout << setw(15) << (s.value.ival ? "true" : "false");
            else if (s.type == "string")       cout << setw(15) << s.value.sval;
            cout << setw(10) << s.scope << endl;
        }
    }
}
