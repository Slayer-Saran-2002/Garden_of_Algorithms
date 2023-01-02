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

void Find(struct array arr,int start){
	int i=0;
	for(;i<arr.length;i++){
		if (arr.A[i]-i != start){
			while(arr.A[i]-i>start){
			  printf(" %d ",start+i);
			  start++;
			}
		}
	}
}

int main()
{
	struct array arr = {{1,2,5,9,10,15,17},20,7};
	Find(arr,1);

 return 0;
}

