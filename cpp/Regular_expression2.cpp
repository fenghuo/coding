#include<iostream>

using namespace std;

    bool isMatch(const char *s, const char *p) {

        if(!*p)

            return !*s;

        if(p[1]=='*'){

            if(isMatch(s,p+2))

                return true;

            while(*s && (*s==*p || *s=='.')){

                if(isMatch(s+1,p+2))

                    return true;

                s++;       

            }

            return false;

        } else

            return ( (p[0]=='.' || p[0]==*s) && isMatch(s+1,p+1));

    }

int main(){

	cout<<isMatch("aa",".*")<<endl;
}
