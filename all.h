#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "quad.h"
typedef struct node{
	int value;
	struct node * next;
}Node;

struct Eval {
		Node * trueList;
		Node * falseList;
		Node* nextList;
		char * quad;
		char * str;
	};
	
Node * mergeList(Node* t1 , Node * t2){
	Node* currentNode = t1;
	//printf("t1 is NULL:%x\n",t1);
	//printf("t2 is NULL:%x\n",t2);
	
	printf("begining of the mergeList:\n");
	if(t1 != NULL && t2 != NULL ){
		//printf("inside the if \t t1Value:%d \t\n", t1->value );
		while(currentNode->next != NULL){
			currentNode = currentNode->next;
		}
		printf("currentNode->next = t2\n");
		currentNode->next = t2;
		printf("merg is done - non of them is null!\n");
		return t1;
	}
	else if(t1 != 0)
	{
		printf("merg is done - second one is null!\n");
		return t1;
	}
	else{
		printf("merg is done - first one is null!\n");
		return t2;
	}
}

void backpatch(Node * t , char* lable){
	Node* currentNode = t;
	if(currentNode != NULL){
		while(currentNode->next != NULL){
			printf("first in while!\n");
			setLabel(currentNode->value,lable);
			printf("inside the while \t currentNode value is:%d\n",currentNode->value);
			printf("middle in the while\n");
			currentNode = currentNode->next;
			printf("inside the while \t currentNode value is:%d\n",currentNode->value);
			printf("currentNode go to next!\n");
			if(currentNode->next != NULL)
				printf("currentNode->next is not NULL!\n");
		}
		
		setLabel(currentNode->value,lable);
		printf("backpatch is done!\n");
	}
	
}

Node * mkList(int quad){
	Node * n = (Node*) malloc(sizeof(Node));
	n->value = quad;
	n -> next = 0;
	return n;
}

struct Eval * mkEval(Node * trueList , Node * falseList, Node* nextList, char * quad, char * str ){
	struct Eval * eval = (struct Eval *) malloc(sizeof(struct Eval));
	eval->trueList = trueList;
	eval->falseList = falseList;
	eval->nextList = nextList;
	eval->quad = quad;
	char * string = (char*) malloc(strlen(str));
	strcpy(string , str);
	eval->str = string;
	//printf("\n\n-\n%s\n",eval->str);
	return eval;
}
