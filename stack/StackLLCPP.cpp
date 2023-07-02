#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
};
class Stack {
	private:
		Node* top;
	public:
		Stack() {
			top=NULL;
		}
		void push(int x);
		int pop();
		void Display();
};
void Stack::push(int x) {
	Node* t = new Node;
	if(t==NULL) cout<<"stack overflow";
	else {
		t->data=x;
		t->next=top;
		top=t;
	}
}
int Stack::pop() {
	int x=-1;
	if(top==NULL) cout<<"stack underflow";
	else {
		Node* t=top;
		top=top->next;
		x=t->data;
		delete t;
	}
	return x;
}
void Stack::Display(){
	Node* t=top;
	while(t){
		cout<<t->data<<" ";
		t=t->next;
	}
	cout<<endl; 	
}

int main(){
	Stack stk;
	stk.push(11);
	stk.push(22);
	stk.push(33);	
	stk.Display();
	cout<<stk.pop()<<endl;
	stk.Display();
	return 0;
}

