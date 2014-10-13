#include<iostream>
#include<algorithm>

using namespace std;

int partition(int*A,int s,int e){
	if(s>=e)
		return e;
	else {
		int p=s;
		for(int i=s+1;i<e;i++)
			if(A[i]<A[p])
				swap(A[i],A[++p]);
		swap(A[i],A[p]);
	}
	return p;
}

void qsort(int * A, int s, int e){
	if(s<e){
		int p=partition(A,s,e);
		qsort(s,p);
		qsort(p+1,e);
	}

}

int main(){
	int a[]={2,3,4,2,1,2,4,5};
	qsort(a,0,8);
	for(int i=0;i<8;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
