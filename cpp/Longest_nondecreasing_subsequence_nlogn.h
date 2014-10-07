// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#ifndef SOLUTIONS_LONGEST_NONDECREASING_SUBSEQUENCE_NLOGN_H_
#define SOLUTIONS_LONGEST_NONDECREASING_SUBSEQUENCE_NLOGN_H_

#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

namespace LNS_nlogn {

// @include
// Long increasing one
int LongestNondecreasingSubsequence(const vector<int>& A) {
	vector<int> tail;
	for(int i=0;i<A.size();i++){
		auto p=lower_bound(tail.begin(), tail.end(),A[i]);
		if(p==tail.end())
			tail.emplace_back(A[i]);
		else
			*p=A[i];
	}
	return tail.size();
}

int A_LongestNondecreasingSubsequence(const vector<int>& A) {
	int l=A.size();
	vector<int> seq(l+2, numeric_limits<int>::max());
	auto start = seq.begin();
	int mx=0;
	for(int i=0;i<l;i++){
		auto p=upper_bound(start,start+l+2,A[i]);
		if(p-start && A[i]==*(p-1))continue;
		*p=A[i];
		mx=max((int)(p-start+1),mx);
	}
	for(int i=0;i<mx;i++)
		cout<<seq[i]<<" ";
	cout<<endl;
	return mx;
}


























int S_LongestNondecreasingSubsequence(const vector<int>& A) {
  vector<int> tail_values;
  for (const int& a : A) {
    auto it = upper_bound(tail_values.begin(), tail_values.end(), a);
    if (it == tail_values.end()) {
      tail_values.emplace_back(a);
    } else {
      *it = a;
    }
  }
  return tail_values.size();
}
// @exclude

}  // LNS_nlogn

#endif  // SOLUTIONS_LONGEST_NONDECREASING_SUBSEQUENCE_NLOGN_H_
