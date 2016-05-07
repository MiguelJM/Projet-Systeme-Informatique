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
#line 1 "analysGramPointers.yacc" /* yacc.c:339  */

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

  	bool pointer_value_flag = false;	//Used to verify if pointer value was initialized or was true
  	bool pointer_value_flag2 = false;	//turns pointer value to false (because a = b + a OR a = &var + &var2 where a,b are pointers is not permited)
  	bool pointer_value = false;			//Used to verify if a val i used for a pointer assignation

  	bool temp1_flag = false;		//Used to indicate if temp1 is being used (in that case, use temp2)

	char snum[5];		//To convert numbers to strings
	char snum2[5];		//To convert numbers to strings
	char auxString[32];	
	char auxString2[32];
	
	char last_while_type[8]; //Returns the last type of while retrieved

	int auxNum;	
	int depth = 0;				//Allows to determine how deep a variable is

	char retrievedString[64]; //Used to store user input in the printf instructions.
	char stringPrinter[4]; 	//Used to create the printf instructions.

#line 150 "y.tab.c" /* yacc.c:339  */

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
    tAMPERSAND = 258,
    tINT = 259,
    tMIN = 260,
    tMAY = 261,
    tMINEQU = 262,
    tMAYEQU = 263,
    tEQU = 264,
    tDIF = 265,
    tOR = 266,
    tAND = 267,
    tPO = 268,
    tPF = 269,
    tCO = 270,
    tCF = 271,
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
    tWHILE = 284,
    tELSE = 285,
    tV = 286,
    tCONST = 287,
    tGUILLEMETS = 288
  };
#endif
/* Tokens.  */
#define tAMPERSAND 258
#define tINT 259
#define tMIN 260
#define tMAY 261
#define tMINEQU 262
#define tMAYEQU 263
#define tEQU 264
#define tDIF 265
#define tOR 266
#define tAND 267
#define tPO 268
#define tPF 269
#define tCO 270
#define tCF 271
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
#define tWHILE 284
#define tELSE 285
#define tV 286
#define tCONST 287
#define tGUILLEMETS 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 85 "analysGramPointers.yacc" /* yacc.c:355  */

	int nb;
	char * variable;

#line 261 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 276 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   173

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   130,   130,   133,   143,   144,   145,   146,   147,   148,
     151,   178,   194,   242,   269,   296,   334,   363,   376,   380,
     417,   423,   423,   443,   443,   460,   466,   466,   486,   486,
     503,   506,   509,   515,   546,   588,   610,   622,   622,   666,
     675,   676,   677,   680,   681,   682,   720,   739,   740,   741,
     778,   797,   798,   799,   838,   860,   886,   942,   989,  1040,
    1055,  1070,  1085,  1100,  1101
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tAMPERSAND", "tINT", "tMIN", "tMAY",
  "tMINEQU", "tMAYEQU", "tEQU", "tDIF", "tOR", "tAND", "tPO", "tPF", "tCO",
  "tCF", "tPV", "tPLUS", "tVAR", "tSTRING", "tE", "tMAIN", "tSOU", "tMUL",
  "tDIV", "tPRINT", "tNUM", "tIF", "tWHILE", "tELSE", "tV", "tCONST",
  "tGUILLEMETS", "$accept", "TestStart", "TestMessage", "Body", "Assign",
  "Condition", "If", "Cond", "$@1", "$@2", "CondWhile", "$@3", "$@4",
  "CompareToken", "CondValue", "ConditionWhile", "While", "$@5", "Print",
  "Declar", "DeclarInt", "DeclarPtr", "DeclarCnst", "Val", "Expr", YY_NULLPTR
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
     285,   286,   287,   288
};
# endif

#define YYPACT_NINF -75

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-75)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -12,   -75,     7,   -75,   -75,     3,   -75,   101,    32,   101,
     -75,     0,   -75,    28,    77,    69,    43,   -75,   -75,   -75,
     -75,   -75,    50,     4,    58,    73,    87,    98,    29,     5,
     -75,    82,   -75,   -75,   -75,    90,    99,   107,     2,   -75,
       8,    92,    11,   -11,    72,   119,   100,   110,   124,   123,
       1,   -75,    69,   130,     8,    11,    29,   -75,   -75,    91,
     122,   126,    23,   -75,   129,    91,   132,   131,   134,   -75,
     118,    22,   133,   -75,   135,   -75,   139,   110,   141,    77,
      69,    91,   -75,    69,    90,    99,   107,   143,   144,    84,
      91,   -75,   142,   108,   -75,   145,   -75,   -75,    91,    91,
      91,    91,   146,   147,   -75,   -75,   148,   152,   -75,    50,
      34,    84,    52,   101,   101,    84,   -75,   -75,   -75,    27,
      27,   -75,   -75,   -75,   -75,   -75,    78,   -75,   -75,   -75,
     153,   154,   -75,   -75,   -75,   -75,   156,   157,   110,   110,
     158,   159,   -75,   -75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    37,     0,     2,     3,     0,     1,     0,     0,     0,
      33,     0,    35,     0,     0,     0,     0,    34,    36,    30,
      31,    32,     0,     0,    46,     0,     0,     0,     0,     0,
       8,     5,     6,     7,     4,    40,    41,    42,     0,    25,
       0,    46,     0,     0,     0,     0,     0,     0,     0,    54,
       0,    38,     9,     0,     0,     0,     0,    26,    28,     0,
       0,    50,     0,    43,     0,     0,    56,     0,    55,    64,
      45,     0,     0,    56,     0,    55,     0,     0,     0,     0,
       0,     0,    51,     0,    44,    48,    52,     0,     0,    45,
       0,    47,    58,     0,    10,    57,    11,    12,     0,     0,
       0,     0,     0,     0,    58,    57,     0,     0,    17,     0,
       0,    53,     0,     0,     0,    49,    16,    63,    13,    59,
      60,    61,    62,    14,    15,    39,     0,    20,    19,    18,
       0,     0,    21,    23,    27,    29,     0,     0,     0,     0,
       0,     0,    22,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -75,   -13,   -75,   -75,   -75,   -74,   -75,   -75,
      -8,   -75,   -75,    79,   -22,   -75,   160,   -75,   -75,   -75,
     -18,    17,   -17,   115,   -55
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    52,    30,    48,    31,    78,   136,   137,
      13,    87,    88,    22,    14,     8,    32,     5,    33,    34,
      35,    36,    37,    69,    70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,    16,    29,   107,    89,    43,    63,     6,    40,    23,
      93,    50,    40,    57,    58,    60,     7,     1,    82,    17,
      54,    51,    43,    41,    24,    79,   111,    41,    42,    25,
      61,    26,    56,    27,     1,   115,    84,    28,    23,    86,
      91,   102,    18,   119,   120,   121,   122,    15,    49,   103,
     128,   100,   101,    24,    55,    79,    23,    38,    25,    62,
      26,    28,    27,     1,   140,   141,    28,   110,   129,    10,
     112,    24,    85,    23,    11,    64,    25,    12,    26,    44,
      27,     1,    19,    20,    28,    65,    21,   127,    24,   132,
     133,    66,    45,    25,    72,    26,    67,    27,     1,    68,
      46,    28,    98,    72,    65,   130,   131,    99,   100,   101,
      73,    47,    53,    59,     9,    74,    79,    79,    75,    73,
      10,    54,   117,    77,    74,    11,    98,    75,    12,    10,
      55,    99,   100,   101,    11,    97,    98,    12,    56,    80,
      71,    99,   100,   101,    81,    83,    42,    90,    92,    94,
      95,    96,   104,   106,   105,   108,   113,   114,   109,   116,
       4,    76,   118,   123,   124,   125,   126,   134,   135,   138,
     139,     0,   142,   143
};

