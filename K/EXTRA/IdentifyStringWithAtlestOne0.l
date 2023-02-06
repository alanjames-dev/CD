num (0|1)*0(0|1)*
%%
{num} printf("Accepted");
.+ printf("Not accepted");

%%
void main()
{
printf("Enter the string:");
yylex();
}
