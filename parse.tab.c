/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "includes/parse.y" /* yacc.c:339  */

	#include <stack>
	#include <string>
	#include <iostream>
	#include "includes/ast.h"
	int yylex (void);
	extern char *yytext;
	void yyerror (const char *);

	
	PoolOfNodes& pool = PoolOfNodes::getInstance();

	
	int complexity = 0;
	int old_complexity = 0;
	bool isFinally = false;
	struct func_info{
		int line;
		int column;
		std::string name;
		int complexity;
	};
	std::stack<func_info> func_stack;
	void reverse(std::stack<func_info>);

#line 92 "parse.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parse.tab.h".  */
#ifndef YY_YY_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AMPEREQUAL = 258,
    AMPERSAND = 259,
    AND = 260,
    AS = 261,
    ASSERT = 262,
    AT = 263,
    BACKQUOTE = 264,
    BAR = 265,
    BREAK = 266,
    CIRCUMFLEX = 267,
    CIRCUMFLEXEQUAL = 268,
    CLASS = 269,
    COLON = 270,
    COMMA = 271,
    CONTINUE = 272,
    DEDENT = 273,
    DEF = 274,
    DEL = 275,
    DOT = 276,
    DOUBLESLASH = 277,
    DOUBLESLASHEQUAL = 278,
    DOUBLESTAR = 279,
    DOUBLESTAREQUAL = 280,
    ELIF = 281,
    ELSE = 282,
    ENDMARKER = 283,
    EQEQUAL = 284,
    EQUAL = 285,
    EXCEPT = 286,
    EXEC = 287,
    FINALLY = 288,
    FOR = 289,
    FROM = 290,
    GLOBAL = 291,
    GREATER = 292,
    GREATEREQUAL = 293,
    GRLT = 294,
    IF = 295,
    IMPORT = 296,
    IN = 297,
    INDENT = 298,
    IS = 299,
    LAMBDA = 300,
    LBRACE = 301,
    LEFTSHIFT = 302,
    LEFTSHIFTEQUAL = 303,
    LESS = 304,
    LESSEQUAL = 305,
    LPAR = 306,
    LSQB = 307,
    MINEQUAL = 308,
    MINUS = 309,
    NAME = 310,
    NEWLINE = 311,
    NOT = 312,
    NOTEQUAL = 313,
    INTEGER = 314,
    FLOAT = 315,
    OR = 316,
    PASS = 317,
    PERCENT = 318,
    PERCENTEQUAL = 319,
    PLUS = 320,
    PLUSEQUAL = 321,
    PRINT = 322,
    RAISE = 323,
    RBRACE = 324,
    RETURN = 325,
    RIGHTSHIFT = 326,
    RIGHTSHIFTEQUAL = 327,
    RPAR = 328,
    RSQB = 329,
    SEMI = 330,
    SLASH = 331,
    SLASHEQUAL = 332,
    STAR = 333,
    STAREQUAL = 334,
    STRING = 335,
    TILDE = 336,
    TRY = 337,
    VBAREQUAL = 338,
    WHILE = 339,
    WITH = 340,
    YIELD = 341
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 40 "includes/parse.y" /* yacc.c:355  */

	Node* node;
	char *str;
	int intNum;
	float fltNum;
	char oper;

#line 227 "parse.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 258 "parse.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1091

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  141
/* YYNRULES -- Number of rules.  */
#define YYNRULES  316
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  478

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   341

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    61,    61,    64,    70,    71,    74,    75,    78,    79,
      82,    83,    86,    87,    90,    91,    94,   109,   110,   113,
     114,   117,   118,   121,   122,   125,   126,   129,   130,   133,
     134,   137,   138,   141,   142,   145,   146,   149,   153,   156,
     157,   163,   164,   167,   171,   172,   173,   174,   175,   176,
     177,   178,   181,   211,   226,   227,   230,   234,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     251,   256,   259,   263,   266,   270,   273,   274,   277,   278,
     281,   284,   287,   288,   289,   290,   291,   294,   297,   300,
     301,   304,   307,   308,   311,   312,   315,   316,   319,   320,
     323,   326,   329,   330,   333,   334,   335,   338,   339,   342,
     343,   346,   347,   350,   351,   354,   355,   358,   359,   362,
     365,   366,   369,   370,   373,   374,   377,   378,   379,   380,
     381,   382,   383,   384,   387,   388,   391,   392,   395,   396,
     399,   400,   403,   416,   419,   420,   423,   424,   427,   428,
     431,   434,   435,   438,   439,   442,   443,   446,   447,   450,
     451,   454,   455,   458,   459,   462,   463,   466,   467,   470,
     471,   474,   475,   478,   482,   485,   486,   489,   493,   496,
     500,   503,   504,   510,   514,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   530,   534,   537,   541,
     544,   548,   551,   555,   558,   559,   562,   566,   582,   586,
     592,   596,   618,   622,   626,   630,   636,   653,   657,   660,
     664,   668,   674,   681,   689,   690,   693,   694,   695,   696,
     697,   703,   704,   707,   712,   719,   720,   723,   724,   727,
     728,   731,   732,   735,   736,   739,   740,   743,   744,   747,
     748,   751,   752,   753,   756,   757,   760,   761,   764,   765,
     766,   769,   770,   773,   774,   777,   778,   781,   782,   785,
     786,   789,   793,   799,   800,   803,   804,   807,   808,   811,
     812,   815,   816,   819,   820,   823,   829,   830,   833,   834,
     837,   838,   841,   845,   846,   849,   850,   853,   854,   857,
     858,   861,   862,   865,   866,   869,   870,   873,   874,   877,
     878,   881,   882,   885,   886,   889,   890
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AMPEREQUAL", "AMPERSAND", "AND", "AS",
  "ASSERT", "AT", "BACKQUOTE", "BAR", "BREAK", "CIRCUMFLEX",
  "CIRCUMFLEXEQUAL", "CLASS", "COLON", "COMMA", "CONTINUE", "DEDENT",
  "DEF", "DEL", "DOT", "DOUBLESLASH", "DOUBLESLASHEQUAL", "DOUBLESTAR",
  "DOUBLESTAREQUAL", "ELIF", "ELSE", "ENDMARKER", "EQEQUAL", "EQUAL",
  "EXCEPT", "EXEC", "FINALLY", "FOR", "FROM", "GLOBAL", "GREATER",
  "GREATEREQUAL", "GRLT", "IF", "IMPORT", "IN", "INDENT", "IS", "LAMBDA",
  "LBRACE", "LEFTSHIFT", "LEFTSHIFTEQUAL", "LESS", "LESSEQUAL", "LPAR",
  "LSQB", "MINEQUAL", "MINUS", "NAME", "NEWLINE", "NOT", "NOTEQUAL",
  "INTEGER", "FLOAT", "OR", "PASS", "PERCENT", "PERCENTEQUAL", "PLUS",
  "PLUSEQUAL", "PRINT", "RAISE", "RBRACE", "RETURN", "RIGHTSHIFT",
  "RIGHTSHIFTEQUAL", "RPAR", "RSQB", "SEMI", "SLASH", "SLASHEQUAL", "STAR",
  "STAREQUAL", "STRING", "TILDE", "TRY", "VBAREQUAL", "WHILE", "WITH",
  "YIELD", "$accept", "start", "file_input", "pick_NEWLINE_stmt",
  "star_NEWLINE_stmt", "decorator", "opt_arglist", "decorators",
  "decorated", "funcdef", "parameters", "varargslist", "opt_EQUAL_test",
  "star_fpdef_COMMA", "opt_DOUBLESTAR_NAME", "pick_STAR_DOUBLESTAR",
  "opt_COMMA", "fpdef", "fplist", "star_fpdef_notest", "stmt",
  "simple_stmt", "star_SEMI_small_stmt", "small_stmt", "expr_stmt",
  "pick_yield_expr_testlist", "star_EQUAL", "augassign", "print_stmt",
  "star_COMMA_test", "opt_test", "plus_COMMA_test", "opt_test_2",
  "del_stmt", "pass_stmt", "flow_stmt", "break_stmt", "continue_stmt",
  "return_stmt", "yield_stmt", "raise_stmt", "opt_COMMA_test",
  "opt_test_3", "import_stmt", "import_name", "import_from",
  "pick_dotted_name", "pick_STAR_import", "import_as_name",
  "dotted_as_name", "import_as_names", "star_COMMA_import_as_name",
  "dotted_as_names", "dotted_name", "global_stmt", "star_COMMA_NAME",
  "exec_stmt", "assert_stmt", "compound_stmt", "if_stmt", "star_ELIF",
  "while_stmt", "for_stmt", "try_stmt", "plus_except", "opt_ELSE",
  "opt_FINALLY", "with_stmt", "star_COMMA_with_item", "with_item",
  "except_clause", "pick_AS_COMMA", "opt_AS_COMMA", "suite", "plus_stmt",
  "testlist_safe", "plus_COMMA_old_test", "old_test", "old_lambdef",
  "test", "opt_IF_ELSE", "or_test", "and_test", "not_test", "comparison",
  "comp_op", "expr", "xor_expr", "and_expr", "shift_expr",
  "pick_LEFTSHIFT_RIGHTSHIFT", "arith_expr", "pick_PLUS_MINUS", "term",
  "pick_multop", "factor", "pick_unop", "power", "star_trailer", "atom",
  "number", "pick_yield_expr_testlist_comp", "opt_yield_test",
  "opt_listmaker", "opt_dictorsetmaker", "plus_STRING", "listmaker",
  "testlist_comp", "lambdef", "trailer", "subscriptlist",
  "star_COMMA_subscript", "subscript", "opt_test_only", "opt_sliceop",
  "sliceop", "exprlist", "star_COMMA_expr", "testlist", "dictorsetmaker",
  "star_test_COLON_test", "pick_for_test_test", "pick_for_test",
  "classdef", "opt_testlist", "arglist", "star_argument_COMMA",
  "star_COMMA_argument", "opt_DOUBLESTAR_test", "pick_argument",
  "argument", "opt_comp_for", "list_iter", "list_for", "list_if",
  "comp_iter", "comp_for", "comp_if", "testlist1", "yield_expr",
  "star_DOT", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341
};
# endif

