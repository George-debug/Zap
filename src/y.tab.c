/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "zap.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "umbrella.h"

extern FILE* yyin;
extern char* yytext;
extern int yylineno;

//struct Vector *variable_table_list, *global_scope;


#line 86 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    TRUE = 279,                    /* TRUE  */
    FALSE = 280,                   /* FALSE  */
    BREAK = 281,                   /* BREAK  */
    EXIT = 282,                    /* EXIT  */
    CONTINUE = 283,                /* CONTINUE  */
    STRING_LITERAL = 284,          /* STRING_LITERAL  */
    DIGIT_SEQUENCE = 285,          /* DIGIT_SEQUENCE  */
    IDENTIFIER = 286,              /* IDENTIFIER  */
    TYPE = 287,                    /* TYPE  */
    STAR = 288,                    /* STAR  */
    DIV = 289,                     /* DIV  */
    UMINUS = 290                   /* UMINUS  */
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
#define TRUE 279
#define FALSE 280
#define BREAK 281
#define EXIT 282
#define CONTINUE 283
#define STRING_LITERAL 284
#define DIGIT_SEQUENCE 285
#define IDENTIFIER 286
#define TYPE 287
#define STAR 288
#define DIV 289
#define UMINUS 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "zap.y"

    bool bool_val;
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
    struct Zap_Block_Item* zap_block_item_val;
    struct Zap_Function_Call* zap_function_call_val;
    struct Zap_Selection_Statement* zap_selection_statement_val;
    struct Zap_Iteration_Statement* zap_iteration_statement_val;
    struct Zap_Signal* zap_signal_val;

