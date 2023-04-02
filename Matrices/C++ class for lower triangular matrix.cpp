#include<iostream>
using namespace std;
class LowerTriangular
{
	private :
		int *A;
		int n;
	public :
	    LowerTriangular()
	    {
	    	n=2;
			A=new int[n*(n+1)/2];
		}
		LowerTriangular(int n)
		{
			this->n = n;
			A=new int[n*(n+1)/2];
		}
		~LowerTriangular(){
			delete []A;
		}
		void Set(int i,int j,int x);
		int Get(int i,int j);
		void display();
};

void LowerTriangular::Set(int i,int j,int x){
	if(i>=j)
	A[i*(i-1)/2+(j-1)]=x; //row major formula
}
int LowerTriangular::Get(int i,int j){
	if(i>=j)
	return A[i*(i-1)/2+(j-1)];
	else 
	return 0;
}
void LowerTriangular::display(){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
  		if(i>=j)
		  cout<<A[i*(i-1)/2+(j-1)]<<" ";
		else
		  cout<<"0 ";	
		}
		cout<<endl;
	}
}
int main()
{
	int d;
	cout<<"Enter the dimenstion of the matrix : ";
	cin>>d;
	LowerTriangular T(d);
	int x;
	for (int i=1;i<=d;i++){
		for(int j=1;j<=d;j++)
		{
			cin>>x;
			T.Set(i,j,x);
		}
	}
	T.display();
	
return 0;
}

