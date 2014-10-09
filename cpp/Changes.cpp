#include<iostream>
#include<vector>

using namespace std;

void change(int sum, vector<int>&changes, vector<int>&path){
	if(sum==0){
		for(auto i:path)
			cout<<i<<" ";
		cout<<endl;
	} else if(sum>0){
		for(auto i:changes){
			if(path.size() && i<path.back())
				continue;
			path.push_back(i);
			change(sum-i,changes,path);
			path.pop_back();
		}
	}
} 

int main(){
	vector<int> changes={2,3,7};
	vector<int> path;
	change(20,changes,path);
}
