#include "symbol_table.h"
#include <stdio.h>
#include <string.h>
struct Stack
{
    struct StackNode* top ;
};
struct StackNode
{
    struct SymbolTable* tblptr;
	struct StackNode* next;
};


struct Stack* createStack(){
	struct Stack* node = (struct Stack*) malloc(sizeof(struct Stack));
	return node;
}

void push (struct SymbolTable* tblptr , struct Stack* s)
{
	
	struct StackNode* node = (struct StackNode*) malloc(sizeof(struct StackNode));
	node->tblptr = tblptr;
	node->next = s->top;
    s->top = node;
	
}
/*  Function to delete an element from the stack */
struct SymbolTable* pop (struct Stack* s)
{
	if(s->top != NULL){
		struct SymbolTable* node = s->top->tblptr;
		s->top = s->top->next;
		return(node);
	}
    return NULL;
}

struct SymbolTable* top (struct Stack* s)
{
	if(s->top != NULL){
		struct SymbolTable* node = s->top->tblptr;
		return(node);
	}
    return NULL;
}
