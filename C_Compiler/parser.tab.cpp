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
// Syntax Analyzer for Mini C Compiler
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
extern char* yytext;
void yyerror(const char* s);


extern ASTNode* astRoot;
extern bool g_syntaxOk;


/* Line 189 of yacc.c  */
#line 98 "parser.tab.cpp"

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
#line 26 "parser.y"

    #include <string>
    #include <vector>
    #include "ast.h"



/* Line 209 of yacc.c  */
#line 130 "parser.tab.cpp"

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

/* Line 214 of yacc.c  */
#line 34 "parser.y"

    int ival;
    double fval;
    char cval;
    std::string* sval;
    ASTNode* node;
    std::vector<ASTNode*>* nodelist;



/* Line 214 of yacc.c  */
#line 208 "parser.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 220 "parser.tab.cpp"

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
#define YYLAST   972

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNRULES -- Number of states.  */
#define YYNSTATES  235

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,     2,     2,     2,    60,    53,     2,
      63,    64,    58,    56,    69,    57,     2,    59,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    67,
      54,    68,    55,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,    51,    66,    71,     2,     2,     2,
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
      45,    46,    47,    48,    61,    62
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
     112,   116,   120,   124,   128,   132,   138,   146,   154,   160,
     167,   168,   170,   172,   173,   175,   176,   178,   180,   182,
     192,   200,   201,   204,   206,   208,   213,   217,   219,   221,
     227,   228,   232,   238,   239,   244,   246,   249,   251,   253,
     255,   257,   259,   263,   266,   269,   272,   275,   278,   281,
     284,   288,   292,   296,   300,   304,   308,   312,   316,   320,
     324,   328,   332,   336,   340,   344,   348,   352,   356,   362,
     367,   372,   377,   384,   389,   394
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      73,     0,    -1,     9,     7,    63,    64,    74,    -1,    65,
      75,    66,    -1,    -1,    75,    76,    -1,    81,    67,    -1,
      82,    67,    -1,    83,    67,    -1,   102,    67,    -1,    84,
      -1,    85,    -1,    86,    -1,    90,    -1,    91,    -1,    95,
      67,    -1,    96,    67,    -1,    97,    67,    -1,    99,    67,
      -1,   101,    67,    -1,    74,    -1,    67,    -1,     9,    -1,
      10,    -1,    11,    -1,    12,    -1,    13,    -1,    13,     9,
      -1,    13,    13,    -1,    13,    13,     9,    -1,    14,    13,
      -1,    14,    13,    13,    -1,    77,     7,    -1,    77,     7,
      68,   102,    -1,     7,    -1,     7,    68,   102,    -1,    79,
      -1,    80,    69,    79,    -1,    77,    80,    -1,     8,    77,
      80,    -1,     7,    68,   102,    -1,     7,    41,   102,    -1,
       7,    42,   102,    -1,     7,    43,   102,    -1,     7,    44,
     102,    -1,    15,    63,   102,    64,    74,    -1,    15,    63,
     102,    64,    74,    16,    74,    -1,    15,    63,   102,    64,
      74,    16,    84,    -1,    17,    63,   102,    64,    74,    -1,
      19,    74,    17,    63,   102,    64,    -1,    -1,    78,    -1,
      82,    -1,    -1,   102,    -1,    -1,    82,    -1,    83,    -1,
     102,    -1,    18,    63,    87,    67,    88,    67,    89,    64,
      74,    -1,    20,    63,   102,    64,    65,    92,    66,    -1,
      -1,    92,    94,    -1,     3,    -1,     5,    -1,    21,    93,
      50,    75,    -1,    22,    50,    75,    -1,    23,    -1,    24,
      -1,    25,    63,     6,    98,    64,    -1,    -1,    69,   102,
      98,    -1,    26,    63,     6,   100,    64,    -1,    -1,    69,
      53,     7,   100,    -1,    33,    -1,    33,   102,    -1,     3,
      -1,     4,    -1,     5,    -1,     6,    -1,     7,    -1,    63,
     102,    64,    -1,    57,   102,    -1,    70,   102,    -1,    71,
     102,    -1,    45,     7,    -1,    46,     7,    -1,     7,    45,
      -1,     7,    46,    -1,   102,    56,   102,    -1,   102,    57,
     102,    -1,   102,    58,   102,    -1,   102,    59,   102,    -1,
     102,    60,   102,    -1,   102,    54,   102,    -1,   102,    55,
     102,    -1,   102,    37,   102,    -1,   102,    38,   102,    -1,
     102,    35,   102,    -1,   102,    36,   102,    -1,   102,    39,
     102,    -1,   102,    40,   102,    -1,   102,    53,   102,    -1,
     102,    51,   102,    -1,   102,    52,   102,    -1,   102,    47,
     102,    -1,   102,    48,   102,    -1,   102,    49,   102,    50,
     102,    -1,    27,    63,    77,    64,    -1,    27,    63,   102,
      64,    -1,    28,    63,   102,    64,    -1,    29,    63,   102,
      69,   102,    64,    -1,    30,    63,   102,    64,    -1,    31,
      63,   102,    64,    -1,    32,    63,   102,    64,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    88,    88,    99,   103,   104,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   141,   147,   157,   159,   164,   165,   170,   176,
     185,   195,   197,   199,   201,   206,   213,   220,   232,   241,
     250,   251,   252,   256,   257,   261,   262,   263,   264,   268,
     279,   289,   290,   294,   295,   299,   305,   313,   317,   321,
     331,   332,   336,   346,   347,   357,   358,   362,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406
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
  "KW_VOID", "EQ", "NE", "LE", "GE", "AND", "OR", "PLUSEQ", "MINUSEQ",
  "MULEQ", "DIVEQ", "INC", "DEC", "LSHIFT", "RSHIFT", "'?'", "':'", "'|'",
  "'^'", "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS",
  "NOTPREC", "'('", "')'", "'{'", "'}'", "';'", "'='", "','", "'!'", "'~'",
  "$accept", "program", "block", "stmt_list", "stmt", "type_spec",
  "vardecl", "declarator", "declarator_list", "vardecl_stmt",
  "assign_stmt", "compound_assign_stmt", "if_stmt", "while_stmt",
  "do_while_stmt", "for_init", "for_cond", "for_update", "for_stmt",
  "switch_stmt", "case_list", "case_value", "case_clause", "break_stmt",
  "continue_stmt", "printf_stmt", "printf_arglist", "scanf_stmt",
  "scanf_arglist", "return_stmt", "expr", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,    63,
      58,   124,    94,    38,    60,    62,    43,    45,    42,    47,
      37,   304,   305,    40,    41,   123,   125,    59,    61,    44,
      33,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    74,    75,    75,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    78,    78,    79,    79,    80,    80,    81,    81,
      82,    83,    83,    83,    83,    84,    84,    84,    85,    86,
      87,    87,    87,    88,    88,    89,    89,    89,    89,    90,
      91,    92,    92,    93,    93,    94,    94,    95,    96,    97,
      98,    98,    99,   100,   100,   101,   101,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     0,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       2,     3,     2,     4,     1,     3,     1,     3,     2,     3,
       3,     3,     3,     3,     3,     5,     7,     7,     5,     6,
       0,     1,     1,     0,     1,     0,     1,     1,     1,     9,
       7,     0,     2,     1,     1,     4,     3,     1,     1,     5,
       0,     3,     5,     0,     4,     1,     2,     1,     1,     1,
       1,     1,     3,     2,     2,     2,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     4,
       4,     4,     6,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     4,     2,     0,
      77,    78,    79,    80,    81,     0,    22,    23,    24,    25,
      26,     0,     0,     0,     0,     0,     0,    67,    68,     0,
       0,     0,     0,     0,     0,     0,     0,    75,     0,     0,
       0,     0,     3,    21,     0,     0,    20,     5,     0,     0,
       0,     0,    10,    11,    12,    13,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,    89,     0,
       0,    27,    28,    30,     0,     0,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,    76,    86,
      87,    83,     0,    84,    85,    34,    36,    38,     6,     7,
       8,    15,    16,    17,    18,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,    41,    42,    43,    44,
      40,    39,    29,    31,     0,     0,     0,     0,    51,    52,
       0,     0,     0,    70,    73,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,    99,   100,    97,    98,   101,
     102,   106,   107,     0,   104,   105,   103,    95,    96,    90,
      91,    92,    93,    94,     0,     0,    32,    53,     0,     0,
       0,     0,     0,     0,   109,   110,   111,     0,   113,   114,
     115,    35,    37,     0,    45,    48,     0,     0,    54,     0,
      61,    70,    69,     0,    72,     0,   108,     0,    33,    55,
      49,     0,    71,    73,   112,    46,    47,    56,    57,     0,
      58,     0,     0,    60,    62,    74,     0,    63,    64,     0,
       4,    59,     4,    66,    65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    46,     9,    47,    48,   138,    96,    97,    49,
      50,    51,    52,    53,    54,   140,   197,   219,    55,    56,
     211,   229,   224,    57,    58,    59,   181,    60,   183,    61,
      62
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -190
static const yytype_int16 yypact[] =
{
      -2,     5,    26,   -27,  -190,   -20,     0,  -190,  -190,   179,
    -190,  -190,  -190,  -190,   -28,    11,  -190,  -190,  -190,  -190,
      22,    24,     3,     4,    27,     0,    28,  -190,  -190,    30,
      36,    44,    51,    52,    53,    61,    62,   293,    47,    82,
     293,   293,  -190,  -190,   293,   293,  -190,  -190,    85,    59,
      60,    63,  -190,  -190,  -190,  -190,  -190,    64,    65,    66,
      67,    71,   384,   293,   293,   293,   293,  -190,  -190,   293,
      85,  -190,   119,    55,   293,   293,    99,   112,   293,   133,
     134,    91,   293,   293,   293,   293,   293,    17,   766,  -190,
    -190,  -190,   410,  -190,  -190,    75,  -190,    76,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,  -190,   766,   766,   766,   766,
     766,    76,  -190,  -190,   440,   470,    78,   140,  -190,  -190,
      83,    86,   500,    84,    87,    88,   530,   560,   332,   590,
     620,   650,  -190,   293,    85,   898,   898,   912,   912,   818,
     792,     1,     1,   740,   844,   870,   884,   912,   912,    -7,
      -7,  -190,  -190,  -190,     0,     0,    90,   293,   293,    94,
     293,   100,   102,   101,  -190,  -190,  -190,   293,  -190,  -190,
    -190,   766,  -190,   293,   147,  -190,   293,   103,   766,   680,
    -190,   358,  -190,   159,  -190,   710,   766,    -9,   766,   303,
    -190,   -11,  -190,    87,  -190,  -190,  -190,  -190,  -190,   107,
     766,    29,   117,  -190,  -190,  -190,     0,  -190,  -190,   122,
    -190,  -190,  -190,   248,   248
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -190,  -190,    -6,  -189,  -190,   -12,  -190,    20,   105,  -190,
     -74,   -33,   -30,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,   -23,  -190,   -34,  -190,
     -36
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
       8,    88,   139,    70,    91,    92,    22,     1,    93,    94,
     221,   222,     3,    63,    64,    65,    66,    67,    68,    77,
      16,    17,    18,    19,    20,    21,     4,   126,   127,   128,
     129,    71,   227,   130,   228,    72,     5,    73,   134,   135,
      69,   233,   142,   234,     6,   146,   147,   148,   149,   150,
     151,   122,   123,   124,    89,   223,     7,   120,   121,   122,
     123,   124,    67,    68,   137,     7,    74,    75,   133,   145,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,    90,
      76,    78,    95,    79,    10,    11,    12,    13,    87,    80,
      16,    17,    18,    19,    20,    21,   136,    81,    16,    17,
      18,    19,    20,    21,    82,    83,    84,   191,    31,    32,
      33,    34,    35,    36,    85,    86,    98,    99,   132,   141,
     100,   101,   102,   103,   104,   217,    38,    39,   105,   143,
     144,   198,   199,   153,   201,   154,    69,   176,    40,   178,
     177,   205,   184,   180,    41,   203,   182,   206,   196,   200,
     208,    44,    45,   207,   202,   204,   213,   230,   194,   195,
     209,   226,   232,   220,   192,   131,   218,   216,   212,   225,
       0,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     0,    23,    24,    25,    26,
       0,   215,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,     0,     0,     0,     0,     0,     0,     0,
     231,     0,     0,     0,    38,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    40,     0,     0,     0,
       0,     0,    41,     0,     7,    42,    43,     0,     0,    44,
      45,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     0,    23,    24,    25,    26,     0,
       0,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    39,     0,    10,    11,    12,    13,
      87,     0,     0,     0,     0,    40,    10,    11,    12,    13,
      14,    41,     0,     7,     0,    43,     0,     0,    44,    45,
      31,    32,    33,    34,    35,    36,     0,     0,     0,     0,
      31,    32,    33,    34,    35,    36,     0,     0,    38,    39,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    39,
      40,     0,     0,     0,     0,     0,    41,     0,     0,     0,
      40,     0,     0,    44,    45,     0,    41,   106,   107,   108,
     109,   110,   111,    44,    45,     0,     0,     0,     0,   112,
     113,   114,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   106,   107,   108,   109,   110,   111,     0,
       0,   187,     0,     0,     0,   112,   113,   114,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   106,
     107,   108,   109,   110,   111,     0,     0,   180,     0,     0,
       0,   112,   113,   114,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   106,   107,   108,   109,   110,
     111,   125,     0,     0,     0,     0,     0,   112,   113,   114,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,     0,     0,   152,   106,   107,   108,   109,   110,
     111,     0,     0,     0,     0,     0,     0,   112,   113,   114,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,     0,     0,   174,   106,   107,   108,   109,   110,
     111,     0,     0,     0,     0,     0,     0,   112,   113,   114,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,     0,     0,   175,   106,   107,   108,   109,   110,
     111,     0,     0,     0,     0,     0,     0,   112,   113,   114,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,     0,     0,   179,   106,   107,   108,   109,   110,
     111,     0,     0,     0,     0,     0,     0,   112,   113,   114,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,     0,     0,   185,   106,   107,   108,   109,   110,
     111,     0,     0,     0,     0,     0,     0,   112,   113,   114,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,     0,     0,   186,   106,   107,   108,   109,   110,
     111,     0,     0,     0,     0,     0,     0,   112,   113,   114,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,     0,     0,   188,   106,   107,   108,   109,   110,
     111,     0,     0,     0,     0,     0,     0,   112,   113,   114,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,     0,     0,   189,   106,   107,   108,   109,   110,
     111,     0,     0,     0,     0,     0,     0,   112,   113,   114,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,     0,     0,   190,   106,   107,   108,   109,   110,
     111,     0,     0,     0,     0,     0,     0,   112,   113,   114,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,     0,     0,   210,   106,   107,   108,   109,   110,
     111,     0,     0,     0,     0,     0,     0,   112,   113,   114,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,     0,     0,   214,   106,   107,   108,   109,   110,
     111,     0,     0,     0,     0,     0,     0,   112,   113,   114,
     193,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   106,   107,   108,   109,   110,   111,     0,     0,     0,
       0,     0,     0,   112,   113,   114,     0,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   106,   107,   108,
     109,   110,     0,     0,     0,     0,     0,     0,     0,   112,
     113,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   106,   107,   108,   109,     0,     0,     0,
       0,     0,     0,     0,     0,   112,   113,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   106,
     107,   108,   109,     0,     0,     0,     0,     0,     0,     0,
       0,   112,   113,     0,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   106,   107,   108,   109,     0,
       0,     0,     0,     0,     0,     0,     0,   112,   113,   106,
     107,   108,   109,   117,   118,   119,   120,   121,   122,   123,
     124,   112,   113,     0,     0,   108,   109,     0,   118,   119,
     120,   121,   122,   123,   124,   112,   113,     0,     0,    -1,
      -1,     0,   118,   119,   120,   121,   122,   123,   124,   112,
     113,     0,     0,     0,     0,     0,    -1,    -1,   120,   121,
     122,   123,   124
};

