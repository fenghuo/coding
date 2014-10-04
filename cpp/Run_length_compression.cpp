// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cassert>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <locale>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

using namespace std;

// @include
string Decoding(const string &s) {
	int count=0;
	string ans="";
	for(auto&c:s){
		if(isdigit(c))
			count=count*10+(c-'0');
		else{
			ans.append(count,c);
			count=0;
		}	
	}
	return ans;
}

string Encoding(const string &s) {
	int count=0;
	string ans="";
	for(size_t i=0;i<s.size();i++){
		if(i==0 || s[i]==s[i-1])
			count++;
		else{
			ans+=to_string(count)+s[i-1];
			count=1;
		}
	}
	if(count)
		ans+=to_string(count)+s.back();
	return ans;
}

string S_Decoding(const string &s) {
  int count = 0;
  string ret;
  for (const char &c : s) {
    if (isdigit(c)) {
      count = count * 10 + c - '0';
    } else {  // c is a letter of alphabet.
      ret.append(count, c);  // Adds count copies of c to the end of ret.
      count = 0;
    }
  }
  return ret;
}

string S_Encoding(const string &s) {
  int count = 1;
  stringstream ss;
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == s[i - 1]) {
      ++count;
    } else {
      // Found new character so write the count of previous character.
      ss << count << s[i - 1];
      count = 1;
    }
  }
  ss << count << s.back();
  return ss.str();
}
// @exclude

int main(int argc, char *argv[]) {
  if (argc == 3) {
    cout << Encoding(argv[1]) << ' ' << Decoding(argv[2]) << endl;
  }
  assert(string("4a1b3c2a") == Encoding("aaaabcccaa"));
  assert(string("") == Encoding(""));
  assert(string("11a") == Encoding("aaaaaaaaaaa"));
  assert(string("eeeffffee") == Decoding("3e4f2e"));
  assert(string("aaaaaaaaaaffffee") == Decoding("10a4f2e"));
  return 0;
}
