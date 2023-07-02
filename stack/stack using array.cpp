#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    int *S;
};
void Create(struct Stack *stk){
	printf("Enter the size of the stack : ");
	scanf("%d",&stk->size);
	stk->top=-1;
	stk->S=(int*)malloc(sizeof(int)*stk->size);
}
void Display(struct Stack stk){
	
	for(int i=stk.top;i>=0;i--){
		printf("%d ",stk.S[i]);
	}
	printf("\n");
}
void push(struct Stack *stk, int x){
	if(stk->top==stk->size-1) printf("Stack overflow");
	else{
		stk->S[++stk->top]=x;
	}
}
int pop(struct Stack *stk){
	int x;
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
int peek(struct Stack stk,int pos)
{
	if(stk.top-pos+1<0) printf("Invalid Index");

	int x=stk.S[stk.top-pos+1];
	return x;
}
int Stacktop(struct Stack stk){
	if(!Isempty(stk))
	  return stk.S[stk.top];
	return -1;  
}
int main(){
	struct Stack stk;
	Create(&stk);
	push(&stk,1);
	push(&stk,3);
	push(&stk,5);	
	push(&stk,2);
	Display(stk);
	printf("%d\n",peek(stk,2));
	printf("%d\n",Stacktop(stk));
	printf("%d\n",pop(&stk));
	Display(stk);
	return 0;
}
