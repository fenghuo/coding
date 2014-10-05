#include<iostream>

using namespace std;

int* countingSort(int*A,int n){
	int count[10]={};
	for(int i=0;i<n;i++)
		count[A[i]]++;
	for(int i=1;i<10;i++)
		count[i]+=count[i-1];
	int*res=new int[n];
	for(int i=0;i<n;i++)
		res[--count[A[i]]]=A[i];
	return res;
}

int main(){
	int A[20]={2,1,4,5,6,7,6,3,2,1,2,4,5,1,2,3,4};
	int * B=countingSort(A,20);
	for(int i=0;i<20;i++)
		cout<<B[i]<<" ";
	cout<<endl;
}
