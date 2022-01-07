%{
#include <stdio.h>
#include <string.h>
#include "umbrella.h"

extern FILE* yyin;
extern char* yytext;
extern int yylineno;

struct Vector *variable_table_list, *global_scope;

%}
%union{
    float float_val;
    int int_val;
    char *string_val;
    struct Zap_Type_Value *zap_val;
    struct Zap_Expression *zap_expression_val;
    struct Vector *vector_val;
    struct Zap_Init_Declaration *init_declarator_val;
}

%token RETURN ASSIGN CONSTANT IF ELSE WHILE DO UNTIL VOID LESS LESS_EQUAL GREATER GREATER_EQUAL EQUAL NOT_EQUAL AND OR NOT PLUS MINUS MOD
%token <string_val> DIGIT_SEQUENCE TYPE IDENTIFIER
%type <float_val> unsigned_rational
%type <int_val> unsigned_integer
%type <zap_expression_val> expression
%type <vector_val> init_declarator_list
%type <init_declarator_val> init_declarator

%right NOT
%left STAR DIV MOD
%left PLUS MINUS 
%left LESS LESS_EQUAL GREATER GREATER_EQUAL
%left EQUAL NOT_EQUAL
%left AND
%left OR
%right ASSIGN
%nonassoc UMINUS
%left ','
%start progr
%%
progr
    : translation_unit {printf("program corect sintactic\n");}
    | {printf("De unde program?\n");}
    ;

translation_unit
    : statement_unit
    | translation_unit statement_unit
    ;

statement_unit
    : block_item
    | function_declaration
    ;

compound_statement
    : '{' block_item_list '}'
    | '{' '}'
    ;

block_item_list
    : block_item
    | block_item_list block_item
    ;

block_item
    : declaration
    | IDENTIFIER ASSIGN expression ';'
    | iteration_statement
    | selectionStatement
    | return_statement
    | function_call
    | ';'
    ;

iteration_statement
    : WHILE '(' expression ')' compound_statement
    | DO compound_statement WHILE '(' expression ')' ';'
    | DO compound_statement UNTIL '(' expression ')' ';'
    ;

selectionStatement
    : IF '(' expression ')' compound_statement
    | IF '(' expression ')' compound_statement ELSE compound_statement
    ;

return_statement
    : RETURN expression ';'
    | RETURN ';'
    ;

function_declaration
    : TYPE IDENTIFIER '(' identifier_list ')' compound_statement
    | TYPE IDENTIFIER '(' ')' compound_statement
    | VOID IDENTIFIER '(' identifier_list ')' compound_statement
    | VOID IDENTIFIER '(' ')' compound_statement
    ;

function_call
    : IDENTIFIER '(' function_argument_list ')' ';'
    ;

function_argument_list
    : /* empty */
    | function_argument_list function_argument
    ;

function_argument
    : TYPE IDENTIFIER
    | CONSTANT TYPE IDENTIFIER
    ;

declaration
    :   TYPE init_declarator_list ';'
    |   CONSTANT TYPE init_declarator ';'
    ;

init_declarator_list
    : init_declarator
    | init_declarator_list ',' init_declarator
    ;

init_declarator
    : IDENTIFIER
    | IDENTIFIER ASSIGN expression
    | IDENTIFIER '[' expression ']'
    {
    }
    ;

expression
    : unsigned_integer
    {
        $$ = create_zap_expression
        (
            create_zap_value(NULL, Integer),
            Constant,
            NULL,
            &$1
        );
    }
    | unsigned_rational
    {
        $$ = create_zap_expression
        (
            create_zap_value(NULL, Float),
            Constant,
            NULL,
            &$1
        );
    }
    | function_call
    | IDENTIFIER
    | IDENTIFIER '(' identifier_list ')'
    | expression STAR expression
    | expression DIV expression
    | expression PLUS expression
    | expression MINUS expression
    | expression LESS expression
    | expression LESS_EQUAL expression
    | expression GREATER expression
    | expression GREATER_EQUAL expression
    | expression EQUAL expression
    | expression NOT_EQUAL expression
    | expression AND expression
    | expression OR expression
    | NOT expression
    | '(' expression ')'
    {
        $$ = $2;
    }
    ;

identifier_list
    : IDENTIFIER
    | identifier_list ',' IDENTIFIER
    ;

unsigned_integer
    : DIGIT_SEQUENCE
    {
        $$ = atoi($1);
        free($1);
    }
    ;

unsigned_rational
    : DIGIT_SEQUENCE '.' DIGIT_SEQUENCE
    {        
        $$ = a2tof($1, $3);

        free($1);
        free($3);
    }
    | '.' DIGIT_SEQUENCE
    {
        $$ = a2tof("", $2);

        free($2);
    }
    ;

%%
int yyerror(const char * s){
    printf("error: %s | line: %d\n",s,yylineno);
}

int main(int argc, char** argv){
    variable_table_list = create_vector(sizeof(struct Vector), 10);
    global_scope = create_vector(sizeof(struct Zap_Variable),10);
    add_to_vector(variable_table_list, global_scope);

    yyin=fopen(argv[1],"r");
    yyparse();
} 