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
    NODE_UNOP,           // op ("-","!") + children[0]
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
    NODE_PRINT,          // ival = 1 for println, 0 for print; children[0] = expr (optional for println())
    NODE_IF,              // children[0]=cond, children[1]=thenBlock, children[2]=elseBlock(optional)
    NODE_WHILE,           // children[0]=cond, children[1]=body
    NODE_FOR,             // children[0]=init, children[1]=cond, children[2]=update, children[3]=body
    NODE_BREAK,           // leaf
    NODE_CONTINUE,        // leaf
    NODE_RETURN,          // children[0] = expr (optional)

    NODE_IMPORT,          // sval = dotted import path (e.g. "java.util.Scanner"); no runtime effect
    NODE_SYSTEM_IN,        // leaf; represents the "System.in" expression (only meaningful as a Scanner() ctor arg)
    NODE_NEW_SCANNER,      // leaf; result of "new Scanner(System.in)"
    NODE_METHOD_CALL,      // sval = method name; children[0] = object expr; children[1..] = call arguments
    NODE_TERNARY,          // children[0]=cond, children[1]=trueExpr, children[2]=falseExpr
    NODE_SWITCH,           // children[0]=selector expr; remaining children = NODE_CASE / NODE_DEFAULT (in order)
    NODE_CASE,             // ival/fval/cval/sval = the case's constant label; children = case body statements
    NODE_DEFAULT,          // children = default body statements
    NODE_DO_WHILE          // children[0]=body(block), children[1]=cond
};

// Human readable datatype strings used in NODE_VARDECL::datatype:
//   "int", "float", "double", "char", "boolean", "String"

class ASTNode {
public:
    NodeType type;
    int line;

    // literal / identifier payloads
    int ival;
    double fval;
    char cval;
    std::string sval;      // name, string literal text, or format string

    // operator text, used by BINOP / UNOP / COMPOUND_ASSIGN
    std::string op;

    // used by VARDECL
    std::string datatype;  // "int", "float", "char", "String", "boolean", "Scanner"
    bool isFinal = false;  // true for "final" declarations (VARDECL only)

    // used by NODE_CASE: which "kind" of literal the label is,
    // so the switch interpreter knows which payload field to compare.
    // "int" | "char" | "String"  (Java also allows these as case labels)
    std::string caseKind;

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
