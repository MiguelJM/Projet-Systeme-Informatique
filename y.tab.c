/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "analysgramAssExp.yacc" /* yacc.c:339  */

	#include <stdio.h>	
	#include <string.h>
	#include <stdbool.h>

	#include "symtab.h"
	#include "stack.h"

	int yylex(void);
	void yyerror(char *);

	char *address_Concat( char * );
	void insert_Instruction( char *, char *, char *, char *, char *, int );

	FILE *fp;	



#define instSIZE 8000 

	struct labelTable
	{
		char instruct[16];
		char  param1[16];		//@1
		char  param2[16];		//@2
		char  param3[16];		//@3
		char  comments[16];		//Comments of the line
	};

	struct errorTable
	{
		char error[128];
		int line;
	};

	;
	struct errorTable errTab[instSIZE];		//Stores found errors
	int ce = 0; //error counter

	struct labelTable labTab[instSIZE];		//Stores ASM instructions
	int cp = 0; //instruction counter
	int cp_Offset = 0; //Offset of the instruction counter

  	int tempCounter = 1; //Counter to determine if 0temp1 and 0temp2 are used

	struct stack if_stack;		//Keeps count of if statements to create labels
  	int if_lbl_count = 0; 		//Counter to determine the if labels to use

	char snum[5];		//To convert numbers to strings
	char auxString[16];	
	char auxString2[16];	

	int auxNum;	

	char retrievedString[64]; //Used to store user input in the printf instructions.
	char stringPrinter[4]; 	//Used to create the printf instructions.

#line 124 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    tINT = 258,
    tDIF = 259,
    tOR = 260,
    tAND = 261,
    tPO = 262,
    tPF = 263,
    tCO = 264,
    tCF = 265,
    tWHILE = 266,
    tPV = 267,
    tPLUS = 268,
    tVAR = 269,
    tSTRING = 270,
    tE = 271,
    tMAIN = 272,
    tSOU = 273,
    tMUL = 274,
    tDIV = 275,
    tPRINT = 276,
    tNUM = 277,
    tIF = 278,
    tV = 279,
    tCONST = 280,
    tGUILLEMETS = 281
  };
#endif
/* Tokens.  */
#define tINT 258
#define tDIF 259
#define tOR 260
#define tAND 261
#define tPO 262
#define tPF 263
#define tCO 264
#define tCF 265
#define tWHILE 266
#define tPV 267
#define tPLUS 268
#define tVAR 269
#define tSTRING 270
#define tE 271
#define tMAIN 272
#define tSOU 273
#define tMUL 274
#define tDIV 275
#define tPRINT 276
#define tNUM 277
#define tIF 278
#define tV 279
#define tCONST 280
#define tGUILLEMETS 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 59 "analysgramAssExp.yacc" /* yacc.c:355  */

	int nb;
	char * variable;

#line 221 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 236 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   110

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  27
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  38
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  89

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

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
      25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    98,    98,   101,   111,   112,   113,   114,   115,   116,
     119,   134,   152,   169,   169,   215,   219,   220,   223,   226,
     229,   230,   307,   311,   312,   313,   324,   335,   346,   357,
     368,   392,   404,   420,   435,   450,   465,   468,   469
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tINT", "tDIF", "tOR", "tAND", "tPO",
  "tPF", "tCO", "tCF", "tWHILE", "tPV", "tPLUS", "tVAR", "tSTRING", "tE",
  "tMAIN", "tSOU", "tMUL", "tDIV", "tPRINT", "tNUM", "tIF", "tV", "tCONST",
  "tGUILLEMETS", "$accept", "TestStart", "TestMessage", "Body", "Assign",
  "If", "$@1", "Cond", "While", "Print", "PrintCont", "Declar", "Val",
  "Expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281
};
# endif

