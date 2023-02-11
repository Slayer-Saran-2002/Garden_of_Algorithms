#include<stdio.h>
#include<stdlib.h>

int *createArray(int n){
	int*p=(int*)malloc(n*sizeof(int));
	return p;//returning an array
}
int main()
{
	int * A;
	A=createArray(5);
	A[0]=1;A[1]=4;A[2]=6;A[3]=2;A[4]=5;
	for(int i=0;i<5;i++){
	printf("%d ",A[i]);
	}

return 0;
}

