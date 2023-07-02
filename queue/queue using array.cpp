
#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q,int size){
	q->size=size;
	q->Q=(int*)malloc(sizeof(int)*size);
	q->front= q->rear =-1;
}
void enqueue(struct Queue *q,int x){
	if(q->rear==q->size-1){
		printf("queue is full");
	}
	else{
		q->rear++;
		q->Q[q->rear]=x;
	}

}
int dequeue(struct Queue *q){
	int x;
	if(q->front==q->rear){
		printf("queue is empty");
	}
	else{
		q->front++;
		x=q->Q[q->front];
	}
	return x;
}
void display(struct Queue q){
	for(int i=q.front+1;i<=q.rear;i++){
		printf("%d ",q.Q[i]);
	}printf("\n");
}

int main(){
	struct Queue que;
	int size;
	printf("Enter size of the queue: ");
	scanf("%d",&size);
	create(&que,size);
	enqueue(&que,52);
	enqueue(&que,9);
	enqueue(&que,26);
	
	display(que);
	printf("%d\n",dequeue(&que));
	enqueue(&que,13);
	display(que);
	
	
	return 0;
}
