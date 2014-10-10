#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> s={1,2,3,4,5};
	for(auto t:s)
		t=1;
	for(auto t:s)
		cout<<t<<",";

}
