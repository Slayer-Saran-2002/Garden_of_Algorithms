#include<iostream>
using namespace std;

long long sum(int n){
//		recursive method

	if(n>0){
		return sum(n-1)+n;
	}
	else{
		return 0;
	}

//	return n*(n+1)/2;   // iterative method
}

int main()
{
	cout<<sum(9999999);

return 0;
}

