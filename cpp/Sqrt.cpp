#include<iostream>

using namespace std;

    int sqrt(int x) {

        if(x<=0)

            return 0;

        int root=1;

        int l=1,r=1;

        while(r*2<x)

            r<<=1;

        while(l<=r){

            long mid=(l+r)/2;

            if(mid*mid<x)

                l=mid+1;

            else if(mid*mid==x)

                return mid;

            else

                r=mid-1;

        }

        return r;

    }

int main(){
	
	cout<<sqrt(2147395599)<<endl;

}
