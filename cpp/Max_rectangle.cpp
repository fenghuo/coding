#include<iostream>
#include<vector>
#include<limits>

using namespace std;

    int maximalRectangle(vector<vector<char> > &matrix) {

        if(matrix.empty())return 0;

        int m=matrix.size(),n=matrix[0].size();

        if(!m)return 0;

        int i,j,mx=0;

        vector<vector<int> > h(m,vector<int>(n,0));

        vector<vector<int> > r(m,vector<int>(n,0));

        for(i=0;i<m;i++){

            for(j=n-1;j>=0;j--)

                if(matrix[i][j]=='0')

                    h[i][j]=0;

                else

                    h[i][j]=1+(j==n-1?0:h[i][j+1]);

        }

        for(j=0;j<n;j++)

            for(int i=m-1;i>=0;i--){

                if(matrix[i][j]=='0')

                    h[i][j]=0;

                else

                    h[i][j]=1+(i==m-1?0:h[i+1][j]);

            }

        for(i=0;i<m;i++)

            for(j=0;j<n;j++){

                int l=numeric_limits<int>::max();

                for(int k=0;k<r[i][j];k++){

                    l=min(l,h[i][j+k]);

		cout<<" --"<<endl;

                    mx=max(mx,l*(k+1));

                }

            }

        return mx;

    }

int main(){
	vector<vector<char> > t={{'1'}};
	cout<<maximalRectangle(t)<<endl;

}
