#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<unordered_map>
#include<functional>

using namespace std;

struct Hash{
	size_t operator()(const string&s) const{
		return 1;
	}
};

int main(){
	ifstream in("t");
	string s;
	int p=0;
	unordered_map<string,int,Hash> dict;
	while(getline(in,s))
		dict[s]=++p;
	for(auto entry:dict)
		cout<<entry.first<<" - "<<entry.second<<" : "<<dict.hash_function()(entry.first)<<endl;
	return 0;
}
