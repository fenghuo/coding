#include<iostream>
#include<string>

using namespace std;

	bool check(string&s1,string&s2){
		int count[256]={0};
		for(auto c:s1)
			count[c]++;
		for(auto c:s2)
			count[c]++;
		for(int i=0;i<256;i++)
			if(!count[i])
				return false;
		return true;
		
	}

    bool isScramble(string s1, string s2) {
	cout<<s1<<" "<<s2<<endl;

        if(s1==s2)

            return true;

        if(s1.size()==1)

            return false;

	if(!check(s1,s2))
		return false;

        int l=s1.size();

        for(int i=1;i<l;i++)

            if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i,l-i),s2.substr(i,l-i)))

                return true;

        return false;

    }

int main(){
	string s1="ccbbcaccbccbbbcca";
	string s2="ccbbcbbaabcccbccc";
	cout<<isScramble(s1,s2)<<endl;
}
