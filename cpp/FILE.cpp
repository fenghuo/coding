#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){
	ifstream in("t");
	string s;
	while(getline(in,s))
		cout<<s<<endl;
	return 0;
}
