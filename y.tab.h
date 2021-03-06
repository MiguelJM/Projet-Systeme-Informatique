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
#line 66 "analysgramAssExp.yacc" /* yacc.c:1909  */

	int nb;
	char * variable;

#line 123 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
