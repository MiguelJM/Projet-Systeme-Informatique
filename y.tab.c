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

	struct stack while_stack;		//Keeps count of while statements to create labels
  	int while_lbl_count = 0; 		//Counter to determine the while labels to use

	char snum[5];		//To convert numbers to strings
	char auxString[32];	
	char auxString2[32];

	char last_if_type[8]; 	 //Returns the last type of if retrieved	
	char last_while_type[8]; //Returns the last type of while retrieved

	int auxNum;	

	char retrievedString[64]; //Used to store user input in the printf instructions.
	char stringPrinter[4]; 	//Used to create the printf instructions.

#line 131 "y.tab.c" /* yacc.c:339  */

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
    tPV = 271,
    tPLUS = 272,
    tVAR = 273,
    tSTRING = 274,
    tE = 275,
    tMAIN = 276,
    tSOU = 277,
    tMUL = 278,
    tDIV = 279,
    tPRINT = 280,
    tNUM = 281,
    tIF = 282,
    tWHILE = 283,
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
#define tPV 271
#define tPLUS 272
#define tVAR 273
#define tSTRING 274
#define tE 275
#define tMAIN 276
#define tSOU 277
#define tMUL 278
#define tDIV 279
#define tPRINT 280
#define tNUM 281
#define tIF 282
#define tWHILE 283
#define tV 284
#define tCONST 285
#define tGUILLEMETS 286
#define tELSE 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 66 "analysgramAssExp.yacc" /* yacc.c:355  */

	int nb;
	char * variable;

#line 240 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 255 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

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
       0,   111,   111,   114,   124,   125,   126,   127,   128,   129,
     132,   148,   168,   185,   185,   191,   191,   253,   269,   274,
     274,   305,   305,   348,   353,   353,   384,   384,   427,   430,
     433,   436,   439,   442,   447,   462,   470,   485,   492,   505,
     492,   563,   566,   567,   644,   648,   649,   650,   661,   672,
     683,   694,   705,   718,   718,   729,   744,   761,   776,   791,
     806,   809,   810
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tINT", "tMIN", "tMAY", "tMINEQU",
  "tMAYEQU", "tEQU", "tDIF", "tOR", "tAND", "tPO", "tPF", "tCO", "tCF",
  "tPV", "tPLUS", "tVAR", "tSTRING", "tE", "tMAIN", "tSOU", "tMUL", "tDIV",
  "tPRINT", "tNUM", "tIF", "tWHILE", "tV", "tCONST", "tGUILLEMETS",
  "tELSE", "$accept", "TestStart", "TestMessage", "Body", "Assign", "If",
  "$@1", "$@2", "Else", "Cond", "$@3", "$@4", "CondWhile", "$@5", "$@6",
  "CompareToken", "CondValueEAX", "CondValueEBX", "While", "$@7", "$@8",
  "Print", "PrintCont", "Declar", "Main", "$@9", "Val", "Expr", YY_NULLPTR
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

#define YYPACT_NINF -77

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-77)))

