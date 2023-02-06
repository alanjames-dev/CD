#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define SIZE 1024
bool duplicateflag=false;
int idCount=0,keywordCount=0,constantCount=0,operatorCount=0,idPointer=0;
char idMap[30][30]={};
char keyword[30][30]={"void","int","if","else","do","while","for"};
bool isDelimiter(char c){
if ( c == '{' || c == '}' ||c == '(' || c == ')'||c == '[' || c == ']'||c == ' ' || c == '+'
|| c == '-' || c == '*' ||c == '/' || c == ',' || c == ';' || c == '>' ||c == '<' || c == '=' || c == '\t')
return true;
return false;
}
bool isOperator(char c){
if (c == '+' || c == '-' || c == '*' || c == '/' || c == '>' || c == '<' ||c == '=')
return true;
return false;
}
bool isIdentifier(char *str){
if(isdigit(str[0]) || isDelimiter(str[0])) return false;
// reaching here would mean this is an identifier now to check for duplicates
int i = 0;
while(i <= idPointer){
if(strcmp(str, idMap[i]) == 0 ){
printf("Duplicate identifier found => %s\n", str);
duplicateflag = true;
return true;
}
i++;
}
strcpy(idMap[idPointer], str);
idPointer++;
return true;
}
bool isConstant(char *str){
for(int i = 0 ; i < strlen(str); i++)
if(!isdigit(str[i]))
return false;
return true;
}
bool isKeyword(char *str){
for(int i = 0 ; i < 7 ; i++){
if(strcmp(str, keyword[i]) == 0){
return true;
}}
return false;
}
void detect(char * line){
int left = 0, right = 0;
while (right < strlen(line) && left <= right) {
// find delimiter
if(isDelimiter(line[right]) == false) {
right++;
continue;
}// if pgm reaches here, we found the delimiter at right
if(left == right) {
// no substring to the left of delimiter that we haven’t parsed
if(isOperator(line[right])){
operatorCount++;
}
right++;
left = right;
}
else{ // left != right, substring is between left and right substring extraction
char str[SIZE];
int tempLeft = left;
int i;
for(i = 0; i < right - left ; i++ ){
if(str[i] == ' ') continue;
str[i] = line[tempLeft + i];
}
str[i] = '\0';
// first check if keywords, then check for constants, then check for identifiers. if all fails, print error
if(isKeyword(str)){
keywordCount++;
}
else if(isConstant(str)){
constantCount++;
}
else if( isIdentifier(str)){
if(!duplicateflag)
idCount ++;
printf("Found identifier %s\n", str);
}
else{
printf("SYNTAX ERROR!");
return;
}
right ++;
left = right;
}}}
int main(){
FILE * ip;
FILE * op;
char file_name[SIZE];
printf("Enter file name: ");
scanf("%s", file_name);
ip = fopen(file_name, "r");
op = fopen("out.txt", "w");
char line[SIZE];
while(fgets(line, SIZE, ip) != NULL){
char line1[SIZE];
int i = 0, k = 0;
while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'){
i++;
}
for (int j = i; line[j] != '\0'; j++){
line1[k] = line[j];
k++;
}
line1[k] = '\0';
// is pre-processor statement or 
if( line1[0] == '#' || (line1[0] == '/'&& line1[1] == '/')){
continue;
}
detect(line1);
} printf("OPERATOR:%d\nKEYWORDS:%d\nCONSTANTS:%d\nIDENTIFIERS:%d\n",operatorCount, keywordCount,
constantCount, idCount);
fclose(ip);
fclose(op);
return 0;
}
