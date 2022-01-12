%{
#include <stdio.h>
#include <string.h>

#include "umbrella.h"

#include "y.tab.h"
%}
%option noyywrap
%%
"int"|"float"|"char"|"string"|"bool"   {
        
        switch (yytext[0])
        {
        case 'i':
            yylval.zap_variable_type_val = Integer;
            break;

        case 'f':
            yylval.zap_variable_type_val = Floating_Point;
            break;

        case 'c':
            yylval.zap_variable_type_val = Character;
            break;

        case 's':
            yylval.zap_variable_type_val = String;
            break;

        default:
            yylval.zap_variable_type_val = Boolean;
            break;
        }
        return TYPE;
    }

"True"|"true"|"TRUE"    {return TRUE;}
"False"|"false"|"FALSE" {return FALSE;}

"break" {return BREAK;}
"continue" {return CONTINUE;}
"exit" {return EXIT;}

"return"    {return RETURN;}
"="    {return ASSIGN;}
"const"  {return CONSTANT;}
"if"    {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"do" {return DO;}
"until" {return UNTIL;}
"void" {return VOID;}

"<" {return LESS;}
"<="    {return LESS_EQUAL;}
">" {return GREATER;}
">="    {return GREATER_EQUAL;}

"=="    {return EQUAL;}
"!="    {return NOT_EQUAL;}

"&&"    {return AND;}
"||"    {return OR;}
"!" {return NOT;}

"+" {return PLUS;}
"-" {return MINUS;}
"*" {return STAR;}
"/" {return DIV;}
"%" {return MOD;}

\"[^\"\\\r\n]*\" {
        yytext[yyleng - 1] = '\0';
        yylval.string_val=strdup(yytext+1);
        return STRING_LITERAL;
    }

[_a-zA-Z][_a-zA-Z0-9]*  {
        yylval.string_val=strdup(yytext);
        return IDENTIFIER;
    }
[0-9]+ {
        yylval.string_val=strdup(yytext);
        return DIGIT_SEQUENCE;
    }

#[^\r\n]* ; // sau \r?\n

[ \t]   ;
\n  {yylineno++;}
.   {return yytext[0];}

 
