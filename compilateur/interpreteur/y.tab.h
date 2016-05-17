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
    tRETURN = 258,
    tADD = 259,
    tMUL = 260,
    tSOU = 261,
    tDIV = 262,
    tCOP = 263,
    tAFC = 264,
    tJMP = 265,
    tJMF = 266,
    tINF = 267,
    tSUP = 268,
    tEQU = 269,
    tPRI = 270,
    tPCOP = 271,
    tIPCOP = 272,
    tCPA = 273,
    tJMPA = 274,
    tSPACE = 275,
    tALL = 276,
    tDESA = 277,
    tNUM = 278
  };
#endif
/* Tokens.  */
#define tRETURN 258
#define tADD 259
#define tMUL 260
#define tSOU 261
#define tDIV 262
#define tCOP 263
#define tAFC 264
#define tJMP 265
#define tJMF 266
#define tINF 267
#define tSUP 268
#define tEQU 269
#define tPRI 270
#define tPCOP 271
#define tIPCOP 272
#define tCPA 273
#define tJMPA 274
#define tSPACE 275
#define tALL 276
#define tDESA 277
#define tNUM 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 21 "analysGramInterpret.yacc" /* yacc.c:1909  */

	int nb;

#line 104 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