#define YYPACT_NINF -309

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-309)))

#define YYTABLE_NINF -262

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -309,    47,  -309,   415,  -309,   934,    34,   934,  -309,    60,
    -309,    87,  1010,  -309,  1010,  1010,  -309,    92,   934,    34,
      72,   934,    21,   934,  -309,  -309,  -309,   978,  -309,  -309,
    -309,  -309,   338,   787,   804,  -309,  -309,   134,   934,   934,
     934,  -309,  -309,   140,  -309,  -309,  -309,  -309,  -309,  -309,
    -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,
    -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,
    -309,  -309,    18,    43,  -309,   320,   142,   148,   159,    -9,
     -10,    30,  -309,  1010,  -309,  -309,  -309,    91,  -309,    46,
    -309,  -309,   160,  -309,    14,  -309,    37,    10,   127,   142,
    -309,    32,   138,   141,     5,  -309,   169,  -309,   171,   105,
     934,   176,    13,    75,   124,  -309,   162,  -309,   121,  -309,
    -309,   164,   125,  -309,  -309,   934,  -309,  -309,   184,  -309,
     655,   186,  -309,   197,  -309,  -309,  -309,  -309,    42,   188,
     978,   978,  -309,   978,  -309,  -309,  -309,  -309,  -309,   149,
    -309,  -309,   166,  -309,  1010,  1010,  1010,  1010,  -309,  -309,
    1010,  -309,  -309,  1010,  -309,  -309,  -309,  -309,  1010,  -309,
      33,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,
    -309,  -309,  -309,  -309,   175,    21,   934,   155,   139,  -309,
    -309,   934,   655,   934,   143,   196,   201,   934,   934,    41,
     172,   200,   202,   655,    34,   177,  -309,   934,   178,   -12,
    -309,   180,  -309,   206,   934,  1010,   215,  -309,  -309,  -309,
     215,  -309,  -309,  1010,   215,  -309,  -309,   221,   215,   934,
    -309,   195,  -309,    83,   655,   158,  1010,  -309,   717,   934,
       2,    43,  -309,  -309,  -309,   142,   148,   159,    -9,   -10,
      30,  -309,   187,  1010,   139,   868,  -309,    21,  -309,  -309,
    -309,  -309,  -309,   168,  -309,   285,  -309,  -309,  -309,   173,
    -309,   174,   655,  1010,   228,   230,   193,   243,  -309,  -309,
    -309,  -309,   198,  -309,  -309,  -309,  -309,  -309,  -309,   179,
     235,   934,   238,   162,   214,   218,  -309,  -309,   216,  -309,
     934,   245,  -309,  -309,   228,   575,   885,   244,   108,   247,
     241,   655,   934,   142,  -309,  -309,  -309,   934,  -309,  -309,
     192,   250,   261,   205,  -309,   266,  -309,   226,   934,   934,
     128,  -309,   268,   270,  -309,  -309,   142,   934,  -309,   655,
     224,   233,   273,  -309,   163,   288,  -309,   281,  -309,  -309,
       9,  -309,   292,  -309,  -309,   978,   966,  -309,   836,  -309,
    -309,  -309,   495,    35,   655,   295,   278,   298,   655,   299,
    -309,  -309,  -309,  -309,   294,  -309,   300,   934,  -309,  -309,
    -309,   934,  -309,  -309,   246,  -309,   655,  -309,   290,  -309,
    -309,   193,   934,   303,   -12,   265,    86,  -309,    16,   306,
      63,   310,  -309,   272,  -309,  -309,  -309,  -309,  -309,   934,
    -309,  -309,   655,   307,  -309,   655,  -309,   655,  -309,   868,
    -309,   312,   313,  -309,  -309,   319,  -309,   323,   655,  -309,
    -309,   326,   966,  -309,  -309,  -309,   966,   328,   966,  -309,
    -309,  -309,   966,   330,  -309,  -309,   655,  -309,  -309,  -309,
     934,  -309,  -309,   917,  -309,   655,   655,  -309,   934,    93,
    -309,   966,    63,  -309,   755,  -309,  -309,  -309,   934,  -309,
    -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       7,     0,     2,   218,     1,   218,     0,   218,    87,     0,
      88,     0,   218,     3,   218,   218,   316,     0,   218,     0,
      24,   218,   218,   218,   220,   230,     4,   218,   234,   233,
      81,   219,   218,   218,   218,   244,   221,     0,   218,   218,
     218,     6,    13,     0,   133,   131,     5,    37,    42,    43,
      44,    45,    46,    47,    82,    83,    84,    86,    85,    48,
      98,    99,    49,    50,    51,    38,   126,   127,   128,   129,
     130,    73,   176,   177,   179,   182,   183,   196,   198,   200,
     202,   206,   210,   218,   217,   225,   231,   232,   174,    57,
     132,    91,   125,   117,     0,   311,     0,     0,     0,   270,
      80,   123,     0,     0,     0,   121,     0,   115,   100,   110,
     218,     0,     0,    73,     0,   241,    73,   237,     0,   236,
     235,    73,     0,   239,   181,   218,    70,    73,    97,    89,
     218,     0,   152,   154,   313,    12,    15,    14,     0,   272,
     218,   218,   173,   218,   187,   186,   188,   190,   192,   194,
     185,   189,     0,   191,   218,   218,   218,   218,   204,   205,
     218,   209,   208,   218,   215,   214,   213,   212,   218,   216,
     223,   243,    63,    65,    69,    68,    66,    59,    62,    58,
      67,    61,    60,    64,    53,   218,   218,     0,   287,     9,
     229,   218,   218,   218,    24,     0,   268,   218,   218,     0,
     315,   102,   119,   218,     0,     0,   250,   218,     0,     0,
      31,     0,    19,    22,   218,   218,    30,   274,   279,   228,
      30,   247,   226,   218,    30,   245,   227,    79,    30,   218,
      92,     0,   161,     0,   218,     0,   218,    40,   218,   218,
       0,   178,   180,   195,   193,   184,   197,   199,   201,   203,
     207,   211,     0,   218,   287,   218,   224,   218,    52,    55,
      54,   124,   118,     0,    10,   218,   312,   282,   283,     0,
      18,     0,   218,   218,    95,     0,     0,   108,   104,   101,
     114,   106,     0,   137,   116,   109,   249,    28,    36,     0,
      26,   218,    30,   276,     0,   218,   280,   248,     0,   246,
     218,    30,    71,    74,    95,   218,   218,     0,   147,     0,
     139,   218,   218,   153,    39,    41,    72,   218,   253,   222,
       0,     0,   259,     0,   257,     0,    56,     0,   218,   218,
     298,   285,    30,     0,    17,    16,   269,   218,   122,   218,
       0,     0,   112,   120,   135,    34,    32,     0,    27,    21,
      23,    20,    30,   273,   277,   218,   218,    77,   218,    78,
      96,   164,   218,   160,   218,     0,   149,     0,   218,     0,
     150,   151,   175,   251,     0,   252,   255,   218,     8,   294,
     289,   218,   295,   297,   286,   292,   218,    94,   141,   105,
     107,   111,   218,     0,    33,     0,   218,   278,   308,    24,
     302,   166,   170,   169,    76,   162,   163,   157,   158,   218,
     155,   143,   218,     0,   142,   218,   145,   218,   258,   218,
     261,   264,   291,   296,   281,     0,   113,     0,   218,    35,
      25,     0,   218,   307,   305,   306,   218,     0,   218,   301,
     299,   300,   218,    30,   159,   146,   218,   144,   138,   256,
     218,   260,   263,   218,   293,   218,   218,   134,   218,   310,
     172,   218,   304,   168,   218,   165,   148,   265,   218,   288,
     140,   136,   275,   309,   171,   303,   167,   290
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -309,  -309,  -309,  -309,  -309,   305,    81,  -309,  -309,   308,
    -309,  -185,  -309,  -309,  -309,  -309,  -188,  -199,  -309,  -309,
    -274,    -2,  -309,   114,  -309,    97,  -309,  -309,  -309,    56,
    -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,
    -309,    51,  -309,  -309,  -309,  -309,  -309,  -309,   -35,   157,
      95,  -309,  -309,    17,  -309,  -309,  -309,  -309,  -309,  -309,
    -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,    55,
      65,  -309,  -309,  -189,  -309,  -309,  -309,  -308,  -309,    -5,
    -309,  -136,   227,    -7,  -309,  -309,     7,   219,   223,   225,
    -309,   220,  -309,   212,  -309,   -68,  -309,  -309,  -309,  -309,
    -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,
    -309,  -309,   -38,     8,  -309,  -309,    -8,  -309,   -28,  -309,
    -309,  -309,  -309,   343,  -309,  -309,  -309,  -309,  -309,  -309,
     -65,  -309,   -66,   279,  -309,   -60,  -105,  -309,  -309,   -17,
    -309
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    41,     3,    42,   263,    43,    44,    45,
     195,   111,   292,   112,   348,   212,   296,   213,   289,   345,
      46,   232,   138,    48,    49,   258,   184,   185,    50,   139,
     126,   301,   302,    51,    52,    53,    54,    55,    56,    57,
      58,   338,   230,    59,    60,    61,   103,   279,   280,   107,
     281,   342,   108,   109,    62,   202,    63,    64,    65,    66,
     344,    67,    68,    69,   308,   366,   414,    70,   235,   132,
     309,   409,   410,   233,   362,   400,   443,   401,   402,    71,
     142,    72,    73,    74,    75,   154,    76,    77,    78,    79,
     160,    80,   163,    81,   168,    82,    83,    84,   170,    85,
      86,   117,   118,   122,   114,    87,   123,   119,    88,   256,
     323,   376,   324,   325,   451,   452,   100,   196,    89,   115,
     352,   353,   217,    90,   269,   264,   265,   422,   454,   331,
     332,   382,   439,   440,   441,   433,   434,   435,    96,    91,
     104
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      92,    47,    95,   267,   240,   120,   129,   102,   218,   271,
     288,   221,   134,   106,   283,   169,   113,   116,   121,    99,
     124,   101,    99,    94,   -29,   192,   200,   127,   128,   317,
       7,   361,   297,   131,   133,   187,   299,   208,   158,   209,
     303,   407,   155,   210,   161,   310,   190,     4,   143,   172,
     215,   408,   164,   191,   252,   162,   432,   253,   140,   173,
      93,   193,   159,   141,   209,   188,    20,    21,   210,   174,
     189,   175,    22,    23,   197,    24,    25,   141,    27,   141,
      28,    29,   -29,   335,   254,   255,    31,   110,   406,    93,
     214,   211,   276,   165,   176,     7,   277,   223,   237,   177,
     251,    35,    36,   438,   351,   206,   166,    40,   167,   215,
     178,   205,   179,   359,   306,    97,   307,   238,   180,   278,
     227,   201,   370,   181,   459,   182,   187,   215,   460,   183,
     462,    20,    21,   432,   463,   365,   242,    22,    23,   306,
      24,    25,    98,    27,   385,    28,    29,   105,     6,   130,
     388,    31,   155,   474,     9,   -29,   476,   259,   381,    11,
     156,   245,   215,   157,   397,   268,    35,    36,   260,   216,
     275,   171,   220,   311,   312,   411,   186,   224,   194,   416,
     198,   261,   199,   228,   203,   319,   266,   204,   354,   392,
     393,   207,   274,   219,   222,   429,   215,   424,   223,   226,
     229,   234,   286,   236,   239,   257,   243,   294,   244,   293,
     262,   272,   -11,  -103,   437,   298,   270,   273,   282,   398,
     403,   187,    99,   445,   304,   383,   447,     7,   448,   259,
      99,   295,   285,   287,   316,   290,   291,   300,   305,   457,
     260,   327,   318,   313,   337,   339,   333,   334,   277,   341,
     322,   347,   346,   343,   350,   465,   355,   466,   356,   364,
     330,   358,   368,    20,    21,   373,   470,   471,   369,    22,
      23,   374,    24,    25,   -29,    27,  -261,    28,    29,   375,
     336,   377,   378,    31,   384,   386,   349,   -29,   390,   391,
     316,   -29,   -29,   -29,     7,   357,   403,   389,    35,    36,
     403,   363,   403,    47,   394,   395,   403,   133,   396,   328,
     412,   413,   372,   415,   417,   418,   419,   425,   428,   -29,
     430,   436,   446,   379,   380,   403,   442,   450,   403,   453,
      20,    21,   387,   141,   455,   320,    22,    23,   456,    24,
      25,   458,    27,   461,    28,    29,   464,     7,   135,   144,
      31,   136,   315,   404,   326,   360,   426,   145,   146,   147,
      47,   284,   148,   329,   149,    35,    36,   371,   241,   150,
     151,   340,   420,   367,   246,   250,   423,   152,   153,   247,
     249,   449,   248,    20,    21,   421,   137,   427,   469,    22,
      23,   431,    24,    25,   -75,    27,   475,    28,    29,   473,
     225,     0,     0,    31,   444,     0,     0,     0,     0,   125,
       0,     0,     0,   -75,   322,     0,     0,     0,    35,    36,
       0,     0,     5,     6,     7,     0,     8,     0,     0,     9,
       0,     0,    10,     0,    11,    12,     0,     0,     0,     0,
       0,     0,     0,    13,     0,   467,     0,    14,   330,    15,
      16,    17,     0,   472,     0,    18,    19,     0,     0,     0,
      20,    21,     0,   477,     0,     0,    22,    23,     0,    24,
      25,    26,    27,     0,    28,    29,     0,    30,     0,     0,
      31,     0,    32,    33,     0,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,    36,    37,     0,    38,
      39,    40,     5,     6,     7,     0,     8,     0,     0,     9,
       0,     0,    10,   405,    11,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,    15,
      16,    17,     0,     0,     0,    18,    19,     0,     0,     0,
      20,    21,     0,     0,     0,     0,    22,    23,     0,    24,
      25,     0,    27,     0,    28,    29,     0,    30,     0,     0,
      31,     0,    32,    33,     0,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,    36,    37,     0,    38,
      39,    40,     5,     6,     7,     0,     8,     0,     0,     9,
       0,     0,    10,     0,    11,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,    15,
      16,    17,     0,     0,     0,    18,    19,     0,     0,     0,
      20,    21,     0,     0,     0,     0,    22,    23,     0,    24,
      25,     0,    27,     0,    28,    29,     0,    30,     0,     0,
      31,     0,    32,    33,     0,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,    36,    37,     0,    38,
      39,    40,     5,     0,     7,     0,     8,     0,     0,     0,
       0,     0,    10,     0,     0,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,     0,
      16,    17,     0,     0,     0,     0,    19,     0,     0,     0,
      20,    21,     0,     0,     0,     0,    22,    23,     0,    24,
      25,   231,    27,     0,    28,    29,     0,    30,     0,     0,
      31,     0,    32,    33,     5,    34,     7,     0,     8,     0,
       0,     0,     0,     0,    10,    35,    36,    12,     0,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,    14,
       0,     0,    16,    17,     0,     0,     0,     0,    19,     0,
       0,     0,    20,    21,     7,     0,     0,     0,    22,    23,
       0,    24,    25,   314,    27,     0,    28,    29,     0,    30,
       0,     0,    31,     0,    32,    33,     0,    34,     0,   -29,
       0,     0,     0,     0,     0,   -29,     7,    35,    36,     0,
     399,    21,     0,    40,     0,     0,    22,    23,     0,    24,
      25,     0,    27,     7,    28,    29,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,   -29,
       0,     0,    20,    21,     0,    35,    36,     0,    22,    23,
       0,    24,    25,   -93,    27,     7,    28,    29,     0,    20,
      21,     0,    31,     0,     0,    22,    23,     0,    24,    25,
     -90,    27,   -93,    28,    29,     0,     0,    35,    36,    31,
       0,     0,     0,     0,     0,     0,     0,     7,     0,   -90,
       0,    20,    21,     0,    35,    36,     0,    22,    23,   321,
      24,    25,   -29,    27,     7,    28,    29,     0,     0,     0,
    -156,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -29,     0,    20,    21,     0,    35,    36,     0,    22,
      23,     0,    24,    25,     0,    27,     7,    28,    29,     0,
      20,    21,     0,    31,     0,     0,    22,    23,     0,    24,
      25,   468,    27,     7,    28,    29,     0,     0,    35,    36,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,    21,     0,    35,    36,     0,    22,    23,
       0,    24,    25,     0,    27,     7,    28,    29,     0,    20,
      21,     0,    31,     0,     0,    22,    23,     7,    24,    25,
       0,    27,     0,    28,    29,     0,     0,    35,    36,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   399,    21,     0,    35,    36,     0,    22,    23,     7,
      24,    25,     0,    27,    21,    28,    29,     0,     0,    22,
      23,    31,    24,    25,     0,    27,     0,    28,    29,     0,
       0,     0,     0,    31,     0,     0,    35,    36,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,    35,    36,
       0,    22,    23,     0,    24,    25,     0,     0,     0,    28,
      29,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      35,    36
};

