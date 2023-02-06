#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
//read states
printf("\nEnter the number of states");
int n,i,j;
scanf("%d",&n);
int state[30];
for(i=0;i<n;i++){
printf("\nInput state %d label\t",i+1);
scanf("%d",&state[i]);
}
//alphabets
char alpha[100][100];
printf("\nEnter the transition alphabets\t");
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
printf("\n %d -> %d :",i,j);
scanf("%s",&alpha[i][j]);
}}
//print matrix
printf("\n\nTransition Table");
printf("\n\t");
for(i=0;i<n;i++){
printf("%d\t",i+1);
}
for(i=1;i<=n;i++){
printf("\n%d",i);
for(j=1;j<=n;j++){
printf("\t%c",alpha[i][j]);
}}
printf("\n");
//e- closure
for(i=0;i<n;i++){
printf("\ne-closure of %d = { %d,",i+1,i+1);
for(j=0;j<n;j++){
if(alpha[i+1][j+1]=='e'){
printf("%d,",j+1);
for(int k=0;k<n;k++){
if(alpha[j+1][k+1]=='e')
printf("%d,",k+1);
}}}
printf(" }");
}
printf("\n");
return 0;
}
