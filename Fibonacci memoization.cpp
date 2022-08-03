#include<iostream>
#include<stdlib.h>
using namespace std;

int *createArray(int n){
	int*p=(int*)malloc(n*sizeof(int));
	return p;
}
//global dynamic array
int *F;	

int fib(int n)
{
	if(n<=1){
		F[n]=n;
		return n;
	}
	else{
		
		if(F[n-2]==-1)
			F[n-2]=fib(n-2);
		
		if(F[n-1]==-1)
			F[n-1]=fib(n-1);
		
		return F[n-2]+F[n-1];
	}

}
int main()
{
	// index of fibonacci series start from 0
	int n=70; 
	F=createArray(n);	
	//Assigning all elements -1
	for (int i=0;i<n;i++){		
		F[i]=-1;
	}	
	cout<<fib(n);

return 0;
}

