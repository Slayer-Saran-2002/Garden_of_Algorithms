#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
struct array
{
	int A[20];
	int size;
	int lentgh;
};
int Get(struct array arr,int index){
	if(index>=0 && index<arr.lentgh)
	  return arr.A[index];
}
void Set(struct array *arr,int index,int value){
	if(index>=0 && index<arr->lentgh)
	  arr->A[index]=value;
}
int Max(struct array arr){
	int max=arr.A[0];
	for(int i=1;i<arr.lentgh;i++)
	  if(arr.A[i]>max)
	    max=arr.A[i];
	return max;
}
int Min(struct array arr){
	int min=arr.A[0];
	for(int i=1;i<arr.lentgh;i++)
	  if(arr.A[i]<min)
	    min=arr.A[i];
	return min;
}
int main()
{
	struct array arr = {{8,9,3,6,1,5,4,},20,7};
	printf("%d\n",Max(arr));
	printf("%d\n",Min(arr));
 return 0;
}



