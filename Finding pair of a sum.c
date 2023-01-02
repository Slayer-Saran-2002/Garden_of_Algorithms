#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct array
{
	int A[50];
	int size;
	int length;
};

int Max(struct array arr){
	int max=arr.A[0];
	int i;
	for(i=1;i<arr.length;i++)
	  if(arr.A[i]>max)
	    max=arr.A[i];
	return max;
}
void findsorted(struct array arr,int k){
	int i=0, j=arr.length-1;
	while(i<j){
		if(arr.A[i]+arr.A[j]==k){
			printf("%d , %d \n",arr.A[i],arr.A[j]);
			i++;
			j++;
		}
		else if(arr.A[i]+arr.A[j]<k)
		i++;
		else 
		j++;
	}
}

/*  Hashing Table or  Bitset  
	only works in array having no duplicate elements*/

void FindPair(struct array arr,int max,int k){
	int i;
	struct array hash ={{0},max,max};
	
	for(i=0;i<arr.length;i++){
		
		if(hash.A[k-arr.A[i]]!=0)
		printf(" %d , %d \n",arr.A[i],k-arr.A[i]);
		
		hash.A[arr.A[i]]++;
	}

}

int main()
{
 	struct array arr = {{5,9,7,4,1,2,11,6,},20,8};
 	
	struct array arr1 = {{1,2,3,4,5,6,7,8,9,10,12},20,11};
	FindPair(arr,Max(arr),9);
	findsorted(arr1,9);

 return 0;
}
