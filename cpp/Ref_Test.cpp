#include<iostream>

using namespace std;

int n=0;

int&get(){
	n++;
	int k=n;
	return k;
}

void t(){
	int k;
	for(int i=0;i<100;i++){
		k=get();
		k++;
		char a[100];
		cout<<k<<endl;
	}
}

int main(){
	t();
}