static const yytype_int16 yycheck[] =
{
       5,     3,     7,   192,   140,    22,    34,    15,   113,   194,
     209,   116,    40,    18,   203,    83,    21,    22,    23,    12,
      27,    14,    15,     6,    15,    15,    21,    32,    33,    27,
       9,   305,   220,    38,    39,    21,   224,    24,    47,    51,
     228,     6,    10,    55,    54,   234,     9,     0,     5,     3,
      34,    16,    22,    16,    21,    65,    40,    24,    40,    13,
      55,    51,    71,    61,    51,    51,    45,    46,    55,    23,
      56,    25,    51,    52,    42,    54,    55,    61,    57,    61,
      59,    60,    73,   272,    51,    52,    65,    15,   362,    55,
      15,    78,    51,    63,    48,     9,    55,    34,    56,    53,
     168,    80,    81,    40,   292,   110,    76,    86,    78,    34,
      64,     6,    66,   301,    31,    55,    33,    75,    72,    78,
     125,   104,   311,    77,   432,    79,    21,    34,   436,    83,
     438,    45,    46,    40,   442,    27,   143,    51,    52,    31,
      54,    55,    55,    57,   332,    59,    60,    55,     8,    15,
     339,    65,    10,   461,    14,    69,   464,   185,    30,    19,
      12,   154,    34,     4,   352,   193,    80,    81,   185,   113,
     198,    80,   116,    15,    16,   364,    16,   121,    51,   368,
      42,   186,    41,   127,    15,   253,   191,    16,   293,    26,
      27,    15,   197,    69,    73,   394,    34,   386,    34,    74,
      16,    15,   207,     6,    16,    30,    57,   215,    42,   214,
      55,    15,    73,    41,   399,   223,    73,    16,    16,   355,
     356,    21,   215,   412,   229,   330,   415,     9,   417,   257,
     223,    16,    55,    55,   239,    55,    30,    16,    43,   428,
     257,    73,    55,   236,    16,    15,    73,    73,    55,     6,
     255,    16,    73,    55,    16,   443,    42,   446,    42,    15,
     265,    16,    15,    45,    46,    73,   455,   456,    27,    51,
      52,    21,    54,    55,    56,    57,    15,    59,    60,    74,
     273,    15,    56,    65,    16,    15,   291,    69,    55,    16,
     295,    73,    74,    75,     9,   300,   432,    73,    80,    81,
     436,   306,   438,   305,    16,    24,   442,   312,    16,    24,
      15,    33,   317,    15,    15,    21,    16,    27,    15,    73,
      55,    15,    15,   328,   329,   461,    16,    15,   464,    16,
      45,    46,   337,    61,    15,   254,    51,    52,    15,    54,
      55,    15,    57,    15,    59,    60,    16,     9,    43,    29,
      65,    43,   238,   358,   257,   304,   391,    37,    38,    39,
     362,   204,    42,    78,    44,    80,    81,   312,   141,    49,
      50,   276,   377,   308,   155,   163,   381,    57,    58,   156,
     160,   419,   157,    45,    46,   377,    43,   392,   453,    51,
      52,   396,    54,    55,    56,    57,   462,    59,    60,   459,
     121,    -1,    -1,    65,   409,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    -1,    75,   419,    -1,    -1,    -1,    80,    81,
      -1,    -1,     7,     8,     9,    -1,    11,    -1,    -1,    14,
      -1,    -1,    17,    -1,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,   450,    -1,    32,   453,    34,
      35,    36,    -1,   458,    -1,    40,    41,    -1,    -1,    -1,
      45,    46,    -1,   468,    -1,    -1,    51,    52,    -1,    54,
      55,    56,    57,    -1,    59,    60,    -1,    62,    -1,    -1,
      65,    -1,    67,    68,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    81,    82,    -1,    84,
      85,    86,     7,     8,     9,    -1,    11,    -1,    -1,    14,
      -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,
      35,    36,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      45,    46,    -1,    -1,    -1,    -1,    51,    52,    -1,    54,
      55,    -1,    57,    -1,    59,    60,    -1,    62,    -1,    -1,
      65,    -1,    67,    68,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    81,    82,    -1,    84,
      85,    86,     7,     8,     9,    -1,    11,    -1,    -1,    14,
      -1,    -1,    17,    -1,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,
      35,    36,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      45,    46,    -1,    -1,    -1,    -1,    51,    52,    -1,    54,
      55,    -1,    57,    -1,    59,    60,    -1,    62,    -1,    -1,
      65,    -1,    67,    68,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    81,    82,    -1,    84,
      85,    86,     7,    -1,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      45,    46,    -1,    -1,    -1,    -1,    51,    52,    -1,    54,
      55,    56,    57,    -1,    59,    60,    -1,    62,    -1,    -1,
      65,    -1,    67,    68,     7,    70,     9,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    17,    80,    81,    20,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    45,    46,     9,    -1,    -1,    -1,    51,    52,
      -1,    54,    55,    56,    57,    -1,    59,    60,    -1,    62,
      -1,    -1,    65,    -1,    67,    68,    -1,    70,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    40,     9,    80,    81,    -1,
      45,    46,    -1,    86,    -1,    -1,    51,    52,    -1,    54,
      55,    -1,    57,     9,    59,    60,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    45,    46,    -1,    80,    81,    -1,    51,    52,
      -1,    54,    55,    56,    57,     9,    59,    60,    -1,    45,
      46,    -1,    65,    -1,    -1,    51,    52,    -1,    54,    55,
      56,    57,    75,    59,    60,    -1,    -1,    80,    81,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    75,
      -1,    45,    46,    -1,    80,    81,    -1,    51,    52,    21,
      54,    55,    56,    57,     9,    59,    60,    -1,    -1,    -1,
      15,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    -1,    45,    46,    -1,    80,    81,    -1,    51,
      52,    -1,    54,    55,    -1,    57,     9,    59,    60,    -1,
      45,    46,    -1,    65,    -1,    -1,    51,    52,    -1,    54,
      55,    24,    57,     9,    59,    60,    -1,    -1,    80,    81,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    -1,    80,    81,    -1,    51,    52,
      -1,    54,    55,    -1,    57,     9,    59,    60,    -1,    45,
      46,    -1,    65,    -1,    -1,    51,    52,     9,    54,    55,
      -1,    57,    -1,    59,    60,    -1,    -1,    80,    81,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    80,    81,    -1,    51,    52,     9,
      54,    55,    -1,    57,    46,    59,    60,    -1,    -1,    51,
      52,    65,    54,    55,    -1,    57,    -1,    59,    60,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    80,    81,
      -1,    51,    52,    -1,    54,    55,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    88,    89,    91,     0,     7,     8,     9,    11,    14,
      17,    19,    20,    28,    32,    34,    35,    36,    40,    41,
      45,    46,    51,    52,    54,    55,    56,    57,    59,    60,
      62,    65,    67,    68,    70,    80,    81,    82,    84,    85,
      86,    90,    92,    94,    95,    96,   107,   108,   110,   111,
     115,   120,   121,   122,   123,   124,   125,   126,   127,   130,
     131,   132,   141,   143,   144,   145,   146,   148,   149,   150,
     154,   166,   168,   169,   170,   171,   173,   174,   175,   176,
     178,   180,   182,   183,   184,   186,   187,   192,   195,   205,
     210,   226,   166,    55,   140,   166,   225,    55,    55,   173,
     203,   173,   203,   133,   227,    55,   166,   136,   139,   140,
      15,    98,   100,   166,   191,   206,   166,   188,   189,   194,
     226,   166,   190,   193,   170,    71,   117,   166,   166,   205,
      15,   166,   156,   166,   205,    92,    96,   210,   109,   116,
      40,    61,   167,     5,    29,    37,    38,    39,    42,    44,
      49,    50,    57,    58,   172,    10,    12,     4,    47,    71,
     177,    54,    65,   179,    22,    63,    76,    78,   181,   182,
     185,    80,     3,    13,    23,    25,    48,    53,    64,    66,
      72,    77,    79,    83,   113,   114,    16,    21,    51,    56,
       9,    16,    15,    51,    51,    97,   204,    42,    42,    41,
      21,   140,   142,    15,    16,     6,   166,    15,    24,    51,
      55,    78,   102,   104,    15,    34,   116,   209,   223,    69,
     116,   223,    73,    34,   116,   220,    74,   166,   116,    16,
     129,    56,   108,   160,    15,   155,     6,    56,    75,    16,
     168,   169,   170,    57,    42,   173,   174,   175,   176,   178,
     180,   182,    21,    24,    51,    52,   196,    30,   112,   205,
     226,   166,    55,    93,   212,   213,   166,   160,   205,   211,
      73,    98,    15,    16,   166,   205,    51,    55,    78,   134,
     135,   137,    16,   160,   136,    55,   166,    55,   104,   105,
      55,    30,    99,   166,   203,    16,   103,   103,   203,   103,
      16,   118,   119,   103,   166,    43,    31,    33,   151,   157,
     160,    15,    16,   173,    56,   110,   166,    27,    55,   182,
      93,    21,   166,   197,   199,   200,   112,    73,    24,    78,
     166,   216,   217,    73,    73,   160,   173,    16,   128,    15,
     137,     6,   138,    55,   147,   106,    73,    16,   101,   166,
      16,   103,   207,   208,   223,    42,    42,   166,    16,   103,
     128,   107,   161,   166,    15,    27,   152,   157,    15,    27,
     160,   156,   166,    73,    21,    74,   198,    15,    56,   166,
     166,    30,   218,   223,    16,   103,    15,   166,   160,    73,
      55,    16,    26,    27,    16,    24,    16,   103,   168,    45,
     162,   164,   165,   168,   166,    18,   107,     6,    16,   158,
     159,   160,    15,    33,   153,    15,   160,    15,    21,    16,
     166,   200,   214,   166,   160,    27,   135,   166,    15,   104,
      55,   166,    40,   222,   223,   224,    15,    98,    40,   219,
     220,   221,    16,   163,   166,   160,    15,   160,   160,   199,
      15,   201,   202,    16,   215,    15,    15,   160,    15,   164,
     164,    15,   164,   164,    16,   103,   160,   166,    24,   217,
     160,   160,   166,   222,   164,   219,   164,   166
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    89,    90,    90,    91,    91,    92,    92,
      93,    93,    94,    94,    95,    95,    96,    97,    97,    98,
      98,    99,    99,   100,   100,   101,   101,   102,   102,   103,
     103,   104,   104,   105,   105,   106,   106,   107,   107,   108,
     108,   109,   109,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   111,   111,   112,   112,   113,   113,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     115,   115,   116,   116,   117,   117,   118,   118,   119,   119,
     120,   121,   122,   122,   122,   122,   122,   123,   124,   125,
     125,   126,   127,   127,   128,   128,   129,   129,   130,   130,
     131,   132,   133,   133,   134,   134,   134,   135,   135,   136,
     136,   137,   137,   138,   138,   139,   139,   140,   140,   141,
     142,   142,   143,   143,   144,   144,   145,   145,   145,   145,
     145,   145,   145,   145,   146,   146,   147,   147,   148,   148,
     149,   149,   150,   150,   151,   151,   152,   152,   153,   153,
     154,   155,   155,   156,   156,   157,   157,   158,   158,   159,
     159,   160,   160,   161,   161,   162,   162,   163,   163,   164,
     164,   165,   165,   166,   166,   167,   167,   168,   168,   169,
     169,   170,   170,   171,   171,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   173,   173,   174,   174,
     175,   175,   176,   176,   177,   177,   178,   178,   179,   179,
     180,   180,   181,   181,   181,   181,   182,   182,   182,   183,
     183,   183,   184,   184,   185,   185,   186,   186,   186,   186,
     186,   186,   186,   187,   187,   188,   188,   189,   189,   190,
     190,   191,   191,   192,   192,   193,   193,   194,   194,   195,
     195,   196,   196,   196,   197,   197,   198,   198,   199,   199,
     199,   200,   200,   201,   201,   202,   202,   203,   203,   204,
     204,   205,   205,   206,   206,   207,   207,   208,   208,   209,
     209,   210,   210,   211,   211,   212,   213,   213,   214,   214,
     215,   215,   216,   216,   216,   217,   217,   218,   218,   219,
     219,   220,   220,   221,   221,   222,   222,   223,   223,   224,
     224,   225,   225,   226,   226,   227,   227
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     0,     6,     3,
       1,     0,     2,     1,     2,     2,     5,     3,     2,     2,
       4,     2,     0,     4,     0,     3,     0,     3,     2,     1,
       0,     1,     3,     3,     2,     3,     0,     1,     1,     4,
       3,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     1,     3,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     3,     0,     3,     0,     3,     2,     2,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     3,     1,     2,     0,     3,     0,     1,     1,
       2,     4,     2,     2,     1,     3,     1,     3,     1,     3,
       1,     3,     2,     3,     0,     1,     3,     1,     3,     3,
       3,     0,     5,     2,     4,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     8,     5,     5,     0,     7,     4,
       9,     6,     6,     6,     4,     3,     3,     0,     3,     0,
       5,     3,     0,     3,     1,     3,     1,     1,     1,     2,
       0,     1,     4,     2,     1,     3,     1,     3,     2,     1,
       1,     4,     3,     2,     1,     4,     0,     1,     3,     1,
       3,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     2,     1,     0,     1,
       1,     1,     4,     2,     2,     0,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       0,     1,     0,     2,     1,     2,     3,     2,     3,     4,
       3,     3,     3,     2,     3,     2,     3,     0,     3,     1,
       4,     1,     0,     1,     0,     2,     1,     3,     2,     3,
       0,     3,     2,     4,     2,     5,     0,     1,     2,     1,
       2,     7,     4,     1,     0,     2,     3,     0,     3,     0,
       3,     0,     2,     4,     2,     2,     3,     1,     0,     1,
       1,     5,     4,     3,     2,     1,     1,     5,     4,     3,
       2,     1,     3,     2,     1,     2,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 65 "includes/parse.y" /* yacc.c:1661  */
    {
		reverse(func_stack);
	}
#line 1962 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 82 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node);}
#line 1968 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 83 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 1974 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 95 "includes/parse.y" /* yacc.c:1661  */
    {
		struct func_info func;
		func.line = (yylsp[-4]).first_line;
		func.column = (yylsp[-4]).first_column;
		func.name = (yyvsp[-3].str);
	    delete[] (yyvsp[-3].str);	
		func.complexity = ++complexity;
		func_stack.push(func);
		complexity = 0;
		old_complexity = 0;
		isFinally = false;
	}
#line 1991 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 109 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 1997 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 110 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2003 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 125 "includes/parse.y" /* yacc.c:1661  */
    {delete[] (yyvsp[0].str);}
#line 2009 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 129 "includes/parse.y" /* yacc.c:1661  */
    {delete[] (yyvsp[-1].str);}
#line 2015 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 130 "includes/parse.y" /* yacc.c:1661  */
    {delete[] (yyvsp[0].str);}
#line 2021 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 137 "includes/parse.y" /* yacc.c:1661  */
    {delete[] (yyvsp[0].str);}
#line 2027 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 150 "includes/parse.y" /* yacc.c:1661  */
    {
//		$$ = $1;
	}
#line 2035 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 158 "includes/parse.y" /* yacc.c:1661  */
    {
//		$$ = $1;
	}
#line 2043 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 168 "includes/parse.y" /* yacc.c:1661  */
    {
//		$$ = $1;
	}
#line 2051 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 182 "includes/parse.y" /* yacc.c:1661  */
    {
		Node* tempNode;
		switch((yyvsp[-1].intNum)){
			case 1:
				tempNode = new AddBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
				break;
			case 2:
				tempNode = new SubBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
				break;
			case 3:
				tempNode = new MulBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
				break;
			case 4:
				tempNode = new DivBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
				break;
			case 5:
				tempNode = new PerBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
				break;
			case 6:
				tempNode = new DbStarBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
				break;
			case 7:
				tempNode = new DbSlashBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
				break;
		}
		(yyvsp[-2].node) = new AsgBinaryNode((yyvsp[-2].node), tempNode);
		pool.add((yyvsp[-2].node));
		delete tempNode;
	}
#line 2085 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 212 "includes/parse.y" /* yacc.c:1661  */
    {
		if((yyvsp[0].node)){
			(yyval.node) = new AsgBinaryNode((yyvsp[-1].node), (yyvsp[0].node));
			pool.add((yyval.node));
		}
		else{
			(yyval.node) = (yyvsp[-1].node);
			if((yyvsp[-1].node)){
				((yyval.node))->eval()->print();
			}
		}
	}
#line 2102 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 226 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2108 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 227 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2114 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 231 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2122 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 234 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0;}
#line 2128 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 237 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.intNum) = 1; }
#line 2134 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 238 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.intNum) = 2; }
#line 2140 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 239 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.intNum) = 3; }
#line 2146 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 240 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.intNum) = 4; }
#line 2152 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 241 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.intNum) = 5; }
#line 2158 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 242 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.intNum) = 0; }
#line 2164 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 243 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.intNum) = 0; }
#line 2170 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 244 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.intNum) = 0; }
#line 2176 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 245 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.intNum) = 0; }
#line 2182 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 246 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.intNum) = 0; }
#line 2188 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 247 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.intNum) = 6; }
#line 2194 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 248 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.intNum) = 7; }
#line 2200 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 252 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = (yyvsp[0].node);
		((yyvsp[0].node))->eval()->print();
	}
