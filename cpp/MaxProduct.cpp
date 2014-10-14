#include<iostream>
#include<algorithm>
#include<limits>
#include<vector>

using namespace std;

    int maxProduct2(int A[], int n) {

        if(n==1)

            return A[0];

        vector<long> pre(n+1,1);

        for(int i=0;i<n;i++)

            pre[i+1]=pre[i]*A[i];

        long maxNeg=numeric_limits<long>::min(),minPos=numeric_limits<long>::max();

        long maxP=maxNeg;

        for(int i=0;i<=n;i++){

            if(pre[i]<0){

                if(pre[i]>maxNeg)

                    maxNeg=pre[i];

                else

                    maxP=max(maxP,pre[i]/maxNeg);

            } else {

                if(pre[i]<minPos)

                    minPos=pre[i];

                else

                    maxP=max(maxP,pre[i]/minPos);

            }

        }

        return (int)maxP;

    }

    int maxProduct(int A[], int n) {

        int last=0;

        int m=numeric_limits<int>::min();

        for(int i=0;i<=n;i++){

            if((i==n || A[i]==0) && i-last){

                m=max(m,maxProduct2(A+last,i-last));
		

                if(i!=n)

                    m=max(0,m);

                last=i+1;
	 }

        }

        return m;

    }

int main(){
	int a[]={0,-2,-9};
	cout<<maxProduct(a,2)<<endl;
}

