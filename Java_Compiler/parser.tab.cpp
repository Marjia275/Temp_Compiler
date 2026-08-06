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
void yyerror(const char* s);

// Defined in main.cpp - filled in once parsing succeeds.
extern ASTNode* astRoot;
extern bool g_syntaxOk;


/* Line 189 of yacc.c  */
#line 93 "parser.tab.cpp"

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
#line 21 "parser.y"

    #include <string>
    #include <vector>
    #include "ast.h"



/* Line 209 of yacc.c  */
#line 125 "parser.tab.cpp"

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
     KW_PUBLIC = 263,
     KW_CLASS = 264,
     KW_STATIC = 265,
     KW_VOID = 266,
     KW_MAIN = 267,
     KW_INT = 268,
     KW_FLOAT = 269,
     KW_DOUBLE = 270,
     KW_CHAR = 271,
     KW_BOOLEAN = 272,
     KW_STRING = 273,
     KW_SCANNER = 274,
     KW_TRUE = 275,
     KW_FALSE = 276,
     KW_IF = 277,
     KW_ELSE = 278,
     KW_WHILE = 279,
     KW_DO = 280,
     KW_FOR = 281,
     KW_BREAK = 282,
     KW_CONTINUE = 283,
     KW_RETURN = 284,
     KW_SYSOUT_PRINT = 285,
     KW_SYSOUT_PRINTLN = 286,
     KW_SYSTEM_IN = 287,
     KW_IMPORT = 288,
     KW_NEW = 289,
     KW_FINAL = 290,
     KW_SWITCH = 291,
     KW_CASE = 292,
     KW_DEFAULT = 293,
     EQ = 294,
     NE = 295,
     LE = 296,
     GE = 297,
     AND = 298,
     OR = 299,
     SHL = 300,
     SHR = 301,
     PLUSEQ = 302,
     MINUSEQ = 303,
     MULEQ = 304,
     DIVEQ = 305,
     MODEQ = 306,
     INC = 307,
     DEC = 308,
     RSHIFT = 309,
     LSHIFT = 310,
     UMINUS = 311,
     NOTPREC = 312,
     BITNOT = 313
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 27 "parser.y"

    int ival;
    double fval;
    char cval;
    std::string* sval;
    ASTNode* node;
    std::vector<ASTNode*>* nodelist;



