#include <stdio.h>
#include <stdlib.h>
FILE* symTable;
char* intToString(int n);
int IDcounter=0;
struct SymbolTable{
	char* name;
	int ID;
	int localNum;
	int argNum;
	struct SymbolTable* outerScope;
	struct SymbolTableNode* head;
};

struct SymbolTableNode{
   // char* header;
	int offset;
	char* name;
	char * address;
	int size;
	struct SymbolTable* innerScope;
	char* returnType;
	struct SymbolTableNode* next;
};

void addNode(struct SymbolTable* symbolTable , struct SymbolTableNode* node);
struct SymbolTable* mkTable(struct SymbolTable* previous , char* tableName);
void enterVar(char* name , int size , struct SymbolTable* symbolTable);
void enterFunc(char* name , int size , char* returnType,  struct SymbolTable* innerScope , struct SymbolTable* symbolTable, char* address);
void symbolTablePrint(struct SymbolTable* symbolTable);
void allSymbolTablePrint(struct SymbolTable* symbolTable);
char * getOffset(int offset , int argNum);

//struct symbolTable* symbolTableAddScope(struct symbolTable** head, char* name, int nickName, int size, int outerScopenickName, struct scopeTable** scope, struct symbolTable* outerScope);
//void symbolTablePrint(struct symbolTable** head);
//void scopeTableAddVariable(struct scopeTable** head, char* name, char* variableType, int variableSize, int nickName);
//void scopeTableAddProcedure(struct scopeTable** head, char* name, int nickName);
//void scopeTableAddFunction(struct scopeTable** head, char* name, int nickName, char* returnType);
//void scopeTablePrint(struct scopeTable** head);
char* createString(char* string);

void addNode(struct SymbolTable* symbolTable , struct SymbolTableNode* node)
{
	struct SymbolTableNode* currentNode = symbolTable->head;
	if(currentNode == NULL){
		symbolTable->head = node;
	}else{
		while(currentNode->next != NULL) currentNode = currentNode->next;
		currentNode->next = node;
	}
}

struct SymbolTable* mkTable(struct SymbolTable* previous , char* tableName)
{
	struct SymbolTable* node = (struct SymbolTable*) malloc(sizeof(struct SymbolTable));
	node-> name = createString(tableName);
	node -> outerScope = previous;
	node -> head = NULL;
	node -> localNum = 0;
	node -> argNum = 0;
	node -> ID = IDcounter;
	IDcounter++;
	return node;
}

void enterParam(char* name , int size ,struct SymbolTable* symbolTable)
{
	struct SymbolTableNode* node = (struct SymbolTableNode*) malloc(sizeof(struct SymbolTableNode));
	node -> name = createString(name);
	node -> size = size;
	node -> innerScope = NULL;
	node -> returnType = "-";
	node -> next = NULL;
	(symbolTable -> argNum) ++;
	node -> offset = (symbolTable -> argNum);
	addNode(symbolTable , node);
}

void enterVar(char* name , int size ,struct SymbolTable* symbolTable)
{
	struct SymbolTableNode* node = (struct SymbolTableNode*) malloc(sizeof(struct SymbolTableNode));
	node -> name = createString(name);
	node -> size = size;
	node -> innerScope = NULL;
	node -> returnType = "-";
	node -> next = NULL;
	(symbolTable -> localNum) ++;
	node -> offset = -(symbolTable -> localNum);
	addNode(symbolTable , node);
}

void enterFunc(char* name , int size , char* returnType ,struct SymbolTable* innerScope , struct SymbolTable* symbolTable , char* address)
{
	printf("-------in enterFunc() nameis: %s\t symbolTable name is:%s\n",name, symbolTable->name);
	struct SymbolTableNode* node = (struct SymbolTableNode*) malloc(sizeof(struct SymbolTableNode));
	node -> name = createString(name);
	node -> size = size;
	node-> address = createString(address);
	node -> innerScope = innerScope;
	node -> returnType = returnType;
	node -> next = NULL;
	node -> offset = 0;
	addNode(symbolTable , node);
}