#line 2209 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 256 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2215 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 260 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2223 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 263 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2229 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 267 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = (yyvsp[-2].node);
	}
#line 2237 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 270 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2243 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 338 "includes/parse.y" /* yacc.c:1661  */
    {delete[] (yyvsp[-2].str); delete[] (yyvsp[0].str);}
#line 2249 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 339 "includes/parse.y" /* yacc.c:1661  */
    {delete[] (yyvsp[0].str);}
#line 2255 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 342 "includes/parse.y" /* yacc.c:1661  */
    {delete[] (yyvsp[0].str);}
#line 2261 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 117:
#line 358 "includes/parse.y" /* yacc.c:1661  */
    {delete[] (yyvsp[0].str);}
#line 2267 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 118:
#line 359 "includes/parse.y" /* yacc.c:1661  */
    {delete[] (yyvsp[0].str);}
#line 2273 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 119:
#line 362 "includes/parse.y" /* yacc.c:1661  */
    {delete[] (yyvsp[-1].str);}
#line 2279 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 120:
#line 365 "includes/parse.y" /* yacc.c:1661  */
    {delete[] (yyvsp[0].str);}
#line 2285 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 126:
#line 377 "includes/parse.y" /* yacc.c:1661  */
    {complexity++;}
#line 2291 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 127:
#line 378 "includes/parse.y" /* yacc.c:1661  */
    {complexity++;}
