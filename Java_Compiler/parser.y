%{

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
%}

%code requires {
    #include <string>
    #include <vector>
    #include "ast.h"
}

%union {
    int ival;
    double fval;
    char cval;
    std::string* sval;
    ASTNode* node;
    std::vector<ASTNode*>* nodelist;
}

/*  Tokens  */
%token <ival> INT_LIT
%token <fval> FLOAT_LIT
%token <cval> CHAR_LIT
%token <sval> STRING_LIT
%token <sval> IDENTIFIER

%token KW_PUBLIC KW_CLASS KW_STATIC KW_VOID KW_MAIN
%token KW_INT KW_FLOAT KW_DOUBLE KW_CHAR KW_BOOLEAN KW_STRING KW_SCANNER
%token KW_TRUE KW_FALSE
%token KW_IF KW_ELSE KW_WHILE KW_DO KW_FOR KW_BREAK KW_CONTINUE KW_RETURN
%token KW_SYSOUT_PRINT KW_SYSOUT_PRINTLN KW_SYSTEM_IN
%token KW_IMPORT KW_NEW KW_FINAL
%token KW_SWITCH KW_CASE KW_DEFAULT
%token EQ NE LE GE AND OR SHL SHR PLUSEQ MINUSEQ MULEQ DIVEQ MODEQ INC DEC

/*  Precedence (low to high)  */
%right '?' ':'
%left OR
%left AND
%left '|'
%left '^'
%left '&'
%left EQ NE
%nonassoc '<' '>' LE GE
%left LSHIFT RSHIFT
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS
%nonassoc NOTPREC
%nonassoc BITNOT

/*  Non-terminal types  */
%type <node> program block stmt_list stmt
%type <node> vardecl assign_stmt compound_assign_stmt
%type <node> if_stmt while_stmt for_stmt do_while_stmt return_stmt print_stmt
%type <node> switch_stmt case_clause
%type <nodelist> case_clauses
%type <node> for_init for_cond for_update
%type <node> expr postfix_expr primary_expr new_expr
%type <node> import_decl
%type <sval> type_spec dotted_name
%type <nodelist> arg_list arg_list_opt case_body import_list

%%

program:
    import_list
    KW_PUBLIC KW_CLASS IDENTIFIER '{'
        KW_PUBLIC KW_STATIC KW_VOID KW_MAIN '(' KW_STRING '[' ']' IDENTIFIER ')'
        block
    '}'
        {
            ASTNode* prog = new ASTNode(NODE_PROGRAM);
            // imports carry no runtime behavior, but we keep them as
            // leading no-op statements so they still show up in the AST dump.
            if ($1) {
                for (auto imp : *$1) prog->children.push_back(imp);
                delete $1;
            }
            for (auto c : $16->children) prog->children.push_back(c);
            astRoot = prog;
            g_syntaxOk = true;
            delete $4; delete $14;
        }
    ;

import_list:
    /* empty */                { $$ = nullptr; }
    | import_list import_decl
        {
            if (!$1) $1 = new vector<ASTNode*>();
            $1->push_back($2);
            $$ = $1;
        }
    ;

import_decl:
    KW_IMPORT dotted_name ';'
        { $$ = new ASTNode(NODE_IMPORT); $$->sval = *$2; delete $2; }
    ;

dotted_name:
    IDENTIFIER                  { $$ = $1; }
    | dotted_name '.' IDENTIFIER
        { *$1 += "."; *$1 += *$3; delete $3; $$ = $1; }
    | dotted_name '.' KW_SCANNER
        { *$1 += ".Scanner"; $$ = $1; }
    | dotted_name '.' '*'
        { *$1 += ".*"; $$ = $1; }
    ;

block:
    '{' stmt_list '}' { $$ = $2; }
    ;

stmt_list:
    /* empty */              { $$ = new ASTNode(NODE_BLOCK); }
    | stmt_list stmt         { $1->children.push_back($2); $$ = $1; }
    ;

