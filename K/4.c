#include<stdio.h>
char gram[8][35]={"E->TX","X->+TX","X->e","T->FY","Y->*FY","Y->e","F->(E)","F->i"};
char ter[10]={'+','e','*','(',')','i'};
char nonter[10]={'E','T','X','F','Y'};
char fir[10],fol[10];
int fi=0,fo=0,k;
int ister(char b){
int i;
for(i=0;i<6;i++){
if(b==ter[i]){
return 1;
}}
return 0;
}
int First(char a){
int i,j;
if(ister(a)){
fir[fi]=a;
fi++;
}
else{
for(i=0;i<8;i++){
if(gram[i][0]==a)
if (gram[i][3]=='e'){
fir[fi]='e';
fi++;
}
else
First(gram[i][3]);
}}}
int Follow(char x){
int i,j;
if(x=='E'){
fol[fo]='$';
fo++;
}
for(i=0;i<8;i++){
for(j=3;gram[i][j]!='\0';j++){
if(gram[i][j]==x){
if(gram[i][j+1]=='\0'){
Follow(gram[i][0]);
return;
}
else{
fi=0;
First(gram[i][j+1]);
for(k=0;k<fi;k++){
if(fir[k]!='e'){
fol[fo]=fir[k];
fo++;
}
else{
Follow(gram[i][0]);
return;
}}}}}}}
int main(){
int i,j;
char val;
printf("Grammar \n");
for(i=0;i<8;i++){
for(j=0;gram[i][j]!='\0';j++){
printf(" %c",gram[i][j]);
}
printf("\n");
}
printf("\n\nFirst: \n");
for(i=0;i<5;i++){
printf("\nFIRST (%c) : {",nonter[i]);
First(nonter[i]);
for(j=0;j<fi;j++)
printf(" %c,",fir[j]);
printf("\b}");
fi=0;
}
printf("\n");
printf("\n\nFollow: \n");
for(i=0;i<5;i++){
printf("\nFOLLOW (%c) : {",nonter[i]);
Follow(nonter[i]);
for(j=0;j<fo;j++)
printf(" %c,",fol[j]);
printf("\b}");
fo=0;
}
printf("\n");
return 0;
}
