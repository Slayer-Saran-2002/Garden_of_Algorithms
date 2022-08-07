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
//Iterative
int BinarySearch(struct array arr ,int key){
	int l=0, h=arr.length-1, mid;
	while(l<=h)
	{
		mid=(l+h)/2;
	
		if(key==arr.A[mid]){
		  return mid;
		}
		else if(key<arr.A[mid]){
		  h=mid-1;
		}
		else{
		  l=mid+1;  
		}
	}
	return -1;
}
//Recursive
int RBinarySearch(struct array arr ,int key,int l,int h){
	if(l<=h){
		int mid=(l+h)/2;
		if(key==arr.A[mid])
		  return mid;
		else if(key<arr.A[mid]) 
		  return RBinarySearch(arr,key,l,mid-1);
		else
		  return RBinarySearch(arr,key,mid+1,h);
	}
	return -1;
}

int main()
{
	//Advantages -> takes less time than linear search, time complexity: O(log n)
	//Disadvantage -> array must be sorted
	struct array arr = {{1,2,3,4,5,8,9,12,14,15,16,19,20,21,28,30,32,35},20,18};	
	printf("Element found at index %d\n",BinarySearch(arr,4));

 return 0;
}



