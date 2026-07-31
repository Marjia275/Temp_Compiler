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
#ifndef AST_H
#define AST_H

#include <string>
#include <vector>

enum NodeType {
    NODE_PROGRAM,        // children = list of statements inside main()
    NODE_BLOCK,          // children = list of statements inside { }
                          // (also used to group a multi-variable declaration
                          //  statement such as "int a, b = 2;" into a list
                          //  of NODE_VARDECL children)
    NODE_VARDECL,        // datatype + sval(name) + isConst + children[0]=init expr (optional)
    NODE_ASSIGN,         // sval(name) + children[0] = expr
    NODE_COMPOUND_ASSIGN,// op ("+=","-=","*=","/=") + sval(name) + children[0]=expr
    NODE_BINOP,          // op + children[0], children[1]
    NODE_UNOP,           // op ("-","!","~") + children[0]
    NODE_TERNARY,        // children[0]=cond, children[1]=trueExpr, children[2]=falseExpr
    NODE_PREINC,         // sval(name)  ++a
    NODE_PREDEC,         // sval(name)  --a
    NODE_POSTINC,        // sval(name)  a++
    NODE_POSTDEC,        // sval(name)  a--
    NODE_NUM_INT,        // ival
    NODE_NUM_FLOAT,      // fval
    NODE_CHAR,           // cval
    NODE_STRING,         // sval
    NODE_ID,             // sval(name)
    NODE_IF,             // children[0]=cond, children[1]=thenBlock, children[2]=elseBlock(optional)
    NODE_WHILE,          // children[0]=cond, children[1]=body
    NODE_DOWHILE,        // children[0]=body, children[1]=cond
    NODE_FOR,            // children[0]=init, children[1]=cond, children[2]=update, children[3]=body
    NODE_SWITCH,         // children[0]=expr, children[1..]=NODE_CASE / NODE_DEFAULT (in source order)
    NODE_CASE,           // ival = case constant, children[0] = NODE_BLOCK of statements
    NODE_DEFAULT,        // children[0] = NODE_BLOCK of statements
    NODE_BREAK,          // (leaf)
    NODE_CONTINUE,       // (leaf)
    NODE_PRINTF,         // sval = format string, children = argument expressions
    NODE_SCANF,          // sval = format string, children = NODE_ID targets (names only)
    NODE_SIZEOF,         // datatype set -> sizeof(type)   OR   children[0] set -> sizeof(expr)
    NODE_CALL,           // sval = builtin fn name ("sqrt","pow","abs","ceil","floor"), children = args
    NODE_RETURN          // children[0] = expr (optional)
};

class ASTNode {
public:
    NodeType type;
    int line;

    // literal / identifier payloads
    int ival;
    long long llit;        // used by NODE_NUM_INT when the literal doesn't fit in 'int'
    double fval;
    char cval;
    std::string sval;      // name, string literal text, or format string

    // operator text, used by BINOP / UNOP / COMPOUND_ASSIGN
    std::string op;

    // used by VARDECL / SIZEOF
    std::string datatype;  // "int", "float", "double", "char", "long"
    bool isConst;           // used by VARDECL

    // generic child list (meaning depends on 'type', see comments above)
    std::vector<ASTNode*> children;

    ASTNode(NodeType t)
        : type(t), line(0), ival(0), llit(0), fval(0.0), cval(0), isConst(false) {}

    void addChild(ASTNode* n) {
        if (n != nullptr) children.push_back(n);
    }
};

// Pretty-printer used by --debug mode to show the AST.
void printAST(ASTNode* node, int indent = 0);

#endif // AST_H
