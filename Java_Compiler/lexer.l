%{

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "parser.tab.h"

using namespace std;

extern int yylineno;
extern bool g_debugMode;   // defined in main.cpp, controls token dump

static void reportToken(const char* name, const string& text) {
    if (g_debugMode) {
        cout.width(12); cout << left << name << " " << text << endl;
    }
}
%}

%option noyywrap
%option yylineno

DIGIT       [0-9]
LETTER      [a-zA-Z_]
WS          [ \t\r\n]

%%

"//".*                              { /* single line comment: ignore */ }
"/*"([^*]|\*+[^*/])*\*+"/"          { /* multi-line comment: ignore */ }

"System"{WS}*"."{WS}*"out"{WS}*"."{WS}*"println"   { reportToken("KEYWORD", "System.out.println"); return KW_SYSOUT_PRINTLN; }
"System"{WS}*"."{WS}*"out"{WS}*"."{WS}*"print"      { reportToken("KEYWORD", "System.out.print"); return KW_SYSOUT_PRINT; }
"System"{WS}*"."{WS}*"in"                            { reportToken("KEYWORD", "System.in"); return KW_SYSTEM_IN; }

"public"    { reportToken("KEYWORD", yytext); return KW_PUBLIC; }
"class"     { reportToken("KEYWORD", yytext); return KW_CLASS; }
"static"    { reportToken("KEYWORD", yytext); return KW_STATIC; }
"void"      { reportToken("KEYWORD", yytext); return KW_VOID; }
"main"      { reportToken("KEYWORD", yytext); return KW_MAIN; }
"int"       { reportToken("KEYWORD", yytext); return KW_INT; }
"float"     { reportToken("KEYWORD", yytext); return KW_FLOAT; }
"double"    { reportToken("KEYWORD", yytext); return KW_DOUBLE; }
"char"      { reportToken("KEYWORD", yytext); return KW_CHAR; }
"boolean"   { reportToken("KEYWORD", yytext); return KW_BOOLEAN; }
"String"    { reportToken("KEYWORD", yytext); return KW_STRING; }
"Scanner"   { reportToken("KEYWORD", yytext); return KW_SCANNER; }
"true"      { reportToken("KEYWORD", yytext); return KW_TRUE; }
"false"     { reportToken("KEYWORD", yytext); return KW_FALSE; }
"if"        { reportToken("KEYWORD", yytext); return KW_IF; }
"else"      { reportToken("KEYWORD", yytext); return KW_ELSE; }
"while"     { reportToken("KEYWORD", yytext); return KW_WHILE; }
"do"        { reportToken("KEYWORD", yytext); return KW_DO; }
"for"       { reportToken("KEYWORD", yytext); return KW_FOR; }
"break"     { reportToken("KEYWORD", yytext); return KW_BREAK; }
"continue"  { reportToken("KEYWORD", yytext); return KW_CONTINUE; }
"return"    { reportToken("KEYWORD", yytext); return KW_RETURN; }
"import"    { reportToken("KEYWORD", yytext); return KW_IMPORT; }
"new"       { reportToken("KEYWORD", yytext); return KW_NEW; }
"final"     { reportToken("KEYWORD", yytext); return KW_FINAL; }
"switch"    { reportToken("KEYWORD", yytext); return KW_SWITCH; }
"case"      { reportToken("KEYWORD", yytext); return KW_CASE; }
"default"   { reportToken("KEYWORD", yytext); return KW_DEFAULT; }

{DIGIT}+"."{DIGIT}+[fFdD]?   { reportToken("FLOAT", yytext); yylval.fval = atof(yytext); return FLOAT_LIT; }
{DIGIT}+[fFdD]               { reportToken("FLOAT", yytext); yylval.fval = atof(yytext); return FLOAT_LIT; }
{DIGIT}+                     { reportToken("INTEGER", yytext); yylval.ival = atoi(yytext); return INT_LIT; }

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
                        size_t last = raw.size() - 2; // index of last content char (before closing quote)
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
"+="   { reportToken("OP", yytext); return PLUSEQ; }
"-="   { reportToken("OP", yytext); return MINUSEQ; }
"*="   { reportToken("OP", yytext); return MULEQ; }
"/="   { reportToken("OP", yytext); return DIVEQ; }
"%="   { reportToken("OP", yytext); return MODEQ; }
"++"   { reportToken("OP", yytext); return INC; }
"--"   { reportToken("OP", yytext); return DEC; }
"<<"   { reportToken("OP", yytext); return LSHIFT; }
">>"   { reportToken("OP", yytext); return RSHIFT; }

"&"    { reportToken("OP", yytext); return '&'; }
"|"    { reportToken("OP", yytext); return '|'; }
"^"    { reportToken("OP", yytext); return '^'; }
"~"    { reportToken("OP", yytext); return '~'; }
"?"    { reportToken("OP", yytext); return '?'; }
":"    { reportToken("OP", yytext); return ':'; }

"+"    { reportToken("OP", yytext); return '+'; }
"-"    { reportToken("OP", yytext); return '-'; }
"*"    { reportToken("OP", yytext); return '*'; }
"/"    { reportToken("OP", yytext); return '/'; }
"%"    { reportToken("OP", yytext); return '%'; }
"="    { reportToken("OP", yytext); return '='; }
"<"    { reportToken("OP", yytext); return '<'; }
">"    { reportToken("OP", yytext); return '>'; }
"!"    { reportToken("OP", yytext); return '!'; }
"("    { reportToken("LPAREN", yytext); return '('; }
")"    { reportToken("RPAREN", yytext); return ')'; }
"{"    { reportToken("LBRACE", yytext); return '{'; }
"}"    { reportToken("RBRACE", yytext); return '}'; }
"["    { reportToken("LBRACKET", yytext); return '['; }
"]"    { reportToken("RBRACKET", yytext); return ']'; }
";"    { reportToken("SEMICOLON", yytext); return ';'; }
","    { reportToken("COMMA", yytext); return ','; }
"."    { reportToken("DOT", yytext); return '.'; }

[ \t\r\n]+   { /* ignore whitespace */ }

.      { cerr << "Lexer Error: unknown character '" << yytext << "' at line " << yylineno << endl; }

%%
