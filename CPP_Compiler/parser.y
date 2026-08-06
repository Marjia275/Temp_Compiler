%{
// ============================================================
// parser.y
// Syntax Analyzer for Mini C++ Compiler
// Builds the AST for main.cpp / semantic.cpp / interpreter.cpp
// ============================================================
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include "ast.h"

using namespace std;

extern int yylex();
extern int yylineno;
void yyerror(const char* s);

// Defined in main.cpp - filled in once parsing succeeds.
extern ASTNode* astRoot;
extern bool g_syntaxOk;

// Every node created during parsing is stamped with the line it was
// parsed on (yylineno) so the semantic analyzer / runtime can produce
// detailed "Line N: ..." error messages instead of generic ones.
static ASTNode* mkNode(NodeType t) {
    ASTNode* n = new ASTNode(t);
    n->line = yylineno;
    return n;
}
%}

%code requires {
    #include <string>
    #include <vector>
    #include "ast.h"
}



%union {
    long long ival;
    double fval;
    char cval;
    std::string* sval;
    ASTNode* node;
    std::vector<ASTNode*>* nodelist;
}

/* ---------------- Tokens ---------------- */
%token <ival> INT_LIT
%token <fval> FLOAT_LIT
%token <cval> CHAR_LIT
%token <sval> STRING_LIT
%token <sval> IDENTIFIER

%token KW_INT KW_FLOAT KW_DOUBLE KW_CHAR KW_BOOL KW_STRING KW_VOID
%token KW_TRUE KW_FALSE
%token KW_IF KW_ELSE KW_WHILE KW_DO KW_FOR KW_BREAK KW_CONTINUE KW_RETURN
%token KW_COUT KW_CIN KW_ENDL
%token KW_CONST KW_LONG KW_UNSIGNED KW_SIZEOF
%token KW_SWITCH KW_CASE KW_DEFAULT
%token EQ NE LE GE AND OR SHL SHR PLUSEQ MINUSEQ MULEQ DIVEQ MODEQ INC DEC

/* ---------------- Precedence (low to high) ---------------- */
%right '?' ':'
%left OR
%left AND
%left '|'
%left '^'
%left '&'
%left EQ NE
%nonassoc '<' '>' LE GE
%left SHL SHR
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS
%nonassoc NOTPREC
%nonassoc TILDEPREC
%nonassoc SIZEOFPREC

/* ---------------- Non-terminal types ---------------- */
%type <node> program block stmt_list stmt
%type <node> vardecl assign_stmt compound_assign_stmt
%type <node> if_stmt while_stmt do_while_stmt for_stmt return_stmt
%type <node> for_init for_cond for_update
%type <node> switch_stmt case_list case_stmt
%type <node> expr
%type <node> declarator
%type <nodelist> declarator_list
%type <sval> type_spec

%%

program:
    KW_INT IDENTIFIER '(' ')' block
        {
            ASTNode* prog = mkNode(NODE_PROGRAM);
            prog->children = $5->children;
            astRoot = prog;
            g_syntaxOk = true;
            delete $2;
        }
    ;

block:
    '{' stmt_list '}' { $$ = $2; }
    ;

stmt_list:
    /* empty */              { $$ = mkNode(NODE_BLOCK); }
    | stmt_list stmt         { $1->children.push_back($2); $$ = $1; }
    ;

stmt:
    vardecl ';'                { $$ = $1; }
    | assign_stmt ';'           { $$ = $1; }
    | compound_assign_stmt ';'   { $$ = $1; }
    | expr ';'                    { $$ = $1; }
    | if_stmt                      { $$ = $1; }
    | while_stmt                    { $$ = $1; }
    | do_while_stmt                  { $$ = $1; }
    | for_stmt                       { $$ = $1; }
    | switch_stmt                     { $$ = $1; }
    | KW_BREAK ';'                     { $$ = mkNode(NODE_BREAK); }
    | KW_CONTINUE ';'                   { $$ = mkNode(NODE_CONTINUE); }
    | return_stmt ';'                    { $$ = $1; }
    | block                                { $$ = $1; }
    | ';'                                    { $$ = mkNode(NODE_BLOCK); }
    ;

