#ifndef Queue_h
#define Queue_h

struct Node{
	Node *lchild;
	int data;
	Node *rchild;
};
struct Queue{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct Queue *q,int size){
	q->size=size;
	q->Q=(struct Node **)malloc(sizeof(struct Node *)*size);
	q->front= q->rear =-1;
}
void enqueue(struct Queue *q,Node *x){
	if(q->rear==q->size-1){
		printf("queue is full");
	}
	else{
		q->rear++;
		q->Q[q->rear]=x;
	}

}
Node* dequeue(struct Queue *q){
	Node* x=0;
	if(q->front==q->rear){
		printf("queue is empty");
	}
	else{
		q->front++;
		x=q->Q[q->front];
	}
	return x;
}
int queuempty(struct Queue q){
	if(q.front==q.rear) return 1;
	return 0;
}

#endif


