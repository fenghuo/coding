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
	cout<<i<<" - "<<j<<endl;
	return j==lp?i-j:-1;
}

int match2(string s,string p){
	size_t l1=s.size(),l2=p.size();
	vector<size_t> T(l2,0);
	int k=0;
	for(size_t i=1;i<l2;i++){
		while(k && p[k]!=p[i])
			k=T[k-1];	
		if(p[k]==p[i])
			k++;
		T[i]=k;
	}	
	for(auto k:T)
		cout<<k<<" ";
	cout<<endl;
	k=0;
	for(size_t i=0;i<l1;i++){
		while(k && s[i]!=p[k])
			k=p[k];
		if(s[i]==p[k])
			k++;
		if(k==l2)
			return (i+1-k);
	}
	return -1;
}

int main(){
	string s="ababsdfsdfccababcadsfsdf";
	string p="abababcababa";
	cout<<match2(s,p)<<endl;
	cout<<(match2(s,p)==s.find(p))<<endl;
}