#line 228 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_RETURN = 3,                     /* RETURN  */
  YYSYMBOL_ASSIGN = 4,                     /* ASSIGN  */
  YYSYMBOL_CONSTANT = 5,                   /* CONSTANT  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_DO = 9,                         /* DO  */
  YYSYMBOL_UNTIL = 10,                     /* UNTIL  */
  YYSYMBOL_VOID = 11,                      /* VOID  */
  YYSYMBOL_LESS = 12,                      /* LESS  */
  YYSYMBOL_LESS_EQUAL = 13,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER = 14,                   /* GREATER  */
  YYSYMBOL_GREATER_EQUAL = 15,             /* GREATER_EQUAL  */
  YYSYMBOL_EQUAL = 16,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 17,                 /* NOT_EQUAL  */
  YYSYMBOL_AND = 18,                       /* AND  */
  YYSYMBOL_OR = 19,                        /* OR  */
  YYSYMBOL_NOT = 20,                       /* NOT  */
  YYSYMBOL_PLUS = 21,                      /* PLUS  */
  YYSYMBOL_MINUS = 22,                     /* MINUS  */
  YYSYMBOL_MOD = 23,                       /* MOD  */
  YYSYMBOL_TRUE = 24,                      /* TRUE  */
  YYSYMBOL_FALSE = 25,                     /* FALSE  */
  YYSYMBOL_BREAK = 26,                     /* BREAK  */
  YYSYMBOL_EXIT = 27,                      /* EXIT  */
  YYSYMBOL_CONTINUE = 28,                  /* CONTINUE  */
  YYSYMBOL_STRING_LITERAL = 29,            /* STRING_LITERAL  */
  YYSYMBOL_DIGIT_SEQUENCE = 30,            /* DIGIT_SEQUENCE  */
  YYSYMBOL_IDENTIFIER = 31,                /* IDENTIFIER  */
  YYSYMBOL_TYPE = 32,                      /* TYPE  */
  YYSYMBOL_STAR = 33,                      /* STAR  */
  YYSYMBOL_DIV = 34,                       /* DIV  */
  YYSYMBOL_UMINUS = 35,                    /* UMINUS  */
  YYSYMBOL_36_ = 36,                       /* ','  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* '['  */
  YYSYMBOL_43_ = 43,                       /* ']'  */
  YYSYMBOL_44_ = 44,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_progr = 46,                     /* progr  */
  YYSYMBOL_translation_unit = 47,          /* translation_unit  */
  YYSYMBOL_statement_unit = 48,            /* statement_unit  */
  YYSYMBOL_compound_statement = 49,        /* compound_statement  */
  YYSYMBOL_block_item_list = 50,           /* block_item_list  */
  YYSYMBOL_block_item = 51,                /* block_item  */
  YYSYMBOL_assignation = 52,               /* assignation  */
  YYSYMBOL_iteration_statement = 53,       /* iteration_statement  */
  YYSYMBOL_selection_statement = 54,       /* selection_statement  */
  YYSYMBOL_signal_statement = 55,          /* signal_statement  */
  YYSYMBOL_exit_statement = 56,            /* exit_statement  */
  YYSYMBOL_return_statement = 57,          /* return_statement  */
  YYSYMBOL_function_declaration = 58,      /* function_declaration  */
  YYSYMBOL_function_call = 59,             /* function_call  */
  YYSYMBOL_function_argument_list = 60,    /* function_argument_list  */
  YYSYMBOL_function_argument = 61,         /* function_argument  */
  YYSYMBOL_declaration = 62,               /* declaration  */
  YYSYMBOL_init_declarator_list = 63,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 64,           /* init_declarator  */
  YYSYMBOL_expression = 65,                /* expression  */
  YYSYMBOL_identifier_list = 66,           /* identifier_list  */
  YYSYMBOL_boolean_constant = 67,          /* boolean_constant  */
  YYSYMBOL_unsigned_integer = 68,          /* unsigned_integer  */
  YYSYMBOL_unsigned_rational = 69          /* unsigned_rational  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  55
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   409

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,     2,     2,    36,     2,    44,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    65,    65,    70,    76,    77,    81,   129,   133,   141,
     145,   155,   160,   164,   168,   172,   176,   181,   188,   195,
     199,   203,   210,   214,   221,   225,   229,   233,   240,   244,
     251,   255,   262,   263,   264,   265,   269,   278,   279,   283,
     284,   288,   292,   299,   305,   314,   323,   332,   349,   361,
     372,   383,   394,   403,   404,   405,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   423,   428,   432,
     433,   437,   441,   448,   456,   463
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "RETURN", "ASSIGN",
  "CONSTANT", "IF", "ELSE", "WHILE", "DO", "UNTIL", "VOID", "LESS",
  "LESS_EQUAL", "GREATER", "GREATER_EQUAL", "EQUAL", "NOT_EQUAL", "AND",
  "OR", "NOT", "PLUS", "MINUS", "MOD", "TRUE", "FALSE", "BREAK", "EXIT",
  "CONTINUE", "STRING_LITERAL", "DIGIT_SEQUENCE", "IDENTIFIER", "TYPE",
  "STAR", "DIV", "UMINUS", "','", "'{'", "'}'", "';'", "'('", "')'", "'['",
  "']'", "'.'", "$accept", "progr", "translation_unit", "statement_unit",
  "compound_statement", "block_item_list", "block_item", "assignation",
  "iteration_statement", "selection_statement", "signal_statement",
  "exit_statement", "return_statement", "function_declaration",
  "function_call", "function_argument_list", "function_argument",
  "declaration", "init_declarator_list", "init_declarator", "expression",
  "identifier_list", "boolean_constant", "unsigned_integer",
  "unsigned_rational", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-34)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   311,    12,     5,    13,    31,    19,    15,   323,    33,
       1,    42,   -34,    76,     4,   -34,   -34,   -34,   -34,   -34,
     -34,   -34,   -34,   -34,    40,   -34,   344,   344,   -34,   -34,
     -34,    39,   -34,   -34,   344,    54,   249,   -34,   -34,   -34,
      59,   344,   344,   -34,    17,    51,   -34,   -34,   277,   -34,
     344,   -34,    -3,   -16,   -34,   -34,   -34,   -34,   364,   -34,
      62,    99,   -34,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   -34,    -2,   -15,   129,
     159,    43,    63,    65,   -27,   -34,   305,     6,   344,   -25,
      72,    59,   -34,   -34,   -34,    70,    70,    70,    70,    10,
      10,    90,   -34,    82,    82,   387,   387,   387,   -34,    31,
      31,    59,   -34,   -34,   344,   344,   -34,    31,   -33,   -34,
      87,    92,   -34,   -34,   364,    31,   -19,   -34,    81,   -34,
     118,   -34,   189,   219,   -34,    95,    31,    96,   -34,   -34,
      31,   -34,    31,    89,    91,   -34,   -34,   -34,   -34,   -34,
     -34,   -34
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,     0,     2,     4,     6,    12,    13,    14,
      15,    27,    24,     7,     0,    11,     0,     0,    71,    72,
      51,    73,    52,    31,     0,     0,     0,    48,    49,    50,
       0,     0,     0,     9,     0,     0,    25,    29,     0,    26,
       0,    37,    45,     0,    43,     1,     5,    16,    66,    68,
       0,     0,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,    45,     0,     0,
       0,     0,     0,     0,     0,    28,     0,     0,     0,     0,
       0,     0,    41,    74,    67,    58,    59,    60,    61,    62,
      63,    64,    65,    55,    56,    57,    53,    54,    42,     0,
       0,     0,     8,    10,     0,     0,    69,     0,     0,    18,
       0,     0,    36,    38,    46,     0,     0,    73,     0,    44,
      22,    19,     0,     0,    35,     0,     0,     0,    39,    33,
       0,    47,     0,     0,     0,    70,    34,    40,    32,    23,
      20,    21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,   -34,   -34,   115,   -32,   -34,    50,   -34,   -34,   -34,
     -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,    94,    44,
      -8,    47,   -34,    48,   -34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    13,    14,    15,    44,    81,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    87,   123,    25,    53,    54,
      36,   118,    37,    38,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      48,    88,    88,   135,   116,    50,   116,     1,   136,     2,
       3,   120,     4,     5,   117,     6,   125,   135,    58,    59,
      91,    91,   140,    92,   108,    82,    61,    83,    69,    70,
       7,     8,     9,    79,    80,    10,    11,    89,   121,    90,
      90,    51,    86,    12,    40,    41,     1,   122,     2,     3,
      45,     4,     5,    42,    46,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,    43,     7,
       8,     9,    49,    52,    10,   111,    55,   130,   131,    57,
     124,   112,    12,    60,    62,   134,    67,    68,    69,    70,
      77,    84,    93,   139,    63,    64,    65,    66,    67,    68,
      69,    70,   127,   114,   146,   115,   132,   133,   148,    70,
     149,    63,    64,    65,    66,    67,    68,    69,    70,   137,
      71,    72,    73,   138,   141,   142,   145,   147,   150,    56,
     151,   113,    74,    75,    78,   129,   126,     0,   128,     0,
      94,    63,    64,    65,    66,    67,    68,    69,    70,     0,
      71,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    75,     0,     0,     0,     0,     0,     0,
     109,    63,    64,    65,    66,    67,    68,    69,    70,     0,
      71,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    75,     0,     0,     0,     0,     0,     0,
     110,    63,    64,    65,    66,    67,    68,    69,    70,     0,
      71,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    75,     0,     0,     0,     0,     0,     0,
     143,    63,    64,    65,    66,    67,    68,    69,    70,     0,
      71,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    75,     0,     0,     0,     0,     0,     0,
     144,    63,    64,    65,    66,    67,    68,    69,    70,     0,
      71,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    75,     0,     0,     0,     0,    76,    63,
      64,    65,    66,    67,    68,    69,    70,     0,    71,    72,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    75,     0,     0,     0,     0,    85,    63,    64,    65,
      66,    67,    68,    69,    70,     0,    71,    72,    73,     0,
       0,    26,     0,    27,     0,    28,    29,     0,    74,    75,
      30,    31,    32,    26,   119,    27,     0,    28,    29,     0,
      33,    34,    30,    31,    32,    35,     0,     0,     0,     0,
       0,     0,    47,    34,    26,     0,    27,    35,    28,    29,
       0,     0,     0,    30,    31,    32,    63,    64,    65,    66,
      67,    68,    69,    70,    34,    71,    72,    73,    35,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    63,
      64,    65,    66,    67,    68,    69,    70,     0,    71,    72
};

static const yytype_int16 yycheck[] =
{
       8,     4,     4,    36,    31,     4,    31,     3,    41,     5,
       6,     5,     8,     9,    41,    11,    41,    36,    26,    27,
      36,    36,    41,    39,    39,     8,    34,    10,    18,    19,
      26,    27,    28,    41,    42,    31,    32,    40,    32,    42,
      42,    40,    50,    39,    32,    40,     3,    41,     5,     6,
      31,     8,     9,    40,    39,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    37,    26,
      27,    28,    39,    31,    31,    32,     0,   109,   110,    39,
      88,    38,    39,    44,    30,   117,    16,    17,    18,    19,
      31,    40,    30,   125,    12,    13,    14,    15,    16,    17,
      18,    19,    30,    40,   136,    40,   114,   115,   140,    19,
     142,    12,    13,    14,    15,    16,    17,    18,    19,    32,
      21,    22,    23,    31,    43,     7,    31,    31,    39,    14,
      39,    81,    33,    34,    40,    91,    89,    -1,    90,    -1,
      41,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    39,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    -1,    -1,    -1,    39,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    22,    23,    -1,
      -1,    20,    -1,    22,    -1,    24,    25,    -1,    33,    34,
      29,    30,    31,    20,    39,    22,    -1,    24,    25,    -1,
      39,    40,    29,    30,    31,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    20,    -1,    22,    44,    24,    25,
      -1,    -1,    -1,    29,    30,    31,    12,    13,    14,    15,
      16,    17,    18,    19,    40,    21,    22,    23,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    21,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     8,     9,    11,    26,    27,    28,
      31,    32,    39,    46,    47,    48,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    62,    20,    22,    24,    25,
      29,    30,    31,    39,    40,    44,    65,    67,    68,    69,
      32,    40,    40,    37,    49,    31,    39,    39,    65,    39,
       4,    40,    31,    63,    64,     0,    48,    39,    65,    65,
      44,    65,    30,    12,    13,    14,    15,    16,    17,    18,
      19,    21,    22,    23,    33,    34,    39,    31,    63,    65,
      65,    50,     8,    10,    40,    39,    65,    60,     4,    40,
      42,    36,    39,    30,    41,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    39,    41,
      41,    32,    38,    51,    40,    40,    31,    41,    66,    39,
       5,    32,    41,    61,    65,    41,    66,    30,    68,    64,
      49,    49,    65,    65,    49,    36,    41,    32,    31,    49,
      41,    43,     7,    41,    41,    31,    49,    31,    49,    49,
      39,    39
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    46,    47,    47,    48,    48,    49,    50,
      50,    51,    51,    51,    51,    51,    51,    51,    52,    53,
      53,    53,    54,    54,    55,    55,    55,    55,    56,    56,
      57,    57,    58,    58,    58,    58,    59,    60,    60,    61,
      61,    62,    62,    63,    63,    64,    64,    64,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    66,
      66,    67,    67,    68,    69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     3,     0,
       2,     1,     1,     1,     1,     1,     2,     1,     4,     5,
       7,     7,     5,     7,     1,     2,     2,     1,     3,     2,
       3,     2,     6,     5,     6,     5,     4,     0,     2,     2,
       3,     3,     4,     1,     3,     1,     3,     4,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     2,     1,
       3,     1,     1,     1,     3,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* progr: translation_unit  */