#line 2297 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 128:
#line 379 "includes/parse.y" /* yacc.c:1661  */
    {complexity++;}
#line 2303 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 136:
#line 391 "includes/parse.y" /* yacc.c:1661  */
    {complexity++;}
#line 2309 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 142:
#line 404 "includes/parse.y" /* yacc.c:1661  */
    { 
		if(isFinally)
		{
			complexity = old_complexity;
		}
		else
		{
			complexity++;
		}
		old_complexity = 0;
		isFinally = false;
	}
#line 2326 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 143:
#line 416 "includes/parse.y" /* yacc.c:1661  */
    { complexity = old_complexity;}
#line 2332 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 144:
#line 419 "includes/parse.y" /* yacc.c:1661  */
    { complexity++; }
#line 2338 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 145:
#line 420 "includes/parse.y" /* yacc.c:1661  */
    { complexity++; }
#line 2344 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 148:
#line 427 "includes/parse.y" /* yacc.c:1661  */
    { isFinally = true; }
#line 2350 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 173:
#line 479 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = (yyvsp[-1].node);
	}
#line 2358 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 174:
#line 482 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2364 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 175:
#line 485 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2370 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 176:
#line 486 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2376 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 177:
#line 490 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2384 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 178:
#line 493 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2390 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 179:
#line 497 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2398 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 180:
#line 500 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2404 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 181:
#line 503 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2410 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 182:
#line 505 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2418 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 183:
#line 511 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2426 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 184:
#line 514 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2432 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 196:
#line 531 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2440 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 197:
#line 534 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2446 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 198:
#line 538 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2454 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 199:
#line 541 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2460 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 200:
#line 545 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2468 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 201:
#line 548 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2474 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 202:
#line 552 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2482 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 203:
#line 555 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2488 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 206:
#line 563 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2496 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 207:
#line 567 "includes/parse.y" /* yacc.c:1661  */
    {
		if((yyvsp[-2].node) && (yyvsp[0].node)){
			switch((yyvsp[-1].oper)){
				case '+':
					(yyval.node) = new AddBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
					pool.add((yyval.node));
					break;
				case '-':
					(yyval.node) = new SubBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
					pool.add((yyval.node));
			}
		}
	}
