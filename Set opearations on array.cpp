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

struct array* UnionSorted(struct array arr1,struct array arr2)
{
	struct array *arr3=(struct array *)malloc(sizeof(struct array));
	int i=0,j=0,k=0;
	while(i<arr1.length && j<arr2.length){
		if(arr1.A[i]<arr2.A[j])
		  arr3->A[k++]=arr1.A[i++];
		else if(arr1.A[i]>arr2.A[j])
		  arr3->A[k++]=arr2.A[j++];  
		else{
			arr3->A[k++]=arr1.A[i++];
			j++;
		}  
	}
	for(;i<arr1.length;i++)
	  arr3->A[k++]=arr1.A[i];
	for(;j<arr2.length;j++)
	  arr3->A[k++]=arr2.A[j];
	  
	arr3->length=k;  
	arr3->size=arr1.size+arr2.size;
	return arr3;
}

int main()
{
	struct array arr1 = {{1,2,3,4,5,8,9},20,7};
	struct array arr2 = {{1,7,8,9,11,14},20,6};
	struct array *arr3 = UnionSorted(arr1,arr2);
	Display(*arr3);

 return 0;
}



