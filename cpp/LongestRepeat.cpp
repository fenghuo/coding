#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_map>

using namespace std;

struct Trie{
	unordered_map<char, Trie*> m;
};

string find(string&S){
	Trie root;
	int max=0;
	int start=0;
	vector<Trie*> pointers={};
	for(size_t i=0;i<S.size();i++){
		auto*curr=&root;
		for(int j=i;j<S.size();j++){
			if(curr->m.count(S[j])){
				if(j-i+1>max){
					max=j-i+1;
					start=i;
				}
			} else{
				curr->m[S[j]]=new Trie();
				pointers.push_back(curr->m[S[j]]);
			}
			curr=curr->m[S[j]];
		}
	}
	for(auto p:pointers)
		delete p;
	return S.substr(start,max);
}

struct Compare{
	bool operator()(const char*l, const char*r) const{
		return strcmp(l,r)<0;
	}
};

string find2(string&S){
	vector<char*> ps;
	int max=0,j=0;
	char* start;
	for(auto&s:S)
		ps.push_back(&s);
	sort(ps.begin(),ps.end(),Compare());
	for(size_t i=1;i<ps.size();i++){
		for(j=0;j<strlen(ps[i]);j++)
			if(ps[i][j]!=ps[i-1][j])
				break;	
		if(j>max){
			max=j;
			start=ps[i];
		}
	}
	return string(start,max);
}

int main(){
	string s;
	while(getline(cin,s))
		cout<<find2(s)<<endl;
}
