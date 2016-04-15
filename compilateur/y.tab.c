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
#line 1 "analysGram.yacc" /* yacc.c:339  */

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

	struct stack if_iter_stack;			//Keep count of number of ifs to correct
	struct stack if_stack;				//Allows to assign if begin code lines to jump instructions
	struct stack else_iter_stack;		//Keep count of number of else to correct
	struct stack else_stack;			//Allows to assign else begin code lines to jump instructions
  	int if_begin_count = 0; 			//Counter to determine the if labels to use
  	int else_begin_count = 0; 			//Counter to determine the else labels to use

  	int if_lbl_count = 0; 				//Counter to determine the if labels to use

	struct stack while_last_cond;		//Stores the position after comparissons of the while (to add the last comparisson)

	struct stack while_begin_iter_stack;			//Keep count of number of while begin lines to add
	struct stack while_begin_stack;						//Allows to assign while begin code lines to jump instructions
	struct stack while_end_iter_stack;				//Keep count of number of while end lines to correct
	struct stack while_end_stack;							//Allows to assign while end code lines to jump instructions
  	int while_begin_count = 0; 						//Counter to determine the while begin labels to use
  	int while_end_count = 0; 						//Counter to determine the while end labels to use

	struct stack while_stack;		//Keeps count of while statements to create labels
  	int while_lbl_count = 0; 		//Counter to determine the while labels to use

	char snum[5];		//To convert numbers to strings
	char snum2[5];		//To convert numbers to strings
	char auxString[32];	
	char auxString2[32];
	
	char last_while_type[8]; //Returns the last type of while retrieved

	int auxNum;	

	char retrievedString[64]; //Used to store user input in the printf instructions.
	char stringPrinter[4]; 	//Used to create the printf instructions.

#line 145 "y.tab.c" /* yacc.c:339  */

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
    tELSE = 284,
    tV = 285,
    tCONST = 286,
    tGUILLEMETS = 287
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
#define tELSE 284
#define tV 285
#define tCONST 286
#define tGUILLEMETS 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 80 "analysGram.yacc" /* yacc.c:355  */

	int nb;
	char * variable;

#line 254 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 269 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   132

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  114

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
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
       0,   124,   124,   127,   137,   138,   139,   140,   141,   142,
     145,   162,   180,   199,   210,   214,   253,   257,   257,   277,
     277,   294,   298,   298,   318,   318,   335,   338,   341,   347,
     362,   368,   378,   381,   381,   422,   430,   431,   432,   443,
     454,   465,   476,   487,   511,   536,   553,   561,   568,   576,
     583,   584
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
  "tPRINT", "tNUM", "tIF", "tWHILE", "tELSE", "tV", "tCONST",
  "tGUILLEMETS", "';'", "$accept", "TestStart", "TestMessage", "Body",
  "Assign", "Condition", "If", "Cond", "$@1", "$@2", "CondWhile", "$@3",
  "$@4", "CompareToken", "CondValue", "ConditionWhile", "While", "$@5",
  "Print", "Declar", "Val", "Expr", YY_NULLPTR
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
     285,   286,   287,    59
};
# endif

