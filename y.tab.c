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
	struct stack else_stack;		//Keeps count of else statements to create labels
  	int if_lbl_count = 0; 		//Counter to determine the if labels to use

	char snum[5];		//To convert numbers to strings
	char auxString[32];	
	char auxString2[32];

	char last_if_type[8]; //Returns the last type of if retrieved	

	int auxNum;	

	char retrievedString[64]; //Used to store user input in the printf instructions.
	char stringPrinter[4]; 	//Used to create the printf instructions.

#line 127 "y.tab.c" /* yacc.c:339  */

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
    tMIN = 259,
    tMAY = 260,
    tMINEQU = 261,
    tMAYEQU = 262,
    tEQU = 263,
    tDIF = 264,
    tOR = 265,
    tAND = 266,
    tPO = 267,
    tPF = 268,
    tCO = 269,
    tCF = 270,
    tWHILE = 271,
    tPV = 272,
    tPLUS = 273,
    tVAR = 274,
    tSTRING = 275,
    tE = 276,
    tMAIN = 277,
    tSOU = 278,
    tMUL = 279,
    tDIV = 280,
    tPRINT = 281,
    tNUM = 282,
    tIF = 283,
    tV = 284,
    tCONST = 285,
    tGUILLEMETS = 286,
    tELSE = 287
  };
#endif
/* Tokens.  */
#define tINT 258
#define tMIN 259
#define tMAY 260
#define tMINEQU 261
#define tMAYEQU 262
#define tEQU 263
#define tDIF 264
#define tOR 265
#define tAND 266
#define tPO 267
#define tPF 268
#define tCO 269
#define tCF 270
#define tWHILE 271
#define tPV 272
#define tPLUS 273
#define tVAR 274
#define tSTRING 275
#define tE 276
#define tMAIN 277
#define tSOU 278
#define tMUL 279
#define tDIV 280
#define tPRINT 281
#define tNUM 282
#define tIF 283
#define tV 284
#define tCONST 285
#define tGUILLEMETS 286
#define tELSE 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 62 "analysgramAssExp.yacc" /* yacc.c:355  */

	int nb;
	char * variable;

#line 236 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 251 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   118

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  107

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   108,   108,   111,   121,   122,   123,   124,   125,   126,
     129,   145,   165,   182,   182,   188,   188,   250,   266,   271,
     271,   302,   302,   342,   345,   348,   351,   354,   357,   362,
     377,   385,   389,   396,   399,   402,   403,   480,   484,   485,
     486,   497,   508,   519,   530,   541,   565,   577,   593,   608,
     623,   638,   641,   642
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tINT", "tMIN", "tMAY", "tMINEQU",
  "tMAYEQU", "tEQU", "tDIF", "tOR", "tAND", "tPO", "tPF", "tCO", "tCF",
  "tWHILE", "tPV", "tPLUS", "tVAR", "tSTRING", "tE", "tMAIN", "tSOU",
  "tMUL", "tDIV", "tPRINT", "tNUM", "tIF", "tV", "tCONST", "tGUILLEMETS",
  "tELSE", "$accept", "TestStart", "TestMessage", "Body", "Assign", "If",
  "$@1", "$@2", "Else", "Cond", "$@3", "$@4", "CompareToken",
  "CondValueEAX", "CondValueEBX", "While", "Print", "PrintCont", "Declar",
  "Val", "Expr", YY_NULLPTR
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
     285,   286,   287
};
# endif

#define YYPACT_NINF -56

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-56)))

