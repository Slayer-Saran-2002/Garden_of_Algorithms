#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
} *first;
void Create(int* A,int n)
{
	int i;
	struct Node *t, *last;
	first = (struct Node*)malloc(sizeof(struct Node));
	first->data=A[0];
	first->prev=first->next=NULL;
	last=first;
	for(i=1;i<n;i++){
		t = (struct Node*)malloc(sizeof(struct Node));
        t->prev=last;
		t->data=A[i];
		t->next=NULL;
        last->next=t;
		last= t;
	}
}
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf(" %d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int Length(struct Node* p){
    int len=0;
    while(p){
        len++;
        p=p->next;
    }return len;
}
void Insert(struct Node* p,int index, int data){
    struct Node *t;
    int i;

    if(index<0 || index>Length(p)) return;

    t = (struct Node*)malloc(sizeof(struct Node));
    t->data=data;

    if(index==0){
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else{
        for(i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
        t->next->prev=t;
        t->prev=p;
    }
}
int Delete(struct Node *p,int pos)
{
    int x=-1;
    if(pos<1 || pos>Length(p))return -1;
    if(pos==1){
        first=first->next;
        first->prev=NULL;
        x=p->data;
        free(p);
    }
    else{
        int i;
        for(i=0;i<pos-1;i++)
            p=p->next;
        p->prev->next=p->next;
        x=p->data;
        if(p->next) p->next->prev=p->prev;
        free(p);
    }
    return x;
}
void Reverse(struct Node *p){
    struct Node *temp;
    while(p){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        if(p->prev==NULL)
            first=p;
        p=p->prev;
    }
}

int main(){
	int A[]= {1,2,3,4,5,7,9};
	Create(A,7);
    Insert(first,6,10);
    // printf("%d",Length(first));
    Display(first);
    Reverse(first);
    Display(first);
	return 0;
}