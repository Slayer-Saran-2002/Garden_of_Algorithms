#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
struct array
{
	int A[20];
	int size;
	int length;
};
void Display(struct array arr){
	for(int i=0;i<arr.length;i++)
			printf("%d ",arr.A[i]);
}
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void Reverse1(struct array *arr){
	int *B;
	int i,j;
	B=(int *)malloc(arr->length*sizeof(int));
	for(i=0,j=arr->length-1;i<arr->length;i++,j--)
	  B[i]=arr->A[j];
	for(i=0;i<arr->length;i++)
	  arr->A[i]=B[i]; 
}

void Reverse2(struct array *arr){
	int i,j;
	for(i=0,j=arr->length-1;i<arr->length/2;i++,j--)
	  swap(&arr->A[i],&arr->A[j]);
}
int main()
{
	struct array arr = {{1,2,3,4,5,8,9,12,14,15,16,19,20,21,28,30,32,35},20,18};
	Reverse1(&arr);	
	Display(arr);

 return 0;
}



