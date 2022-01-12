%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "umbrella.h"

extern FILE* yyin;
extern char* yytext;
extern int yylineno;

//struct Vector *variable_table_list, *global_scope;

%}
%union{
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
    struct Zap_Function_Declaration *zap_function_declaration_val;
}

%token RETURN ASSIGN CONSTANT IF ELSE WHILE DO UNTIL VOID LESS LESS_EQUAL GREATER GREATER_EQUAL EQUAL NOT_EQUAL AND OR NOT PLUS MINUS MOD TRUE FALSE BREAK EXIT CONTINUE
%token <string_val> STRING_LITERAL DIGIT_SEQUENCE IDENTIFIER
%token <zap_variable_type_val> TYPE

%type <bool_val> boolean_constant
%type <float_val> unsigned_rational
%type <int_val> unsigned_integer
%type <zap_expression_val> expression
%type <vector_val> init_declarator_list block_item_list compound_statement function_argument_list function_argument_list_or_empty function_parameter_list function_parameter_list_or_empty
%type <zap_declaration_val> declaration
%type <zap_init_declarator_val> init_declarator function_parameter
%type <zap_assignation_val> assignation
%type <zap_block_item_val> block_item
%type <zap_function_call_val> function_call
%type <zap_selection_statement_val> selection_statement
%type <zap_iteration_statement_val> iteration_statement
%type <zap_signal_val> signal_statement return_statement exit_statement
%type <zap_function_declaration_val> function_declaration

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
        //printf("I'll run\n");
        struct Zap_Signal* sig = run_zap_block_item($1);

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
    | function_declaration
    ;

compound_statement
    : '{' block_item_list '}'
    {
        $$ = $2;
    }
    ;

block_item_list
    : /* empty */
    {
        $$ = create_vector(sizeof(struct Zap_Block_Item), 10);
    }
    | block_item_list block_item
    {
        if($2 != NULL)
            add_to_vector($1, $2);
        $$ = $1;
    }
    ;

block_item
    : declaration
    {
        $$ = create_zap_block_item($1, Declaration_Type);
    }
    | assignation
    {
        $$ = create_zap_block_item($1, Assignation_Type);
    }
    | iteration_statement
    {
        $$ = create_zap_block_item($1, Iteration_Statement_Type);
    }
    | selection_statement
    {
        $$ = create_zap_block_item($1, Selection_Statement_Type);
    }
    | signal_statement
    {
        $$ = create_zap_block_item($1, Signal_Statement_Type);
    }
    | function_call ';'
    {
        $$ = create_zap_block_item($1, Function_Call_Type);
    }
    | ';'
    {
        $$ = NULL;
    }
    ;

assignation
    : IDENTIFIER ASSIGN expression ';'
    {
        $$ = create_zap_assignation($1, $3);
    }
    ;

iteration_statement
    : WHILE '(' expression ')' compound_statement
    {
        $$ = create_zap_iteration_statement(While_Type, $3, $5);
    }
    | DO compound_statement WHILE '(' expression ')' ';'
    {
        $$ = create_zap_iteration_statement(Do_While_Type, $5, $2);
    }
    | DO compound_statement UNTIL '(' expression ')' ';'
    {
        $$ = create_zap_iteration_statement(Do_Until_Type, $5, $2);
    }
    ;

selection_statement
    : IF '(' expression ')' compound_statement
    {
        $$ = create_zap_selection_statement($3, $5, NULL);
    }
    | IF '(' expression ')' compound_statement ELSE compound_statement
    {
        $$ = create_zap_selection_statement($3, $5, $7);
    }
    ;

signal_statement
    : return_statement
    {
        $$ = $1;
    }
    | BREAK ';'
    {
        $$ = create_zap_signal(Break_Signal, NULL);
    }
    | CONTINUE ';'
    {
        $$ = create_zap_signal(Continue_Signal, NULL);
    }
    | exit_statement
    {
        $$ = $1;
    }
    ;

exit_statement
    : EXIT expression ';'
    {
        $$ = create_zap_signal(Exit_Signal, $2);
    }
    | EXIT ';'
    {
        $$ = create_zap_signal(Exit_Signal, NULL);
    }
    ;

return_statement
    : RETURN expression ';'
    {
        $$ = create_zap_signal(Return_Signal, $2);
    }
    | RETURN ';'
    {
        $$ = create_zap_signal(Return_Signal, NULL);
    }
    ;

function_declaration
    : TYPE IDENTIFIER '(' function_parameter_list_or_empty ')' compound_statement
    {
        enum Zap_Variable_Type* var_type = malloc(sizeof(enum Zap_Variable_Type));
        *var_type = $1;

        $$ = create_zap_function_declaration(var_type, $2, $4, $6);
    }
    | VOID IDENTIFIER '(' function_parameter_list_or_empty ')' compound_statement
    {
        $$ = create_zap_function_declaration(NULL, $2, $4, $6);
    }
    ;

