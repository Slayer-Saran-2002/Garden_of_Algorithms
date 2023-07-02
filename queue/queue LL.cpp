#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x){
	struct Node *t = (struct Node *)malloc(sizeof(struct Node *));
	if(t==NULL){ //only will be null if heap is full
		printf("queue is full");
	}
	else{
		t->data=x;
		t->next=NULL;
		if(front==NULL) front =rear=t;
		else{
			rear->next=t;
			rear=t;
		}
	}
}
int dequeue(){
	int x=-1;
	if(front==rear){
		printf("queue is empty");
	}
	else{
		x=front->data;
		struct Node *p=front ;
		front=front->next;
		free(p);
	}
	return x;
}
void display(){
	struct Node *p=front;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int main(){
	enqueue(12);enqueue(45);enqueue(9);enqueue(5);enqueue(22);
	display();
	printf("%d\n",dequeue());
	display();
	return 0;
}
