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
int isSorted(struct array arr){
	int i;
	for(i=0;i<arr.length-1;i++)
	  if(arr.A[i]>arr.A[i+1])
	    return 0;
    return 1;
}
int main()
{
	struct array arr={{1,2,4,8,9,12,15,18,20,22,},20,10};
	printf("%d",isSorted(arr));
	
	return 0;
}
