%{
#include "all.h"
#include<stdio.h>
#include <stdbool.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
extern char* currentLexeme;
extern FILE* yyin;
struct Stack* tblptrStack;
extern char* intToString(int n);
FILE* symTable;
extern char* tempString;
void loadTmpVal(char * theTmp);
void saveTmpVal(char* theTmp);
void topPlsLoclNum(int quad);
extern char* mkStr(char* input);
char* currentLable;
char* assignBool(Node * trueList , Node * falseList , char* var , bool isVar, bool mkItEval);
char * lookup(char * name , struct SymbolTable* symbolTable , int * size ,int * scopeID);
char* functionCall(char* id , char * explist);
struct Eval* strToEval(char* input);
char * newQuad();
char * na;
char * newTemp();
char * newVTemp();
char * newPTemp();
char * newITemp();
char * funcName;
int ifNum = 0;
int forNum = 0;
int whileNum = 0;
char * afterIF;
char* createLable();
void defaultGotoGen();
struct Eval* idToEval(char * idName);
struct SymbolTable* secondArg(struct SymbolTable* a,struct SymbolTable* b );
void mkSymTbl(char * name);
int address[30];
char* funcID[30];
int sizeAdd[30];
int scpAdd[30];
int j = 0;
char num[5];
char snum[5];
int returnQuads[30];
int returnQuad;
int lastOfReturnQuad=0;
int tt=0;
int v=0;
int I=0;
bool inBlock = false;
int currentType;
char* returnType;
bool errorFlag=false;
Node* break_list = NULL;
Node* cont_list = NULL;
int quadTmp;
struct SymbolTable* mainSymTbl;
bool func_reached=false;
int main_quad;
struct MyNode{
     char* data;
     struct MyNode* next;
};
char temp[50];
struct MyNode* IDHead = NULL;
struct Eval * mainFunc = NULL;
struct MyNode* IDCurrent = NULL;
FILE* output;
int yylex();
void print(const char* string);
void yyerror(char* error);
%}
%union{
  char* sVal;
  int iVal;
struct Eval* evalptr;
}

%start program
%type <evalptr> ES if_pop function_call_body actual_arguments_list actual_arguments TOKEN_TRUE TOKEN_FALSE  exp block PM NS M binary_operation NP logical_operation comparison_operation statements_list statement assignment  Return Print Continue Break  If For While unary_operation function_call bitwise_operation Elseifs Elseif TOKEN_FOR TOKEN_LP for_tbl
%type <sVal> symbol_decs symbol_dec TOKEN_ID TOKEN_INTEGER TOKEN_REAL TOKEN_STRING TOKEN_ADDITION TOKEN_SUBTRACTION TOKEN_MULTIPLICATION TOKEN_DIVISION  TOKEN_MODULO func_body TOKEN_CLASS program lvalue  func_dec var_dec return_type var_type var_list_item var_list TOKEN_INT_TYPE TOKEN_REAL_TYPE TOKEN_BOOL_TYPE TOKEN_STRING_TYPE TOKEN_VOID Class statement_var_dec TOKEN_IN TOKEN_WHILE formal_argument TOKEN_IF formal_arguments
%token TOKEN_CLASS
%token TOKEN_REFERENCE
%token TOKEN_STATIC
%token TOKEN_INT_TYPE
%token TOKEN_REAL_TYPE
%token TOKEN_BOOL_TYPE
%token TOKEN_STRING_TYPE
%token TOKEN_VOID
%token TOKEN_TRUE
%token TOKEN_FALSE
%token TOKEN_PRINT
%token TOKEN_RETURN
%token TOKEN_BREAK
%token TOKEN_CONTINUE
%token TOKEN_WHILE
%token TOKEN_FOR
%token TOKEN_TO
%token TOKEN_IN
%token TOKEN_STEPS
%token TOKEN_LCB
%token TOKEN_RCB
%token TOKEN_LP
%token TOKEN_RP
%token TOKEN_DOT
%token TOKEN_SEMICOLON
%token TOKEN_ID
%nonassoc TOKEN_IF
%nonassoc TOKEN_ELSEIF
%nonassoc TOKEN_ELSE
%left TOKEN_COMMA
%token TOKEN_INTEGER
%token TOKEN_REAL
%token TOKEN_STRING
%right TOKEN_ASSIGNMENT
%left TOKEN_OR 
%left TOKEN_AND 
%left TOKEN_BITWISE_OR
%left TOKEN_BITWISE_AND
%left TOKEN_EQ TOKEN_NE
%left TOKEN_GT TOKEN_GE TOKEN_LT TOKEN_LE 
%left TOKEN_SHIFT_RIGHT TOKEN_SHIFT_LEFT
%left TOKEN_ADDITION TOKEN_SUBTRACTION
%left  TOKEN_MULTIPLICATION TOKEN_DIVISION TOKEN_MODULO
%left TOKEN_POWER
%right TOKEN_NOT TOKEN_BITWISE_NOT


%%
program:
	 macros Classes {
        print("program -> macros Classes");
        print("");
    }
;

macros:
macros macro {
    print("macros -> macros macro");}
	|   {print("macros -> lambda");}
;
macro: 
TOKEN_REFERENCE TOKEN_STRING{
    print("macro -> reference TOKEN_STRING");}
;
Classes: 
Classes Class{
    print("Classes -> Classes Class");}
	| { print("Classes -> lambda"); }
;
Class: 
TOKEN_CLASS TOKEN_ID PM TOKEN_LCB symbol_decs M TOKEN_RCB {
    functionCall("_main", "");
   topPlsLoclNum( atoi( ((struct Eval*)$3)->str));
    for(int i=0 ; i<lastOfReturnQuad ; i++)
        topPlsLoclNum( returnQuads[i]);
       topPlsLoclNum( returnQuad);
    lastOfReturnQuad=0;
    mainSymTbl = pop(tblptrStack);
    allSymbolTablePrint(mainSymTbl);
    printf("this is program");
   // if(mainFunc != NULL){
        //backpatch(mainFunc->nextList , ((struct Eval*)$6)->quad );
       // printf("mainfunc not null %s ", ((struct Eval*)$6)->quad);
   // }else
     printf("mainfunc  null");
    emit("return" , "0" , "" , "" );
    printf("end of program\n");
    $$ = $2;

    print("Class -> class ID ( symbod_decs )");
     
}
;
PM :
{

    snprintf(num,5,"%d",nextquad);
    emit("-" , "top" , "NA" , "top" );
    struct SymbolTable* t = mkTable( NULL , "program");
    push(t, tblptrStack);
    $$ = mkEval (0 ,0 ,0 , "" , mkStr(num) );
}
;
M :
{
    currentLable  = (char *) malloc(sizeof("L") + sizeof(num));
    currentLable = mkStr(createLable());
    $$ = mkEval( 0 , 0 , 0 ,currentLable , "");
}



symbol_decs: 
	symbol_decs symbol_dec{
    
       
       $$ = $1;
        print("symbol_decs -> symbol_decs symbol_dec");}
        |{ print("symbol_decs -> lambda");}
;
symbol_dec: 
	var_dec{
       $$ = $1;
        print("symbol_dec -> var_dec");
         }
	| func_dec{
        $$ = $1;
        print("symbol_dec -> func_dec");
          }
;
var_dec: var_type var_list TOKEN_SEMICOLON {
    print("var_dec -> var_type var_list ;");
    $$ = $1;
     }
;
var_type: 
	return_type {
        $$ = $1;
        print("var_type -> return_type");
         }
	| TOKEN_STATIC return_type {
        $$ = $2;
        print("var_type -> static return_type");
          }
;
return_type: 
	TOKEN_INT_TYPE{
        currentType=4;
        returnType = (char*) malloc(strlen("INT"));
        strcpy(returnType, "INT");
        printf("this is int");
        $$ = $1;
         print("return_type -> int");
         }
	| TOKEN_REAL_TYPE {
        currentType=8;
        returnType = (char*) malloc(strlen("REAL"));
        strcpy(returnType, "REAL");
        printf("this is real");
        $$ = $1;
        print("return_type -> real");
         }
	| TOKEN_BOOL_TYPE {
       currentType=1;
        returnType = (char*) malloc(strlen("BOOL"));
        strcpy(returnType, "BOOL");
       printf("this is bool\n");
        $$ = $1;
        print("return_type -> bool");
         }
	| TOKEN_STRING_TYPE {
        //TODO add
        print("return_type -> string");
         }
	|TOKEN_ID {
        printf( "return_type -> <ID, %s>\n", $1);
          }