#define YYPACT_NINF -57

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-57)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -19,   -57,    12,   -57,   -57,    35,   -57,   -18,    -5,    25,
     -57,    -5,   -57,   -57,    28,    88,    70,    37,   -57,   -57,
     -57,   -57,     1,    15,    39,    44,    49,    63,    17,   -57,
      41,   -57,   -57,    10,    53,   -57,    58,    65,    -4,    36,
      -2,    80,    84,   -57,    70,    90,   -57,     3,   -57,   -57,
      -1,    93,    -1,    98,    99,   -57,    83,   -57,   -57,   103,
      -2,   104,    88,    70,   100,    70,    10,   106,   107,    86,
      -1,    67,   -57,   -57,   -57,    -1,    -1,    -1,    -1,   105,
     109,   -57,     1,    40,    -1,    54,    -5,    -5,    86,   -57,
      51,    51,   -57,   -57,   -57,   101,   -57,   -57,    86,   -57,
     110,   111,   -57,   -57,   -57,   -57,   113,   114,    -2,    -2,
     115,   116,   -57,   -57
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    33,     0,     2,     3,     0,     1,     0,     0,     0,
      32,     0,    29,    30,     0,     0,     0,     0,    31,    26,
      27,    28,     0,     0,     0,     0,     0,     0,     0,     8,
       5,     6,     7,     4,     0,    21,    39,     0,     0,     0,
       0,     0,     0,    34,     9,     0,    36,     0,    22,    24,
       0,    43,     0,    45,    44,    51,     0,    45,    44,     0,
       0,     0,     0,     0,    41,     0,    37,     0,     0,    38,
       0,     0,    10,    11,    12,     0,     0,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,     0,    42,    50,
      46,    47,    48,    49,    35,     0,    16,    15,    40,    14,
       0,     0,    17,    19,    23,    25,     0,     0,     0,     0,
       0,     0,    18,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -57,   -57,   -14,   -57,   -57,   -57,   -56,   -57,   -57,
     -10,   -57,   -57,    68,   -22,   -57,   127,   -57,   -57,    85,
      92,   -47
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    44,    29,    41,    30,    61,   106,   107,
      14,    67,    68,    22,    15,     9,    31,     5,    32,    33,
      55,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      35,    17,    28,    69,    80,    71,    23,    11,    52,     1,
      60,    52,     6,    12,    53,    10,    12,    57,    62,    12,
      23,    13,    54,    88,    13,    58,    46,    13,    90,    91,
      92,    93,    43,    36,    27,    24,     7,    98,    62,    16,
      47,    18,    25,    23,    26,     1,    37,     8,    27,    83,
      34,    85,   110,   111,    57,    97,    39,    23,    24,    38,
      96,    40,    58,    48,    49,    25,    42,    26,     1,    99,
      45,    27,    24,    23,    77,    78,   100,   101,    50,    25,
      89,    26,     1,    51,    75,    27,    62,    62,    24,    76,
      77,    78,    19,    20,    63,    25,    21,    26,     1,    74,
      75,    27,    64,    75,    65,    76,    77,    78,    76,    77,
      78,   102,   103,    70,    72,    73,    79,    81,    86,    87,
      84,    94,    95,   104,   105,   108,   109,     4,   112,   113,
      82,    59,    66
};