char* getEntityType(int size){
	switch(size)
	{
		case -2:
			return createString("Temprary Variable");
		case 0:
			return createString("Procedure");
		case -1:
			return createString("Function");
		default:
			return createString("Variable");
	}
}

char* getVariableType(int size){
	switch(size)
	{
		case 4:
			return createString("Int");
		case 8:
			return createString("Real");
		case 1:
			return createString("Bool");
		default:
			return createString("-");
	}
}

void symbolTablePrint(struct SymbolTable* symbolTable){
	fprintf(symTable, "---------------------------------------------------\n");
	
    if(symbolTable->outerScope != 0){
        
		fprintf(symTable,"Symboltable name: %s \t outer scope: %s \t ID: %d \t localvar num: %d \t arg num:%d\n",symbolTable->name,symbolTable->outerScope->name ,symbolTable->ID , symbolTable->localNum , symbolTable->argNum);
    }
	else
		fprintf(symTable,"Symboltable name: %s \t outer scope: %s\tID: %d\t localvar num: %d \t arg num:%d\n",symbolTable->name, "-" ,symbolTable->ID , symbolTable->localNum , symbolTable->argNum);
	fprintf(symTable, "Name\tEntity type\tVariable type\tVariable size\tOffset\treturnType\tinner Scope name\n");
	struct SymbolTableNode* currentNode = symbolTable->head;
	while(currentNode != NULL){
		//printf("----in symbolTablePrint() currentNode is not null");
		if(currentNode->innerScope != NULL)
			fprintf(symTable,"%s\t%s\t%s\t%d\t%d\t%s\t%s\n", currentNode->name,
		getEntityType(currentNode->size) , getVariableType(currentNode->size) , currentNode->size ,
		currentNode->offset, currentNode->returnType , currentNode->innerScope->name );
		else
			fprintf(symTable, "%s\t%s\t%s\t%d\t%d\t%s\t%s\n", currentNode->name,
		getEntityType(currentNode->size) , getVariableType(currentNode->size) , currentNode->size ,
		currentNode->offset, currentNode->returnType , "-" );
		
		currentNode = currentNode->next;
	}
	fprintf(symTable, "-----------------------------------------\n");
}

void allSymbolTablePrint(struct SymbolTable* symbolTable){
    symTable = fopen("symbolTable.txt", "w");
	symbolTablePrint(symbolTable);
	struct SymbolTableNode* currentNode = symbolTable->head;
	while(currentNode != NULL){
		if(currentNode->innerScope != NULL)
			allSymbolTablePrint(currentNode->innerScope);
		currentNode = currentNode->next;
		printf("currentNode go to next!\n");
	}
    fclose(symTable);
	
}

char * getOffset(int offset , int argNum){
	char * tmp = (char*) malloc(sizeof(char)*10);
	if(offset < 0 ){
		 tmp = intToString(-offset);
		return tmp;
	}
	 tmp = intToString( 3 + argNum - (offset-1));
	return tmp;
}

char* createString(char* string){
	char* pointer = (char*) malloc(strlen(string) + 1);
	strcpy(pointer, string);
	pointer[strlen(string)] = 0;
	return pointer;
}
char* intToString(int n) {
    char* ret = NULL;
    int numChars = 0;
    // Determine if integer is negative
    bool isNegative = false;
    if (n < 0) {
        n = -n;
        isNegative = true;
        numChars++;
    }
    // Count how much space we will need for the string
    int temp = n;
    do {
        numChars++;
        temp /= 10;
    } while ( temp );
    //Allocate space for the string (1 for negative sign, 1 for each digit, and 1 for null terminator)
     ret = (char *) malloc(sizeof(char)* (numChars + 1));
    ret[numChars] = 0;
    //Add the negative sign if needed
    if (isNegative) ret[0] = '-';
    // Copy digits to string in reverse order
    int i = numChars - 1;
    do {
        ret[i--] = n%10 + '0';
        n /= 10;
    } while (n);
    return ret;
}
