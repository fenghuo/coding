#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<unordered_map>

using namespace std;

int main(){
	ifstream in("t");
	string s;
	int p=0;
	unordered_map<string,int> dict;
	while(getline(in,s))
		dict[s]=++p;
	for(auto entry:dict)
		cout<<entry.first<<" - "<<entry.second<<endl;
	return 0;
}
