#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

struct MAP{
	unordered_map<char,MAP*> m;
};

class Trie{
public:
	Trie(){
		root = new MAP();
	}
	void insert(const string&s){
		auto* p = root;
		for(const auto & c:s){
			if(!p->m.count(c))
				(*p)[c]=new MAP();
			p=(*p)[c];
		}
	}
	string prefix(const string&s){
		string pre="";
		auto* p = root;
		for(const auto & c:s){
			if(p->m.count(c)){
				pre+=c;
				p=(*p)[c];
			} else
				break;
		}
		return pre;
	}
private:
	MAP*root;
};

int main(){
	Trie trie;
	string s1="abcdefgh";
	trie.insert(s1);
	cout<<trie.prefix("abc")<<endl;
}
