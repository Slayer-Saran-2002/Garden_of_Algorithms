#include<iostream>
using namespace std;

double tailor(double x,double n)
{
	static double p=1,f=1,r;  //p= x power and f= factorial denominater
	if(n==0)
	  return 1;
	r=tailor(x,n-1);	
	p*=x;		//performing at returning time
	f*=n;
	return r+p/f;  // O(n2)
	
}

double Itailor(double x,double n)
{
	double p=1,f=1,r=1;
	for(int i=1;i<n;i++)
	{
		p*=x;
		f*=i;
		r+=p/f;
	}
	return r;
}

int main()
{
	cout<<Itailor(3,12);
return 0;
}

