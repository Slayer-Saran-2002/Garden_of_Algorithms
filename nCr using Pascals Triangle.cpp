#include<iostream>
using namespace std;
int Ifact(int n){  //Iterative
	int s=1;
	for(int i=1;i<=n;i++)
	    s*=i;
	return s;
}
//pure formula
int ncr(int n, int r)
{
	int t0,t1,t2;
	t0=Ifact(n);
	t1=Ifact(r);
	t2=Ifact(n-r);
	return t0/(t1*t2);
}
// Pascal's Triangle
int C(int n, int r)
{
	if(r==0||r==n) return 1;
	else
	return C(n-1,r-1)+C(n-1,r);
}

int main()
{
	cout<<C(7,5);

return 0;
}