type_spec:
    KW_INT     { $$ = new string("int"); }
    | KW_FLOAT   { $$ = new string("float"); }
    | KW_DOUBLE   { $$ = new string("double"); }
    | KW_CHAR      { $$ = new string("char"); }
    | KW_BOOL       { $$ = new string("bool"); }
    | KW_STRING      { $$ = new string("string"); }
    | KW_LONG KW_LONG        { $$ = new string("long long"); }
    | KW_LONG KW_INT          { $$ = new string("long"); }
    | KW_LONG                  { $$ = new string("long"); }
    | KW_UNSIGNED KW_LONG KW_LONG { $$ = new string("unsigned long long"); }
    | KW_UNSIGNED KW_LONG          { $$ = new string("unsigned long"); }
    | KW_UNSIGNED KW_INT            { $$ = new string("unsigned int"); }
    | KW_UNSIGNED                    { $$ = new string("unsigned int"); }
    ;

declarator:
    IDENTIFIER
        {
            $$ = mkNode(NODE_VARDECL);
            $$->sval = *$1;
            delete $1;
        }
    | IDENTIFIER '=' expr
        {
            $$ = mkNode(NODE_VARDECL);
            $$->sval = *$1;
            $$->children.push_back($3);
            delete $1;
        }
    ;

declarator_list:
    declarator
        {
            $$ = new vector<ASTNode*>();
            $$->push_back($1);
        }
    | declarator_list ',' declarator
        {
            $1->push_back($3);
            $$ = $1;
        }
    ;

vardecl:
    type_spec declarator_list
        {
            for (auto d : *$2) d->datatype = *$1;
            if ($2->size() == 1) {
                $$ = (*$2)[0];
            } else {
                ASTNode* blk = mkNode(NODE_BLOCK);
                for (auto d : *$2) blk->children.push_back(d);
                $$ = blk;
            }
            delete $1; delete $2;
        }
    | KW_CONST type_spec declarator_list
        {
            for (auto d : *$3) { d->datatype = *$2; d->isConst = true; }
            if ($3->size() == 1) {
                $$ = (*$3)[0];
            } else {
                ASTNode* blk = mkNode(NODE_BLOCK);
                for (auto d : *$3) blk->children.push_back(d);
                $$ = blk;
            }
            delete $2; delete $3;
        }
    ;

assign_stmt:
    IDENTIFIER '=' expr
        {
            $$ = mkNode(NODE_ASSIGN);
            $$->sval = *$1;
            $$->children.push_back($3);
            delete $1;
        }
    ;

compound_assign_stmt:
    IDENTIFIER PLUSEQ expr
        { $$ = mkNode(NODE_COMPOUND_ASSIGN); $$->sval = *$1; $$->op = "+="; $$->children.push_back($3); delete $1; }
    | IDENTIFIER MINUSEQ expr
        { $$ = mkNode(NODE_COMPOUND_ASSIGN); $$->sval = *$1; $$->op = "-="; $$->children.push_back($3); delete $1; }
    | IDENTIFIER MULEQ expr
        { $$ = mkNode(NODE_COMPOUND_ASSIGN); $$->sval = *$1; $$->op = "*="; $$->children.push_back($3); delete $1; }
    | IDENTIFIER DIVEQ expr
        { $$ = mkNode(NODE_COMPOUND_ASSIGN); $$->sval = *$1; $$->op = "/="; $$->children.push_back($3); delete $1; }
    | IDENTIFIER MODEQ expr
    { $$ = mkNode(NODE_COMPOUND_ASSIGN); $$->sval = *$1; $$->op = "%="; $$->children.push_back($3); delete $1; }
    ;