;
var_list: 
	var_list TOKEN_COMMA var_list_item {
        $$ = $1;
        print("var_list -> var_list, var_list_item");
          }
	| var_list_item{
        $$ = $1;
        print("var_list -> var_list_item");
         }
;
var_list_item: TOKEN_ID {
/*if(currentType == 4){
        emit("int", $1, "", "");
    }*/
    enterVar( $1, currentType , top(tblptrStack) );
    printf("a variable entered:%s\n",$1);
    $$ = $1;
    printf( "var_list_item -> <ID, %s>\n", $1);
     }
| TOKEN_ID {
   /* if(currentType == 4){
           emit("int", $1, "", "");
       }else if( currentType == 8)*/
   // emit ("real", $1, "", "");

    enterVar( $1 , currentType , top(tblptrStack) );
    printf("a variable entered:%s\n",$1);
    
}
TOKEN_ASSIGNMENT exp{
         if( currentType > 1 && ((struct Eval*)$4)->str != 0 )
             {
                 struct Eval* lvalueEval = idToEval($1);
                 emit("IP" , ((struct Eval*)$4)->str , "" , lvalueEval->str );
             }
             else if (currentType == 1)
             {
                 assignBool( ((struct Eval*)$4)->trueList , ((struct Eval*)$4)->falseList, $1 , true ,true );
             }
             $$ = $1;
         printf( "var_list_item -> <ID> = exp\n");
           }
;

func_dec: 
	var_type func_body {
        $$ = $2;
        print("func_dec -> var_type func_body");
    }
	| TOKEN_VOID func_body {
         returnType = (char*) malloc(strlen("VOID"));
         strcpy(returnType, "VOID");
        $$ = $2;
         print("func_dec -> void func_body");
         }
	| TOKEN_STATIC TOKEN_VOID func_body {
         returnType = (char*) malloc(strlen("VOID"));
         strcpy(returnType, "VOID");
        $$ = $3;
         print("func_dec -> static void func_body");
         }
;
func_body: 
TOKEN_ID NP M {
    emit("=" , "top" , "" , "sp");
    emit("//" , "func decleration:" ,"" , $1);
    snprintf(num,5,"%d",nextquad);
    strcpy(snum, num);
    emit("-" , "top" , "NA" , "top" );
    char* tmpc = mkStr( top(tblptrStack)->name );
    struct SymbolTable* tmpt = pop(tblptrStack);
    enterFunc(tmpc , -1 , returnType ,  tmpt , top(tblptrStack) , ((struct Eval*)$3)->quad);
    push( tmpt , tblptrStack );
}TOKEN_LP formal_arguments TOKEN_RP  block M ret M{
    for(int i = 0; i < j; i++){
          if(strcmp($1, funcID[i])==0){
              backpatch(mkList(address[i]),((struct Eval*)$3)->quad);
              strcpy(quad_ruples[sizeAdd[i]][2], intToString(9 + (top(tblptrStack)->argNum)));
              strcpy(quad_ruples[scpAdd[i]][2], intToString((top(tblptrStack)->ID)));
              
          }
      }
    topPlsLoclNum(atoi(snum));
    for(int i=0 ; i<lastOfReturnQuad ; i++)
        topPlsLoclNum( returnQuads[i] );
    topPlsLoclNum(returnQuad);
    lastOfReturnQuad=0;
    pop(tblptrStack);
    backpatch( ((struct Eval*)$2)->nextList , ((struct Eval*)$11)->quad );
    backpatch( ((struct Eval*)$8)->nextList , ((struct Eval*)$9)->quad );
    $$ = $1;
    emit("//", "num", $$, $1);
    printf( "func_body -> <ID, %s> ( formal_arguments ) block\n", $1);
}
;
ret : {
   /* if(inBlock == true){
       emit("+" , "top" , "1" , "top");
       emit("+" , "atop" , "1" , "atop");
          emit("IP" , "sp" , "" , "atop");
        inBlock = false;
    }*/
        char * tmpPointer = newPTemp();
        char * PPtmp = newVTemp();
        char * tmpPointerWithStar = (char*) malloc(strlen(tmpPointer)+1);
        strcpy(tmpPointerWithStar , "*");
        strcat( tmpPointerWithStar , tmpPointer );
        //returning
        emit("//","return" , "" , "");
        returnQuads[lastOfReturnQuad] = nextquad;
      returnQuad = nextquad;
        lastOfReturnQuad++;
        emit("+" , "top" , "NA" , "top");
        emit("+" , "atop" , "1" , PPtmp);
        emit("PI" , PPtmp , "" , tmpPointer );
        emit("goto" , tmpPointerWithStar , "" , "");
    }
;
NP :
{
   
    printf("starting reducing NP\n");
    mkSymTbl(currentLexeme);
    $$ = mkEval(0 , 0 , mkList(nextquad) , "" , "");
       
    emit("goto" , "" , "" , "" );
   
}
;

formal_arguments:
	formal_arguments TOKEN_COMMA formal_argument{
        $$ = $1;
         print("formal_arguments -> formal_arguments , formal_argument");
          }
	| {
        $$ = 0;
         print("formal_arguments -> lambda");
         }
	| formal_argument {
        $$ = $1;
         print("formal_arguments -> formal_argument");
          }
;
formal_argument: return_type TOKEN_ID{
    emit("//", "param entered in: ", top(tblptrStack)->name, $2);
   enterParam($2, currentType , top(tblptrStack));
    $$ = $1;
     printf( "formal_argument -> return_type <ID, %s>\n", $2);
     }
;
block :
	M TOKEN_LCB statements_list TOKEN_RCB M {
        $$ = $3;
        if(break_list != NULL){
            printf("broken\n");
            backpatch(break_list, ((struct Eval*)$5)->quad );
            break_list = NULL;
        }
        if(cont_list != NULL){
            printf("continue\n");
            backpatch(cont_list, ((struct Eval*)$1)->quad );
            cont_list = NULL;
        }
        
        //printf("this is block \t nextList:%x\n" , ((struct Eval*)$2)->nextList );
        print("block -> { statements_list }");
    }
	| statement{
        $$ = $1;
       // printf("this is block \t nextList:%x\n" , ((struct Eval*)$1)->nextList );
        print("block -> statement");
          }
;
statements_list: 
	statements_list M statement{
        
       backpatch( ((struct Eval*)$1)->nextList , ((struct Eval*)$2)->quad );
     
        $$ = mkEval (0 ,0 , ((struct Eval*)$3)->nextList , "" , "");

        print("statements_list -> statements_list statement");
         }
|{
    $$ = mkEval(0,0,0,"","");
    print("statements_list -> lambda");
         }
;
statement:
	TOKEN_SEMICOLON {
        $$ = mkEval(0,0,0,"","");
        print("statement ->  ;");
          }
	| exp TOKEN_SEMICOLON {
        $$ = mkEval(0,0,0,"","");
        print("statement -> exp ;");
         }
	| assignment {
         printf("reduced");
         //$$ = mkEval (0 ,0 , ((struct Eval*)$1)->nextList , "" , "");
         $$ = $1;
        print("statement -> assignment");
         }
	| Print {
        $$ = mkEval(0,0,0,"","");
       // $$ = mkEval (0 ,0 , ((struct Eval*)$1)->nextList , "" , "");
       // $$=$1;
        print("statement -> Print ");
          }
    | statement_var_dec {
        $$ = strToEval($1);
        // $$=$1;
    print("statement -> statement_var_dec");
      }
	| If {
        $$ = mkEval (0 ,0 , ((struct Eval*)$1)->nextList , "" , "");
         //$$=$1;
        print("statement -> If");
          }
	| For {
        $$ = mkEval (0 ,0 , ((struct Eval*)$1)->nextList , "" , "");
         //$$=$1;
        print("statement -> For");
         }
	| While {
        $$ = mkEval (0 ,0 , ((struct Eval*)$1)->nextList , "" , "");
         //$$=$1;
        print("statement -> While ");
         }
	| Return {
        $$ = mkEval (0 ,0 , ((struct Eval*)$1)->nextList , "" , "");
        // $$=$1;
        print("statement -> Return");
          }
    | Break {
        $$ = mkEval (0 ,0 , ((struct Eval*)$1)->nextList , "" , "");
        // $$=$1;
        print("statement -> Break");
          }
	| Continue {
        $$ = mkEval (0 ,0 , ((struct Eval*)$1)->nextList , "" , "");
         //$$=$1;
        print("statement -> Continue");
         }
