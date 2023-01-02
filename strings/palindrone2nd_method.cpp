#include<iostream>
using namespace std;


void perm(char s[],int l,int h){
	int i;
	if(l==h){
	 cout<<s<<endl;
	}
	for(i=l;i<=h;i++){
		swap(s[l],s[i]);
		perm(s,l+1,h);
		swap(s[l],s[i]);
	} 
	
}
int main()
{
	char s[]="ABCD";
	perm(s,0,3);

return 0;
}

