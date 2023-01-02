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
	int i;
	for(i=0;i<arr.length;i++)
			printf("%d ",arr.A[i]);
}
void InsertSorted(struct array *arr,int x){
	if(arr->length==arr->size) // Overflow
	  return;
	int i=arr->length-1;
	while(arr->A[i]>x){
		arr->A[i+1]=arr->A[i];
		i--;
	}
	arr->A[i+1]=x;
	arr->length++;
}
int main()
{
	struct array arr={{1,2,4,8,9,12,15,18,20,22},20,10};
	InsertSorted(&arr,10);
	Display(arr);
	
	return 0;
}