static const yytype_int16 yycheck[] =
{
      22,     9,    15,    77,    59,    23,    17,     0,     4,     4,
      65,    28,     4,    11,    12,     4,    13,    29,    17,    19,
      31,    16,    40,    19,    19,    47,    81,    19,    24,    24,
      19,    26,    31,    28,    29,    90,    54,    32,     4,    56,
      17,    19,    14,    98,    99,   100,   101,    15,    19,    27,
      16,    24,    25,    19,    31,    77,     4,    14,    24,    42,
      26,    32,    28,    29,   138,   139,    32,    80,    16,    19,
      83,    19,    55,     4,    24,     3,    24,    27,    26,    21,
      28,    29,     5,     6,    32,    13,     9,   109,    19,    11,
      12,    19,    19,    24,     3,    26,    24,    28,    29,    27,
      13,    32,    18,     3,    13,   113,   114,    23,    24,    25,
      19,    13,    30,    21,    13,    24,   138,   139,    27,    19,
      19,    31,    14,    13,    24,    24,    18,    27,    27,    19,
      31,    23,    24,    25,    24,    17,    18,    27,    31,    15,
      21,    23,    24,    25,    21,    15,    24,    21,    19,    17,
      19,    17,    19,    14,    19,    14,    13,    13,    79,    17,
       0,    46,    17,    17,    17,    17,    14,    14,    14,    13,
      13,    -1,    14,    14
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    35,    36,    50,    51,     0,    13,    49,    13,
      19,    24,    27,    44,    48,    15,    44,    19,    14,     5,
       6,     9,    47,     4,    19,    24,    26,    28,    32,    37,
      38,    40,    50,    52,    53,    54,    55,    56,    14,    48,
       4,    19,    24,    54,    21,    19,    13,    13,    39,    19,
      56,    16,    37,    30,    31,    31,    31,    11,    12,    21,
       4,    19,    55,    17,     3,    13,    19,    24,    27,    57,
      58,    21,     3,    19,    24,    27,    57,    13,    41,    48,
      15,    21,    17,    15,    54,    55,    56,    45,    46,    58,
      21,    17,    19,    58,    17,    19,    17,    17,    18,    23,
      24,    25,    19,    27,    19,    19,    14,    41,    14,    47,
      37,    58,    37,    13,    13,    58,    17,    14,    17,    58,
      58,    58,    58,    17,    17,    17,    14,    48,    16,    16,
      44,    44,    11,    12,    14,    14,    42,    43,    13,    13,
      41,    41,    14,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    37,    37,    37,    37,    37,    37,
      38,    38,    38,    38,    38,    38,    38,    39,    40,    40,
      41,    42,    41,    43,    41,    44,    45,    44,    46,    44,
      47,    47,    47,    48,    48,    48,    49,    51,    50,    52,
      53,    53,    53,    54,    54,    54,    54,    55,    55,    55,
      55,    56,    56,    56,    56,    57,    57,    57,    57,    58,
      58,    58,    58,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     5,     5,     5,     5,     3,     5,     5,
       3,     0,     8,     0,     8,     3,     0,     8,     0,     8,
       1,     1,     1,     1,     2,     1,     3,     0,     6,     5,
       1,     1,     1,     3,     3,     3,     1,     4,     3,     3,
       1,     3,     3,     3,     1,     1,     1,     2,     2,     3,
       3,     3,     3,     3,     1
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
#line 133 "analysGramPointers.yacc" /* yacc.c:1646  */
    {printf("\n Succesful test");}
#line 1451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 151 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
										if( lookupType((yyvsp[-3].variable)) == 0 && lookupType((yyvsp[-1].variable)) == 0 ) //Both variables exist and are integers
										{		
											sprintf(snum, "%d", lookup((yyvsp[-3].variable)));
											sprintf(snum2, "%d", lookup((yyvsp[-1].variable)));
											setValueByName((yyvsp[-3].variable), getValueByName((yyvsp[-1].variable))); 	//Sets the value
											insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
										    cp++;			
										}
										else
										{
											if( lookupType((yyvsp[-3].variable)) == 2 && lookupType((yyvsp[-1].variable)) == 2 ) //Both variables exist and are pointers
											{	
												sprintf(snum, "%d", lookup((yyvsp[-3].variable)));
												sprintf(snum2, "%d", lookup((yyvsp[-1].variable)));
												setValueByName((yyvsp[-3].variable), getValueByName((yyvsp[-1].variable))); 	//Sets the value
												insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
											    cp++;
											}
											else
											{
												strcpy( errTab[ce].error, "Invalid assignation.\n" );
												errTab[ce].line = cp;
												ce++;
											}
										}
									}
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 178 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
										if( lookupType((yyvsp[-3].variable)) == 0 ) 	//Variable exists and is integer
										{			
											sprintf(snum, "%d", lookup((yyvsp[-3].variable)));
											sprintf(snum2, "%d", (yyvsp[-1].nb));
											setValueByName((yyvsp[-3].variable), (yyvsp[-1].nb)); 	//Sets the value
										    insert_Instruction( "6", snum, snum2, "", "", cp ); //AFC @result constant 
										    cp++;			
										}
										else
										{
											strcpy( errTab[ce].error, "Trying to assign value to a constant, pointer or variable that doesn't exist.\n" );
											errTab[ce].line = cp;
											ce++;
										}	
									}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 194 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
										if(lookupType((yyvsp[-3].variable)) == 0 && !pointer_value)	//Variable exists and is integer and the expression is not for pointer
										{				
											if( temp1_flag )	//value is in temp1
												sprintf(auxString, "0temp1");	
											else
												sprintf(auxString, "0temp2");	

											sprintf(snum, "%d", lookup((yyvsp[-3].variable)));
											sprintf(snum2, "%d", lookup(auxString));
											setValueByName((yyvsp[-3].variable), getValueByName(auxString)); 	//Sets the value
											insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
										    cp++;			
										}
										else
										{
											if(lookupType((yyvsp[-3].variable)) == 2) //Variable exists and is pointer
											{
												if(	pointer_value ) //The expression is correct for the pointer
												{	
													if( temp1_flag )	//value is in temp1
														sprintf(auxString, "0temp1");	
													else
														sprintf(auxString, "0temp2");	

													sprintf(snum, "%d", lookup((yyvsp[-3].variable)));
													sprintf(snum2, "%d", lookup(auxString));
													setValueByName((yyvsp[-3].variable), getValueByName(auxString)); 	//Sets the value
													insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
												    cp++;	
												}
												else
												{
													strcpy( errTab[ce].error, "Invalid pointer convertion.\n" );
													errTab[ce].line = cp;
													ce++;
												}
											}
											else
											{
												strcpy( errTab[ce].error, "Trying to assign number value to a constant or variable that doesn't exist.\n" );
												errTab[ce].line = cp;
												ce++;
											}
										}
										pointer_value_flag = false; //reset variable
										pointer_value_flag2 = false; //reset variable
									}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 242 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
												if(lookupType((yyvsp[-4].variable)) != 2 && lookupType((yyvsp[-4].variable)) != -1 && lookupType((yyvsp[-1].variable)) == 2)	//Variables exist, first variable is not a pointer, and second var is a pointer
												{	
													if( lookupAddress(getValueByName((yyvsp[-1].variable))) != -1 ) //Pointed address is valid
													{
														sprintf(snum, "%d", lookup((yyvsp[-4].variable)));
														sprintf(snum2, "%d", lookup((yyvsp[-1].variable)));	
														setValueByName((yyvsp[-4].variable), getValueByName(lookupName(getValueByName((yyvsp[-1].variable))))); 	//Sets the value	
														insert_Instruction( "D", snum, snum2, "", "", cp ); //PCOP @result @operand1 copies the value stored at @operand1.value to @result
													    cp++;		
													}
													else
													{
														strcpy( errTab[ce].error, "The pointer '" );
														strcat( errTab[ce].error, (yyvsp[-1].variable) );
														strcat( errTab[ce].error, "' points to an invalid address.\n" );		
														errTab[ce].line = cp;
														ce++;
													}
												}
												else
												{
													strcpy( errTab[ce].error, "Invalid pointer assignment.\n" );
													errTab[ce].line = cp;
													ce++;
												}
											}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 269 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
												if(lookupType((yyvsp[-3].variable)) == 2 && lookupType((yyvsp[-1].variable)) != -1 && lookupType((yyvsp[-1].variable)) != 2)	//Variables exist, first variable is a pointer, and second var is not pointer
												{														
													if( lookupAddress(getValueByName((yyvsp[-3].variable))) != -1 ) //Pointed address is valid
													{
														sprintf(snum, "%d", lookup((yyvsp[-3].variable)));		
														sprintf(snum2, "%d", lookup((yyvsp[-1].variable)));	
														setValueByName(lookupName(getValueByName((yyvsp[-3].variable))), getValueByName((yyvsp[-1].variable))); 	//Sets the value	
														insert_Instruction( "E", snum, snum2, "", "", cp ); //IPCOP @result @operand1 copies the value stored at @operand1 to @result.value
													    cp++;		
													}
													else
													{
														strcpy( errTab[ce].error, "The pointer '" );
														strcat( errTab[ce].error, (yyvsp[-3].variable) );
														strcat( errTab[ce].error, "' points to an invalid address.\n" );		
														errTab[ce].line = cp;
														ce++;
													}
												}
												else
												{
													strcpy( errTab[ce].error, "Invalid pointer assignment.\n" );
													errTab[ce].line = cp;
													ce++;
												}
											}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 296 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
												if(lookupType((yyvsp[-3].variable)) == 2 )	//Variable exists and is pointer
												{			
													if( lookupAddress(getValueByName((yyvsp[-3].variable))) != -1 ) //Pointed address is valid
													{
														if( temp1_flag )	//value is in temp1
															sprintf(auxString, "0temp1");	
														else
															sprintf(auxString, "0temp2");	

														sprintf(snum, "%d", lookup(auxString));
														sprintf(snum2, "%d", (yyvsp[-1].nb));	
														setValueByName(auxString, (yyvsp[-1].nb)); 	//Sets the value	
														insert_Instruction( "6", snum, snum2, "", "", cp ); //AFC @result num 
													    cp++;	

														sprintf(snum, "%d", lookup((yyvsp[-3].variable)));		
														sprintf(snum2, "%d", lookup(auxString));
														setValueByName(lookupName(getValueByName((yyvsp[-3].variable))), getValueByName(auxString)); 	//Sets the value
														insert_Instruction( "E", snum, snum2, "", "", cp ); //IPCOP @result @operand1 copies the value stored at @operand1 to @result.value
													    cp++;		
													}
													else
													{
														strcpy( errTab[ce].error, "The pointer '" );
														strcat( errTab[ce].error, (yyvsp[-3].variable) );
														strcat( errTab[ce].error, "' points to an invalid address.\n" );		
														errTab[ce].line = cp;
														ce++;
													}
												}
												else
												{
													strcpy( errTab[ce].error, "The pointer doesn't exist.\n" );
													errTab[ce].line = cp;
													ce++;
												}
											}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 334 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
												if(lookupType((yyvsp[-4].variable)) == 2 && lookupType((yyvsp[-1].variable)) != -1 && lookupType((yyvsp[-1].variable)) != 2)	//Both variable exist, the first is pointer, and the second is not pointer
												{				
													if( temp1_flag )	//value is in temp1
														sprintf(auxString, "0temp1");	
													else
														sprintf(auxString, "0temp2");	

													sprintf(snum, "%d", lookup(auxString));
													sprintf(snum2, "%d", lookup((yyvsp[-1].variable)));	
													setValueByName(auxString, lookup((yyvsp[-1].variable))); 	//Sets the value	
													insert_Instruction( "6", snum, snum2, "", "", cp ); //AFC @result num Copy address to result
												    cp++;	

													sprintf(snum, "%d", lookup((yyvsp[-4].variable)));
													sprintf(snum2, "%d", lookup(auxString));
													setValueByName((yyvsp[-4].variable), getValueByName(auxString)); 										//Sets the value of the pointer		
													insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
												    cp++;	
												}
												else
												{
													strcpy( errTab[ce].error, "The pointer doesn't exist.\n" );
													errTab[ce].line = cp;
													ce++;
												}
											}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 363 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
									depth++;	//Used for variable creation

									(yyval.nb) = cp;
									cp++;
									if_iter_stack = push(if_begin_count, if_iter_stack);	//store if begin iterations to later assign if begin line
									if_begin_count = 0;

									else_iter_stack = push(else_begin_count, else_iter_stack);	//store else begin iterations to later assign if begin line
									else_begin_count = 0;
								}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 376 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
													sprintf(snum , "%d", cp);									//Obtain else body end
													insert_Instruction( "JMP", snum, "", "", "", (yyvsp[-4].nb)-1 );		//If ended, jump to else body end
												}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 380 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
													sprintf(snum , "%d", cp+1);												//next instruction to ignore else jmp
													insert_Instruction( "JMF", "@X", snum, "", "", (yyvsp[-3].nb) );				//If statement is false jump to else body

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

													depth--;	//Used for variable creation
												}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 417 "analysGramPointers.yacc" /* yacc.c:1646  */
    {					
															sprintf(snum, "%d", lookup("0temp1"));
															sprintf(snum2, "%d", lookup("0temp2"));	
															insert_Instruction( (yyvsp[-1].variable), "@X", snum, snum2, "", cp );			//COMPARISSON
															cp++;
														}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 423 "analysGramPointers.yacc" /* yacc.c:1646  */
    {									
											sprintf(snum , "%d", cp+2);	
											insert_Instruction( "JMF", "@X", snum, "", "", cp );					//If statement is false jump to the next statement
											cp++;

											if_begin_count++;
											if_stack = push(cp, if_stack);												//Remember this line to later add the if begin line
											insert_Instruction( "JMP", "IF BEGIN", "", "", "", cp );					//If statement is true jump to the last if and return true value
											cp++;
										}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 433 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
											sprintf(snum , "%d", cp+2);	
					 						insert_Instruction( "JMF", "@X", snum, "", "", cp );					//If statement is false jump to the next statement
											cp++;	

											if_begin_count++;
											if_stack = push(cp, if_stack);												//Remember this line to later add the if begin line
											insert_Instruction( "JMP", "IF BEGIN", "", "", "", cp );					//If statement is true jump to the last if and return true value
											cp++;
										}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 443 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
											else_begin_count++;
											else_stack = push(cp, else_stack);											//Remember this line to later add the else begin line
											insert_Instruction( "JMF", "@X", "ELSE BEGIN", "", "", cp );			//If statement is false jump to the else body
											cp++;
										}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 449 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
											else_begin_count++;
											else_stack = push(cp, else_stack);											//Remember this line to later add the else begin line
											insert_Instruction( "JMF", "@X", "ELSE BEGIN", "", "", cp );			//If statement is false jump to the else body
											cp++;											
										}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 460 "analysGramPointers.yacc" /* yacc.c:1646  */
    {					
															sprintf(snum, "%d", lookup("0temp1"));
															sprintf(snum2, "%d", lookup("0temp2"));	
															insert_Instruction( (yyvsp[-1].variable), "@X", snum, snum2, "", cp );			//COMPARISSON
															cp++;
														}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 466 "analysGramPointers.yacc" /* yacc.c:1646  */
    {											
												sprintf(snum , "%d", cp+2);										
												insert_Instruction( "JMF", "@X", snum, "", "", cp );				//If statement is false, jump to next condition
												cp++;	

												while_begin_count++;
												while_begin_stack = push(cp, while_begin_stack);					//Remember this line to later add the while begin line
												insert_Instruction( "JMP", "WHILE BEGIN", "", "", "", cp );			//Jump to the begining of the while
												cp++;
											}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 476 "analysGramPointers.yacc" /* yacc.c:1646  */
    {											
												sprintf(snum , "%d", cp+2);										
												insert_Instruction( "JMF", "@X", snum, "", "", cp );				//If statement is false, jump to next condition
												cp++;	

												while_begin_count++;
												while_begin_stack = push(cp, while_begin_stack);					//Remember this line to later add the while begin line
												insert_Instruction( "JMP", "WHILE BEGIN", "", "", "", cp );			//Jump to the begining of the while
												cp++;
											}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 486 "analysGramPointers.yacc" /* yacc.c:1646  */
    {		
												while_end_count++;
												while_end_stack = push(cp, while_end_stack);						//Remember this line to later add the while end line				
												insert_Instruction( "JMF", "@X", "WHILE END", "", "", cp );			//If statement is false, jump to the end of the while
												cp++;	
											}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 492 "analysGramPointers.yacc" /* yacc.c:1646  */
    {			
												while_end_count++;
												while_end_stack = push(cp, while_end_stack);						//Remember this line to later add the while end line			
												insert_Instruction( "JMF", "@X", "WHILE END", "", "", cp );			//If statement is false, jump to the end of the while
												cp++;	
											}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 503 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
							(yyval.variable)="9";	//INF
						}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 506 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
							(yyval.variable)="A";	//SUP
						}
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 509 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
							(yyval.variable)="B";	//EQU
						}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 515 "analysGramPointers.yacc" /* yacc.c:1646  */
    {			
								if( lookup((yyvsp[0].variable)) != -1 && lookupType((yyvsp[0].variable)) != 2	)		//var exists and is not pointer
								{	
									if( !temp1_flag )
									{
										temp1_flag = true;
										strcpy( auxString, "0temp1" );
									}
									else{
										temp1_flag = false;		
										strcpy( auxString, "0temp2" );
									}

									sprintf(snum, "%d", lookup(auxString));
									sprintf(snum2, "%d", lookup((yyvsp[0].variable)));		
									setValueByName(auxString, getValueByName((yyvsp[0].variable))); 	//Sets the value	
									insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
									cp++;
		
									sprintf(snum, "%d", lookup(auxString));
									(yyval.variable)=snum;
								}
								else
								{
									strcpy( errTab[ce].error, "The variable '" );
									strcat( errTab[ce].error, (yyvsp[0].variable) );
									strcat( errTab[ce].error, "' does not exist or is invalid.\n" );		
									errTab[ce].line = cp;
									ce++;
								}	
							}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 546 "analysGramPointers.yacc" /* yacc.c:1646  */
    {			
									if(lookup((yyvsp[0].variable)) != -1 && lookup((yyvsp[0].variable)) == 2	)		//var exists and is a pointer
									{	
										if( lookupAddress(getValueByName((yyvsp[0].variable))) != -1 ) //Pointed address is valid
										{
											if( !temp1_flag )
											{
												temp1_flag = true;
												strcpy( auxString, "0temp1" );
											}
											else{
												temp1_flag = false;		
												strcpy( auxString, "0temp2" );
											}

											sprintf(snum, "%d", lookup(auxString));
											sprintf(snum2, "%d", lookup((yyvsp[0].variable)));	
											setValueByName(auxString, getValueByName(lookupName(getValueByName((yyvsp[0].variable))))); 	//Sets the value	
											insert_Instruction( "D", snum, snum2, "", "", cp ); //PCOP @result @operand1 copies the value stored at @operand1.value to @result 
											cp++;
				
											sprintf(snum, "%d", lookup(auxString));
											(yyval.variable)=snum;			
										}
										else
										{
											strcpy( errTab[ce].error, "The pointer '" );
											strcat( errTab[ce].error, (yyvsp[0].variable) );
											strcat( errTab[ce].error, "' points to an invalid address.\n" );		
											errTab[ce].line = cp;
											ce++;
										}										
									}
									else
									{
										strcpy( errTab[ce].error, "The variable " );
										strcat( errTab[ce].error, (yyvsp[0].variable) );
										strcat( errTab[ce].error, " does not exist.\n" );		
										errTab[ce].line = cp;
										ce++;
									}	
								}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 588 "analysGramPointers.yacc" /* yacc.c:1646  */
    {	
								if( !temp1_flag )
								{
									temp1_flag = true;
									strcpy( auxString, "0temp1" );
								}
								else{
									temp1_flag = false;		
									strcpy( auxString, "0temp2" );
								}

								sprintf(snum, "%d", lookup(auxString));
								sprintf(snum2, "%d", (yyvsp[0].nb));	
								setValueByName(auxString, (yyvsp[0].nb)); 	//Sets the value	
								insert_Instruction( "6", snum, snum2, "", "", cp ); //AFC @result num 
								cp++;
	
								sprintf(snum, "%d", lookup(auxString));
								(yyval.variable)=snum;
							}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 610 "analysGramPointers.yacc" /* yacc.c:1646  */
    {											
											while_last_cond = push(cp, while_last_cond);	//Store while begin
											cp++;	

											while_begin_iter_stack = push(while_begin_count, while_begin_iter_stack);	//store while begin iterations to later assign while begin line
											while_begin_count = 0;

											while_end_iter_stack = push(while_end_count, while_end_iter_stack);			//store while end iterations to later assign while end line
											while_end_count = 0;	
										}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 622 "analysGramPointers.yacc" /* yacc.c:1646  */
    {	
														depth++;	//Used for variable creation
														(yyvsp[0].nb)=cp;										//Save while begin
			
													}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 627 "analysGramPointers.yacc" /* yacc.c:1646  */
    {				
														int whileBegin = while_last_cond.stk[while_last_cond.top];
														while_last_cond = pop(while_last_cond);							//pop the value		

														sprintf(snum , "%d", cp+1);										
														insert_Instruction( "JMF", "@X", snum, "", "",  whileBegin);	//Jump to while end in case condition is not met

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

														depth--;	//Used for variable creation
													}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 666 "analysGramPointers.yacc" /* yacc.c:1646  */
    {	
											sprintf(snum, "%d", (yyvsp[-2].nb));
											insert_Instruction( "C", snum, "", "", "", cp );	//PRI @result
											cp++;
											pointer_value_flag = false; //reset variable
											pointer_value_flag2 = false; //reset variable
										}
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 682 "analysGramPointers.yacc" /* yacc.c:1646  */
    {				
									if(lookup((yyvsp[-2].variable)) == -1 && !pointer_value)	//Variable doesn't exist and the expr is not for pointers
									{
										insert((yyvsp[-2].variable), 0, depth);		//new int

										sprintf(snum, "%d", lookup((yyvsp[-2].variable)));
										sprintf(snum2, "%d", lookupType((yyvsp[-2].variable)));
										insert_Instruction( "ALLOUER", snum, (yyvsp[-2].variable), snum2, "", cp ); //ALLOUER @var varName varType 
									    cp++;

									    if( temp1_flag )	//Last value was stored in temp1
											strcpy( auxString, "0temp1");
										else
											strcpy( auxString, "0temp2");

										sprintf(snum, "%d", lookup((yyvsp[-2].variable)));
										sprintf(snum2, "%d", lookup(auxString));
										setValueByName((yyvsp[-2].variable), getValueByName(auxString)); 	//Sets the value
										insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
									    cp++;											    		
									}else
									{	
										if(pointer_value)	
										{						
											strcpy( errTab[ce].error, "Invalid convertion.\n" );
											errTab[ce].line = cp;
											ce++;													
										}	
										else
										{									
											strcpy( errTab[ce].error, "Variable already exists.\n" );
											errTab[ce].line = cp;
											ce++;
										}
									}
									pointer_value_flag = false; //reset variable
									pointer_value_flag2 = false; //reset variable
								}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 720 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
									if(lookup((yyvsp[0].variable)) == -1)
									{
										insert((yyvsp[0].variable), 0, depth);		//new int

										sprintf(snum, "%d", lookup((yyvsp[0].variable)));
										sprintf(snum2, "%d", lookupType((yyvsp[0].variable)));
										insert_Instruction( "ALLOUER", snum, (yyvsp[0].variable), snum2, "", cp ); //ALLOUER @var varName varType 
									    cp++;

									}else
									{												
										strcpy( errTab[ce].error, "Variable already exists.\n" );
										errTab[ce].line = cp;
										ce++;
									}
								}
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 741 "analysGramPointers.yacc" /* yacc.c:1646  */
    {				
									if(lookup((yyvsp[-2].variable)) == -1 && pointer_value) //Variable exists and the expression is correct
									{
										insert((yyvsp[-2].variable), 2, depth);		//new pointer

										sprintf(snum, "%d", lookup((yyvsp[-2].variable)));
										sprintf(snum2, "%d", lookupType((yyvsp[-2].variable)));
										insert_Instruction( "ALLOUER", snum, (yyvsp[-2].variable), snum2, "", cp ); //ALLOUER @var varName varType 
									    cp++;

									    if( temp1_flag )	//temp1 is not being used
											sprintf(auxString, "0temp1");	
										else
											sprintf(auxString, "0temp2");		

										sprintf(snum, "%d", lookup((yyvsp[-2].variable)));
										sprintf(snum2, "%d", lookup(auxString));		
										setValueByName((yyvsp[-2].variable), getValueByName(auxString)); 	//Sets the value
										insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
									    cp++;		
									}else
									{				
										if(!pointer_value)
										{				
											strcpy( errTab[ce].error, "Invalid expression.\n" );
											errTab[ce].line = cp;
											ce++;
										}else
										{							
											strcpy( errTab[ce].error, "Variable %s already exists.\n" );
											errTab[ce].line = cp;
											ce++;
										}
									}
									pointer_value_flag = false; //reset variable
									pointer_value_flag2 = false; //reset variable
								}
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 778 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
									if(lookup((yyvsp[0].variable)) == -1)
									{
										insert((yyvsp[0].variable), 2, depth);			//new pointer

										sprintf(snum, "%d", lookup((yyvsp[0].variable)));
										sprintf(snum2, "%d", lookupType((yyvsp[0].variable)));
										insert_Instruction( "ALLOUER", snum, (yyvsp[0].variable), snum2, "", cp ); //ALLOUER @var varName varType 
									    cp++;

									}else
									{												
										strcpy( errTab[ce].error, "Variable already exists.\n" );
										errTab[ce].line = cp;
										ce++;
									}	
								}
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 799 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
									if(lookup((yyvsp[-2].variable)) == -1 && !pointer_value) //Variable exists and the expression is correct
									{
										insert((yyvsp[-2].variable), 1, depth);		//new const		

										sprintf(snum, "%d", lookup((yyvsp[-2].variable)));
										sprintf(snum2, "%d", lookupType((yyvsp[-2].variable)));
										insert_Instruction( "ALLOUER", snum, (yyvsp[-2].variable), snum2, "", cp ); //ALLOUER @var varName varType 
									    cp++;											

									    if( temp1_flag )	//temp1 is not being used
											sprintf(auxString, "0temp1");	
										else
											sprintf(auxString, "0temp2");	

										sprintf(snum, "%d", lookup((yyvsp[-2].variable)));
										sprintf(snum2, "%d", lookup(auxString));		
										setValueByName((yyvsp[-2].variable), getValueByName(auxString)); 	//Sets the value
										insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
									    cp++;		
									}else
									{											
												
										if(pointer_value)	
										{						
											strcpy( errTab[ce].error, "Invalid convertion.\n" );
											errTab[ce].line = cp;
											ce++;													
										}	
										else
										{									
											strcpy( errTab[ce].error, "Variable %s already exists.\n" );
											errTab[ce].line = cp;
											ce++;
										}
									}
									pointer_value_flag = false; //reset variable
									pointer_value_flag2 = false; //reset variable
								}
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 838 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
									if(lookup((yyvsp[0].variable)) == -1)
									{
										insert((yyvsp[0].variable), 1, depth);		//new const

										sprintf(snum, "%d", lookup((yyvsp[0].variable)));
										sprintf(snum2, "%d", lookupType((yyvsp[0].variable)));
										insert_Instruction( "ALLOUER", snum, (yyvsp[0].variable), snum2, "", cp ); //ALLOUER @var varName varType 
									    cp++;

									}else
									{												
										strcpy( errTab[ce].error, "Variable already exists.\n" );
										errTab[ce].line = cp;
										ce++;
									}
								}
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 860 "analysGramPointers.yacc" /* yacc.c:1646  */
    {
								if( !pointer_value_flag )	//pointer value hasn't been initialized
								{
									pointer_value_flag = true;
									pointer_value = false; 			//not a pointer expression
								}
												
								if( !temp1_flag )	//temp1 is not being used
								{
									temp1_flag = true;
									sprintf(auxString, "0temp1");	
								}else
								{
									temp1_flag = false;
									sprintf(auxString, "0temp2");	
								}	


								sprintf(snum, "%d", lookup(auxString));
								sprintf(snum2, "%d", (yyvsp[0].nb));
								setValueByName(auxString, (yyvsp[0].nb)); 	//Sets the value
								insert_Instruction( "6", snum, snum2, "", "", cp ); //COP @result @operand1 
								cp++;

								(yyval.nb) = lookup(auxString);
							}
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 886 "analysGramPointers.yacc" /* yacc.c:1646  */
    {	
								if(lookup((yyvsp[0].variable)) != -1)	//var exists
								{
									if(lookupType((yyvsp[0].variable)) != 2)	//not pointer
									{
										if( !pointer_value_flag )	//pointer value hasn't been initialized
										{
											pointer_value_flag = true;
											pointer_value = false; 			//not a pointer expression
										}

										if( !temp1_flag )	//temp1 is not being used
										{
											temp1_flag = true;
											sprintf(auxString, "0temp1");	
										}else
										{
											temp1_flag = false;
											sprintf(auxString, "0temp2");	
										}	

										sprintf(snum, "%d", lookup(auxString));
										sprintf(snum2, "%d", lookup((yyvsp[0].variable)));
										setValueByName(auxString, getValueByName((yyvsp[0].variable))); 	//Sets the value
										insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
										cp++;

										(yyval.nb) = lookup(auxString);	//temp contains Address of the pointer(to print the address of the pointed variable)
									}
									else
									{
										if(	pointer_value_flag2 )
										{
											pointer_value = false; //pointer expression wrong
										}
										else{
											if( !pointer_value_flag || !pointer_value )	//pointer value hasn't been initialized or pointer value was false
											{
												pointer_value_flag = true;
												pointer_value = true; //pointer expression
												pointer_value_flag2 = true;
											}
										}	

										(yyval.nb) = lookup((yyvsp[0].variable));	//Address of the pointer(to print the address of the pointed variable)
									}
								}
								else
								{
									strcpy( errTab[ce].error, "The variable " );
									strcat( errTab[ce].error, (yyvsp[0].variable) );
									strcat( errTab[ce].error, " does not exist.\n" );		
									errTab[ce].line = cp;
									ce++;
								}
							}
