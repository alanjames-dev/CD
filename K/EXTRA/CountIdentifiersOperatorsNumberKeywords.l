%{
#include<stdio.h>
 int n = 0 ;
 int a = 0;
 int c = 0;
 int d = 0;
 int e = 0;
 int f = 0;
 int g = 0;
 
%}


%%
"while"|"if"|"else" {n++;a++;printf("\n keywords : %s", yytext);}
"int"|"float" {n++;a++;printf("\n keywords : %s", yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {n++;c++;printf("\n identifier : %s", yytext);}
"<="|"=="|"="|"++"|"-"|"*"|"+" {n++;d++;printf("\n operator : %s", yytext);}
[(){}|, ;] {n++;e++;printf("\n separator : %s", yytext);}
[0-9]*"."[0-9]+ {n++;f++;printf("\n float : %s", yytext);}
[0-9]+ {n++;f++;printf("\n integer : %s", yytext);}
. {ECHO;}
\n { printf("\n Total no. of token = %d, Keywords = %d,Identifier = %d, Operator = %d, Separator = %d, Numbers = %d \n", n,a,c,d,e,f);}

%%


int main()

{
printf("Enter the statement: ");
yylex();



}