#line 2514 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 208:
#line 583 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.oper) = '+';
	}
#line 2522 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 209:
#line 587 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.oper) = '-';
	}
#line 2530 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 210:
#line 593 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2538 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 211:
#line 597 "includes/parse.y" /* yacc.c:1661  */
    {
		switch((yyvsp[-1].oper)){
			case '*':
				(yyval.node) = new MulBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
				pool.add((yyval.node));
				break;
			case '/':
				(yyval.node) = new DivBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
				pool.add((yyval.node));
				break;
			case '%':
				(yyval.node) = new PerBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
				pool.add((yyval.node));
				break;
			case '|':
				(yyval.node) = new DbSlashBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
				pool.add((yyval.node));
		}
	}
#line 2562 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 212:
#line 619 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.oper) = '*';
	}
#line 2570 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 213:
#line 623 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.oper) = '/';
	}
#line 2578 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 214:
#line 627 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.oper) = '%';
	}
#line 2586 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 215:
#line 631 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.oper) = '|';
	}
#line 2594 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 216:
#line 637 "includes/parse.y" /* yacc.c:1661  */
    {
		if((yyvsp[0].node)){
			switch((yyvsp[-1].oper)){
				case '+':
					(yyval.node) = new PosUnaryNode((yyvsp[0].node));
					pool.add((yyval.node));
					break;
				case '-':
					(yyval.node) = new NegUnaryNode((yyvsp[0].node));
					pool.add((yyval.node));
					break;
				default :
					(yyval.node) = (yyvsp[0].node);
			}
		}
	}