;
assignment:
lvalue TOKEN_ASSIGNMENT exp TOKEN_SEMICOLON { print("assignment -> lvalue = exp ;");
        if( strcmp( ((struct Eval*)$3)->quad , "*" ) != 0 ){
             struct Eval* lvalueEval = idToEval($1);
             //DANGER
             emit("IP" , ((struct Eval*)$3)->str , "" , lvalueEval->str );
             printf("emited\n");
         }
         else{
             assignBool( ((struct Eval*)$3)->trueList , ((struct Eval*)$3)->falseList, $1 , true ,true );
         }
         $$ = mkEval(0,0,0,"","");
         printf("g\n");
}
;
lvalue: 
	TOKEN_ID{
        $$ = $1;
        printf( "lvalue -> <ID, %s>\n", $1);
          }
| TOKEN_ID TOKEN_DOT TOKEN_ID{
    //TODO
    printf( "lvalue -> <ID, %s> . <ID, %s>\n", $1, $3);
      }
;
Print : TOKEN_PRINT TOKEN_LP exp TOKEN_RP TOKEN_SEMICOLON{
        emit("pr", ((struct Eval*)$3)->str, "", "");
}
;
statement_var_dec: return_type var_list TOKEN_SEMICOLON {
    //TODO
    $$ = $1;
     print("statement_var_dec -> return_type var_list ;");
     }
;
If :
TOKEN_IF if_tbl TOKEN_LP exp TOKEN_RP M if_code M block if_pop M Elseifs %prec TOKEN_IF{
    currentLable  = (char *) malloc(sizeof("L") + sizeof(num));
    currentLable = mkStr(createLable());
    backpatch( ((struct Eval*)$10) ->nextList , currentLable);
        backpatch( ((struct Eval*)$4) ->trueList, ((struct Eval*)$8) ->quad);
        backpatch( ((struct Eval*)$4) ->falseList, ((struct Eval*)$11)->quad);
       // backpatch( ((struct Eval*)$12) ->falseList , currentLable );
       //  backpatch(((struct Eval*)$12) ->nextList,currentLable );
        Node * tmp = mergeList ( ((struct Eval*)$4) ->falseList, ((struct Eval*)$11) ->nextList );
        $$=mkEval(0,0, tmp ,"","");
     //    emit("+" , "top" , "1" , "top");
      //   emit("+" , "atop" , "1" , "atop");
        //    emit("IP" , "sp" , "" , "atop");
        print("IF -> if ( exp ) block Elseifs");
}
|TOKEN_IF if_tbl TOKEN_LP exp TOKEN_RP M if_code M block if_pop M Elseifs TOKEN_ELSE NS M block M %prec TOKEN_ELSE{
        backpatch( ((struct Eval*)$10) ->nextList , ((struct Eval*)$17) ->quad );
        backpatch( ((struct Eval*)$4) ->trueList , ((struct Eval*)$8) ->quad );
        backpatch( ((struct Eval*)$4) ->falseList , ((struct Eval*)$11) ->quad );
        backpatch( ((struct Eval*)$12) ->falseList , ((struct Eval*)$15) ->quad );
        backpatch(((struct Eval*)$12) ->nextList,((struct Eval*)$17) ->quad );
       // Node * tmp1=mergeList ( ((struct Eval*)$12) ->nextList , ((struct Eval*)$16) ->nextList );
        //Node * tmp2 = mergeList(((struct Eval*)$9) -> nextList, tmp1);
        //Node * tmp = mergeList ( ((struct Eval*)$9) ->nextList , tmp2);
        $$ = mkEval(0,0,0,"","");
       // printf("FINISH : IF exp THEN M block ELSE NS M block <TO> stmt FINISHED\n");
          print("IF -> if ( exp ) block Elseifs else");
         }
;
if_code:{
  /*
    emit("=" , "top" , "" , "sp");
       na = intToString(nextquad);
       emit("-" , "top" , "NA" , "top" );
       emit("//", na, "here", "");
       char* tmpc = mkStr(top(tblptrStack)->name);
       struct SymbolTable* tmpt = pop(tblptrStack);
        enterFunc(tmpc , -1 , "" ,  tmpt , top(tblptrStack) , currentLable);
        push( tmpt , tblptrStack );*/
}
;
if_pop :{
    /*inBlock = false;
    topPlsLoclNum(atoi(na));
    pop(tblptrStack);*/
    $$ = mkEval ( 0 , 0 , mkList(nextquad) , "" , "" );
    emit( "goto" ,"","","" );
}
;
if_tbl :{
   /* inBlock = true;
    char * n  = (char *) malloc(sizeof(char) *5);
    snprintf(n, 5, "%d", ifNum);
    printf("%s\n", n);
    char * tmp = mkStr("if_");
    strcat(tmp, n);
    mkSymTbl(tmp);
    ifNum++;
    emit("-" , "top" , "1" , "top");
    emit("IP" , intToString(-1*(ifNum - 1) ), "" , "top");
    emit("-" , "atop" , "1" , "atop");
    emit("IP" , "sp" , "" , "atop");*/
}

NS:
{
   // $$ = mkEval ( 0 , 0 , mkList(nextquad) , "" , "" );
    //emit( "goto" ,"","","" );
}

;
Elseifs :  
	Elseifs Elseif M{
        
        //backpatch( ((struct Eval*)$1) ->falseList , ((struct Eval*)$2) ->quad );
         Node * tmp=mergeList ( ((struct Eval*)$1) ->nextList , ((struct Eval*)$2) ->nextList);
        // Node * tmp = mergeList(((struct Eval*)$3) -> nextList, tmp1);
         $$ = mkEval(((struct Eval*)$2) ->trueList ,((struct Eval*)$2) ->falseList ,tmp,"","");
          print("Elseifs -> Elseifs Elseif");
           }
	| {
         //afterIF = mkStr(((struct Eval*)$1)->quad);
        $$ = mkEval(0, 0, 0 , "", "");
        print("Elseifs -> lambda");
         }
;
Elseif : 
	TOKEN_ELSEIF TOKEN_LP exp TOKEN_RP M block ES M {
    afterIF = mkStr(((struct Eval*)$8)->quad);
    backpatch( ((struct Eval*)$3) ->falseList , ((struct Eval*)$8) ->quad );
    backpatch( ((struct Eval*)$3) ->trueList , ((struct Eval*)$5) ->quad );
    $$ = mkEval(((struct Eval*)$3)->trueList, ((struct Eval*)$3) ->falseList, ((struct Eval*)$7) ->nextList, "", "");
        print("Elseif -> elseif ( exp ) block");
         }
