%{

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "parser.tab.h"

using namespace std;

extern int yylineno;
extern bool g_debugMode;   

static void reportToken(const char* name, const string& text) {
    if (g_debugMode) {
        cout.width(12); cout << left << name << " " << text << endl;
    }
}
static void lexError(const string& msg) {
    cerr << "Lexical Error:" << endl;
    cerr << "Line " << yylineno << ":" << endl;
    cerr << msg << endl;
    exit(1);
}
%}


%option noyywrap
%option yylineno
%option nounput

DIGIT       [0-9]
LETTER      [a-zA-Z_]

%%

"//".*                              { /* single line comment: ignore */ }
"/*"([^*]|\*+[^*/])*\*+"/"          { /* multi-line comment: ignore */ }

"#"[^\n]*                           { /* preprocessor line, e.g. #include<stdio.h>: ignore */ }

"const"    { reportToken("KEYWORD", yytext); return KW_CONST; }
"int"      { reportToken("KEYWORD", yytext); return KW_INT; }
"float"    { reportToken("KEYWORD", yytext); return KW_FLOAT; }
"double"   { reportToken("KEYWORD", yytext); return KW_DOUBLE; }
"char"     { reportToken("KEYWORD", yytext); return KW_CHAR; }
"long"     { reportToken("KEYWORD", yytext); return KW_LONG; }
"unsigned" { reportToken("KEYWORD", yytext); return KW_UNSIGNED; }
"if"       { reportToken("KEYWORD", yytext); return KW_IF; }
"else"     { reportToken("KEYWORD", yytext); return KW_ELSE; }
"while"    { reportToken("KEYWORD", yytext); return KW_WHILE; }
"for"      { reportToken("KEYWORD", yytext); return KW_FOR; }
"do"       { reportToken("KEYWORD", yytext); return KW_DO; }
"switch"   { reportToken("KEYWORD", yytext); return KW_SWITCH; }
"case"     { reportToken("KEYWORD", yytext); return KW_CASE; }
"default"  { reportToken("KEYWORD", yytext); return KW_DEFAULT; }
"break"    { reportToken("KEYWORD", yytext); return KW_BREAK; }
"continue" { reportToken("KEYWORD", yytext); return KW_CONTINUE; }
"sizeof"   { reportToken("KEYWORD", yytext); return KW_SIZEOF; }
"printf"   { reportToken("KEYWORD", yytext); return KW_PRINTF; }
"scanf"    { reportToken("KEYWORD", yytext); return KW_SCANF; }
"sqrt"     { reportToken("KEYWORD", yytext); return KW_SQRT; }
"pow"      { reportToken("KEYWORD", yytext); return KW_POW; }
"abs"      { reportToken("KEYWORD", yytext); return KW_ABS; }
"ceil"     { reportToken("KEYWORD", yytext); return KW_CEIL; }
"floor"    { reportToken("KEYWORD", yytext); return KW_FLOOR; }
"return"   { reportToken("KEYWORD", yytext); return KW_RETURN; }
"void"     { reportToken("KEYWORD", yytext); return KW_VOID; }

{DIGIT}+\.{DIGIT}+   { reportToken("FLOAT", yytext); yylval.fval = atof(yytext); return FLOAT_LIT; }
{DIGIT}+              { reportToken("INTEGER", yytext); yylval.sval = new string(yytext); return INT_LIT; }

{DIGIT}+"."{DIGIT}+{LETTER}({LETTER}|{DIGIT})*   {
    lexError("Invalid identifier '" + string(yytext) + "' - identifiers cannot start with a digit.");
}
{DIGIT}+{LETTER}({LETTER}|{DIGIT})*   {
    lexError("Invalid identifier '" + string(yytext) + "' - identifiers cannot start with a digit.");
}
\'(\\.|[^\\'])\'      {
                        reportToken("CHAR", yytext);
                        string t(yytext);
                        char c;
                        if (t[1] == '\\') {
                            switch (t[2]) {
                                case 'n': c = '\n'; break;
                                case 't': c = '\t'; break;
                                case '0': c = '\0'; break;
                                case '\\': c = '\\'; break;
                                case '\'': c = '\''; break;
                                default: c = t[2];
                            }
                        } else {
                            c = t[1];
                        }
                        yylval.cval = c;
                        return CHAR_LIT;
                      }

\"([^\"\\]|\\.)*\"   {
                        reportToken("STRING", yytext);
                        string raw(yytext);
                        string val;
                        size_t last = raw.size() - 2; 
                        for (size_t i = 1; i <= last; i++) {
                            if (raw[i] == '\\' && i < last) {
                                i++;
                                switch (raw[i]) {
                                    case 'n': val += '\n'; break;
                                    case 't': val += '\t'; break;
                                    case '\\': val += '\\'; break;
                                    case '"': val += '"'; break;
                                    default: val += raw[i];
                                }
                            } else {
                                val += raw[i];
                            }
                        }
                        yylval.sval = new string(val);
                        return STRING_LIT;
                      }

{LETTER}({LETTER}|{DIGIT})*   { reportToken("IDENTIFIER", yytext); yylval.sval = new string(yytext); return IDENTIFIER; }

"=="   { reportToken("OP", yytext); return EQ; }
"!="   { reportToken("OP", yytext); return NE; }
"<="   { reportToken("OP", yytext); return LE; }
">="   { reportToken("OP", yytext); return GE; }
"&&"   { reportToken("OP", yytext); return AND; }
"||"   { reportToken("OP", yytext); return OR; }
"<<"   { reportToken("OP", yytext); return LSHIFT; }
">>"   { reportToken("OP", yytext); return RSHIFT; }
"+="   { reportToken("OP", yytext); return PLUSEQ; }
"-="   { reportToken("OP", yytext); return MINUSEQ; }
"*="   { reportToken("OP", yytext); return MULEQ; }
"/="   { reportToken("OP", yytext); return DIVEQ; }
"%="   { reportToken("OP", yytext); return MODEQ; }
"++"   { reportToken("OP", yytext); return INC; }
"--"   { reportToken("OP", yytext); return DEC; }

"+"    { reportToken("OP", yytext); return '+'; }
"-"    { reportToken("OP", yytext); return '-'; }
"*"    { reportToken("OP", yytext); return '*'; }
"/"    { reportToken("OP", yytext); return '/'; }
"%"    { reportToken("OP", yytext); return '%'; }
"="    { reportToken("OP", yytext); return '='; }
"<"    { reportToken("OP", yytext); return '<'; }
">"    { reportToken("OP", yytext); return '>'; }
"!"    { reportToken("OP", yytext); return '!'; }
"&"    { reportToken("OP", yytext); return '&'; }
"|"    { reportToken("OP", yytext); return '|'; }
"^"    { reportToken("OP", yytext); return '^'; }
"~"    { reportToken("OP", yytext); return '~'; }
"?"    { reportToken("OP", yytext); return '?'; }
":"    { reportToken("OP", yytext); return ':'; }
"("    { reportToken("LPAREN", yytext); return '('; }
")"    { reportToken("RPAREN", yytext); return ')'; }
"{"    { reportToken("LBRACE", yytext); return '{'; }
"}"    { reportToken("RBRACE", yytext); return '}'; }
";"    { reportToken("SEMICOLON", yytext); return ';'; }
","    { reportToken("COMMA", yytext); return ','; }



[ \t\r\n]+   { /* ignore whitespace */ }

.      { lexError("Unrecognized character '" + string(yytext) + "'."); }



%%