#line 2615 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 217:
#line 654 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2623 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 218:
#line 657 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2629 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 219:
#line 661 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.oper) = '+';
	}
#line 2637 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 220:
#line 665 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.oper) = '-';
	}
#line 2645 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 221:
#line 669 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.oper) = '~';
	}
#line 2653 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 222:
#line 675 "includes/parse.y" /* yacc.c:1661  */
    {
		if((yyvsp[-3].node) && (yyvsp[0].node)){
			(yyval.node) = new DbStarBinaryNode((yyvsp[-3].node), (yyvsp[0].node));
			pool.add((yyval.node));
		}
	}
#line 2664 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 223:
#line 682 "includes/parse.y" /* yacc.c:1661  */
    {
		if(!(yyvsp[0].node)){
		    (yyval.node) = (yyvsp[-1].node);
		}
	}
#line 2674 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 225:
#line 690 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2680 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 226:
#line 693 "includes/parse.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2686 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 227:
#line 694 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0;}
#line 2692 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 228:
#line 695 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2698 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 229:
#line 696 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2704 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 230:
#line 698 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = new IdentNode((yyvsp[0].str));
		pool.add((yyval.node));
		delete[] (yyvsp[0].str);
	}
#line 2714 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 231:
#line 703 "includes/parse.y" /* yacc.c:1661  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2720 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 232:
#line 704 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2726 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 233:
#line 708 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = new FloatLiteral((yyvsp[0].fltNum)); 
        pool.add((yyval.node));
	}