#define YYTABLE_NINF -14

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,     5,    23,   -77,   -77,    31,   -77,   -77,    32,    56,
      25,    44,    46,    59,   -77,    79,    10,   -77,    60,   -77,
     -77,    -5,    98,    76,    -8,   -11,    -4,   107,    81,   -77,
      56,    88,   -77,     6,     3,   101,     3,   106,   109,   -77,
      84,   -77,   104,    -1,    -4,   -77,   -77,   111,   108,    67,
     110,   112,   -77,    -5,   -77,   -77,    87,     3,    74,   -77,
     -77,   -77,     3,     3,     3,     3,    96,   113,   -11,   115,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,    62,    67,   118,
     108,     3,    56,    87,   -77,    66,    66,   -77,   -77,   -77,
     -77,   -77,    51,   119,   -77,   -77,   -77,   121,   -77,    62,
      87,    24,   -77,   -77,    56,    92,   122,   -77,   -77,   120,
     123,    38,   -77,   -77,    56,    -4,    -4,   -77,   125,   126,
      42,   127,   128,    67,    67,   -77,   -77,   -77,   129,   130,
     -77,   -77
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     0,     1,    53,     0,     0,
       0,     0,     0,     0,    38,     0,     0,     8,     5,     6,
       7,     4,    48,     0,     0,     0,     0,     0,     0,    54,
       9,     0,    45,     0,     0,    52,     0,    56,    55,    62,
       0,    44,     0,     0,     0,    34,    35,     0,     0,     0,
      50,     0,    14,    46,    56,    55,    47,     0,     0,    10,
      11,    12,     0,     0,     0,     0,     0,     0,     0,     0,
      15,    28,    29,    33,    32,    30,    31,     0,     0,     0,
       0,     0,     0,    51,    61,    57,    58,    59,    60,    43,
      41,    42,     0,     0,    36,    37,    18,     0,    39,     0,
      49,     0,    19,    21,     0,     0,     0,    23,    17,     0,
       0,     0,    24,    26,     0,     0,     0,    16,     0,     0,
       0,     0,     0,     0,     0,    40,    20,    22,     0,     0,
      25,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -77,   -77,   -77,    -9,   -77,   -77,   -77,   -77,   -77,   -38,
     -77,   -77,   -76,   -77,   -77,    64,   -48,    40,   -77,   -77,
     -77,   -77,    77,   114,   -77,   -77,   -77,   -31
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    30,    17,    18,    31,    93,    52,    47,
     109,   110,    79,   118,   119,    77,    48,    96,    19,    27,
     106,    20,    43,    21,     4,     8,    39,    40
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      16,    80,    97,    56,    36,    58,    69,    41,    44,    10,
      37,    32,    67,    10,    45,    36,    68,     5,    38,     1,
      42,    54,    46,     6,    33,    29,    83,    10,    11,    55,
      80,    85,    86,    87,    88,    12,    15,    13,    14,   108,
      15,    10,    11,    22,     7,    10,     9,   128,   129,    12,
     100,    13,    14,   117,    15,    23,    11,   125,    25,    10,
      11,   102,   103,    12,    24,    13,    14,    12,    15,    13,
      14,    26,    15,   101,    11,    80,    80,   121,   122,    78,
      94,    12,    28,    13,    14,    45,    15,    84,    95,    64,
      65,    62,   -13,    46,    35,   111,    63,    64,    65,    50,
      61,    62,   112,   113,    62,   120,    63,    64,    65,    63,
      64,    65,    71,    72,    73,    74,    75,    76,    34,    49,
      51,    57,    59,    66,    70,    60,    82,    89,    92,    90,
      81,    98,   115,   104,   105,   116,   114,   123,   124,   107,
     126,   127,   130,   131,    99,    91,     0,    53
};

