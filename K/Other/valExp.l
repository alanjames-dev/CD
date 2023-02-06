%{
#include<stdio.h>
#include<stdlib.h>
int c,d,bo=0,bc=0;
%}

operand [a-zA-Z0-9]+
operator [+-/*]
%%

{operator} d++;

{operand} c++;

"(" {if(bc<=bo)bo++;}

")" {bc++;}

\n {if(bo==bc&&c>d){printf("valid exp\n");}else {printf("invalid exp\n");};exit(0);}
%%
int yywrap(){return 1;}
void main(){
printf("enter expresion: ");
yylex();
}