#line 66 "zap.y"
    {
        printf("program corect sintactic\n");
    }
#line 1430 "y.tab.c"
    break;

  case 3: /* progr: %empty  */
#line 70 "zap.y"
    {
        printf("De unde program?\n");
    }
#line 1438 "y.tab.c"
    break;

  case 6: /* statement_unit: block_item  */
#line 82 "zap.y"
    {
        //printf("I'll run\n");
        struct Zap_Signal* sig = run_zap_block_item((yyvsp[0].zap_block_item_val));

        //printf("I ran\n");

        switch (sig->sig_type)
        {
        case Continue_Signal:
        {
            perror("You can't have \"continue\" outside loops\n Why would that be helpful? Meh... I'll just ignore it for now!\n");
            break;
        }

        case Return_Signal:
        {
            printf("Program returned ");

            if(sig->carry == NULL)
                printf("without any value\n");
            else
                // PRINT THE VALUE
                printf("0\n");

            exit(0);
        }

        case Break_Signal:
        {
            perror("Break doesn't work outside loops.\n Did you mean \"return\"?");
            break;
        }

        case Exit_Signal:
        {
            printf("Program exit ");

            if(sig->carry == NULL)
                printf("without any value\n");
            else
                // PRINT THE VALUE
                printf("0\n");

            exit(0);
        }
        }
    }
