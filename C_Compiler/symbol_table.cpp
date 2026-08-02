// ============================================================
// symbol_table.cpp
// ============================================================
#include "symbol_table.h"
#include <iostream>
#include <iomanip>

using namespace std;

SymbolTable::SymbolTable() {
    
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
        return false; 
    }
    Symbol s;
    s.name = name;
    s.type = type;
    s.scope = currentScopeName();
    s.isConst = isConst;
    s.value.type = type;
    current[name] = s;
    return true;
}

Symbol* SymbolTable::lookup(const std::string& name) {
  
    for (int i = (int)scopes.size() - 1; i >= 0; i--) {
        auto it = scopes[i].find(name);
        if (it != scopes[i].end()) {
            return &it->second;
        }
    }
    return nullptr;
}

void SymbolTable::print() const {
    cout << left << setw(10) << "Name" << setw(10) << "Type"
         << setw(16) << "Value" << setw(10) << "Scope" << endl;
    cout << "----------------------------------------------" << endl;
    for (auto& scope : scopes) {
        for (auto& pair : scope) {
            const Symbol& s = pair.second;
            string typeLabel = s.isConst ? ("const " + s.type) : s.type;
            cout << left << setw(10) << s.name << setw(16) << typeLabel;
            if (s.type == "int")         cout << setw(16) << s.value.ival;
            else if (s.type == "float")  cout << setw(16) << s.value.fval;
            else if (s.type == "double") cout << setw(16) << s.value.fval;
            else if (s.type == "char")   cout << setw(16) << s.value.cval;
            else if (s.type == "long")   cout << setw(16) << s.value.lval;
            cout << setw(10) << s.scope << endl;
        }
    }
}