#define YYPACT_NINF -41

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-41)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -17,    16,    26,   -41,   -41,    52,   -41,    52,   -41,   -41,
      19,    33,    40,   -41,    -7,     7,    56,   -41,    60,    64,
      30,    52,    52,     0,    65,    57,    80,    88,    29,   -41,
     -41,   -41,   -41,    -8,    84,    85,    78,    81,    52,    54,
      -5,    82,   -41,    30,   -41,    -1,   -41,   -41,    55,    83,
      89,    55,    86,    90,   -41,    66,   -41,    91,    34,    87,
      -8,    70,    55,    92,    62,   -41,   -41,   -41,    55,    55,
      55,    55,    74,    93,    -5,    55,    70,    30,   -41,    44,
      44,   -41,   -41,   -41,   -41,   -41,    70,    35,   -41
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     0,     1,     0,    32,    31,
       0,     0,     0,    13,     0,     0,     0,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       5,     6,     7,     4,     0,     0,    26,     0,     0,     0,
       0,     0,    14,     9,    23,     0,    16,    17,     0,    30,
       0,     0,    32,    31,    38,     0,    22,     0,     0,    28,
      24,    25,     0,     0,     0,    10,    11,    12,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,    37,    33,
      34,    35,    36,    21,    19,    20,    27,     0,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -41,   -41,   -41,   -20,   -41,   104,   -41,    -2,   -41,   -41,
      36,    63,    -4,   -40
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    43,    29,    30,    16,    10,    31,    32,
      58,    33,    54,    55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      28,    11,    23,    11,    44,    12,     1,     8,    61,    56,
      17,    64,    18,    19,    36,     9,    45,    11,    11,    34,
      35,    57,    76,     5,    27,    37,     6,    13,    79,    80,
      81,    82,    23,    23,    11,    86,    50,    14,    23,    42,
      24,    24,    73,    25,    25,    88,    24,    74,    15,    25,
      26,    26,     1,     1,    27,    27,    26,    87,     1,     7,
      27,    51,    51,    70,    71,    20,     8,    21,    52,     8,
      78,    22,    38,    39,     9,    68,    53,     9,    67,    68,
      69,    70,    71,    68,    69,    70,    71,    40,    69,    70,
      71,    41,    46,    47,    48,    49,    59,    63,    65,    62,
      83,    77,    66,    75,     4,    84,    72,     0,    60,     0,
      85
};

static const yytype_int8 yycheck[] =
{
      20,     5,     3,     7,    12,     7,    23,    14,    48,    14,
      14,    51,     5,     6,    14,    22,    24,    21,    22,    21,
      22,    26,    62,     7,    25,    25,     0,     8,    68,    69,
      70,    71,     3,     3,    38,    75,    38,     4,     3,    10,
      11,    11,     8,    14,    14,    10,    11,    13,     8,    14,
      21,    21,    23,    23,    25,    25,    21,    77,    23,     7,
      25,     7,     7,    19,    20,     9,    14,     7,    14,    14,
       8,     7,     7,    16,    22,    13,    22,    22,    12,    13,
      18,    19,    20,    13,    18,    19,    20,     7,    18,    19,
      20,     3,     8,     8,    16,    14,    14,     8,    12,    16,
      26,     9,    12,    16,     0,    12,    15,    -1,    45,    -1,
      74
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,    28,    29,    32,     7,     0,     7,    14,    22,
      34,    39,    34,     8,     4,     8,    33,    39,     5,     6,
       9,     7,     7,     3,    11,    14,    21,    25,    30,    31,
      32,    35,    36,    38,    34,    34,    14,    25,     7,    16,
       7,     3,    10,    30,    12,    24,     8,     8,    16,    14,
      34,     7,    14,    22,    39,    40,    14,    26,    37,    14,
      38,    40,    16,     8,    40,    12,    12,    12,    13,    18,
      19,    20,    15,     8,    13,    16,    40,     9,     8,    40,
      40,    40,    40,    26,    12,    37,    40,    30,    10
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    27,    28,    29,    30,    30,    30,    30,    30,    30,
      31,    31,    31,    33,    32,    34,    34,    34,    35,    36,
      37,    37,    37,    38,    38,    38,    38,    38,    38,    38,
      38,    39,    39,    40,    40,    40,    40,    40,    40
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     0,     8,     3,     7,     7,     7,     5,
       3,     3,     1,     2,     3,     4,     2,     5,     3,     5,
       3,     1,     1,     3,     3,     3,     3,     3,     1
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 101 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n Succesful test");}
#line 1367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 119 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
										if( lookupType((yyvsp[-3].variable)) != -1 && lookupType((yyvsp[-1].variable)) != -1 ) //Both variables exist
										{									
										    fprintf(fp, "mov [%s], [%s]\n", (yyvsp[-3].variable), (yyvsp[-1].variable)); 	//a = b

										    insert_Instruction( "mov", address_Concat((yyvsp[-3].variable)), address_Concat((yyvsp[-1].variable)), "", "", cp );
										    cp++;			
										}
										else
										{
											strcpy( errTab[ce].error, "Trying to assign value to a constant.\n" );
											errTab[ce].line = ce;
											ce++;
										}	
									}
