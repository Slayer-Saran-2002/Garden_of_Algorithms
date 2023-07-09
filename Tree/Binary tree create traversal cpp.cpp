#include <iostream>
#include "Queuecpp.h"
using namespace std;
class Tree{
public:	
	Node *root;
	Tree(){root=NULL;};
	void Tcreate();
	void preorder(Node *p);
	void postorder(Node *p);
	void inorder(Node *p);
	void levelorder(Node *p);
	void height();
	
};

void Tree::Tcreate()
{
	Node *p, *t;
	int x;
	Queue q(100);
	root=new Node;
	cout<<"Enter the Root value";
	cin>>root->data;
	root->lchild=root->rchild=NULL;
	q.enqueue(root);
	
	while(!q.queuempty()){
		p=q.dequeue(); 
		cout<<"Enter Left child of "<<p->data<<": ";
		cin>>x;
		if(x!=-1){
			t=new Node;
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			q.enqueue(t);
		}
		cout<<"Enter right child of "<<p->data<<": ";
		cin>>x;
		if(x!=-1){
			t=new Node;
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->rchild=t;
			q.enqueue(t);
		}
	}
}
void Tree::preorder(Node *p){
	if(p){
		cout<<p->data<<" ";
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
void Tree::inorder(Node *p){
	if(p){
		inorder(p->lchild);
		cout<<p->data<<" ";
		inorder(p->rchild);
	}
}
void Tree::postorder(Node *p){
	if(p){
		postorder(p->lchild);
		postorder(p->rchild);
		cout<<p->data<<" ";
	}
}
int main(){
	Tree T;
	T.Tcreate();
	T.preorder(T.root);
	cout<<endl;
	T.postorder(T.root);
	cout<<endl;
	T.inorder(T.root);
	return 0;
}