if_stmt:
    KW_IF '(' expr ')' block
        {
            $$ = mkNode(NODE_IF);
            $$->children.push_back($3);
            $$->children.push_back($5);
            $$->children.push_back(nullptr);
        }
    | KW_IF '(' expr ')' block KW_ELSE block
        {
            $$ = mkNode(NODE_IF);
            $$->children.push_back($3);
            $$->children.push_back($5);
            $$->children.push_back($7);
        }
    | KW_IF '(' expr ')' block KW_ELSE if_stmt
        {
            ASTNode* wrapper = mkNode(NODE_BLOCK);
            wrapper->children.push_back($7);
            $$ = mkNode(NODE_IF);
            $$->children.push_back($3);
            $$->children.push_back($5);
            $$->children.push_back(wrapper);
        }
    ;

while_stmt:
    KW_WHILE '(' expr ')' block
        {
            $$ = mkNode(NODE_WHILE);
            $$->children.push_back($3);
            $$->children.push_back($5);
        }
    ;

do_while_stmt:
    KW_DO block KW_WHILE '(' expr ')' ';'
        {
            $$ = mkNode(NODE_DOWHILE);
            $$->children.push_back($2);  // body
            $$->children.push_back($5);  // cond
        }
    ;

for_init:
    /* empty */   { $$ = nullptr; }
    | vardecl      { $$ = $1; }
    | assign_stmt   { $$ = $1; }
    ;

for_cond:
    /* empty */   { $$ = nullptr; }
    | expr         { $$ = $1; }
    ;

for_update:
    /* empty */             { $$ = nullptr; }
    | assign_stmt            { $$ = $1; }
    | compound_assign_stmt    { $$ = $1; }
    | expr                     { $$ = $1; }
    ;

for_stmt:
    KW_FOR '(' for_init ';' for_cond ';' for_update ')' block
        {
            $$ = mkNode(NODE_FOR);
            $$->children.push_back($3);
            $$->children.push_back($5);
            $$->children.push_back($7);
            $$->children.push_back($9);
        }
    ;

switch_stmt:
    KW_SWITCH '(' expr ')' '{' case_list '}'
        {
            $$ = mkNode(NODE_SWITCH);
            $$->children.push_back($3);   // switch expr
            $$->children.push_back($6);   // NODE_BLOCK of case/default nodes
        }
    ;

case_list:
    /* empty */              { $$ = mkNode(NODE_BLOCK); }
    | case_list case_stmt     { $1->children.push_back($2); $$ = $1; }
    ;

case_stmt:
    KW_CASE expr ':' stmt_list
        {
            $$ = mkNode(NODE_CASE);
            $$->children.push_back($2);  // case value expr
            $$->children.push_back($4);  // NODE_BLOCK of statements
        }
    | KW_DEFAULT ':' stmt_list
        {
            $$ = mkNode(NODE_DEFAULT);
            $$->children.push_back($3);  // NODE_BLOCK of statements
        }
    ;

return_stmt:
    KW_RETURN            { $$ = mkNode(NODE_RETURN); }
    | KW_RETURN expr       { $$ = mkNode(NODE_RETURN); $$->children.push_back($2); }
    ;

