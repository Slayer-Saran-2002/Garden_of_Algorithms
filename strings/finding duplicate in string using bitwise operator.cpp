#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char A[]="saranjeet";
	long int h=0,x=0;
	for(int i=0;A[i]!='\0';i++){
		x=1;
		x=x<<A[i]-97;
		if((h&x)>0)
			printf("%c is found duplicate \n",A[i]);	 
		else
			h=x|h; 
	}
}
