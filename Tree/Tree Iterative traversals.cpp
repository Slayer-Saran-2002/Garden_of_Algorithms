#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include "Queue.h"
#include "Stack.h"

struct Node *root=NULL;

void Tcreate(){
	struct Node *p, *t;
	int x;
	struct Queue q;
	create(&q,100);
	root=(struct Node *)malloc(sizeof(struct Node));
	printf("Enter the Root value");
	scanf("%d",&root->data);
	root->lchild=root->rchild=NULL;
	enqueue(&q,root);
	while(!queuempty(q)){
		p=dequeue(&q); 
		printf("Enter Left child of %d : ",p->data);
		scanf("%d",&x);
		if(x!=-1){
			t=(struct Node *)malloc(sizeof(struct Node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			enqueue(&q,t);
		}
		printf("Enter Right child of %d : ",p->data);
		scanf("%d",&x);
		if(x!=-1){
			t=(struct Node *)malloc(sizeof(struct Node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->rchild=t;
			enqueue(&q,t);
		}
	}
}

void Ipreorder(struct Node *t){
	struct Stack st;
	CreateStack(&st,100);
	while(t!=NULL || !Isempty(st)){
		if(t){
			printf("%d ",t->data);
			push(&st,t);
			t=t->lchild;
		}
		else{
			t=pop(&st);
			t=t->rchild;
		}
	}
}
void Iinorder(struct Node *t){
	struct Stack st1;
	CreateStack(&st1,100);
	while(t!=NULL || !Isempty(st1)){
		if(t){
			push(&st1,t);
			t=t->lchild;
		}
		else{
			t=pop(&st1);
			printf("%d ",t->data);
			t=t->rchild;
		}
	}
}
void Ipostorder(struct Node *t){
	struct Stack st;
	Node *temp;
	CreateStack(&st,100);
	while(t!=NULL || !Isempty(st)){
		if(t){
			push(&st,t);
			t=t->lchild;
		}
		else{
			temp=pop(&st);
			if(temp>0){
				push(&st,-temp);
				t=((Node*)temp)->rchild;
			}
			else{
				printf("%d",((Node*)temp)->data);
				t=NULL;
			}
		}
	}
}
int main(){
	Tcreate();
	
	Ipostorder(root);
	return 0;
}

