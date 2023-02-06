%{
#include<stdio.h>
int lc=0, sc=0, tc=0, ch=0; /*Global variables*/
%}


%%
\n lc++; 
([ ])+ sc++; 
. ch++;	 //characters counter
%%

int main()
{

	yylex();
	
	printf("\nNo. of lines=%d", lc);
	printf("\nNo. of spaces=%d", sc);
	printf("\nNo. of other characters=%d", ch);
	
}