;
ES:
{
    $$ = mkEval ( 0 , 0 , mkList(nextquad) , "" , "" );
    emit( "goto" ,"","","" );
}
For :
TOKEN_FOR for_tbl TOKEN_LP TOKEN_ID
TOKEN_IN exp TOKEN_TO exp TOKEN_STEPS exp TOKEN_RP M{
      //  emit("=" , "top" , "" , "sp");
       // $5 = intToString(nextquad);
       // emit("-" , "top" , "NA" , "top" );
       // emit("//", $5, "here", "");
       // char* tmpc = mkStr(top(tblptrStack)->name);
       // printf("sym tblName: %s\n", top(tblptrStack)->name);
       // struct SymbolTable* tmpt = pop(tblptrStack);
       // printf("inner scope: %s\n", top(tblptrStack)->name);
       // enterFunc(tmpc , -1 , "" ,  tmpt , top(tblptrStack) , ((struct Eval*)$12)->quad);
       // push( tmpt , tblptrStack );
        enterVar( $4, 8, top(tblptrStack));
        $1 = idToEval($4);
        emit("IP" , ((struct Eval*)$6)->str , "-" , ((struct Eval*)$1)->str );
        printf("emited\n");
//  $$ = mkEval( 0 ,0 , ((struct Eval*)$4)->falseList , "" , "");
}M {
    char* tmp = mkStr("*");
     printf("%s\n", tmp);
    strcat(tmp,mkStr(((struct Eval*)$1)->str));
    printf("%s\n", tmp);
    emit("if", tmp, " >=", ((struct Eval*)$6)->str);
    emit("if", tmp, " < ", ((struct Eval*)$8)->str);
    $3 = mkEval( mkList(nextquad) , mkList(nextquad+1) , 0 , "*" , "");
    emit("goto" , "" , "" , "" );
    emit("goto" , "" , "" , "" );
}M block{
    char* tmp = mkStr("*");
     strcat(tmp,mkStr(((struct Eval*)$1)->str));
     emit ("+",tmp, ((struct Eval*)$10)->str, tmp );
     emit("goto", ((struct Eval*)$14)->quad ,"" ,"");
} M{
    backpatch( ((struct Eval*)$3)->trueList , ((struct Eval*)$16)->quad );
    backpatch( ((struct Eval*)$3)->falseList , ((struct Eval*)$19)->quad );
    Node * tmp = mergeList ( ((struct Eval*)$3)->falseList, ((struct Eval*)$17)->nextList );
     $$ = mkEval( 0 ,0 , 0 , "" , "");
    
     
      //  printf( "For -> for ( <ID, %s> in exp to exp steps exp ) block", $4);
    //  emit("//", "quad ", $5, "for");
    //  topPlsLoclNum(atoi($5));
    //  pop(tblptrStack);
      // backpatch( ((struct Eval*)$2)->nextList , ((struct Eval*)$18)->quad );
         }
;
for_tbl :{
    printf("in for_\n");
 //   char * n  = (char *) malloc(sizeof(char) *5);
 //   snprintf(n, 5, "%d", forNum);
 //   printf("%s\n", n);
    
   // char * tmp = mkStr("for_");
 //   strcat(tmp, n);
   // mkSymTbl(tmp);
    printf("sym tbl made\n");
    forNum++;
}
;
While :
TOKEN_WHILE while_tbl M TOKEN_LP exp TOKEN_RP {
    //emit("=" , "top" , "" , "sp");
   // $1 = intToString(nextquad);
    //emit("-" , "top" , "NA" , "top" );
    //char* tmpc = mkStr(top(tblptrStack)->name);
    //printf("sym tblName: %s\n", top(tblptrStack)->name);
    //struct SymbolTable* tmpt = pop(tblptrStack);
    //printf("inner scope: %s\n", top(tblptrStack)->name);
    //enterFunc(tmpc , -1 , "-" ,  tmpt , top(tblptrStack) , ((struct Eval*)$3)->quad);
    //push( tmpt , tblptrStack );
}M block {
    emit("goto", ((struct Eval*)$3)->quad ,"" ,"");
}M{
        printf("in : WHILE\n");
        backpatch( ((struct Eval*)$9)->nextList , ((struct Eval*)$3)->quad );
        backpatch( ((struct Eval*)$5)->trueList , ((struct Eval*)$8)->quad );
        backpatch( ((struct Eval*)$5)->falseList , ((struct Eval*)$11)->quad );
        //Node * tmp = mergeList ( ((struct Eval*)$5)->falseList, ((struct Eval*)$9)->nextList );
        $$ = mkEval( 0 ,0 , 0 , "" , "");
        
        //topPlsLoclNum(atoi($1));
        //pop(tblptrStack);
        print("While -> while ( exp ) block");
         }
;
while_tbl :{
    //char * n  = (char *) malloc(sizeof(char) *5);
    //snprintf(n, 5, "%d", forNum);
    //printf("%s\n", n);
    //char * tmp = mkStr("while_");
   // strcat(tmp, n);
   // mkSymTbl(tmp);
    printf("sym tbl made\n");
    whileNum++;
}
Return :
TOKEN_RETURN {
    emit("//","saw return\n", "", "");
}exp TOKEN_SEMICOLON {
        char * tmpPointer = newPTemp();
        emit("+" , "sp" , "1" , tmpPointer);
        emit("IP" , ((struct Eval*)$3)->str , "" , tmpPointer);
        
}ret {$$=mkEval(0 , 0 , 0 , "" , "");}
;

Break :
	TOKEN_BREAK TOKEN_SEMICOLON {
        $$ = mkEval(0,0,0,"","");
        if(break_list == NULL){
            printf("starting breaklist %d\n", nextquad);
            break_list = mkList(nextquad);
            printf("%d\n", break_list->value);
        }
        else
            break_list->next = mkList(nextquad);
        //TODO
        emit("goto" , "" , "" , "" );
        print("Break -> break;"); }
;

Continue :
	TOKEN_CONTINUE TOKEN_SEMICOLON {
        $$ = mkEval(0,0,0,"","");
              if(cont_list == NULL){
                  printf("starting contlist %d\n", nextquad);
                  cont_list = mkList(nextquad);
                  printf("%d\n", cont_list->value);
              }
              else
                  break_list->next = mkList(nextquad);
          emit("goto" , "" , "" , "" );
        //TODO
        print("Continue -> continue;");  }
;

exp :
TOKEN_INTEGER {
    $$=strToEval($1);
    printf( "exp -> <int, %s>\n", $1);
}
	| TOKEN_REAL {
        $$=strToEval($1);;
        printf( "exp -> <real, %s>\n", $1);
    }
	| TOKEN_TRUE {
        $$ = mkEval( mkList(nextquad) , 0 , 0 , "*" , "true");
        defaultGotoGen();

        print("exp -> true"); }
	| TOKEN_FALSE {
        $$ = mkEval( 0 , mkList(nextquad) , 0 , "*" , "false");
        defaultGotoGen();}
	| TOKEN_STRING {
        $$ = strToEval($1);
        printf( "exp -> <string, %s>\n", $1); }
	| lvalue {
        struct Eval* lvalueEval = idToEval($1);
        int idSize = atoi( lvalueEval->quad);
        char * value = newTemp();
        emit("PI" , lvalueEval ->str , "" , value);
        saveTmpVal(value);
        if( idSize == 1)
        {
            emit("if", value , "==" , "true" );
            $$ = mkEval( mkList(nextquad) , mkList(nextquad+2) , 0 , "*" , value);
            defaultGotoGen();
            defaultGotoGen();
        }
        else
            $$ = mkEval( 0 , 0 , 0 , "" , value);
        print("exp -> lvalue");
        
    }
	| binary_operation {
        $$ = $1;
        print("exp -> binary_operation");}
	| logical_operation {
        $$ = $1;
        print("exp -> logical_operation"); }
    | comparison_operation {
        $$ = $1;
        print("exp -> comparison_operation");}
	| bitwise_operation {
        $$ = $1;
        print("exp -> bitwise_operation"); }
	| unary_operation {
        $$ = $1;
        print("exp -> unary_operation");}
	| TOKEN_LP exp TOKEN_RP {
        $$ = $2;
        print("exp -> ( exp )"); }
	| function_call {
        $$ = $1;
        print("exp -> function_call");}
;
binary_operation :

