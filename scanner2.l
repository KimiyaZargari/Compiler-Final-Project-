%{
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser3.tab.h"
void updateCurrentLexeme(const char* str);
char* myCreateString(const char* str);
char* currentLexeme = NULL;
void delchar(char *x,int a, int b);
char *trimwhitespace(char *str);
void yyerror( char* error);
extern FILE* symTable;
int idNum = 0;
struct MyNode{
     char* data;
     struct MyNode* next;
 };

int exists(char * id, struct MyNode *);
 extern struct MyNode* IDHead;
 extern struct MyNode* IDCurrent;
char* mkStr(char* input)
{
	char* string = (char*) malloc(strlen(input));
	strcpy(string , input);
	return string;
}


%}

myChar	[a-zA-Z]
digit	[0-9]
nz_digit	[1-9]
w_underscore	_({myChar}|{digit})
ws	[ \t\n\r]
operator	[\;\:\,\+\*\(\)\-\<\>\=\/{}]

%%
{ws}+	;
class	{updateCurrentLexeme(yytext);
    printf("here");
	//fprintf(output,"TOKEN_CLASS:\t\t%s\t\t-\n",yytext);
    //printf("class");
    yylval.sVal =  "class";
	return TOKEN_CLASS;
	}
reference	{//updateCurrentLexeme(yytext);
	//fprintf(output,"TOKEN_REFERENCE:\t\t%s\t\t-\n", yytext);
    yylval.sVal = "reference";
	return TOKEN_REFERENCE;
	}
static	{//updateCurrentLexeme(yytext);
	//fprintf(output,"TOKEN_STATIC:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "static";
	return TOKEN_STATIC;
	}
int	{//updateCurrentLexeme(yytext);
	//fprintf(output,"TOKEN_INT_TYPE:\t\t%s\t\t-\n", yytext);
   yylval.sVal =  "int";
	return TOKEN_INT_TYPE;
	}
real	{//updateCurrentLexeme(yytext);
	//fprintf(output,"TOKEN_REAL_TYPE:\t\t%s\t\t-\n", yytext);
     yylval.sVal =  "real";
	return TOKEN_REAL_TYPE;
}
bool	{//updateCurrentLexeme(yytext);
	//fprintf(output,"TOKEN_BOOL_TYPE:\t\t%s\t\t-\n", yytext);
     yylval.sVal= "bool";
	return TOKEN_BOOL_TYPE;
	}
string	{//updateCurrentLexeme(yytext);
	//fprintf(output,"TOKEN_STRING_TYPE:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "string";
	return TOKEN_STRING_TYPE;
	}
