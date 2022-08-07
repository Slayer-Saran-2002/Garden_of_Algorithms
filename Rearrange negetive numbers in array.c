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
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void Rearrange(struct array *arr){
	int i=0,j=arr->length-1;
	while(i<j){
		while(arr->A[i]<0)
			i++;
		while(arr->A[j]>=0)
		  j--;
  		if(i<j)swap(&arr->A[i],&arr->A[j]);
	}
}
int main()
{
	struct array arr={{-1,2,4,-8,9,12,-15,18,-20,-22},20,10};
	Rearrange(&arr);
	Display(arr);
	
	return 0;
}