#line 1387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 134 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
										if( lookupType((yyvsp[-3].variable)) != -1 ) 	
										{									
										    fprintf(fp, "mov [%s], %d\n", (yyvsp[-3].variable), (yyvsp[-1].nb)); 	//a = 4

										    //convert num to string			
											sprintf(snum ,"%d" , (yyvsp[-1].nb));

										    insert_Instruction( "mov", address_Concat((yyvsp[-3].variable)), snum, "", "", cp );
										    cp++;			
										}
										else
										{
											strcpy( errTab[ce].error, "Trying to assign value to a constant.\n" );
											errTab[ce].line = ce;
											ce++;
										}	
									}
#line 1410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 152 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
										if(lookupType((yyvsp[-3].variable)) != -1)	
										{									
										    fprintf(fp, "mov [%d], eax\n", lookup((yyvsp[-3].variable))); 	//a = Resultado

										    insert_Instruction( "mov", address_Concat((yyvsp[-3].variable)), "eax", "", "", cp );
										    cp++;			
										}
										else
										{
											strcpy( errTab[ce].error, "Trying to assign value to a constant.\n" );
											errTab[ce].line = ce;
											ce++;
										}
									}
#line 1430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 169 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
										printf("Counter = %d", cp);
									 	(yyvsp[-3].nb) = cp;		//If is inserted the execution of the body but its instruction is inserted here
										cp++;    		//Jx	
										cp++;			//JMP instruction goes here (used in case if statement is not approved)	
										cp++;			//If label goes here (used in case if statement is approved)

										if_stack = push(if_lbl_count, if_stack);	//Insert if label value to 										
										if_lbl_count++;				
									}