#line 2385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 942 "analysGramPointers.yacc" /* yacc.c:1646  */
    {	
								if( lookupType((yyvsp[0].variable)) == 2 )	//var exists and is pointer
								{
									if( lookupAddress(getValueByName((yyvsp[0].variable))) != -1 ) //Pointed address is valid
									{
										if( !pointer_value_flag )	//pointer value hasn't been initialized
										{
											pointer_value_flag = true;
											pointer_value = false; 			//not a pointer expression
										}
												
										if( !temp1_flag )	//temp1 is not being used
										{
											temp1_flag = true;
											sprintf(auxString, "0temp1");	
										}else
										{
											temp1_flag = false;
											sprintf(auxString, "0temp2");	
										}						

										sprintf(snum, "%d", lookup(auxString));
										sprintf(snum2, "%d", lookup((yyvsp[0].variable)));		//Address of the pointer 
										setValueByName(auxString, getValueByName(lookupName(getValueByName((yyvsp[0].variable))))); 	//Sets the value
										insert_Instruction( "D", snum, snum2, "", "", cp ); //PCOP @result @operand1 
										cp++;

										(yyval.nb) = lookup(auxString);	//Address of the variable (to print value of the pointed variable)		
									}
									else
									{
										strcpy( errTab[ce].error, "The pointer '" );
										strcat( errTab[ce].error, (yyvsp[0].variable) );
										strcat( errTab[ce].error, "' points to an invalid address.\n" );		
										errTab[ce].line = cp;
										ce++;
									}
								}
								else
								{
									strcpy( errTab[ce].error, "The pointer " );
									strcat( errTab[ce].error, (yyvsp[0].variable) );
									strcat( errTab[ce].error, " does not exist.\n" );		
									errTab[ce].line = cp;
									ce++;
								}
							}