static const yytype_uint8 yycheck[] =
{
      22,    11,    16,    50,    60,    52,     3,    12,    12,    28,
      12,    12,     0,    18,    18,    33,    18,    18,    40,    18,
       3,    26,    26,    70,    26,    26,    16,    26,    75,    76,
      77,    78,    15,    18,    31,    18,     1,    84,    60,    14,
      30,    13,    25,     3,    27,    28,    31,    12,    31,    63,
      13,    65,   108,   109,    18,    15,    12,     3,    18,    20,
      82,    12,    26,    10,    11,    25,     3,    27,    28,    15,
      29,    31,    18,     3,    23,    24,    86,    87,    20,    25,
      13,    27,    28,    18,    17,    31,   108,   109,    18,    22,
      23,    24,     4,     5,    14,    25,     8,    27,    28,    16,
      17,    31,    18,    17,    14,    22,    23,    24,    22,    23,
      24,    10,    11,    20,    16,    16,    13,    13,    12,    12,
      20,    16,    13,    13,    13,    12,    12,     0,    13,    13,
      62,    39,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    35,    36,    50,    51,     0,     1,    12,    49,
      33,    12,    18,    26,    44,    48,    14,    44,    13,     4,
       5,     8,    47,     3,    18,    25,    27,    31,    37,    38,
      40,    50,    52,    53,    13,    48,    18,    31,    20,    12,
      12,    39,     3,    15,    37,    29,    16,    30,    10,    11,
      20,    18,    12,    18,    26,    54,    55,    18,    26,    54,
      12,    41,    48,    14,    18,    14,    53,    45,    46,    55,
      20,    55,    16,    16,    16,    17,    22,    23,    24,    13,
      41,    13,    47,    37,    20,    37,    12,    12,    55,    13,
      55,    55,    55,    55,    16,    13,    48,    15,    55,    15,
      44,    44,    10,    11,    13,    13,    42,    43,    12,    12,
      41,    41,    13,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    37,    37,    37,    37,    37,    37,
      38,    38,    38,    39,    40,    40,    41,    42,    41,    43,
      41,    44,    45,    44,    46,    44,    47,    47,    47,    48,
      48,    49,    49,    51,    50,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    54,    54,    55,    55,    55,    55,
      55,    55
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     3,     5,     5,     3,     0,     8,     0,
       8,     3,     0,     8,     0,     8,     1,     1,     1,     1,
       1,     3,     2,     0,     6,     5,     2,     3,     4,     2,
       5,     3,     5,     3,     1,     1,     3,     3,     3,     3,
       3,     1
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
#line 127 "analysGram.yacc" /* yacc.c:1646  */
    {printf("\n Succesful test");}
#line 1424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 145 "analysGram.yacc" /* yacc.c:1646  */
    {
										if( lookupType((yyvsp[-3].variable)) != -1 && lookupType((yyvsp[-1].variable)) != -1 ) //Both variables exist
										{									
										    fprintf(fp, "mov [%s], [%s]\n", (yyvsp[-3].variable), (yyvsp[-1].variable)); 	//a = b

											sprintf(snum, "%d", lookup((yyvsp[-3].variable)));
											sprintf(snum2, "%d", lookup((yyvsp[-1].variable)));
											insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
										    cp++;			
										}
										else
										{
											strcpy( errTab[ce].error, "Trying to assign value to a constant.\n" );
											errTab[ce].line = ce;
											ce++;
										}	
									}
#line 1446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 162 "analysGram.yacc" /* yacc.c:1646  */
    {
										if( lookupType((yyvsp[-3].variable)) != -1 ) 	
										{									
										    fprintf(fp, "mov [%s], %d\n", (yyvsp[-3].variable), (yyvsp[-1].nb)); 	//a = 4
										    		
											sprintf(snum, "%d", lookup((yyvsp[-3].variable)));
											sprintf(snum2, "%d", (yyvsp[-1].nb));

										    insert_Instruction( "6", snum, snum2, "", "", cp ); //AFC @result constant 
										    cp++;			
										}
										else
										{
											strcpy( errTab[ce].error, "Trying to assign value to a constant.\n" );
											errTab[ce].line = ce;
											ce++;
										}	
									}
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 180 "analysGram.yacc" /* yacc.c:1646  */
    {
										if(lookupType((yyvsp[-3].variable)) != -1)	
										{									
										    fprintf(fp, "mov [%d], eax\n", lookup((yyvsp[-3].variable))); 	//a = Resultado

											sprintf(snum, "%d", lookup((yyvsp[-3].variable)));
											sprintf(snum2, "%d", (yyvsp[-1].nb));
											insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
										    cp++;			
										}
										else
										{
											strcpy( errTab[ce].error, "Trying to assign value to a constant.\n" );
											errTab[ce].line = ce;
											ce++;
										}
									}
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 199 "analysGram.yacc" /* yacc.c:1646  */
    {
									(yyval.nb) = cp;
									cp++;
									if_iter_stack = push(if_begin_count, if_iter_stack);	//store if begin iterations to later assign if begin line
									if_begin_count = 0;

									else_iter_stack = push(else_begin_count, else_iter_stack);	//store else begin iterations to later assign if begin line
									else_begin_count = 0;
								}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 210 "analysGram.yacc" /* yacc.c:1646  */
    {
													sprintf(snum , "%d", cp);									//Obtain else body end
													insert_Instruction( "JMP", snum, "", "", "", (yyvsp[-4].nb)-1 );		//If ended, jump to else body end
												}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 214 "analysGram.yacc" /* yacc.c:1646  */
    {
													sprintf(snum , "%d", cp+1);												//next instruction to ignore else jmp
													insert_Instruction( "JMF", "RESULTADO", snum, "", "", (yyvsp[-3].nb) );				//If statement is false jump to else body

													sprintf(snum , "%d", cp+1);									//Obtain if end
													insert_Instruction( "JMP", snum, "", "", "", cp );			//If ended, jump to else body end (If there is an else instruction, will be overwritten)
													cp++;		
													(yyval.nb) = cp; 													//Obtain else body end	

													if(if_iter_stack.top != -1)	//If there is one jmp to if begin
													{
														auxNum = if_iter_stack.stk[if_iter_stack.top];	//take if label value from the stack	
														if_iter_stack = pop(if_iter_stack);						//pop the value		
														for(int i=0  ; i<auxNum ; i++)	
														{ 										
															sprintf(snum , "%d", (yyvsp[-3].nb)+1);									//If begin	
															strcpy( labTab[if_stack.stk[if_stack.top]].param1, snum );	//put if begin on second parameter of jmp instruct
															if_stack = pop(if_stack);				
														}
													}													

													if(else_iter_stack.top != -1)	//If there is one jmp to else begin
													{
														auxNum = else_iter_stack.stk[else_iter_stack.top];	//take if label value from the stack	
														else_iter_stack = pop(else_iter_stack);							//pop the value		
														for(int i=0  ; i<auxNum ; i++)	
														{ 										
															sprintf(snum , "%d", cp);										//Else begin	
															strcpy( labTab[else_stack.stk[else_stack.top]].param2, snum );	//put if begin on second parameter of jmp instruct
															else_stack = pop(else_stack);				
														}
													}
												}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 253 "analysGram.yacc" /* yacc.c:1646  */
    {						
																insert_Instruction( (yyvsp[-1].variable), "@X", (yyvsp[-2].variable), (yyvsp[0].variable), "", cp );	//COMPARISSON	$1 and $3 not working
																cp++;
														}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 257 "analysGram.yacc" /* yacc.c:1646  */
    {									
											sprintf(snum , "%d", cp+2);	
											insert_Instruction( "JMF", "@X", snum, "", "", cp );					//If statement is false jump to the next statement
											cp++;

											if_begin_count++;
											if_stack = push(cp, if_stack);												//Remember this line to later add the if begin line
											insert_Instruction( "JMP", "IF BEGIN", "", "", "", cp );					//If statement is true jump to the last if and return true value
											cp++;
										}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 267 "analysGram.yacc" /* yacc.c:1646  */
    {
											sprintf(snum , "%d", cp+2);	
					 						insert_Instruction( "JMF", "@X", snum, "", "", cp );					//If statement is false jump to the next statement
											cp++;	

											if_begin_count++;
											if_stack = push(cp, if_stack);												//Remember this line to later add the if begin line
											insert_Instruction( "JMP", "IF BEGIN", "", "", "", cp );					//If statement is true jump to the last if and return true value
											cp++;
										}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 277 "analysGram.yacc" /* yacc.c:1646  */
    {
											else_begin_count++;
											else_stack = push(cp, else_stack);											//Remember this line to later add the else begin line
											insert_Instruction( "JMF", "@X", "ELSE BEGIN", "", "", cp );			//If statement is false jump to the else body
											cp++;
										}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 283 "analysGram.yacc" /* yacc.c:1646  */
    {
											else_begin_count++;
											else_stack = push(cp, else_stack);											//Remember this line to later add the else begin line
											insert_Instruction( "JMF", "@X", "ELSE BEGIN", "", "", cp );			//If statement is false jump to the else body
											cp++;											
										}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 294 "analysGram.yacc" /* yacc.c:1646  */
    {						
															insert_Instruction( (yyvsp[-1].variable), "@X", (yyvsp[-2].variable), (yyvsp[0].variable), "", cp );			//COMPARISSON	$1 and $3 not working
															cp++;
														}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 298 "analysGram.yacc" /* yacc.c:1646  */
    {											
												sprintf(snum , "%d", cp+2);										
												insert_Instruction( "JMF", "@X", snum, "", "", cp );				//If statement is false, jump to next condition
												cp++;	

												while_begin_count++;
												while_begin_stack = push(cp, while_begin_stack);					//Remember this line to later add the while begin line
												insert_Instruction( "JMP", "WHILE BEGIN", "", "", "", cp );			//Jump to the begining of the while
												cp++;
											}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 308 "analysGram.yacc" /* yacc.c:1646  */
    {											
												sprintf(snum , "%d", cp+2);										
												insert_Instruction( "JMF", "@X", snum, "", "", cp );				//If statement is false, jump to next condition
												cp++;	

												while_begin_count++;
												while_begin_stack = push(cp, while_begin_stack);					//Remember this line to later add the while begin line
												insert_Instruction( "JMP", "WHILE BEGIN", "", "", "", cp );			//Jump to the begining of the while
												cp++;
											}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 318 "analysGram.yacc" /* yacc.c:1646  */
    {		
												while_end_count++;
												while_end_stack = push(cp, while_end_stack);						//Remember this line to later add the while end line				
												insert_Instruction( "JMF", "@X", "WHILE END", "", "", cp );			//If statement is false, jump to the end of the while
												cp++;	
											}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 324 "analysGram.yacc" /* yacc.c:1646  */
    {			
												while_end_count++;
												while_end_stack = push(cp, while_end_stack);						//Remember this line to later add the while end line			
												insert_Instruction( "JMF", "@X", "WHILE END", "", "", cp );			//If statement is false, jump to the end of the while
												cp++;	
											}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 335 "analysGram.yacc" /* yacc.c:1646  */
    {
							(yyval.variable)="9";	//INF
						}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 338 "analysGram.yacc" /* yacc.c:1646  */
    {
							(yyval.variable)="A";	//SUP
						}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 341 "analysGram.yacc" /* yacc.c:1646  */
    {
							(yyval.variable)="B";	//EQU
						}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 347 "analysGram.yacc" /* yacc.c:1646  */
    {			
								if(lookup((yyvsp[0].variable)) != -1)
								{									
									sprintf(snum , "%d", lookup((yyvsp[0].variable)));	
									(yyval.variable)=snum;	
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
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 362 "analysGram.yacc" /* yacc.c:1646  */
    {								
								sprintf(snum , "%d", (yyvsp[0].nb));	
								(yyval.variable)=snum;
							}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 368 "analysGram.yacc" /* yacc.c:1646  */
    {											
											while_last_cond = push(cp, while_last_cond);	//Store while begin
											cp++;	

											while_begin_iter_stack = push(while_begin_count, while_begin_iter_stack);	//store while begin iterations to later assign while begin line
											while_begin_count = 0;

											while_end_iter_stack = push(while_end_count, while_end_iter_stack);			//store while end iterations to later assign while end line
											while_end_count = 0;	
										}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 378 "analysGram.yacc" /* yacc.c:1646  */
    { printf("ERROR!!!\n");  yyerrok; }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 381 "analysGram.yacc" /* yacc.c:1646  */
    {	
														(yyvsp[0].nb)=cp;										//Save while begin
			
													}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 385 "analysGram.yacc" /* yacc.c:1646  */
    {				
														int whileBegin = while_last_cond.stk[while_last_cond.top];
														while_last_cond = pop(while_last_cond);							//pop the value		

														sprintf(snum , "%d", cp+1);										
														insert_Instruction( "JMF", snum, "", "", "",  whileBegin);	//Jump to while end in case condition is not met

														sprintf(snum , "%d", (yyvsp[-5].nb));												
														insert_Instruction( "JMP", snum, "", "", "", cp );	//JMP to while begin
														cp++;

														if(while_begin_iter_stack.top != -1)	//If there is one jmp to if begin
														{
															auxNum = while_begin_iter_stack.stk[while_begin_iter_stack.top];	//take if label value from the stack	
															while_begin_iter_stack = pop(while_begin_iter_stack);						//pop the value		
															for(int i=0  ; i<auxNum ; i++)	
															{ 										
																sprintf(snum , "%d", whileBegin);									//while begin	
																strcpy( labTab[while_begin_stack.stk[while_begin_stack.top]].param1, snum );	//put while begin on second parameter of jmp instruct
																while_begin_stack = pop(while_begin_stack);				
															}
														}													

														if(while_end_iter_stack.top != -1)	//If there is one jmp to else begin
														{
															auxNum = while_end_iter_stack.stk[while_end_iter_stack.top];	//take if label value from the stack	
															while_end_iter_stack = pop(while_end_iter_stack);							//pop the value		
															for(int i=0  ; i<auxNum ; i++)	
															{ 										
																sprintf(snum , "%d", cp);										//while end	
																strcpy( labTab[while_end_stack.stk[while_end_stack.top]].param2, snum );	//put while end on second parameter of jmp instruct
																while_end_stack = pop(while_end_stack);				
															}
														}
													}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 422 "analysGram.yacc" /* yacc.c:1646  */
    {	
											sprintf(snum, "%d", (yyvsp[-2].nb));
											insert_Instruction( "C", snum, "", "", "", cp );	//PRI @result
											cp++;
										}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 432 "analysGram.yacc" /* yacc.c:1646  */
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
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 443 "analysGram.yacc" /* yacc.c:1646  */
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
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 454 "analysGram.yacc" /* yacc.c:1646  */
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
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 465 "analysGram.yacc" /* yacc.c:1646  */
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
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 476 "analysGram.yacc" /* yacc.c:1646  */
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
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 487 "analysGram.yacc" /* yacc.c:1646  */
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
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 511 "analysGram.yacc" /* yacc.c:1646  */
    {
								if( tempCounter == 1 )
								{
									sprintf(snum, "%d", lookup("0temp1"));
									sprintf(snum2, "%d", (yyvsp[0].nb));
									insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @temp1 @num	
									cp++;

									tempCounter = 2;
									(yyval.nb)=lookup("0temp1");
								}		
								else
								{
									sprintf(snum, "%d", lookup("0temp2"));
									sprintf(snum2, "%d", (yyvsp[0].nb));
									insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @temp2 @num	
									cp++;

									tempCounter = 1;
									(yyval.nb)=lookup("0temp2");	
								}

								//sprintf(snum , "%d", $1);	
								//$$=snum;
							}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 536 "analysGram.yacc" /* yacc.c:1646  */
    {	
								if(lookup((yyvsp[0].variable)) != -1)
								{
									(yyval.nb)=lookup((yyvsp[0].variable));
									//$$=address_Concat($1);			
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
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 553 "analysGram.yacc" /* yacc.c:1646  */
    { 		
										 sprintf(snum, "%d", (yyvsp[-2].nb));
										 sprintf(snum2, "%d", (yyvsp[0].nb));
										 insert_Instruction( "1", snum, snum, snum2, "", cp ); //ADD @result @operand1 @operand2
									     cp++;

										tempCounter = 2;					//Como se evaluaron dos expresiones, se coloca en 0temp2
									}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 561 "analysGram.yacc" /* yacc.c:1646  */
    {	
										 sprintf(snum, "%d", (yyvsp[-2].nb));
										 sprintf(snum2, "%d", (yyvsp[0].nb));
										 insert_Instruction( "3", snum, snum, snum2, "", cp ); //SOU @result @operand1 @operand2

										tempCounter = 2;					//Como se evaluaron dos expresiones, se coloca en temp2 
									}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 568 "analysGram.yacc" /* yacc.c:1646  */
    {								
										 sprintf(snum, "%d", (yyvsp[-2].nb));
										 sprintf(snum2, "%d", (yyvsp[0].nb));
										 insert_Instruction( "2", snum, snum, snum2, "", cp ); //MUL @result @operand1 @operand2
									     cp++;

										tempCounter = 2;					//Como se evaluaron dos expresiones, se coloca en temp2 
									}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 576 "analysGram.yacc" /* yacc.c:1646  */
    { 
										 sprintf(snum, "%d", (yyvsp[-2].nb));
										 sprintf(snum2, "%d", (yyvsp[0].nb));
										 insert_Instruction( "4", snum, snum, snum2, "", cp ); //DIV @result @operand1 @operand2

										tempCounter = 2;					//Como se evaluaron dos expresiones, se coloca en temp2 
									}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2007 "y.tab.c" /* yacc.c:1646  */
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
#line 593 "analysGram.yacc" /* yacc.c:1906  */


void yyerror(char *s) {
	printf("%s\n", s);
	//fprintf(stderr, "%s\n", s);
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
	fprintf(fp, " \tInstruction | param1 | param2 | param 3 | comments |\n");
  	fprintf(fp,"----------------------------------------------------- \n");
	for (int i = 0 ; i < cp; i++)
	{
		fprintf(fp, "%-3d:  %-14s %-12s %-12s %-12s ;%-s \n", i, labTab[i].instruct, labTab[i].param1, labTab[i].param2, labTab[i].param3, labTab[i].comments );
	}
}

char* address_Concat( char *varName ) //concatenates [] with the address: the result is similar to: [a]
{
	char *result = malloc(16 * sizeof(char));
	strcat(result, "@");
	strcat(result, varName);

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
