

/**
 * Get the list of duplicated files
 *
 */


#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

size_t getFileSize(const string&file){return 0;}
size_t readFile(const string&file){return 0;}
vector<string> getFiles(string s){return {"a","b"};}
vector<string> getDirs(string s){return {};}

struct File{
	string path;
	File(string s):path(s){}
	bool operator==(const File&file) const{
		ifstream left(path),right(file.path);
		string l="",r="";
		while(!left.eof() && !right.eof()){
			if(l!=r)
				return false;	
			getline(left,l);
			getline(right,r);
		}
		return left.eof() == right.eof();
	}
};

struct Hash{
	size_t operator()(const File&file) const{
		ifstream in(file.path);
		string line;
		size_t hashCode=0;
		hash<string> strHash;
		while(getline(in,line))
			hashCode^=strHash(line);
		return hashCode;
	}
};

vector<vector<string> > findDuplicatedFiles(const vector<string>&files){
	unordered_map<size_t, vector<string> > fileSize;
	vector<vector<string> > res;
	for(auto&path:files){
		size_t size= getFileSize(path);
		if(!fileSize.count(size))
			fileSize[size]={};
		fileSize[size].push_back(path);
	}
	for(const auto&entry:fileSize){
		if(entry.second.size()>1){
			auto&fs=entry.second;
			unordered_map<File,vector<string>, Hash> dict;
			for(auto&path:fs){
				File f(path);
				if(!dict.count(f))
					dict[f]={};
				dict[f].push_back(path);
			}
			for(auto&d:dict){
				auto&sameFiles=d.second;
				if(sameFiles.size()>1)
					res.push_back(sameFiles);
			}
		}
	}
	return res;
}

void getNames(string root, vector<string>&paths){
	auto files=getFiles(root);
	auto dirs=getDirs(root);
	paths.insert(paths.end(),files.begin(),files.end());
	for(auto dir:dirs)
		getNames(dir,paths);
}

vector<vector<string> > findDuplicatedFiles(string root){
	vector<string> names;
	getNames(root,names);
	return findDuplicatedFiles(names);
}

int main(){
	auto res=findDuplicatedFiles("/");
	for(auto&l:res){
		for(auto&s:l)
			cout<<s<<",";
		cout<<endl;
	}
}