exp TOKEN_ADDITION exp{
    printf("in bi\n");
    $$=mkEval( 0 , 0 , 0 , "" , newTemp());
    loadTmpVal(((struct Eval*)$1)->str);
    loadTmpVal(((struct Eval*)$3)->str);
    emit("+" , ((struct Eval*)$1)->str , ((struct Eval*)$3)->str , ((struct Eval*)$$)->str );
    saveTmpVal(((struct Eval*)$$)->str);
print("binary_operation -> exp + exp"); }
	| exp TOKEN_SUBTRACTION exp{
        $$=mkEval( 0 , 0 , 0 , "" , newTemp() );
        loadTmpVal(((struct Eval*)$1)->str);
        loadTmpVal(((struct Eval*)$3)->str);
        emit("-" , ((struct Eval*)$1)->str , ((struct Eval*)$3)->str , ((struct Eval*)$$)->str );
        saveTmpVal(((struct Eval*)$$)->str);
        print("binary_operation -> exp - exp"); }
	| exp TOKEN_MULTIPLICATION exp{
        $$=mkEval( 0 , 0 , 0 , "" , newTemp() );
        loadTmpVal(((struct Eval*)$1)->str);
        loadTmpVal(((struct Eval*)$3)->str);
        emit("*" , ((struct Eval*)$1)->str , ((struct Eval*)$3)->str , ((struct Eval*)$$)->str );
        saveTmpVal(((struct Eval*)$$)->str);
        print("binary_operation -> exp * exp"); }
	| exp TOKEN_DIVISION exp{
        $$=mkEval( 0 , 0 , 0 , "" , newTemp() );
        loadTmpVal(((struct Eval*)$1)->str);
        loadTmpVal(((struct Eval*)$3)->str);
        emit("/" , ((struct Eval*)$1)->str , ((struct Eval*)$3)->str , ((struct Eval*)$$)->str );
        saveTmpVal(((struct Eval*)$$)->str);
        print("binary_operation -> exp / exp"); }
	| exp TOKEN_MODULO exp{
        $$=mkEval( 0 , 0 , 0 , "" , newTemp() );
        loadTmpVal(((struct Eval*)$1)->str);
        loadTmpVal(((struct Eval*)$3)->str);
        emit("%" , ((struct Eval*)$1)->str , ((struct Eval*)$3)->str , ((struct Eval*)$$)->str );
        saveTmpVal(((struct Eval*)$$)->str);;
        print("binary_operation -> exp % exp"); }
    | exp TOKEN_POWER exp{
        $$=mkEval( 0 , 0 , 0 , "" , newTemp() );
        loadTmpVal(((struct Eval*)$1)->str);
        loadTmpVal(((struct Eval*)$3)->str);
        emit("^" , ((struct Eval*)$1)->str , ((struct Eval*)$3)->str , ((struct Eval*)$$)->str );
        saveTmpVal(((struct Eval*)$$)->str);
        print("binary_operation -> exp ^ exp"); }
	| exp TOKEN_SHIFT_LEFT exp{
        $$=mkEval( 0 , 0 , 0 , "" , newTemp() );
        loadTmpVal(((struct Eval*)$1)->str);
        loadTmpVal(((struct Eval*)$3)->str);
        emit("<<" , ((struct Eval*)$1)->str , ((struct Eval*)$3)->str , ((struct Eval*)$$)->str );
        saveTmpVal(((struct Eval*)$$)->str);
        print("binary_operation -> exp << exp");}
	| exp TOKEN_SHIFT_RIGHT exp {
        $$=mkEval( 0 , 0 , 0 , "" , newTemp() );
        loadTmpVal(((struct Eval*)$1)->str);
        loadTmpVal(((struct Eval*)$3)->str);
        emit(">>" , ((struct Eval*)$1)->str , ((struct Eval*)$3)->str , ((struct Eval*)$$)->str );
        saveTmpVal(((struct Eval*)$$)->str);
        print("binary_operation -> exp >> exp"); }
;
logical_operation : 
    exp TOKEN_AND M exp{
        backpatch( ((struct Eval*)$1) ->trueList , ((struct Eval*)$3) ->quad);
        $$ = mkEval( ((struct Eval*)$4) ->trueList , mergeList( ((struct Eval*)$1)->falseList , ((struct Eval*)$4) ->falseList ) , 0 , "*" , "" );
        print("logical_operation -> exp && exp");}
	| exp TOKEN_OR M exp {
        backpatch( ((struct Eval*)$1) ->falseList , ((struct Eval*)$3) ->quad);
        $$ = mkEval( mergeList( ((struct Eval*)$1)->trueList , ((struct Eval*)$4) ->trueList ), ((struct Eval*)$4) ->falseList , 0 , "*" , "" );
        print("logical_operation -> exp || exp");}
;
comparison_operation :
	exp TOKEN_LT exp {
        loadTmpVal( ((struct Eval*)$1) ->str );
        loadTmpVal( ((struct Eval*)$3) ->str );
        emit("if", ((struct Eval*)$1) ->str , "<" ,((struct Eval*)$3)->str );
        $$ = mkEval( mkList(nextquad) , mkList(nextquad+2) , 0 , "*" , "");
        defaultGotoGen();
        defaultGotoGen();
        print("comparison_operation -> exp < exp"); }
	|exp TOKEN_LE exp {
        loadTmpVal( ((struct Eval*)$1) ->str );
              loadTmpVal( ((struct Eval*)$3) ->str );
              emit("if", ((struct Eval*)$1) ->str , "<=" ,((struct Eval*)$3)->str );
              $$ = mkEval( mkList(nextquad) , mkList(nextquad+2) , 0 , "*" , "");
              defaultGotoGen();
              defaultGotoGen();
        print("comparison_operation -> exp <= exp"); }
	|exp TOKEN_GT exp {
        loadTmpVal( ((struct Eval*)$1) ->str );
              loadTmpVal( ((struct Eval*)$3) ->str );
              emit("if", ((struct Eval*)$1) ->str , ">" ,((struct Eval*)$3)->str );
              $$ = mkEval( mkList(nextquad) , mkList(nextquad+2) , 0 , "*" , "");
              defaultGotoGen();
              defaultGotoGen();
        print("comparison_operation -> exp > exp"); }
	|exp TOKEN_GE exp {
        loadTmpVal( ((struct Eval*)$1) ->str );
              loadTmpVal( ((struct Eval*)$3) ->str );
              emit("if", ((struct Eval*)$1) ->str , ">=" ,((struct Eval*)$3)->str );
              $$ = mkEval( mkList(nextquad) , mkList(nextquad+2) , 0 , "*" , "");
              defaultGotoGen();
              defaultGotoGen();
        print("comparison_operation -> exp >= exp");}
	|exp TOKEN_EQ exp {
        loadTmpVal( ((struct Eval*)$1) ->str );
              loadTmpVal( ((struct Eval*)$3) ->str );
              emit("if", ((struct Eval*)$1) ->str , "==" ,((struct Eval*)$3)->str );
              $$ = mkEval( mkList(nextquad) , mkList(nextquad+2) , 0 , "*" , "");
              defaultGotoGen();
              defaultGotoGen();
        print("comparison_operation -> exp == exp"); }
	|exp TOKEN_NE exp {
        loadTmpVal( ((struct Eval*)$1) ->str );
              loadTmpVal( ((struct Eval*)$3) ->str );
              emit("if", ((struct Eval*)$1) ->str , "!=" ,((struct Eval*)$3)->str );
              $$ = mkEval( mkList(nextquad) , mkList(nextquad+2) , 0 , "*" , "");
              defaultGotoGen();
              defaultGotoGen();
        print("comparison_operation -> exp != exp");}
;
bitwise_operation : 
	exp TOKEN_BITWISE_AND exp {
        $$=mkEval( 0 , 0 , 0 , "" , newTemp() );
               loadTmpVal(((struct Eval*)$1)->str);
               loadTmpVal(((struct Eval*)$3)->str);
               emit("&" , ((struct Eval*)$1)->str , ((struct Eval*)$3)->str , ((struct Eval*)$$)->str );
               saveTmpVal(((struct Eval*)$$)->str);
        print("bitwise_operation -> exp & exp");}
	| exp TOKEN_BITWISE_OR exp{
        $$=mkEval( 0 , 0 , 0 , "" , newTemp() );
               loadTmpVal(((struct Eval*)$1)->str);
               loadTmpVal(((struct Eval*)$3)->str);
               emit("|" , ((struct Eval*)$1)->str , ((struct Eval*)$3)->str , ((struct Eval*)$$)->str );
               saveTmpVal(((struct Eval*)$$)->str);
        
        print("bitwise_operation -> exp | exp");}
