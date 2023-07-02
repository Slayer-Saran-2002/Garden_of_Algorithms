#include <iostream>
#include <string.h>
#include <cmath>

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
		int StackTop();
		int Isempty();
		int EvaluatePostfix(char *infix);
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
int Stack::Isempty() {
	if(top==NULL) return 1;
	return 0;
}
void Stack::Display() {
	Node* t=top;
	while(t) {
		cout<<t->data<<" ";
		t=t->next;
	}
	cout<<endl;
}
int Stack::StackTop() {
	return top->data;

}
int IsOperand(char x) {
	if(x=='+' || x=='-' || x=='*' || x=='/'|| x=='^'|| x=='('|| x==')') return 0;
	return 1;
}

int Stack::EvaluatePostfix(char* exp)
{
	int i,x1,x2,r;
	for(i=0;exp[i]!='\0';i++){
		if(IsOperand(exp[i])) push(exp[i]-'0');
		else{
			x2=pop();x1=pop();
			switch (exp[i]){
				case '+': r=x1+x2; break;
				case '-': r=x1-x2; break;
				case '*': r=x1*x2; break;
				case '/': r=x1/x2; break;
				case '^': r=pow(x1,x2);break;
			}
			push(r);
		}
	}
	return pop();
}


int main() {
	Stack stk;
	char *exp = "52+4*321^^-";
	cout<<stk.EvaluatePostfix(exp);
	return 0;
}