stmt:
    vardecl ';'                { $$ = $1; }
    | assign_stmt ';'           { $$ = $1; }
    | compound_assign_stmt ';'   { $$ = $1; }
    | expr ';'                    { $$ = $1; }
    | if_stmt                      { $$ = $1; }
    | while_stmt                    { $$ = $1; }
    | do_while_stmt ';'              { $$ = $1; }
    | for_stmt                       { $$ = $1; }
    | switch_stmt                     { $$ = $1; }
    | KW_BREAK ';'                     { $$ = new ASTNode(NODE_BREAK); }
    | KW_CONTINUE ';'                   { $$ = new ASTNode(NODE_CONTINUE); }
    | return_stmt ';'                    { $$ = $1; }
    | print_stmt                          { $$ = $1; }
    | block                                 { $$ = $1; }
    | ';'                                     { $$ = new ASTNode(NODE_BLOCK); }
    ;

type_spec:
    KW_INT      { $$ = new string("int"); }
    | KW_FLOAT    { $$ = new string("float"); }
    | KW_DOUBLE    { $$ = new string("double"); }
    | KW_CHAR       { $$ = new string("char"); }
    | KW_BOOLEAN     { $$ = new string("boolean"); }
    | KW_STRING       { $$ = new string("String"); }
    | KW_SCANNER       { $$ = new string("Scanner"); }
    ;

vardecl:
    type_spec IDENTIFIER
        {
            $$ = new ASTNode(NODE_VARDECL);
            $$->datatype = *$1; $$->sval = *$2;
            delete $1; delete $2;
        }
    | type_spec IDENTIFIER '=' expr
        {
            $$ = new ASTNode(NODE_VARDECL);
            $$->datatype = *$1; $$->sval = *$2;
            $$->children.push_back($4);
            delete $1; delete $2;
        }
    | KW_FINAL type_spec IDENTIFIER
        {
            $$ = new ASTNode(NODE_VARDECL);
            $$->datatype = *$2; $$->sval = *$3; $$->isFinal = true;
            delete $2; delete $3;
        }
    | KW_FINAL type_spec IDENTIFIER '=' expr
        {
            $$ = new ASTNode(NODE_VARDECL);
            $$->datatype = *$2; $$->sval = *$3; $$->isFinal = true;
            $$->children.push_back($5);
            delete $2; delete $3;
        }
    ;

assign_stmt:
    IDENTIFIER '=' expr
        {
            $$ = new ASTNode(NODE_ASSIGN);
            $$->sval = *$1;
            $$->children.push_back($3);
            delete $1;
        }
    ;

compound_assign_stmt:
    IDENTIFIER PLUSEQ expr
        { $$ = new ASTNode(NODE_COMPOUND_ASSIGN); $$->sval = *$1; $$->op = "+="; $$->children.push_back($3); delete $1; }
    | IDENTIFIER MINUSEQ expr
        { $$ = new ASTNode(NODE_COMPOUND_ASSIGN); $$->sval = *$1; $$->op = "-="; $$->children.push_back($3); delete $1; }
    | IDENTIFIER MULEQ expr
        { $$ = new ASTNode(NODE_COMPOUND_ASSIGN); $$->sval = *$1; $$->op = "*="; $$->children.push_back($3); delete $1; }
    | IDENTIFIER DIVEQ expr
        { $$ = new ASTNode(NODE_COMPOUND_ASSIGN); $$->sval = *$1; $$->op = "/="; $$->children.push_back($3); delete $1; }
    | IDENTIFIER MODEQ expr
        { $$ = new ASTNode(NODE_COMPOUND_ASSIGN); $$->sval = *$1; $$->op = "%="; $$->children.push_back($3); delete $1; }
    ;

if_stmt:
    KW_IF '(' expr ')' block
        {
            $$ = new ASTNode(NODE_IF);
            $$->children.push_back($3);
            $$->children.push_back($5);
            $$->children.push_back(nullptr);
        }
    | KW_IF '(' expr ')' block KW_ELSE block
        {
            $$ = new ASTNode(NODE_IF);
            $$->children.push_back($3);
            $$->children.push_back($5);
            $$->children.push_back($7);
        }
    | KW_IF '(' expr ')' block KW_ELSE if_stmt
        {
            ASTNode* wrapper = new ASTNode(NODE_BLOCK);
            wrapper->children.push_back($7);
            $$ = new ASTNode(NODE_IF);
            $$->children.push_back($3);
            $$->children.push_back($5);
            $$->children.push_back(wrapper);
        }
    ;

