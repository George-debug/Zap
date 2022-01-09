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
    struct Zap_Init_Declaration *zap_init_declarator_val;
    enum Zap_Variable_Type zap_variable_type_val;
    struct Zap_Declaration* zap_declaration_val;
    struct Zap_Assignation* zap_assignation_val;
    struct Zap_Block_Item* zap_block_item_val;
}

%token RETURN ASSIGN CONSTANT IF ELSE WHILE DO UNTIL VOID LESS LESS_EQUAL GREATER GREATER_EQUAL EQUAL NOT_EQUAL AND OR NOT PLUS MINUS MOD
%token <string_val> DIGIT_SEQUENCE IDENTIFIER
%token <zap_variable_type_val> TYPE
%type <float_val> unsigned_rational
%type <int_val> unsigned_integer
%type <zap_expression_val> expression
%type <vector_val> init_declarator_list block_item_list compound_statement
%type <zap_declaration_val> declaration
%type <zap_init_declarator_val> init_declarator
%type <zap_assignation_val> assignation
%type <zap_block_item_val> block_item

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
    : translation_unit
    {
        printf("program corect sintactic\n");
    }
    | /* empty */
    {
        printf("De unde program?\n");
    }
    ;

translation_unit
    : statement_unit
    | translation_unit statement_unit
    ;

statement_unit
    : block_item
    {
        struct Zap_Signal* sig = run_zap_block_item($1);

        switch (sig->sig_type)
        {
        case Continue:
            perror("You can't have \"continue\" outside loops\n Why would that be helpful? Meh... I'll just ignore it for now!\n");
            break;

        case Return:
            printf("Program returned ");

            if(sig->carry == NULL)
                printf("without any value\n");
            else
                // PRINT THE VALUE
                printf("0\n");
            break;

        case Break:
            perror("Break doesn't work outside loops.\n Did you mean \"return\"?")
            break;

        case Exit:
            printf("Program exit ");

            if(sig->carry == NULL)
                printf("without any value\n");
            else
                // PRINT THE VALUE
                printf("0\n");
            break;
        }
    }
    | function_declaration
    ;

compound_statement
    : '{' block_item_list '}'
    {
        $$ = $1;
    }
    ;

block_item_list
    : /* empty */
    {
        $$ = create_vector(sizeof(struct Zap_Block_Item), 10);
    }
    | block_item_list block_item
    {
        add_to_vector($1, $2);
        $$ = $1;
    }
    ;

block_item
    : declaration
    {
        $$ = create_zap_block_item($1, Declaration);
    }
    | assignation
    {
        $$ = create_zap_block_item($1, Assignation);
    }
    | iteration_statement
    | selection_statement
    | return_statement
    | function_call
    | ';'
    ;

assignation
    : IDENTIFIER ASSIGN expression ';'
    {
        $$ = create_zap_assignation($1, $3);
    }
    ;

iteration_statement
    : WHILE '(' expression ')' compound_statement
    | DO compound_statement WHILE '(' expression ')' ';'
    | DO compound_statement UNTIL '(' expression ')' ';'
    ;

selection_statement
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
    {
        $$ = create_zap_declaration($2, $1, false);
    }
    |   CONSTANT TYPE init_declarator_list ';'
    {
        $$ = create_zap_declaration($3, $2, true);
    }
    ;

init_declarator_list
    : init_declarator
    {
        $$ = create_vector(sizeof(struct Zap_Init_Declaration), 10);
        add_to_vector($$, $1);
    }
    | init_declarator_list ',' init_declarator
    {
        add_to_vector($1, $3);
        $$ = $1;
    }
    ;

init_declarator
    : IDENTIFIER
    {
        $$ = create_zap_init_declaration(
            $1,
            0,
            0
        );
    }
    | IDENTIFIER ASSIGN expression
    {
        $$ = create_zap_init_declaration(
            $1,
            $3,
            0
        );
    }
    | IDENTIFIER '[' unsigned_integer ']'
    {
        if($3 == 0){
            perror("Array: Wdym size 0?\n I got u, bro! The size is now 10\n");
            $3 = 10;
        }

        $$ = create_zap_init_declaration(
            $1,
            NULL,
            $3
        );
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
            create_zap_value(NULL, Floating_Point),
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
    | expression MOD expression
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