#line 2437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 989 "analysGramPointers.yacc" /* yacc.c:1646  */
    {	
										if( lookupType((yyvsp[0].variable)) != -1 )	//var exists
										{
											if(	pointer_value_flag2 )
											{
												pointer_value = false; //pointer expression wrong
											}
											else{
												if( !pointer_value_flag || !pointer_value )	//pointer value hasn't been initialized or pointer value was false
												{
													pointer_value_flag = true;
													pointer_value = true; //pointer expression
													pointer_value_flag2 = true;
												}
											}

											if( !temp1_flag )
											{
												temp1_flag = true;

												sprintf(snum, "%d", lookup("0temp1"));
												sprintf(snum2, "%d", lookup((yyvsp[0].variable)));		//Address of the pointer 
												setValueByName("0temp1", lookup((yyvsp[0].variable))); 	//Sets the value
												insert_Instruction( "6", snum, snum2, "", "", cp ); //AFC @result num Copy address to result
												cp++;

												(yyval.nb) = lookup("0temp1");
											}else
											{
												temp1_flag = false;

												sprintf(snum, "%d", lookup("0temp2"));
												sprintf(snum2, "%d", lookup((yyvsp[0].variable)));		//Address of the pointer 
												setValueByName("0temp2", lookup((yyvsp[0].variable))); 	//Sets the value
												insert_Instruction( "6", snum, snum2, "", "", cp ); //AFC @result num Copy address to result
												cp++;

												(yyval.nb) = lookup("0temp2");
											}
										}
										else
										{
											strcpy( errTab[ce].error, "The variable " );
											strcat( errTab[ce].error, (yyvsp[0].variable) );
											strcat( errTab[ce].error, " does not exist.\n" );		
											errTab[ce].line = cp;
											ce++;
										}
									}
