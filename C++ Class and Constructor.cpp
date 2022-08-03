#include<iostream>
using namespace std;

class Rectangle
{
	private:   // parameters
		int length;
		int bredth;
	public:
		Rectangle(int l,int b){   // Constructor
			length=l;
			this->bredth=b;   // pointer to current object //not neccessary to use
		}
		int area(){			// methods
			return length*bredth;
		}
		int perimeter(){
			return 2*(length+bredth);
		}
		~Rectangle(){}	// Destructor
		int getlength();
};
int Rectangle::getlength(){ //Defining functions outside the class
	return length;
}
int main()
{
	Rectangle r(10,5);
	cout<<r.area()<<endl<<r.perimeter()<<endl<<r.getlength();

return 0;
}

