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
    RETURN = 258,                  /* RETURN  */
    ASSIGN = 259,                  /* ASSIGN  */
    CONSTANT = 260,                /* CONSTANT  */
    IF = 261,                      /* IF  */
    ELSE = 262,                    /* ELSE  */
    WHILE = 263,                   /* WHILE  */
    DO = 264,                      /* DO  */
    UNTIL = 265,                   /* UNTIL  */
    VOID = 266,                    /* VOID  */
    LESS = 267,                    /* LESS  */
    LESS_EQUAL = 268,              /* LESS_EQUAL  */
    GREATER = 269,                 /* GREATER  */
    GREATER_EQUAL = 270,           /* GREATER_EQUAL  */
    EQUAL = 271,                   /* EQUAL  */
    NOT_EQUAL = 272,               /* NOT_EQUAL  */
    AND = 273,                     /* AND  */
    OR = 274,                      /* OR  */
    NOT = 275,                     /* NOT  */
    PLUS = 276,                    /* PLUS  */
    MINUS = 277,                   /* MINUS  */
    MOD = 278,                     /* MOD  */
    DIGIT_SEQUENCE = 279,          /* DIGIT_SEQUENCE  */
    IDENTIFIER = 280,              /* IDENTIFIER  */
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
#define RETURN 258
#define ASSIGN 259
#define CONSTANT 260
#define IF 261
#define ELSE 262
#define WHILE 263
#define DO 264
#define UNTIL 265
#define VOID 266
#define LESS 267
#define LESS_EQUAL 268
#define GREATER 269
#define GREATER_EQUAL 270
#define EQUAL 271
#define NOT_EQUAL 272
#define AND 273
#define OR 274
#define NOT 275
#define PLUS 276
#define MINUS 277
#define MOD 278
#define DIGIT_SEQUENCE 279
#define IDENTIFIER 280
#define TYPE 281
#define STAR 282
#define DIV 283
#define UMINUS 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "zap.y"

    float float_val;
    int int_val;
    char *string_val;
    struct Zap_Type_Value *zap_val;
    struct Zap_Expression *zap_expression_val;
    struct Vector *vector_val;
    struct Zap_Init_Declaration *zap_init_declarator_val;
    enum Zap_Variable_Type zap_variable_type_val;
    struct Zap_Declaration* zap_declaration_val;
    struct Zap_Assignation* zap_assignation_val;

#line 138 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
