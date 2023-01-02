#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
struct array
{
	int A[40];
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
struct array* Difference(struct array arr1,struct array arr2)
{
	struct array *arr3=(struct array *)malloc(sizeof(struct array));
	int i=0,j=0,k=0;

	for(j=0;j<arr1.length;j++)
	{
		if(Search(arr2,arr1.A[j])==-1)
		{
			arr3->A[k++]=arr1.A[j];
		}
		arr3->length=k;	
	}
	
	return arr3;
}


int main()
{
	struct array arr1 = {{1,2,3,4,5,8,9},20,7};
	struct array arr2 = {{1,5,8,9,11,14},20,6};
	struct array *arr3 = Difference(arr1,arr2);
	Display(*arr3);

//	struct array arr1 = {{1,8,3,4,9,6,11,5,10,25},20,10};
//	struct array arr2 = {{1,7,4,10,6,8,6,14},20,8};
//	struct array *arr3 = Difference(arr1,arr2);
//	Display(*arr3);

 return 0;
}
