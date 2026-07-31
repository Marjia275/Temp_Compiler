// ============================================================
// ast.cpp
// AST debug pretty-printer
// ============================================================
#include "ast.h"
#include <iostream>

using namespace std;

static void pad(int indent) {
    for (int i = 0; i < indent; i++) cout << "  ";
}

void printAST(ASTNode* node, int indent) {
    if (!node) return;

    switch (node->type) {
        case NODE_PROGRAM:
            pad(indent); cout << "Program" << endl;
            for (auto c : node->children) printAST(c, indent + 1);
            break;

        case NODE_BLOCK:
            pad(indent); cout << "Block" << endl;
            for (auto c : node->children) printAST(c, indent + 1);
            break;

        case NODE_VARDECL:
            pad(indent); cout << "Declaration (" << (node->isConst ? "const " : "") << node->datatype << " " << node->sval;
            if (!node->children.empty()) cout << " = <init>";
            cout << ")" << endl;
            if (!node->children.empty()) printAST(node->children[0], indent + 1);
            break;

        case NODE_ASSIGN:
            pad(indent); cout << "Assign (" << node->sval << " = )" << endl;
            if (!node->children.empty()) printAST(node->children[0], indent + 1);
            break;

        case NODE_COMPOUND_ASSIGN:
            pad(indent); cout << "CompoundAssign (" << node->sval << " " << node->op << " )" << endl;
            if (!node->children.empty()) printAST(node->children[0], indent + 1);
            break;

        case NODE_BINOP:
            pad(indent); cout << "BinOp (" << node->op << ")" << endl;
            for (auto c : node->children) printAST(c, indent + 1);
            break;

        case NODE_UNOP:
            pad(indent); cout << "UnOp (" << node->op << ")" << endl;
            for (auto c : node->children) printAST(c, indent + 1);
            break;

        case NODE_PREINC:  pad(indent); cout << "PreInc (" << node->sval << ")" << endl; break;
        case NODE_PREDEC:  pad(indent); cout << "PreDec (" << node->sval << ")" << endl; break;
        case NODE_POSTINC: pad(indent); cout << "PostInc (" << node->sval << ")" << endl; break;
        case NODE_POSTDEC: pad(indent); cout << "PostDec (" << node->sval << ")" << endl; break;

        case NODE_NUM_INT:   pad(indent); cout << "Int(" << node->ival << ")" << endl; break;
        case NODE_NUM_FLOAT: pad(indent); cout << "Number(" << node->fval << ")" << endl; break;
        case NODE_CHAR:      pad(indent); cout << "Char('" << node->cval << "')" << endl; break;
        case NODE_STRING:    pad(indent); cout << "String(\"" << node->sval << "\")" << endl; break;
        case NODE_BOOL:      pad(indent); cout << "Bool(" << (node->ival ? "true" : "false") << ")" << endl; break;
        case NODE_ID:        pad(indent); cout << "Id(" << node->sval << ")" << endl; break;
        case NODE_COUT:      pad(indent); cout << "Cout" << endl; break;
        case NODE_CIN:       pad(indent); cout << "Cin" << endl; break;
        case NODE_ENDL:      pad(indent); cout << "Endl" << endl; break;

        case NODE_IF:
            pad(indent); cout << "If" << endl;
            pad(indent + 1); cout << "Cond:" << endl;
            printAST(node->children[0], indent + 2);
            pad(indent + 1); cout << "Then:" << endl;
            printAST(node->children[1], indent + 2);
            if (node->children.size() > 2 && node->children[2]) {
                pad(indent + 1); cout << "Else:" << endl;
                printAST(node->children[2], indent + 2);
            }
            break;

        case NODE_WHILE:
            pad(indent); cout << "While" << endl;
            pad(indent + 1); cout << "Cond:" << endl;
            printAST(node->children[0], indent + 2);
            pad(indent + 1); cout << "Body:" << endl;
            printAST(node->children[1], indent + 2);
            break;

        case NODE_FOR:
            pad(indent); cout << "For" << endl;
            pad(indent + 1); cout << "Init:" << endl;
            if (node->children[0]) printAST(node->children[0], indent + 2);
            pad(indent + 1); cout << "Cond:" << endl;
            if (node->children[1]) printAST(node->children[1], indent + 2);
            pad(indent + 1); cout << "Update:" << endl;
            if (node->children[2]) printAST(node->children[2], indent + 2);
            pad(indent + 1); cout << "Body:" << endl;
            printAST(node->children[3], indent + 2);
            break;

        case NODE_BREAK:    pad(indent); cout << "Break" << endl; break;
        case NODE_CONTINUE: pad(indent); cout << "Continue" << endl; break;

        case NODE_RETURN:
            pad(indent); cout << "Return" << endl;
            if (!node->children.empty()) printAST(node->children[0], indent + 1);
            break;

        case NODE_DOWHILE:
            pad(indent); cout << "DoWhile" << endl;
            pad(indent + 1); cout << "Body:" << endl;
            printAST(node->children[0], indent + 2);
            pad(indent + 1); cout << "Cond:" << endl;
            printAST(node->children[1], indent + 2);
            break;

        case NODE_SIZEOF:
            pad(indent);
            if (!node->datatype.empty()) cout << "Sizeof(type=" << node->datatype << ")" << endl;
            else cout << "Sizeof(var=" << node->sval << ")" << endl;
            break;

        case NODE_TERNARY:
            pad(indent); cout << "Ternary" << endl;
            pad(indent + 1); cout << "Cond:" << endl;
            printAST(node->children[0], indent + 2);
            pad(indent + 1); cout << "Then:" << endl;
            printAST(node->children[1], indent + 2);
            pad(indent + 1); cout << "Else:" << endl;
            printAST(node->children[2], indent + 2);
            break;
    }
}
