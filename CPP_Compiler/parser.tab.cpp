/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

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


/* Line 189 of yacc.c  */
#line 106 "parser.tab.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 34 "parser.y"

    #include <string>
    #include <vector>
    #include "ast.h"



/* Line 209 of yacc.c  */
#line 138 "parser.tab.cpp"

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
     EQ = 287,
     NE = 288,
     LE = 289,
     GE = 290,
     AND = 291,
     OR = 292,
     SHL = 293,
     SHR = 294,
     PLUSEQ = 295,
     MINUSEQ = 296,
     MULEQ = 297,
     DIVEQ = 298,
     INC = 299,
     DEC = 300,
     UMINUS = 301,
     NOTPREC = 302,
     TILDEPREC = 303,
     SIZEOFPREC = 304
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 42 "parser.y"

    long long ival;
    double fval;
    char cval;
    std::string* sval;
    ASTNode* node;
    std::vector<ASTNode*>* nodelist;



/* Line 214 of yacc.c  */
#line 215 "parser.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 227 "parser.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   614

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNRULES -- Number of states.  */
#define YYNSTATES  176

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,     2,     2,     2,    57,    50,     2,
      62,    63,    55,    53,    68,    54,     2,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    66,
      51,    67,    52,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,    48,    65,    70,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    58,    59,    60,    61
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    13,    14,    17,    20,    23,    26,
      29,    31,    33,    35,    37,    40,    43,    46,    48,    50,
      52,    54,    56,    58,    60,    62,    65,    68,    70,    74,
      77,    80,    82,    84,    88,    90,    94,    97,   101,   105,
     109,   113,   117,   121,   127,   135,   143,   149,   157,   158,
     160,   162,   163,   165,   166,   168,   170,   172,   182,   184,
     187,   189,   191,   193,   195,   197,   199,   201,   203,   205,
     207,   211,   214,   217,   220,   223,   226,   229,   232,   236,
     240,   244,   248,   252,   256,   260,   264,   268,   272,   276,
     280,   284,   288,   292,   296,   300,   304,   310,   315
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      72,     0,    -1,     8,     7,    62,    63,    73,    -1,    64,
      74,    65,    -1,    -1,    74,    75,    -1,    79,    66,    -1,
      80,    66,    -1,    81,    66,    -1,    90,    66,    -1,    82,
      -1,    83,    -1,    84,    -1,    88,    -1,    22,    66,    -1,
      23,    66,    -1,    89,    66,    -1,    73,    -1,    66,    -1,
       8,    -1,     9,    -1,    10,    -1,    11,    -1,    12,    -1,
      13,    -1,    29,    29,    -1,    29,     8,    -1,    29,    -1,
      30,    29,    29,    -1,    30,    29,    -1,    30,     8,    -1,
      30,    -1,     7,    -1,     7,    67,    90,    -1,    77,    -1,
      78,    68,    77,    -1,    76,    78,    -1,    28,    76,    78,
      -1,     7,    67,    90,    -1,     7,    40,    90,    -1,     7,
      41,    90,    -1,     7,    42,    90,    -1,     7,    43,    90,
      -1,    17,    62,    90,    63,    73,    -1,    17,    62,    90,
      63,    73,    18,    73,    -1,    17,    62,    90,    63,    73,
      18,    82,    -1,    19,    62,    90,    63,    73,    -1,    20,
      73,    19,    62,    90,    63,    66,    -1,    -1,    79,    -1,
      80,    -1,    -1,    90,    -1,    -1,    80,    -1,    81,    -1,
      90,    -1,    21,    62,    85,    66,    86,    66,    87,    63,
      73,    -1,    24,    -1,    24,    90,    -1,     3,    -1,     4,
      -1,     5,    -1,     6,    -1,    15,    -1,    16,    -1,    25,
      -1,    26,    -1,    27,    -1,     7,    -1,    62,    90,    63,
      -1,    54,    90,    -1,    69,    90,    -1,    70,    90,    -1,
      44,     7,    -1,    45,     7,    -1,     7,    44,    -1,     7,
      45,    -1,    90,    53,    90,    -1,    90,    54,    90,    -1,
      90,    55,    90,    -1,    90,    56,    90,    -1,    90,    57,
      90,    -1,    90,    51,    90,    -1,    90,    52,    90,    -1,
      90,    34,    90,    -1,    90,    35,    90,    -1,    90,    32,
      90,    -1,    90,    33,    90,    -1,    90,    36,    90,    -1,
      90,    37,    90,    -1,    90,    50,    90,    -1,    90,    48,
      90,    -1,    90,    49,    90,    -1,    90,    38,    90,    -1,
      90,    39,    90,    -1,    90,    46,    90,    47,    90,    -1,
      31,    62,    76,    63,    -1,    31,    62,     7,    63,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    95,    95,   106,   110,   111,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   147,   153,   163,   168,   176,   188,   203,   213,
     215,   217,   219,   224,   231,   238,   250,   259,   268,   269,
     270,   274,   275,   279,   280,   281,   282,   286,   297,   298,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   341
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_LIT", "FLOAT_LIT", "CHAR_LIT",
  "STRING_LIT", "IDENTIFIER", "KW_INT", "KW_FLOAT", "KW_DOUBLE", "KW_CHAR",
  "KW_BOOL", "KW_STRING", "KW_VOID", "KW_TRUE", "KW_FALSE", "KW_IF",
  "KW_ELSE", "KW_WHILE", "KW_DO", "KW_FOR", "KW_BREAK", "KW_CONTINUE",
  "KW_RETURN", "KW_COUT", "KW_CIN", "KW_ENDL", "KW_CONST", "KW_LONG",
  "KW_UNSIGNED", "KW_SIZEOF", "EQ", "NE", "LE", "GE", "AND", "OR", "SHL",
  "SHR", "PLUSEQ", "MINUSEQ", "MULEQ", "DIVEQ", "INC", "DEC", "'?'", "':'",
  "'|'", "'^'", "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "UMINUS", "NOTPREC", "TILDEPREC", "SIZEOFPREC", "'('", "')'", "'{'",
  "'}'", "';'", "'='", "','", "'!'", "'~'", "$accept", "program", "block",
  "stmt_list", "stmt", "type_spec", "declarator", "declarator_list",
  "vardecl", "assign_stmt", "compound_assign_stmt", "if_stmt",
  "while_stmt", "do_while_stmt", "for_init", "for_cond", "for_update",
  "for_stmt", "return_stmt", "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    63,    58,   124,    94,
      38,    60,    62,    43,    45,    42,    47,    37,   301,   302,
     303,   304,    40,    41,   123,   125,    59,    61,    44,    33,
     126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    74,    74,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    77,    77,    78,    78,    79,    79,    80,    81,
      81,    81,    81,    82,    82,    82,    83,    84,    85,    85,
      85,    86,    86,    87,    87,    87,    87,    88,    89,    89,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     0,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     3,     2,
       2,     1,     1,     3,     1,     3,     2,     3,     3,     3,
       3,     3,     3,     5,     7,     7,     5,     7,     0,     1,
       1,     0,     1,     0,     1,     1,     1,     9,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     2,     2,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     4,     2,     0,
      60,    61,    62,    63,    69,    19,    20,    21,    22,    23,
      24,    64,    65,     0,     0,     0,     0,     0,     0,    58,
      66,    67,    68,     0,    27,    31,     0,     0,     0,     0,
       0,     3,    18,     0,     0,    17,     5,     0,     0,     0,
       0,    10,    11,    12,    13,     0,     0,     0,     0,     0,
       0,    76,    77,     0,     0,     0,     0,    48,    14,    15,
      69,    59,     0,    26,    25,    30,    29,     0,    74,    75,
      71,     0,    72,    73,    32,    34,    36,     6,     7,     8,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,    39,    40,    41,    42,    38,     0,     0,     0,     0,
      49,    50,     0,    37,    28,     0,     0,    70,     0,     0,
      87,    88,    85,    86,    89,    90,    94,    95,     0,    92,
      93,    91,    83,    84,    78,    79,    80,    81,    82,     0,
       0,     0,    51,    98,    97,    33,    35,     0,    43,    46,
       0,     0,    52,    96,     0,     0,    53,    44,    45,    47,
      54,    55,     0,    56,     0,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    46,    47,    85,    86,    48,    49,
      50,    51,    52,    53,   122,   161,   172,    54,    55,    56
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -67
static const yytype_int16 yypact[] =
{
       7,    13,    39,   -18,   -67,   -12,   -19,   -67,   -67,   163,
     -67,   -67,   -67,   -67,   -17,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -16,   -14,   -19,   -10,    -6,    -5,    88,
     -67,   -67,   -67,   233,    11,    24,    -8,    55,    56,    88,
      88,   -67,   -67,    88,    88,   -67,   -67,    57,    -1,     0,
      22,   -67,   -67,   -67,   -67,    23,   234,    88,    88,    88,
      88,   -67,   -67,    88,    88,    88,    48,     1,   -67,   -67,
     -11,   414,    57,   -67,   -67,   -67,    61,   473,   -67,   -67,
     -67,   260,   -67,   -67,    29,   -67,    30,   -67,   -67,   -67,
     -67,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
     -67,   414,   414,   414,   414,   414,   292,   324,     6,    32,
     -67,   -67,    31,    30,   -67,    38,    42,   -67,    88,    57,
     533,   533,   557,   557,   466,   440,     2,     2,   388,   492,
     500,   526,   557,   557,   -51,   -51,   -67,   -67,   -67,   -19,
     -19,    88,    88,   -67,   -67,   414,   -67,    88,    84,   -67,
     356,    41,   414,   414,   -15,    43,   195,   -67,   -67,   -67,
     -67,   -67,    45,   414,   -19,   -67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,    -9,   -67,   -67,   -30,   -13,    40,    44,   -66,
     -56,   -47,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -22
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      45,   121,    23,    72,   107,   108,   109,    71,   119,    15,
      16,    17,    18,    19,    20,     1,    66,    80,    81,    73,
       3,    82,    83,    57,    58,    59,    60,    61,    62,    33,
      34,    35,    75,    61,    62,   111,   112,   113,   114,     4,
      74,   115,   116,   117,     5,     7,    64,   126,    65,     7,
      63,     6,    67,    76,    77,   105,   106,   107,   108,   109,
      68,    69,    78,    79,    84,    87,    88,   118,   151,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    89,    90,
     124,    10,    11,    12,    13,    70,   128,   152,   129,    63,
     170,   153,   164,    21,    22,   154,   155,   166,   174,   169,
     171,   120,   123,    30,    31,    32,   156,   168,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   160,
     162,     0,    37,    38,     0,   163,     0,     0,     0,     0,
     158,   159,    39,     0,   173,     0,     0,     0,     0,     0,
      40,     0,     0,     0,     0,   167,     0,    43,    44,     0,
       0,     0,     0,     0,     0,   175,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,    21,    22,
      23,     0,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     0,     0,     0,    10,    11,
      12,    13,    14,     0,     0,     0,     0,    37,    38,     0,
      21,    22,     0,     0,     0,     0,     0,    39,     0,     0,
      30,    31,    32,     0,     0,    40,    36,     7,    41,    42,
       0,     0,    43,    44,     0,     0,     0,     0,     0,    37,
      38,    15,    16,    17,    18,    19,    20,     0,     0,    39,
       0,     0,     0,     0,     0,     0,     0,    40,     0,     0,
       0,     0,    34,    35,    43,    44,    91,    92,    93,    94,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,     0,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    91,    92,    93,    94,    95,    96,    97,    98,
     110,     0,     0,     0,     0,     0,    99,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,   127,    91,    92,    93,    94,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,     0,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,   149,    91,    92,    93,    94,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,     0,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,     0,     0,     0,     0,     0,   150,    91,    92,
      93,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,   165,
      91,    92,    93,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   157,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,    91,    92,    93,    94,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,     0,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    91,    92,    93,    94,    95,     0,    97,    98,
     125,    15,    16,    17,    18,    19,    20,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    91,    92,
      93,    94,    34,    35,    97,    98,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    91,    92,    93,    94,     0,     0,
      97,    98,    91,    92,    93,    94,     0,     0,    97,    98,
       0,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     102,   103,   104,   105,   106,   107,   108,   109,    91,    92,
      93,    94,     0,     0,    97,    98,     0,    93,    94,     0,
       0,    97,    98,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   103,   104,   105,   106,   107,   108,
     109,    -1,    -1,     0,     0,    97,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    -1,    -1,
     105,   106,   107,   108,   109
};

