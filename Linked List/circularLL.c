#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
    int data;
    struct Node *next;
} *head;
void Create(int* A,int n)
{
	int i;
	struct Node *t, *last;
	head = (struct Node*)malloc(sizeof(struct Node));
	head->data=A[0];
	head->next=head;
	last=head;
	for(i=1;i<n;i++){
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=last->next;
		last->next=t;
		last= t;
	}
}
void Display(struct Node *p){
	do{
		printf(" %d ",p->data);
		p=p->next;
	}while(p!=head);
	printf("\n");
}
int length(struct Node *p)
{
	int len=0;
	do
	{
		len++;
		p=p->next;
	} while (p!=head);
	return len;
}
void Insert(struct Node* p,int index,int data)
{
	if(index<0 || index>length(p)){return;}
	struct Node *t=(struct Node *)malloc(sizeof(struct Node));
	t->data=data;
	if(index==0){
		if(head==NULL)
		{
			head=t;
			head->next=head;
		}
		else{
			while(p->next!=head)p=p->next;
			p->next=t;
			t->next=head;
			head=t;
		}
	}
	else{
		int i;
		for(i=0;i<index-1;i++)p=p->next;
		t->next=p->next;
		p->next=t;
	}
}
int Delete(struct Node *p,int pos){
	int x;
	if(pos<1 || pos>length(p))return -1;
	struct Node* q;
	if(pos==1){
		while(p->next!=head)p=p->next;
		x=head->data;
		if(p==head){
			free(head);
			head=NULL;
		}
		else{
			p->next=head->next;
			free(head);
			head=p->next;
		}
	}
	else{
		int i;
		for(i=1;i<pos-1;i++){p=p->next;}
		q=p->next;
		x=q->data;
		p->next=q->next;
		free(q);
	}
	return x;
}

int main(){
	int A[]= {1,2,3,4,5,7,9};
	Create(A,7);
	Insert(head,0,10);
	Display(head);
	Delete(head,1);
	Display(head);
	return 0;
}
