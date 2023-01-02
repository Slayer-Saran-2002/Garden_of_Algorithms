#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char A[]="saran";
	char B[10];
	int i,j;
	//First method
	for(i=0;A[i]!='\0';i++){
	}
	i--;
	for(j=0;i>=0;i--,j++){
		B[j]=A[i];
	}
	B[j+1]='\0';
	printf("%s",B);
	//second method
//	char temp;
//	for(j=0;j>i;i--,j++){
//		temp=A[i];
//		A[i]=A[j];
//		A[j]=temp;
//	}
 return 0;
}