function_call
    : IDENTIFIER '('function_argument_list_or_empty ')'
    {
        $$ = create_zap_function_call($1, $3);
    }
    ;


function_parameter_list_or_empty
    : /* empty */
    {
        $$ = create_vector(sizeof(struct Zap_Init_Declaration), 1);
    }
    | function_parameter_list
    {
        $$ = $1;
    }
    ;

function_parameter_list
    : function_parameter
    {
        $$ = create_vector(sizeof(struct Zap_Init_Declaration), 10);
    }
    | function_parameter_list ',' function_parameter
    {
        add_to_vector($1, $3);
        $$ = $1;
    }
    ;

function_parameter
    : TYPE IDENTIFIER
    {
        $$ = create_zap_init_declaration($2, NULL, 0);
    }
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
        //printf("begins init_declarator_list\n");
        $$ = create_vector(sizeof(struct Zap_Init_Declaration), 10);
        add_to_vector($$, $1);
    }
    | init_declarator_list ',' init_declarator
    {
        //printf("continue init_declarator_list\n");
        add_to_vector($1, $3);
        $$ = $1;
    }
    ;

init_declarator
    : IDENTIFIER
    {
        //printf("begins simple init_declarator\n");
        $$ = create_zap_init_declaration(
            $1,
            0,
            0
        );
    }
    | IDENTIFIER ASSIGN expression
    {
        //printf("begins assign init_declarator\n");
        $$ = create_zap_init_declaration(
            $1,
            $3,
            0
        );
    }
    | IDENTIFIER '[' unsigned_integer ']'
    {
        printf("begins array init_declarator\n");
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
    : boolean_constant
    {
        bool *aux = malloc(sizeof(bool));
        *aux = $1;

        $$ = create_zap_expression
        (
            Constant,
            NULL,
            create_zap_value(aux, Boolean)
        );
    }
    | unsigned_integer
    {
        int *aux = malloc(sizeof(int));
        *aux = $1;
        $$ = create_zap_expression
        (
            Constant,
            NULL,
            create_zap_value(aux, Integer)
        );
    }
    | unsigned_rational
    {
        float *aux = malloc(sizeof(float));
        *aux = $1;
        $$ = create_zap_expression
        (
            Constant,
            NULL,
            create_zap_value(aux, Floating_Point)
        );
    }
    | STRING_LITERAL
    {
        char *aux = strdup($1);

        $$ = create_zap_expression
        (
            Constant,
            NULL,
            create_zap_value(aux, String)
        );
    }
    | IDENTIFIER
    {
        $$ = create_zap_expression
        (
            Variable,
            NULL,
            $1
        );
    }
    | expression STAR expression
    {
        $$ = create_binary_zap_expression($1, $3, multiplication);
    }
    | expression DIV expression
    {
        $$ = create_binary_zap_expression($1, $3, division);
    }
    | expression PLUS expression
    {
        $$ = create_binary_zap_expression($1, $3, addition);
    }
    | expression MINUS expression
    {
        $$ = create_binary_zap_expression($1, $3, reduction);
    }
    | expression MOD expression
    {
        $$ = create_binary_zap_expression($1, $3, modular);
    }
    | expression LESS expression
    {
        $$ = create_binary_zap_expression($1, $3, less);
    }
    | expression LESS_EQUAL expression
    {
        $$ = create_binary_zap_expression($1, $3, less_equal);
    }
    | expression GREATER expression
    {
        $$ = create_binary_zap_expression($1, $3, greater);
    }
    | expression GREATER_EQUAL expression
    {
        $$ = create_binary_zap_expression($1, $3, greater_equal);
    }
    | expression EQUAL expression
    {
        $$ = create_binary_zap_expression($1, $3, equal);
    }
    | expression NOT_EQUAL expression
    {
        $$ = create_binary_zap_expression($1, $3, not_equal);
    }
    | expression AND expression
    {
        $$ = create_binary_zap_expression($1, $3, conjunction);
    }
    | expression OR expression
    {
        $$ = create_binary_zap_expression($1, $3, disjunction);
    }
    | NOT expression
    {
        $$ = create_unary_zap_expression($2, negation);
    }
    | '(' expression ')'
    {
        printf("expression ()\n");
        $$ = $2;
    }
    | MINUS expression %prec UMINUS
    {
        $$ = create_unary_zap_expression($2, uminus_operator);
    }
    ;

function_argument_list_or_empty
    : /* empty */
    {
        $$ = create_vector(sizeof(struct Zap_Expression), 1);
    }
    | function_argument_list
    {
        $$ = $1;
    }
    ;

function_argument_list
    : expression
    {
        $$ = create_vector(sizeof(struct Zap_Expression), 10);

        add_to_vector($$, $1);
    }
    | function_argument_list ',' expression
    {
        add_to_vector($1, $3);
        $$ = $1;
    }
    ;

boolean_constant
    : TRUE
    {
        $$ = true;
    }
    | FALSE
    {
        $$ = false;
    }
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
    initiate_scope();

    yyin=fopen(argv[1],"r");
    yyparse();
} 