#line 1490 "y.tab.c"
    break;

  case 8: /* compound_statement: '{' block_item_list '}'  */
#line 134 "zap.y"
    {
        (yyval.vector_val) = (yyvsp[-1].vector_val);
    }
#line 1498 "y.tab.c"
    break;

  case 9: /* block_item_list: %empty  */
#line 141 "zap.y"
    {
        //printf("start block_item_list\n");
        (yyval.vector_val) = create_vector(sizeof(struct Zap_Block_Item), 10);
    }
#line 1507 "y.tab.c"
    break;

  case 10: /* block_item_list: block_item_list block_item  */
#line 146 "zap.y"
    {
        //printf("continue block_item_list\n");
        if((yyvsp[0].zap_block_item_val) != NULL)
            add_to_vector((yyvsp[-1].vector_val), (yyvsp[0].zap_block_item_val));
        (yyval.vector_val) = (yyvsp[-1].vector_val);
    }
#line 1518 "y.tab.c"
    break;

  case 11: /* block_item: declaration  */
#line 156 "zap.y"
    {
        //printf("create declaration\n");
        (yyval.zap_block_item_val) = create_zap_block_item((yyvsp[0].zap_declaration_val), Declaration_Type);
    }
#line 1527 "y.tab.c"
    break;

  case 12: /* block_item: assignation  */