expr:
    INT_LIT                { $$ = mkNode(NODE_NUM_INT); $$->ival = $1; }
    | FLOAT_LIT              { $$ = mkNode(NODE_NUM_FLOAT); $$->fval = $1; }
    | CHAR_LIT                { $$ = mkNode(NODE_CHAR); $$->cval = $1; }
    | STRING_LIT               { $$ = mkNode(NODE_STRING); $$->sval = *$1; delete $1; }
    | KW_TRUE                   { $$ = mkNode(NODE_BOOL); $$->ival = 1; }
    | KW_FALSE                   { $$ = mkNode(NODE_BOOL); $$->ival = 0; }
    | KW_COUT                     { $$ = mkNode(NODE_COUT); }
    | KW_CIN                       { $$ = mkNode(NODE_CIN); }
    | KW_ENDL                       { $$ = mkNode(NODE_ENDL); }
    | IDENTIFIER                     { $$ = mkNode(NODE_ID); $$->sval = *$1; delete $1; }
    | '(' expr ')'                    { $$ = $2; }
    | '-' expr %prec UMINUS            { $$ = mkNode(NODE_UNOP); $$->op = "-"; $$->children.push_back($2); }
    | '!' expr %prec NOTPREC            { $$ = mkNode(NODE_UNOP); $$->op = "!"; $$->children.push_back($2); }
    | '~' expr %prec TILDEPREC           { $$ = mkNode(NODE_UNOP); $$->op = "~"; $$->children.push_back($2); }
    | INC IDENTIFIER                      { $$ = mkNode(NODE_PREINC); $$->sval = *$2; delete $2; }
    | DEC IDENTIFIER                       { $$ = mkNode(NODE_PREDEC); $$->sval = *$2; delete $2; }
    | IDENTIFIER INC                        { $$ = mkNode(NODE_POSTINC); $$->sval = *$1; delete $1; }
    | IDENTIFIER DEC                         { $$ = mkNode(NODE_POSTDEC); $$->sval = *$1; delete $1; }
    | expr '+' expr              { $$ = mkNode(NODE_BINOP); $$->op = "+"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '-' expr              { $$ = mkNode(NODE_BINOP); $$->op = "-"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '*' expr              { $$ = mkNode(NODE_BINOP); $$->op = "*"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '/' expr              { $$ = mkNode(NODE_BINOP); $$->op = "/"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '%' expr              { $$ = mkNode(NODE_BINOP); $$->op = "%"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '<' expr              { $$ = mkNode(NODE_BINOP); $$->op = "<"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '>' expr              { $$ = mkNode(NODE_BINOP); $$->op = ">"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr LE expr                { $$ = mkNode(NODE_BINOP); $$->op = "<="; $$->children.push_back($1); $$->children.push_back($3); }
    | expr GE expr                { $$ = mkNode(NODE_BINOP); $$->op = ">="; $$->children.push_back($1); $$->children.push_back($3); }
    | expr EQ expr                { $$ = mkNode(NODE_BINOP); $$->op = "=="; $$->children.push_back($1); $$->children.push_back($3); }
    | expr NE expr                { $$ = mkNode(NODE_BINOP); $$->op = "!="; $$->children.push_back($1); $$->children.push_back($3); }
    | expr AND expr               { $$ = mkNode(NODE_BINOP); $$->op = "&&"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr OR expr                { $$ = mkNode(NODE_BINOP); $$->op = "||"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '&' expr                { $$ = mkNode(NODE_BINOP); $$->op = "&"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '|' expr                { $$ = mkNode(NODE_BINOP); $$->op = "|"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '^' expr                { $$ = mkNode(NODE_BINOP); $$->op = "^"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr SHL expr                 { $$ = mkNode(NODE_BINOP); $$->op = "<<"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr SHR expr                  { $$ = mkNode(NODE_BINOP); $$->op = ">>"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '?' expr ':' expr          { $$ = mkNode(NODE_TERNARY); $$->children.push_back($1); $$->children.push_back($3); $$->children.push_back($5); }
    | KW_SIZEOF '(' type_spec ')' %prec SIZEOFPREC
        { $$ = mkNode(NODE_SIZEOF); $$->datatype = *$3; delete $3; }
    | KW_SIZEOF '(' IDENTIFIER ')' %prec SIZEOFPREC
        { $$ = mkNode(NODE_SIZEOF); $$->sval = *$3; delete $3; }
    ;

%%

extern char* yytext;

void yyerror(const char* s) {
   
    string msg(s);
    string expected;
    size_t expPos = msg.find("expecting");
    if (expPos != string::npos) {
        expected = msg.substr(expPos + 10); // text after "expecting "
    }

    cout << "Syntax Error:" << endl;
    cout << "Line " << yylineno << ":" << endl;
    if (yytext && yytext[0] != '\0')
        cout << "Unexpected token '" << yytext << "'." << endl;
    else
        cout << "Unexpected end of input." << endl;
    if (!expected.empty())
        cout << "Expected " << expected << "." << endl;

    g_syntaxOk = false;
}
