/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_CLASS = 258,
     TOKEN_REFERENCE = 259,
     TOKEN_STATIC = 260,
     TOKEN_INT_TYPE = 261,
     TOKEN_REAL_TYPE = 262,
     TOKEN_BOOL_TYPE = 263,
     TOKEN_STRING_TYPE = 264,
     TOKEN_VOID = 265,
     TOKEN_TRUE = 266,
     TOKEN_FALSE = 267,
     TOKEN_PRINT = 268,
     TOKEN_RETURN = 269,
     TOKEN_BREAK = 270,
     TOKEN_CONTINUE = 271,
     TOKEN_WHILE = 272,
     TOKEN_FOR = 273,
     TOKEN_TO = 274,
     TOKEN_IN = 275,
     TOKEN_STEPS = 276,
     TOKEN_LCB = 277,
     TOKEN_RCB = 278,
     TOKEN_LP = 279,
     TOKEN_RP = 280,
     TOKEN_DOT = 281,
     TOKEN_SEMICOLON = 282,
     TOKEN_ID = 283,
     TOKEN_IF = 284,
     TOKEN_ELSEIF = 285,
     TOKEN_ELSE = 286,
     TOKEN_COMMA = 287,
     TOKEN_INTEGER = 288,
     TOKEN_REAL = 289,
     TOKEN_STRING = 290,
     TOKEN_ASSIGNMENT = 291,
     TOKEN_OR = 292,
     TOKEN_AND = 293,
     TOKEN_BITWISE_OR = 294,
     TOKEN_BITWISE_AND = 295,
     TOKEN_NE = 296,
     TOKEN_EQ = 297,
     TOKEN_LE = 298,
     TOKEN_LT = 299,
     TOKEN_GE = 300,
     TOKEN_GT = 301,
     TOKEN_SHIFT_LEFT = 302,
     TOKEN_SHIFT_RIGHT = 303,
     TOKEN_SUBTRACTION = 304,
     TOKEN_ADDITION = 305,
     TOKEN_MODULO = 306,
     TOKEN_DIVISION = 307,
     TOKEN_MULTIPLICATION = 308,
     TOKEN_POWER = 309,
     TOKEN_BITWISE_NOT = 310,
     TOKEN_NOT = 311
   };
#endif
/* Tokens.  */
#define TOKEN_CLASS 258
#define TOKEN_REFERENCE 259
#define TOKEN_STATIC 260
#define TOKEN_INT_TYPE 261
#define TOKEN_REAL_TYPE 262
#define TOKEN_BOOL_TYPE 263
#define TOKEN_STRING_TYPE 264
#define TOKEN_VOID 265
#define TOKEN_TRUE 266
#define TOKEN_FALSE 267
#define TOKEN_PRINT 268
#define TOKEN_RETURN 269
#define TOKEN_BREAK 270
#define TOKEN_CONTINUE 271
#define TOKEN_WHILE 272
#define TOKEN_FOR 273
#define TOKEN_TO 274
#define TOKEN_IN 275
#define TOKEN_STEPS 276
#define TOKEN_LCB 277
#define TOKEN_RCB 278
#define TOKEN_LP 279
#define TOKEN_RP 280
#define TOKEN_DOT 281
#define TOKEN_SEMICOLON 282
#define TOKEN_ID 283
#define TOKEN_IF 284
#define TOKEN_ELSEIF 285
#define TOKEN_ELSE 286
#define TOKEN_COMMA 287
#define TOKEN_INTEGER 288
#define TOKEN_REAL 289
#define TOKEN_STRING 290
#define TOKEN_ASSIGNMENT 291
#define TOKEN_OR 292
#define TOKEN_AND 293
#define TOKEN_BITWISE_OR 294
#define TOKEN_BITWISE_AND 295
#define TOKEN_NE 296
#define TOKEN_EQ 297
#define TOKEN_LE 298
#define TOKEN_LT 299
#define TOKEN_GE 300
#define TOKEN_GT 301
#define TOKEN_SHIFT_LEFT 302
#define TOKEN_SHIFT_RIGHT 303
#define TOKEN_SUBTRACTION 304
#define TOKEN_ADDITION 305
#define TOKEN_MODULO 306
#define TOKEN_DIVISION 307
#define TOKEN_MULTIPLICATION 308
#define TOKEN_POWER 309
#define TOKEN_BITWISE_NOT 310
#define TOKEN_NOT 311




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 76 "parser3.y"
{
  char* sVal;
  int iVal;
struct Eval* evalptr;
}
/* Line 1529 of yacc.c.  */
#line 167 "parser3.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

