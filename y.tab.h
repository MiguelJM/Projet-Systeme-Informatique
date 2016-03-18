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
    tE = 270,
    tMAIN = 271,
    tSOU = 272,
    tMUL = 273,
    tDIV = 274,
    tPRINT = 275,
    tNUM = 276,
    tIF = 277,
    tV = 278,
    tCONST = 279
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
#define tE 270
#define tMAIN 271
#define tSOU 272
#define tMUL 273
#define tDIV 274
#define tPRINT 275
#define tNUM 276
#define tIF 277
#define tV 278
#define tCONST 279

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 40 "analysgramAssExp.yacc" /* yacc.c:1909  */

	int nb;
	char * variable;

#line 107 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