#line 2735 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 234:
#line 713 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = new IntLiteral((yyvsp[0].intNum)); 
        pool.add((yyval.node)); 
	}
#line 2744 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 235:
#line 719 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2750 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 236:
#line 720 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2756 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 237:
#line 723 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2762 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 238:
#line 724 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2768 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 247:
#line 743 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2774 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 248:
#line 744 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2780 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 251:
#line 751 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2786 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 252:
#line 752 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2792 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 253:
#line 753 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; delete[] (yyvsp[0].str); }
#line 2798 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 271:
#line 790 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = (yyvsp[-2].node);
	}
#line 2806 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 272:
#line 794 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = (yyvsp[-1].node);
	}
#line 2814 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 281:
#line 815 "includes/parse.y" /* yacc.c:1661  */
    {delete[] (yyvsp[-5].str);}
#line 2820 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 282:
#line 816 "includes/parse.y" /* yacc.c:1661  */
    {delete[] (yyvsp[-2].str);}
#line 2826 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 285:
#line 824 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2834 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 292:
#line 842 "includes/parse.y" /* yacc.c:1661  */
    {
		(yyval.node) = (yyvsp[-1].node);
	}
#line 2842 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 293:
#line 845 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2848 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 294:
#line 846 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = 0; }
#line 2854 "parse.tab.c" /* yacc.c:1661  */
    break;

  case 295:
#line 849 "includes/parse.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2860 "parse.tab.c" /* yacc.c:1661  */
    break;


#line 2864 "parse.tab.c" /* yacc.c:1661  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
  return yyresult;
}
#line 893 "includes/parse.y" /* yacc.c:1906  */


#include <stdio.h>
void yyerror (const char *s)
{
    if(yylloc.first_line > 0)	{
        fprintf (stderr, "%d.%d-%d.%d:", yylloc.first_line, yylloc.first_column,
	                                     yylloc.last_line,  yylloc.last_column);
    }
    fprintf(stderr, " %s with [%s]\n", s, yytext);
}
void reverse(std::stack<func_info> stack)
{
	while(!stack.empty())
	{
		std::cout<<"(\""<<stack.top().line<<":"<<stack.top().column<<": \'"<<stack.top().name<<"\'\", "<<stack.top().complexity<<")"<<std::endl;
		stack.pop();	
	}
}