#line 161 "zap.y"
    {
        (yyval.zap_block_item_val) = create_zap_block_item((yyvsp[0].zap_assignation_val), Assignation_Type);
    }
#line 1535 "y.tab.c"
    break;

  case 13: /* block_item: iteration_statement  */
#line 165 "zap.y"
    {
        (yyval.zap_block_item_val) = create_zap_block_item((yyvsp[0].zap_iteration_statement_val), Iteration_Statement_Type);
    }
#line 1543 "y.tab.c"
    break;

  case 14: /* block_item: selection_statement  */
#line 169 "zap.y"
    {
        (yyval.zap_block_item_val) = create_zap_block_item((yyvsp[0].zap_selection_statement_val), Selection_Statement_Type);
    }
#line 1551 "y.tab.c"
    break;

  case 15: /* block_item: signal_statement  */
#line 173 "zap.y"
    {
        (yyval.zap_block_item_val) = create_zap_block_item((yyvsp[0].zap_signal_val), Signal_Statement_Type);
    }
#line 1559 "y.tab.c"
    break;

  case 16: /* block_item: function_call ';'  */
#line 177 "zap.y"
    {
        //printf("call function;\n");
        (yyval.zap_block_item_val) = create_zap_block_item((yyvsp[-1].zap_function_call_val), Function_Call_Type);
    }
