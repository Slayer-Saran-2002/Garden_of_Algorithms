#include<iostream>
using namespace std;

double tailorhorner(double x,double n)
{
	static double r;  
	if(n==0)
	  return 1;
	r=1+x/n;
	return(r*tailorhorner(x,n-1));  // O(n)
	
}
double Itailorhorner(double x,double n)
{
	double r=1;
	for(int i=n-1;i>0;i--)
	  r=1+(x/i)*r;
	return r;  
} 

int main()
{
	cout<<Itailorhorner(3,12);
return 0;
}

