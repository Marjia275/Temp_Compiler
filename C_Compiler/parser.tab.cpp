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


/* Line 189 of yacc.c  */
#line 94 "parser.tab.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 22 "parser.y"

    #include <string>
    #include <vector>
    #include "ast.h"



/* Line 209 of yacc.c  */
#line 126 "parser.tab.cpp"

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
     SHL = 296,
     SHR = 297,
     PLUSEQ = 298,
     MINUSEQ = 299,
     MULEQ = 300,
     DIVEQ = 301,
     MODEQ = 302,
     INC = 303,
     DEC = 304,
     RSHIFT = 305,
     LSHIFT = 306,
     UMINUS = 307,
     NOTPREC = 308
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 30 "parser.y"

    int ival;
    double fval;
    char cval;
    std::string* sval;
    ASTNode* node;
    std::vector<ASTNode*>* nodelist;



/* Line 214 of yacc.c  */
#line 207 "parser.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 219 "parser.tab.cpp"

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
#define YYLAST   1003

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNRULES -- Number of states.  */
#define YYNSTATES  237

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,     2,     2,     2,    63,    54,     2,
      66,    67,    61,    59,    72,    60,     2,    62,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    70,
      55,    71,    56,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    53,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,    52,    69,    74,     2,     2,     2,
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
      45,    46,    47,    48,    49,    57,    58,    64,    65
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    13,    14,    17,    20,    23,    26,
      29,    31,    33,    35,    37,    39,    42,    45,    48,    51,
      54,    56,    58,    60,    62,    64,    66,    68,    71,    74,
      78,    81,    85,    88,    93,    95,    99,   101,   105,   108,
     112,   116,   120,   124,   128,   132,   136,   142,   150,   158,
     164,   171,   172,   174,   176,   177,   179,   180,   182,   184,
     186,   196,   204,   205,   208,   210,   212,   217,   221,   223,
     225,   231,   232,   236,   242,   243,   248,   250,   253,   255,
     257,   259,   261,   263,   267,   270,   273,   276,   279,   282,
     285,   288,   292,   296,   300,   304,   308,   312,   316,   320,
     324,   328,   332,   336,   340,   344,   348,   352,   356,   360,
     366,   371,   376,   381,   388,   393,   398
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      76,     0,    -1,     9,     7,    66,    67,    77,    -1,    68,
      78,    69,    -1,    -1,    78,    79,    -1,    84,    70,    -1,
      85,    70,    -1,    86,    70,    -1,   105,    70,    -1,    87,
      -1,    88,    -1,    89,    -1,    93,    -1,    94,    -1,    98,
      70,    -1,    99,    70,    -1,   100,    70,    -1,   102,    70,
      -1,   104,    70,    -1,    77,    -1,    70,    -1,     9,    -1,
      10,    -1,    11,    -1,    12,    -1,    13,    -1,    13,     9,
      -1,    13,    13,    -1,    13,    13,     9,    -1,    14,    13,
      -1,    14,    13,    13,    -1,    80,     7,    -1,    80,     7,
      71,   105,    -1,     7,    -1,     7,    71,   105,    -1,    82,
      -1,    83,    72,    82,    -1,    80,    83,    -1,     8,    80,
      83,    -1,     7,    71,   105,    -1,     7,    43,   105,    -1,
       7,    44,   105,    -1,     7,    45,   105,    -1,     7,    46,
     105,    -1,     7,    47,   105,    -1,    15,    66,   105,    67,
      77,    -1,    15,    66,   105,    67,    77,    16,    77,    -1,
      15,    66,   105,    67,    77,    16,    87,    -1,    17,    66,
     105,    67,    77,    -1,    19,    77,    17,    66,   105,    67,
      -1,    -1,    81,    -1,    85,    -1,    -1,   105,    -1,    -1,
      85,    -1,    86,    -1,   105,    -1,    18,    66,    90,    70,
      91,    70,    92,    67,    77,    -1,    20,    66,   105,    67,
      68,    95,    69,    -1,    -1,    95,    97,    -1,     3,    -1,
       5,    -1,    21,    96,    51,    78,    -1,    22,    51,    78,
      -1,    23,    -1,    24,    -1,    25,    66,     6,   101,    67,
      -1,    -1,    72,   105,   101,    -1,    26,    66,     6,   103,
      67,    -1,    -1,    72,    54,     7,   103,    -1,    33,    -1,
      33,   105,    -1,     3,    -1,     4,    -1,     5,    -1,     6,
      -1,     7,    -1,    66,   105,    67,    -1,    60,   105,    -1,
      73,   105,    -1,    74,   105,    -1,    48,     7,    -1,    49,
       7,    -1,     7,    48,    -1,     7,    49,    -1,   105,    59,
     105,    -1,   105,    60,   105,    -1,   105,    61,   105,    -1,
     105,    62,   105,    -1,   105,    63,   105,    -1,   105,    55,
     105,    -1,   105,    56,   105,    -1,   105,    37,   105,    -1,
     105,    38,   105,    -1,   105,    35,   105,    -1,   105,    36,
     105,    -1,   105,    39,   105,    -1,   105,    40,   105,    -1,
     105,    54,   105,    -1,   105,    52,   105,    -1,   105,    53,
     105,    -1,   105,    58,   105,    -1,   105,    57,   105,    -1,
     105,    50,   105,    51,   105,    -1,    27,    66,    80,    67,
      -1,    27,    66,   105,    67,    -1,    28,    66,   105,    67,
      -1,    29,    66,   105,    72,   105,    67,    -1,    30,    66,
     105,    67,    -1,    31,    66,   105,    67,    -1,    32,    66,
     105,    67,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    95,    99,   100,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   137,   143,   153,   155,   160,   161,   166,   172,
     181,   191,   193,   195,   197,   199,   204,   211,   218,   230,
     239,   248,   249,   250,   254,   255,   259,   260,   261,   262,
     266,   277,   287,   288,   292,   293,   297,   303,   311,   315,
     319,   329,   330,   334,   344,   345,   355,   356,   360,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_LIT", "FLOAT_LIT", "CHAR_LIT",
  "STRING_LIT", "IDENTIFIER", "KW_CONST", "KW_INT", "KW_FLOAT",
  "KW_DOUBLE", "KW_CHAR", "KW_LONG", "KW_UNSIGNED", "KW_IF", "KW_ELSE",
  "KW_WHILE", "KW_FOR", "KW_DO", "KW_SWITCH", "KW_CASE", "KW_DEFAULT",
  "KW_BREAK", "KW_CONTINUE", "KW_PRINTF", "KW_SCANF", "KW_SIZEOF",
  "KW_SQRT", "KW_POW", "KW_ABS", "KW_CEIL", "KW_FLOOR", "KW_RETURN",
  "KW_VOID", "EQ", "NE", "LE", "GE", "AND", "OR", "SHL", "SHR", "PLUSEQ",
  "MINUSEQ", "MULEQ", "DIVEQ", "MODEQ", "INC", "DEC", "'?'", "':'", "'|'",
  "'^'", "'&'", "'<'", "'>'", "RSHIFT", "LSHIFT", "'+'", "'-'", "'*'",
  "'/'", "'%'", "UMINUS", "NOTPREC", "'('", "')'", "'{'", "'}'", "';'",
  "'='", "','", "'!'", "'~'", "$accept", "program", "block", "stmt_list",
  "stmt", "type_spec", "vardecl", "declarator", "declarator_list",
  "vardecl_stmt", "assign_stmt", "compound_assign_stmt", "if_stmt",
  "while_stmt", "do_while_stmt", "for_init", "for_cond", "for_update",
  "for_stmt", "switch_stmt", "case_list", "case_value", "case_clause",
  "break_stmt", "continue_stmt", "printf_stmt", "printf_arglist",
  "scanf_stmt", "scanf_arglist", "return_stmt", "expr", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      63,    58,   124,    94,    38,    60,    62,   305,   306,    43,
      45,    42,    47,    37,   307,   308,    40,    41,   123,   125,
      59,    61,    44,    33,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    77,    78,    78,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    84,
      85,    86,    86,    86,    86,    86,    87,    87,    87,    88,
      89,    90,    90,    90,    91,    91,    92,    92,    92,    92,
      93,    94,    95,    95,    96,    96,    97,    97,    98,    99,
     100,   101,   101,   102,   103,   103,   104,   104,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     0,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       2,     3,     2,     4,     1,     3,     1,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     5,     7,     7,     5,
       6,     0,     1,     1,     0,     1,     0,     1,     1,     1,
       9,     7,     0,     2,     1,     1,     4,     3,     1,     1,
       5,     0,     3,     5,     0,     4,     1,     2,     1,     1,
       1,     1,     1,     3,     2,     2,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       4,     4,     4,     6,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     4,     2,     0,
      78,    79,    80,    81,    82,     0,    22,    23,    24,    25,
      26,     0,     0,     0,     0,     0,     0,    68,    69,     0,
       0,     0,     0,     0,     0,     0,     0,    76,     0,     0,
       0,     0,     3,    21,     0,     0,    20,     5,     0,     0,
       0,     0,    10,    11,    12,    13,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
       0,     0,    27,    28,    30,     0,     0,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,    77,
      87,    88,    84,     0,    85,    86,    34,    36,    38,     6,
       7,     8,    15,    16,    17,    18,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     9,    41,    42,    43,
      44,    45,    40,    39,    29,    31,     0,     0,     0,     0,
      52,    53,     0,     0,     0,    71,    74,     0,     0,     0,
       0,     0,     0,     0,    83,     0,     0,   100,   101,    98,
      99,   102,   103,     0,   105,   106,   104,    96,    97,   108,
     107,    91,    92,    93,    94,    95,     0,     0,    32,    54,
       0,     0,     0,     0,     0,     0,   110,   111,   112,     0,
     114,   115,   116,    35,    37,     0,    46,    49,     0,     0,
      55,     0,    62,    71,    70,     0,    73,     0,   109,     0,
      33,    56,    50,     0,    72,    74,   113,    47,    48,    57,
      58,     0,    59,     0,     0,    61,    63,    75,     0,    64,
      65,     0,     4,    60,     4,    67,    66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    46,     9,    47,    48,   140,    97,    98,    49,
      50,    51,    52,    53,    54,   142,   199,   221,    55,    56,
     213,   231,   226,    57,    58,    59,   183,    60,   185,    61,
      62
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -191
static const yytype_int16 yypact[] =
{
      -2,    19,    37,   -28,  -191,   -26,   -23,  -191,  -191,   181,
    -191,  -191,  -191,  -191,    47,     3,  -191,  -191,  -191,  -191,
      23,    44,     0,     1,     2,   -23,    31,  -191,  -191,    32,
      33,    34,    35,    36,    42,    49,    50,   301,    62,   110,
     301,   301,  -191,  -191,   301,   301,  -191,  -191,   113,    51,
      52,    53,  -191,  -191,  -191,  -191,  -191,    54,    55,    56,
      63,    64,   401,   301,   301,   301,   301,   301,  -191,  -191,
     301,   113,  -191,   126,   124,   301,   301,    11,   121,   301,
     133,   134,   100,   301,   301,   301,   301,   301,    15,   822,
    -191,  -191,  -191,   430,  -191,  -191,    70,  -191,    73,  -191,
    -191,  -191,  -191,  -191,  -191,  -191,  -191,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,  -191,   822,   822,   822,
     822,   822,   822,    73,  -191,  -191,   463,   496,    71,   140,
    -191,  -191,    80,    85,   529,    82,    83,    89,   562,   595,
     343,   628,   661,   694,  -191,   301,   113,   237,   237,   940,
     940,   863,   851,   793,   892,   902,   931,   940,   940,    -7,
      -7,    -1,    -1,  -191,  -191,  -191,   -23,   -23,    81,   301,
     301,    90,   301,    94,   103,    96,  -191,  -191,  -191,   301,
    -191,  -191,  -191,   822,  -191,   301,   148,  -191,   301,    95,
     822,   727,  -191,   372,  -191,   160,  -191,   760,   822,    -9,
     822,   311,  -191,   -11,  -191,    83,  -191,  -191,  -191,  -191,
    -191,   101,   822,    30,   118,  -191,  -191,  -191,   -23,  -191,
    -191,   125,  -191,  -191,  -191,   253,   253
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -191,  -191,    -6,  -190,  -191,   -12,  -191,    16,   106,  -191,
     -75,   -33,   -30,  -191,  -191,  -191,  -191,  -191,  -191,  -191,
    -191,  -191,  -191,  -191,  -191,  -191,   -22,  -191,   -35,  -191,
     -36
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
       8,    89,   141,    71,    92,    93,    22,     1,    94,    95,
     223,   224,    16,    17,    18,    19,    20,    21,   138,    78,
      16,    17,    18,    19,    20,    21,     3,   127,   128,   129,
     130,   131,    72,   229,   132,   230,    73,     4,     5,   136,
     137,     6,   235,   144,   236,     7,   148,   149,   150,   151,
     152,   153,   121,   122,   123,   124,   125,    74,   225,     7,
     123,   124,   125,    68,    69,   139,    75,    76,    77,    90,
     147,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
      63,    64,    65,    66,    67,    68,    69,    79,    80,    81,
      82,    83,    84,    10,    11,    12,    13,    88,    85,    16,
      17,    18,    19,    20,    21,    86,    87,    91,    70,   193,
      96,    99,   100,   101,   102,   103,   104,    31,    32,    33,
      34,    35,    36,   105,   106,   134,   219,   135,   143,   145,
     146,   155,    70,   200,   201,   156,   203,   178,    38,    39,
     179,   180,   198,   207,   182,   184,   186,   205,   202,   208,
      40,   204,   210,   206,   209,   211,    41,   215,   228,   232,
     196,   197,   194,    44,    45,   222,   234,   133,   220,   218,
     227,   214,     0,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,     0,   217,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,     0,     0,     0,     0,     0,
       0,     0,   233,     0,     0,     0,     0,     0,     0,    38,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    40,     0,     0,     0,     0,     0,    41,     0,     7,
      42,    43,     0,     0,    44,    45,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     0,
      23,    24,    25,    26,   109,   110,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,     0,     0,     0,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    38,    39,     0,    10,    11,    12,    13,    88,     0,
       0,     0,     0,    40,    10,    11,    12,    13,    14,    41,
       0,     7,     0,    43,     0,     0,    44,    45,    31,    32,
      33,    34,    35,    36,     0,     0,     0,     0,    31,    32,
      33,    34,    35,    36,     0,     0,     0,     0,     0,    38,
      39,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      39,    40,     0,     0,     0,     0,     0,    41,     0,     0,
       0,    40,     0,     0,    44,    45,     0,    41,   107,   108,
     109,   110,   111,   112,    44,    45,     0,     0,     0,     0,
       0,     0,     0,   113,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   107,   108,   109,
     110,   111,   112,     0,     0,   189,     0,     0,     0,     0,
       0,     0,   113,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   107,   108,   109,   110,
     111,   112,     0,     0,   182,     0,     0,     0,     0,     0,
       0,   113,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   107,   108,   109,   110,   111,
     112,   126,     0,     0,     0,     0,     0,     0,     0,     0,
     113,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,     0,     0,     0,   154,   107,   108,
     109,   110,   111,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,     0,     0,     0,
     176,   107,   108,   109,   110,   111,   112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
       0,     0,     0,   177,   107,   108,   109,   110,   111,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   113,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,     0,     0,   181,   107,   108,   109,
     110,   111,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,     0,     0,     0,   187,
     107,   108,   109,   110,   111,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,     0,
       0,     0,   188,   107,   108,   109,   110,   111,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,     0,     0,     0,   190,   107,   108,   109,   110,
     111,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,     0,     0,     0,   191,   107,
     108,   109,   110,   111,   112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,     0,     0,
       0,   192,   107,   108,   109,   110,   111,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   113,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,     0,     0,     0,   212,   107,   108,   109,   110,   111,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,     0,     0,     0,   216,   107,   108,
     109,   110,   111,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,   195,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   107,   108,   109,
     110,   111,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   107,   108,   109,   110,
     111,     0,     0,     0,     0,     0,     0,     0,   107,   108,
     109,   110,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   107,   108,   109,
     110,     0,     0,     0,     0,     0,     0,   107,   108,   109,
     110,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   107,   108,   109,   110,
       0,     0,     0,     0,     0,     0,     0,    -1,    -1,     0,
       0,     0,     0,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,   119,   120,   121,
     122,   123,   124,   125
};

