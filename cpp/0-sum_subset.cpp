// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;

using namespace std;

// @include
// 22:19
vector<int> find_0_sum_subset(const vector<int> &A) {
	int n=A.size();
	vector<int> idx(n,-1);
	vector<int> sum(n+1,0);
	vector<int> ans;
	for(int i=1;i<=n;i++)
		sum[i]+=A[i-1]+sum[i-1];
	for(int i=1;i<=n;i++){
		if(sum[i]%n==0)
		{
			ans.resize(i);
			copy(A.begin(),A.begin()+i,ans.begin());
			break;
		} else {
			int mod = sum[i]%n;
			if(idx[mod] >= 0) {
				ans.resize(i-idx[mod]);
				copy(A.begin()+idx[mod],A.begin()+i,ans.begin());
				break;
			} else 
				idx[mod] = i;
		}
	}
	return ans;
}
vector<int> A_find_0_sum_subset(const vector<int> &A) {
	int n=A.size();
	vector<int> idx(n,-1);
	vector<int> sum(n,0);
	vector<int> ans;
	for(int i=0;i<n;i++)
		sum[i]+=A[i]+(i==0?0:sum[i-1]);
	for(int i=0;i<n;i++){
		if(sum[i]%n==0)
		{
			ans.resize(i+1);
			copy(A.begin(),A.begin()+i+1,ans.begin());
			break;
		} else {
			int mod = sum[i]%n;
			if(idx[mod] >= 0) {
				ans.resize(i-idx[mod]);
				copy(A.begin()+idx[mod]+1,A.begin()+i+1,ans.begin());
				break;
			} else 
				idx[mod] = i;
		}
	}
	return ans;
}
vector<int> S_find_0_sum_subset(const vector<int> &A) {
  vector<int> prefix_sum(A);
  for (int i = 0; i < prefix_sum.size(); ++i) {
    prefix_sum[i] += i > 0 ? prefix_sum[i - 1] : 0;
    prefix_sum[i] %= A.size();
  }

  vector<int> table(A.size(), -1);
  for (int i = 0; i < A.size(); ++i) {
    if (prefix_sum[i] == 0) {
      vector<int> ans(i + 1);
      iota(ans.begin(), ans.end(), 0);
      return ans;
    } else if (table[prefix_sum[i]] != -1) {
      vector<int> ans(i - table[prefix_sum[i]]);
      iota(ans.begin(), ans.end(), table[prefix_sum[i]] + 1);
      return ans;
    }
    table[prefix_sum[i]] = i;
  }
  // @exclude
  return {};  // it should not happen
  // @include
}
// @exclude

void check_ans(const vector<int> &A, const vector<int> &ans) {
  int sum = 0;
  for (const int &a : ans) {
    sum = (sum + a) % A.size();
  }
  assert(sum == 0);
}

int main(int argc, char *argv[]) {
  default_random_engine gen((random_device())());
  for (int times = 0; times < 1000; ++times) {
    int n;
    vector<int> A;
    if (argc == 2) {
      n = atoi(argv[1]);
      A.resize(n);
      uniform_int_distribution<int> dis(0, 9999);
      for (int i = 0; i < n; ++i) {
        A[i] = dis(gen);
      }
    } else if (argc > 2) {
      for (int i = 1; i < argc; ++i) {
        A.emplace_back(atoi(argv[i]));
      }
    } else {
      uniform_int_distribution<int> n_dis(1, 100);
      n = n_dis(gen);
      A.resize(n);
      uniform_int_distribution<int> dis(0, 9999);
      for (int i = 0; i < n; ++i) {
        A[i] = dis(gen);
      }
    }
    vector<int> ans = find_0_sum_subset(A);
    check_ans(A, ans);
  }
  return 0;
}
