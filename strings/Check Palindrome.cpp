#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
char *reverse(char A[]){
	char *B = (char *)malloc(50*sizeof(char));
	int i,j;
	for(i=0;A[i]!='\0';i++){
	}
	i--;
	for(j=0;i>=0;i--,j++){
		B[j]=A[i];
	}
	B[j+1]='\0';
	return B;
}

int main()
{
	char A[]="tattarrattat";
	//First method
//	char *B =reverse(A);
//	int i=0;
//	bool flag=true;
//	while(A[i]!='\0'){
//		if(A[i]!=B[i]){
//		flag= false;
//		printf("Not palindrome");
//		break;	
//		}
//		i++;
//	}
//	if(flag)
//	printf("This is palindrome");

	//second method  //
	int i,j;
	bool flag=true;
	
	for(i=0;A[i]!='\0';i++){
	}
	i--;
	
	for(j=0;i>j;i--,j++){
		if(A[i]!=A[j]){
		flag= false;
		printf("Not palindrome");
		break;	
		}
	}
	if(flag)
	printf("This is palindrome");
	
 return 0;
}



