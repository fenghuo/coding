#include<iostream>
#include<vector>
#include<string>
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

string find2(string&S){
	vector<char*> ps;
	for(auto&s:S)
		ps.push_back(&s);
	for(auto*s:ps)
		cout<<s<<endl;

	return S;
}

int main(){
	string s;
	while(getline(cin,s))
		cout<<find2(s)<<endl;
}
