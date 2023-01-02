#include<iostream>
using namespace std;
void Toh(int n, int A, int B,int C)
{
	if(n>0)
	{
		Toh(n-1,A,C,B);
		cout<<"Move disk from "<<A<<" to "<<C<<endl;
		Toh(n-1,B,A,C);
	}
}
int main()
{
	Toh(2,1,2,3);

return 0;
}

