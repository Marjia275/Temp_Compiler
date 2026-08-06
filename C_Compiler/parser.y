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
extern char* yytext;
void yyerror(const char* s);


extern ASTNode* astRoot;
extern bool g_syntaxOk;
%}

%code requires {
    #include <string>
    #include <vector>
    #include "ast.h"
}

%error-verbose

%union {
    int ival;
    double fval;
    char cval;
    std::string* sval;
    ASTNode* node;
    std::vector<ASTNode*>* nodelist;
}

/* ---------------- Tokens ---------------- */
%token <sval> INT_LIT
%token <fval> FLOAT_LIT
%token <cval> CHAR_LIT
%token <sval> STRING_LIT
%token <sval> IDENTIFIER

%token KW_CONST KW_INT KW_FLOAT KW_DOUBLE KW_CHAR KW_LONG KW_UNSIGNED
%token KW_IF KW_ELSE KW_WHILE KW_FOR KW_DO
%token KW_SWITCH KW_CASE KW_DEFAULT KW_BREAK KW_CONTINUE
%token KW_PRINTF KW_SCANF KW_SIZEOF
%token KW_SQRT KW_POW KW_ABS KW_CEIL KW_FLOOR
%token KW_RETURN KW_VOID
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
%left LSHIFT RSHIFT
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS
%nonassoc NOTPREC

/* ---------------- Non-terminal types ---------------- */
%type <node> program block stmt_list stmt
%type <node> vardecl vardecl_stmt assign_stmt compound_assign_stmt declarator
%type <node> if_stmt while_stmt do_while_stmt for_stmt switch_stmt case_clause
%type <node> break_stmt continue_stmt
%type <node> printf_stmt scanf_stmt return_stmt
%type <node> for_init for_cond for_update
%type <node> expr
%type <sval> type_spec
%type <nodelist> printf_arglist scanf_arglist declarator_list case_list
%type <ival> case_value

%%

