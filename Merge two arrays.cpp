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
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
struct array Merge(struct array arr1,struct array arr2)
{
	int arr3_lentgh=arr1.length+arr2.length;
	int arr3_size=arr1.size+arr2.size;
	struct array arr3={{0},arr3_size,arr3_lentgh};
	int i=0,j=0,k=0;
	while(i<arr1.length && j<arr2.length){
		if(arr1.A[i]<arr2.A[j])
		  arr3.A[k++]=arr1.A[i++];
		else
		  arr3.A[k++]=arr2.A[j++];  
	}
	for(;i<arr1.length;i++)
	  arr3.A[k++]=arr1.A[i];
	for(;j<arr2.length;j++)
	  arr3.A[k++]=arr2.A[j];
	return arr3;
}
int main()
{
	struct array arr1 = {{1,2,3,4,5,8,9,12,14,15,16},20,11};
	struct array arr2 = {{1,3,8,9,11,14,15,18,25,38},20,10};
	struct array arr3 = Merge(arr1,arr2);
	Display(arr3);

 return 0;
}



