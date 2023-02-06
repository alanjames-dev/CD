
%{
#include<stdio.h>
 int n = 0 ;
%}


%%
"while"|"if"|"else" {n++;printf("\n keywords : %s", yytext);}
"int"|"float" {n++;printf("\n keywords : %s", yytext);}l
[a-zA-Z_][a-zA-Z0-9_]* {n++;printf("\n identifier : %s", yytext);}
"<="|"=="|"="|"++"|"-"|"*"|"+" {n++;printf("\n operator : %s", yytext);}
[(){}|, ;] {n++;printf("\n separator : %s", yytext);}
[0-9]*"."[0-9]+ {n++;printf("\n float : %s", yytext);}
[0-9]+ {n++;printf("\n integer : %s", yytext);}
. {ECHO;}
\n { printf("\n Total no. of token = %d\n", n);}
%%


int main()

{
printf("Enter the statement: ");
yylex();



}
