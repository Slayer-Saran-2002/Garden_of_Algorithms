#include<iostream>
using namespace std;

template<class T>
class Arithmatic
{
	private:
		T a;
		T b;
		
	public:
		Arithmatic(T a,T b){
			this->a =a;
			this->b = b; 
		}
		T add(){
			T c;
			c=a+b;
			return c;
		}
		T sub(){
			return a-b;
		}
		T mul();
};
template<class T>
T Arithmatic<T>:: mul(){
	T c = a*b;
	return c;
}

int main()
{
	Arithmatic<int> ar(10,5);
	cout<<ar.add()<<endl<<ar.sub()<<endl<<ar.mul()<<endl;
	
	Arithmatic<float> ar1(10.52,5.6);
	cout<<ar1.add()<<endl<<ar1.sub()<<endl<<ar1.mul()<<endl;

return 0;
}