while_stmt:
    KW_WHILE '(' expr ')' block
        {
            $$ = new ASTNode(NODE_WHILE);
            $$->children.push_back($3);
            $$->children.push_back($5);
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
            $$ = new ASTNode(NODE_FOR);
            $$->children.push_back($3);
            $$->children.push_back($5);
            $$->children.push_back($7);
            $$->children.push_back($9);
        }
    ;

do_while_stmt:
    KW_DO block KW_WHILE '(' expr ')'
        {
            $$ = new ASTNode(NODE_DO_WHILE);
            $$->children.push_back($2);
            $$->children.push_back($5);
        }
    ;

switch_stmt:
    KW_SWITCH '(' expr ')' '{' case_clauses '}'
        {
            $$ = new ASTNode(NODE_SWITCH);
            $$->children.push_back($3);
            if ($6) { for (auto c : *$6) $$->children.push_back(c); delete $6; }
        }
    ;

case_clauses:
    /* empty */                { $$ = nullptr; }
    | case_clauses case_clause
        {
            if (!$1) $1 = new vector<ASTNode*>();
            $1->push_back($2);
            $$ = $1;
        }
    ;

case_clause:
    KW_CASE INT_LIT ':' case_body
        {
            $$ = new ASTNode(NODE_CASE);
            $$->caseKind = "int"; $$->ival = $2;
            if ($4) { for (auto s : *$4) $$->children.push_back(s); delete $4; }
        }
    | KW_CASE CHAR_LIT ':' case_body
        {
            $$ = new ASTNode(NODE_CASE);
            $$->caseKind = "char"; $$->cval = $2;
            if ($4) { for (auto s : *$4) $$->children.push_back(s); delete $4; }
        }
    | KW_CASE STRING_LIT ':' case_body
        {
            $$ = new ASTNode(NODE_CASE);
            $$->caseKind = "String"; $$->sval = *$2; delete $2;
            if ($4) { for (auto s : *$4) $$->children.push_back(s); delete $4; }
        }
    | KW_DEFAULT ':' case_body
        {
            $$ = new ASTNode(NODE_DEFAULT);
            if ($3) { for (auto s : *$3) $$->children.push_back(s); delete $3; }
        }
    ;

case_body:
    /* empty */                { $$ = nullptr; }
    | case_body stmt
        {
            if (!$1) $1 = new vector<ASTNode*>();
            $1->push_back($2);
            $$ = $1;
        }
    ;

return_stmt:
    KW_RETURN            { $$ = new ASTNode(NODE_RETURN); }
    | KW_RETURN expr       { $$ = new ASTNode(NODE_RETURN); $$->children.push_back($2); }
    ;

print_stmt:
    KW_SYSOUT_PRINTLN '(' ')' ';'
        { $$ = new ASTNode(NODE_PRINT); $$->ival = 1; }
    | KW_SYSOUT_PRINTLN '(' expr ')' ';'
        { $$ = new ASTNode(NODE_PRINT); $$->ival = 1; $$->children.push_back($3); }
    | KW_SYSOUT_PRINT '(' expr ')' ';'
        { $$ = new ASTNode(NODE_PRINT); $$->ival = 0; $$->children.push_back($3); }
    ;

primary_expr:
    INT_LIT                { $$ = new ASTNode(NODE_NUM_INT); $$->ival = $1; }
    | FLOAT_LIT              { $$ = new ASTNode(NODE_NUM_FLOAT); $$->fval = $1; }
    | CHAR_LIT                { $$ = new ASTNode(NODE_CHAR); $$->cval = $1; }
    | STRING_LIT               { $$ = new ASTNode(NODE_STRING); $$->sval = *$1; delete $1; }
    | KW_TRUE                   { $$ = new ASTNode(NODE_BOOL); $$->ival = 1; }
    | KW_FALSE                   { $$ = new ASTNode(NODE_BOOL); $$->ival = 0; }
    | KW_SYSTEM_IN                { $$ = new ASTNode(NODE_SYSTEM_IN); }
    | IDENTIFIER                    { $$ = new ASTNode(NODE_ID); $$->sval = *$1; delete $1; }
    | new_expr                       { $$ = $1; }
    | '(' expr ')'                    { $$ = $2; }
    ;

