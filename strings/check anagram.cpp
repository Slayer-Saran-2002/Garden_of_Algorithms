#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char A[]="decimal";
	char B[]="medical";
	int i,j;
	bool flag=true;
	int H[26]={0};
	for(i=0;A[i]!='\0';i++){
		H[A[i]-97]+=1;
	}
	for(j=0;B[j]!='\0';j++){
		H[B[j]-97]-=1;	
		if(H[B[j]-97]<0){
			printf("not anagram");
			flag=false;
			break;
		} 
	}
	
	if(flag&&i==j)
	printf("anagram");
	
}
