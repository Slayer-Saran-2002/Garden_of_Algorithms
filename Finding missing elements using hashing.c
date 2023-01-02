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

void FindHash(struct array arr,int min,int max){
	int i=0;
	struct array arr2 ={{0},max,max};
	
	for(;i<arr.length;i++){
		arr2.A[arr.A[i]]++;
	}
	for(i=min;i<arr2.length;i++){
		if(arr2.A[i]==0)
		printf(" %d ",i);
	}
	
}

int main()
{
	struct array arr = {{9,6,11,2,5,8,14,16,22,4,5,19},20,12};
	FindHash(arr,2,22);

 return 0;
}