;
unary_operation : 
	TOKEN_SUBTRACTION exp{
        $$=mkEval( 0 , 0 , 0 , "" , newTemp() );
        loadTmpVal(((struct Eval*)$2)->str);
        emit("1-" , ((struct Eval*)$2)->str , "" , ((struct Eval*)$$)->str );
        saveTmpVal(((struct Eval*)$$)->str);
        print("unary_operation -> - exp");}
	| TOKEN_NOT exp {print("unary_operation -> ! exp");
        $$ = mkEval(((struct Eval*)$2)->falseList, ((struct Eval*)$2)->trueList, 0, "*", "");
      //  //TODO
    }
	| TOKEN_BITWISE_NOT exp {
        $$=mkEval( 0 , 0 , 0 , "" , newTemp() );
        loadTmpVal(((struct Eval*)$2)->str);
        emit("~" , ((struct Eval*)$2)->str , "" , ((struct Eval*)$$)->str );
        saveTmpVal(((struct Eval*)$$)->str);
        print("unary_operation -> ~ exp");}
;
function_call : 
	TOKEN_ID {
        funcName = mkStr($1);
    } function_call_body {
        $$= $3;
       printf( "function_call -> ID%s function_call_body", $1);
    }
	| TOKEN_ID TOKEN_DOT TOKEN_ID function_call_body {
        printf( "function_call -> <ID, %s> . <ID, %s> function_call_body\n", $1, $3 );
        
    }
;

function_call_body : 
	TOKEN_LP actual_arguments TOKEN_RP {
        $$ = mkEval( 0 , 0 , 0 , "" , functionCall ( funcName , ((struct Eval*)$2)->str ) );
         printf("%s\n", funcName);
        print("function_call_body -> (actual_arguments)"); }
;

actual_arguments : 
	actual_arguments_list {
        $$ = $1;
        print("actual_arguments -> actual_arguments_list");}
	|{
        $$ = mkEval(0 , 0 , 0 , "" , "" );
        print("actual_arguments -> lambda");
        
    }
;

actual_arguments_list : 
	actual_arguments_list TOKEN_COMMA exp {
        char* strTmp = strcat( ((struct Eval*)$1)->str , "," );
        if( strcmp( ((struct Eval*)$3)->str , "" ) )
            strTmp = strcat( strTmp , ((struct Eval*)$3)->str );
        else
        {
            char * mytmp = newTemp();
            assignBool(((struct Eval*)$3) ->trueList , ((struct Eval*)$3) ->falseList , mytmp , true , true );
            strTmp = strcat( strTmp , mytmp );
        }
        $$ = mkEval(0 , 0 , 0 , "" , strTmp);
        print("actual_arguments_list -> actual_arguments_list , exp");}
    | exp {
        printf("explist->exp : %s\n", ((struct Eval*)$1)->str  );
        char* strTmp;
        if( strcmp( ((struct Eval*)$1)->str , "" ) )
            strTmp = strcat( ((struct Eval*)$1)->str , "," );
        else
        {
            char * mytmp = newTemp();
            assignBool(((struct Eval*)$1) ->trueList , ((struct Eval*)$1) ->falseList , mytmp , true , true );
            strTmp = strcat( mytmp , "," );
            
        }
        $$ = mkEval(0 , 0 , 0 , "" , strTmp);

        print("actual_arguments_list -> exp");}
;

%%

int t=0;
int q=0;

void topPlsLoclNum(int quad)
{
  
    snprintf(num,5,"%d",top(tblptrStack)->localNum);
      emit("//", "in topPlsLoclNum()", num, intToString(quad));
    int i =0;
  //  printf("in topPlsLoclNum()\n");
  while(num[i]!='\0'){
      printf("in toppls %s\n", num);
      printf("in toppls %s %s %s\n", quad_ruples[quad][0], quad_ruples[quad][1], quad_ruples[quad][3]);
   quad_ruples[quad][2][i] = num[i];
  i++;
  }
  quad_ruples[quad][2][i] = num[i];
}

void loadTmpVal(char * theTmp){
  
    if( (theTmp[0]>='0' && theTmp[0]<='9') || strcmp(theTmp, "true")==0 || strcmp(theTmp, "false" )==0 || theTmp[0]=='-')
        return;
    int *i = (int *) malloc( sizeof(int) );
    int *j = (int *) malloc( sizeof(int) );
    char* addressOfStack = lookup(theTmp , top(tblptrStack) , i , j );
    emit("//", " load temp val: stack add:", addressOfStack, theTmp);
   emit( "PI" , addressOfStack , "" , theTmp );
}

void saveTmpVal(char* theTmp){
    if((theTmp[0]>='0' && theTmp[0]<='9') || strcmp(theTmp, "true" )==0 || strcmp(theTmp, "false" )==0 || theTmp[0]=='-')
        return;
    int *i = (int *) malloc( sizeof(int) );
    int *j = (int *) malloc( sizeof(int) );
    char* addressOfStack = lookup(theTmp , top(tblptrStack) , i , j );
    emit("//", " save temp val: stack add:", addressOfStack, theTmp);
   emit("IP" , theTmp , "" , addressOfStack );
}

struct Eval * idToEval(char * idName){
    
    int * intsize = (int *) malloc(sizeof(int));
    int * scopeID = (int *) malloc(sizeof(int));
    char* tmp = lookup( idName ,top(tblptrStack) , intsize , scopeID );
    char * num = (char*) malloc( sizeof(char) * 3 ) ;
    num =  intToString(*intsize);
    //printf("lvalue to Identifier\tintSize:%d\tnum=%s\tthe addres is:%s\n", *intsize , num , tmp);
    if(tmp == 0)
    {
        yyerror("Variable is not Defined!!!!!!\t:'(");
        return 0;
    }
    else
        return mkEval( 0,0, 0 , num , tmp);
}

char* functionCall(char* id ,char * explist){
    //emit("=" , "top" , "" , "sp");
    emit( "//" , "function call:" , id , "");
    printf("function call: %s \n" , id);
    //char * casStr = explist;
    char* strTmp = strtok( explist , "," );
    while( strTmp != 0 )//push variables
    {
        emit( "//" , "arg:" , strTmp , "");
        //casStr += strlen(strTmp) + 1 ;
        emit( "-" , "top" , "1" , "top" );
        loadTmpVal(strTmp);
        emit("IP" , strTmp , "" , "top" );
        strTmp = strtok( NULL , ",");
    }
    int* size = (int*) malloc( sizeof(int) );
    int* scopeID = (int*) malloc( sizeof(int) );
    //symbolTablePrint(top(tblptrStack) );
    printf("gonna look %s\n", top(tblptrStack)->name);
    char* tmp = lookup(id , top(tblptrStack) , size , scopeID);
     printf(" looked\n");
    printf("size is : %d" , *size );
   // if(*size>8)
        char * retLabel= newQuad();
        char * retaddress = newPTemp();
        
        //push number of arguments
        emit("-" , "top" , "1" , "top");
        char* buff = (char*) malloc( sizeof(char) * 3 );
        buff = intToString(*size - 9);
        if(strcmp(tmp, "-") != 0)
            sizeAdd[j] = nextquad;
        emit("IP" , buff , "" , "top" );
        
        //push return address
        emit("-" , "top" , "1" , "top");
        emit("&&" , retLabel , "" , retaddress);
        emit("-" , "atop" , "1" , "atop");
        emit("IP" , retaddress , "" , "atop");
        
        //push return value
        emit("-" , "top" , "1" , "top");
        
        //push sp
        emit("-" , "top" , "1" , "top");
        char* scopeid = (char*) malloc( sizeof(char) * 3 );
         scopeid= intToString(*scopeID);
         if(strcmp(tmp, "-") != 0)
            scpAdd[j] = nextquad;
        emit("IP" , scopeid , "" , "top");
        emit("-" , "atop" , "1" , "atop");
        emit("IP" , "sp" , "" , "atop");
        
        //call
        if(strcmp(tmp, "-") != 0)
            emit("goto" , tmp , "" , "");
        else{
            printf("hereeee\n");
            funcID[j] = id;
            address[j] = nextquad;
            emit("goto" , "" , "" , "");
            j++;
        }
        emit( "//" , "return after func call" , "" , "");
        //return location
        emit( strcat(retLabel ,":") , "" , "" , "");
        
        //get return value
        char* returnValue = newTemp();
        emit("+" , "top" , "1" , "top");
        emit("PI" , "top" , "" , returnValue);
        //printf("size is : %d" , *size );
        
        //make every thing normal
            //setting top
            emit("+" , "top" , "2" , "top");
            char* argcount = newITemp();
            emit("PI" , "top" , "" , argcount);
            emit("+" , argcount , "1" , argcount);
            emit("+" , "top" , argcount , "top");
            //setting sp
            emit("PI" , "atop" , "" , "sp");
            //setting atop
            emit("+" , "atop" , "2" , "atop");
        emit( "//" , "every thing is normal after func call:" , id , "");
        saveTmpVal(returnValue);
        return returnValue;

  /*  else{
        printf("No such Function!!! : %s\n" , id);
        errorFlag = true;
        return 0;
    }*/
}

