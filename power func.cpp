#include<iostream>
using namespace std;

int power(int m, int n){  //Recursive minimized form
	if (n==0){
		return 1;
	}
	if(n%2==0)
	return power(m*m,n/2);
	else
	return power(m*m,(n-1)/2)*m;
}

int Ipower(int m,int n){  //Iterative
	int i,s=1;
	if(n%2!=0){
		s*=m;
 	    for (i=0;i<n/2;i++)
			s*=m*m;
	}
	if(n%2==0){
		for (i=0;i<n/2;i++)
			s*=m*m;
	}
	return s;
}

int main()
{
	cout<<Ipower(2,13);
return 0;
}

