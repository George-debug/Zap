%{
#include <stdio.h>
#include <string.h>

#include "y.tab.h"
%}
%option noyywrap
%%
"int"|"float"|"char"|"string"|"bool"   {
        yylval.string_val=strdup(yytext);
        return TYPE;
    }

"return"    {return RETURN;}
":="    {return ASSIGN;}
"constant"  {return CONSTANT;}
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

[_a-zA-Z][_a-zA-Z0-9]*  {
        return IDENTIFIER;
        yylval.string_val=strdup(yytext);
    }
[0-9]+ {
        yylval.string_val=strdup(yytext);
        return DIGIT_SEQUENCE;
    }


#~[\r\n]* ;

[ \t]   ;
\n  {yylineno++;}
.   {return yytext[0];}

 