/* Line 214 of yacc.c  */
#line 211 "parser.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 223 "parser.tab.cpp"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   766

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNRULES -- Number of states.  */
#define YYNSTATES  236

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    81,     2,     2,     2,    67,    58,     2,
      72,    75,    65,    63,    80,    64,    78,    66,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,    77,
      59,    79,    60,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    73,     2,    74,    57,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,    56,    76,    82,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    61,
      62,    68,    69,    70
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    21,    22,    25,    29,    31,    35,    39,
      43,    47,    48,    51,    54,    57,    60,    63,    65,    67,
      70,    72,    74,    77,    80,    83,    85,    87,    89,    91,
      93,    95,    97,    99,   101,   103,   106,   111,   115,   121,
     125,   129,   133,   137,   141,   145,   151,   159,   167,   173,
     174,   176,   178,   179,   181,   182,   184,   186,   188,   198,
     205,   213,   214,   217,   222,   227,   232,   236,   237,   240,
     242,   245,   250,   256,   262,   264,   266,   268,   270,   272,
     274,   276,   278,   280,   284,   286,   293,   299,   300,   302,
     304,   308,   310,   313,   316,   319,   322,   325,   328,   331,
     335,   339,   343,   347,   351,   355,   359,   363,   367,   371,
     375,   379,   383,   387,   391,   395,   399,   403
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      84,     0,    -1,    85,     8,     9,     7,    71,     8,    10,
      11,    12,    72,    18,    73,    74,     7,    75,    88,    76,
      -1,    -1,    85,    86,    -1,    33,    87,    77,    -1,     7,
      -1,    87,    78,     7,    -1,    87,    78,    19,    -1,    87,
      78,    65,    -1,    71,    89,    76,    -1,    -1,    89,    90,
      -1,    92,    77,    -1,    93,    77,    -1,    94,    77,    -1,
     113,    77,    -1,    95,    -1,    96,    -1,   101,    77,    -1,
     100,    -1,   102,    -1,    27,    77,    -1,    28,    77,    -1,
     106,    77,    -1,   107,    -1,    88,    -1,    77,    -1,    13,
      -1,    14,    -1,    15,    -1,    16,    -1,    17,    -1,    18,
      -1,    19,    -1,    91,     7,    -1,    91,     7,    79,   113,
      -1,    35,    91,     7,    -1,    35,    91,     7,    79,   113,
      -1,     7,    79,   113,    -1,     7,    47,   113,    -1,     7,
      48,   113,    -1,     7,    49,   113,    -1,     7,    50,   113,
      -1,     7,    51,   113,    -1,    22,    72,   113,    75,    88,
      -1,    22,    72,   113,    75,    88,    23,    88,    -1,    22,
      72,   113,    75,    88,    23,    95,    -1,    24,    72,   113,
      75,    88,    -1,    -1,    92,    -1,    93,    -1,    -1,   113,
      -1,    -1,    93,    -1,    94,    -1,   113,    -1,    26,    72,
      97,    77,    98,    77,    99,    75,    88,    -1,    25,    88,
      24,    72,   113,    75,    -1,    36,    72,   113,    75,    71,
     103,    76,    -1,    -1,   103,   104,    -1,    37,     3,    55,
     105,    -1,    37,     5,    55,   105,    -1,    37,     6,    55,
     105,    -1,    38,    55,   105,    -1,    -1,   105,    90,    -1,
      29,    -1,    29,   113,    -1,    31,    72,    75,    77,    -1,
      31,    72,   113,    75,    77,    -1,    30,    72,   113,    75,
      77,    -1,     3,    -1,     4,    -1,     5,    -1,     6,    -1,
      20,    -1,    21,    -1,    32,    -1,     7,    -1,   110,    -1,
      72,   113,    75,    -1,   108,    -1,   109,    78,     7,    72,
     111,    75,    -1,    34,    19,    72,   111,    75,    -1,    -1,
     112,    -1,   113,    -1,   112,    80,   113,    -1,   109,    -1,
      64,   113,    -1,    81,   113,    -1,    82,   113,    -1,    52,
       7,    -1,    53,     7,    -1,     7,    52,    -1,     7,    53,
      -1,   113,    63,   113,    -1,   113,    64,   113,    -1,   113,
      65,   113,    -1,   113,    66,   113,    -1,   113,    67,   113,
      -1,   113,    59,   113,    -1,   113,    60,   113,    -1,   113,
      41,   113,    -1,   113,    42,   113,    -1,   113,    39,   113,
      -1,   113,    40,   113,    -1,   113,    43,   113,    -1,   113,
      44,   113,    -1,   113,    58,   113,    -1,   113,    56,   113,
      -1,   113,    57,   113,    -1,   113,    62,   113,    -1,   113,
      61,   113,    -1,   113,    54,   113,    55,   113,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,   104,   105,   114,   119,   120,   122,   124,
     129,   133,   134,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   156,   157,
     158,   159,   160,   161,   162,   166,   172,   179,   185,   195,
     205,   207,   209,   211,   213,   218,   225,   232,   244,   253,
     254,   255,   259,   260,   264,   265,   266,   267,   271,   282,
     291,   300,   301,   310,   316,   322,   328,   336,   337,   346,
     347,   351,   353,   355,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   374,   375,   385,   393,   394,   398,
     399,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_LIT", "FLOAT_LIT", "CHAR_LIT",
  "STRING_LIT", "IDENTIFIER", "KW_PUBLIC", "KW_CLASS", "KW_STATIC",
  "KW_VOID", "KW_MAIN", "KW_INT", "KW_FLOAT", "KW_DOUBLE", "KW_CHAR",
  "KW_BOOLEAN", "KW_STRING", "KW_SCANNER", "KW_TRUE", "KW_FALSE", "KW_IF",
  "KW_ELSE", "KW_WHILE", "KW_DO", "KW_FOR", "KW_BREAK", "KW_CONTINUE",
  "KW_RETURN", "KW_SYSOUT_PRINT", "KW_SYSOUT_PRINTLN", "KW_SYSTEM_IN",
  "KW_IMPORT", "KW_NEW", "KW_FINAL", "KW_SWITCH", "KW_CASE", "KW_DEFAULT",
  "EQ", "NE", "LE", "GE", "AND", "OR", "SHL", "SHR", "PLUSEQ", "MINUSEQ",
  "MULEQ", "DIVEQ", "MODEQ", "INC", "DEC", "'?'", "':'", "'|'", "'^'",
  "'&'", "'<'", "'>'", "RSHIFT", "LSHIFT", "'+'", "'-'", "'*'", "'/'",
  "'%'", "UMINUS", "NOTPREC", "BITNOT", "'{'", "'('", "'['", "']'", "')'",
  "'}'", "';'", "'.'", "'='", "','", "'!'", "'~'", "$accept", "program",
  "import_list", "import_decl", "dotted_name", "block", "stmt_list",
  "stmt", "type_spec", "vardecl", "assign_stmt", "compound_assign_stmt",
  "if_stmt", "while_stmt", "for_init", "for_cond", "for_update",
  "for_stmt", "do_while_stmt", "switch_stmt", "case_clauses",
  "case_clause", "case_body", "return_stmt", "print_stmt", "primary_expr",
  "postfix_expr", "new_expr", "arg_list_opt", "arg_list", "expr", 0
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
     305,   306,   307,   308,    63,    58,   124,    94,    38,    60,
      62,   309,   310,    43,    45,    42,    47,    37,   311,   312,
     313,   123,    40,    91,    93,    41,   125,    59,    46,    61,
      44,    33,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    85,    85,    86,    87,    87,    87,    87,
      88,    89,    89,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    91,    91,
      91,    91,    91,    91,    91,    92,    92,    92,    92,    93,
      94,    94,    94,    94,    94,    95,    95,    95,    96,    97,
      97,    97,    98,    98,    99,    99,    99,    99,   100,   101,
     102,   103,   103,   104,   104,   104,   104,   105,   105,   106,
     106,   107,   107,   107,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   109,   109,   110,   111,   111,   112,
     112,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    17,     0,     2,     3,     1,     3,     3,     3,
       3,     0,     2,     2,     2,     2,     2,     1,     1,     2,
       1,     1,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     3,     5,     3,
       3,     3,     3,     3,     3,     5,     7,     7,     5,     0,
       1,     1,     0,     1,     0,     1,     1,     1,     9,     6,
       7,     0,     2,     4,     4,     4,     3,     0,     2,     1,
       2,     4,     5,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     6,     5,     0,     1,     1,
       3,     1,     2,     2,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     4,     0,     6,     0,
       0,     5,     0,     0,     7,     8,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       2,    74,    75,    76,    77,    81,    28,    29,    30,    31,
      32,    33,    34,    78,    79,     0,     0,     0,     0,     0,
       0,    69,     0,     0,    80,     0,     0,     0,     0,     0,
       0,     0,    10,    27,     0,     0,    26,    12,     0,     0,
       0,     0,    17,    18,    20,     0,    21,     0,    25,    84,
      91,    82,     0,     0,     0,     0,     0,     0,    97,    98,
       0,     0,     0,     0,    49,    22,    23,    81,    70,     0,
       0,     0,     0,     0,    95,    96,    92,     0,    93,    94,
      35,    13,    14,    15,    19,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    40,    41,    42,
      43,    44,    39,     0,     0,     0,     0,    50,    51,     0,
       0,     0,     0,    87,    37,     0,    83,     0,     0,   108,
     109,   106,   107,   110,   111,     0,   113,   114,   112,   104,
     105,   116,   115,    99,   100,   101,   102,   103,     0,     0,
       0,    52,     0,    71,     0,     0,    88,    89,     0,     0,
      36,    87,     0,    45,    48,     0,     0,    53,    73,    72,
      86,     0,    38,    61,     0,   117,     0,    59,    54,    90,
       0,    85,    46,    47,    55,    56,     0,    57,     0,     0,
      60,    62,     0,     0,     0,     0,    67,    58,    67,    67,
      67,    66,    63,    64,    65,    68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     9,    66,    29,   235,    68,    69,
      70,    71,    72,    73,   149,   196,   216,    74,    75,    76,
     210,   221,   231,    77,    78,    79,    80,    81,   185,   186,
      82
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -184
static const yytype_int16 yypact[] =
{
    -184,    18,    -1,  -184,    29,    32,  -184,    36,  -184,   -69,
     -23,  -184,    -3,    43,  -184,  -184,  -184,    53,    54,    52,
      -6,    86,    33,    31,   101,    34,    39,  -184,    35,   157,
    -184,  -184,  -184,  -184,  -184,   -25,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,    40,    41,    39,    56,    38,
      55,   278,    57,    61,  -184,   115,    42,    63,   129,   130,
     278,   278,  -184,  -184,   278,   278,  -184,  -184,   132,    66,
      67,    68,  -184,  -184,  -184,    69,  -184,    70,  -184,  -184,
      62,  -184,   368,   278,   278,   278,   278,   278,  -184,  -184,
     278,   278,   278,   124,    79,  -184,  -184,   -40,   629,   278,
     271,    77,   143,   278,  -184,  -184,  -184,   397,  -184,  -184,
      75,  -184,  -184,  -184,  -184,  -184,   148,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,  -184,   629,   629,   629,
     629,   629,   629,   426,   455,    84,    78,  -184,  -184,    82,
     484,    88,   513,   278,    87,   542,  -184,   278,    95,   153,
     153,   315,   315,   670,   658,   600,    60,   330,   699,   315,
     315,    24,    24,   -36,   -36,  -184,  -184,  -184,    39,    39,
     278,   278,    91,  -184,    92,   122,   110,   629,   278,   127,
     629,   278,   278,   176,  -184,   571,   123,   629,  -184,  -184,
    -184,   278,   629,  -184,   126,   629,   -19,  -184,   334,   629,
     -32,  -184,  -184,  -184,  -184,  -184,   128,   629,    14,   147,
    -184,  -184,    39,   149,   150,   151,  -184,  -184,  -184,  -184,
    -184,   237,   237,   237,   237,  -184
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -184,  -184,  -184,  -184,  -184,   -26,  -184,   178,   152,   117,
     -92,    15,    16,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -183,  -184,  -184,  -184,  -184,  -184,    44,  -184,
     -50
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      28,    98,   148,    45,    14,   218,   219,     4,    11,    12,
     106,   107,    88,    89,   108,   109,    15,   223,     3,   224,
     225,    93,    83,    84,    85,    86,    87,    88,    89,   133,
     134,   135,     5,   137,   138,   139,   140,   141,     7,     8,
     142,   143,   144,    10,   220,   232,   233,   234,    13,   150,
     152,    17,    27,   155,    90,    36,    37,    38,    39,    40,
      41,    42,    16,    18,    20,    19,    21,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   146,   131,   132,   133,
     134,   135,    36,    37,    38,    39,    40,    41,    42,   117,
     118,   119,   120,   187,    22,    24,    23,   190,    25,    26,
      27,    30,    91,    92,    56,    95,   214,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    94,    99,
     195,   197,    96,   100,   101,   103,   104,   105,   202,   110,
     116,   187,   205,   111,   112,   113,   114,   115,   145,   153,
     154,   209,   193,   194,   157,   158,   180,    90,   217,   181,
      31,    32,    33,    34,    35,   183,   188,   191,   198,   199,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
     212,    46,    47,    48,    49,    50,    51,    52,    53,    54,
     201,    55,    56,    57,   119,   120,   227,   200,   203,   206,
     208,   211,   226,   222,   228,   229,   230,    67,   102,    58,
      59,   147,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    60,   213,   215,     0,     0,     0,     0,    27,    61,
       0,     0,     0,    62,    63,   204,     0,     0,    64,    65,
      31,    32,    33,    34,    35,     0,     0,     0,     0,     0,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
       0,    46,    47,    48,    49,    50,    51,    52,    53,    54,
       0,    55,    56,    57,    31,    32,    33,    34,    97,     0,
       0,    31,    32,    33,    34,    97,     0,     0,     0,    58,
      59,    43,    44,     0,     0,     0,     0,     0,    43,    44,
       0,    60,     0,    54,     0,    55,     0,     0,    27,    61,
      54,     0,    55,     0,    63,     0,     0,     0,    64,    65,
       0,     0,     0,    58,    59,     0,     0,     0,     0,     0,
      58,    59,     0,     0,     0,    60,     0,    31,    32,    33,
      34,    35,    60,    61,     0,     0,   151,     0,     0,     0,
      61,     0,    64,    65,    43,    44,    -1,    -1,     0,    64,
      65,     0,     0,     0,     0,     0,    54,     0,    55,   117,
     118,   119,   120,     0,    -1,    -1,   129,   130,   131,   132,
     133,   134,   135,     0,     0,     0,    58,    59,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    60,     0,
       0,     0,     0,     0,     0,     0,    61,   117,   118,   119,
     120,   121,   122,     0,     0,    64,    65,     0,     0,     0,
       0,     0,   123,     0,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   117,   118,   119,   120,
     121,   122,     0,     0,     0,   136,     0,     0,     0,     0,
       0,   123,     0,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   117,   118,   119,   120,   121,
     122,     0,   156,     0,     0,     0,     0,     0,     0,     0,
     123,     0,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   117,   118,   119,   120,   121,   122,
       0,   178,     0,     0,     0,     0,     0,     0,     0,   123,
       0,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   117,   118,   119,   120,   121,   122,     0,
     179,     0,     0,     0,     0,     0,     0,     0,   123,     0,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   117,   118,   119,   120,   121,   122,     0,   182,
       0,     0,     0,     0,     0,     0,     0,   123,     0,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   117,   118,   119,   120,   121,   122,     0,   184,     0,
       0,     0,     0,     0,     0,     0,   123,     0,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     117,   118,   119,   120,   121,   122,     0,   189,     0,     0,
       0,     0,     0,     0,     0,   123,     0,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   117,
     118,   119,   120,   121,   122,     0,   207,     0,     0,     0,
       0,     0,     0,     0,   123,   192,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   117,   118,
     119,   120,   121,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   123,     0,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   117,   118,   119,
     120,   121,     0,     0,     0,     0,     0,     0,     0,   117,
     118,   119,   120,     0,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   117,   118,
     119,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,   128,
     129,   130,   131,   132,   133,   134,   135
};