#line 1568 "y.tab.c"
    break;

  case 17: /* block_item: ';'  */
#line 182 "zap.y"
    {
        (yyval.zap_block_item_val) = NULL;
    }
#line 1576 "y.tab.c"
    break;

  case 18: /* assignation: IDENTIFIER ASSIGN expression ';'  */
#line 189 "zap.y"
    {
        (yyval.zap_assignation_val) = create_zap_assignation((yyvsp[-3].string_val), (yyvsp[-1].zap_expression_val));
    }
#line 1584 "y.tab.c"
    break;

  case 19: /* iteration_statement: WHILE '(' expression ')' compound_statement  */
#line 196 "zap.y"
    {
        (yyval.zap_iteration_statement_val) = create_zap_iteration_statement(While_Type, (yyvsp[-2].zap_expression_val), (yyvsp[0].vector_val));
    }
#line 1592 "y.tab.c"
    break;

  case 20: /* iteration_statement: DO compound_statement WHILE '(' expression ')' ';'  */
#line 200 "zap.y"
    {
        (yyval.zap_iteration_statement_val) = create_zap_iteration_statement(Do_While_Type, (yyvsp[-2].zap_expression_val), (yyvsp[-5].vector_val));
    }
#line 1600 "y.tab.c"
    break;

  case 21: /* iteration_statement: DO compound_statement UNTIL '(' expression ')' ';'  */
#line 204 "zap.y"
    {
        (yyval.zap_iteration_statement_val) = create_zap_iteration_statement(Do_Until_Type, (yyvsp[-2].zap_expression_val), (yyvsp[-5].vector_val));
    }
#line 1608 "y.tab.c"
    break;

  case 22: /* selection_statement: IF '(' expression ')' compound_statement  */
#line 211 "zap.y"
    {
        (yyval.zap_selection_statement_val) = create_zap_selection_statement((yyvsp[-2].zap_expression_val), (yyvsp[0].vector_val), NULL);
    }
#line 1616 "y.tab.c"
    break;

  case 23: /* selection_statement: IF '(' expression ')' compound_statement ELSE compound_statement  */
#line 215 "zap.y"
    {
        (yyval.zap_selection_statement_val) = create_zap_selection_statement((yyvsp[-4].zap_expression_val), (yyvsp[-2].vector_val), (yyvsp[0].vector_val));
    }
#line 1624 "y.tab.c"
    break;

  case 24: /* signal_statement: return_statement  */
#line 222 "zap.y"
    {
        (yyval.zap_signal_val) = (yyvsp[0].zap_signal_val);
    }
#line 1632 "y.tab.c"
    break;

  case 25: /* signal_statement: BREAK ';'  */
#line 226 "zap.y"
    {
        (yyval.zap_signal_val) = create_zap_signal(Break_Signal, NULL);
    }
#line 1640 "y.tab.c"
    break;

  case 26: /* signal_statement: CONTINUE ';'  */
#line 230 "zap.y"
    {
        (yyval.zap_signal_val) = create_zap_signal(Continue_Signal, NULL);
    }
#line 1648 "y.tab.c"
    break;

  case 27: /* signal_statement: exit_statement  */
#line 234 "zap.y"
    {
        (yyval.zap_signal_val) = (yyvsp[0].zap_signal_val);
    }
#line 1656 "y.tab.c"
    break;

  case 28: /* exit_statement: EXIT expression ';'  */
#line 241 "zap.y"
    {
        (yyval.zap_signal_val) = create_zap_signal(Exit_Signal, (yyvsp[-1].zap_expression_val));
    }
#line 1664 "y.tab.c"
    break;

  case 29: /* exit_statement: EXIT ';'  */
#line 245 "zap.y"
    {
        (yyval.zap_signal_val) = create_zap_signal(Exit_Signal, NULL);
    }