#line 2491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1040 "analysGramPointers.yacc" /* yacc.c:1646  */
    { 		
										 if( temp1_flag )	//value is in temp1
											sprintf(auxString, "%d", lookup("0temp1"));
										else
											sprintf(auxString, "%d", lookup("0temp2"));
										sscanf(auxString, "%d", &auxNum);

										 sprintf(snum, "%d", (yyvsp[-2].nb));
										 sprintf(snum2, "%d", (yyvsp[0].nb));;
										 setValueByName( lookupName(auxNum), getValueByName(lookupName((yyvsp[-2].nb)))+getValueByName(lookupName((yyvsp[0].nb))) );
										 insert_Instruction( "1", auxString, snum, snum2, "", cp ); //ADD @result @operand1 @operand2
									     cp++;

									     (yyval.nb)=auxNum;
									}
#line 2511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1055 "analysGramPointers.yacc" /* yacc.c:1646  */
    {	
										 if( temp1_flag )	//value is in temp1
											sprintf(auxString, "%d", lookup("0temp1"));
										else
											sprintf(auxString, "%d", lookup("0temp2"));
										sscanf(auxString, "%d", &auxNum);

										 sprintf(snum, "%d", (yyvsp[-2].nb));
										 sprintf(snum2, "%d", (yyvsp[0].nb));
										 setValueByName( lookupName(auxNum), getValueByName(lookupName((yyvsp[-2].nb)))-getValueByName(lookupName((yyvsp[0].nb))) );
										 insert_Instruction( "3", auxString, snum, snum2, "", cp ); //SOU @result @operand1 @operand2
									     cp++;

									     (yyval.nb)=auxNum;
									}
