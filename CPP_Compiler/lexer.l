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

%%

"//".*                              { /* single line comment: ignore */ }
"/*"([^*]|\*+[^*/])*\*+"/"          { /* multi-line comment: ignore */ }

"#"[^\n]*                           { /* #include <...> etc: ignore */ }
"using"[ \t]+"namespace"[ \t]+"std"[ \t]*";"   { /* "using namespace std;": ignore */ }

"int"      { reportToken("KEYWORD", yytext); return KW_INT; }
"float"    { reportToken("KEYWORD", yytext); return KW_FLOAT; }
"double"   { reportToken("KEYWORD", yytext); return KW_DOUBLE; }
"char"     { reportToken("KEYWORD", yytext); return KW_CHAR; }
"bool"     { reportToken("KEYWORD", yytext); return KW_BOOL; }
"string"   { reportToken("KEYWORD", yytext); return KW_STRING; }
"true"     { reportToken("KEYWORD", yytext); return KW_TRUE; }
"false"    { reportToken("KEYWORD", yytext); return KW_FALSE; }
"if"       { reportToken("KEYWORD", yytext); return KW_IF; }
"else"     { reportToken("KEYWORD", yytext); return KW_ELSE; }
"while"    { reportToken("KEYWORD", yytext); return KW_WHILE; }
"do"       { reportToken("KEYWORD", yytext); return KW_DO; }
"for"      { reportToken("KEYWORD", yytext); return KW_FOR; }
"break"    { reportToken("KEYWORD", yytext); return KW_BREAK; }
"continue" { reportToken("KEYWORD", yytext); return KW_CONTINUE; }
"return"   { reportToken("KEYWORD", yytext); return KW_RETURN; }
"cout"     { reportToken("KEYWORD", yytext); return KW_COUT; }
"cin"      { reportToken("KEYWORD", yytext); return KW_CIN; }
"endl"     { reportToken("KEYWORD", yytext); return KW_ENDL; }
"void"     { reportToken("KEYWORD", yytext); return KW_VOID; }
"const"    { reportToken("KEYWORD", yytext); return KW_CONST; }
"long"     { reportToken("KEYWORD", yytext); return KW_LONG; }
"unsigned" { reportToken("KEYWORD", yytext); return KW_UNSIGNED; }
"sizeof"   { reportToken("KEYWORD", yytext); return KW_SIZEOF; }
"switch"   { reportToken("KEYWORD", yytext); return KW_SWITCH; }
"case"     { reportToken("KEYWORD", yytext); return KW_CASE; }
"default"  { reportToken("KEYWORD", yytext); return KW_DEFAULT; }

{DIGIT}+"."{DIGIT}+   { reportToken("FLOAT", yytext); yylval.fval = atof(yytext); return FLOAT_LIT; }
{DIGIT}+              { reportToken("INTEGER", yytext); yylval.ival = strtoll(yytext, nullptr, 10); return INT_LIT; }

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
"<<"   { reportToken("OP", yytext); return SHL; }
">>"   { reportToken("OP", yytext); return SHR; }
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
"("    { reportToken("LPAREN", yytext); return '('; }
")"    { reportToken("RPAREN", yytext); return ')'; }
"{"    { reportToken("LBRACE", yytext); return '{'; }
"}"    { reportToken("RBRACE", yytext); return '}'; }
";"    { reportToken("SEMICOLON", yytext); return ';'; }
","    { reportToken("COMMA", yytext); return ','; }
"?"    { reportToken("QMARK", yytext); return '?'; }
":"    { reportToken("COLON", yytext); return ':'; }

[ \t\r\n]+   { /* ignore whitespace */ }

.      {
         cerr << "Lexical Error:" << endl;
         cerr << "Line " << yylineno << ":" << endl;
         cerr << "Unrecognized character '" << yytext << "'." << endl;
       }

%%