static const yytype_int16 yycheck[] =
{
      26,    51,    94,    22,     7,    37,    38,     8,    77,    78,
      60,    61,    52,    53,    64,    65,    19,     3,     0,     5,
       6,    47,    47,    48,    49,    50,    51,    52,    53,    65,
      66,    67,    33,    83,    84,    85,    86,    87,     9,     7,
      90,    91,    92,     7,    76,   228,   229,   230,    71,    99,
     100,     8,    71,   103,    79,    13,    14,    15,    16,    17,
      18,    19,    65,    10,    12,    11,    72,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,     7,    63,    64,    65,
      66,    67,    13,    14,    15,    16,    17,    18,    19,    39,
      40,    41,    42,   153,    18,    74,    73,   157,     7,    75,
      71,    76,    72,    72,    35,    77,   208,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    72,    72,
     180,   181,    77,    72,    19,    72,     7,     7,   188,     7,
      78,   191,   192,    77,    77,    77,    77,    77,    24,    72,
       7,   201,   178,   179,    79,     7,    72,    79,   208,    77,
       3,     4,     5,     6,     7,    77,    79,    72,    77,    77,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     206,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      80,    34,    35,    36,    41,    42,   222,    75,    71,    23,
      77,    75,    55,    75,    55,    55,    55,    29,    56,    52,
      53,    94,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    64,   206,   208,    -1,    -1,    -1,    -1,    71,    72,
      -1,    -1,    -1,    76,    77,   191,    -1,    -1,    81,    82,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    35,    36,     3,     4,     5,     6,     7,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    52,
      53,    20,    21,    -1,    -1,    -1,    -1,    -1,    20,    21,
      -1,    64,    -1,    32,    -1,    34,    -1,    -1,    71,    72,
      32,    -1,    34,    -1,    77,    -1,    -1,    -1,    81,    82,
      -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,
      52,    53,    -1,    -1,    -1,    64,    -1,     3,     4,     5,
       6,     7,    64,    72,    -1,    -1,    75,    -1,    -1,    -1,
      72,    -1,    81,    82,    20,    21,    41,    42,    -1,    81,
      82,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    39,
      40,    41,    42,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    52,    53,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    39,    40,    41,
      42,    43,    44,    -1,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    39,    40,    41,    42,    43,
      44,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    39,    40,    41,    42,    43,    44,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    39,    40,    41,    42,    43,    44,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    39,    40,    41,    42,    43,    44,    -1,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    39,    40,    41,    42,    43,    44,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      39,    40,    41,    42,    43,    44,    -1,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    39,
      40,    41,    42,    43,    44,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    67
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    84,    85,     0,     8,    33,    86,     9,     7,    87,
       7,    77,    78,    71,     7,    19,    65,     8,    10,    11,
      12,    72,    18,    73,    74,     7,    75,    71,    88,    89,
      76,     3,     4,     5,     6,     7,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    34,    35,    36,    52,    53,
      64,    72,    76,    77,    81,    82,    88,    90,    91,    92,
      93,    94,    95,    96,   100,   101,   102,   106,   107,   108,
     109,   110,   113,    47,    48,    49,    50,    51,    52,    53,
      79,    72,    72,    88,    72,    77,    77,     7,   113,    72,
      72,    19,    91,    72,     7,     7,   113,   113,   113,   113,
       7,    77,    77,    77,    77,    77,    78,    39,    40,    41,
      42,    43,    44,    54,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    77,   113,   113,   113,
     113,   113,   113,   113,   113,    24,     7,    92,    93,    97,
     113,    75,   113,    72,     7,   113,    75,    79,     7,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,    75,    75,
      72,    77,    75,    77,    75,   111,   112,   113,    79,    75,
     113,    72,    55,    88,    88,   113,    98,   113,    77,    77,
      75,    80,   113,    71,   111,   113,    23,    75,    77,   113,
     103,    75,    88,    95,    93,    94,    99,   113,    37,    38,
      76,   104,    75,     3,     5,     6,    55,    88,    55,    55,
      55,   105,   105,   105,   105,    90
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
#line 88 "parser.y"
    {
            ASTNode* prog = new ASTNode(NODE_PROGRAM);
            // imports carry no runtime behavior, but we keep them as
            // leading no-op statements so they still show up in the AST dump.
            if ((yyvsp[(1) - (17)].nodelist)) {
                for (auto imp : *(yyvsp[(1) - (17)].nodelist)) prog->children.push_back(imp);
                delete (yyvsp[(1) - (17)].nodelist);
            }
            for (auto c : (yyvsp[(16) - (17)].node)->children) prog->children.push_back(c);
            astRoot = prog;
            g_syntaxOk = true;
            delete (yyvsp[(4) - (17)].sval); delete (yyvsp[(14) - (17)].sval);
        ;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 104 "parser.y"
    { (yyval.nodelist) = nullptr; ;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 106 "parser.y"
    {
            if (!(yyvsp[(1) - (2)].nodelist)) (yyvsp[(1) - (2)].nodelist) = new vector<ASTNode*>();
            (yyvsp[(1) - (2)].nodelist)->push_back((yyvsp[(2) - (2)].node));
            (yyval.nodelist) = (yyvsp[(1) - (2)].nodelist);
        ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 115 "parser.y"
    { (yyval.node) = new ASTNode(NODE_IMPORT); (yyval.node)->sval = *(yyvsp[(2) - (3)].sval); delete (yyvsp[(2) - (3)].sval); ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 119 "parser.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 121 "parser.y"
    { *(yyvsp[(1) - (3)].sval) += "."; *(yyvsp[(1) - (3)].sval) += *(yyvsp[(3) - (3)].sval); delete (yyvsp[(3) - (3)].sval); (yyval.sval) = (yyvsp[(1) - (3)].sval); ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 123 "parser.y"
    { *(yyvsp[(1) - (3)].sval) += ".Scanner"; (yyval.sval) = (yyvsp[(1) - (3)].sval); ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 125 "parser.y"
    { *(yyvsp[(1) - (3)].sval) += ".*"; (yyval.sval) = (yyvsp[(1) - (3)].sval); ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 129 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 133 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BLOCK); ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 134 "parser.y"
    { (yyvsp[(1) - (2)].node)->children.push_back((yyvsp[(2) - (2)].node)); (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 138 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 139 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 140 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 141 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 142 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 143 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 144 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 145 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 146 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 147 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BREAK); ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 148 "parser.y"
    { (yyval.node) = new ASTNode(NODE_CONTINUE); ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 149 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 150 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 151 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 152 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BLOCK); ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 156 "parser.y"
    { (yyval.sval) = new string("int"); ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 157 "parser.y"
    { (yyval.sval) = new string("float"); ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 158 "parser.y"
    { (yyval.sval) = new string("double"); ;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 159 "parser.y"
    { (yyval.sval) = new string("char"); ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 160 "parser.y"
    { (yyval.sval) = new string("boolean"); ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 161 "parser.y"
    { (yyval.sval) = new string("String"); ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 162 "parser.y"
    { (yyval.sval) = new string("Scanner"); ;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 167 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_VARDECL);
            (yyval.node)->datatype = *(yyvsp[(1) - (2)].sval); (yyval.node)->sval = *(yyvsp[(2) - (2)].sval);
            delete (yyvsp[(1) - (2)].sval); delete (yyvsp[(2) - (2)].sval);
        ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 173 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_VARDECL);
            (yyval.node)->datatype = *(yyvsp[(1) - (4)].sval); (yyval.node)->sval = *(yyvsp[(2) - (4)].sval);
            (yyval.node)->children.push_back((yyvsp[(4) - (4)].node));
            delete (yyvsp[(1) - (4)].sval); delete (yyvsp[(2) - (4)].sval);
        ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 180 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_VARDECL);
            (yyval.node)->datatype = *(yyvsp[(2) - (3)].sval); (yyval.node)->sval = *(yyvsp[(3) - (3)].sval); (yyval.node)->isFinal = true;
            delete (yyvsp[(2) - (3)].sval); delete (yyvsp[(3) - (3)].sval);
        ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 186 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_VARDECL);
            (yyval.node)->datatype = *(yyvsp[(2) - (5)].sval); (yyval.node)->sval = *(yyvsp[(3) - (5)].sval); (yyval.node)->isFinal = true;
            (yyval.node)->children.push_back((yyvsp[(5) - (5)].node));
            delete (yyvsp[(2) - (5)].sval); delete (yyvsp[(3) - (5)].sval);
        ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 196 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_ASSIGN);
            (yyval.node)->sval = *(yyvsp[(1) - (3)].sval);
            (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
            delete (yyvsp[(1) - (3)].sval);
        ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 206 "parser.y"
    { (yyval.node) = new ASTNode(NODE_COMPOUND_ASSIGN); (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->op = "+="; (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); delete (yyvsp[(1) - (3)].sval); ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 208 "parser.y"
    { (yyval.node) = new ASTNode(NODE_COMPOUND_ASSIGN); (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->op = "-="; (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); delete (yyvsp[(1) - (3)].sval); ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 210 "parser.y"
    { (yyval.node) = new ASTNode(NODE_COMPOUND_ASSIGN); (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->op = "*="; (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); delete (yyvsp[(1) - (3)].sval); ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 212 "parser.y"
    { (yyval.node) = new ASTNode(NODE_COMPOUND_ASSIGN); (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->op = "/="; (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); delete (yyvsp[(1) - (3)].sval); ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 214 "parser.y"
    { (yyval.node) = new ASTNode(NODE_COMPOUND_ASSIGN); (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->op = "%="; (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); delete (yyvsp[(1) - (3)].sval); ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 219 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_IF);
            (yyval.node)->children.push_back((yyvsp[(3) - (5)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (5)].node));
            (yyval.node)->children.push_back(nullptr);
        ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 226 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_IF);
            (yyval.node)->children.push_back((yyvsp[(3) - (7)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (7)].node));
            (yyval.node)->children.push_back((yyvsp[(7) - (7)].node));
        ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 233 "parser.y"
    {
            ASTNode* wrapper = new ASTNode(NODE_BLOCK);
            wrapper->children.push_back((yyvsp[(7) - (7)].node));
            (yyval.node) = new ASTNode(NODE_IF);
            (yyval.node)->children.push_back((yyvsp[(3) - (7)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (7)].node));
            (yyval.node)->children.push_back(wrapper);
        ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 245 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_WHILE);
            (yyval.node)->children.push_back((yyvsp[(3) - (5)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (5)].node));
        ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 253 "parser.y"
    { (yyval.node) = nullptr; ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 254 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 255 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 259 "parser.y"
    { (yyval.node) = nullptr; ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 260 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 264 "parser.y"
    { (yyval.node) = nullptr; ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 265 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 266 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 267 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 272 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_FOR);
            (yyval.node)->children.push_back((yyvsp[(3) - (9)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (9)].node));
            (yyval.node)->children.push_back((yyvsp[(7) - (9)].node));
            (yyval.node)->children.push_back((yyvsp[(9) - (9)].node));
        ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 283 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_DO_WHILE);
            (yyval.node)->children.push_back((yyvsp[(2) - (6)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (6)].node));
        ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 292 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_SWITCH);
            (yyval.node)->children.push_back((yyvsp[(3) - (7)].node));
            if ((yyvsp[(6) - (7)].nodelist)) { for (auto c : *(yyvsp[(6) - (7)].nodelist)) (yyval.node)->children.push_back(c); delete (yyvsp[(6) - (7)].nodelist); }
        ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 300 "parser.y"
    { (yyval.nodelist) = nullptr; ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 302 "parser.y"
    {
            if (!(yyvsp[(1) - (2)].nodelist)) (yyvsp[(1) - (2)].nodelist) = new vector<ASTNode*>();
            (yyvsp[(1) - (2)].nodelist)->push_back((yyvsp[(2) - (2)].node));
            (yyval.nodelist) = (yyvsp[(1) - (2)].nodelist);
        ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 311 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_CASE);
            (yyval.node)->caseKind = "int"; (yyval.node)->ival = (yyvsp[(2) - (4)].ival);
            if ((yyvsp[(4) - (4)].nodelist)) { for (auto s : *(yyvsp[(4) - (4)].nodelist)) (yyval.node)->children.push_back(s); delete (yyvsp[(4) - (4)].nodelist); }
        ;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 317 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_CASE);
            (yyval.node)->caseKind = "char"; (yyval.node)->cval = (yyvsp[(2) - (4)].cval);
            if ((yyvsp[(4) - (4)].nodelist)) { for (auto s : *(yyvsp[(4) - (4)].nodelist)) (yyval.node)->children.push_back(s); delete (yyvsp[(4) - (4)].nodelist); }
        ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 323 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_CASE);
            (yyval.node)->caseKind = "String"; (yyval.node)->sval = *(yyvsp[(2) - (4)].sval); delete (yyvsp[(2) - (4)].sval);
            if ((yyvsp[(4) - (4)].nodelist)) { for (auto s : *(yyvsp[(4) - (4)].nodelist)) (yyval.node)->children.push_back(s); delete (yyvsp[(4) - (4)].nodelist); }
        ;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 329 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_DEFAULT);
            if ((yyvsp[(3) - (3)].nodelist)) { for (auto s : *(yyvsp[(3) - (3)].nodelist)) (yyval.node)->children.push_back(s); delete (yyvsp[(3) - (3)].nodelist); }
        ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 336 "parser.y"
    { (yyval.nodelist) = nullptr; ;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 338 "parser.y"
    {
            if (!(yyvsp[(1) - (2)].nodelist)) (yyvsp[(1) - (2)].nodelist) = new vector<ASTNode*>();
            (yyvsp[(1) - (2)].nodelist)->push_back((yyvsp[(2) - (2)].node));
            (yyval.nodelist) = (yyvsp[(1) - (2)].nodelist);
        ;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 346 "parser.y"
    { (yyval.node) = new ASTNode(NODE_RETURN); ;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 347 "parser.y"
    { (yyval.node) = new ASTNode(NODE_RETURN); (yyval.node)->children.push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 352 "parser.y"
    { (yyval.node) = new ASTNode(NODE_PRINT); (yyval.node)->ival = 1; ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 354 "parser.y"
    { (yyval.node) = new ASTNode(NODE_PRINT); (yyval.node)->ival = 1; (yyval.node)->children.push_back((yyvsp[(3) - (5)].node)); ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 356 "parser.y"
    { (yyval.node) = new ASTNode(NODE_PRINT); (yyval.node)->ival = 0; (yyval.node)->children.push_back((yyvsp[(3) - (5)].node)); ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 360 "parser.y"
    { (yyval.node) = new ASTNode(NODE_NUM_INT); (yyval.node)->ival = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 361 "parser.y"
    { (yyval.node) = new ASTNode(NODE_NUM_FLOAT); (yyval.node)->fval = (yyvsp[(1) - (1)].fval); ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 362 "parser.y"
    { (yyval.node) = new ASTNode(NODE_CHAR); (yyval.node)->cval = (yyvsp[(1) - (1)].cval); ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 363 "parser.y"
    { (yyval.node) = new ASTNode(NODE_STRING); (yyval.node)->sval = *(yyvsp[(1) - (1)].sval); delete (yyvsp[(1) - (1)].sval); ;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 364 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BOOL); (yyval.node)->ival = 1; ;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 365 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BOOL); (yyval.node)->ival = 0; ;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 366 "parser.y"
    { (yyval.node) = new ASTNode(NODE_SYSTEM_IN); ;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 367 "parser.y"
    { (yyval.node) = new ASTNode(NODE_ID); (yyval.node)->sval = *(yyvsp[(1) - (1)].sval); delete (yyvsp[(1) - (1)].sval); ;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 368 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 369 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); ;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 374 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 376 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_METHOD_CALL);
            (yyval.node)->sval = *(yyvsp[(3) - (6)].sval); delete (yyvsp[(3) - (6)].sval);
            (yyval.node)->children.push_back((yyvsp[(1) - (6)].node));
            if ((yyvsp[(5) - (6)].nodelist)) { for (auto a : *(yyvsp[(5) - (6)].nodelist)) (yyval.node)->children.push_back(a); delete (yyvsp[(5) - (6)].nodelist); }
        ;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 386 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_NEW_SCANNER);
            if ((yyvsp[(4) - (5)].nodelist)) delete (yyvsp[(4) - (5)].nodelist); // ctor arg (System.in) has no runtime effect
        ;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 393 "parser.y"
    { (yyval.nodelist) = nullptr; ;}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 394 "parser.y"
    { (yyval.nodelist) = (yyvsp[(1) - (1)].nodelist); ;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 398 "parser.y"
    { (yyval.nodelist) = new vector<ASTNode*>(); (yyval.nodelist)->push_back((yyvsp[(1) - (1)].node)); ;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 399 "parser.y"
    { (yyvsp[(1) - (3)].nodelist)->push_back((yyvsp[(3) - (3)].node)); (yyval.nodelist) = (yyvsp[(1) - (3)].nodelist); ;}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 403 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 404 "parser.y"
    { (yyval.node) = new ASTNode(NODE_UNOP); (yyval.node)->op = "-"; (yyval.node)->children.push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 405 "parser.y"
    { (yyval.node) = new ASTNode(NODE_UNOP); (yyval.node)->op = "!"; (yyval.node)->children.push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 406 "parser.y"
    { (yyval.node) = new ASTNode(NODE_UNOP); (yyval.node)->op = "~"; (yyval.node)->children.push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 407 "parser.y"
    { (yyval.node) = new ASTNode(NODE_PREINC); (yyval.node)->sval = *(yyvsp[(2) - (2)].sval); delete (yyvsp[(2) - (2)].sval); ;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 408 "parser.y"
    { (yyval.node) = new ASTNode(NODE_PREDEC); (yyval.node)->sval = *(yyvsp[(2) - (2)].sval); delete (yyvsp[(2) - (2)].sval); ;}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 409 "parser.y"
    { (yyval.node) = new ASTNode(NODE_POSTINC); (yyval.node)->sval = *(yyvsp[(1) - (2)].sval); delete (yyvsp[(1) - (2)].sval); ;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 410 "parser.y"
    { (yyval.node) = new ASTNode(NODE_POSTDEC); (yyval.node)->sval = *(yyvsp[(1) - (2)].sval); delete (yyvsp[(1) - (2)].sval); ;}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 411 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "+"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 412 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "-"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 413 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "*"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 414 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "/"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 415 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "%"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 416 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "<"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 417 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = ">"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 418 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "<="; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 419 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = ">="; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 420 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "=="; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 421 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "!="; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 422 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "&&"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 423 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "||"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 424 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "&"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 425 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "|"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 426 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "^"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 427 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "<<"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 428 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = ">>"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 429 "parser.y"
    { (yyval.node) = new ASTNode(NODE_TERNARY); (yyval.node)->children.push_back((yyvsp[(1) - (5)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (5)].node)); (yyval.node)->children.push_back((yyvsp[(5) - (5)].node)); ;}
    break;



/* Line 1464 of yacc.c  */
#line 2667 "parser.tab.cpp"
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
#line 432 "parser.y"


void yyerror(const char* s) {
    cerr << "Syntax Error at line " << yylineno << ": " << s << endl;
    g_syntaxOk = false;
}

