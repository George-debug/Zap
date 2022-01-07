/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    RETURN = 259,                  /* RETURN  */
    ASSIGN = 260,                  /* ASSIGN  */
    CONSTANT = 261,                /* CONSTANT  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    WHILE = 264,                   /* WHILE  */
    DO = 265,                      /* DO  */
    UNTIL = 266,                   /* UNTIL  */
    VOID = 267,                    /* VOID  */
    LESS = 268,                    /* LESS  */
    LESS_EQUAL = 269,              /* LESS_EQUAL  */
    GREATER = 270,                 /* GREATER  */
    GREATER_EQUAL = 271,           /* GREATER_EQUAL  */
    EQUAL = 272,                   /* EQUAL  */
    NOT_EQUAL = 273,               /* NOT_EQUAL  */
    AND = 274,                     /* AND  */
    OR = 275,                      /* OR  */
    NOT = 276,                     /* NOT  */
    PLUS = 277,                    /* PLUS  */
    MINUS = 278,                   /* MINUS  */
    MOD = 279,                     /* MOD  */
    DIGIT_SEQUENCE = 280,          /* DIGIT_SEQUENCE  */
    TYPE = 281,                    /* TYPE  */
    STAR = 282,                    /* STAR  */
    DIV = 283,                     /* DIV  */
    UMINUS = 284                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define RETURN 259
#define ASSIGN 260
#define CONSTANT 261
#define IF 262
#define ELSE 263
#define WHILE 264
#define DO 265
#define UNTIL 266
#define VOID 267
#define LESS 268
#define LESS_EQUAL 269
#define GREATER 270
#define GREATER_EQUAL 271
#define EQUAL 272
#define NOT_EQUAL 273
#define AND 274
#define OR 275
#define NOT 276
#define PLUS 277
#define MINUS 278
#define MOD 279
#define DIGIT_SEQUENCE 280
#define TYPE 281
#define STAR 282
#define DIV 283
#define UMINUS 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 11 "./src/zap.y"

    float float_val;
    int int_val;
    char *string_val;
    struct Zap_Type_Value *zap_val;
    struct Zap_Expression *zap_expression_val;

#line 133 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
