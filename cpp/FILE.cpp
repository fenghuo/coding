#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<unordered_map>
#include<functional>
#include<priority_queue>


using namespace std;

struct String{
	string s;
	String(string s):s(s){}
	bool operator==(const String&right) const {
		return s==right.s;
	}
	ostream&operator<<(ostream&os){
		os<<s;
		return os;
	}
};

struct Hash{
	size_t operator()(const String&s) const{
		return 1;
	}
};

int main(){
	ifstream in("t");
	string s;
	int p=0;
	unordered_map<String,int,Hash> dict;
	priority_queue<string> pq;
	while(getline(in,s))
		pq.push(s);
	for(auto s:pq)
		cout<<s<<endl;
	return 0;
}