program:
    KW_INT IDENTIFIER '(' ')' block
        {
            ASTNode* prog = new ASTNode(NODE_PROGRAM);
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
    /* empty */              { $$ = new ASTNode(NODE_BLOCK); }
    | stmt_list stmt         { $1->children.push_back($2); $$ = $1; }
    ;

stmt:
    vardecl_stmt ';'          { $$ = $1; }
    | assign_stmt ';'         { $$ = $1; }
    | compound_assign_stmt ';'{ $$ = $1; }
    | expr ';'                { $$ = $1; }
    | if_stmt                 { $$ = $1; }
    | while_stmt               { $$ = $1; }
    | do_while_stmt              { $$ = $1; }
    | for_stmt                     { $$ = $1; }
    | switch_stmt                    { $$ = $1; }
    | break_stmt ';'                   { $$ = $1; }
    | continue_stmt ';'                  { $$ = $1; }
    | printf_stmt ';'                      { $$ = $1; }
    | scanf_stmt ';'                         { $$ = $1; }
    | return_stmt ';'                          { $$ = $1; }
    | block                                      { $$ = $1; }
    | ';'                                          { $$ = new ASTNode(NODE_BLOCK); }
    ;

type_spec:
    KW_INT      { $$ = new string("int"); }
    | KW_FLOAT    { $$ = new string("float"); }
    | KW_DOUBLE     { $$ = new string("double"); }
    | KW_CHAR         { $$ = new string("char"); }
    | KW_LONG                       { $$ = new string("long"); }
    | KW_LONG KW_INT                 { $$ = new string("long"); }
    | KW_LONG KW_LONG                  { $$ = new string("long"); }
    | KW_LONG KW_LONG KW_INT             { $$ = new string("long"); }
    | KW_UNSIGNED KW_LONG                  { $$ = new string("long"); }
    | KW_UNSIGNED KW_LONG KW_LONG            { $$ = new string("long"); }
    ;

/* single-declarator form, used only where a list wouldn't make sense (for-init) */
vardecl:
    type_spec IDENTIFIER
        {
            $$ = new ASTNode(NODE_VARDECL);
            $$->datatype = *$1; $$->sval = *$2; $$->line = yylineno;
            delete $1; delete $2;
        }
    | type_spec IDENTIFIER '=' expr
        {
            $$ = new ASTNode(NODE_VARDECL);
            $$->datatype = *$1; $$->sval = *$2; $$->line = yylineno;
            $$->children.push_back($4);
            delete $1; delete $2;
        }
    ;

declarator:
    IDENTIFIER
        { $$ = new ASTNode(NODE_VARDECL); $$->sval = *$1; $$->line = yylineno; delete $1; }
    | IDENTIFIER '=' expr
        { $$ = new ASTNode(NODE_VARDECL); $$->sval = *$1; $$->line = yylineno; $$->children.push_back($3); delete $1; }
    ;

declarator_list:
    declarator                        { $$ = new std::vector<ASTNode*>(); $$->push_back($1); }
    | declarator_list ',' declarator  { $1->push_back($3); $$ = $1; }
    ;

/* statement-level declaration: supports "int a, b=2, c;" and "const int X = 5;" */
vardecl_stmt:
    type_spec declarator_list
        {
            $$ = new ASTNode(NODE_BLOCK);
            for (auto d : *$2) { d->datatype = *$1; $$->children.push_back(d); }
            delete $1; delete $2;
        }
    | KW_CONST type_spec declarator_list
        {
            $$ = new ASTNode(NODE_BLOCK);
            for (auto d : *$3) { d->datatype = *$2; d->isConst = true; $$->children.push_back(d); }
            delete $2; delete $3;
        }
    ;

assign_stmt:
    IDENTIFIER '=' expr
        {
            $$ = new ASTNode(NODE_ASSIGN);
            $$->sval = *$1; $$->line = yylineno;
            $$->children.push_back($3);
            delete $1;
        }
    ;

compound_assign_stmt:
    IDENTIFIER PLUSEQ expr
        { $$ = new ASTNode(NODE_COMPOUND_ASSIGN); $$->sval = *$1; $$->op = "+="; $$->line = yylineno; $$->children.push_back($3); delete $1; }
    | IDENTIFIER MINUSEQ expr
        { $$ = new ASTNode(NODE_COMPOUND_ASSIGN); $$->sval = *$1; $$->op = "-="; $$->line = yylineno; $$->children.push_back($3); delete $1; }
    | IDENTIFIER MULEQ expr
        { $$ = new ASTNode(NODE_COMPOUND_ASSIGN); $$->sval = *$1; $$->op = "*="; $$->line = yylineno; $$->children.push_back($3); delete $1; }
    | IDENTIFIER DIVEQ expr
        { $$ = new ASTNode(NODE_COMPOUND_ASSIGN); $$->sval = *$1; $$->op = "/="; $$->line = yylineno; $$->children.push_back($3); delete $1; }
    | IDENTIFIER MODEQ expr
    { $$ = new ASTNode(NODE_COMPOUND_ASSIGN); $$->sval = *$1; $$->op = "%="; $$->line = yylineno; $$->children.push_back($3); delete $1; }
    ;

if_stmt:
    KW_IF '(' expr ')' block
        {
            $$ = new ASTNode(NODE_IF); $$->line = yylineno;
            $$->children.push_back($3);
            $$->children.push_back($5);
            $$->children.push_back(nullptr);
        }
    | KW_IF '(' expr ')' block KW_ELSE block
        {
            $$ = new ASTNode(NODE_IF); $$->line = yylineno;
            $$->children.push_back($3);
            $$->children.push_back($5);
            $$->children.push_back($7);
        }
    | KW_IF '(' expr ')' block KW_ELSE if_stmt
        {
            ASTNode* wrapper = new ASTNode(NODE_BLOCK);
            wrapper->children.push_back($7);
            $$ = new ASTNode(NODE_IF); $$->line = yylineno;
            $$->children.push_back($3);
            $$->children.push_back($5);
            $$->children.push_back(wrapper);
        }
    ;

while_stmt:
    KW_WHILE '(' expr ')' block
        {
            $$ = new ASTNode(NODE_WHILE); $$->line = yylineno;
            $$->children.push_back($3);
            $$->children.push_back($5);
        }
    ;

do_while_stmt:
    KW_DO block KW_WHILE '(' expr ')'
        {
            $$ = new ASTNode(NODE_DOWHILE); $$->line = yylineno;
            $$->children.push_back($2);
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
            $$ = new ASTNode(NODE_FOR); $$->line = yylineno;
            $$->children.push_back($3);
            $$->children.push_back($5);
            $$->children.push_back($7);
            $$->children.push_back($9);
        }
    ;

switch_stmt:
    KW_SWITCH '(' expr ')' '{' case_list '}'
        {
            $$ = new ASTNode(NODE_SWITCH); $$->line = yylineno;
            $$->children.push_back($3);
            for (auto c : *$6) $$->children.push_back(c);
            delete $6;
        }
    ;

case_list:
    /* empty */              { $$ = new std::vector<ASTNode*>(); }
    | case_list case_clause  { $1->push_back($2); $$ = $1; }
    ;

case_value:
    INT_LIT   { $$ = (int)strtoll($1->c_str(), nullptr, 10); delete $1; }
    | CHAR_LIT  { $$ = (int)$1; }
    ;

case_clause:
    KW_CASE case_value ':' stmt_list
        {
            $$ = new ASTNode(NODE_CASE); $$->line = yylineno;
            $$->ival = $2;
            $$->children.push_back($4);
        }
    | KW_DEFAULT ':' stmt_list
        {
            $$ = new ASTNode(NODE_DEFAULT); $$->line = yylineno;
            $$->children.push_back($3);
        }
    ;

break_stmt:
    KW_BREAK { $$ = new ASTNode(NODE_BREAK); $$->line = yylineno; }
    ;

continue_stmt:
    KW_CONTINUE { $$ = new ASTNode(NODE_CONTINUE); $$->line = yylineno; }
    ;

printf_stmt:
    KW_PRINTF '(' STRING_LIT printf_arglist ')'
        {
            $$ = new ASTNode(NODE_PRINTF); $$->line = yylineno;
            $$->sval = *$3;
            $$->children = *$4;
            delete $3; delete $4;
        }
    ;

printf_arglist:
    /* empty */                      { $$ = new std::vector<ASTNode*>(); }
    | ',' expr printf_arglist        { $3->insert($3->begin(), $2); $$ = $3; }
    ;

scanf_stmt:
    KW_SCANF '(' STRING_LIT scanf_arglist ')'
        {
            $$ = new ASTNode(NODE_SCANF); $$->line = yylineno;
            $$->sval = *$3;
            $$->children = *$4;
            delete $3; delete $4;
        }
    ;

scanf_arglist:
    /* empty */                          { $$ = new std::vector<ASTNode*>(); }
    | ',' '&' IDENTIFIER scanf_arglist
        {
            ASTNode* idn = new ASTNode(NODE_ID);
            idn->sval = *$3; delete $3;
            $4->insert($4->begin(), idn);
            $$ = $4;
        }
    ;

return_stmt:
    KW_RETURN            { $$ = new ASTNode(NODE_RETURN); $$->line = yylineno; }
    | KW_RETURN expr       { $$ = new ASTNode(NODE_RETURN); $$->line = yylineno; $$->children.push_back($2); }
    ;

expr:
    INT_LIT                {
                              long long v = strtoll($1->c_str(), nullptr, 10);
                              delete $1;
                              $$ = new ASTNode(NODE_NUM_INT);
                              if (v >= -2147483648LL && v <= 2147483647LL) { $$->ival = (int)v; }
                              else { $$->datatype = "long"; $$->llit = v; }
                            }
    | FLOAT_LIT              { $$ = new ASTNode(NODE_NUM_FLOAT); $$->fval = $1; }
    | CHAR_LIT                { $$ = new ASTNode(NODE_CHAR); $$->cval = $1; }
    | STRING_LIT               { $$ = new ASTNode(NODE_STRING); $$->sval = *$1; delete $1; }
    | IDENTIFIER                { $$ = new ASTNode(NODE_ID); $$->sval = *$1; delete $1; }
    | '(' expr ')'               { $$ = $2; }
    | '-' expr %prec UMINUS       { $$ = new ASTNode(NODE_UNOP); $$->op = "-"; $$->children.push_back($2); }
    | '!' expr %prec NOTPREC        { $$ = new ASTNode(NODE_UNOP); $$->op = "!"; $$->children.push_back($2); }
    | '~' expr %prec NOTPREC          { $$ = new ASTNode(NODE_UNOP); $$->op = "~"; $$->children.push_back($2); }
    | INC IDENTIFIER                  { $$ = new ASTNode(NODE_PREINC); $$->sval = *$2; delete $2; }
    | DEC IDENTIFIER                    { $$ = new ASTNode(NODE_PREDEC); $$->sval = *$2; delete $2; }
    | IDENTIFIER INC                      { $$ = new ASTNode(NODE_POSTINC); $$->sval = *$1; delete $1; }
    | IDENTIFIER DEC                        { $$ = new ASTNode(NODE_POSTDEC); $$->sval = *$1; delete $1; }
    | expr '+' expr             { $$ = new ASTNode(NODE_BINOP); $$->op = "+"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '-' expr             { $$ = new ASTNode(NODE_BINOP); $$->op = "-"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '*' expr             { $$ = new ASTNode(NODE_BINOP); $$->op = "*"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '/' expr             { $$ = new ASTNode(NODE_BINOP); $$->op = "/"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '%' expr             { $$ = new ASTNode(NODE_BINOP); $$->op = "%"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '<' expr             { $$ = new ASTNode(NODE_BINOP); $$->op = "<"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '>' expr             { $$ = new ASTNode(NODE_BINOP); $$->op = ">"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr LE expr               { $$ = new ASTNode(NODE_BINOP); $$->op = "<="; $$->children.push_back($1); $$->children.push_back($3); }
    | expr GE expr               { $$ = new ASTNode(NODE_BINOP); $$->op = ">="; $$->children.push_back($1); $$->children.push_back($3); }
    | expr EQ expr               { $$ = new ASTNode(NODE_BINOP); $$->op = "=="; $$->children.push_back($1); $$->children.push_back($3); }
    | expr NE expr               { $$ = new ASTNode(NODE_BINOP); $$->op = "!="; $$->children.push_back($1); $$->children.push_back($3); }
    | expr AND expr              { $$ = new ASTNode(NODE_BINOP); $$->op = "&&"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr OR expr               { $$ = new ASTNode(NODE_BINOP); $$->op = "||"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '&' expr               { $$ = new ASTNode(NODE_BINOP); $$->op = "&"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '|' expr               { $$ = new ASTNode(NODE_BINOP); $$->op = "|"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '^' expr               { $$ = new ASTNode(NODE_BINOP); $$->op = "^"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr LSHIFT expr            { $$ = new ASTNode(NODE_BINOP); $$->op = "<<"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr RSHIFT expr            { $$ = new ASTNode(NODE_BINOP); $$->op = ">>"; $$->children.push_back($1); $$->children.push_back($3); }
    | expr '?' expr ':' expr      { $$ = new ASTNode(NODE_TERNARY); $$->children.push_back($1); $$->children.push_back($3); $$->children.push_back($5); }
    | KW_SIZEOF '(' type_spec ')' { $$ = new ASTNode(NODE_SIZEOF); $$->datatype = *$3; delete $3; }
    | KW_SIZEOF '(' expr ')'      { $$ = new ASTNode(NODE_SIZEOF); $$->children.push_back($3); }
    | KW_SQRT '(' expr ')'        { $$ = new ASTNode(NODE_CALL); $$->sval = "sqrt"; $$->children.push_back($3); }
    | KW_POW '(' expr ',' expr ')'{ $$ = new ASTNode(NODE_CALL); $$->sval = "pow"; $$->children.push_back($3); $$->children.push_back($5); }
    | KW_ABS '(' expr ')'         { $$ = new ASTNode(NODE_CALL); $$->sval = "abs"; $$->children.push_back($3); }
    | KW_CEIL '(' expr ')'        { $$ = new ASTNode(NODE_CALL); $$->sval = "ceil"; $$->children.push_back($3); }
    | KW_FLOOR '(' expr ')'       { $$ = new ASTNode(NODE_CALL); $$->sval = "floor"; $$->children.push_back($3); }
    ;

%%

void yyerror(const char* s) {
    cerr << "Syntax Error:" << endl;
    cerr << "Line " << yylineno << ":" << endl;
    cerr << s;
    if (yytext && yytext[0] != '\0') cerr << " (near token '" << yytext << "')";
    cerr << "." << endl;
    g_syntaxOk = false;
}
