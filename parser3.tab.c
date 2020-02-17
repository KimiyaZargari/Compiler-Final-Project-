/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "parser3.y"

#include "all.h"
#include<stdio.h>
#include <stdbool.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
extern char* currentLexeme;
extern FILE* yyin;
struct Stack* tblptrStack;
extern char* intToString(int n);
FILE* symTable;
extern char* tempString;
void loadTmpVal(char * theTmp);
void saveTmpVal(char* theTmp);
void topPlsLoclNum(int quad);
extern char* mkStr(char* input);
char* currentLable;
char* assignBool(Node * trueList , Node * falseList , char* var , bool isVar, bool mkItEval);
char * lookup(char * name , struct SymbolTable* symbolTable , int * size ,int * scopeID);
char* functionCall(char* id , char * explist);
struct Eval* strToEval(char* input);
char * newQuad();
char * na;
char * newTemp();
char * newVTemp();
char * newPTemp();
char * newITemp();
char * funcName;
int ifNum = 0;
int forNum = 0;
int whileNum = 0;
char * afterIF;
char* createLable();
void defaultGotoGen();
struct Eval* idToEval(char * idName);
struct SymbolTable* secondArg(struct SymbolTable* a,struct SymbolTable* b );
void mkSymTbl(char * name);
int address[30];
char* funcID[30];
int sizeAdd[30];
int scpAdd[30];
int j = 0;
char num[5];
char snum[5];
int returnQuads[30];
int returnQuad;
int lastOfReturnQuad=0;
int tt=0;
int v=0;
int I=0;
bool inBlock = false;
int currentType;
char* returnType;
bool errorFlag=false;
Node* break_list = NULL;
Node* cont_list = NULL;
int quadTmp;
struct SymbolTable* mainSymTbl;
bool func_reached=false;
int main_quad;
struct MyNode{
     char* data;
     struct MyNode* next;
};
char temp[50];
struct MyNode* IDHead = NULL;
struct Eval * mainFunc = NULL;
struct MyNode* IDCurrent = NULL;
FILE* output;
int yylex();
void print(const char* string);
void yyerror(char* error);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 76 "parser3.y"
{
  char* sVal;
  int iVal;
struct Eval* evalptr;
}
/* Line 193 of yacc.c.  */
#line 290 "parser3.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 303 "parser3.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   660

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNRULES -- Number of states.  */
#define YYNSTATES  231

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    13,    16,    17,    25,
      26,    27,    30,    31,    33,    35,    39,    41,    44,    46,
      48,    50,    52,    54,    58,    60,    62,    63,    68,    71,
      74,    78,    79,    91,    92,    93,    97,    98,   100,   103,
     109,   111,   115,   116,   118,   121,   123,   125,   127,   129,
     131,   133,   135,   137,   139,   144,   146,   150,   156,   160,
     173,   191,   192,   193,   194,   195,   199,   200,   209,   210,
     211,   212,   213,   233,   234,   235,   236,   248,   249,   250,
     251,   258,   261,   264,   266,   268,   270,   272,   274,   276,
     278,   280,   282,   284,   286,   290,   292,   296,   300,   304,
     308,   312,   316,   320,   324,   329,   334,   338,   342,   346,
     350,   354,   358,   362,   366,   369,   372,   375,   376,   380,
     385,   389,   391,   392,   396
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    59,    61,    -1,    59,    60,    -1,    -1,
       4,    35,    -1,    61,    62,    -1,    -1,     3,    28,    63,
      22,    65,    64,    23,    -1,    -1,    -1,    65,    66,    -1,
      -1,    67,    -1,    73,    -1,    68,    70,    27,    -1,    69,
      -1,     5,    69,    -1,     6,    -1,     7,    -1,     8,    -1,
       9,    -1,    28,    -1,    70,    32,    71,    -1,    71,    -1,
      28,    -1,    -1,    28,    72,    36,   109,    -1,    68,    74,
      -1,    10,    74,    -1,     5,    10,    74,    -1,    -1,    28,
      77,    64,    75,    24,    78,    25,    80,    64,    76,    64,
      -1,    -1,    -1,    78,    32,    79,    -1,    -1,    79,    -1,
      69,    28,    -1,    64,    22,    81,    23,    64,    -1,    82,
      -1,    81,    64,    82,    -1,    -1,    27,    -1,   109,    27,
      -1,    83,    -1,    85,    -1,    86,    -1,    87,    -1,    95,
      -1,   100,    -1,   104,    -1,   107,    -1,   108,    -1,    84,
      36,   109,    27,    -1,    28,    -1,    28,    26,    28,    -1,
      13,    24,   109,    25,    27,    -1,    69,    70,    27,    -1,
      29,    90,    24,   109,    25,    64,    88,    64,    80,    89,
      64,    92,    -1,    29,    90,    24,   109,    25,    64,    88,
      64,    80,    89,    64,    92,    31,    91,    64,    80,    64,
      -1,    -1,    -1,    -1,    -1,    92,    93,    64,    -1,    -1,
      30,    24,   109,    25,    64,    80,    94,    64,    -1,    -1,
      -1,    -1,    -1,    18,    99,    24,    28,    20,   109,    19,
     109,    21,   109,    25,    64,    96,    64,    97,    64,    80,
      98,    64,    -1,    -1,    -1,    -1,    17,   103,    64,    24,
     109,    25,   101,    64,    80,   102,    64,    -1,    -1,    -1,
      -1,    14,   105,   109,    27,   106,    76,    -1,    15,    27,
      -1,    16,    27,    -1,    33,    -1,    34,    -1,    11,    -1,
      12,    -1,    35,    -1,    84,    -1,   110,    -1,   111,    -1,
     112,    -1,   113,    -1,   114,    -1,    24,   109,    25,    -1,
     115,    -1,   109,    50,   109,    -1,   109,    49,   109,    -1,
     109,    53,   109,    -1,   109,    52,   109,    -1,   109,    51,
     109,    -1,   109,    54,   109,    -1,   109,    47,   109,    -1,
     109,    48,   109,    -1,   109,    38,    64,   109,    -1,   109,
      37,    64,   109,    -1,   109,    44,   109,    -1,   109,    43,
     109,    -1,   109,    46,   109,    -1,   109,    45,   109,    -1,
     109,    42,   109,    -1,   109,    41,   109,    -1,   109,    40,
     109,    -1,   109,    39,   109,    -1,    49,   109,    -1,    56,
     109,    -1,    55,   109,    -1,    -1,    28,   116,   117,    -1,
      28,    26,    28,   117,    -1,    24,   118,    25,    -1,   119,
      -1,    -1,   119,    32,   109,    -1,   109,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   134,   134,   141,   143,   146,   150,   152,   155,   179,
     189,   198,   203,   206,   210,   215,   221,   225,   231,   239,
     247,   255,   259,   264,   268,   273,   282,   282,   308,   312,
     318,   326,   326,   358,   382,   394,   398,   402,   407,   415,
     431,   438,   446,   452,   456,   460,   466,   472,   477,   482,
     487,   492,   497,   502,   509,   524,   528,   533,   537,   544,
     559,   573,   585,   593,   609,   616,   624,   631,   640,   646,
     662,   672,   645,   691,   705,   715,   705,   730,   741,   743,
     741,   752,   767,   782,   786,   790,   795,   798,   801,   819,
     822,   825,   828,   831,   834,   837,   843,   851,   858,   865,
     872,   879,   886,   893,   902,   906,   912,   920,   928,   936,
     944,   952,   962,   969,   979,   985,   989,   997,   997,  1003,
    1010,  1017,  1020,  1028,  1040
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_CLASS", "TOKEN_REFERENCE",
  "TOKEN_STATIC", "TOKEN_INT_TYPE", "TOKEN_REAL_TYPE", "TOKEN_BOOL_TYPE",
  "TOKEN_STRING_TYPE", "TOKEN_VOID", "TOKEN_TRUE", "TOKEN_FALSE",
  "TOKEN_PRINT", "TOKEN_RETURN", "TOKEN_BREAK", "TOKEN_CONTINUE",
  "TOKEN_WHILE", "TOKEN_FOR", "TOKEN_TO", "TOKEN_IN", "TOKEN_STEPS",
  "TOKEN_LCB", "TOKEN_RCB", "TOKEN_LP", "TOKEN_RP", "TOKEN_DOT",
  "TOKEN_SEMICOLON", "TOKEN_ID", "TOKEN_IF", "TOKEN_ELSEIF", "TOKEN_ELSE",
  "TOKEN_COMMA", "TOKEN_INTEGER", "TOKEN_REAL", "TOKEN_STRING",
  "TOKEN_ASSIGNMENT", "TOKEN_OR", "TOKEN_AND", "TOKEN_BITWISE_OR",
  "TOKEN_BITWISE_AND", "TOKEN_NE", "TOKEN_EQ", "TOKEN_LE", "TOKEN_LT",
  "TOKEN_GE", "TOKEN_GT", "TOKEN_SHIFT_LEFT", "TOKEN_SHIFT_RIGHT",
  "TOKEN_SUBTRACTION", "TOKEN_ADDITION", "TOKEN_MODULO", "TOKEN_DIVISION",
  "TOKEN_MULTIPLICATION", "TOKEN_POWER", "TOKEN_BITWISE_NOT", "TOKEN_NOT",
  "$accept", "program", "macros", "macro", "Classes", "Class", "PM", "M",
  "symbol_decs", "symbol_dec", "var_dec", "var_type", "return_type",
  "var_list", "var_list_item", "@1", "func_dec", "func_body", "@2", "ret",
  "NP", "formal_arguments", "formal_argument", "block", "statements_list",
  "statement", "assignment", "lvalue", "Print", "statement_var_dec", "If",
  "if_code", "if_pop", "if_tbl", "NS", "Elseifs", "Elseif", "ES", "For",
  "@3", "@4", "@5", "for_tbl", "While", "@6", "@7", "while_tbl", "Return",
  "@8", "@9", "Break", "Continue", "exp", "binary_operation",
  "logical_operation", "comparison_operation", "bitwise_operation",
  "unary_operation", "function_call", "@10", "function_call_body",
  "actual_arguments", "actual_arguments_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    61,    61,    62,    63,
      64,    65,    65,    66,    66,    67,    68,    68,    69,    69,
      69,    69,    69,    70,    70,    71,    72,    71,    73,    73,
      73,    75,    74,    76,    77,    78,    78,    78,    79,    80,
      80,    81,    81,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    83,    84,    84,    85,    86,    87,
      87,    88,    89,    90,    91,    92,    92,    93,    94,    96,
      97,    98,    95,    99,   101,   102,   100,   103,   105,   106,
     104,   107,   108,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   110,   110,   110,   110,
     110,   110,   110,   110,   111,   111,   112,   112,   112,   112,
     112,   112,   113,   113,   114,   114,   114,   116,   115,   115,
     117,   118,   118,   119,   119
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     2,     0,     7,     0,
       0,     2,     0,     1,     1,     3,     1,     2,     1,     1,
       1,     1,     1,     3,     1,     1,     0,     4,     2,     2,
       3,     0,    11,     0,     0,     3,     0,     1,     2,     5,
       1,     3,     0,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     5,     3,    12,
      17,     0,     0,     0,     0,     3,     0,     8,     0,     0,
       0,     0,    19,     0,     0,     0,    11,     0,     0,     0,
       6,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     0,     3,     4,
       3,     1,     0,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     7,     1,     0,     3,     2,     5,     0,     6,
       9,     0,    12,    10,     0,    18,    19,    20,    21,     0,
      22,     0,    11,    13,     0,    16,    14,     0,    17,    34,
      29,     8,    25,     0,    24,    28,    30,    10,     0,    15,
       0,    31,     0,    25,    23,     0,    85,    86,     0,    55,
      83,    84,    87,     0,     0,     0,    88,    27,    89,    90,
      91,    92,    93,    95,    36,     0,     0,     0,   114,   116,
     115,    10,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,    94,    56,   122,   118,     0,     0,   113,   112,
     111,   110,   107,   106,   109,   108,   102,   103,    97,    96,
     100,    99,    98,   101,    38,    10,     0,   119,   124,     0,
     121,   105,   104,     0,    78,     0,     0,    77,    73,    43,
      55,    63,     0,     0,    10,    40,    45,    88,    46,    47,
      48,    49,    50,    51,    52,    53,     0,    35,   120,     0,
       0,     0,    81,    82,    10,     0,     0,    42,     0,    33,
       0,    44,   123,     0,     0,     0,     0,     0,    10,    58,
      10,     0,     0,    79,     0,     0,     0,    10,     0,    32,
      54,    57,    33,     0,     0,    10,    39,    41,    80,    74,
       0,    61,    10,     0,    10,    10,     0,    10,    75,     0,
      62,    10,     0,    10,    76,    10,    66,    69,    59,    10,
       0,    64,    10,    70,     0,    10,    65,    10,     0,    10,
      10,    10,    10,    71,    10,    60,    10,    68,    72,    10,
      67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     6,     9,    11,   132,    13,    22,
      23,    24,   133,    33,    34,    38,    26,    30,    45,   170,
      37,    90,    91,   134,   168,   135,   136,    56,   138,   139,
     140,   194,   203,   156,   215,   208,   212,   229,   141,   209,
     217,   226,   155,   142,   192,   201,   154,   143,   151,   182,
     144,   145,   146,    58,    59,    60,    61,    62,    63,    67,
      95,   119,   120
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -144
static const yytype_int16 yypact[] =
{
    -144,     5,     7,  -144,    16,  -144,    28,  -144,    50,  -144,
    -144,    63,  -144,    20,    89,  -144,  -144,  -144,  -144,    64,
    -144,    65,  -144,  -144,    90,  -144,  -144,    64,  -144,  -144,
    -144,  -144,   -21,    47,  -144,  -144,  -144,  -144,    84,  -144,
      94,  -144,    38,    87,  -144,   100,  -144,  -144,    38,    37,
    -144,  -144,  -144,    38,    38,    38,  -144,   547,  -144,  -144,
    -144,  -144,  -144,  -144,    61,   295,    97,   103,    62,  -144,
    -144,  -144,  -144,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,   101,
      32,  -144,  -144,   103,    38,  -144,    38,    38,   247,   594,
     606,   606,   -31,   -31,   -31,   -31,    51,    51,    62,    62,
      74,    74,    74,  -144,  -144,   211,    61,  -144,   547,   105,
      99,   564,   580,   108,  -144,   107,   109,  -144,  -144,  -144,
     -20,  -144,   113,    94,  -144,  -144,  -144,   102,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,   473,  -144,  -144,    38,
      38,    38,  -144,  -144,  -144,   115,   116,  -144,    48,  -144,
      38,  -144,   547,   325,   501,   118,   117,    38,   114,  -144,
    -144,   529,   119,  -144,    38,   124,   355,  -144,   211,  -144,
    -144,  -144,  -144,   385,    38,  -144,  -144,  -144,  -144,  -144,
     231,  -144,  -144,    38,  -144,   211,   265,   211,  -144,    38,
    -144,  -144,   415,  -144,  -144,  -144,  -144,  -144,    60,  -144,
     123,  -144,  -144,  -144,    38,  -144,  -144,  -144,   445,   211,
     211,  -144,  -144,  -144,   211,  -144,  -144,  -144,  -144,  -144,
    -144
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,  -144,  -144,  -144,  -144,   -13,  -144,  -144,
    -144,  -144,    -4,    15,   110,  -144,  -144,    59,  -144,   -33,
    -144,  -144,    35,  -143,  -144,   -25,  -144,  -113,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,   -41,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
      66,  -144,  -144
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -118
static const yytype_int16 yytable[] =
{
      21,    57,   137,   -34,  -117,     3,    66,    65,   -22,    25,
      28,     4,    68,    69,    70,   -26,    81,    82,    83,    84,
      85,    86,    87,    88,    41,    14,    15,    16,    17,    18,
      19,     8,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    20,    46,
      47,     7,   198,   118,   200,   121,   122,   115,    96,    97,
      89,  -117,    48,    66,   116,   137,    49,    15,    16,    17,
      18,    50,    51,    52,    39,   169,   222,   223,    10,    40,
      40,   227,   137,    35,   137,    12,    36,    53,    31,    20,
     210,   211,    29,    54,    55,    15,    16,    17,    18,    27,
      83,    84,    85,    86,    87,    88,   137,   137,   162,   163,
     164,   137,    89,    85,    86,    87,    88,    20,    32,   171,
      42,   159,    43,   -26,    64,    93,   176,    94,    88,   114,
     148,   149,   150,   183,   152,   157,   153,   177,   160,   166,
     167,   165,   174,   190,   184,   175,   181,   214,   158,   188,
      44,   147,   196,   187,     0,   178,     0,   179,   202,   117,
       0,     0,     0,     0,   186,     0,     0,     0,     0,     0,
       0,     0,   191,   218,     0,     0,     0,     0,     0,   195,
       0,   197,     0,     0,     0,     0,     0,     0,   204,     0,
     206,     0,   207,     0,     0,     0,   213,     0,     0,   216,
       0,     0,   219,     0,   220,     0,     0,     0,   224,   225,
       0,     0,     0,   228,     0,     0,   230,    15,    16,    17,
      18,     0,    46,    47,   123,   124,   125,   126,   127,   128,
       0,     0,     0,     0,     0,    48,     0,     0,   129,   130,
     131,     0,     0,     0,    50,    51,    52,     0,     0,     0,
     193,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,     0,     0,     0,     0,    54,    55,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,   199,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
     185,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
     189,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
     205,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
     221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
     161,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,   173,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88
};

static const yytype_int16 yycheck[] =
{
      13,    42,   115,    24,    24,     0,    26,    48,    28,    13,
      14,     4,    53,    54,    55,    36,    47,    48,    49,    50,
      51,    52,    53,    54,    37,     5,     6,     7,     8,     9,
      10,     3,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    28,    11,
      12,    35,   195,    94,   197,    96,    97,    25,    71,    72,
      64,    24,    24,    26,    32,   178,    28,     6,     7,     8,
       9,    33,    34,    35,    27,    27,   219,   220,    28,    32,
      32,   224,   195,    24,   197,    22,    27,    49,    23,    28,
      30,    31,    28,    55,    56,     6,     7,     8,     9,    10,
      49,    50,    51,    52,    53,    54,   219,   220,   149,   150,
     151,   224,   116,    51,    52,    53,    54,    28,    28,   160,
      36,   134,    28,    36,    24,    28,   167,    24,    54,    28,
      25,    32,    24,   174,    27,    22,    27,    23,    36,    24,
      24,   154,    24,   184,    20,    28,    27,    24,   133,   182,
      40,   116,   193,   178,    -1,   168,    -1,   170,   199,    93,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   185,   214,    -1,    -1,    -1,    -1,    -1,   192,
      -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,
     203,    -1,   205,    -1,    -1,    -1,   209,    -1,    -1,   212,
      -1,    -1,   215,    -1,   217,    -1,    -1,    -1,   221,   222,
      -1,    -1,    -1,   226,    -1,    -1,   229,     6,     7,     8,
       9,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    27,    28,
      29,    -1,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    55,    56,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    21,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    58,    59,     0,     4,    60,    61,    35,     3,    62,
      28,    63,    22,    65,     5,     6,     7,     8,     9,    10,
      28,    64,    66,    67,    68,    69,    73,    10,    69,    28,
      74,    23,    28,    70,    71,    74,    74,    77,    72,    27,
      32,    64,    36,    28,    71,    75,    11,    12,    24,    28,
      33,    34,    35,    49,    55,    56,    84,   109,   110,   111,
     112,   113,   114,   115,    24,   109,    26,   116,   109,   109,
     109,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    69,
      78,    79,    25,    28,    24,   117,    64,    64,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,    28,    25,    32,   117,   109,   118,
     119,   109,   109,    13,    14,    15,    16,    17,    18,    27,
      28,    29,    64,    69,    80,    82,    83,    84,    85,    86,
      87,    95,   100,   104,   107,   108,   109,    79,    25,    32,
      24,   105,    27,    27,   103,    99,    90,    22,    70,    64,
      36,    27,   109,   109,   109,    64,    24,    24,    81,    27,
      76,   109,    25,    27,    24,    28,   109,    23,    64,    64,
      27,    27,   106,   109,    20,    25,    64,    82,    76,    25,
     109,    64,   101,    19,    88,    64,   109,    64,    80,    21,
      80,   102,   109,    89,    64,    25,    64,    64,    92,    96,
      30,    31,    93,    64,    24,    91,    64,    97,   109,    64,
      64,    25,    80,    80,    64,    64,    98,    80,    64,    94,
      64
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 134 "parser3.y"
    {
        print("program -> macros Classes");
        print("");
    ;}
    break;

  case 3:
#line 141 "parser3.y"
    {
    print("macros -> macros macro");;}
    break;

  case 4:
#line 143 "parser3.y"
    {print("macros -> lambda");;}
    break;

  case 5:
#line 146 "parser3.y"
    {
    print("macro -> reference TOKEN_STRING");;}
    break;

  case 6:
#line 150 "parser3.y"
    {
    print("Classes -> Classes Class");;}
    break;

  case 7:
#line 152 "parser3.y"
    { print("Classes -> lambda"); ;}
    break;

  case 8:
#line 155 "parser3.y"
    {
    functionCall("_main", "");
   topPlsLoclNum( atoi( ((struct Eval*)(yyvsp[(3) - (7)].evalptr))->str));
    for(int i=0 ; i<lastOfReturnQuad ; i++)
        topPlsLoclNum( returnQuads[i]);
       topPlsLoclNum( returnQuad);
    lastOfReturnQuad=0;
    mainSymTbl = pop(tblptrStack);
    allSymbolTablePrint(mainSymTbl);
    printf("this is program");
   // if(mainFunc != NULL){
        //backpatch(mainFunc->nextList , ((struct Eval*)$6)->quad );
       // printf("mainfunc not null %s ", ((struct Eval*)$6)->quad);
   // }else
     printf("mainfunc  null");
    emit("return" , "0" , "" , "" );
    printf("end of program\n");
    (yyval.sVal) = (yyvsp[(2) - (7)].sVal);

    print("Class -> class ID ( symbod_decs )");
     
;}
    break;

  case 9:
#line 179 "parser3.y"
    {

    snprintf(num,5,"%d",nextquad);
    emit("-" , "top" , "NA" , "top" );
    struct SymbolTable* t = mkTable( NULL , "program");
    push(t, tblptrStack);
    (yyval.evalptr) = mkEval (0 ,0 ,0 , "" , mkStr(num) );
;}
    break;

  case 10:
#line 189 "parser3.y"
    {
    currentLable  = (char *) malloc(sizeof("L") + sizeof(num));
    currentLable = mkStr(createLable());
    (yyval.evalptr) = mkEval( 0 , 0 , 0 ,currentLable , "");
;}
    break;

  case 11:
#line 198 "parser3.y"
    {
    
       
       (yyval.sVal) = (yyvsp[(1) - (2)].sVal);
        print("symbol_decs -> symbol_decs symbol_dec");;}
    break;

  case 12:
#line 203 "parser3.y"
    { print("symbol_decs -> lambda");;}
    break;

  case 13:
#line 206 "parser3.y"
    {
       (yyval.sVal) = (yyvsp[(1) - (1)].sVal);
        print("symbol_dec -> var_dec");
         ;}
    break;

  case 14:
#line 210 "parser3.y"
    {
        (yyval.sVal) = (yyvsp[(1) - (1)].sVal);
        print("symbol_dec -> func_dec");
          ;}
    break;

  case 15:
#line 215 "parser3.y"
    {
    print("var_dec -> var_type var_list ;");
    (yyval.sVal) = (yyvsp[(1) - (3)].sVal);
     ;}
    break;

  case 16:
#line 221 "parser3.y"
    {
        (yyval.sVal) = (yyvsp[(1) - (1)].sVal);
        print("var_type -> return_type");
         ;}
    break;

  case 17:
#line 225 "parser3.y"
    {
        (yyval.sVal) = (yyvsp[(2) - (2)].sVal);
        print("var_type -> static return_type");
          ;}
    break;

  case 18:
#line 231 "parser3.y"
    {
        currentType=4;
        returnType = (char*) malloc(strlen("INT"));
        strcpy(returnType, "INT");
        printf("this is int");
        (yyval.sVal) = (yyvsp[(1) - (1)].sVal);
         print("return_type -> int");
         ;}
    break;

  case 19:
#line 239 "parser3.y"
    {
        currentType=8;
        returnType = (char*) malloc(strlen("REAL"));
        strcpy(returnType, "REAL");
        printf("this is real");
        (yyval.sVal) = (yyvsp[(1) - (1)].sVal);
        print("return_type -> real");
         ;}
    break;

  case 20:
#line 247 "parser3.y"
    {
       currentType=1;
        returnType = (char*) malloc(strlen("BOOL"));
        strcpy(returnType, "BOOL");
       printf("this is bool\n");
        (yyval.sVal) = (yyvsp[(1) - (1)].sVal);
        print("return_type -> bool");
         ;}
    break;

  case 21:
#line 255 "parser3.y"
    {
        //TODO add
        print("return_type -> string");
         ;}
    break;

  case 22:
#line 259 "parser3.y"
    {
        printf( "return_type -> <ID, %s>\n", (yyvsp[(1) - (1)].sVal));
          ;}
    break;

  case 23:
#line 264 "parser3.y"
    {
        (yyval.sVal) = (yyvsp[(1) - (3)].sVal);
        print("var_list -> var_list, var_list_item");
          ;}
    break;

  case 24:
#line 268 "parser3.y"
    {
        (yyval.sVal) = (yyvsp[(1) - (1)].sVal);
        print("var_list -> var_list_item");
         ;}
    break;

  case 25:
#line 273 "parser3.y"
    {
/*if(currentType == 4){
        emit("int", $1, "", "");
    }*/
    enterVar( (yyvsp[(1) - (1)].sVal), currentType , top(tblptrStack) );
    printf("a variable entered:%s\n",(yyvsp[(1) - (1)].sVal));
    (yyval.sVal) = (yyvsp[(1) - (1)].sVal);
    printf( "var_list_item -> <ID, %s>\n", (yyvsp[(1) - (1)].sVal));
     ;}
    break;

  case 26:
#line 282 "parser3.y"
    {
   /* if(currentType == 4){
           emit("int", $1, "", "");
       }else if( currentType == 8)*/
   // emit ("real", $1, "", "");

    enterVar( (yyvsp[(1) - (1)].sVal) , currentType , top(tblptrStack) );
    printf("a variable entered:%s\n",(yyvsp[(1) - (1)].sVal));
    
;}
    break;

  case 27:
#line 292 "parser3.y"
    {
         if( currentType > 1 && ((struct Eval*)(yyvsp[(4) - (4)].evalptr))->str != 0 )
             {
                 struct Eval* lvalueEval = idToEval((yyvsp[(1) - (4)].sVal));
                 emit("IP" , ((struct Eval*)(yyvsp[(4) - (4)].evalptr))->str , "" , lvalueEval->str );
             }
             else if (currentType == 1)
             {
                 assignBool( ((struct Eval*)(yyvsp[(4) - (4)].evalptr))->trueList , ((struct Eval*)(yyvsp[(4) - (4)].evalptr))->falseList, (yyvsp[(1) - (4)].sVal) , true ,true );
             }
             (yyval.sVal) = (yyvsp[(1) - (4)].sVal);
         printf( "var_list_item -> <ID> = exp\n");
           ;}
    break;

  case 28:
#line 308 "parser3.y"
    {
        (yyval.sVal) = (yyvsp[(2) - (2)].sVal);
        print("func_dec -> var_type func_body");
    ;}
    break;

  case 29:
#line 312 "parser3.y"
    {
         returnType = (char*) malloc(strlen("VOID"));
         strcpy(returnType, "VOID");
        (yyval.sVal) = (yyvsp[(2) - (2)].sVal);
         print("func_dec -> void func_body");
         ;}
    break;

  case 30:
#line 318 "parser3.y"
    {
         returnType = (char*) malloc(strlen("VOID"));
         strcpy(returnType, "VOID");
        (yyval.sVal) = (yyvsp[(3) - (3)].sVal);
         print("func_dec -> static void func_body");
         ;}
    break;

  case 31:
#line 326 "parser3.y"
    {
    emit("=" , "top" , "" , "sp");
    emit("//" , "func decleration:" ,"" , (yyvsp[(1) - (3)].sVal));
    snprintf(num,5,"%d",nextquad);
    strcpy(snum, num);
    emit("-" , "top" , "NA" , "top" );
    char* tmpc = mkStr( top(tblptrStack)->name );
    struct SymbolTable* tmpt = pop(tblptrStack);
    enterFunc(tmpc , -1 , returnType ,  tmpt , top(tblptrStack) , ((struct Eval*)(yyvsp[(3) - (3)].evalptr))->quad);
    push( tmpt , tblptrStack );
;}
    break;

  case 32:
#line 336 "parser3.y"
    {
    for(int i = 0; i < j; i++){
          if(strcmp((yyvsp[(1) - (11)].sVal), funcID[i])==0){
              backpatch(mkList(address[i]),((struct Eval*)(yyvsp[(3) - (11)].evalptr))->quad);
              strcpy(quad_ruples[sizeAdd[i]][2], intToString(9 + (top(tblptrStack)->argNum)));
              strcpy(quad_ruples[scpAdd[i]][2], intToString((top(tblptrStack)->ID)));
              
          }
      }
    topPlsLoclNum(atoi(snum));
    for(int i=0 ; i<lastOfReturnQuad ; i++)
        topPlsLoclNum( returnQuads[i] );
    topPlsLoclNum(returnQuad);
    lastOfReturnQuad=0;
    pop(tblptrStack);
    backpatch( ((struct Eval*)(yyvsp[(2) - (11)].evalptr))->nextList , ((struct Eval*)(yyvsp[(11) - (11)].evalptr))->quad );
    backpatch( ((struct Eval*)(yyvsp[(8) - (11)].evalptr))->nextList , ((struct Eval*)(yyvsp[(9) - (11)].evalptr))->quad );
    (yyval.sVal) = (yyvsp[(1) - (11)].sVal);
    emit("//", "num", (yyval.sVal), (yyvsp[(1) - (11)].sVal));
    printf( "func_body -> <ID, %s> ( formal_arguments ) block\n", (yyvsp[(1) - (11)].sVal));
;}
    break;

  case 33:
#line 358 "parser3.y"
    {
   /* if(inBlock == true){
       emit("+" , "top" , "1" , "top");
       emit("+" , "atop" , "1" , "atop");
          emit("IP" , "sp" , "" , "atop");
        inBlock = false;
    }*/
        char * tmpPointer = newPTemp();
        char * PPtmp = newVTemp();
        char * tmpPointerWithStar = (char*) malloc(strlen(tmpPointer)+1);
        strcpy(tmpPointerWithStar , "*");
        strcat( tmpPointerWithStar , tmpPointer );
        //returning
        emit("//","return" , "" , "");
        returnQuads[lastOfReturnQuad] = nextquad;
      returnQuad = nextquad;
        lastOfReturnQuad++;
        emit("+" , "top" , "NA" , "top");
        emit("+" , "atop" , "1" , PPtmp);
        emit("PI" , PPtmp , "" , tmpPointer );
        emit("goto" , tmpPointerWithStar , "" , "");
    ;}
    break;

  case 34:
#line 382 "parser3.y"
    {
   
    printf("starting reducing NP\n");
    mkSymTbl(currentLexeme);
    (yyval.evalptr) = mkEval(0 , 0 , mkList(nextquad) , "" , "");
       
    emit("goto" , "" , "" , "" );
   
;}
    break;

  case 35:
#line 394 "parser3.y"
    {
        (yyval.sVal) = (yyvsp[(1) - (3)].sVal);
         print("formal_arguments -> formal_arguments , formal_argument");
          ;}
    break;

  case 36:
#line 398 "parser3.y"
    {
        (yyval.sVal) = 0;
         print("formal_arguments -> lambda");
         ;}
    break;

  case 37:
#line 402 "parser3.y"
    {
        (yyval.sVal) = (yyvsp[(1) - (1)].sVal);
         print("formal_arguments -> formal_argument");
          ;}
    break;

  case 38:
#line 407 "parser3.y"
    {
    emit("//", "param entered in: ", top(tblptrStack)->name, (yyvsp[(2) - (2)].sVal));
   enterParam((yyvsp[(2) - (2)].sVal), currentType , top(tblptrStack));
    (yyval.sVal) = (yyvsp[(1) - (2)].sVal);
     printf( "formal_argument -> return_type <ID, %s>\n", (yyvsp[(2) - (2)].sVal));
     ;}
    break;

  case 39:
#line 415 "parser3.y"
    {
        (yyval.evalptr) = (yyvsp[(3) - (5)].evalptr);
        if(break_list != NULL){
            printf("broken\n");
            backpatch(break_list, ((struct Eval*)(yyvsp[(5) - (5)].evalptr))->quad );
            break_list = NULL;
        }
        if(cont_list != NULL){
            printf("continue\n");
            backpatch(cont_list, ((struct Eval*)(yyvsp[(1) - (5)].evalptr))->quad );
            cont_list = NULL;
        }
        
        //printf("this is block \t nextList:%x\n" , ((struct Eval*)$2)->nextList );
        print("block -> { statements_list }");
    ;}
    break;

  case 40:
#line 431 "parser3.y"
    {
        (yyval.evalptr) = (yyvsp[(1) - (1)].evalptr);
       // printf("this is block \t nextList:%x\n" , ((struct Eval*)$1)->nextList );
        print("block -> statement");
          ;}
    break;

  case 41:
#line 438 "parser3.y"
    {
        
       backpatch( ((struct Eval*)(yyvsp[(1) - (3)].evalptr))->nextList , ((struct Eval*)(yyvsp[(2) - (3)].evalptr))->quad );
     
        (yyval.evalptr) = mkEval (0 ,0 , ((struct Eval*)(yyvsp[(3) - (3)].evalptr))->nextList , "" , "");

        print("statements_list -> statements_list statement");
         ;}
    break;

  case 42:
#line 446 "parser3.y"
    {
    (yyval.evalptr) = mkEval(0,0,0,"","");
    print("statements_list -> lambda");
         ;}
    break;

  case 43:
#line 452 "parser3.y"
    {
        (yyval.evalptr) = mkEval(0,0,0,"","");
        print("statement ->  ;");
          ;}
    break;

  case 44:
#line 456 "parser3.y"
    {
        (yyval.evalptr) = mkEval(0,0,0,"","");
        print("statement -> exp ;");
         ;}
    break;

  case 45:
#line 460 "parser3.y"
    {
         printf("reduced");
         //$$ = mkEval (0 ,0 , ((struct Eval*)$1)->nextList , "" , "");
         (yyval.evalptr) = (yyvsp[(1) - (1)].evalptr);
        print("statement -> assignment");
         ;}
    break;

  case 46:
#line 466 "parser3.y"
    {
        (yyval.evalptr) = mkEval(0,0,0,"","");
       // $$ = mkEval (0 ,0 , ((struct Eval*)$1)->nextList , "" , "");
       // $$=$1;
        print("statement -> Print ");
          ;}
    break;

  case 47:
#line 472 "parser3.y"
    {
        (yyval.evalptr) = strToEval((yyvsp[(1) - (1)].sVal));
        // $$=$1;
    print("statement -> statement_var_dec");
      ;}
    break;

  case 48:
#line 477 "parser3.y"
    {
        (yyval.evalptr) = mkEval (0 ,0 , ((struct Eval*)(yyvsp[(1) - (1)].evalptr))->nextList , "" , "");
         //$$=$1;
        print("statement -> If");
          ;}
    break;

  case 49:
#line 482 "parser3.y"
    {
        (yyval.evalptr) = mkEval (0 ,0 , ((struct Eval*)(yyvsp[(1) - (1)].evalptr))->nextList , "" , "");
         //$$=$1;
        print("statement -> For");
         ;}
    break;

  case 50:
#line 487 "parser3.y"
    {
        (yyval.evalptr) = mkEval (0 ,0 , ((struct Eval*)(yyvsp[(1) - (1)].evalptr))->nextList , "" , "");
         //$$=$1;
        print("statement -> While ");
         ;}
    break;

  case 51:
#line 492 "parser3.y"
    {
        (yyval.evalptr) = mkEval (0 ,0 , ((struct Eval*)(yyvsp[(1) - (1)].evalptr))->nextList , "" , "");
        // $$=$1;
        print("statement -> Return");
          ;}
    break;

  case 52:
#line 497 "parser3.y"
    {
        (yyval.evalptr) = mkEval (0 ,0 , ((struct Eval*)(yyvsp[(1) - (1)].evalptr))->nextList , "" , "");
        // $$=$1;
        print("statement -> Break");
          ;}
    break;

  case 53:
#line 502 "parser3.y"
    {
        (yyval.evalptr) = mkEval (0 ,0 , ((struct Eval*)(yyvsp[(1) - (1)].evalptr))->nextList , "" , "");
         //$$=$1;
        print("statement -> Continue");
         ;}
    break;

  case 54:
#line 509 "parser3.y"
    { print("assignment -> lvalue = exp ;");
        if( strcmp( ((struct Eval*)(yyvsp[(3) - (4)].evalptr))->quad , "*" ) != 0 ){
             struct Eval* lvalueEval = idToEval((yyvsp[(1) - (4)].sVal));
             //DANGER
             emit("IP" , ((struct Eval*)(yyvsp[(3) - (4)].evalptr))->str , "" , lvalueEval->str );
             printf("emited\n");
         }
         else{
             assignBool( ((struct Eval*)(yyvsp[(3) - (4)].evalptr))->trueList , ((struct Eval*)(yyvsp[(3) - (4)].evalptr))->falseList, (yyvsp[(1) - (4)].sVal) , true ,true );
         }
         (yyval.evalptr) = mkEval(0,0,0,"","");
         printf("g\n");
;}
    break;

  case 55:
#line 524 "parser3.y"
    {
        (yyval.sVal) = (yyvsp[(1) - (1)].sVal);
        printf( "lvalue -> <ID, %s>\n", (yyvsp[(1) - (1)].sVal));
          ;}
    break;

  case 56:
#line 528 "parser3.y"
    {
    //TODO
    printf( "lvalue -> <ID, %s> . <ID, %s>\n", (yyvsp[(1) - (3)].sVal), (yyvsp[(3) - (3)].sVal));
      ;}
    break;

  case 57:
#line 533 "parser3.y"
    {
        emit("pr", ((struct Eval*)(yyvsp[(3) - (5)].evalptr))->str, "", "");
;}
    break;

  case 58:
#line 537 "parser3.y"
    {
    //TODO
    (yyval.sVal) = (yyvsp[(1) - (3)].sVal);
     print("statement_var_dec -> return_type var_list ;");
     ;}
    break;

  case 59:
#line 544 "parser3.y"
    {
    currentLable  = (char *) malloc(sizeof("L") + sizeof(num));
    currentLable = mkStr(createLable());
    backpatch( ((struct Eval*)(yyvsp[(10) - (12)].evalptr)) ->nextList , currentLable);
        backpatch( ((struct Eval*)(yyvsp[(4) - (12)].evalptr)) ->trueList, ((struct Eval*)(yyvsp[(8) - (12)].evalptr)) ->quad);
        backpatch( ((struct Eval*)(yyvsp[(4) - (12)].evalptr)) ->falseList, ((struct Eval*)(yyvsp[(11) - (12)].evalptr))->quad);
       // backpatch( ((struct Eval*)$12) ->falseList , currentLable );
       //  backpatch(((struct Eval*)$12) ->nextList,currentLable );
        Node * tmp = mergeList ( ((struct Eval*)(yyvsp[(4) - (12)].evalptr)) ->falseList, ((struct Eval*)(yyvsp[(11) - (12)].evalptr)) ->nextList );
        (yyval.evalptr)=mkEval(0,0, tmp ,"","");
     //    emit("+" , "top" , "1" , "top");
      //   emit("+" , "atop" , "1" , "atop");
        //    emit("IP" , "sp" , "" , "atop");
        print("IF -> if ( exp ) block Elseifs");
;}
    break;

  case 60:
#line 559 "parser3.y"
    {
        backpatch( ((struct Eval*)(yyvsp[(10) - (17)].evalptr)) ->nextList , ((struct Eval*)(yyvsp[(17) - (17)].evalptr)) ->quad );
        backpatch( ((struct Eval*)(yyvsp[(4) - (17)].evalptr)) ->trueList , ((struct Eval*)(yyvsp[(8) - (17)].evalptr)) ->quad );
        backpatch( ((struct Eval*)(yyvsp[(4) - (17)].evalptr)) ->falseList , ((struct Eval*)(yyvsp[(11) - (17)].evalptr)) ->quad );
        backpatch( ((struct Eval*)(yyvsp[(12) - (17)].evalptr)) ->falseList , ((struct Eval*)(yyvsp[(15) - (17)].evalptr)) ->quad );
        backpatch(((struct Eval*)(yyvsp[(12) - (17)].evalptr)) ->nextList,((struct Eval*)(yyvsp[(17) - (17)].evalptr)) ->quad );
       // Node * tmp1=mergeList ( ((struct Eval*)$12) ->nextList , ((struct Eval*)$16) ->nextList );
        //Node * tmp2 = mergeList(((struct Eval*)$9) -> nextList, tmp1);
        //Node * tmp = mergeList ( ((struct Eval*)$9) ->nextList , tmp2);
        (yyval.evalptr) = mkEval(0,0,0,"","");
       // printf("FINISH : IF exp THEN M block ELSE NS M block <TO> stmt FINISHED\n");
          print("IF -> if ( exp ) block Elseifs else");
         ;}
    break;

  case 61:
#line 573 "parser3.y"
    {
  /*
    emit("=" , "top" , "" , "sp");
       na = intToString(nextquad);
       emit("-" , "top" , "NA" , "top" );
       emit("//", na, "here", "");
       char* tmpc = mkStr(top(tblptrStack)->name);
       struct SymbolTable* tmpt = pop(tblptrStack);
        enterFunc(tmpc , -1 , "" ,  tmpt , top(tblptrStack) , currentLable);
        push( tmpt , tblptrStack );*/
;}
    break;

  case 62:
#line 585 "parser3.y"
    {
    /*inBlock = false;
    topPlsLoclNum(atoi(na));
    pop(tblptrStack);*/
    (yyval.evalptr) = mkEval ( 0 , 0 , mkList(nextquad) , "" , "" );
    emit( "goto" ,"","","" );
;}
    break;

  case 63:
#line 593 "parser3.y"
    {
   /* inBlock = true;
    char * n  = (char *) malloc(sizeof(char) *5);
    snprintf(n, 5, "%d", ifNum);
    printf("%s\n", n);
    char * tmp = mkStr("if_");
    strcat(tmp, n);
    mkSymTbl(tmp);
    ifNum++;
    emit("-" , "top" , "1" , "top");
    emit("IP" , intToString(-1*(ifNum - 1) ), "" , "top");
    emit("-" , "atop" , "1" , "atop");
    emit("IP" , "sp" , "" , "atop");*/
;}
    break;

  case 64:
#line 609 "parser3.y"
    {
   // $$ = mkEval ( 0 , 0 , mkList(nextquad) , "" , "" );
    //emit( "goto" ,"","","" );
;}
    break;

  case 65:
#line 616 "parser3.y"
    {
        
        //backpatch( ((struct Eval*)$1) ->falseList , ((struct Eval*)$2) ->quad );
         Node * tmp=mergeList ( ((struct Eval*)(yyvsp[(1) - (3)].evalptr)) ->nextList , ((struct Eval*)(yyvsp[(2) - (3)].evalptr)) ->nextList);
        // Node * tmp = mergeList(((struct Eval*)$3) -> nextList, tmp1);
         (yyval.evalptr) = mkEval(((struct Eval*)(yyvsp[(2) - (3)].evalptr)) ->trueList ,((struct Eval*)(yyvsp[(2) - (3)].evalptr)) ->falseList ,tmp,"","");
          print("Elseifs -> Elseifs Elseif");
           ;}
    break;

  case 66:
#line 624 "parser3.y"
    {
         //afterIF = mkStr(((struct Eval*)$1)->quad);
        (yyval.evalptr) = mkEval(0, 0, 0 , "", "");
        print("Elseifs -> lambda");
         ;}
    break;

  case 67:
#line 631 "parser3.y"
    {
    afterIF = mkStr(((struct Eval*)(yyvsp[(8) - (8)].evalptr))->quad);
    backpatch( ((struct Eval*)(yyvsp[(3) - (8)].evalptr)) ->falseList , ((struct Eval*)(yyvsp[(8) - (8)].evalptr)) ->quad );
    backpatch( ((struct Eval*)(yyvsp[(3) - (8)].evalptr)) ->trueList , ((struct Eval*)(yyvsp[(5) - (8)].evalptr)) ->quad );
    (yyval.evalptr) = mkEval(((struct Eval*)(yyvsp[(3) - (8)].evalptr))->trueList, ((struct Eval*)(yyvsp[(3) - (8)].evalptr)) ->falseList, ((struct Eval*)(yyvsp[(7) - (8)].evalptr)) ->nextList, "", "");
        print("Elseif -> elseif ( exp ) block");
         ;}
    break;

  case 68:
#line 640 "parser3.y"
    {
    (yyval.evalptr) = mkEval ( 0 , 0 , mkList(nextquad) , "" , "" );
    emit( "goto" ,"","","" );
;}
    break;

  case 69:
#line 646 "parser3.y"
    {
      //  emit("=" , "top" , "" , "sp");
       // $5 = intToString(nextquad);
       // emit("-" , "top" , "NA" , "top" );
       // emit("//", $5, "here", "");
       // char* tmpc = mkStr(top(tblptrStack)->name);
       // printf("sym tblName: %s\n", top(tblptrStack)->name);
       // struct SymbolTable* tmpt = pop(tblptrStack);
       // printf("inner scope: %s\n", top(tblptrStack)->name);
       // enterFunc(tmpc , -1 , "" ,  tmpt , top(tblptrStack) , ((struct Eval*)$12)->quad);
       // push( tmpt , tblptrStack );
        enterVar( (yyvsp[(4) - (12)].sVal), 8, top(tblptrStack));
        (yyvsp[(1) - (12)].evalptr) = idToEval((yyvsp[(4) - (12)].sVal));
        emit("IP" , ((struct Eval*)(yyvsp[(6) - (12)].evalptr))->str , "-" , ((struct Eval*)(yyvsp[(1) - (12)].evalptr))->str );
        printf("emited\n");
//  $$ = mkEval( 0 ,0 , ((struct Eval*)$4)->falseList , "" , "");
;}
    break;

  case 70:
#line 662 "parser3.y"
    {
    char* tmp = mkStr("*");
     printf("%s\n", tmp);
    strcat(tmp,mkStr(((struct Eval*)(yyvsp[(1) - (14)].evalptr))->str));
    printf("%s\n", tmp);
    emit("if", tmp, " >=", ((struct Eval*)(yyvsp[(6) - (14)].evalptr))->str);
    emit("if", tmp, " < ", ((struct Eval*)(yyvsp[(8) - (14)].evalptr))->str);
    (yyvsp[(3) - (14)].evalptr) = mkEval( mkList(nextquad) , mkList(nextquad+1) , 0 , "*" , "");
    emit("goto" , "" , "" , "" );
    emit("goto" , "" , "" , "" );
;}
    break;

  case 71:
#line 672 "parser3.y"
    {
    char* tmp = mkStr("*");
     strcat(tmp,mkStr(((struct Eval*)(yyvsp[(1) - (17)].evalptr))->str));
     emit ("+",tmp, ((struct Eval*)(yyvsp[(10) - (17)].evalptr))->str, tmp );
     emit("goto", ((struct Eval*)(yyvsp[(14) - (17)].evalptr))->quad ,"" ,"");
;}
    break;

  case 72:
#line 677 "parser3.y"
    {
    backpatch( ((struct Eval*)(yyvsp[(3) - (19)].evalptr))->trueList , ((struct Eval*)(yyvsp[(16) - (19)].evalptr))->quad );
    backpatch( ((struct Eval*)(yyvsp[(3) - (19)].evalptr))->falseList , ((struct Eval*)(yyvsp[(19) - (19)].evalptr))->quad );
    Node * tmp = mergeList ( ((struct Eval*)(yyvsp[(3) - (19)].evalptr))->falseList, ((struct Eval*)(yyvsp[(17) - (19)].evalptr))->nextList );
     (yyval.evalptr) = mkEval( 0 ,0 , 0 , "" , "");
    
     
      //  printf( "For -> for ( <ID, %s> in exp to exp steps exp ) block", $4);
    //  emit("//", "quad ", $5, "for");
    //  topPlsLoclNum(atoi($5));
    //  pop(tblptrStack);
      // backpatch( ((struct Eval*)$2)->nextList , ((struct Eval*)$18)->quad );
         ;}
    break;

  case 73:
#line 691 "parser3.y"
    {
    printf("in for_\n");
 //   char * n  = (char *) malloc(sizeof(char) *5);
 //   snprintf(n, 5, "%d", forNum);
 //   printf("%s\n", n);
    
   // char * tmp = mkStr("for_");
 //   strcat(tmp, n);
   // mkSymTbl(tmp);
    printf("sym tbl made\n");
    forNum++;
;}
    break;

  case 74:
#line 705 "parser3.y"
    {
    //emit("=" , "top" , "" , "sp");
   // $1 = intToString(nextquad);
    //emit("-" , "top" , "NA" , "top" );
    //char* tmpc = mkStr(top(tblptrStack)->name);
    //printf("sym tblName: %s\n", top(tblptrStack)->name);
    //struct SymbolTable* tmpt = pop(tblptrStack);
    //printf("inner scope: %s\n", top(tblptrStack)->name);
    //enterFunc(tmpc , -1 , "-" ,  tmpt , top(tblptrStack) , ((struct Eval*)$3)->quad);
    //push( tmpt , tblptrStack );
;}
    break;

  case 75:
#line 715 "parser3.y"
    {
    emit("goto", ((struct Eval*)(yyvsp[(3) - (9)].evalptr))->quad ,"" ,"");
;}
    break;

  case 76:
#line 717 "parser3.y"
    {
        printf("in : WHILE\n");
        backpatch( ((struct Eval*)(yyvsp[(9) - (11)].evalptr))->nextList , ((struct Eval*)(yyvsp[(3) - (11)].evalptr))->quad );
        backpatch( ((struct Eval*)(yyvsp[(5) - (11)].evalptr))->trueList , ((struct Eval*)(yyvsp[(8) - (11)].evalptr))->quad );
        backpatch( ((struct Eval*)(yyvsp[(5) - (11)].evalptr))->falseList , ((struct Eval*)(yyvsp[(11) - (11)].evalptr))->quad );
        //Node * tmp = mergeList ( ((struct Eval*)$5)->falseList, ((struct Eval*)$9)->nextList );
        (yyval.evalptr) = mkEval( 0 ,0 , 0 , "" , "");
        
        //topPlsLoclNum(atoi($1));
        //pop(tblptrStack);
        print("While -> while ( exp ) block");
         ;}
    break;

  case 77:
#line 730 "parser3.y"
    {
    //char * n  = (char *) malloc(sizeof(char) *5);
    //snprintf(n, 5, "%d", forNum);
    //printf("%s\n", n);
    //char * tmp = mkStr("while_");
   // strcat(tmp, n);
   // mkSymTbl(tmp);
    printf("sym tbl made\n");
    whileNum++;
;}
    break;

  case 78:
#line 741 "parser3.y"
    {
    emit("//","saw return\n", "", "");
;}
    break;

  case 79:
#line 743 "parser3.y"
    {
        char * tmpPointer = newPTemp();
        emit("+" , "sp" , "1" , tmpPointer);
        emit("IP" , ((struct Eval*)(yyvsp[(3) - (4)].evalptr))->str , "" , tmpPointer);
        
;}
    break;

  case 80:
#line 748 "parser3.y"
    {(yyval.evalptr)=mkEval(0 , 0 , 0 , "" , "");;}
    break;

  case 81:
#line 752 "parser3.y"
    {
        (yyval.evalptr) = mkEval(0,0,0,"","");
        if(break_list == NULL){
            printf("starting breaklist %d\n", nextquad);
            break_list = mkList(nextquad);
            printf("%d\n", break_list->value);
        }
        else
            break_list->next = mkList(nextquad);
        //TODO
        emit("goto" , "" , "" , "" );
        print("Break -> break;"); ;}
    break;

  case 82:
#line 767 "parser3.y"
    {
        (yyval.evalptr) = mkEval(0,0,0,"","");
              if(cont_list == NULL){
                  printf("starting contlist %d\n", nextquad);
                  cont_list = mkList(nextquad);
                  printf("%d\n", cont_list->value);
              }
              else
                  break_list->next = mkList(nextquad);
          emit("goto" , "" , "" , "" );
        //TODO
        print("Continue -> continue;");  ;}
    break;

  case 83:
#line 782 "parser3.y"
    {
    (yyval.evalptr)=strToEval((yyvsp[(1) - (1)].sVal));
    printf( "exp -> <int, %s>\n", (yyvsp[(1) - (1)].sVal));
;}
    break;

  case 84:
#line 786 "parser3.y"
    {
        (yyval.evalptr)=strToEval((yyvsp[(1) - (1)].sVal));;
        printf( "exp -> <real, %s>\n", (yyvsp[(1) - (1)].sVal));
    ;}
    break;

  case 85:
#line 790 "parser3.y"
    {
        (yyval.evalptr) = mkEval( mkList(nextquad) , 0 , 0 , "*" , "true");
        defaultGotoGen();

        print("exp -> true"); ;}
    break;

  case 86:
#line 795 "parser3.y"
    {
        (yyval.evalptr) = mkEval( 0 , mkList(nextquad) , 0 , "*" , "false");
        defaultGotoGen();;}
    break;

  case 87:
#line 798 "parser3.y"
    {
        (yyval.evalptr) = strToEval((yyvsp[(1) - (1)].sVal));
        printf( "exp -> <string, %s>\n", (yyvsp[(1) - (1)].sVal)); ;}
    break;

  case 88:
#line 801 "parser3.y"
    {
        struct Eval* lvalueEval = idToEval((yyvsp[(1) - (1)].sVal));
        int idSize = atoi( lvalueEval->quad);
        char * value = newTemp();
        emit("PI" , lvalueEval ->str , "" , value);
        saveTmpVal(value);
        if( idSize == 1)
        {
            emit("if", value , "==" , "true" );
            (yyval.evalptr) = mkEval( mkList(nextquad) , mkList(nextquad+2) , 0 , "*" , value);
            defaultGotoGen();
            defaultGotoGen();
        }
        else
            (yyval.evalptr) = mkEval( 0 , 0 , 0 , "" , value);
        print("exp -> lvalue");
        
    ;}
    break;

  case 89:
#line 819 "parser3.y"
    {
        (yyval.evalptr) = (yyvsp[(1) - (1)].evalptr);
        print("exp -> binary_operation");;}
    break;

  case 90:
#line 822 "parser3.y"
    {
        (yyval.evalptr) = (yyvsp[(1) - (1)].evalptr);
        print("exp -> logical_operation"); ;}
    break;

  case 91:
#line 825 "parser3.y"
    {
        (yyval.evalptr) = (yyvsp[(1) - (1)].evalptr);
        print("exp -> comparison_operation");;}
    break;

  case 92:
#line 828 "parser3.y"
    {
        (yyval.evalptr) = (yyvsp[(1) - (1)].evalptr);
        print("exp -> bitwise_operation"); ;}
    break;

  case 93:
#line 831 "parser3.y"
    {
        (yyval.evalptr) = (yyvsp[(1) - (1)].evalptr);
        print("exp -> unary_operation");;}
    break;

  case 94:
#line 834 "parser3.y"
    {
        (yyval.evalptr) = (yyvsp[(2) - (3)].evalptr);
        print("exp -> ( exp )"); ;}
    break;

  case 95:
#line 837 "parser3.y"
    {
        (yyval.evalptr) = (yyvsp[(1) - (1)].evalptr);
        print("exp -> function_call");;}
    break;

  case 96:
#line 843 "parser3.y"
    {
    printf("in bi\n");
    (yyval.evalptr)=mkEval( 0 , 0 , 0 , "" , newTemp());
    loadTmpVal(((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str);
    loadTmpVal(((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str);
    emit("+" , ((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str , ((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str , ((struct Eval*)(yyval.evalptr))->str );
    saveTmpVal(((struct Eval*)(yyval.evalptr))->str);
print("binary_operation -> exp + exp"); ;}
    break;

  case 97:
#line 851 "parser3.y"
    {
        (yyval.evalptr)=mkEval( 0 , 0 , 0 , "" , newTemp() );
        loadTmpVal(((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str);
        loadTmpVal(((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str);
        emit("-" , ((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str , ((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str , ((struct Eval*)(yyval.evalptr))->str );
        saveTmpVal(((struct Eval*)(yyval.evalptr))->str);
        print("binary_operation -> exp - exp"); ;}
    break;

  case 98:
#line 858 "parser3.y"
    {
        (yyval.evalptr)=mkEval( 0 , 0 , 0 , "" , newTemp() );
        loadTmpVal(((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str);
        loadTmpVal(((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str);
        emit("*" , ((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str , ((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str , ((struct Eval*)(yyval.evalptr))->str );
        saveTmpVal(((struct Eval*)(yyval.evalptr))->str);
        print("binary_operation -> exp * exp"); ;}
    break;

  case 99:
#line 865 "parser3.y"
    {
        (yyval.evalptr)=mkEval( 0 , 0 , 0 , "" , newTemp() );
        loadTmpVal(((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str);
        loadTmpVal(((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str);
        emit("/" , ((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str , ((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str , ((struct Eval*)(yyval.evalptr))->str );
        saveTmpVal(((struct Eval*)(yyval.evalptr))->str);
        print("binary_operation -> exp / exp"); ;}
    break;

  case 100:
#line 872 "parser3.y"
    {
        (yyval.evalptr)=mkEval( 0 , 0 , 0 , "" , newTemp() );
        loadTmpVal(((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str);
        loadTmpVal(((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str);
        emit("%" , ((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str , ((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str , ((struct Eval*)(yyval.evalptr))->str );
        saveTmpVal(((struct Eval*)(yyval.evalptr))->str);;
        print("binary_operation -> exp % exp"); ;}
    break;

  case 101:
#line 879 "parser3.y"
    {
        (yyval.evalptr)=mkEval( 0 , 0 , 0 , "" , newTemp() );
        loadTmpVal(((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str);
        loadTmpVal(((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str);
        emit("^" , ((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str , ((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str , ((struct Eval*)(yyval.evalptr))->str );
        saveTmpVal(((struct Eval*)(yyval.evalptr))->str);
        print("binary_operation -> exp ^ exp"); ;}
    break;

  case 102:
#line 886 "parser3.y"
    {
        (yyval.evalptr)=mkEval( 0 , 0 , 0 , "" , newTemp() );
        loadTmpVal(((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str);
        loadTmpVal(((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str);
        emit("<<" , ((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str , ((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str , ((struct Eval*)(yyval.evalptr))->str );
        saveTmpVal(((struct Eval*)(yyval.evalptr))->str);
        print("binary_operation -> exp << exp");;}
    break;

  case 103:
#line 893 "parser3.y"
    {
        (yyval.evalptr)=mkEval( 0 , 0 , 0 , "" , newTemp() );
        loadTmpVal(((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str);
        loadTmpVal(((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str);
        emit(">>" , ((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str , ((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str , ((struct Eval*)(yyval.evalptr))->str );
        saveTmpVal(((struct Eval*)(yyval.evalptr))->str);
        print("binary_operation -> exp >> exp"); ;}
    break;

  case 104:
#line 902 "parser3.y"
    {
        backpatch( ((struct Eval*)(yyvsp[(1) - (4)].evalptr)) ->trueList , ((struct Eval*)(yyvsp[(3) - (4)].evalptr)) ->quad);
        (yyval.evalptr) = mkEval( ((struct Eval*)(yyvsp[(4) - (4)].evalptr)) ->trueList , mergeList( ((struct Eval*)(yyvsp[(1) - (4)].evalptr))->falseList , ((struct Eval*)(yyvsp[(4) - (4)].evalptr)) ->falseList ) , 0 , "*" , "" );
        print("logical_operation -> exp && exp");;}
    break;

  case 105:
#line 906 "parser3.y"
    {
        backpatch( ((struct Eval*)(yyvsp[(1) - (4)].evalptr)) ->falseList , ((struct Eval*)(yyvsp[(3) - (4)].evalptr)) ->quad);
        (yyval.evalptr) = mkEval( mergeList( ((struct Eval*)(yyvsp[(1) - (4)].evalptr))->trueList , ((struct Eval*)(yyvsp[(4) - (4)].evalptr)) ->trueList ), ((struct Eval*)(yyvsp[(4) - (4)].evalptr)) ->falseList , 0 , "*" , "" );
        print("logical_operation -> exp || exp");;}
    break;

  case 106:
#line 912 "parser3.y"
    {
        loadTmpVal( ((struct Eval*)(yyvsp[(1) - (3)].evalptr)) ->str );
        loadTmpVal( ((struct Eval*)(yyvsp[(3) - (3)].evalptr)) ->str );
        emit("if", ((struct Eval*)(yyvsp[(1) - (3)].evalptr)) ->str , "<" ,((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str );
        (yyval.evalptr) = mkEval( mkList(nextquad) , mkList(nextquad+2) , 0 , "*" , "");
        defaultGotoGen();
        defaultGotoGen();
        print("comparison_operation -> exp < exp"); ;}
    break;

  case 107:
#line 920 "parser3.y"
    {
        loadTmpVal( ((struct Eval*)(yyvsp[(1) - (3)].evalptr)) ->str );
              loadTmpVal( ((struct Eval*)(yyvsp[(3) - (3)].evalptr)) ->str );
              emit("if", ((struct Eval*)(yyvsp[(1) - (3)].evalptr)) ->str , "<=" ,((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str );
              (yyval.evalptr) = mkEval( mkList(nextquad) , mkList(nextquad+2) , 0 , "*" , "");
              defaultGotoGen();
              defaultGotoGen();
        print("comparison_operation -> exp <= exp"); ;}
    break;

  case 108:
#line 928 "parser3.y"
    {
        loadTmpVal( ((struct Eval*)(yyvsp[(1) - (3)].evalptr)) ->str );
              loadTmpVal( ((struct Eval*)(yyvsp[(3) - (3)].evalptr)) ->str );
              emit("if", ((struct Eval*)(yyvsp[(1) - (3)].evalptr)) ->str , ">" ,((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str );
              (yyval.evalptr) = mkEval( mkList(nextquad) , mkList(nextquad+2) , 0 , "*" , "");
              defaultGotoGen();
              defaultGotoGen();
        print("comparison_operation -> exp > exp"); ;}
    break;

  case 109:
#line 936 "parser3.y"
    {
        loadTmpVal( ((struct Eval*)(yyvsp[(1) - (3)].evalptr)) ->str );
              loadTmpVal( ((struct Eval*)(yyvsp[(3) - (3)].evalptr)) ->str );
              emit("if", ((struct Eval*)(yyvsp[(1) - (3)].evalptr)) ->str , ">=" ,((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str );
              (yyval.evalptr) = mkEval( mkList(nextquad) , mkList(nextquad+2) , 0 , "*" , "");
              defaultGotoGen();
              defaultGotoGen();
        print("comparison_operation -> exp >= exp");;}
    break;

  case 110:
#line 944 "parser3.y"
    {
        loadTmpVal( ((struct Eval*)(yyvsp[(1) - (3)].evalptr)) ->str );
              loadTmpVal( ((struct Eval*)(yyvsp[(3) - (3)].evalptr)) ->str );
              emit("if", ((struct Eval*)(yyvsp[(1) - (3)].evalptr)) ->str , "==" ,((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str );
              (yyval.evalptr) = mkEval( mkList(nextquad) , mkList(nextquad+2) , 0 , "*" , "");
              defaultGotoGen();
              defaultGotoGen();
        print("comparison_operation -> exp == exp"); ;}
    break;

  case 111:
#line 952 "parser3.y"
    {
        loadTmpVal( ((struct Eval*)(yyvsp[(1) - (3)].evalptr)) ->str );
              loadTmpVal( ((struct Eval*)(yyvsp[(3) - (3)].evalptr)) ->str );
              emit("if", ((struct Eval*)(yyvsp[(1) - (3)].evalptr)) ->str , "!=" ,((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str );
              (yyval.evalptr) = mkEval( mkList(nextquad) , mkList(nextquad+2) , 0 , "*" , "");
              defaultGotoGen();
              defaultGotoGen();
        print("comparison_operation -> exp != exp");;}
    break;

  case 112:
#line 962 "parser3.y"
    {
        (yyval.evalptr)=mkEval( 0 , 0 , 0 , "" , newTemp() );
               loadTmpVal(((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str);
               loadTmpVal(((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str);
               emit("&" , ((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str , ((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str , ((struct Eval*)(yyval.evalptr))->str );
               saveTmpVal(((struct Eval*)(yyval.evalptr))->str);
        print("bitwise_operation -> exp & exp");;}
    break;

  case 113:
#line 969 "parser3.y"
    {
        (yyval.evalptr)=mkEval( 0 , 0 , 0 , "" , newTemp() );
               loadTmpVal(((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str);
               loadTmpVal(((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str);
               emit("|" , ((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str , ((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str , ((struct Eval*)(yyval.evalptr))->str );
               saveTmpVal(((struct Eval*)(yyval.evalptr))->str);
        
        print("bitwise_operation -> exp | exp");;}
    break;

  case 114:
#line 979 "parser3.y"
    {
        (yyval.evalptr)=mkEval( 0 , 0 , 0 , "" , newTemp() );
        loadTmpVal(((struct Eval*)(yyvsp[(2) - (2)].evalptr))->str);
        emit("1-" , ((struct Eval*)(yyvsp[(2) - (2)].evalptr))->str , "" , ((struct Eval*)(yyval.evalptr))->str );
        saveTmpVal(((struct Eval*)(yyval.evalptr))->str);
        print("unary_operation -> - exp");;}
    break;

  case 115:
#line 985 "parser3.y"
    {print("unary_operation -> ! exp");
        (yyval.evalptr) = mkEval(((struct Eval*)(yyvsp[(2) - (2)].evalptr))->falseList, ((struct Eval*)(yyvsp[(2) - (2)].evalptr))->trueList, 0, "*", "");
      //  //TODO
    ;}
    break;

  case 116:
#line 989 "parser3.y"
    {
        (yyval.evalptr)=mkEval( 0 , 0 , 0 , "" , newTemp() );
        loadTmpVal(((struct Eval*)(yyvsp[(2) - (2)].evalptr))->str);
        emit("~" , ((struct Eval*)(yyvsp[(2) - (2)].evalptr))->str , "" , ((struct Eval*)(yyval.evalptr))->str );
        saveTmpVal(((struct Eval*)(yyval.evalptr))->str);
        print("unary_operation -> ~ exp");;}
    break;

  case 117:
#line 997 "parser3.y"
    {
        funcName = mkStr((yyvsp[(1) - (1)].sVal));
    ;}
    break;

  case 118:
#line 999 "parser3.y"
    {
        (yyval.evalptr)= (yyvsp[(3) - (3)].evalptr);
       printf( "function_call -> ID%s function_call_body", (yyvsp[(1) - (3)].sVal));
    ;}
    break;

  case 119:
#line 1003 "parser3.y"
    {
        printf( "function_call -> <ID, %s> . <ID, %s> function_call_body\n", (yyvsp[(1) - (4)].sVal), (yyvsp[(3) - (4)].sVal) );
        
    ;}
    break;

  case 120:
#line 1010 "parser3.y"
    {
        (yyval.evalptr) = mkEval( 0 , 0 , 0 , "" , functionCall ( funcName , ((struct Eval*)(yyvsp[(2) - (3)].evalptr))->str ) );
         printf("%s\n", funcName);
        print("function_call_body -> (actual_arguments)"); ;}
    break;

  case 121:
#line 1017 "parser3.y"
    {
        (yyval.evalptr) = (yyvsp[(1) - (1)].evalptr);
        print("actual_arguments -> actual_arguments_list");;}
    break;

  case 122:
#line 1020 "parser3.y"
    {
        (yyval.evalptr) = mkEval(0 , 0 , 0 , "" , "" );
        print("actual_arguments -> lambda");
        
    ;}
    break;

  case 123:
#line 1028 "parser3.y"
    {
        char* strTmp = strcat( ((struct Eval*)(yyvsp[(1) - (3)].evalptr))->str , "," );
        if( strcmp( ((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str , "" ) )
            strTmp = strcat( strTmp , ((struct Eval*)(yyvsp[(3) - (3)].evalptr))->str );
        else
        {
            char * mytmp = newTemp();
            assignBool(((struct Eval*)(yyvsp[(3) - (3)].evalptr)) ->trueList , ((struct Eval*)(yyvsp[(3) - (3)].evalptr)) ->falseList , mytmp , true , true );
            strTmp = strcat( strTmp , mytmp );
        }
        (yyval.evalptr) = mkEval(0 , 0 , 0 , "" , strTmp);
        print("actual_arguments_list -> actual_arguments_list , exp");;}
    break;

  case 124:
#line 1040 "parser3.y"
    {
        printf("explist->exp : %s\n", ((struct Eval*)(yyvsp[(1) - (1)].evalptr))->str  );
        char* strTmp;
        if( strcmp( ((struct Eval*)(yyvsp[(1) - (1)].evalptr))->str , "" ) )
            strTmp = strcat( ((struct Eval*)(yyvsp[(1) - (1)].evalptr))->str , "," );
        else
        {
            char * mytmp = newTemp();
            assignBool(((struct Eval*)(yyvsp[(1) - (1)].evalptr)) ->trueList , ((struct Eval*)(yyvsp[(1) - (1)].evalptr)) ->falseList , mytmp , true , true );
            strTmp = strcat( mytmp , "," );
            
        }
        (yyval.evalptr) = mkEval(0 , 0 , 0 , "" , strTmp);

        print("actual_arguments_list -> exp");;}
    break;


/* Line 1267 of yacc.c.  */
#line 3134 "parser3.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1057 "parser3.y"


int t=0;
int q=0;

void topPlsLoclNum(int quad)
{
  
    snprintf(num,5,"%d",top(tblptrStack)->localNum);
      emit("//", "in topPlsLoclNum()", num, intToString(quad));
    int i =0;
  //  printf("in topPlsLoclNum()\n");
  while(num[i]!='\0'){
      printf("in toppls %s\n", num);
      printf("in toppls %s %s %s\n", quad_ruples[quad][0], quad_ruples[quad][1], quad_ruples[quad][3]);
   quad_ruples[quad][2][i] = num[i];
  i++;
  }
  quad_ruples[quad][2][i] = num[i];
}

void loadTmpVal(char * theTmp){
  
    if( (theTmp[0]>='0' && theTmp[0]<='9') || strcmp(theTmp, "true")==0 || strcmp(theTmp, "false" )==0 || theTmp[0]=='-')
        return;
    int *i = (int *) malloc( sizeof(int) );
    int *j = (int *) malloc( sizeof(int) );
    char* addressOfStack = lookup(theTmp , top(tblptrStack) , i , j );
    emit("//", " load temp val: stack add:", addressOfStack, theTmp);
   emit( "PI" , addressOfStack , "" , theTmp );
}

void saveTmpVal(char* theTmp){
    if((theTmp[0]>='0' && theTmp[0]<='9') || strcmp(theTmp, "true" )==0 || strcmp(theTmp, "false" )==0 || theTmp[0]=='-')
        return;
    int *i = (int *) malloc( sizeof(int) );
    int *j = (int *) malloc( sizeof(int) );
    char* addressOfStack = lookup(theTmp , top(tblptrStack) , i , j );
    emit("//", " save temp val: stack add:", addressOfStack, theTmp);
   emit("IP" , theTmp , "" , addressOfStack );
}

struct Eval * idToEval(char * idName){
    
    int * intsize = (int *) malloc(sizeof(int));
    int * scopeID = (int *) malloc(sizeof(int));
    char* tmp = lookup( idName ,top(tblptrStack) , intsize , scopeID );
    char * num = (char*) malloc( sizeof(char) * 3 ) ;
    num =  intToString(*intsize);
    //printf("lvalue to Identifier\tintSize:%d\tnum=%s\tthe addres is:%s\n", *intsize , num , tmp);
    if(tmp == 0)
    {
        yyerror("Variable is not Defined!!!!!!\t:'(");
        return 0;
    }
    else
        return mkEval( 0,0, 0 , num , tmp);
}

char* functionCall(char* id ,char * explist){
    //emit("=" , "top" , "" , "sp");
    emit( "//" , "function call:" , id , "");
    printf("function call: %s \n" , id);
    //char * casStr = explist;
    char* strTmp = strtok( explist , "," );
    while( strTmp != 0 )//push variables
    {
        emit( "//" , "arg:" , strTmp , "");
        //casStr += strlen(strTmp) + 1 ;
        emit( "-" , "top" , "1" , "top" );
        loadTmpVal(strTmp);
        emit("IP" , strTmp , "" , "top" );
        strTmp = strtok( NULL , ",");
    }
    int* size = (int*) malloc( sizeof(int) );
    int* scopeID = (int*) malloc( sizeof(int) );
    //symbolTablePrint(top(tblptrStack) );
    printf("gonna look %s\n", top(tblptrStack)->name);
    char* tmp = lookup(id , top(tblptrStack) , size , scopeID);
     printf(" looked\n");
    printf("size is : %d" , *size );
   // if(*size>8)
        char * retLabel= newQuad();
        char * retaddress = newPTemp();
        
        //push number of arguments
        emit("-" , "top" , "1" , "top");
        char* buff = (char*) malloc( sizeof(char) * 3 );
        buff = intToString(*size - 9);
        if(strcmp(tmp, "-") != 0)
            sizeAdd[j] = nextquad;
        emit("IP" , buff , "" , "top" );
        
        //push return address
        emit("-" , "top" , "1" , "top");
        emit("&&" , retLabel , "" , retaddress);
        emit("-" , "atop" , "1" , "atop");
        emit("IP" , retaddress , "" , "atop");
        
        //push return value
        emit("-" , "top" , "1" , "top");
        
        //push sp
        emit("-" , "top" , "1" , "top");
        char* scopeid = (char*) malloc( sizeof(char) * 3 );
         scopeid= intToString(*scopeID);
         if(strcmp(tmp, "-") != 0)
            scpAdd[j] = nextquad;
        emit("IP" , scopeid , "" , "top");
        emit("-" , "atop" , "1" , "atop");
        emit("IP" , "sp" , "" , "atop");
        
        //call
        if(strcmp(tmp, "-") != 0)
            emit("goto" , tmp , "" , "");
        else{
            printf("hereeee\n");
            funcID[j] = id;
            address[j] = nextquad;
            emit("goto" , "" , "" , "");
            j++;
        }
        emit( "//" , "return after func call" , "" , "");
        //return location
        emit( strcat(retLabel ,":") , "" , "" , "");
        
        //get return value
        char* returnValue = newTemp();
        emit("+" , "top" , "1" , "top");
        emit("PI" , "top" , "" , returnValue);
        //printf("size is : %d" , *size );
        
        //make every thing normal
            //setting top
            emit("+" , "top" , "2" , "top");
            char* argcount = newITemp();
            emit("PI" , "top" , "" , argcount);
            emit("+" , argcount , "1" , argcount);
            emit("+" , "top" , argcount , "top");
            //setting sp
            emit("PI" , "atop" , "" , "sp");
            //setting atop
            emit("+" , "atop" , "2" , "atop");
        emit( "//" , "every thing is normal after func call:" , id , "");
        saveTmpVal(returnValue);
        return returnValue;

  /*  else{
        printf("No such Function!!! : %s\n" , id);
        errorFlag = true;
        return 0;
    }*/
}

char* mkCodeFndVarScp(int id){
    char * scopeId = (char*) malloc(sizeof(char) * 3);
    scopeId = intToString(id);
    
    char * loop = newQuad();
    char * outOfLoop = newQuad();
    char * loopLabel = (char* ) malloc( strlen(loop)+1 );
    strcpy(loopLabel , loop);
    strcat(loopLabel , ":");
    
    char * outOfLoopLabel = (char* ) malloc( strlen(outOfLoop)+1 );
    strcpy(outOfLoopLabel , outOfLoop );
    strcat(outOfLoopLabel , ":");
    
    char* vPointer = newVTemp();
    char* pPointer = newPTemp();
    char* value = newTemp();
    
    emit("=" , "atop" , "" , vPointer);
    emit(loopLabel , "" ,"" ,"");
    emit("PI" , vPointer , "" , pPointer);
    emit("PI" , pPointer , "" , value);
    emit("if" , value , "==" , scopeId);
    printf("emitted if %s\n", scopeId );
    emit("goto" , outOfLoop , "" , "");
    emit("+" , vPointer , "2" , vPointer );
    emit("goto" , loop , "" , "");
    emit(outOfLoopLabel , "" ,"" ,"");
    return pPointer;
}

char * lookup(char * name , struct SymbolTable* symbolTable , int * size ,int * scopeID){
    emit("//", "looking for:", name, "" );
    bool isInside=true;
    struct SymbolTable* currentTbl = symbolTable;
    
    while(currentTbl != NULL){
        
        struct SymbolTableNode* currentNode = currentTbl->head;
        // emit("//", "looking in", currentTbl->name, "" );
        printf("looking in %s\n", currentTbl->name);
        while(currentNode != NULL){
            //emit("//", "checking with", currentNode->name, "");
            
            if( strcmp( currentNode->name , name) == 0 )
            {
                *size = currentNode->size;
                emit("//", "the variable is found! id and size:" , intToString(currentTbl->ID) , intToString(*size));
                char* tblPtrTmp;
                
                if(*size >= 1 || *size==-2)
                {
                    *scopeID = currentTbl->ID;
                    if(isInside)
                    {
                        emit("//", "var is inside offset: ", intToString(currentNode->offset), "");
                        tblPtrTmp = newPTemp();
                        if(currentNode->offset>0){
                            emit("+" , "sp" , getOffset(currentNode->offset , currentTbl->argNum ) , tblPtrTmp );
                        }
                        else{
                           emit("-" , "sp" , getOffset(currentNode->offset , currentTbl->argNum ) , tblPtrTmp );
                        }
                        return tblPtrTmp;
                    }else{
                        emit("//", "var is outside offset: ", intToString(currentNode->offset), "");
                        tblPtrTmp = mkCodeFndVarScp(currentTbl->ID);
                        if(currentNode->offset>0){
                            emit("+" , tblPtrTmp , getOffset(currentNode->offset , currentTbl->argNum ) , tblPtrTmp );
                        }else{
                            emit("-" , tblPtrTmp , getOffset(currentNode->offset , currentTbl->argNum ) , tblPtrTmp );
                           }
                        return tblPtrTmp;
                    }
                }
                else{
                    printf("it is func!\n");
                    *scopeID = currentNode-> innerScope ->ID;
                    *size = 9 + (currentNode->innerScope->argNum);
                    return (currentNode->address);
                }
            }
           
            currentNode = currentNode->next;
        }
         
        currentTbl = currentTbl->outerScope;
       
        isInside = false;
        
    }
    printf("No such variable or Function!!! : %s\n" , name);
    *size = -1;
    *scopeID = -1;
    errorFlag = true;
    return "-";
}

char * assignBool(Node * trueList , Node * falseList , char* name , bool isVar , bool mkItEval)
{
    char* var;
    
    char * quad3 = newQuad();
    if(trueList!=0){
        char * quad1 = createLable();
        
        if(mkItEval){
            struct Eval* lvalueEval = idToEval(name);
            var = lvalueEval->str;
        }
        else{
            var = (char*) malloc(strlen(name));
            strcpy(var , name);
        }
        if(isVar)
            emit ( "IP" , "true" , "" , var );
        else
            emit ( "=" , "true" , "" , var );
        
        backpatch( trueList , quad1 );
        emit ( "goto" , quad3 , "" , "" );
    }
    if(falseList!=0)
    {
        char * quad2 = newQuad();
        char * colonQuad2 = (char *)malloc( strlen(quad2) );
        strcpy(colonQuad2 , quad2);
        strcat(colonQuad2 , ":");
        emit ( colonQuad2 , "" , "" , "" );
        if(mkItEval){
            struct Eval* lvalueEval = idToEval(name);
            var = lvalueEval->str;
        }
        else{
            var = (char*) malloc(strlen(name));
            strcpy(var , name);
        }
        if(isVar)
            emit ( "IP" , "false" , "" , var );
        else
            emit ( "=" , "false" , "" , var );
        backpatch( falseList , quad2 );
        emit ( "goto" , quad3 , "" , "" );
    }
    
    char * colonQuad3 = (char *)malloc( strlen(quad3) );
    strcpy(colonQuad3 , quad3);
    strcat(colonQuad3 , ":");
    emit ( colonQuad3 , "" , "" , "" );
    return var;
}


void writeTmpVar(FILE * f)
{
    char defStr[10000];
    strcpy(defStr , "double ");
    
    
    for(int i = 0 ; i<t ; i++)
    {
        snprintf(num,5,"%d",i);
        char * tmp = (char*) malloc( sizeof("t")+sizeof(num) );
        strcpy(tmp,  "t");
        strcat(tmp,num);
        strcat(defStr , tmp );
        strcat(defStr , " , " );
    }
    strcpy( defStr+strlen(defStr)-2 , ";\n" );
    if(t>0)
        fprintf(f,"%s", defStr );
    
    strcpy(defStr , "double ");
    
    for(int i = 0 ; i<tt ; i++)
    {
        snprintf(num,5,"%d",i);
        char * tmp = (char*) malloc( sizeof("*tt")+sizeof(num) );
        strcpy(tmp,  "*tt");
        strcat(tmp,num);
        strcat(defStr , tmp );
        strcat(defStr , " , " );
    }
    strcpy( defStr+strlen(defStr)-2 , ";\n" );
    if(tt>0)
       fprintf(f,"%s", defStr );
    
    strcpy(defStr , "double ");
    for(int i = 0 ; i<v ; i++)
    {
        snprintf(num,5,"%d",i);
        char * tmp = (char*) malloc( sizeof("**v")+sizeof(num) );
        strcpy(tmp,  "**v");
        strcat(tmp,num);
        strcat(defStr , tmp );
        strcat(defStr , " , " );
    }
    strcpy( defStr+strlen(defStr)-2 , ";\n" );
    if(v>0)
        fprintf(f,"%s", defStr );
    
    strcpy(defStr , "int ");
    for(int i = 0 ; i<I ; i++)
    {
        snprintf(num,5,"%d",i);
        char * tmp = (char*) malloc( sizeof("i")+sizeof(num) );
        strcpy(tmp,  "i");
        strcat(tmp,num);
        strcat(defStr , tmp );
        strcat(defStr , " , " );
    }
    strcpy( defStr+strlen(defStr)-2 , ";\n" );
    if(I>0)
       fprintf(f,"%s", defStr );
}

void mkCfile()
{
    FILE * fp;
   /* open the file for writing*/
   fp = fopen ("intermediate.c","w");
   fprintf(fp,"#include <stdbool.h>\n");
   fprintf(fp,"#include <stdlib.h>\n");
   fprintf(fp,"#include <stdio.h>\n");
   
   fprintf(fp,"double * top;\n");
   fprintf(fp,"double * sp;\n");
   fprintf(fp,"double ** atop;\n");
   
   writeTmpVar(fp);
   //writeVar( mainSymTbl , 8 , fp );
   //writeVar( mainSymTbl , 4 , fp );
   //writeVar( mainSymTbl , 1 , fp );
   
   fprintf(fp,"int main() {\n");
   fprintf(fp,"top = (double *) malloc(sizeof(double) *10001);\n");
   fprintf(fp,"atop = (double **) malloc(sizeof(double*) *1001);\n");
   fprintf(fp,"top = top + 10000;\n");
   fprintf(fp,"atop = atop + 1000;\n");
   fprintf(fp,"sp = top;\n\n");
   fprintf(fp,"*top = 0;\n\n");
   
   for(int i=0; i<=nextquad-1; i++){
       if( strcmp( quad_ruples[i][0] , "if" ) == 0 )
          fprintf(fp,"%s ( %s %s %s )\n",quad_ruples[i][0],quad_ruples[i][1],quad_ruples[i][2],quad_ruples[i][3]);
        else if(strcmp( quad_ruples[i][0] , "goto" ) == 0 )
            fprintf(fp,"\t\t%s %s; \n",quad_ruples[i][0],quad_ruples[i][1]);
        else if(strcmp( quad_ruples[i][0] , "int" ) == 0 )
            fprintf(fp,"\t\t%s %s; \n",quad_ruples[i][0],quad_ruples[i][1]);
        else if(strcmp( quad_ruples[i][0] , "=" ) == 0 )
            fprintf(fp,"\t%s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][0],quad_ruples[i][1]);
        else if(strcmp( quad_ruples[i][0] , "+" ) == 0 )
            fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
        else if(strcmp( quad_ruples[i][0] , ">>" ) == 0 )
            fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
        else if(strcmp( quad_ruples[i][0] , "<<" ) == 0 )
            fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
        else if(strcmp( quad_ruples[i][0] , "-" ) == 0 )
            fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
        else if(strcmp( quad_ruples[i][0] , "1-" ) == 0 )
            fprintf(fp,"\t%s = - %s; \n", quad_ruples[i][3] , quad_ruples[i][1]);
        else if(strcmp( quad_ruples[i][0] , "~" ) == 0 )
            fprintf(fp,"\t%s = ~ %s; \n", quad_ruples[i][3] , quad_ruples[i][1]);
        else if(strcmp( quad_ruples[i][0] , "|" ) == 0 )
            fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
        else if(strcmp( quad_ruples[i][0] , "&" ) == 0 )
            fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
        else if(strcmp( quad_ruples[i][0] , "*" ) == 0 )
            fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
        else if(strcmp( quad_ruples[i][0] , "%" ) == 0 )
            fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
        else if(strcmp( quad_ruples[i][0] , "/" ) == 0 )
            fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
        else if( strstr( quad_ruples[i][0] , ":" ) != 0 )
            fprintf(fp,"%s\n", quad_ruples[i][0]);
        else if(strcmp( quad_ruples[i][0] , "PI" ) == 0 )
            fprintf(fp,"\t%s = *%s; \n", quad_ruples[i][3] , quad_ruples[i][1] );
        else if(strcmp( quad_ruples[i][0] , "IP" ) == 0 )
            fprintf(fp,"\t*%s = %s; \n", quad_ruples[i][3] , quad_ruples[i][1] );
        else if(strcmp( quad_ruples[i][0] , "&&" ) == 0 )
            fprintf(fp,"\t%s = &&%s; \n", quad_ruples[i][3] , quad_ruples[i][1] );
        else if(strcmp( quad_ruples[i][0] , "//" ) == 0 )
            fprintf(fp,"//%s %s %s\n", quad_ruples[i][1] , quad_ruples[i][2] , quad_ruples[i][3] );
            else if(strcmp( quad_ruples[i][0] , "pr" ) == 0 ){
            fprintf(fp,"printf(\"%s\\n\", %s %s\n", "%lf",  quad_ruples[i][1] ,");" );
            }
        
    }
    fprintf(fp,"return 0;\n");
    fprintf(fp,"}\n");
 
   fclose (fp);
}


void defaultGotoGen(){
    char * tmp = newQuad();
    emit("goto",tmp,"","");
    emit(strcat(tmp,":") , "" ,"" ,"");
}



char * newQuad(){
    
  snprintf(num,5,"%d",q);
  char * tmp = (char*) malloc( sizeof("L")+sizeof(num) );
    strcpy(tmp,  "L");
  strcat(tmp,num);
  q++;
  return tmp;
  
}

char * newVTemp(){
    
  snprintf(num,5,"%d",v);
  char * tmp = (char*) malloc( sizeof("v")+sizeof(num) );
    strcpy(tmp,  "v");
  strcat(tmp,num);
  v++;
  return tmp;
}

char * newTemp(){
    
  snprintf(num,5,"%d",t);
  char * tmp = (char*) malloc( sizeof("t")+sizeof(num) );
    strcpy(tmp,  "t");
  strcat(tmp,num);
  tmp = mkStr(tmp);
  //printf("newTmp() : |%s|\n", tmp);
  enterVar( tmp, -2 , top(tblptrStack) );
  t++;
  return tmp;
}

char * newPTemp(){
    
  snprintf(num,5,"%d",tt);
  char * tmp = (char*) malloc( sizeof("tt")+sizeof(num) );
    strcpy(tmp,  "tt");
  strcat(tmp,num);
  tt++;
  return tmp;
}

char * newITemp(){
    
  snprintf(num,5,"%d",I);
  char * tmp = (char*) malloc( sizeof("i")+sizeof(num) );
    strcpy(tmp,  "i");
  strcat(tmp,num);
  I++;
  return tmp;
}

char* createLable(){
    char * tmp = newQuad();
    char *ttmp = mkStr(tmp);
    emit(strcat(ttmp,":") , "" ,"" ,"");
    return tmp;
}

struct Eval* strToEval(char* input){
    
    struct Eval* e = (struct Eval*) malloc (sizeof(struct Eval));
    char * string = (char*) malloc (strlen(input));
    strcpy(string , input);
    e->str = string;
    e->trueList = 0;
    e->falseList = 0;
    e->nextList = 0;
    e->quad = mkStr("");
    return e;
}

void mkSymTbl(char * name)
{
    struct SymbolTable* t = mkTable( top(tblptrStack) , name );
    push(t, tblptrStack);
}

struct SymbolTable* popTop(struct Stack* b ){
    pop(b);
    return top(b);
}

int main(){

    tblptrStack = createStack();
    printf("created\n");
    tblptrStack->top = NULL;
    yyin = fopen("input.txt", "r");
    printf("input opened \n");
    IDHead = (struct MyNode*)malloc(sizeof(struct MyNode));
    IDHead->data = NULL;
    IDHead->next = NULL;
    IDCurrent = IDHead;
    output = fopen("output.txt", "w");
   // symTable = fopen("symbolTable.txt", "w");
    yyparse();
    
    if(errorFlag)
    {
        printf("!!!!!!!!OH!!!!!!!!! <<<<ERROR>>>> !!!!!!!!OH!!!!!!!!!! \t :'( /_\\");
    }
    quad_display();
    mkCfile();
    printf("------<<<<<<<***** FINISH *****>>>>>>------ :D *_*");
    return 0;
}

/*int main(){
	yyin = fopen("input.txt", "r");
    if(yyin == NULL){
        printf("oops");
    }
    else{
        
    printf("yey");
    IDHead = (struct MyNode*)malloc(sizeof(struct MyNode));
    IDHead->data = NULL;
    IDHead->next = NULL;
    IDCurrent = IDHead;
    output = fopen("output.txt", "w");
    symTable = fopen("symbolTable.txt", "w");
    yyparse();
	fclose(output);
    fclose(symTable);
    }
	fclose(yyin);
    return 0;
}*/

void print(const char* string){
    printf( "\n%s\n", string);
}

void yyerror( char* error){
	fprintf(output, "Error: %s\n", error);
}

