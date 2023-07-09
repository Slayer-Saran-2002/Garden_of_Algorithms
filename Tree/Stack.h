#include <stdio.h>
#include <stdlib.h>
#ifndef Stack_h
#define Stack_h
#include "Queue.h"
struct Stack{
    int size;
    int top;
    Node **S;
};
void CreateStack(struct Stack *stk,int size){
	stk->top=-1;
	stk->S=(Node**)malloc(sizeof(Node *)*stk->size);
}
void Display(struct Stack stk){
	
	for(int i=stk.top;i>=0;i--){
		printf("%d ",stk.S[i]);
	}
	printf("\n");
}
void push(struct Stack *stk, Node* x){
	if(stk->top==stk->size-1) printf("Stack overflow");
	else{
		stk->S[++stk->top]=x;
	}
}
Node* pop(struct Stack *stk){
	Node *x;
	if(stk->top==-1) printf("Stack underflow");
	else{
		x=stk->S[stk->top--];
	}
	return x;
}
int Isempty(struct Stack stk){
	return stk.top==-1;
}
int Isfull(struct Stack stk){
	return stk.top==stk.size-1;
}

#endif
