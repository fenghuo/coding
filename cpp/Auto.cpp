#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int*> s;
	for(int i=0;i<10;i++){
		s.push_back(&i);
		cout<<s[0]<<" "<<s.capacity()<<endl;
	}
	for(auto t:s)
		cout<<t<<",";

}
