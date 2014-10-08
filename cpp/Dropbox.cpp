
#include<iostream>
#include<functional>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

string END_OF_FILE = "end";

struct File;
  // get line for File and return END_OF_FILE if reaches the end of File
  string getLine(const File File);
  // get File names from a directory
  vector<string>  getFileNamesFromRootPath(string rootPath);
  // get sub directories from a directory
  vector<string>  getSubDirectories(string rootPath);

  struct File{
    bool operator==(const File&r){
      File l=*this;
      string linput="",rinput="";
      while(linput!=END_OF_FILE && rinput!=END_OF_FILE){
        if(linput!=rinput)
          return false;
        linput=getLine(l);
        rinput=getLine(r);
      }
      return linput==rinput;
    }
  };

  // get line for File and return END_OF_FILE if reaches the end of File
  string getLine(const File File){return "";}
  // get File names from a directory
  vector<string>  getFileNamesFromRootPath(string rootPath){return {};}
  // get sub directories from a directory
  vector<string>  getSubDirectories(string rootPath){return {};}
  
  

  struct Hash{
    size_t operator()(const File&File){
      size_t hashCode=0;
      string input="";
	hash<string> string_hash;
      while(input!=END_OF_FILE){
        hashCode^=string_hash(input);
        input=getLine(File);
      }
      return hashCode;
    }
  };
  
  vector<vector<string> > findDuplicates(const vector<string>&names, const vector<File>&Files){
      unordered_map<File, vector<size_t>, Hash> dict;
      vector<vector<string> > res;
      for(size_t i=0;i<Files.size();i++){
          if(dict.count(Files[i])){
            auto group = dict[Files[i]];
            group.push_back(i);
            found = true;
          } else {
            dict[Files[i] = {i};
          }
      }
      for(auto entry:dict){
          vector<string> fnames;
          for(auto idx:entry.second)
            fnames.push_back(names[idx]);
          res.push_back(fnames);
      }
      return res;
  }
  
  void findAllFiles(string rootPath,vector<string>&names, vector<File>&Files){
    vector<string> this_names = getFileNamesFromRootPath(rootPath);
    vector<File> this_Files;
    vector<string> directPath = getSubDirectories(rootPath);
    for(auto name:names)
      Files.push_back(getFileFromFileName(name));
    names.append(this_names);
    files.append(this_Files);
    for(auto dir:directPath){
      findAllFiles(dir, names,Files);
    }
  }
  
  vector<vector<string>> findDuplicates(string rootPath){
    vector<string> names;
    vector<File> Files;
    findAllFiles(rootPath, names, Files);
    auto result = findDuplicates(names,Files);
    return result;
  }

int main(){

}
