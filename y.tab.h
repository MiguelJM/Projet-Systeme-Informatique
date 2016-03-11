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
    tID = 260,
    tOR = 261,
    tAND = 262,
    tPO = 263,
    tPF = 264,
    tCO = 265,
    tCF = 266,
    tIF = 267,
    tWHILE = 268,
    tPV = 269,
    tPLUS = 270,
    tVAR = 271,
    tE = 272,
    tMAIN = 273,
    tSOU = 274,
    tMUL = 275,
    tDIV = 276,
    tPRINT = 277,
    tNUM = 278,
    tV = 279,
    tCONST = 280
  };
#endif
/* Tokens.  */
#define tINT 258
#define tDIF 259
#define tID 260
#define tOR 261
#define tAND 262
#define tPO 263
#define tPF 264
#define tCO 265
#define tCF 266
#define tIF 267
#define tWHILE 268
#define tPV 269
#define tPLUS 270
#define tVAR 271
#define tE 272
#define tMAIN 273
#define tSOU 274
#define tMUL 275
#define tDIV 276
#define tPRINT 277
#define tNUM 278
#define tV 279
#define tCONST 280

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 24 "analysgramAssExp.yacc" /* yacc.c:1909  */

	int nb;
	char * variable;

#line 109 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