void	{//updateCurrentLexeme(yytext);
	//fprintf(output,"TOKEN_VOID:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "void";
	return TOKEN_VOID;
}
true	{//updateCurrentLexeme(yytext);
	//fprintf(output,"TOKEN_TRUE:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "true";
	return TOKEN_TRUE;
}
false	{//updateCurrentLexeme(yytext);
	//fprintf(output,"TOKEN_FALSE:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "false";
	return TOKEN_FALSE;
}
print	{//updateCurrentLexeme(yytext);
	//fprintf(output,"TOKEN_PRINT:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "print";
	return TOKEN_PRINT;
}
return	{//updateCurrentLexeme(yytext);
	//fprintf(output,"TOKEN_RETURN:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "return";
	return TOKEN_RETURN;
}
break	{//updateCurrentLexeme(yytext);
	//fprintf(output,"TOKEN_BREAK:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "break";
	return TOKEN_BREAK;
}
continue	{//updateCurrentLexeme(yytext);
	//fprintf(output,"TOKEN_CONTINUE:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "continue";
	return TOKEN_CONTINUE;
}
if	{//updateCurrentLexeme(yytext);
	//fprintf(output,"TOKEN_IF:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "if";
	return TOKEN_IF;
}
else	{//updateCurrentLexeme(yytext);
	//fprintf(output,"TOKEN_ELSE:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "else";
	return TOKEN_ELSE;
}
elseif	{//updateCurrentLexeme(yytext);
	//fprintf(output,"TOKEN_ELSEIF:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "elseif";
	return TOKEN_ELSEIF;
}
while   {//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_WHILE:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "while";
	return TOKEN_WHILE;
}
for {//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_FOR:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "for";
	return TOKEN_FOR;
}
to	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_TO:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "to";
	return TOKEN_TO;
}
in	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_IN:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "in";
	return TOKEN_IN;
}
steps	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_STEPS:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "steps";
	return TOKEN_STEPS;
}
"&"	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_BITWISE_AND:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "&";
	return TOKEN_BITWISE_AND;
}
"&&"	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_AND:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "&&";
	return TOKEN_AND;
}
"|"	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_BITWISE_OR:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "|";
	return TOKEN_BITWISE_OR;
}
"||"	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_OR:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "||";
	return TOKEN_OR;
}
"!"	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_NOT:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "!";
	return TOKEN_NOT;
}
"~"	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_BITWISE_NOT:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "~";
	return TOKEN_BITWISE_NOT;
}
">>"	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_SHIFT_RIGHT:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  ">>";
	return TOKEN_SHIFT_RIGHT;
}
"<<"	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_SHIFT_LEFT:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "<<";
	return TOKEN_SHIFT_LEFT;
}
"="	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_ASSIGNMENT:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "=";
	return TOKEN_ASSIGNMENT;
}
"+"	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_ADDITION:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "+";
	return TOKEN_ADDITION;
}
"-"	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_SUBTRACTION:\t\t%s\t\t-\n", yytext);
    yylval.sVal=  "-";
	return TOKEN_SUBTRACTION;
}
"*"	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_MULTIPLICATION:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "*";
	return TOKEN_MULTIPLICATION;
}
"/"	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_DIVISION:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "/";
	return TOKEN_DIVISION;
}
"%"	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_MODULO:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "%";
	return TOKEN_MODULO;
}
"^"	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_POWER:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "^";
	return TOKEN_POWER;
}
">"	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_GT:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  ">";
	return TOKEN_GT;
}
">="	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_GE:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  ">=";
	return TOKEN_GE;
}	
"<"	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_LT:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "<";
	return TOKEN_LT;
}
"<="	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_LE:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "<=";
	return TOKEN_LE;
}
"=="	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_EQ:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "==";
	return TOKEN_EQ;
}
"!="	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_NE:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "!=";
	return TOKEN_NE;
}
"{"	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_LCB:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "{";
	return TOKEN_LCB;
}
"}"	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_RCB:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "}";
	return TOKEN_RCB;
}
"("	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_LP:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  "(";
	return TOKEN_LP;
}
")"	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_RP:\t\t%s\t\t-\n", yytext);
	return TOKEN_RP;
}
[.]	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_DOT:\t\t%s\t\t-\n", yytext);
     
	return TOKEN_DOT;
}
[;]	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_SEMICOLON:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  ";";
	return TOKEN_SEMICOLON;
}
[,]	{//updateCurrentLexeme(yytext);//fprintf(output,"TOKEN_COMMA:\t\t%s\t\t-\n", yytext);
     yylval.sVal=  ",";
	return TOKEN_COMMA;
}
({myChar}(({myChar}|{digit})({myChar}|{digit}))*({w_underscore})*(({myChar}|{digit})({myChar}|{digit}))*)|(({w_underscore})+(((({myChar}|{digit})({myChar}|{digit}))*({myChar}|{digit}))|(_(({myChar}|{digit})({myChar}|{digit}))*)))|((({myChar}|{digit})({myChar}|{digit}))*({w_underscore})*_(({myChar}|{digit})({myChar}|{digit}))*)	{
    updateCurrentLexeme(yytext);
	/*int res = exists(yytext, IDHead);
    if(res ==0){
        IDCurrent->data = (char*)malloc(sizeof(yytext));
        for (int i = 0; i < strlen(yytext); i++){
               IDCurrent->data[i] = yytext[i];
        }
        IDCurrent->next = (struct MyNode*)malloc(sizeof(struct MyNode));
        IDCurrent = IDCurrent->next;
        IDCurrent->data = NULL;
        IDCurrent->next = NULL;
		idNum++;
		res = idNum;
        fprintf(symTable, "%s\t\t%d\n",yytext, res - 1);
        
    }
		//fprintf(output,"TOKEN_ID:\t\t%s\t\t%d\n", yytext, res);
        yylval.iVal = res - 1;*/
   
    yylval.sVal = mkStr(yytext);
		return TOKEN_ID;
		

	}