#line 1445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 179 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
									//convert num to string		

									auxNum = if_stack.stk[if_stack.top];	//take if label value from the stack	
									if_stack = pop(if_stack);				//pop the value	

									//create string if_lbl_n for Jx						//Assign the correct Jx: Je, Jg, etc... ************************
									strcpy( auxString, "if_lbl_" );										
									sprintf(snum , "%d", auxNum);	
									strcat( auxString, snum );
									strcat( auxString, ":" );	
									insert_Instruction( "Jx", auxString, "", "", "", (yyvsp[-7].nb) );		//Jx To ($1 stores the pointer before if began)

									//create string else_lbl_n for JMP
									strcpy( auxString, "else_lbl_" );										
									sprintf(snum , "%d", auxNum);	
									strcat( auxString, snum );
									insert_Instruction( "JMP", auxString, "", "", "", (yyvsp[-7].nb)+1 );	//JMP TO		

									//create string if_lbl_n for if lbl
									strcpy( auxString, "if_lbl_" );										
									sprintf(snum , "%d", auxNum);	
									strcat( auxString, snum );
									strcat( auxString, ":" );
									insert_Instruction( auxString, "", "", "", "", (yyvsp[-7].nb)+2 );	//If label	

									//create string else_lbl_n	for else lbl
									strcpy( auxString, "else_lbl_" );									
									sprintf(snum , "%d", auxNum);	
									strcat( auxString, snum );
									strcat( auxString, ":" );		//Else label
									insert_Instruction( auxString, "", "", "", "", cp );	//insert else label at the end of the if
									cp++;			
								}
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 215 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {									
									insert_Instruction( "CMP", "", "", "", "", cp );	//JMP FROM TO	
									cp++;
								}
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 219 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n Condition trouvee");}
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 220 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n Condition trouvee");}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 223 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n While trouve");}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 226 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n Print trouve");}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 229 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n Contenu du Print trouve");}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 230 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {	
														//TODO: Add \n management
														int mod;

														strcpy( retrievedString, (yyvsp[-1].variable) ); 
														strcpy( stringPrinter, "'" ); 	
														int count = 0, count2 = 0;

														sprintf(snum, "%d", (int) strlen(retrievedString));
														strcpy( auxString, snum );
														insert_Instruction( "MOV", "edx", auxString, "", "Message length", cp );	//Message length
														cp++;

														while( retrievedString[count] != '\0')
														{
															stringPrinter[count2] = retrievedString[count];  

															if( count2 == 3 )		//Print every 4 characters to respect dword size
															{
																//Create string with printf_MSG+count+1
    															strcpy( auxString, "printf_MSG+" );
																sprintf(snum, "%d", count-count2);	
    															strcat( auxString, snum );

																//Create string with dword stringPrinter[0]+[1]+[2]+[3]
    															strcpy( auxString2, "dword " );
    															stringPrinter[count2+1] = '\0';
    															strcat( auxString2, stringPrinter );

																insert_Instruction( "MOV", address_Concat(auxString), auxString2, "", "New message", cp );	//Message[0,1,2,3]
																cp++;	
																count2 = 0;
															}
															else{
																count2 ++;	
															}														

															count ++;
														}

														if( count2 > 0 )
														{
															/*if( retrievedString[count] == '\' && retrievedString[count+1] == 'n' )  //New line detected
															{
																count++;
																auxString
																insert_Instruction( "MOV", address_Concat("printf_MSG+count+1"), "dword + stringPrinter", "", "New message", cp );	//add new line
																	cp++;
															}*/

															//Create string with printf_MSG+count+1
    														strcpy( auxString, "printf_MSG+" );
															sprintf(snum, "%d", count-count2);		
    														strcat( auxString, snum );

															//Create string with dword stringPrinter[0]+[1]+[2]+[3]
    														strcpy( auxString2, "dword " );
    														stringPrinter[count2] = '\0';
    														strcat( auxString2, stringPrinter );

															insert_Instruction( "MOV", address_Concat(auxString), auxString2, "", "New message", cp );	//Message[0,1,2,3]
															cp++;													

															count ++;
															count2 ++;
														}

														insert_Instruction( "MOV", "ecx", "printf_MSG", "", "Message to write", cp );	
														cp++;	
														insert_Instruction( "MOV", "ebx", "1", "", "file descriptor (stdout)", cp );	
														cp++;	
														insert_Instruction( "MOV", "eax", "4", "", "Message to write", cp );
														cp++;	
														insert_Instruction( "INT", "80h", "", "", "System call (Call Kernel)", cp );	//Call Kernel
														cp++;	
		
													}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 307 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n Contenu du Print trouve");}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 311 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n Declaration trouvee");}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 312 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n Declaration trouvee");}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 313 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {				
											if(lookup((yyvsp[-2].variable)) == -1)
											{
												insert((yyvsp[-2].variable), 0);
											}else
											{												
												strcpy( errTab[ce].error, "Variable %s already exists.\n" );
												errTab[ce].line = ce;
												ce++;
											}
										}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 324 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
											if(lookup((yyvsp[0].variable)) == -1)
											{
												insert((yyvsp[0].variable), 0);
											}else
											{												
												strcpy( errTab[ce].error, "Variable already exists.\n" );
												errTab[ce].line = ce;
												ce++;
											}
										}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 335 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
												if(lookup((yyvsp[-2].variable)) == -1)
												{
													insert((yyvsp[-2].variable), 1);
												}else
												{												
													strcpy( errTab[ce].error, "Variable already exists.\n" );
													errTab[ce].line = ce;
													ce++;
												}
											}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 346 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
												if(lookup((yyvsp[0].variable)) == -1)
												{
													insert((yyvsp[0].variable), 1);
												}else
												{												
													strcpy( errTab[ce].error, "Variable already exists.\n" );
													errTab[ce].line = ce;
													ce++;
												}
											}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 357 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
												if(lookup((yyvsp[-2].variable)) == -1)
												{
													insert((yyvsp[-2].variable), 1);
												}else
												{												
													strcpy( errTab[ce].error, "Variable already exists.\n" );
													errTab[ce].line = ce;
													ce++;
												}
											}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 368 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
												if(lookup((yyvsp[0].variable)) == -1)
												{
													insert((yyvsp[0].variable), 1);
												}else
												{												
													strcpy( errTab[ce].error, "Variable already exists.\n" );
													errTab[ce].line = ce;
													ce++;
												}
											}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 392 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
								if( tempCounter == 1 )
								{
									tempCounter = 2;
									(yyval.nb)=lookup("0temp1");	
								}		
								else
								{
									tempCounter = 1;
									(yyval.nb)=lookup("0temp2");	
								}
							}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 404 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {	
								if(lookup((yyvsp[0].variable)) != -1)
								{
									(yyval.nb)=lookup((yyvsp[0].variable));			
								}
								else
								{
									strcpy( errTab[ce].error, "The variable " );
									strcat( errTab[ce].error, (yyvsp[0].variable) );
									strcat( errTab[ce].error, " does not exist.\n" );		
									errTab[ce].line = ce;
									ce++;
								}
							 }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 420 "analysgramAssExp.yacc" /* yacc.c:1646  */
    { 	
										fprintf(fp, "mov eax, [%d]\n", (yyvsp[-2].nb)); //eax = [a/0temp1]
										 insert_Instruction( "mov", "eax", address_Concat(lookupName((yyvsp[-2].nb))), "", "", cp );
										 cp++;			
									    fprintf(fp, "mov ebx, [%d]\n", (yyvsp[0].nb)); //ebx = [b/0temp2]
										 insert_Instruction( "mov", "ebx", address_Concat(lookupName((yyvsp[0].nb))), "", "", cp );
									     cp++;

									    fprintf(fp, "add eax, ebx\n"); 		//eax = eax + ebx
										 insert_Instruction( "add", "eax", "ebx", "", "", cp );
									     cp++;

										tempCounter = 2;					//Como se evaluaron dos expresiones, se coloca en 0temp2
										printf("\n Somme trouvee");
									}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 435 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {	
										fprintf(fp, "mov eax, [%d]\n", (yyvsp[-2].nb)); //eax = [a/0temp1]
										 insert_Instruction( "mov", "eax", address_Concat(lookupName((yyvsp[-2].nb))), "", "", cp );
										 cp++;			
									    fprintf(fp, "mov ebx, [%d]\n", (yyvsp[0].nb)); //ebx = [b/0temp2]
										 insert_Instruction( "mov", "ebx", address_Concat(lookupName((yyvsp[0].nb))), "", "", cp );
									     cp++;

									    fprintf(fp, "sub eax, ebx\n"); 		//eax - ebx
										 insert_Instruction( "sub", "eax", "ebx", "", "", cp );
									     cp++;

										tempCounter = 2;					//Como se evaluaron dos expresiones, se coloca en temp2 
										printf("\n Substraction trouvee");
									}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 450 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {	
										fprintf(fp, "mov ax, [%d]\n", (yyvsp[-2].nb)); //ax = [a/0temp1]
										 insert_Instruction( "mov", "eax", address_Concat(lookupName((yyvsp[-2].nb))), "", "", cp );
										 cp++;			
									    fprintf(fp, "mov bx, [%d]\n", (yyvsp[0].nb)); //bx = [b/0temp2]
										 insert_Instruction( "mov", "ebx", address_Concat(lookupName((yyvsp[0].nb))), "", "", cp );
									     cp++;

									    fprintf(fp, "mul bx\n"); 			//ax * bx
										 insert_Instruction( "mul", "bx", "", "", "", cp );
									     cp++;

										tempCounter = 2;					//Como se evaluaron dos expresiones, se coloca en temp2 
										printf("\n Multiplication trouvee");
									}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 465 "analysgramAssExp.yacc" /* yacc.c:1646  */
    { 
											fprintf(fp, "\nFirst number : \n"); 
									}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1827 "y.tab.c" /* yacc.c:1646  */
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 478 "analysgramAssExp.yacc" /* yacc.c:1906  */


