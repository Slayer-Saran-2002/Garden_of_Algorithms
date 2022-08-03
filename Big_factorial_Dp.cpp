#include<iostream>
using namespace std;
#define MAX 500
int multiply(int x ,int arr[],int arr_size);
void factorial(int n){
	int arr[MAX];
	arr[0]=1;
	int arr_size=1;
	for(int p=2;p<=n;p++){
		arr_size=multiply(p,arr,arr_size);
	}
	cout<<"Factorial of the given number "<<n<<" is :";
	for(int i =arr_size-1;i>=0;i--){
		cout<<arr[i];
	} 
}
int multiply(int x ,int arr[],int arr_size){
	int carry=0;
	for(int i=0 ;i<arr_size;i++){
		int product = arr[i]*x+carry;
		arr[i]=product%10;
		carry=product/10;
	}
	
	while(carry){
		arr[arr_size]=carry%10;
		carry=carry/10;
		arr_size++;
	}
	return arr_size;
}
int main()
{
	int n;
	cin>>n;
	factorial(n);

return 0;
}

