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
#line 26 "parser.y"

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
     KW_CONST = 263,
     KW_INT = 264,
     KW_FLOAT = 265,
     KW_DOUBLE = 266,
     KW_CHAR = 267,
     KW_LONG = 268,
     KW_UNSIGNED = 269,
     KW_IF = 270,
     KW_ELSE = 271,
     KW_WHILE = 272,
     KW_FOR = 273,
     KW_DO = 274,
     KW_SWITCH = 275,
     KW_CASE = 276,
     KW_DEFAULT = 277,
     KW_BREAK = 278,
     KW_CONTINUE = 279,
     KW_PRINTF = 280,
     KW_SCANF = 281,
     KW_SIZEOF = 282,
     KW_SQRT = 283,
     KW_POW = 284,
     KW_ABS = 285,
     KW_CEIL = 286,
     KW_FLOOR = 287,
     KW_RETURN = 288,
     KW_VOID = 289,
     EQ = 290,
     NE = 291,
     LE = 292,
     GE = 293,
     AND = 294,
     OR = 295,
     PLUSEQ = 296,
     MINUSEQ = 297,
     MULEQ = 298,
     DIVEQ = 299,
     INC = 300,
     DEC = 301,
     LSHIFT = 302,
     RSHIFT = 303,
     UMINUS = 304,
     NOTPREC = 305
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1685 of yacc.c  */
#line 34 "parser.y"

    int ival;
    double fval;
    char cval;
    std::string* sval;
    ASTNode* node;
    std::vector<ASTNode*>* nodelist;



/* Line 1685 of yacc.c  */
#line 125 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