char* mkCodeFndVarScp(int id){
    char * scopeId = (char*) malloc(sizeof(char) * 3);
    scopeId = intToString(id);
    
    char * loop = newQuad();
    char * outOfLoop = newQuad();
    char * loopLabel = (char* ) malloc( strlen(loop)+1 );
    strcpy(loopLabel , loop);
    strcat(loopLabel , ":");
    
    char * outOfLoopLabel = (char* ) malloc( strlen(outOfLoop)+1 );
    strcpy(outOfLoopLabel , outOfLoop );
    strcat(outOfLoopLabel , ":");
    
    char* vPointer = newVTemp();
    char* pPointer = newPTemp();
    char* value = newTemp();
    
    emit("=" , "atop" , "" , vPointer);
    emit(loopLabel , "" ,"" ,"");
    emit("PI" , vPointer , "" , pPointer);
    emit("PI" , pPointer , "" , value);
    emit("if" , value , "==" , scopeId);
    printf("emitted if %s\n", scopeId );
    emit("goto" , outOfLoop , "" , "");
    emit("+" , vPointer , "2" , vPointer );
    emit("goto" , loop , "" , "");
    emit(outOfLoopLabel , "" ,"" ,"");
    return pPointer;
}

char * lookup(char * name , struct SymbolTable* symbolTable , int * size ,int * scopeID){
    emit("//", "looking for:", name, "" );
    bool isInside=true;
    struct SymbolTable* currentTbl = symbolTable;
    
    while(currentTbl != NULL){
        
        struct SymbolTableNode* currentNode = currentTbl->head;
        // emit("//", "looking in", currentTbl->name, "" );
        printf("looking in %s\n", currentTbl->name);
        while(currentNode != NULL){
            //emit("//", "checking with", currentNode->name, "");
            
            if( strcmp( currentNode->name , name) == 0 )
            {
                *size = currentNode->size;
                emit("//", "the variable is found! id and size:" , intToString(currentTbl->ID) , intToString(*size));
                char* tblPtrTmp;
                
                if(*size >= 1 || *size==-2)
                {
                    *scopeID = currentTbl->ID;
                    if(isInside)
                    {
                        emit("//", "var is inside offset: ", intToString(currentNode->offset), "");
                        tblPtrTmp = newPTemp();
                        if(currentNode->offset>0){
                            emit("+" , "sp" , getOffset(currentNode->offset , currentTbl->argNum ) , tblPtrTmp );
                        }
                        else{
                           emit("-" , "sp" , getOffset(currentNode->offset , currentTbl->argNum ) , tblPtrTmp );
                        }
                        return tblPtrTmp;
                    }else{
                        emit("//", "var is outside offset: ", intToString(currentNode->offset), "");
                        tblPtrTmp = mkCodeFndVarScp(currentTbl->ID);
                        if(currentNode->offset>0){
                            emit("+" , tblPtrTmp , getOffset(currentNode->offset , currentTbl->argNum ) , tblPtrTmp );
                        }else{
                            emit("-" , tblPtrTmp , getOffset(currentNode->offset , currentTbl->argNum ) , tblPtrTmp );
                           }
                        return tblPtrTmp;
                    }
                }
                else{
                    printf("it is func!\n");
                    *scopeID = currentNode-> innerScope ->ID;
                    *size = 9 + (currentNode->innerScope->argNum);
                    return (currentNode->address);
                }
            }
           
            currentNode = currentNode->next;
        }
         
        currentTbl = currentTbl->outerScope;
       
        isInside = false;
        
    }
    printf("No such variable or Function!!! : %s\n" , name);
    *size = -1;
    *scopeID = -1;
    errorFlag = true;
    return "-";
}

char * assignBool(Node * trueList , Node * falseList , char* name , bool isVar , bool mkItEval)
{
    char* var;
    
    char * quad3 = newQuad();
    if(trueList!=0){
        char * quad1 = createLable();
        
        if(mkItEval){
            struct Eval* lvalueEval = idToEval(name);
            var = lvalueEval->str;
        }
        else{
            var = (char*) malloc(strlen(name));
            strcpy(var , name);
        }
        if(isVar)
            emit ( "IP" , "true" , "" , var );
        else
            emit ( "=" , "true" , "" , var );
        
        backpatch( trueList , quad1 );
        emit ( "goto" , quad3 , "" , "" );
    }
    if(falseList!=0)
    {
        char * quad2 = newQuad();
        char * colonQuad2 = (char *)malloc( strlen(quad2) );
        strcpy(colonQuad2 , quad2);
        strcat(colonQuad2 , ":");
        emit ( colonQuad2 , "" , "" , "" );
        if(mkItEval){
            struct Eval* lvalueEval = idToEval(name);
            var = lvalueEval->str;
        }
        else{
            var = (char*) malloc(strlen(name));
            strcpy(var , name);
        }
        if(isVar)
            emit ( "IP" , "false" , "" , var );
        else
            emit ( "=" , "false" , "" , var );
        backpatch( falseList , quad2 );
        emit ( "goto" , quad3 , "" , "" );
    }
    
    char * colonQuad3 = (char *)malloc( strlen(quad3) );
    strcpy(colonQuad3 , quad3);
    strcat(colonQuad3 , ":");
    emit ( colonQuad3 , "" , "" , "" );
    return var;
}


void writeTmpVar(FILE * f)
{
    char defStr[10000];
    strcpy(defStr , "double ");
    
    
    for(int i = 0 ; i<t ; i++)
    {
        snprintf(num,5,"%d",i);
        char * tmp = (char*) malloc( sizeof("t")+sizeof(num) );
        strcpy(tmp,  "t");
        strcat(tmp,num);
        strcat(defStr , tmp );
        strcat(defStr , " , " );
    }
    strcpy( defStr+strlen(defStr)-2 , ";\n" );
    if(t>0)
        fprintf(f,"%s", defStr );
    
    strcpy(defStr , "double ");
    
    for(int i = 0 ; i<tt ; i++)
    {
        snprintf(num,5,"%d",i);
        char * tmp = (char*) malloc( sizeof("*tt")+sizeof(num) );
        strcpy(tmp,  "*tt");
        strcat(tmp,num);
        strcat(defStr , tmp );
        strcat(defStr , " , " );
    }
    strcpy( defStr+strlen(defStr)-2 , ";\n" );
    if(tt>0)
       fprintf(f,"%s", defStr );
    
    strcpy(defStr , "double ");
    for(int i = 0 ; i<v ; i++)
    {
        snprintf(num,5,"%d",i);
        char * tmp = (char*) malloc( sizeof("**v")+sizeof(num) );
        strcpy(tmp,  "**v");
        strcat(tmp,num);
        strcat(defStr , tmp );
        strcat(defStr , " , " );
    }
    strcpy( defStr+strlen(defStr)-2 , ";\n" );
    if(v>0)
        fprintf(f,"%s", defStr );
    
    strcpy(defStr , "int ");
    for(int i = 0 ; i<I ; i++)
    {
        snprintf(num,5,"%d",i);
        char * tmp = (char*) malloc( sizeof("i")+sizeof(num) );
        strcpy(tmp,  "i");
        strcat(tmp,num);
        strcat(defStr , tmp );
        strcat(defStr , " , " );
    }
    strcpy( defStr+strlen(defStr)-2 , ";\n" );
    if(I>0)
       fprintf(f,"%s", defStr );
}