#line 1672 "y.tab.c"
    break;

  case 30: /* return_statement: RETURN expression ';'  */
#line 252 "zap.y"
    {
        (yyval.zap_signal_val) = create_zap_signal(Return_Signal, (yyvsp[-1].zap_expression_val));
    }
#line 1680 "y.tab.c"
    break;

  case 31: /* return_statement: RETURN ';'  */
#line 256 "zap.y"
    {
        (yyval.zap_signal_val) = create_zap_signal(Return_Signal, NULL);
    }
#line 1688 "y.tab.c"
    break;

  case 36: /* function_call: IDENTIFIER '(' function_argument_list ')'  */
#line 270 "zap.y"
    {
        print_all_variables();

        (yyval.zap_function_call_val) = create_zap_function_call((yyvsp[-3].string_val));
    }
#line 1698 "y.tab.c"
    break;

  case 41: /* declaration: TYPE init_declarator_list ';'  */
#line 289 "zap.y"
    {
        (yyval.zap_declaration_val) = create_zap_declaration((yyvsp[-1].vector_val), (yyvsp[-2].zap_variable_type_val), false);
    }
#line 1706 "y.tab.c"
    break;

  case 42: /* declaration: CONSTANT TYPE init_declarator_list ';'  */
#line 293 "zap.y"
    {
        (yyval.zap_declaration_val) = create_zap_declaration((yyvsp[-1].vector_val), (yyvsp[-2].zap_variable_type_val), true);
    }
#line 1714 "y.tab.c"
    break;

  case 43: /* init_declarator_list: init_declarator  */
#line 300 "zap.y"
    {
        //printf("begins init_declarator_list\n");
        (yyval.vector_val) = create_vector(sizeof(struct Zap_Init_Declaration), 10);
        add_to_vector((yyval.vector_val), (yyvsp[0].zap_init_declarator_val));
    }
#line 1724 "y.tab.c"
    break;

  case 44: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 306 "zap.y"
    {
        //printf("continue init_declarator_list\n");
        add_to_vector((yyvsp[-2].vector_val), (yyvsp[0].zap_init_declarator_val));
        (yyval.vector_val) = (yyvsp[-2].vector_val);
    }
#line 1734 "y.tab.c"
    break;

  case 45: /* init_declarator: IDENTIFIER  */
#line 315 "zap.y"
    {
        //printf("begins simple init_declarator\n");
        (yyval.zap_init_declarator_val) = create_zap_init_declaration(
            (yyvsp[0].string_val),
            0,
            0
        );
    }
#line 1747 "y.tab.c"
    break;

  case 46: /* init_declarator: IDENTIFIER ASSIGN expression  */
#line 324 "zap.y"
    {
        //printf("begins assign init_declarator\n");
        (yyval.zap_init_declarator_val) = create_zap_init_declaration(
            (yyvsp[-2].string_val),
            (yyvsp[0].zap_expression_val),
            0
        );
    }
#line 1760 "y.tab.c"
    break;

  case 47: /* init_declarator: IDENTIFIER '[' unsigned_integer ']'  */
#line 333 "zap.y"
    {
        printf("begins array init_declarator\n");
        if((yyvsp[-1].int_val) == 0){
            perror("Array: Wdym size 0?\n I got u, bro! The size is now 10\n");
            (yyvsp[-1].int_val) = 10;
        }

        (yyval.zap_init_declarator_val) = create_zap_init_declaration(
            (yyvsp[-3].string_val),
            NULL,
            (yyvsp[-1].int_val)
        );
    }
#line 1778 "y.tab.c"
    break;

  case 48: /* expression: boolean_constant  */
#line 350 "zap.y"
    {
        bool *aux = malloc(sizeof(bool));
        *aux = (yyvsp[0].bool_val);

        (yyval.zap_expression_val) = create_zap_expression
        (
            Constant,
            NULL,
            create_zap_value(aux, Boolean)
        );
    }
