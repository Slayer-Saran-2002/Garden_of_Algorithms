#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void RDisplay(struct Node *p)
{
    if (p != NULL)
    {
        RDisplay(p->next);
        printf("%d ", p->data);
    }
}
int count(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}
int Rcount(struct Node *p)
{
    if (p != NULL)
        return Rcount(p->next) + 1;
    else
        return 0;
}
int sum(struct Node *p)
{
    int s = 0;
    while (p != NULL)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}
int Rsum(struct Node *p)
{
    if (p == NULL)
        return 0;
    else
        return Rsum(p->next) + p->data;
}
int Max(struct Node *p)
{
    int max = INT_MIN;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}
int RMax(struct Node *p)
{
    int x = 0;
    if (p == 0)
        return INT_MIN;
    x = RMax(p->next);
    if (x > p->data)
        return x;
    else
        return p->data;
}
struct Node *LSearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p != NULL)
    {
        if (key == p->data)
        {
            if (p != first)
            {
                q->next = p->next;
                p->next = first;
                first = p;
            }
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}
struct Node *RSearch(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return RSearch(p->next, key);
}
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > count(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}
void SortedInsert(struct Node *p, int x)
{
	 struct Node* t,*q=NULL;
	 t = (struct Node *)malloc(sizeof(struct Node));
	 t->data=x;
	 t->next=NULL;
	 if(!first){
	 	first = t;
	 } 	
	 else{
	 while(p && p->data<x){
	 	q=p;
	 	p=p->next;
	 }
	 if(p==first){
	 	t->next=first;
	 	first=t;
	 }
	 else{
  	 t->next=q->next;
	 q->next=t;
	 }
	 }
}
int Delete(struct Node* p,int pos){
	struct Node* q=p;
	int i,x;
	if( pos<1 || pos>count(p))
		return -1;
	if(pos==1){
		x=p->data;
		first=p->next;
		free(p);
		return x;
	}
	else{
		for(i=0;i<pos-1 && p;i++){
			q=p;
			p=p->next;
		}
		x=p->data;
		q->next=p->next;
	 	free(p);
		return x;	
	}
}
int IsSorted(struct Node* p)
{
	int x=p->data;
	while(p){
		if(x>p->data)
			return 0;
		x=p->data;
		p=p->next;	 
	}
	return 1;
}
void RemoveDuplicates(struct Node* p)
{
	struct Node* q=p->next;
	if(!IsSorted(p)){return;}/*only works on sorted list*/
	while(q){
		if(p->data!=q->data){
			p=q;
			q=q->next;
		}
		else{
			p->next=q->next;
			free(q);
			q=p->next;
			
		}
	}
	
}
void Reverse1(struct Node* p)
{	
	/* Reversing Elements not feasible way*/
	int *A,i=0;
	A=(int *)malloc(sizeof(int)*count(p));
	struct Node* q=p;
	while(q!=NULL){
		A[i]=q->data;
		q=q->next;
		i++;
	}
	i--;
	while(p!=NULL){
		p->data=A[i--];
		p=p->next;
	}
} 
void Reverse2(struct Node *p)
{	
	/*Reversing Links with sliding pointers*/
	struct Node *q=NULL,*r=NULL;
	while(p!=NULL){
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	first=q;
}
void Reverse3(struct Node *q,struct Node *p)
{
	/*Recursive*/
	if(p){
		Reverse3(p,p->next);
		p->next=q;
	}
	else{
		first=q;
	}
}
int main()
{
    int A[] = {10, 20, 30, 40, 50,50,60};
    create(A, 7);
    Reverse3(NULL,first);
	Display(first);
    
    
    return 0;
}
