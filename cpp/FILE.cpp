#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<unordered_map>
#include<functional>
#include<queue>


using namespace std;

struct String{
	string s;
	String(string s):s(s){}
	bool operator==(const String&right) const {
		return s==right.s;
	}
	friend ostream&operator<<(ostream&os, String&S){
		os<<S.s;
		return os;
	}
};

struct Hash{
	size_t operator()(const String&s) const{
		return 1;
	}
};

struct Compare{
	bool operator()(const string&l, const string&r){
		return l<r;
	}
};

int main(){
	ifstream in("t");
	string s;
	int p=0;
	unordered_map<String,int,Hash> dict;
	priority_queue<string, vector<string>,Compare> pq;
	String T("ts");
	cout<<T<<endl;
	while(getline(in,s))
		pq.push(string(s));
	while(!pq.empty()){
		cout<<pq.top()<<endl;
		pq.pop();
	}
	return 0;
}