(0b(1(0|1)*|0))|(({nz_digit}({digit})*)|0)|(0x(({nz_digit}|[A-F])({digit}|[A-F])*|0))	{updateCurrentLexeme(yytext);
	/*int res = exists(yytext, numHead);
	if(res == 0){
		num++;
		numCurrent->data = (char*)malloc(sizeof(yytext));
		for(int i = 0; i < strlen(yytext); i++){
			numCurrent->data[i] = yytext[i];
		}
		numCurrent->next = (struct Node*)malloc(sizeof(struct Node));
		numCurrent = numCurrent->next;
		numCurrent->data = NULL;
		numCurrent->next = NULL;
		fprintf(output,"TOKEN_INTEGER:\t\t%s\t\t%d\n", yytext, num);
	} else
	fprintf(output,"TOKEN_INTEGER:\t\t%s\t\t%d\n", yytext, res);*/
    //
    //
    char* temp = malloc(sizeof(yytext - 2));
	if(yytext[1] == 'b'){
		char str[strlen(yytext - 2)];
        
		for(int i = 0; i <strlen(yytext - 2); i++)
		str[i] = yytext[i + 2];
		//fprintf(output,"TOKEN_INTEGER:\t\t%s\t\t%ld\n", yytext, strtol(str, NULL, 2));
      int a = (int)strtol(str, NULL, 2);
        snprintf(temp, sizeof(temp), "%d", a);
    yylval.sVal = mkStr(temp);
	}
	else if(yytext[1] == 'x'){
		char str[strlen(yytext - 2)];
		for(int i = 0; i <strlen(yytext - 2); i++)
		str[i] = yytext[i + 2];
		//fprintf(output,"TOKEN_INTEGER:\t\t%s\t\t%ld\n", yytext, strtol(str, NULL, 16));
        int a = strtol(str, NULL, 16);
        snprintf(temp, sizeof(temp), "%d", a);
        yylval.sVal = mkStr(temp);
    
    }else {
	//fprintf(output,"TOKEN_INTEGER:\t\t%s\t\t%s\n", yytext, yytext);
        yylval.sVal = mkStr(yytext);
    
    }

		return TOKEN_INTEGER;
}	
((({nz_digit}({digit})*)|0)\.({digit}*{nz_digit}|0))	{updateCurrentLexeme(yytext);
	/*int res = exists(yytext, numHead);
	if(res == 0){
		num++;
		numCurrent->data = (char*)malloc(sizeof(yytext));
		for(int i = 0; i < strlen(yytext); i++){
			numCurrent->data[i] = yytext[i];
		}
		numCurrent->next = (struct Node*)malloc(sizeof(struct Node));
		numCurrent = numCurrent->next;
		numCurrent->data = NULL;
		numCurrent->next = NULL;
		fprintf(output,"TOKEN_REAL:\t%s\t%d\n", yytext, num);
	}else*/
	//fprintf(output,"TOKEN_REAL:\t\t%s\t\t%s\n", yytext, yytext);
     yylval.sVal = mkStr(yytext);
    
		return TOKEN_REAL;
}
\"[^\"]*\"({ws}+?\+{ws}+?\"[^\"]*\")*	{updateCurrentLexeme(yytext);
	 char str[strlen(yytext)];
	 	strcpy(str, yytext);
for(int i = 1; i < strlen(yytext) - 1; i++){
	 int n = 0;
	 int pos = 0;

	if(yytext[i] == '\"'){
		pos = i;
		i++;
		n++;
		while(yytext[i] != '\"'){		
			n++; 
			i++;
		}
		delchar(yytext, n + 1, pos);
	}
		 
}
//fprintf(output, "TOKEN_STRING:\t\t%s\t\t%s\n",str, yytext);
    yylval.sVal = mkStr(yytext);
    return TOKEN_STRING;
}
(\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/)|(\/\/.*)	{
	//fprintf(output,"comment:\n%s\n", yytext);
		//return comment;
}
[^ \t\n\r\;\:\,\+\*\(\)\-\<\>\=\/{}^&%|]+	{
	//fprintf(output, "ERROR:\t\t%s\n", yytext);
    char e[14] = "syntax error: ";
    char error[strlen(yytext) + 14];
    for(int i = 0; i < 14; i++){
        error[i] = e[i];
    }
    for(int i = 14; i < strlen(error); i++){
        error[i] = yytext[i];
    }
    	yyerror(error);
}
%%


int yywrap(){
	return 1;
}
/*
int main(){

	yyin = fopen("input.txt", "r");
	output = fopen("output_lex.txt", "w");
	symTable = fopen("symbolTable.txt", "w");
	IDHead = (struct Node*)malloc(sizeof(struct Node)); 
	IDHead->data = NULL; 
	IDHead->next = NULL;
	IDCurrent = IDHead;
	while(yylex());
    printf("while ended");
fclose(yyin);
fclose(output);
printf("closed");
fclose(symTable);


	return 0;

}*/
void delchar(char *x,int a, int b)
{
	int len = strlen(x);

  if ((a+b-1) <= len)
  {
	  for (int i = 0; i < len  - b; i++)
    {
       x[b +i] = x[b +i +a];
    }
    }
}
bool equals(char* s1, char* s2){
	if(strlen(s1)== strlen(s2))
		for(int i = 0; i < strlen(s1); i++ ){
			if(s1[i] != s2[i])
			return false;
		}
		else
		return	false;
		return true;

}
int exists(char myStr[], struct MyNode * h){
    int cnt = 0;
    struct MyNode *n = h;
    while (n != NULL && n->data!=NULL){
        cnt ++;
        if(equals(myStr, n->data)){
            return cnt;
        }
        n = n->next;
    }
    return 0;
}
void updateCurrentLexeme(const char* str){
    if(currentLexeme != NULL){
        free(currentLexeme);
        currentLexeme = NULL;
    }
    currentLexeme = myCreateString(str);
}

char* myCreateString(const char* str){
    int pointerSize = strlen(str) + 1;
    char* string = (char*) malloc(sizeof(char) * pointerSize);
    
    strcpy(string, str);
    string[pointerSize - 1] = 0;
    
    return string;
}

