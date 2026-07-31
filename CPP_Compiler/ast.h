// ============================================================
// ast.h
// Abstract Syntax Tree node definitions for Mini C Compiler
// ============================================================
//
// Design note:
// Instead of one C++ class per node (Program, IfNode, WhileNode ...),
// we use ONE tagged node class (ASTNode) with a NodeType enum that
// tells every other module (semantic analyzer, interpreter, TAC
// generator, code generator) how to interpret its fields.
//
// This mirrors exactly what the parser.y calculator you were taught
// with does (one grammar, simple actions) but scaled up to a whole
// program tree instead of a single expression.
//
#ifndef AST_H
#define AST_H

#include <string>
#include <vector>

enum NodeType {
    NODE_PROGRAM,        // children = list of statements inside main()
    NODE_BLOCK,          // children = list of statements inside { }
    NODE_VARDECL,        // datatype + sval(name) + children[0]=init expr (optional)
    NODE_ASSIGN,         // sval(name) + children[0] = expr
    NODE_COMPOUND_ASSIGN,// op ("+=","-=","*=","/=") + sval(name) + children[0]=expr
    NODE_BINOP,          // op + children[0], children[1]
    NODE_UNOP,           // op ("-","!","~") + children[0]
    NODE_PREINC,         // sval(name)  ++a
    NODE_PREDEC,         // sval(name)  --a
    NODE_POSTINC,        // sval(name)  a++
    NODE_POSTDEC,        // sval(name)  a--
    NODE_NUM_INT,        // ival
    NODE_NUM_FLOAT,      // fval  (used for both float and double literals)
    NODE_CHAR,           // cval
    NODE_STRING,         // sval  (string literal)
    NODE_BOOL,           // ival (0 or 1)  true / false
    NODE_ID,             // sval(name)
    NODE_COUT,           // leaf: the "cout" stream object
    NODE_CIN,             // leaf: the "cin" stream object
    NODE_ENDL,            // leaf: the "endl" manipulator
    NODE_IF,              // children[0]=cond, children[1]=thenBlock, children[2]=elseBlock(optional)
    NODE_WHILE,           // children[0]=cond, children[1]=body
    NODE_FOR,             // children[0]=init, children[1]=cond, children[2]=update, children[3]=body
    NODE_BREAK,           // leaf
    NODE_CONTINUE,        // leaf
    NODE_RETURN,          // children[0] = expr (optional)
    NODE_DOWHILE,         // children[0]=body, children[1]=cond
    NODE_SIZEOF,          // datatype set directly, OR sval(name) to look up a variable's type
    NODE_TERNARY          // children[0]=cond, children[1]=then-expr, children[2]=else-expr
};

// Human readable datatype strings used in NODE_VARDECL::datatype:
//   "int", "float", "double", "char", "bool", "string"

class ASTNode {
public:
    NodeType type;
    int line;

    // literal / identifier payloads
    long long ival;        // widened to long long so "long"/"long long" literals and values fit
    double fval;
    char cval;
    std::string sval;      // name, string literal text, or format string

    // operator text, used by BINOP / UNOP / COMPOUND_ASSIGN
    std::string op;

    // used by VARDECL
    std::string datatype;  // "int", "float", "char", "long", "long long", "unsigned long long", ...
    bool isConst = false;  // true for "const" declarations (VARDECL)

    // generic child list (meaning depends on 'type', see comments above)
    std::vector<ASTNode*> children;

    ASTNode(NodeType t)
        : type(t), line(0), ival(0), fval(0.0), cval(0) {}

    void addChild(ASTNode* n) {
        if (n != nullptr) children.push_back(n);
    }
};

// Pretty-printer used by --debug mode to show the AST.
void printAST(ASTNode* node, int indent = 0);

#endif // AST_H