#line 2531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1070 "analysGramPointers.yacc" /* yacc.c:1646  */
    {								
										 if( temp1_flag )	//value is in temp1
											sprintf(auxString, "%d", lookup("0temp1"));
										else
											sprintf(auxString, "%d", lookup("0temp2"));
										sscanf(auxString, "%d", &auxNum);

										 sprintf(snum, "%d", (yyvsp[-2].nb));
										 sprintf(snum2, "%d", (yyvsp[0].nb));;
										 setValueByName( lookupName(auxNum), getValueByName(lookupName((yyvsp[-2].nb)))*getValueByName(lookupName((yyvsp[0].nb))) );
										 insert_Instruction( "2", auxString, snum, snum2, "", cp ); //MUL @result @operand1 @operand2
									     cp++;

									     (yyval.nb)=auxNum;
									}
#line 2551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1085 "analysGramPointers.yacc" /* yacc.c:1646  */
    { 
										if( temp1_flag )	//value is in temp1
											sprintf(auxString, "%d", lookup("0temp1"));
										else
											sprintf(auxString, "%d", lookup("0temp2"));
										sscanf(auxString, "%d", &auxNum);

										 sprintf(snum, "%d", (yyvsp[-2].nb));
										 sprintf(snum2, "%d", (yyvsp[0].nb));
										 setValueByName( lookupName(auxNum), getValueByName(lookupName((yyvsp[-2].nb)))/getValueByName(lookupName((yyvsp[0].nb))) );
										 insert_Instruction( "4", auxString, snum, snum2, "", cp ); //DIV @result @operand1 @operand2
									     cp++;

									     (yyval.nb)=auxNum;
									}
