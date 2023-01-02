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

/*  Hashing Table or  Bitset  */

void FindDuplicateHash(struct array arr,int max){
	int i;
	struct array hash ={{0},max,max};
	
	for(i=0;i<arr.length;i++){
		hash.A[arr.A[i]]++;
	}
	for(i=0;i<=hash.length;i++){
		if(hash.A[i]>1)
		printf(" %d - %d \n",i,hash.A[i]);
	}
	/* for finding occurance hash.A[i]>0 condition should be used */
}

int main()
{
	struct array arr = {{5,9,9,4,5,11,9,7,2,7,8,5,11,8},20,14};
	FindDuplicateHash(arr,11);

 return 0;
}
