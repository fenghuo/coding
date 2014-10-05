// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#ifndef SOLUTIONS_MERGE_SORTED_ARRAYS_H_
#define SOLUTIONS_MERGE_SORTED_ARRAYS_H_

#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using std::pair;
using std::priority_queue;
using std::vector;

struct Com{
	bool operator()(const pair<int,int>&l, const pair<int,int>&r){
		return l.first>r.first;
	}
};

vector<int> MergeArrays(const vector<vector<int>>& S) {
	priority_queue<pair<int,int>,vector<pair<int,int> >,Com> pq;
	vector<int> idx(S.size(),1);
	vector<int> res;
	for(size_t i=0;i<S.size();i++)
		pq.push({arr[0],i});
	while(pq.size()){
		auto&top=pq.top();
		pq.pop();
		res.push_back(top.first);
		auto i = top.second;
		idx[i]++;
		if(idx[i]<S[i].size())
			pq.push({S[i][idx[i]],i});
	}
	return res;
}

/* @include
struct Compare {
  bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return lhs.first > rhs.first;
  }
};

vector<int> MergeArrays(const vector<vector<int>>& S) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> min_heap;
  vector<int> S_idx(S.size(), 0);

  // Every array in S puts its smallest element in heap.
  for (int i = 0; i < S.size(); ++i) {
    if (S[i].size() > 0) {
      min_heap.emplace(S[i][0], i);
      S_idx[i] = 1;
    }
  }

  vector<int> ret;
  while (!min_heap.empty()) {
    pair<int, int> p = min_heap.top();
    ret.emplace_back(p.first);
    // Add the smallest element into heap if possible.
    if (S_idx[p.second] < S[p.second].size()) {
      min_heap.emplace(S[p.second][S_idx[p.second]++], p.second);
    }
    min_heap.pop();
  }
  return ret;
}
// @exclude
#endif  // SOLUTIONS_MERGE_SORTED_ARRAYS_H_

*/
