#include <iostream>
using namespace std;

class Node {
	public:
		char data;
		Node* next;
};
class Stack {
	private:
		Node* top;
	public:
		Stack() {
			top=NULL;
		}
		void push(char x);
		char pop();
		void Display();
		int Isbalanced(char *exp);
};
void Stack::push(char x) {
	Node* t = new Node;
	if(t==NULL) cout<<"stack overflow";
	else {
		t->data=x;
		t->next=top;
		top=t;
	}
}
char Stack::pop() {
	char x=-1;
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
int Stack::Isbalanced(char *exp){
	
	for(int i=0;exp[i]!='\0';i++){
		if(exp[i]=='('){
			push(exp[i]);
		}
		else if(exp[i]==')'){
			if(top==NULL)return 0;
			pop();
		}
	}
	return top?0:1;
}

int main(){
	Stack stk;
	char *exp ="(a+b)*(c-d)";
	cout<<stk.Isbalanced(exp);
	return 0;
}

