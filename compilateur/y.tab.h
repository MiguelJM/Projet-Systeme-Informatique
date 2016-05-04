/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 84 "analysGramPointers.yacc" /* yacc.c:1909  */

	int nb;
	char * variable;

#line 125 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
