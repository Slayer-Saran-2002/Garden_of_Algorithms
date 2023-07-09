#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include "Queue.h"

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
void preorder(struct Node *p){
	if(p){
		printf("%d ",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
void inorder(struct Node *p){
	if(p){
		inorder(p->lchild);
		printf("%d ",p->data);
		inorder(p->rchild);
	}
}
void postorder(struct Node *p){
	if(p){
		postorder(p->lchild);
		postorder(p->rchild);
		printf("%d ",p->data);
	}
}
int main(){
	Tcreate();
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	inorder(root);
	return 0;
}

