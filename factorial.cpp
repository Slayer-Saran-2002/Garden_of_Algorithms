#include<iostream>
using namespace std;
int fact (int n){		//Recursive
	if (n<=0){
		return 1;
	}
	return fact(n-1)*n;
}
int Ifact(int n){  //Iterative
	int s=1;
	for(int i=1;i<=n;i++)
	    s*=i;
	return s;
}
int main()
{
	cout<<Ifact(5);

return 0;
}

