// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#ifndef SOLUTIONS_LONGEST_NONDECREASING_SUBSEQUENCE_NLOGN_H_
#define SOLUTIONS_LONGEST_NONDECREASING_SUBSEQUENCE_NLOGN_H_

#include <algorithm>
#include <vector>
#include <limit>

using namespace std;

namespace LNS_nlogn {

// @include
int LongestNondecreasingSubsequence(const vector<int>& A) {
	int l=A.size();
	vector<int> seq(l+2, numeric_limits<int>::max());
	auto start = seq.begin();
	int mx=0;
	for(int i=0;i<l;i++){
		auto p=lower_bound(start,start+l+2);
		*p=A[i];
		mx=max(p-start+1,mx);
	}
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
