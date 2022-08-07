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
	printf("\n");
}
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void LeftShift(struct array *arr){
	for(int i=0;i<arr->length-1;i++)
	  arr->A[i]=arr->A[i+1];
	arr->length--;  
}
void LeftRotate(struct array *arr){
	for(int i =0;i<arr->length-1;i++)
	  swap(&arr->A[i],&arr->A[i+1]);
}
int main()
{
	struct array arr = {{1,2,3,4,5,8,9,12,14,15,16,19,20,21,28,30,32,35},20,18};
	
   	LeftRotate(&arr);	
	Display(arr);
	


 return 0;
}

