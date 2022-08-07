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
int Delete(struct array *arr,int index){
	int x=arr->A[index];
	
	if(index<arr->length){
	for(int i=index;i<arr->length-1;i++){
		arr->A[i]=arr->A[i+1];
	}
	arr->length--;
	}
	return x;
}
int main()
{
	struct array arr = {{1,2,3,4,5},20,5};
	

	printf("%d\n",Delete(&arr,2));
	Display(arr);

 return 0;
}