#define YYTABLE_NINF -14

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -22,     8,    40,   -56,    10,     5,   -56,    14,     5,   -56,
     -56,    42,    86,    53,   -56,    58,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,    32,    22,     1,    72,   -56,   -56,   -56,
     -12,    84,    76,    87,    95,     7,   -56,    10,   -56,   -56,
     -13,   -56,   -56,    22,    79,    82,     5,    41,    26,    83,
     -56,    22,   -56,     6,    91,    92,    28,    54,    85,    94,
      54,    88,    93,   -56,    60,   -56,    89,    57,    90,   -13,
       5,     5,   -56,   -56,   -56,    64,    54,    98,   -10,   -56,
     -56,   -56,    54,    54,    54,    54,    77,    96,    26,    54,
     101,   102,    64,    22,   -56,    55,    55,   -56,   -56,   -56,
     -56,   -56,    64,   -56,   -56,    46,   -56
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     0,     1,     0,     0,    29,
      30,     0,     0,     0,    14,     0,    15,    23,    24,    28,
      27,    25,    26,     0,     0,     0,     0,    31,    32,    18,
       0,     0,     0,     0,     0,     0,     8,     5,     6,     7,
       4,    19,    21,     0,    41,     0,     0,     0,     0,     0,
      17,     9,    38,     0,     0,     0,     0,     0,    45,     0,
       0,    47,    46,    53,     0,    37,     0,     0,    43,    39,
       0,     0,    16,    47,    46,    40,     0,     0,     0,    10,
      11,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,     0,    52,    48,    49,    50,    51,    36,
      34,    35,    42,    20,    22,     0,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -56,   -56,   -56,   -24,   -56,   116,   -56,   -56,   -56,    -7,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,    29,    65,   -56,
     -55
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    51,    36,    37,     7,    26,    14,    11,
      54,    55,    23,    12,    29,    38,    39,    67,    40,    63,
      64
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      35,    15,    75,    94,    52,    78,     1,    44,    82,    30,
      30,    41,    42,    83,    84,    85,    53,     8,    45,    56,
       5,    92,    50,    31,     9,    30,    32,    95,    96,    97,
      98,    30,    10,    33,   102,     1,    34,    34,    31,    59,
       6,    32,   -13,    72,    31,    65,    13,    32,    33,    30,
       1,    27,    34,    60,    33,    16,     1,    66,    34,    28,
      61,   106,    31,    90,    91,    32,    60,    24,    62,   105,
      87,    25,    33,    73,     1,    88,    34,    81,    82,    84,
      85,    74,    82,    83,    84,    85,    43,    83,    84,    85,
      17,    18,    19,    20,    21,    22,    46,    47,    49,    48,
      57,    58,    68,    70,    71,    79,    76,    77,    99,    86,
      80,    89,    93,   100,   103,   104,     4,   101,    69
};

