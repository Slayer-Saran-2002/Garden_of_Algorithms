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

return 0;
}