void mkCfile()
{
    FILE * fp;
   /* open the file for writing*/
   fp = fopen ("intermediate.c","w");
   fprintf(fp,"#include <stdbool.h>\n");
   fprintf(fp,"#include <stdlib.h>\n");
   fprintf(fp,"#include <stdio.h>\n");
   
   fprintf(fp,"double * top;\n");
   fprintf(fp,"double * sp;\n");
   fprintf(fp,"double ** atop;\n");
   
   writeTmpVar(fp);
   //writeVar( mainSymTbl , 8 , fp );
   //writeVar( mainSymTbl , 4 , fp );
   //writeVar( mainSymTbl , 1 , fp );
   
   fprintf(fp,"int main() {\n");
   fprintf(fp,"top = (double *) malloc(sizeof(double) *10001);\n");
   fprintf(fp,"atop = (double **) malloc(sizeof(double*) *1001);\n");
   fprintf(fp,"top = top + 10000;\n");
   fprintf(fp,"atop = atop + 1000;\n");
   fprintf(fp,"sp = top;\n\n");
   fprintf(fp,"*top = 0;\n\n");
   
   for(int i=0; i<=nextquad-1; i++){
       if( strcmp( quad_ruples[i][0] , "if" ) == 0 )
          fprintf(fp,"%s ( %s %s %s )\n",quad_ruples[i][0],quad_ruples[i][1],quad_ruples[i][2],quad_ruples[i][3]);
        else if(strcmp( quad_ruples[i][0] , "goto" ) == 0 )
            fprintf(fp,"\t\t%s %s; \n",quad_ruples[i][0],quad_ruples[i][1]);
        else if(strcmp( quad_ruples[i][0] , "int" ) == 0 )
            fprintf(fp,"\t\t%s %s; \n",quad_ruples[i][0],quad_ruples[i][1]);
        else if(strcmp( quad_ruples[i][0] , "=" ) == 0 )
            fprintf(fp,"\t%s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][0],quad_ruples[i][1]);
        else if(strcmp( quad_ruples[i][0] , "+" ) == 0 )
            fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
        else if(strcmp( quad_ruples[i][0] , ">>" ) == 0 )
            fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
        else if(strcmp( quad_ruples[i][0] , "<<" ) == 0 )
            fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
        else if(strcmp( quad_ruples[i][0] , "-" ) == 0 )
            fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
        else if(strcmp( quad_ruples[i][0] , "1-" ) == 0 )
            fprintf(fp,"\t%s = - %s; \n", quad_ruples[i][3] , quad_ruples[i][1]);
        else if(strcmp( quad_ruples[i][0] , "~" ) == 0 )
            fprintf(fp,"\t%s = ~ %s; \n", quad_ruples[i][3] , quad_ruples[i][1]);
        else if(strcmp( quad_ruples[i][0] , "|" ) == 0 )
            fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
        else if(strcmp( quad_ruples[i][0] , "&" ) == 0 )
            fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
        else if(strcmp( quad_ruples[i][0] , "*" ) == 0 )
            fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
        else if(strcmp( quad_ruples[i][0] , "%" ) == 0 )
            fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
        else if(strcmp( quad_ruples[i][0] , "/" ) == 0 )
            fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
        else if( strstr( quad_ruples[i][0] , ":" ) != 0 )
            fprintf(fp,"%s\n", quad_ruples[i][0]);
        else if(strcmp( quad_ruples[i][0] , "PI" ) == 0 )
            fprintf(fp,"\t%s = *%s; \n", quad_ruples[i][3] , quad_ruples[i][1] );
        else if(strcmp( quad_ruples[i][0] , "IP" ) == 0 )
            fprintf(fp,"\t*%s = %s; \n", quad_ruples[i][3] , quad_ruples[i][1] );
        else if(strcmp( quad_ruples[i][0] , "&&" ) == 0 )
            fprintf(fp,"\t%s = &&%s; \n", quad_ruples[i][3] , quad_ruples[i][1] );
        else if(strcmp( quad_ruples[i][0] , "//" ) == 0 )
            fprintf(fp,"//%s %s %s\n", quad_ruples[i][1] , quad_ruples[i][2] , quad_ruples[i][3] );
            else if(strcmp( quad_ruples[i][0] , "pr" ) == 0 ){
            fprintf(fp,"printf(\"%s\\n\", %s %s\n", "%lf",  quad_ruples[i][1] ,");" );
            }
        
    }
    fprintf(fp,"return 0;\n");
    fprintf(fp,"}\n");
 
   fclose (fp);
}


void defaultGotoGen(){
    char * tmp = newQuad();
    emit("goto",tmp,"","");
    emit(strcat(tmp,":") , "" ,"" ,"");
}



char * newQuad(){
    
  snprintf(num,5,"%d",q);
  char * tmp = (char*) malloc( sizeof("L")+sizeof(num) );
    strcpy(tmp,  "L");
  strcat(tmp,num);
  q++;
  return tmp;
  
}

char * newVTemp(){
    
  snprintf(num,5,"%d",v);
  char * tmp = (char*) malloc( sizeof("v")+sizeof(num) );
    strcpy(tmp,  "v");
  strcat(tmp,num);
  v++;
  return tmp;
}

char * newTemp(){
    
  snprintf(num,5,"%d",t);
  char * tmp = (char*) malloc( sizeof("t")+sizeof(num) );
    strcpy(tmp,  "t");
  strcat(tmp,num);
  tmp = mkStr(tmp);
  //printf("newTmp() : |%s|\n", tmp);
  enterVar( tmp, -2 , top(tblptrStack) );
  t++;
  return tmp;
}

char * newPTemp(){
    
  snprintf(num,5,"%d",tt);
  char * tmp = (char*) malloc( sizeof("tt")+sizeof(num) );
    strcpy(tmp,  "tt");
  strcat(tmp,num);
  tt++;
  return tmp;
}

char * newITemp(){
    
  snprintf(num,5,"%d",I);
  char * tmp = (char*) malloc( sizeof("i")+sizeof(num) );
    strcpy(tmp,  "i");
  strcat(tmp,num);
  I++;
  return tmp;
}

char* createLable(){
    char * tmp = newQuad();
    char *ttmp = mkStr(tmp);
    emit(strcat(ttmp,":") , "" ,"" ,"");
    return tmp;
}

struct Eval* strToEval(char* input){
    
    struct Eval* e = (struct Eval*) malloc (sizeof(struct Eval));
    char * string = (char*) malloc (strlen(input));
    strcpy(string , input);
    e->str = string;
    e->trueList = 0;
    e->falseList = 0;
    e->nextList = 0;
    e->quad = mkStr("");
    return e;
}

void mkSymTbl(char * name)
{
    struct SymbolTable* t = mkTable( top(tblptrStack) , name );
    push(t, tblptrStack);
}

struct SymbolTable* popTop(struct Stack* b ){
    pop(b);
    return top(b);
}

int main(){

    tblptrStack = createStack();
    printf("created\n");
    tblptrStack->top = NULL;
    yyin = fopen("input.txt", "r");
    printf("input opened \n");
    IDHead = (struct MyNode*)malloc(sizeof(struct MyNode));
    IDHead->data = NULL;
    IDHead->next = NULL;
    IDCurrent = IDHead;
    output = fopen("output.txt", "w");
   // symTable = fopen("symbolTable.txt", "w");
    yyparse();
    
    if(errorFlag)
    {
        printf("!!!!!!!!OH!!!!!!!!! <<<<ERROR>>>> !!!!!!!!OH!!!!!!!!!! \t :'( /_\\");
    }
    quad_display();
    mkCfile();
    printf("------<<<<<<<***** FINISH *****>>>>>>------ :D *_*");
    return 0;
}

/*int main(){
	yyin = fopen("input.txt", "r");
    if(yyin == NULL){
        printf("oops");
    }
    else{
        
    printf("yey");
    IDHead = (struct MyNode*)malloc(sizeof(struct MyNode));
    IDHead->data = NULL;
    IDHead->next = NULL;
    IDCurrent = IDHead;
    output = fopen("output.txt", "w");
    symTable = fopen("symbolTable.txt", "w");
    yyparse();
	fclose(output);
    fclose(symTable);
    }
	fclose(yyin);
    return 0;
}*/

void print(const char* string){
    printf( "\n%s\n", string);
}

void yyerror( char* error){
	fprintf(output, "Error: %s\n", error);
}
