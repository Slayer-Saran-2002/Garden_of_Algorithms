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

int Search(struct array arr,int key){
	for(int i=0;i<arr.length;i++){
		if(key==arr.A[i]){
			return i;
		}
	}
	return -1;
}

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int ImprovedSearch(struct array *arr,int key){
	for(int i=0;i<arr->length;i++){
		if(key==arr->A[i]){
			swap(&arr->A[i],&arr->A[i-1]);  //Transposition
//			swap(&arr->A[i],&arr->A[0]);    //Bring it to front
			return i;
		}
	}
	return -1;
}

int main()
{
	struct array arr = {{1,2,3,4,5,8,9,12,14,15,16,19,20,21,28,30,32,35},20,18};	
	
	printf("Element found at index %d\n",ImprovedSearch(&arr,32));
	Display(arr);
//	printf("Element found at index %d\n",ImprovedSearch(&arr,4));
//	Display(arr);
 return 0;
}



