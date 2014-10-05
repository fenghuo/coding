#include<iostream>
#include<string>
#include<vector>

using namespace std;

int match(string s,string p){
	int lp=p.size();
	vector<int> pv(lp,0);	
	for(size_t i=1;i<lp;i++){
		int last=i-1;
		while(last && p[pv[last-1]+1]!=p[i])
			last=pv[last];
		if(last==0)
			pv[i]=p[i]==p[0]?1:0;
		else
			pv[i]=pv[last]+1;

	}
	for(auto&k:pv)
		cout<<k<<" ";
	cout<<endl;
	int i=0,j=0;
	while(i<s.size() && j<lp){
		if(s[i]==p[j]){
			i++;j++;
		} else {
			j=pv[j];
			if(j==0)
				i++;
		}
	}
	return j==lp?-1:i-j;
}

int main(){
	string s="ababccababca";
	string p="ababca";
	cout<<match(s,p)<<endl;
}
