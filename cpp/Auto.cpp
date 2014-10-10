#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> s;
	for(int i=0;i<10;i++){
		s.push_back(i);
		cout<<&i<<endl;
	}
	for(auto t:s)
		cout<<t<<",";

}