void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

/*Error management*/
void print_Error_Table()
{
	if( ce > 0 )
		fprintf(fp, "\nErrors found : \n");
	for (int i = 0 ; i < ce; i++)
		fprintf(fp, "Error found in line: %d \n %s \n", errTab[i].line+1, errTab[i].error );

}
/*End of error management*/




/*Label Table Management*/
void print_Label_Table()
{
  	fprintf(fp,"\nLabel Table :\n----------------------------------------------------- \n");
	fprintf(fp, " Instruction | param1 | param2 | param 3 | comments |\n");
  	fprintf(fp,"----------------------------------------------------- \n");
	for (int i = 0 ; i < cp; i++)
	{
		fprintf(fp, " %-14s %-12s %-12s %-12s ;%-s \n", labTab[i].instruct, labTab[i].param1, labTab[i].param2, labTab[i].param3, labTab[i].comments );
	}
}

char* address_Concat( char *varName ) //concatenates [] with the address: the result is similar to: [a]
{
	char *result = malloc(16 * sizeof(char));
	strcat(result, "[");
	strcat(result, varName);
	strcat(result, "]");

	return result;	
}

void insert_Instruction( char *inst, char *p1, char *p2, char *p3, char *comment, int counter  )	//inserts all values to the table
{
	strcpy( labTab[counter].instruct, inst );
	strcpy( labTab[counter].param1, p1 );	  
	strcpy( labTab[counter].param2, p2 );	  
	strcpy( labTab[counter].param3, p3 );	  
	strcpy( labTab[counter].comments, comment );
}
/*End of label Table Management*/






