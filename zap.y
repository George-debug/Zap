%{
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;

%}
%token IDENTIFIER TYPE RETURN ASSIGN CONSTANT IF ELSE WHILE DO UNTIL VOID DIGIT_SEQUENCE LESS LESS_EQUAL GREATER GREATER_EQUAL EQUAL NOT_EQUAL AND OR NOT PLUS MINUS MOD
%right NOT
%left STAR DIV MOD
%left PLUS MINUS 
%left LESS LESS_EQUAL GREATER GREATER_EQUAL
%left EQUAL NOT_EQUAL
%left AND
%left OR
%right ASSIGN
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
    : IDENTIFIER '(' expression ')' ';'

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
    ;

expression
    : integer
    | rational
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
    ;

identifier_list
    : IDENTIFIER
    | identifier_list ',' IDENTIFIER
    ;

integer
    : unsigned_integer
    | sign unsigned_integer
    ;

rational
    : unsigned_rational
    | sign unsigned_rational
    ;

sign
    : PLUS
    | MINUS
    ;

unsigned_integer
    : DIGIT_SEQUENCE
    ;

unsigned_rational
    : DIGIT_SEQUENCE '.' DIGIT_SEQUENCE
    | '.' DIGIT_SEQUENCE
    ;

%%
int yyerror(char * s){
    printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
    yyin=fopen(argv[1],"r");
    yyparse();
} 