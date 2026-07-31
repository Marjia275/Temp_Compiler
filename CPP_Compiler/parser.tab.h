/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* "%code requires" blocks.  */

/* Line 1685 of yacc.c  */
#line 34 "parser.y"

    #include <string>
    #include <vector>
    #include "ast.h"



/* Line 1685 of yacc.c  */
#line 47 "parser.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_LIT = 258,
     FLOAT_LIT = 259,
     CHAR_LIT = 260,
     STRING_LIT = 261,
     IDENTIFIER = 262,
     KW_INT = 263,
     KW_FLOAT = 264,
     KW_DOUBLE = 265,
     KW_CHAR = 266,
     KW_BOOL = 267,
     KW_STRING = 268,
     KW_VOID = 269,
     KW_TRUE = 270,
     KW_FALSE = 271,
     KW_IF = 272,
     KW_ELSE = 273,
     KW_WHILE = 274,
     KW_DO = 275,
     KW_FOR = 276,
     KW_BREAK = 277,
     KW_CONTINUE = 278,
     KW_RETURN = 279,
     KW_COUT = 280,
     KW_CIN = 281,
     KW_ENDL = 282,
     KW_CONST = 283,
     KW_LONG = 284,
     KW_UNSIGNED = 285,
     KW_SIZEOF = 286,
     KW_SWITCH = 287,
     KW_CASE = 288,
     KW_DEFAULT = 289,
     EQ = 290,
     NE = 291,
     LE = 292,
     GE = 293,
     AND = 294,
     OR = 295,
     SHL = 296,
     SHR = 297,
     PLUSEQ = 298,
     MINUSEQ = 299,
     MULEQ = 300,
     DIVEQ = 301,
     INC = 302,
     DEC = 303,
     UMINUS = 304,
     NOTPREC = 305,
     TILDEPREC = 306,
     SIZEOFPREC = 307
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1685 of yacc.c  */
#line 42 "parser.y"

    long long ival;
    double fval;
    char cval;
    std::string* sval;
    ASTNode* node;
    std::vector<ASTNode*>* nodelist;



/* Line 1685 of yacc.c  */
#line 127 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


