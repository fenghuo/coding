#include<iostream>
#include<vector>


using namespace std;

double cross(double x1,double y1,double x2,double y2,double a,double b){
	return ((x1-a)*(y2-b)-(x2-a)*(y1-b))/2;
}

double isIn(vector<double> x,vector<double> y, double a, double b){
	size_t l=x.size();
	double sign=0;
	for(size_t i=0;i<x.size();i++){
		auto t=cross(x[i],y[i],x[(i+1)%l],y[(i+1)%l],a,b);
		if(t && !sign)
			sign=t;
		else if(t && sign*t<0)
			return -1;	
	}
	return 1;

}

int main(){
	cout<<isIn({-1,0,1,0},{0,-1,0,1},0,1)<<endl;
	
}