static const yytype_int16 yycheck[] =
{
       6,    37,    77,    15,    40,    41,    15,     9,    44,    45,
      21,    22,     9,    10,    11,    12,    13,    14,     7,    25,
       9,    10,    11,    12,    13,    14,     7,    63,    64,    65,
      66,    67,     9,     3,    70,     5,    13,     0,    66,    75,
      76,    67,   232,    79,   234,    68,    82,    83,    84,    85,
      86,    87,    59,    60,    61,    62,    63,    13,    69,    68,
      61,    62,    63,    48,    49,    77,    66,    66,    66,     7,
      82,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      43,    44,    45,    46,    47,    48,    49,    66,    66,    66,
      66,    66,    66,     3,     4,     5,     6,     7,    66,     9,
      10,    11,    12,    13,    14,    66,    66,     7,    71,   155,
       7,    70,    70,    70,    70,    70,    70,    27,    28,    29,
      30,    31,    32,    70,    70,     9,   211,    13,    17,     6,
       6,    71,    71,   179,   180,    72,   182,     7,    48,    49,
      70,    66,    71,   189,    72,    72,    67,    54,    68,   195,
      60,    67,   198,    67,    16,    70,    66,     7,    67,    51,
     176,   177,   156,    73,    74,   211,    51,    71,   211,   209,
     215,   203,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    -1,   209,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    68,
      69,    70,    -1,    -1,    73,    74,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    19,    20,    37,    38,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    48,    49,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    60,     3,     4,     5,     6,     7,    66,
      -1,    68,    -1,    70,    -1,    -1,    73,    74,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,
      -1,    60,    -1,    -1,    73,    74,    -1,    66,    35,    36,
      37,    38,    39,    40,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    35,    36,    37,
      38,    39,    40,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    35,    36,    37,    38,
      39,    40,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    35,    36,    37,    38,    39,
      40,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    67,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      67,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    67,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    67,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    67,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    67,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    67,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    67,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    67,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    55,    56,    57,    58,    59,
      60,    61,    62,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    76,     7,     0,    66,    67,    68,    77,    78,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    17,    18,    19,    20,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    48,    49,
      60,    66,    69,    70,    73,    74,    77,    79,    80,    84,
      85,    86,    87,    88,    89,    93,    94,    98,    99,   100,
     102,   104,   105,    43,    44,    45,    46,    47,    48,    49,
      71,    80,     9,    13,    13,    66,    66,    66,    77,    66,
      66,    66,    66,    66,    66,    66,    66,    66,     7,   105,
       7,     7,   105,   105,   105,   105,     7,    82,    83,    70,
      70,    70,    70,    70,    70,    70,    70,    35,    36,    37,
      38,    39,    40,    50,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    70,   105,   105,   105,
     105,   105,   105,    83,     9,    13,   105,   105,     7,    80,
      81,    85,    90,    17,   105,     6,     6,    80,   105,   105,
     105,   105,   105,   105,    67,    71,    72,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,    67,    67,     7,    70,
      66,    67,    72,   101,    72,   103,    67,    67,    67,    72,
      67,    67,    67,   105,    82,    51,    77,    77,    71,    91,
     105,   105,    68,   105,    67,    54,    67,   105,   105,    16,
     105,    70,    67,    95,   101,     7,    67,    77,    87,    85,
      86,    92,   105,    21,    22,    69,    97,   103,    67,     3,
       5,    96,    51,    77,    51,    78,    78
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
#line 85 "parser.y"
    {
            ASTNode* prog = new ASTNode(NODE_PROGRAM);
            prog->children = (yyvsp[(5) - (5)].node)->children;
            astRoot = prog;
            g_syntaxOk = true;
            delete (yyvsp[(2) - (5)].sval);
        ;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 95 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); ;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 99 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BLOCK); ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 100 "parser.y"
    { (yyvsp[(1) - (2)].node)->children.push_back((yyvsp[(2) - (2)].node)); (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 104 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 105 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 106 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 107 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 108 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 109 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 110 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 111 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 112 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 113 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 114 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 115 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 116 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 117 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 118 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 119 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BLOCK); ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 123 "parser.y"
    { (yyval.sval) = new string("int"); ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 124 "parser.y"
    { (yyval.sval) = new string("float"); ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 125 "parser.y"
    { (yyval.sval) = new string("double"); ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 126 "parser.y"
    { (yyval.sval) = new string("char"); ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 127 "parser.y"
    { (yyval.sval) = new string("long"); ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 128 "parser.y"
    { (yyval.sval) = new string("long"); ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 129 "parser.y"
    { (yyval.sval) = new string("long"); ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 130 "parser.y"
    { (yyval.sval) = new string("long"); ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 131 "parser.y"
    { (yyval.sval) = new string("long"); ;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 132 "parser.y"
    { (yyval.sval) = new string("long"); ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 138 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_VARDECL);
            (yyval.node)->datatype = *(yyvsp[(1) - (2)].sval); (yyval.node)->sval = *(yyvsp[(2) - (2)].sval); (yyval.node)->line = yylineno;
            delete (yyvsp[(1) - (2)].sval); delete (yyvsp[(2) - (2)].sval);
        ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 144 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_VARDECL);
            (yyval.node)->datatype = *(yyvsp[(1) - (4)].sval); (yyval.node)->sval = *(yyvsp[(2) - (4)].sval); (yyval.node)->line = yylineno;
            (yyval.node)->children.push_back((yyvsp[(4) - (4)].node));
            delete (yyvsp[(1) - (4)].sval); delete (yyvsp[(2) - (4)].sval);
        ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 154 "parser.y"
    { (yyval.node) = new ASTNode(NODE_VARDECL); (yyval.node)->sval = *(yyvsp[(1) - (1)].sval); (yyval.node)->line = yylineno; delete (yyvsp[(1) - (1)].sval); ;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 156 "parser.y"
    { (yyval.node) = new ASTNode(NODE_VARDECL); (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->line = yylineno; (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); delete (yyvsp[(1) - (3)].sval); ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 160 "parser.y"
    { (yyval.nodelist) = new std::vector<ASTNode*>(); (yyval.nodelist)->push_back((yyvsp[(1) - (1)].node)); ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 161 "parser.y"
    { (yyvsp[(1) - (3)].nodelist)->push_back((yyvsp[(3) - (3)].node)); (yyval.nodelist) = (yyvsp[(1) - (3)].nodelist); ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 167 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_BLOCK);
            for (auto d : *(yyvsp[(2) - (2)].nodelist)) { d->datatype = *(yyvsp[(1) - (2)].sval); (yyval.node)->children.push_back(d); }
            delete (yyvsp[(1) - (2)].sval); delete (yyvsp[(2) - (2)].nodelist);
        ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 173 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_BLOCK);
            for (auto d : *(yyvsp[(3) - (3)].nodelist)) { d->datatype = *(yyvsp[(2) - (3)].sval); d->isConst = true; (yyval.node)->children.push_back(d); }
            delete (yyvsp[(2) - (3)].sval); delete (yyvsp[(3) - (3)].nodelist);
        ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 182 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_ASSIGN);
            (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->line = yylineno;
            (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
            delete (yyvsp[(1) - (3)].sval);
        ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 192 "parser.y"
    { (yyval.node) = new ASTNode(NODE_COMPOUND_ASSIGN); (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->op = "+="; (yyval.node)->line = yylineno; (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); delete (yyvsp[(1) - (3)].sval); ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 194 "parser.y"
    { (yyval.node) = new ASTNode(NODE_COMPOUND_ASSIGN); (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->op = "-="; (yyval.node)->line = yylineno; (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); delete (yyvsp[(1) - (3)].sval); ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 196 "parser.y"
    { (yyval.node) = new ASTNode(NODE_COMPOUND_ASSIGN); (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->op = "*="; (yyval.node)->line = yylineno; (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); delete (yyvsp[(1) - (3)].sval); ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 198 "parser.y"
    { (yyval.node) = new ASTNode(NODE_COMPOUND_ASSIGN); (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->op = "/="; (yyval.node)->line = yylineno; (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); delete (yyvsp[(1) - (3)].sval); ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 200 "parser.y"
    { (yyval.node) = new ASTNode(NODE_COMPOUND_ASSIGN); (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->op = "%="; (yyval.node)->line = yylineno; (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); delete (yyvsp[(1) - (3)].sval); ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 205 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_IF); (yyval.node)->line = yylineno;
            (yyval.node)->children.push_back((yyvsp[(3) - (5)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (5)].node));
            (yyval.node)->children.push_back(nullptr);
        ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 212 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_IF); (yyval.node)->line = yylineno;
            (yyval.node)->children.push_back((yyvsp[(3) - (7)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (7)].node));
            (yyval.node)->children.push_back((yyvsp[(7) - (7)].node));
        ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 219 "parser.y"
    {
            ASTNode* wrapper = new ASTNode(NODE_BLOCK);
            wrapper->children.push_back((yyvsp[(7) - (7)].node));
            (yyval.node) = new ASTNode(NODE_IF); (yyval.node)->line = yylineno;
            (yyval.node)->children.push_back((yyvsp[(3) - (7)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (7)].node));
            (yyval.node)->children.push_back(wrapper);
        ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 231 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_WHILE); (yyval.node)->line = yylineno;
            (yyval.node)->children.push_back((yyvsp[(3) - (5)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (5)].node));
        ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 240 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_DOWHILE); (yyval.node)->line = yylineno;
            (yyval.node)->children.push_back((yyvsp[(2) - (6)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (6)].node));
        ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 248 "parser.y"
    { (yyval.node) = nullptr; ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 249 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 250 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 254 "parser.y"
    { (yyval.node) = nullptr; ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 255 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 259 "parser.y"
    { (yyval.node) = nullptr; ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 260 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 261 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 262 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 267 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_FOR); (yyval.node)->line = yylineno;
            (yyval.node)->children.push_back((yyvsp[(3) - (9)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (9)].node));
            (yyval.node)->children.push_back((yyvsp[(7) - (9)].node));
            (yyval.node)->children.push_back((yyvsp[(9) - (9)].node));
        ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 278 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_SWITCH); (yyval.node)->line = yylineno;
            (yyval.node)->children.push_back((yyvsp[(3) - (7)].node));
            for (auto c : *(yyvsp[(6) - (7)].nodelist)) (yyval.node)->children.push_back(c);
            delete (yyvsp[(6) - (7)].nodelist);
        ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 287 "parser.y"
    { (yyval.nodelist) = new std::vector<ASTNode*>(); ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 288 "parser.y"
    { (yyvsp[(1) - (2)].nodelist)->push_back((yyvsp[(2) - (2)].node)); (yyval.nodelist) = (yyvsp[(1) - (2)].nodelist); ;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 292 "parser.y"
    { (yyval.ival) = (int)strtoll((yyvsp[(1) - (1)].sval)->c_str(), nullptr, 10); delete (yyvsp[(1) - (1)].sval); ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 293 "parser.y"
    { (yyval.ival) = (int)(yyvsp[(1) - (1)].cval); ;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 298 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_CASE); (yyval.node)->line = yylineno;
            (yyval.node)->ival = (yyvsp[(2) - (4)].ival);
            (yyval.node)->children.push_back((yyvsp[(4) - (4)].node));
        ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 304 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_DEFAULT); (yyval.node)->line = yylineno;
            (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
        ;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 311 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BREAK); (yyval.node)->line = yylineno; ;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 315 "parser.y"
    { (yyval.node) = new ASTNode(NODE_CONTINUE); (yyval.node)->line = yylineno; ;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 320 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_PRINTF); (yyval.node)->line = yylineno;
            (yyval.node)->sval = *(yyvsp[(3) - (5)].sval);
            (yyval.node)->children = *(yyvsp[(4) - (5)].nodelist);
            delete (yyvsp[(3) - (5)].sval); delete (yyvsp[(4) - (5)].nodelist);
        ;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 329 "parser.y"
    { (yyval.nodelist) = new std::vector<ASTNode*>(); ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 330 "parser.y"
    { (yyvsp[(3) - (3)].nodelist)->insert((yyvsp[(3) - (3)].nodelist)->begin(), (yyvsp[(2) - (3)].node)); (yyval.nodelist) = (yyvsp[(3) - (3)].nodelist); ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 335 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_SCANF); (yyval.node)->line = yylineno;
            (yyval.node)->sval = *(yyvsp[(3) - (5)].sval);
            (yyval.node)->children = *(yyvsp[(4) - (5)].nodelist);
            delete (yyvsp[(3) - (5)].sval); delete (yyvsp[(4) - (5)].nodelist);
        ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 344 "parser.y"
    { (yyval.nodelist) = new std::vector<ASTNode*>(); ;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 346 "parser.y"
    {
            ASTNode* idn = new ASTNode(NODE_ID);
            idn->sval = *(yyvsp[(3) - (4)].sval); delete (yyvsp[(3) - (4)].sval);
            (yyvsp[(4) - (4)].nodelist)->insert((yyvsp[(4) - (4)].nodelist)->begin(), idn);
            (yyval.nodelist) = (yyvsp[(4) - (4)].nodelist);
        ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 355 "parser.y"
    { (yyval.node) = new ASTNode(NODE_RETURN); (yyval.node)->line = yylineno; ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 356 "parser.y"
    { (yyval.node) = new ASTNode(NODE_RETURN); (yyval.node)->line = yylineno; (yyval.node)->children.push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 360 "parser.y"
    {
                              long long v = strtoll((yyvsp[(1) - (1)].sval)->c_str(), nullptr, 10);
                              delete (yyvsp[(1) - (1)].sval);
                              (yyval.node) = new ASTNode(NODE_NUM_INT);
                              if (v >= -2147483648LL && v <= 2147483647LL) { (yyval.node)->ival = (int)v; }
                              else { (yyval.node)->datatype = "long"; (yyval.node)->llit = v; }
                            ;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 367 "parser.y"
    { (yyval.node) = new ASTNode(NODE_NUM_FLOAT); (yyval.node)->fval = (yyvsp[(1) - (1)].fval); ;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 368 "parser.y"
    { (yyval.node) = new ASTNode(NODE_CHAR); (yyval.node)->cval = (yyvsp[(1) - (1)].cval); ;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 369 "parser.y"
    { (yyval.node) = new ASTNode(NODE_STRING); (yyval.node)->sval = *(yyvsp[(1) - (1)].sval); delete (yyvsp[(1) - (1)].sval); ;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 370 "parser.y"
    { (yyval.node) = new ASTNode(NODE_ID); (yyval.node)->sval = *(yyvsp[(1) - (1)].sval); delete (yyvsp[(1) - (1)].sval); ;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 371 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); ;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 372 "parser.y"
    { (yyval.node) = new ASTNode(NODE_UNOP); (yyval.node)->op = "-"; (yyval.node)->children.push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 373 "parser.y"
    { (yyval.node) = new ASTNode(NODE_UNOP); (yyval.node)->op = "!"; (yyval.node)->children.push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 374 "parser.y"
    { (yyval.node) = new ASTNode(NODE_UNOP); (yyval.node)->op = "~"; (yyval.node)->children.push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 375 "parser.y"
    { (yyval.node) = new ASTNode(NODE_PREINC); (yyval.node)->sval = *(yyvsp[(2) - (2)].sval); delete (yyvsp[(2) - (2)].sval); ;}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 376 "parser.y"
    { (yyval.node) = new ASTNode(NODE_PREDEC); (yyval.node)->sval = *(yyvsp[(2) - (2)].sval); delete (yyvsp[(2) - (2)].sval); ;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 377 "parser.y"
    { (yyval.node) = new ASTNode(NODE_POSTINC); (yyval.node)->sval = *(yyvsp[(1) - (2)].sval); delete (yyvsp[(1) - (2)].sval); ;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 378 "parser.y"
    { (yyval.node) = new ASTNode(NODE_POSTDEC); (yyval.node)->sval = *(yyvsp[(1) - (2)].sval); delete (yyvsp[(1) - (2)].sval); ;}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 379 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "+"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 380 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "-"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 381 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "*"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 382 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "/"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 383 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "%"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 384 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "<"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 385 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = ">"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 386 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "<="; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 387 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = ">="; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 388 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "=="; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 389 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "!="; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 390 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "&&"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 391 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "||"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 392 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "&"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 393 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "|"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 394 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "^"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 395 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "<<"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 396 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = ">>"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 397 "parser.y"
    { (yyval.node) = new ASTNode(NODE_TERNARY); (yyval.node)->children.push_back((yyvsp[(1) - (5)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (5)].node)); (yyval.node)->children.push_back((yyvsp[(5) - (5)].node)); ;}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 398 "parser.y"
    { (yyval.node) = new ASTNode(NODE_SIZEOF); (yyval.node)->datatype = *(yyvsp[(3) - (4)].sval); delete (yyvsp[(3) - (4)].sval); ;}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 399 "parser.y"
    { (yyval.node) = new ASTNode(NODE_SIZEOF); (yyval.node)->children.push_back((yyvsp[(3) - (4)].node)); ;}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 400 "parser.y"
    { (yyval.node) = new ASTNode(NODE_CALL); (yyval.node)->sval = "sqrt"; (yyval.node)->children.push_back((yyvsp[(3) - (4)].node)); ;}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 401 "parser.y"
    { (yyval.node) = new ASTNode(NODE_CALL); (yyval.node)->sval = "pow"; (yyval.node)->children.push_back((yyvsp[(3) - (6)].node)); (yyval.node)->children.push_back((yyvsp[(5) - (6)].node)); ;}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 402 "parser.y"
    { (yyval.node) = new ASTNode(NODE_CALL); (yyval.node)->sval = "abs"; (yyval.node)->children.push_back((yyvsp[(3) - (4)].node)); ;}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 403 "parser.y"
    { (yyval.node) = new ASTNode(NODE_CALL); (yyval.node)->sval = "ceil"; (yyval.node)->children.push_back((yyvsp[(3) - (4)].node)); ;}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 404 "parser.y"
    { (yyval.node) = new ASTNode(NODE_CALL); (yyval.node)->sval = "floor"; (yyval.node)->children.push_back((yyvsp[(3) - (4)].node)); ;}
    break;



/* Line 1464 of yacc.c  */
#line 2688 "parser.tab.cpp"
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
#line 407 "parser.y"


void yyerror(const char* s) {
    cerr << "Syntax Error:" << endl;
    cerr << "Line " << yylineno << ":" << endl;
    cerr << s;
    if (yytext && yytext[0] != '\0') cerr << " (near token '" << yytext << "')";
    cerr << "." << endl;
    g_syntaxOk = false;
}

