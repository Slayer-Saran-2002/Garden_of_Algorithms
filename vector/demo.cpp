#include<iostream>
#include <vector>
using namespace std;

int main()
{
	// fill constructor
	vector<int> arr(10,0);
	
	//vector<int> arr = {1,2,5,7,8,9}
	
	arr.clear();
	
	arr.push_back(1);arr.push_back(2);arr.push_back(4);arr.push_back(5);arr.push_back(6);
	
	arr.pop_back();
	arr.insert(2,3);
	
	//print all elements
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<endl;
	}

return 0;
}