/* postfix_expr handles (possibly chained) method calls: obj.method(args).method2(args2)... */
postfix_expr:
    primary_expr        { $$ = $1; }
    | postfix_expr '.' IDENTIFIER '(' arg_list_opt ')'
        {
            $$ = new ASTNode(NODE_METHOD_CALL);
            $$->sval = *$3; delete $3;
            $$->children.push_back($1);
            if ($5) { for (auto a : *$5) $$->children.push_back(a); delete $5; }
        }
    ;

new_expr:
    KW_NEW KW_SCANNER '(' arg_list_opt ')'
        {
            $$ = new ASTNode(NODE_NEW_SCANNER);
            if ($4) delete $4; // ctor arg (System.in) has no runtime effect
        }
    ;

arg_list_opt:
    /* empty */   { $$ = nullptr; }
    | arg_list      { $$ = $1; }
    ;

arg_list:
    expr                  { $$ = new vector<ASTNode*>(); $$->push_back($1); }
    | arg_list ',' expr    { $1->push_back($3); $$ = $1; }
    ;

expr:
    postfix_expr             { $$ = $1; }
    | '-' expr %prec UMINUS         { $$ = new ASTNode(NODE_UNOP); $$->op = "-"; $$->children.push_back($2); }
    | '!' expr %prec NOTPREC         { $$ = new ASTNode(NODE_UNOP); $$->op = "!"; $$->children.push_back($2); }
    | '~' expr %prec BITNOT           { $$ = new ASTNode(NODE_UNOP); $$->op = "~"; $$->children.push_back($2); }
    | INC IDENTIFIER                  { $$ = new ASTNode(NODE_PREINC); $$->sval = *$2; delete $2; }
    | DEC IDENTIFIER                   { $$ = new ASTNode(NODE_PREDEC); $$->sval = *$2; delete $2; }
    | IDENTIFIER INC                    { $$ = new ASTNode(NODE_POSTINC); $$->sval = *$1; delete $1; }
    | IDENTIFIER DEC                     { $$ = new ASTNode(NODE_POSTDEC); $$->sval = *$1; delete $1; }
    | expr '+' expr           { $$ = new ASTNode(NODE_BINOP); $$->op = "+"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '-' expr           { $$ = new ASTNode(NODE_BINOP); $$->op = "-"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '*' expr           { $$ = new ASTNode(NODE_BINOP); $$->op = "*"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '/' expr           { $$ = new ASTNode(NODE_BINOP); $$->op = "/"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '%' expr           { $$ = new ASTNode(NODE_BINOP); $$->op = "%"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '<' expr           { $$ = new ASTNode(NODE_BINOP); $$->op = "<"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '>' expr           { $$ = new ASTNode(NODE_BINOP); $$->op = ">"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr LE expr             { $$ = new ASTNode(NODE_BINOP); $$->op = "<="; $$->children.push_back($1); $$->children.push_back($3); }
    | expr GE expr             { $$ = new ASTNode(NODE_BINOP); $$->op = ">="; $$->children.push_back($1); $$->children.push_back($3); }
    | expr EQ expr             { $$ = new ASTNode(NODE_BINOP); $$->op = "=="; $$->children.push_back($1); $$->children.push_back($3); }
    | expr NE expr             { $$ = new ASTNode(NODE_BINOP); $$->op = "!="; $$->children.push_back($1); $$->children.push_back($3); }
    | expr AND expr            { $$ = new ASTNode(NODE_BINOP); $$->op = "&&"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr OR expr             { $$ = new ASTNode(NODE_BINOP); $$->op = "||"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '&' expr             { $$ = new ASTNode(NODE_BINOP); $$->op = "&"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '|' expr             { $$ = new ASTNode(NODE_BINOP); $$->op = "|"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '^' expr             { $$ = new ASTNode(NODE_BINOP); $$->op = "^"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr LSHIFT expr           { $$ = new ASTNode(NODE_BINOP); $$->op = "<<"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr RSHIFT expr           { $$ = new ASTNode(NODE_BINOP); $$->op = ">>"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '?' expr ':' expr      { $$ = new ASTNode(NODE_TERNARY); $$->children.push_back($1); $$->children.push_back($3); $$->children.push_back($5); }
    ;

%%

void yyerror(const char* s) {
    cerr << "Syntax Error at line " << yylineno << ": " << s << endl;
    g_syntaxOk = false;
}
