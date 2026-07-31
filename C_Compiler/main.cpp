
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

#include "ast.h"
#include "symbol_table.h"
#include "semantic.h"
#include "interpreter.h"
#include "tac.h"
#include "codegen.h"
#include "assembly.h"

using namespace std;


extern FILE* yyin;
extern int yylex();
extern int yyparse();
extern int yylineno;
void yyrestart(FILE*);

ASTNode* astRoot = nullptr;
bool g_syntaxOk = false;
bool g_debugMode = false;

static void printSection(const string& title) {
    cout << endl << "-----------------------------------------" << endl;
    cout << title << endl;
    cout << "-----------------------------------------" << endl;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input.c> [--debug]" << endl;
        return 1;
    }

    string filename = argv[1];
    bool debug = (argc > 2 && string(argv[2]) == "--debug");

    FILE* file = fopen(filename.c_str(), "r");
    if (!file) {
        cerr << "Error: cannot open file '" << filename << "'" << endl;
        return 1;
    }

    if (debug) {
        cout << "=========================================" << endl;
        cout << "        MINI C COMPILER" << endl;
        cout << "=========================================" << endl;
        cout << "Reading File..............OK" << endl;
    }

    
    if (debug) {
        printSection("1. LEXICAL ANALYSIS");
        yyin = file;
        g_debugMode = true;
        while (yylex() != 0) {  }
        g_debugMode = false;
        rewind(file);
        yylineno = 1;
        yyrestart(file);
    } else {
        yyin = file;
    }

    // ---------------- Phase 2: Syntax Analysis (build AST) ----------------
    int parseResult = yyparse();
    fclose(file);

    if (debug) printSection("2. PARSER OUTPUT");

    if (parseResult != 0 || !g_syntaxOk || astRoot == nullptr) {
        cout << "Syntax Error - compilation stopped." << endl;
        return 1;
    }
    if (debug) cout << "Parsing Successful" << endl;

    if (debug) {
        printSection("3. AST OUTPUT");
        printAST(astRoot);
    }

    // ---------------- Phase 3: Semantic Analysis ----------------
    SemanticAnalyzer analyzer;
    vector<string> errors;
    bool semanticOk = analyzer.analyze(astRoot, errors);

    if (debug) printSection("4. SEMANTIC ANALYSIS");

    if (!semanticOk) {
        cout << "Semantic Error:" << endl;
        for (auto& e : errors) cout << "  " << e << endl;
        return 1;
    }
    if (debug) cout << "Semantic Analysis Successful" << endl;

    // ---------------- Phase 4: TAC / Codegen / Assembly (debug only) ----------------
    TACGenerator tacGen;
    vector<string> tac = tacGen.generate(astRoot);

    if (debug) {
        printSection("5. THREE ADDRESS CODE (TAC)");
        for (auto& l : tac) cout << l << endl;

        CodeGenerator codeGen;
        vector<string> code = codeGen.generate(tac);
        printSection("6. CODE GENERATION");
        for (auto& l : code) cout << l << endl;

        AssemblyGenerator asmGen;
        vector<string> asmCode = asmGen.generate(tac);
        printSection("7. ASSEMBLY OUTPUT");
        for (auto& l : asmCode) cout << l << endl;
    }

    // ---------------- Phase 5: Interpretation (the real program output) ----------------
    if (debug) printSection("8. PROGRAM OUTPUT");

    Interpreter interp;
    SymbolTable runtimeTable;
    try {
        interp.run(astRoot, runtimeTable);
    } catch (std::exception& e) {
        cout << endl << e.what() << endl;
        return 1;
    }

    if (debug) {
        cout << endl;
        printSection("9. SYMBOL TABLE (final values)");
        runtimeTable.print();
        cout << endl << "Compilation Successful" << endl;
    }

    return 0;
}
