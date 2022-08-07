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
void Append(struct array *arr,int n){
	if(arr->length!=arr->size){
		arr->A[arr->length++] = n;
	}
}
void Insert(struct array *arr,int index,int n){
	if(index>=0 && index<=arr->length && arr->length!=arr->size){
		for(int i=arr->length;i>=index;i--){
			arr->A[i]=arr->A[i-1];
		}
		arr->A[index]=n;
		arr->length++;
	}
}
int main()
{
	struct array arr = {{1,2,3,4,5},20,5};
	
//	for(int i=0;i<20;i++)
//	Append(&arr,i);
	Insert(&arr,5,10);
	Display(arr);

 return 0;
}