static const yytype_int16 yycheck[] =
{
       9,    67,    17,    33,    55,    56,    57,    29,     7,     8,
       9,    10,    11,    12,    13,     8,    25,    39,    40,     8,
       7,    43,    44,    40,    41,    42,    43,    44,    45,    28,
      29,    30,     8,    44,    45,    57,    58,    59,    60,     0,
      29,    63,    64,    65,    62,    64,    62,    77,    62,    64,
      67,    63,    62,    29,    62,    53,    54,    55,    56,    57,
      66,    66,     7,     7,     7,    66,    66,    19,    62,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    66,    66,
      29,     3,     4,     5,     6,     7,    67,    66,    68,    67,
     166,    63,    18,    15,    16,    63,   128,    66,    63,    66,
     166,    67,    72,    25,    26,    27,   129,   164,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     152,    -1,    44,    45,    -1,   157,    -1,    -1,    -1,    -1,
     149,   150,    54,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,   164,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,   174,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    44,    45,    -1,
      15,    16,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      25,    26,    27,    -1,    -1,    62,    31,    64,    65,    66,
      -1,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    44,
      45,     8,     9,    10,    11,    12,    13,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    29,    30,    69,    70,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    32,    33,    34,    35,    36,    37,    38,    39,
      66,    -1,    -1,    -1,    -1,    -1,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    63,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    -1,    -1,    63,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    -1,    -1,    63,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,    63,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    32,    33,    34,    35,    36,    -1,    38,    39,
       7,     8,     9,    10,    11,    12,    13,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    32,    33,
      34,    35,    29,    30,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    32,    33,    34,    35,    -1,    -1,
      38,    39,    32,    33,    34,    35,    -1,    -1,    38,    39,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      50,    51,    52,    53,    54,    55,    56,    57,    32,    33,
      34,    35,    -1,    -1,    38,    39,    -1,    34,    35,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    51,    52,    53,    54,    55,    56,
      57,    34,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    72,     7,     0,    62,    63,    64,    73,    74,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    15,    16,    17,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    44,    45,    54,
      62,    65,    66,    69,    70,    73,    75,    76,    79,    80,
      81,    82,    83,    84,    88,    89,    90,    40,    41,    42,
      43,    44,    45,    67,    62,    62,    73,    62,    66,    66,
       7,    90,    76,     8,    29,     8,    29,    62,     7,     7,
      90,    90,    90,    90,     7,    77,    78,    66,    66,    66,
      66,    32,    33,    34,    35,    36,    37,    38,    39,    46,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      66,    90,    90,    90,    90,    90,    90,    90,    19,     7,
      79,    80,    85,    78,    29,     7,    76,    63,    67,    68,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    63,
      63,    62,    66,    63,    63,    90,    77,    47,    73,    73,
      90,    86,    90,    90,    18,    63,    66,    73,    82,    66,
      80,    81,    87,    90,    63,    73
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1464 of yacc.c  */
#line 96 "parser.y"
    {
            ASTNode* prog = mkNode(NODE_PROGRAM);
            prog->children = (yyvsp[(5) - (5)].node)->children;
            astRoot = prog;
            g_syntaxOk = true;
            delete (yyvsp[(2) - (5)].sval);
        ;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 106 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); ;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 110 "parser.y"
    { (yyval.node) = mkNode(NODE_BLOCK); ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 111 "parser.y"
    { (yyvsp[(1) - (2)].node)->children.push_back((yyvsp[(2) - (2)].node)); (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 115 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 116 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 117 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 118 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 119 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 120 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 121 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 122 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 123 "parser.y"
    { (yyval.node) = mkNode(NODE_BREAK); ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 124 "parser.y"
    { (yyval.node) = mkNode(NODE_CONTINUE); ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 125 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 126 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 127 "parser.y"
    { (yyval.node) = mkNode(NODE_BLOCK); ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 131 "parser.y"
    { (yyval.sval) = new string("int"); ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 132 "parser.y"
    { (yyval.sval) = new string("float"); ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 133 "parser.y"
    { (yyval.sval) = new string("double"); ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 134 "parser.y"
    { (yyval.sval) = new string("char"); ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 135 "parser.y"
    { (yyval.sval) = new string("bool"); ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 136 "parser.y"
    { (yyval.sval) = new string("string"); ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 137 "parser.y"
    { (yyval.sval) = new string("long long"); ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 138 "parser.y"
    { (yyval.sval) = new string("long"); ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 139 "parser.y"
    { (yyval.sval) = new string("long"); ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 140 "parser.y"
    { (yyval.sval) = new string("unsigned long long"); ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 141 "parser.y"
    { (yyval.sval) = new string("unsigned long"); ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 142 "parser.y"
    { (yyval.sval) = new string("unsigned int"); ;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 143 "parser.y"
    { (yyval.sval) = new string("unsigned int"); ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 148 "parser.y"
    {
            (yyval.node) = mkNode(NODE_VARDECL);
            (yyval.node)->sval = *(yyvsp[(1) - (1)].sval);
            delete (yyvsp[(1) - (1)].sval);
        ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 154 "parser.y"
    {
            (yyval.node) = mkNode(NODE_VARDECL);
            (yyval.node)->sval = *(yyvsp[(1) - (3)].sval);
            (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
            delete (yyvsp[(1) - (3)].sval);
        ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 164 "parser.y"
    {
            (yyval.nodelist) = new vector<ASTNode*>();
            (yyval.nodelist)->push_back((yyvsp[(1) - (1)].node));
        ;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 169 "parser.y"
    {
            (yyvsp[(1) - (3)].nodelist)->push_back((yyvsp[(3) - (3)].node));
            (yyval.nodelist) = (yyvsp[(1) - (3)].nodelist);
        ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 177 "parser.y"
    {
            for (auto d : *(yyvsp[(2) - (2)].nodelist)) d->datatype = *(yyvsp[(1) - (2)].sval);
            if ((yyvsp[(2) - (2)].nodelist)->size() == 1) {
                (yyval.node) = (*(yyvsp[(2) - (2)].nodelist))[0];
            } else {
                ASTNode* blk = mkNode(NODE_BLOCK);
                for (auto d : *(yyvsp[(2) - (2)].nodelist)) blk->children.push_back(d);
                (yyval.node) = blk;
            }
            delete (yyvsp[(1) - (2)].sval); delete (yyvsp[(2) - (2)].nodelist);
        ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 189 "parser.y"
    {
            for (auto d : *(yyvsp[(3) - (3)].nodelist)) { d->datatype = *(yyvsp[(2) - (3)].sval); d->isConst = true; }
            if ((yyvsp[(3) - (3)].nodelist)->size() == 1) {
                (yyval.node) = (*(yyvsp[(3) - (3)].nodelist))[0];
            } else {
                ASTNode* blk = mkNode(NODE_BLOCK);
                for (auto d : *(yyvsp[(3) - (3)].nodelist)) blk->children.push_back(d);
                (yyval.node) = blk;
            }
            delete (yyvsp[(2) - (3)].sval); delete (yyvsp[(3) - (3)].nodelist);
        ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 204 "parser.y"
    {
            (yyval.node) = mkNode(NODE_ASSIGN);
            (yyval.node)->sval = *(yyvsp[(1) - (3)].sval);
            (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
            delete (yyvsp[(1) - (3)].sval);
        ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 214 "parser.y"
    { (yyval.node) = mkNode(NODE_COMPOUND_ASSIGN); (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->op = "+="; (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); delete (yyvsp[(1) - (3)].sval); ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 216 "parser.y"
    { (yyval.node) = mkNode(NODE_COMPOUND_ASSIGN); (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->op = "-="; (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); delete (yyvsp[(1) - (3)].sval); ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 218 "parser.y"
    { (yyval.node) = mkNode(NODE_COMPOUND_ASSIGN); (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->op = "*="; (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); delete (yyvsp[(1) - (3)].sval); ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 220 "parser.y"
    { (yyval.node) = mkNode(NODE_COMPOUND_ASSIGN); (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->op = "/="; (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); delete (yyvsp[(1) - (3)].sval); ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 225 "parser.y"
    {
            (yyval.node) = mkNode(NODE_IF);
            (yyval.node)->children.push_back((yyvsp[(3) - (5)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (5)].node));
            (yyval.node)->children.push_back(nullptr);
        ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 232 "parser.y"
    {
            (yyval.node) = mkNode(NODE_IF);
            (yyval.node)->children.push_back((yyvsp[(3) - (7)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (7)].node));
            (yyval.node)->children.push_back((yyvsp[(7) - (7)].node));
        ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 239 "parser.y"
    {
            ASTNode* wrapper = mkNode(NODE_BLOCK);
            wrapper->children.push_back((yyvsp[(7) - (7)].node));
            (yyval.node) = mkNode(NODE_IF);
            (yyval.node)->children.push_back((yyvsp[(3) - (7)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (7)].node));
            (yyval.node)->children.push_back(wrapper);
        ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 251 "parser.y"
    {
            (yyval.node) = mkNode(NODE_WHILE);
            (yyval.node)->children.push_back((yyvsp[(3) - (5)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (5)].node));
        ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 260 "parser.y"
    {
            (yyval.node) = mkNode(NODE_DOWHILE);
            (yyval.node)->children.push_back((yyvsp[(2) - (7)].node));  // body
            (yyval.node)->children.push_back((yyvsp[(5) - (7)].node));  // cond
        ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 268 "parser.y"
    { (yyval.node) = nullptr; ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 269 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 270 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 274 "parser.y"
    { (yyval.node) = nullptr; ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 275 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 279 "parser.y"
    { (yyval.node) = nullptr; ;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 280 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 281 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 282 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 287 "parser.y"
    {
            (yyval.node) = mkNode(NODE_FOR);
            (yyval.node)->children.push_back((yyvsp[(3) - (9)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (9)].node));
            (yyval.node)->children.push_back((yyvsp[(7) - (9)].node));
            (yyval.node)->children.push_back((yyvsp[(9) - (9)].node));
        ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 297 "parser.y"
    { (yyval.node) = mkNode(NODE_RETURN); ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 298 "parser.y"
    { (yyval.node) = mkNode(NODE_RETURN); (yyval.node)->children.push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 302 "parser.y"
    { (yyval.node) = mkNode(NODE_NUM_INT); (yyval.node)->ival = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 303 "parser.y"
    { (yyval.node) = mkNode(NODE_NUM_FLOAT); (yyval.node)->fval = (yyvsp[(1) - (1)].fval); ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 304 "parser.y"
    { (yyval.node) = mkNode(NODE_CHAR); (yyval.node)->cval = (yyvsp[(1) - (1)].cval); ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 305 "parser.y"
    { (yyval.node) = mkNode(NODE_STRING); (yyval.node)->sval = *(yyvsp[(1) - (1)].sval); delete (yyvsp[(1) - (1)].sval); ;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 306 "parser.y"
    { (yyval.node) = mkNode(NODE_BOOL); (yyval.node)->ival = 1; ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 307 "parser.y"
    { (yyval.node) = mkNode(NODE_BOOL); (yyval.node)->ival = 0; ;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 308 "parser.y"
    { (yyval.node) = mkNode(NODE_COUT); ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 309 "parser.y"
    { (yyval.node) = mkNode(NODE_CIN); ;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 310 "parser.y"
    { (yyval.node) = mkNode(NODE_ENDL); ;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 311 "parser.y"
    { (yyval.node) = mkNode(NODE_ID); (yyval.node)->sval = *(yyvsp[(1) - (1)].sval); delete (yyvsp[(1) - (1)].sval); ;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 312 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); ;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 313 "parser.y"
    { (yyval.node) = mkNode(NODE_UNOP); (yyval.node)->op = "-"; (yyval.node)->children.push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 314 "parser.y"
    { (yyval.node) = mkNode(NODE_UNOP); (yyval.node)->op = "!"; (yyval.node)->children.push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 315 "parser.y"
    { (yyval.node) = mkNode(NODE_UNOP); (yyval.node)->op = "~"; (yyval.node)->children.push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 316 "parser.y"
    { (yyval.node) = mkNode(NODE_PREINC); (yyval.node)->sval = *(yyvsp[(2) - (2)].sval); delete (yyvsp[(2) - (2)].sval); ;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 317 "parser.y"
    { (yyval.node) = mkNode(NODE_PREDEC); (yyval.node)->sval = *(yyvsp[(2) - (2)].sval); delete (yyvsp[(2) - (2)].sval); ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 318 "parser.y"
    { (yyval.node) = mkNode(NODE_POSTINC); (yyval.node)->sval = *(yyvsp[(1) - (2)].sval); delete (yyvsp[(1) - (2)].sval); ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 319 "parser.y"
    { (yyval.node) = mkNode(NODE_POSTDEC); (yyval.node)->sval = *(yyvsp[(1) - (2)].sval); delete (yyvsp[(1) - (2)].sval); ;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 320 "parser.y"
    { (yyval.node) = mkNode(NODE_BINOP); (yyval.node)->op = "+"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 321 "parser.y"
    { (yyval.node) = mkNode(NODE_BINOP); (yyval.node)->op = "-"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 322 "parser.y"
    { (yyval.node) = mkNode(NODE_BINOP); (yyval.node)->op = "*"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 323 "parser.y"
    { (yyval.node) = mkNode(NODE_BINOP); (yyval.node)->op = "/"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 324 "parser.y"
    { (yyval.node) = mkNode(NODE_BINOP); (yyval.node)->op = "%"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 325 "parser.y"
    { (yyval.node) = mkNode(NODE_BINOP); (yyval.node)->op = "<"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 326 "parser.y"
    { (yyval.node) = mkNode(NODE_BINOP); (yyval.node)->op = ">"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 327 "parser.y"
    { (yyval.node) = mkNode(NODE_BINOP); (yyval.node)->op = "<="; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 328 "parser.y"
    { (yyval.node) = mkNode(NODE_BINOP); (yyval.node)->op = ">="; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 329 "parser.y"
    { (yyval.node) = mkNode(NODE_BINOP); (yyval.node)->op = "=="; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 330 "parser.y"
    { (yyval.node) = mkNode(NODE_BINOP); (yyval.node)->op = "!="; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 331 "parser.y"
    { (yyval.node) = mkNode(NODE_BINOP); (yyval.node)->op = "&&"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 332 "parser.y"
    { (yyval.node) = mkNode(NODE_BINOP); (yyval.node)->op = "||"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 333 "parser.y"
    { (yyval.node) = mkNode(NODE_BINOP); (yyval.node)->op = "&"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 334 "parser.y"
    { (yyval.node) = mkNode(NODE_BINOP); (yyval.node)->op = "|"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 335 "parser.y"
    { (yyval.node) = mkNode(NODE_BINOP); (yyval.node)->op = "^"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 336 "parser.y"
    { (yyval.node) = mkNode(NODE_BINOP); (yyval.node)->op = "<<"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 337 "parser.y"
    { (yyval.node) = mkNode(NODE_BINOP); (yyval.node)->op = ">>"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 338 "parser.y"
    { (yyval.node) = mkNode(NODE_TERNARY); (yyval.node)->children.push_back((yyvsp[(1) - (5)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (5)].node)); (yyval.node)->children.push_back((yyvsp[(5) - (5)].node)); ;}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 340 "parser.y"
    { (yyval.node) = mkNode(NODE_SIZEOF); (yyval.node)->datatype = *(yyvsp[(3) - (4)].sval); delete (yyvsp[(3) - (4)].sval); ;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 342 "parser.y"
    { (yyval.node) = mkNode(NODE_SIZEOF); (yyval.node)->sval = *(yyvsp[(3) - (4)].sval); delete (yyvsp[(3) - (4)].sval); ;}
    break;



/* Line 1464 of yacc.c  */
#line 2435 "parser.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 345 "parser.y"


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

