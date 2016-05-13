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
    tVOID = 260,
    tMIN = 261,
    tMAY = 262,
    tMINEQU = 263,
    tMAYEQU = 264,
    tEQU = 265,
    tDIF = 266,
    tOR = 267,
    tAND = 268,
    tPO = 269,
    tPF = 270,
    tCO = 271,
    tCF = 272,
    tPV = 273,
    tPLUS = 274,
    tVAR = 275,
    tSTRING = 276,
    tE = 277,
    tMAIN = 278,
    tSOU = 279,
    tMUL = 280,
    tDIV = 281,
    tPRINT = 282,
    tNUM = 283,
    tIF = 284,
    tWHILE = 285,
    tELSE = 286,
    tV = 287,
    tCONST = 288,
    tGUILLEMETS = 289
  };
#endif
/* Tokens.  */
#define tAMPERSAND 258
#define tINT 259
#define tVOID 260
#define tMIN 261
#define tMAY 262
#define tMINEQU 263
#define tMAYEQU 264
#define tEQU 265
#define tDIF 266
#define tOR 267
#define tAND 268
#define tPO 269
#define tPF 270
#define tCO 271
#define tCF 272
#define tPV 273
#define tPLUS 274
#define tVAR 275
#define tSTRING 276
#define tE 277
#define tMAIN 278
#define tSOU 279
#define tMUL 280
#define tDIV 281
#define tPRINT 282
#define tNUM 283
#define tIF 284
#define tWHILE 285
#define tELSE 286
#define tV 287
#define tCONST 288
#define tGUILLEMETS 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 92 "analysGramPointers.yacc" /* yacc.c:1909  */

	int nb;
	char * variable;

#line 127 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