static const yytype_int16 yycheck[] =
{
       6,    37,    76,    15,    40,    41,    15,     9,    44,    45,
      21,    22,     7,    41,    42,    43,    44,    45,    46,    25,
       9,    10,    11,    12,    13,    14,     0,    63,    64,    65,
      66,     9,     3,    69,     5,    13,    63,    13,    74,    75,
      68,   230,    78,   232,    64,    81,    82,    83,    84,    85,
      86,    58,    59,    60,     7,    66,    65,    56,    57,    58,
      59,    60,    45,    46,    76,    65,    63,    63,    13,    81,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     7,
      63,    63,     7,    63,     3,     4,     5,     6,     7,    63,
       9,    10,    11,    12,    13,    14,     7,    63,     9,    10,
      11,    12,    13,    14,    63,    63,    63,   153,    27,    28,
      29,    30,    31,    32,    63,    63,    67,    67,     9,    17,
      67,    67,    67,    67,    67,   209,    45,    46,    67,     6,
       6,   177,   178,    68,   180,    69,    68,     7,    57,    63,
      67,   187,    64,    69,    63,    53,    69,   193,    68,    65,
     196,    70,    71,    16,    64,    64,     7,    50,   174,   175,
      67,    64,    50,   209,   154,    70,   209,   207,   201,   213,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    19,    20,
      -1,   207,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    65,    66,    67,    -1,    -1,    70,
      71,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    18,    19,    20,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    57,     3,     4,     5,     6,
       7,    63,    -1,    65,    -1,    67,    -1,    -1,    70,    71,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      57,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      57,    -1,    -1,    70,    71,    -1,    63,    35,    36,    37,
      38,    39,    40,    70,    71,    -1,    -1,    -1,    -1,    47,
      48,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    35,    36,    37,    38,    39,    40,    -1,
      -1,    69,    -1,    -1,    -1,    47,    48,    49,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    35,
      36,    37,    38,    39,    40,    -1,    -1,    69,    -1,    -1,
      -1,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    35,    36,    37,    38,    39,
      40,    67,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    64,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    64,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    64,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    64,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    64,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    64,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    64,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    64,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    64,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    64,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    64,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    35,
      36,    37,    38,    53,    54,    55,    56,    57,    58,    59,
      60,    47,    48,    -1,    -1,    37,    38,    -1,    54,    55,
      56,    57,    58,    59,    60,    47,    48,    -1,    -1,    37,
      38,    -1,    54,    55,    56,    57,    58,    59,    60,    47,
      48,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,    57,
      58,    59,    60
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    73,     7,     0,    63,    64,    65,    74,    75,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    17,    18,    19,    20,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    45,    46,
      57,    63,    66,    67,    70,    71,    74,    76,    77,    81,
      82,    83,    84,    85,    86,    90,    91,    95,    96,    97,
      99,   101,   102,    41,    42,    43,    44,    45,    46,    68,
      77,     9,    13,    13,    63,    63,    63,    74,    63,    63,
      63,    63,    63,    63,    63,    63,    63,     7,   102,     7,
       7,   102,   102,   102,   102,     7,    79,    80,    67,    67,
      67,    67,    67,    67,    67,    67,    35,    36,    37,    38,
      39,    40,    47,    48,    49,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    67,   102,   102,   102,   102,
     102,    80,     9,    13,   102,   102,     7,    77,    78,    82,
      87,    17,   102,     6,     6,    77,   102,   102,   102,   102,
     102,   102,    64,    68,    69,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,    64,    64,     7,    67,    63,    64,
      69,    98,    69,   100,    64,    64,    64,    69,    64,    64,
      64,   102,    79,    50,    74,    74,    68,    88,   102,   102,
      65,   102,    64,    53,    64,   102,   102,    16,   102,    67,
      64,    92,    98,     7,    64,    74,    84,    82,    83,    89,
     102,    21,    22,    66,    94,   100,    64,     3,     5,    93,
      50,    74,    50,    75,    75
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
#line 89 "parser.y"
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
#line 99 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); ;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 103 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BLOCK); ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 104 "parser.y"
    { (yyvsp[(1) - (2)].node)->children.push_back((yyvsp[(2) - (2)].node)); (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 108 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 109 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 110 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 111 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 112 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 113 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 114 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 115 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 116 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 117 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 118 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 119 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 120 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 121 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 122 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 123 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BLOCK); ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 127 "parser.y"
    { (yyval.sval) = new string("int"); ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 128 "parser.y"
    { (yyval.sval) = new string("float"); ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 129 "parser.y"
    { (yyval.sval) = new string("double"); ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 130 "parser.y"
    { (yyval.sval) = new string("char"); ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 131 "parser.y"
    { (yyval.sval) = new string("long"); ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 132 "parser.y"
    { (yyval.sval) = new string("long"); ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 133 "parser.y"
    { (yyval.sval) = new string("long"); ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 134 "parser.y"
    { (yyval.sval) = new string("long"); ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 135 "parser.y"
    { (yyval.sval) = new string("long"); ;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 136 "parser.y"
    { (yyval.sval) = new string("long"); ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 142 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_VARDECL);
            (yyval.node)->datatype = *(yyvsp[(1) - (2)].sval); (yyval.node)->sval = *(yyvsp[(2) - (2)].sval); (yyval.node)->line = yylineno;
            delete (yyvsp[(1) - (2)].sval); delete (yyvsp[(2) - (2)].sval);
        ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 148 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_VARDECL);
            (yyval.node)->datatype = *(yyvsp[(1) - (4)].sval); (yyval.node)->sval = *(yyvsp[(2) - (4)].sval); (yyval.node)->line = yylineno;
            (yyval.node)->children.push_back((yyvsp[(4) - (4)].node));
            delete (yyvsp[(1) - (4)].sval); delete (yyvsp[(2) - (4)].sval);
        ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 158 "parser.y"
    { (yyval.node) = new ASTNode(NODE_VARDECL); (yyval.node)->sval = *(yyvsp[(1) - (1)].sval); (yyval.node)->line = yylineno; delete (yyvsp[(1) - (1)].sval); ;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 160 "parser.y"
    { (yyval.node) = new ASTNode(NODE_VARDECL); (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->line = yylineno; (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); delete (yyvsp[(1) - (3)].sval); ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 164 "parser.y"
    { (yyval.nodelist) = new std::vector<ASTNode*>(); (yyval.nodelist)->push_back((yyvsp[(1) - (1)].node)); ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 165 "parser.y"
    { (yyvsp[(1) - (3)].nodelist)->push_back((yyvsp[(3) - (3)].node)); (yyval.nodelist) = (yyvsp[(1) - (3)].nodelist); ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 171 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_BLOCK);
            for (auto d : *(yyvsp[(2) - (2)].nodelist)) { d->datatype = *(yyvsp[(1) - (2)].sval); (yyval.node)->children.push_back(d); }
            delete (yyvsp[(1) - (2)].sval); delete (yyvsp[(2) - (2)].nodelist);
        ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 177 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_BLOCK);
            for (auto d : *(yyvsp[(3) - (3)].nodelist)) { d->datatype = *(yyvsp[(2) - (3)].sval); d->isConst = true; (yyval.node)->children.push_back(d); }
            delete (yyvsp[(2) - (3)].sval); delete (yyvsp[(3) - (3)].nodelist);
        ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 186 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_ASSIGN);
            (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->line = yylineno;
            (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
            delete (yyvsp[(1) - (3)].sval);
        ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 196 "parser.y"
    { (yyval.node) = new ASTNode(NODE_COMPOUND_ASSIGN); (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->op = "+="; (yyval.node)->line = yylineno; (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); delete (yyvsp[(1) - (3)].sval); ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 198 "parser.y"
    { (yyval.node) = new ASTNode(NODE_COMPOUND_ASSIGN); (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->op = "-="; (yyval.node)->line = yylineno; (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); delete (yyvsp[(1) - (3)].sval); ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 200 "parser.y"
    { (yyval.node) = new ASTNode(NODE_COMPOUND_ASSIGN); (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->op = "*="; (yyval.node)->line = yylineno; (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); delete (yyvsp[(1) - (3)].sval); ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 202 "parser.y"
    { (yyval.node) = new ASTNode(NODE_COMPOUND_ASSIGN); (yyval.node)->sval = *(yyvsp[(1) - (3)].sval); (yyval.node)->op = "/="; (yyval.node)->line = yylineno; (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); delete (yyvsp[(1) - (3)].sval); ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 207 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_IF); (yyval.node)->line = yylineno;
            (yyval.node)->children.push_back((yyvsp[(3) - (5)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (5)].node));
            (yyval.node)->children.push_back(nullptr);
        ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 214 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_IF); (yyval.node)->line = yylineno;
            (yyval.node)->children.push_back((yyvsp[(3) - (7)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (7)].node));
            (yyval.node)->children.push_back((yyvsp[(7) - (7)].node));
        ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 221 "parser.y"
    {
            ASTNode* wrapper = new ASTNode(NODE_BLOCK);
            wrapper->children.push_back((yyvsp[(7) - (7)].node));
            (yyval.node) = new ASTNode(NODE_IF); (yyval.node)->line = yylineno;
            (yyval.node)->children.push_back((yyvsp[(3) - (7)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (7)].node));
            (yyval.node)->children.push_back(wrapper);
        ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 233 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_WHILE); (yyval.node)->line = yylineno;
            (yyval.node)->children.push_back((yyvsp[(3) - (5)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (5)].node));
        ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 242 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_DOWHILE); (yyval.node)->line = yylineno;
            (yyval.node)->children.push_back((yyvsp[(2) - (6)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (6)].node));
        ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 250 "parser.y"
    { (yyval.node) = nullptr; ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 251 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 252 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 256 "parser.y"
    { (yyval.node) = nullptr; ;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 257 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 261 "parser.y"
    { (yyval.node) = nullptr; ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 262 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 263 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 264 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 269 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_FOR); (yyval.node)->line = yylineno;
            (yyval.node)->children.push_back((yyvsp[(3) - (9)].node));
            (yyval.node)->children.push_back((yyvsp[(5) - (9)].node));
            (yyval.node)->children.push_back((yyvsp[(7) - (9)].node));
            (yyval.node)->children.push_back((yyvsp[(9) - (9)].node));
        ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 280 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_SWITCH); (yyval.node)->line = yylineno;
            (yyval.node)->children.push_back((yyvsp[(3) - (7)].node));
            for (auto c : *(yyvsp[(6) - (7)].nodelist)) (yyval.node)->children.push_back(c);
            delete (yyvsp[(6) - (7)].nodelist);
        ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 289 "parser.y"
    { (yyval.nodelist) = new std::vector<ASTNode*>(); ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 290 "parser.y"
    { (yyvsp[(1) - (2)].nodelist)->push_back((yyvsp[(2) - (2)].node)); (yyval.nodelist) = (yyvsp[(1) - (2)].nodelist); ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 294 "parser.y"
    { (yyval.ival) = (int)strtoll((yyvsp[(1) - (1)].sval)->c_str(), nullptr, 10); delete (yyvsp[(1) - (1)].sval); ;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 295 "parser.y"
    { (yyval.ival) = (int)(yyvsp[(1) - (1)].cval); ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 300 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_CASE); (yyval.node)->line = yylineno;
            (yyval.node)->ival = (yyvsp[(2) - (4)].ival);
            (yyval.node)->children.push_back((yyvsp[(4) - (4)].node));
        ;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 306 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_DEFAULT); (yyval.node)->line = yylineno;
            (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
        ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 313 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BREAK); (yyval.node)->line = yylineno; ;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 317 "parser.y"
    { (yyval.node) = new ASTNode(NODE_CONTINUE); (yyval.node)->line = yylineno; ;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 322 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_PRINTF); (yyval.node)->line = yylineno;
            (yyval.node)->sval = *(yyvsp[(3) - (5)].sval);
            (yyval.node)->children = *(yyvsp[(4) - (5)].nodelist);
            delete (yyvsp[(3) - (5)].sval); delete (yyvsp[(4) - (5)].nodelist);
        ;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 331 "parser.y"
    { (yyval.nodelist) = new std::vector<ASTNode*>(); ;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 332 "parser.y"
    { (yyvsp[(3) - (3)].nodelist)->insert((yyvsp[(3) - (3)].nodelist)->begin(), (yyvsp[(2) - (3)].node)); (yyval.nodelist) = (yyvsp[(3) - (3)].nodelist); ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 337 "parser.y"
    {
            (yyval.node) = new ASTNode(NODE_SCANF); (yyval.node)->line = yylineno;
            (yyval.node)->sval = *(yyvsp[(3) - (5)].sval);
            (yyval.node)->children = *(yyvsp[(4) - (5)].nodelist);
            delete (yyvsp[(3) - (5)].sval); delete (yyvsp[(4) - (5)].nodelist);
        ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 346 "parser.y"
    { (yyval.nodelist) = new std::vector<ASTNode*>(); ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 348 "parser.y"
    {
            ASTNode* idn = new ASTNode(NODE_ID);
            idn->sval = *(yyvsp[(3) - (4)].sval); delete (yyvsp[(3) - (4)].sval);
            (yyvsp[(4) - (4)].nodelist)->insert((yyvsp[(4) - (4)].nodelist)->begin(), idn);
            (yyval.nodelist) = (yyvsp[(4) - (4)].nodelist);
        ;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 357 "parser.y"
    { (yyval.node) = new ASTNode(NODE_RETURN); (yyval.node)->line = yylineno; ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 358 "parser.y"
    { (yyval.node) = new ASTNode(NODE_RETURN); (yyval.node)->line = yylineno; (yyval.node)->children.push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 362 "parser.y"
    {
                              long long v = strtoll((yyvsp[(1) - (1)].sval)->c_str(), nullptr, 10);
                              delete (yyvsp[(1) - (1)].sval);
                              (yyval.node) = new ASTNode(NODE_NUM_INT);
                              if (v >= -2147483648LL && v <= 2147483647LL) { (yyval.node)->ival = (int)v; }
                              else { (yyval.node)->datatype = "long"; (yyval.node)->llit = v; }
                            ;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 369 "parser.y"
    { (yyval.node) = new ASTNode(NODE_NUM_FLOAT); (yyval.node)->fval = (yyvsp[(1) - (1)].fval); ;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 370 "parser.y"
    { (yyval.node) = new ASTNode(NODE_CHAR); (yyval.node)->cval = (yyvsp[(1) - (1)].cval); ;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 371 "parser.y"
    { (yyval.node) = new ASTNode(NODE_STRING); (yyval.node)->sval = *(yyvsp[(1) - (1)].sval); delete (yyvsp[(1) - (1)].sval); ;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 372 "parser.y"
    { (yyval.node) = new ASTNode(NODE_ID); (yyval.node)->sval = *(yyvsp[(1) - (1)].sval); delete (yyvsp[(1) - (1)].sval); ;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 373 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); ;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 374 "parser.y"
    { (yyval.node) = new ASTNode(NODE_UNOP); (yyval.node)->op = "-"; (yyval.node)->children.push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 375 "parser.y"
    { (yyval.node) = new ASTNode(NODE_UNOP); (yyval.node)->op = "!"; (yyval.node)->children.push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 376 "parser.y"
    { (yyval.node) = new ASTNode(NODE_UNOP); (yyval.node)->op = "~"; (yyval.node)->children.push_back((yyvsp[(2) - (2)].node)); ;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 377 "parser.y"
    { (yyval.node) = new ASTNode(NODE_PREINC); (yyval.node)->sval = *(yyvsp[(2) - (2)].sval); delete (yyvsp[(2) - (2)].sval); ;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 378 "parser.y"
    { (yyval.node) = new ASTNode(NODE_PREDEC); (yyval.node)->sval = *(yyvsp[(2) - (2)].sval); delete (yyvsp[(2) - (2)].sval); ;}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 379 "parser.y"
    { (yyval.node) = new ASTNode(NODE_POSTINC); (yyval.node)->sval = *(yyvsp[(1) - (2)].sval); delete (yyvsp[(1) - (2)].sval); ;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 380 "parser.y"
    { (yyval.node) = new ASTNode(NODE_POSTDEC); (yyval.node)->sval = *(yyvsp[(1) - (2)].sval); delete (yyvsp[(1) - (2)].sval); ;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 381 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "+"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 382 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "-"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 383 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "*"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 384 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "/"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 385 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "%"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 386 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "<"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 387 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = ">"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 388 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "<="; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 389 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = ">="; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 390 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "=="; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 391 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "!="; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 392 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "&&"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 393 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "||"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 394 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "&"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 395 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "|"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 396 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "^"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 397 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = "<<"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 398 "parser.y"
    { (yyval.node) = new ASTNode(NODE_BINOP); (yyval.node)->op = ">>"; (yyval.node)->children.push_back((yyvsp[(1) - (3)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); ;}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 399 "parser.y"
    { (yyval.node) = new ASTNode(NODE_TERNARY); (yyval.node)->children.push_back((yyvsp[(1) - (5)].node)); (yyval.node)->children.push_back((yyvsp[(3) - (5)].node)); (yyval.node)->children.push_back((yyvsp[(5) - (5)].node)); ;}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 400 "parser.y"
    { (yyval.node) = new ASTNode(NODE_SIZEOF); (yyval.node)->datatype = *(yyvsp[(3) - (4)].sval); delete (yyvsp[(3) - (4)].sval); ;}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 401 "parser.y"
    { (yyval.node) = new ASTNode(NODE_SIZEOF); (yyval.node)->children.push_back((yyvsp[(3) - (4)].node)); ;}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 402 "parser.y"
    { (yyval.node) = new ASTNode(NODE_CALL); (yyval.node)->sval = "sqrt"; (yyval.node)->children.push_back((yyvsp[(3) - (4)].node)); ;}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 403 "parser.y"
    { (yyval.node) = new ASTNode(NODE_CALL); (yyval.node)->sval = "pow"; (yyval.node)->children.push_back((yyvsp[(3) - (6)].node)); (yyval.node)->children.push_back((yyvsp[(5) - (6)].node)); ;}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 404 "parser.y"
    { (yyval.node) = new ASTNode(NODE_CALL); (yyval.node)->sval = "abs"; (yyval.node)->children.push_back((yyvsp[(3) - (4)].node)); ;}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 405 "parser.y"
    { (yyval.node) = new ASTNode(NODE_CALL); (yyval.node)->sval = "ceil"; (yyval.node)->children.push_back((yyvsp[(3) - (4)].node)); ;}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 406 "parser.y"
    { (yyval.node) = new ASTNode(NODE_CALL); (yyval.node)->sval = "floor"; (yyval.node)->children.push_back((yyvsp[(3) - (4)].node)); ;}
    break;



/* Line 1464 of yacc.c  */
#line 2675 "parser.tab.cpp"
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
#line 409 "parser.y"


void yyerror(const char* s) {
    cerr << "Syntax Error:" << endl;
    cerr << "Line " << yylineno << ":" << endl;
    cerr << s;
    if (yytext && yytext[0] != '\0') cerr << " (near token '" << yytext << "')";
    cerr << "." << endl;
    g_syntaxOk = false;
}

