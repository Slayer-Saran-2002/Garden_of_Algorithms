#include <iostream>
#include <string.h>
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
		char StackTop();
		int Isempty();
		char* Convert(char *infix);
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
char Stack::StackTop() {
	return top->data;

}
int IsOperand(char x) {
	if(x=='+' || x=='-' || x=='*' || x=='/'|| x=='^'|| x=='('|| x==')') return 0;
	return 1;
}
int Outprece(char x) {
	if(x=='+' || x=='-') return 1;
	else if(x=='*' || x=='/') return 3;
	else if(x=='^') return 6;
	else if(x=='(') return 7;
	else if(x==')')return 0;
}

int Inprece(char x) {
	if(x=='+' || x=='-') return 2;
	else if(x=='*' || x=='/') return 4;
	else if(x=='^') return 5;
	else if(x=='(') return 0;
	else return -1; 
}
char* Stack::Convert(char *infix) {
	char *postfix = new char(strlen(infix)+2);
	int i=0,j=0;
	while(infix[i]!='\0') {
		if(IsOperand(infix[i])) {
			postfix[j++]=infix[i++];
		} 
		else {
			if(Outprece(infix[i])==Inprece(StackTop())) {
				pop();
				i++;
		    }
			if(Outprece(infix[i])>Inprece(StackTop())) {
				push(infix[i++]);
			}
			else{
				postfix[j++]=pop();
			}
		}
	}
	while(!Isempty()) {
		postfix[j++]=pop();
	}
	postfix[j]='\0';
	return postfix;

}


int main() {
	Stack stk;
	stk.push('#'); //pushed because if initially stack remain empty then stacktop function will not work and our program will not work
//	char *exp ="a+b*c-d/e+f";
	char *exp = "((a+b)*c)-d^e^f";
	cout<<stk.Convert(exp);
	return 0;
}

