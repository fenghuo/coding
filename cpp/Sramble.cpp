#include<iostream>
#include<string>

using namespace std;

    bool isScramble(string s1, string s2) {

        if(s1==s2)

            return true;

        if(s1.size()==1)

            return false;

        int l=s1.size();

        for(int i=0;i<=l;i++)

            if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i,l-i),s2.substr(i,l-i)))

                return true;

        return false;

    }

int main(){
	string s1="aa";
	string s2="ab";
	cout<<isScramble(s1,s2)<<endl;
}