#line 2571 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2575 "y.tab.c" /* yacc.c:1646  */
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
#line 1118 "analysGramPointers.yacc" /* yacc.c:1906  */


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

	initializeSymtab(); //Sets parameters like temporal variables, etc..

	//Instruction (label) table
	int **lableTable = malloc(instSIZE * 4 * sizeof(int));

	//Initialization of the label table
	int i;
	for(i = 0; i < instSIZE; i++)
	    lableTable[i] = malloc(4 * sizeof(int));


	printf("\nParser V2.0\n\n");

	fp = fopen("assOutput.out","w");


	fprintf(fp, "%d", lookup("0temp1") );

	insert("a", 0, 0);
	//setValueByName("a", 30);
	insert("b", 0, 0);
	delete("b");
	//setValueByName("b", 40);
	insert("Pa", 2, 0);
	//setValueByName("Pa", lookup("a"));
	insert("Pb", 2, 0);
	insert("Pc", 2, 0);
	//setValueByName("Pc", 16);

	delete("a");
	insert("c", 1, 0);
	insert("d", 0, 0);
	insert("e", 1, 0);
	delete("c");
	insert("g", 1, 0);


	yyparse();
	symtab_print(fp);
	print_Label_Table();
	print_Error_Table();
	fprintf(fp, "Number of lines : %d\n", cp+1); 
	fclose(fp);
	return 0;
}




/*TODO: 
	Pointers:
		- On CondValue	 Pointer comparisson is not implemented
	If: 	
			- Conditions must be like: ((cond)||(cond))  or  ((cond)||((cond)||(cond)))
	While:
			- Conditions must be like: ((cond)||(cond))  or  ((cond)||((cond)||(cond)))
	Errors:
		- When two errors arecommited one next to the other, the marker will say they were commited on the same line (because cp wasn't updated)
		- Error lines are taken from ASM code and not from the input code

	Whitespaces interfer with some tokens for example: int a; will detect the token "int " instead of "int"



NOTE:
	Temp variables are called: 0temp1 nor 0temp2	
*/