static const yytype_int8 yycheck[] =
{
       9,    49,    78,    34,    12,    36,    44,    18,    12,     3,
      18,    16,    13,     3,    18,    12,    17,    12,    26,    21,
      31,    18,    26,     0,    29,    15,    57,     3,    18,    26,
      78,    62,    63,    64,    65,    25,    30,    27,    28,    15,
      30,     3,    18,    18,    13,     3,    14,   123,   124,    25,
      81,    27,    28,    15,    30,    30,    18,    15,    12,     3,
      18,    10,    11,    25,    20,    27,    28,    25,    30,    27,
      28,    12,    30,    82,    18,   123,   124,   115,   116,    12,
      18,    25,     3,    27,    28,    18,    30,    13,    26,    23,
      24,    17,    32,    26,    18,   104,    22,    23,    24,    18,
      16,    17,    10,    11,    17,   114,    22,    23,    24,    22,
      23,    24,     4,     5,     6,     7,     8,     9,    20,    12,
      32,    20,    16,    19,    13,    16,    14,    31,    13,    16,
      20,    13,    12,    14,    13,    12,    14,    12,    12,    99,
      13,    13,    13,    13,    80,    68,    -1,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    34,    35,    57,    12,     0,    13,    58,    14,
       3,    18,    25,    27,    28,    30,    36,    37,    38,    51,
      54,    56,    18,    30,    20,    12,    12,    52,     3,    15,
      36,    39,    16,    29,    20,    18,    12,    18,    26,    59,
      60,    18,    31,    55,    12,    18,    26,    42,    49,    12,
      18,    32,    41,    56,    18,    26,    60,    20,    60,    16,
      16,    16,    17,    22,    23,    24,    19,    13,    17,    42,
      13,     4,     5,     6,     7,     8,     9,    48,    12,    45,
      49,    20,    14,    60,    13,    60,    60,    60,    60,    31,
      16,    55,    13,    40,    18,    26,    50,    45,    13,    48,
      60,    36,    10,    11,    14,    13,    53,    50,    15,    43,
      44,    36,    10,    11,    14,    12,    12,    15,    46,    47,
      36,    42,    42,    12,    12,    15,    13,    13,    45,    45,
      13,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    36,    36,    36,    36,    36,    36,
      37,    37,    37,    39,    38,    40,    38,    41,    42,    43,
      42,    44,    42,    45,    46,    45,    47,    45,    48,    48,
      48,    48,    48,    48,    49,    49,    50,    50,    52,    53,
      51,    54,    55,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    58,    57,    59,    59,    60,    60,    60,
      60,    60,    60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     0,     3,     0,     8,     4,     3,     0,
       8,     0,     8,     3,     0,     8,     0,     8,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     0,
       9,     5,     3,     3,     1,     2,     3,     4,     2,     5,
       3,     5,     3,     0,     7,     1,     1,     3,     3,     3,
       3,     3,     1
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
#line 114 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n Succesful test");}
#line 1421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 132 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 1442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 148 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 168 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 185 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
								//Erease the JMP else steps to build the else statement
								else_stack = push(if_lbl_count-1, else_stack);	//Insert else label value to 
								cp--;											//Erease the JMP ignore_else to write it after the else body
							}
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 191 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
									 	(yyvsp[-3].nb) = cp;		//If is inserted the execution of the body but its instruction is inserted here
										cp++;    		//Jx	
										cp++;			//JMP instruction goes here (used in case if statement is not approved)	
										cp++;			//If label goes here (used in case if statement is approved)

										if_stack = push(if_lbl_count, if_stack);		//Insert if label value to 	
										else_stack = push(if_lbl_count, else_stack);	//Insert else label value to 									
										if_lbl_count++;				
								}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 201 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
									//convert num to string		

									auxNum = if_stack.stk[if_stack.top];	//take if label value from the stack	
									if_stack = pop(if_stack);					//pop the value	
									else_stack = pop(else_stack);				//pop the value	

									//create string if_lbl_n for Jx						
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

									//Put a JMP to jump the else statement after if Body 			
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
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 253 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 269 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {									
																insert_Instruction( "CMP", "eax", "ebx", "", "", cp );	//COMPARISSON	
																cp++;
																strcpy (last_if_type, (yyvsp[-1].variable));
															}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 274 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
												/**If true jump to if body**/

												//create string if_lbl_n for if lbl
												strcpy( auxString, "if_lbl_" );										
												sprintf(snum , "%d", if_lbl_count);	
												strcat( auxString, snum );		
												insert_Instruction( last_if_type, auxString, "", "", "", cp );	//IF	
												cp++;
										}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 284 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 305 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 322 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 348 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {									
																	insert_Instruction( "CMP", "eax", "ebx", "", "", cp );	//COMPARISSON	
																	cp++;
																	strcpy (last_while_type, (yyvsp[-1].variable));
																}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 353 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {												
												/**If true jump to while_Begin**/

												//create string while_BEG_lbl_n 
												strcpy( auxString, "while_BEG_lbl_" );										
												sprintf(snum , "%d", while_lbl_count);	
												strcat( auxString, snum );			
												insert_Instruction( last_while_type, auxString, "", "", "", cp );	//IF	
												cp++;
											}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 363 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
						 						/**If true jump to while_Begin**/

												//create string while_BEG_lbl_n 
												strcpy( auxString, "while_BEG_lbl_" );										
												sprintf(snum , "%d", while_lbl_count);	
												strcat( auxString, snum );				
												insert_Instruction( last_while_type, auxString, "", "", "", cp );	//IF	
												cp++;	

												//If false, exit the loop 				
				 						
												//create string while_END_lbl_n 
												strcpy( auxString, "while_END_lbl_" );										
												sprintf(snum , "%d", while_lbl_count);	
												strcat( auxString, snum );		
												insert_Instruction( "JMP", auxString, "", "", "", cp );	//JMP
												cp++;

												(yyval.variable)=last_while_type;	//return last if 
											}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 384 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {											
												/**If true jump to next if**/

												//create string if_lbl_n for if lbl
												strcpy( auxString, "$+4" );			
												insert_Instruction( last_while_type, auxString, "", "", "", cp );	//IF	
												cp++;

												//If false, exit the loop 				
				 						
												//create string while_END_lbl_n 
												strcpy( auxString, "while_END_lbl_" );										
												sprintf(snum , "%d", while_lbl_count);	
												strcat( auxString, snum );		
												insert_Instruction( "JMP", auxString, "", "", "", cp );	//JMP
												cp++;
										}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 401 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
						 						/**If true jump to while_Begin**/

												//create string while_BEG_lbl_n 
												strcpy( auxString, "while_BEG_lbl_" );										
												sprintf(snum , "%d", while_lbl_count);	
												strcat( auxString, snum );				
												insert_Instruction( last_while_type, auxString, "", "", "", cp );	//IF	
												cp++;

												//If false, exit the loop 				
				 						
												//create string while_END_lbl_n 
												strcpy( auxString, "while_END_lbl_" );										
												sprintf(snum , "%d", while_lbl_count);	
												strcat( auxString, snum );		
												insert_Instruction( "JMP", auxString, "", "", "", cp );	//JMP
												cp++;

												(yyval.variable)=last_while_type;	//return last if 
										}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 427 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
							(yyval.variable)="JL";
						}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 430 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
							(yyval.variable)="JG";
						}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 433 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
							(yyval.variable)="JE";
						}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 436 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
							(yyval.variable)="JNE";
						}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 439 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
							(yyval.variable)="JGE";
						}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 442 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
							(yyval.variable)="JLE";
						}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 447 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 462 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {		
								sprintf(snum, "%d", (yyvsp[0].nb));
								insert_Instruction( "MOV", "eax", snum, "", "", cp );	 //mov eax, num	
								cp++;
							}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 470 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {			
								if(lookup((yyvsp[0].variable)) != -1)
								{				
									insert_Instruction( "MOV", "ebx", address_Concat((yyvsp[0].variable)), "", "", cp );	 //mov eax, [var] 	
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
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 485 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {		
								sprintf(snum, "%d", (yyvsp[0].nb));
								insert_Instruction( "MOV", "ebx", snum, "", "", cp );	 //mov eax, num	
								cp++;
							}
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 492 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {	
														//create string while_lbl_n: for the while begin
														strcpy( auxString, "while_lbl_" );										
														sprintf(snum , "%d", while_lbl_count);	
														strcat( auxString, snum );		
														strcat( auxString, ":" );	

														insert_Instruction( auxString, "", "", "", "", cp );	//WHILE:
														cp++;		

														(yyvsp[0].nb)=while_lbl_count;										//Store the while number
			
													}
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 505 "analysgramAssExp.yacc" /* yacc.c:1646  */
    { 	
														/**If true jump to while_Begin**/

														//create string while_BEG_lbl_n 
														strcpy( auxString, "while_BEG_lbl_" );										
														sprintf(snum , "%d", while_lbl_count);	
														strcat( auxString, snum );				
														insert_Instruction( last_while_type, auxString, "", "", "", cp );	//IF	
														cp++;

														//If false, exit the loop 				
						 						
														//create string while_END_lbl_n 
														strcpy( auxString, "while_END_lbl_" );										
														sprintf(snum , "%d", while_lbl_count);	
														strcat( auxString, snum );		
														insert_Instruction( "JMP", auxString, "", "", "", cp );	//JMP
														cp++;		

														//create string while_BEG_lbl_n: for the while begin

														/*Update while label counter*/
														auxNum = while_lbl_count;	//take if label value from the stack	
														while_stack = push(while_lbl_count, while_stack);		//Insert while label value to 						
														while_lbl_count++;	

														strcpy( auxString, "while_BEG_lbl_" );										
														sprintf(snum , "%d", auxNum);	
														strcat( auxString, snum );		
														strcat( auxString, ":" );	

														insert_Instruction( auxString, "", "", "", "", cp );	//WHILE:
														cp++;		
													}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 539 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {						
														auxNum = while_stack.stk[while_stack.top];	//take if label value from the stack	
														while_stack = pop(while_stack);					//pop the value		

														//create string while_lbl_n: for the while begin
														strcpy( auxString, "while_lbl_" );										
														sprintf(snum , "%d", auxNum);	
														strcat( auxString, snum );

														//In case end of while is reached, return to the condition check at the begining														
														insert_Instruction( "JMP", auxString, "", "", "", cp );	//JMP WHILE
														cp++;		

														//create string while_end_lbl_n: for the while end
														strcpy( auxString, "while_END_lbl_" );										
														sprintf(snum , "%d", auxNum);	
														strcat( auxString, snum );		
														strcat( auxString, ":" );	

														insert_Instruction( auxString, "", "", "", "", cp );	//WHILE_END:
														cp++;	
													}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 563 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n Print trouve");}
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 566 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n Contenu du Print trouve");}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 567 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 644 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n Contenu du Print trouve");}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 648 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n Declaration trouvee");}
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 649 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("\n Declaration trouvee");}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 650 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 661 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 672 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 683 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 694 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 705 "analysgramAssExp.yacc" /* yacc.c:1646  */
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
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 718 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {												
									 insert_Instruction( "section", ".text", "", "", "", cp );
									 cp++;										
									 insert_Instruction( "global", "_start", "", "", "", cp );
									 cp++;									
									 insert_Instruction( "_start:", "", "", "", "", cp );
									 cp++;		
								}
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 726 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {printf("Main Trouvee");}
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 729 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {
								if( tempCounter == 1 )
								{
									tempCounter = 2;
									//$$=lookup("0temp1");	
								}		
								else
								{
									tempCounter = 1;
									//$$=lookup("0temp2");	
								}

								sprintf(snum , "%d", (yyvsp[0].nb));	
								(yyval.variable)=snum;
							}
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 744 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {	
								if(lookup((yyvsp[0].variable)) != -1)
								{
									//$$=lookup($1);
									(yyval.variable)=address_Concat((yyvsp[0].variable));			
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
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 761 "analysgramAssExp.yacc" /* yacc.c:1646  */
    { 	
										fprintf(fp, "mov eax, [%s]\n", (yyvsp[-2].variable)); //eax = [a/0temp1]
										 insert_Instruction( "mov", "eax", (yyvsp[-2].variable), "", "", cp );
										 cp++;			
									     fprintf(fp, "mov ebx, [%s]\n", (yyvsp[0].variable)); //ebx = [b/0temp2]
										 insert_Instruction( "mov", "ebx", (yyvsp[0].variable), "", "", cp );
									     cp++;

									    fprintf(fp, "add eax, ebx\n"); 		//eax = eax + ebx
										 insert_Instruction( "add", "eax", "ebx", "", "", cp );
									     cp++;

										tempCounter = 2;					//Como se evaluaron dos expresiones, se coloca en 0temp2
										printf("\n Somme trouvee");
									}
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 776 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {	
										fprintf(fp, "mov eax, [%s]\n", (yyvsp[-2].variable)); //eax = [a/0temp1]
										 insert_Instruction( "mov", "eax", (yyvsp[-2].variable), "", "", cp );
										 cp++;			
									    fprintf(fp, "mov ebx, [%s]\n", (yyvsp[0].variable)); //ebx = [b/0temp2]
										 insert_Instruction( "mov", "ebx", (yyvsp[0].variable), "", "", cp );
									     cp++;

									    fprintf(fp, "sub eax, ebx\n"); 		//eax - ebx
										 insert_Instruction( "sub", "eax", "ebx", "", "", cp );
									     cp++;

										tempCounter = 2;					//Como se evaluaron dos expresiones, se coloca en temp2 
										printf("\n Substraction trouvee");
									}
#line 2281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 791 "analysgramAssExp.yacc" /* yacc.c:1646  */
    {	
										fprintf(fp, "mov ax, [%s]\n", (yyvsp[-2].variable)); //ax = [a/0temp1]
										 insert_Instruction( "mov", "eax", (yyvsp[-2].variable), "", "", cp );
										 cp++;			
									    fprintf(fp, "mov bx, [%s]\n", (yyvsp[0].variable)); //bx = [b/0temp2]
										 insert_Instruction( "mov", "ebx", (yyvsp[0].variable), "", "", cp );
									     cp++;

									    fprintf(fp, "mul bx\n"); 			//ax * bx
										 insert_Instruction( "mul", "bx", "", "", "", cp );
									     cp++;

										tempCounter = 2;					//Como se evaluaron dos expresiones, se coloca en temp2 
										printf("\n Multiplication trouvee");
									}
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 806 "analysgramAssExp.yacc" /* yacc.c:1646  */
    { 
											fprintf(fp, "\nFirst number : \n"); 
									}
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2313 "y.tab.c" /* yacc.c:1646  */
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
#line 819 "analysgramAssExp.yacc" /* yacc.c:1906  */


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