int main(void) {


	//Instruction (label) table
	int **lableTable = malloc(instSIZE * 4 * sizeof(int));

	//Initialization of the label table
	int i;
	for(i = 0; i < instSIZE; i++)
	    lableTable[i] = malloc(4 * sizeof(int));


	printf("\nParser V2.0\n\n");

	fp = fopen("assOutput.out","w");


	insert("0temp1", 0);	//Temp variables inserted with number before to avoid conflict with user create variables	
	insert("0temp2", 0);




	/*insertSymbol("a", 1, 10);
	insertSymbol("a", 0, 10);
	assignValue("a", 11);*/


	//lookup("a");
	insert("a", 0);
	insert("b", 0);
	/*lookup("a");
	insert("a", 0);
	lookupType("a");
	insert("b", 0);
	insert("c", 1);
	insert("d", 0);
	insert("e", 1);
	insert("g", 1);
	insert("arnold", 0);
	insert("arnoldo", 0);
	lookup("arnold");
	lookup("e");*/


	yyparse();
	symtab_print(fp);
	print_Label_Table();
	print_Error_Table();
	fprintf(fp, "Number of lines : %d\n", cp+1); 
	fclose(fp);
	return 0;
}




/*TODO: Users can't name a variable 0temp1 nor 0temp2*/
