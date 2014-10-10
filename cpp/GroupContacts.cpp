

/**
 * 第二题是有这么一个class Contact，里面有一个String的name，和一个List<String>
 * 装着email address，是这个Contact有的address，用一个list装着是因为一个人有可
 * 能有多个email，现在给你an array of Contact，比如
 * #1 John [john@gmail.com]
 * #2 Mary [mary@gmail.com]
 * #3 John [john@yahoo.com]
 * #4 John [john@gmail.com, john@yahoo.com, john@hotmail.com]
 * #5 Bob [bob@gmail.com]
 * 现在我们知道如果email address相同的话，那么就说明是同一个人，现在要做的是根
 * 据这些email address，把同一个contact给group起来，生成一个List<List<Contact>>
 * ，比如我们就可以知道#1，#3，#4是同一个人。注意不能根据名字来group，因为有可
 * 能有相同名字的人，或者同一个人有可能有不同的名字来注册之类的。我给出了一个类
 * 似graph的解法。时间不够，就没有写code，只是把逻辑解释了一遍。
 */

#include<iostream>
#include<set>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

// 17:29
vector<set<string> > group(vector<string>&names, vector<vector<string> >&emails){
	unordered_map<string, int> emailIndex;
	unordered_map<int, set<string> > indexNames;
	vector<set<string> >res;
	for(size_t i=0;i<names.size();i++){
		auto&email=emails[i];
		if(email.size()){
			int index=i;
			for(auto&e:email){
				if(emailIndex.count(e))
					index=min(index,emailIndex[e]);
			}
			if(!indexNames.count(index))
				indexNames[index]={};
			for(auto&e:email){
				if(emailIndex.count(e)){
					int old=emailIndex[e];
					if(old!=index){
						emailIndex[e]=index;
						for(auto&n:indexNames[old])
							indexNames[index].insert(n);
						indexNames.erase(indexNames.find(e));
					}

				} else
					emailIndex[e]=index;
			}
			indexNames[index].insert(names[i]);

		}
	}
	for(auto&s:indexNames)
		res.emplace_back(s);
	return res;
}

int main(){


}