static const yytype_uint8 yycheck[] =
{
      24,     8,    57,    13,    17,    60,    28,    19,    18,     3,
       3,    10,    11,    23,    24,    25,    29,    12,    30,    43,
      12,    76,    15,    16,    19,     3,    19,    82,    83,    84,
      85,     3,    27,    26,    89,    28,    30,    30,    16,    46,
       0,    19,    32,    15,    16,    19,    32,    19,    26,     3,
      28,    19,    30,    12,    26,    13,    28,    31,    30,    27,
      19,    15,    16,    70,    71,    19,    12,    14,    27,    93,
      13,    13,    26,    19,    28,    18,    30,    17,    18,    24,
      25,    27,    18,    23,    24,    25,    14,    23,    24,    25,
       4,     5,     6,     7,     8,     9,    12,    21,     3,    12,
      21,    19,    19,    12,    12,    17,    21,    13,    31,    20,
      17,    21,    14,    17,    13,    13,     0,    88,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    34,    35,    38,    12,     0,    39,    12,    19,
      27,    42,    46,    32,    41,    42,    13,     4,     5,     6,
       7,     8,     9,    45,    14,    13,    40,    19,    27,    47,
       3,    16,    19,    26,    30,    36,    37,    38,    48,    49,
      51,    10,    11,    14,    19,    30,    12,    21,    12,     3,
      15,    36,    17,    29,    43,    44,    36,    21,    19,    42,
      12,    19,    27,    52,    53,    19,    31,    50,    19,    51,
      12,    12,    15,    19,    27,    53,    21,    13,    53,    17,
      17,    17,    18,    23,    24,    25,    20,    13,    18,    21,
      42,    42,    53,    14,    13,    53,    53,    53,    53,    31,
      17,    50,    53,    13,    13,    36,    15
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    36,    36,    36,    36,    36,    36,
      37,    37,    37,    39,    38,    40,    38,    41,    42,    43,
      42,    44,    42,    45,    45,    45,    45,    45,    45,    46,
      46,    47,    47,    48,    49,    50,    50,    50,    51,    51,
      51,    51,    51,    51,    51,    51,    52,    52,    53,    53,
      53,    53,    53,    53
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     0,     3,     0,     8,     4,     3,     0,
       8,     0,     8,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     7,     5,     3,     3,     1,     2,     3,
       4,     2,     5,     3,     5,     3,     1,     1,     3,     3,
       3,     3,     3,     1
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
#line 111 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n Succesful test");}
#line 1399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 129 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
										if( lookupType((yyvsp[-3].variable)) != -1 && lookupType((yyvsp[-1].variable)) != -1 ) //Both variables exist
										{									
										    fprintf(fp, "mov [%s], [%s]\n", (yyvsp[-3].variable), (yyvsp[-1].variable)); 	//a = b
										    insert_Instruction( "mov", "eax", address_Concat((yyvsp[-1].variable)), "", "", cp );
										    cp++;	
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
#line 1420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 145 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
										if( lookupType((yyvsp[-3].variable)) != -1 ) 	
										{									
										    fprintf(fp, "mov [%s], %d\n", (yyvsp[-3].variable), (yyvsp[-1].nb)); 	//a = 4
										    
										    //convert num to string			
											sprintf(snum ,"%d" , (yyvsp[-1].nb));

										    insert_Instruction( "mov", "eax", snum, "", "", cp );
										    cp++;	
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
#line 1445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 165 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 182 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
								//Erease the JMP else steps to build the else statement
								else_stack = push(if_lbl_count-1, else_stack);	//Insert else label value to 
								cp--;											//Erease the JMP ignore_else to write it later
							}
#line 1475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 188 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
									 	(yyvsp[-3].nb) = cp;		//If is inserted the execution of the body but its instruction is inserted here
										cp++;    		//Jx	
										cp++;			//JMP instruction goes here (used in case if statement is not approved)	
										cp++;			//If label goes here (used in case if statement is approved)

										if_stack = push(if_lbl_count, if_stack);		//Insert if label value to 	
										else_stack = push(if_lbl_count, else_stack);	//Insert else label value to 									
										if_lbl_count++;				
								}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 198 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
									//convert num to string		

									auxNum = if_stack.stk[if_stack.top];	//take if label value from the stack	
									if_stack = pop(if_stack);					//pop the value	
									else_stack = pop(else_stack);				//pop the value	

									//create string if_lbl_n for Jx						//Assign the correct Jx: Je, Jg, etc... ************************
									strcpy( auxString, "if_lbl_" );										
									sprintf(snum , "%d", auxNum);	
									strcat( auxString, snum );
									insert_Instruction( last_if_type, auxString, "", "", "", (yyvsp[-7].nb) );		//Jx To ($1 stores the pointer before if began)

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

									//Put a JMP to jump the else statement after if Body 			**********
									strcpy( auxString, "else_lbl_" );										
									sprintf(snum , "%d", auxNum);	
									strcat( auxString, snum );
									strcat( auxString, "_ignr" );
									insert_Instruction( "JMP", auxString, "", "", "", cp );	//Ignore else label	
									cp++;

									//create string else_lbl_n	for else lbl
									strcpy( auxString, "else_lbl_" );									
									sprintf(snum , "%d", auxNum);	
									strcat( auxString, snum );
									strcat( auxString, ":" );		//Else label
									insert_Instruction( auxString, "", "", "", "", cp );	//insert else label at the end of the if
									cp++;	

									//Put a JMP label at the end of the else body
									strcpy( auxString, "else_lbl_" );										
									sprintf(snum , "%d", auxNum);	
									strcat( auxString, snum );
									strcat( auxString, "_ignr:" );
									insert_Instruction( auxString, "", "", "", "", cp );	//Ignore else label	
									cp++;		
								}
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 250 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {		
									auxNum = else_stack.stk[else_stack.top];	//take if label value from the stack	
									else_stack = pop(else_stack);				//pop the value	

									//Put a JMP label at the end of the else body
									strcpy( auxString, "else_lbl_" );										
									sprintf(snum , "%d", auxNum);	
									strcat( auxString, snum );
									strcat( auxString, "_ignr:" );
									insert_Instruction( auxString, "", "", "", "", cp );	//If label	
									cp++;	
								}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 266 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {									
																insert_Instruction( "CMP", "eax", "ebx", "", "", cp );	//COMPARISSON	
																cp++;
																strcpy (last_if_type, (yyvsp[-1].variable));
															}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 271 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
												/**If true jump to if body**/

												//create string if_lbl_n for if lbl
												strcpy( auxString, "if_lbl_" );										
												sprintf(snum , "%d", if_lbl_count);	
												strcat( auxString, snum );		
												insert_Instruction( last_if_type, auxString, "", "", "", cp );	//IF	
												cp++;
										}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 281 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
				 						/**If true jump to if body**/

										//create string if_lbl_n for if lbl
										strcpy( auxString, "if_lbl_" );										
										sprintf(snum , "%d", if_lbl_count);	
										strcat( auxString, snum );		
										insert_Instruction( last_if_type, auxString, "", "", "", cp );	//IF	
										cp++;

										//jmp to else body 				
				 						
										//create string if_lbl_n for if lbl
										strcpy( auxString, "else_lbl_" );										
										sprintf(snum , "%d", if_lbl_count);	
										strcat( auxString, snum );		
										insert_Instruction( "JMP", auxString, "", "", "", cp );	//IF	
										cp++;

										(yyval.variable)=last_if_type;	//return last if 
									}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 302 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
										/**If true jump to next if**/

										//create string if_lbl_n for if lbl
										strcpy( auxString, "$+4" );			
										insert_Instruction( last_if_type, auxString, "", "", "", cp );	//IF	
										cp++;

										//jmp to else body 				
				 						
										//create string if_lbl_n for if lbl
										strcpy( auxString, "else_lbl_" );										
										sprintf(snum , "%d", if_lbl_count);	
										strcat( auxString, snum );		
										insert_Instruction( "JMP", auxString, "", "", "", cp );	//IF	
										cp++;
									}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 319 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
										/**If true jump to if body**/

										//create string if_lbl_n for if lbl
										strcpy( auxString, "if_lbl_" );										
										sprintf(snum , "%d", if_lbl_count);	
										strcat( auxString, snum );		
										insert_Instruction( last_if_type, auxString, "", "", "", cp );	//IF	
										cp++;

										//jmp to else body 				
				 						
										//create string if_lbl_n for if lbl
										strcpy( auxString, "else_lbl_" );										
										sprintf(snum , "%d", if_lbl_count);	
										strcat( auxString, snum );		
										insert_Instruction( "JMP", auxString, "", "", "", cp );	//IF	
										cp++;

										(yyval.variable)=last_if_type;	//return last if 
									}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 342 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
							(yyval.variable)="JL";
						}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 345 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
							(yyval.variable)="JG";
						}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 348 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
							(yyval.variable)="JE";
						}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 351 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
							(yyval.variable)="JNE";
						}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 354 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
							(yyval.variable)="JGE";
						}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 357 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
							(yyval.variable)="JLE";
						}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 362 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {		
								if(lookup((yyvsp[0].variable)) != -1)
								{		
									insert_Instruction( "MOV", "eax", address_Concat((yyvsp[0].variable)), "", "", cp );	 //mov eax, [var] 	
									cp++;			
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
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 377 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {		
								sprintf(snum, "%d", (yyvsp[0].nb));
								insert_Instruction( "MOV", "eax", snum, "", "", cp );	 //mov eax, num	
								cp++;
							}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 385 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {						
								insert_Instruction( "MOV", "ebx", address_Concat((yyvsp[0].variable)), "", "", cp );	 //mov eax, [var] 	
								cp++;
							}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 389 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {		
								sprintf(snum, "%d", (yyvsp[0].nb));
								insert_Instruction( "MOV", "ebx", snum, "", "", cp );	 //mov eax, num	
								cp++;
							}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 396 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n While trouve");}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 399 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n Print trouve");}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 402 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n Contenu du Print trouve");}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 403 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 480 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n Contenu du Print trouve");}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 484 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n Declaration trouvee");}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 485 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n Declaration trouvee");}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 486 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 497 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 508 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 519 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 530 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 541 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 565 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 577 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 593 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 608 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 623 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 638 "analysgramAssExp.yacc" /* yacc.c:1646  */
    { 
											fprintf(fp, "\nFirst number : \n"); 
									}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2080 "y.tab.c" /* yacc.c:1646  */
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
#line 651 "analysgramAssExp.yacc" /* yacc.c:1906  */


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
