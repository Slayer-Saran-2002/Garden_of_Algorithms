#include <stdio.h>
#include <stdlib.h>
struct Node{
    int coeff;
    int exp;
    struct Node *next;
} *first = NULL, *second =NULL;

void create(){
    int i,sum;
    struct Node *t, *last;
    printf("Enter how many terms?");
    scanf("%d",&sum);
    printf("Enter coefficient along with exponent :");
    for(i=0;i<sum;i++){
        t=(struct Node* )malloc(sizeof(struct Node));
        scanf("%d%d",&t->coeff,&t->exp);
        t->next=NULL;
        if(first==NULL) first=last=t;
        else{
            last->next=t;
            last=t; 
        }
    }
}
void Display(struct Node* p ){
    while(p){
        printf("%dx%d + ",p->coeff,p->exp);
        p=p->next;
    }
}
long eval(struct Node* p, int  x){
	long sum=0;
	while(p){
		sum+=p->coeff*pow(x,p->exp);
		p=p->next;
	}
	return sum;
}
int main(){
    create();
    Display(first);
    printf("\n %ld \n",eval(first,1));
}
