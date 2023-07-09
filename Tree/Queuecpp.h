#ifndef Queuecpp_h
#define Queuecpp_h
#include <iostream>
using namespace std;

class Node{
public:
	Node *lchild;
	int data;
	Node *rchild;
};
class Queue{
private:
    int size;
    int front;
    int rear;
    Node **Q;
public:
	Queue(int s){size=s; Q=new Node*[size];front=rear =-1;};
	void enqueue(Node *x);
	Node* dequeue();
	int queuempty(){return front==rear;};
	
};


void Queue::enqueue(Node *x){
	if(rear==size-1){
		cout<<"queue is full";
	}
	else{
		rear++;
		Q[rear]=x;
	}

}
Node* Queue::dequeue(){
	Node* x=0;
	if(front==rear){
		cout<<"queue is empty";
	}
	else{
		front++;
		x=Q[front];
	}
	return x;
}

#endif