#line 1794 "y.tab.c"
    break;

  case 49: /* expression: unsigned_integer  */
#line 362 "zap.y"
    {
        int *aux = malloc(sizeof(int));
        *aux = (yyvsp[0].int_val);
        (yyval.zap_expression_val) = create_zap_expression
        (
            Constant,
            NULL,
            create_zap_value(aux, Integer)
        );
    }
#line 1809 "y.tab.c"
    break;

  case 50: /* expression: unsigned_rational  */
#line 373 "zap.y"
    {
        float *aux = malloc(sizeof(float));
        *aux = (yyvsp[0].float_val);
        (yyval.zap_expression_val) = create_zap_expression
        (
            Constant,
            NULL,
            create_zap_value(aux, Floating_Point)
        );
    }
#line 1824 "y.tab.c"
    break;

  case 51: /* expression: STRING_LITERAL  */
#line 384 "zap.y"
    {
        char *aux = strdup((yyvsp[0].string_val));

        (yyval.zap_expression_val) = create_zap_expression
        (
            Constant,
            NULL,
            create_zap_value(aux, String)
        );
    }
#line 1839 "y.tab.c"
    break;

  case 52: /* expression: IDENTIFIER  */
#line 395 "zap.y"
    {
        (yyval.zap_expression_val) = create_zap_expression
        (
            Variable,
            NULL,
            (yyvsp[0].string_val)
        );
    }
#line 1852 "y.tab.c"
    break;

  case 55: /* expression: expression PLUS expression  */
#line 406 "zap.y"
    {
        (yyval.zap_expression_val) = create_binary_zap_expression((yyvsp[-2].zap_expression_val), (yyvsp[0].zap_expression_val), addition);
    }
#line 1860 "y.tab.c"
    break;

  case 66: /* expression: NOT expression  */
#line 420 "zap.y"
    {
        create_unary_zap_expression((yyvsp[0].zap_expression_val), negation);
    }
#line 1868 "y.tab.c"
    break;

  case 67: /* expression: '(' expression ')'  */
#line 424 "zap.y"
    {
        printf("expression ()\n");
        (yyval.zap_expression_val) = (yyvsp[-1].zap_expression_val);
    }
#line 1877 "y.tab.c"
    break;

  case 71: /* boolean_constant: TRUE  */
#line 438 "zap.y"
    {
        (yyval.bool_val) = true;
    }
#line 1885 "y.tab.c"
    break;

  case 72: /* boolean_constant: FALSE  */
#line 442 "zap.y"
    {
        (yyval.bool_val) = false;
    }
#line 1893 "y.tab.c"
    break;

  case 73: /* unsigned_integer: DIGIT_SEQUENCE  */
#line 449 "zap.y"
    {
        (yyval.int_val) = atoi((yyvsp[0].string_val));
        free((yyvsp[0].string_val));
    }
#line 1902 "y.tab.c"
    break;

  case 74: /* unsigned_rational: DIGIT_SEQUENCE '.' DIGIT_SEQUENCE  */
#line 457 "zap.y"
    {        
        (yyval.float_val) = a2tof((yyvsp[-2].string_val), (yyvsp[0].string_val));

        free((yyvsp[-2].string_val));
        free((yyvsp[0].string_val));
    }
#line 1913 "y.tab.c"
    break;

  case 75: /* unsigned_rational: '.' DIGIT_SEQUENCE  */
#line 464 "zap.y"
    {
        (yyval.float_val) = a2tof("", (yyvsp[0].string_val));

        free((yyvsp[0].string_val));
    }
#line 1923 "y.tab.c"
    break;


#line 1927 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 471 "zap.y"

int yyerror(const char * s){
    printf("error: %s | line: %d\n",s,yylineno);
}

int main(int argc, char** argv){
    initiate_scope();

    yyin=fopen(argv[1],"r");
    yyparse();
} 
