// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::swap;
using std::uniform_int_distribution;
using std::vector;

// @include
// 14:31
void DutchFlagPartition(int pivot_index, vector<int>* A) {
	auto&ref=*A;
	auto p=ref[pivot_index];
	int less=0,equal=0,larger=ref.size()-1;
	while(equal<=larger){
		if(ref[equal]<p)
			swap(ref[less++],ref[equal++]);
		else if(ref[equal]>p)
			swap(ref[equal],ref[larger--]);
		else
			equal++;
	}


}

void A_DutchFlagPartition(int pivot_index, vector<int>* A) {
	auto&ref=*A;
	int a=0,b=0;
	int p=ref[pivot_index];
	cout<<"p: "<<p<<endl;
	for(size_t i=0;i<ref.size();i++){
		if(ref[i]<p){
			if(i==b)
				swap(ref[a++],ref[b++]);
			else{
				swap(ref[b++],ref[a]);
				swap(ref[i],ref[a++]);
			}
		} else if(ref[i]==p) {
			swap(ref[i],ref[b++]);
		}
	}
}
void S_DutchFlagPartition(int pivot_index, vector<int>* A) {
  auto& A_ref = *A;
  int pivot = A_ref[pivot_index];
  /**
   * Keep the following invariants during partitioning:
   * bottom group: A_ref[0 : smaller - 1].
   * middle group: A_ref[smaller : equal - 1].
   * unclassified group: A_ref[equal : larger].
   * top group: A_ref[larger + 1 : A_ref.size() - 1].
   */
  int smaller = 0, equal = 0, larger = A_ref.size() - 1;
  // When there is any unclassified element.
  while (equal <= larger) {
    // A_ref[equal] is the incoming unclassified element.
    if (A_ref[equal] < pivot) {
      swap(A_ref[smaller++], A_ref[equal++]);
    } else if (A_ref[equal] == pivot) {
      ++equal;
    } else {  // A_ref[equal] > pivot.
      swap(A_ref[equal], A_ref[larger--]);
    }
  }
}
// @exclude

vector<int> RandVector(int len) {
  default_random_engine gen((random_device())());
  vector<int> ret;
  while (len--) {
    uniform_int_distribution<int> dis(0, 2);
    ret.emplace_back(dis(gen));
  }
  return ret;
}

int main(int argc, char* argv[]) {
  default_random_engine gen((random_device())());
  for (int times = 0; times < 1000; ++times) {
    int n;
    if (argc == 2) {
      n = atoi(argv[1]);
    } else {
      uniform_int_distribution<int> dis(1, 100);
      n = dis(gen);
    }
    vector<int> A(RandVector(n));
    uniform_int_distribution<int> dis(0, A.size() - 1);
    int pivot_index = dis(gen);
    int pivot = A[pivot_index];
    DutchFlagPartition(pivot_index, &A);
    int i = 0;

    while (A[i] < pivot && i < A.size()) {
      cout << A[i] << ' ';
      ++i;
    }
    while (A[i] == pivot && i < A.size()) {
      cout << A[i] << ' ';
      ++i;
    }
    while (A[i] > pivot && i < A.size()) {
      cout << A[i] << ' ';
      ++i;
    }
    cout << endl;
    cout<<A.size()<<endl;
    assert(i == A.size());
  }
  return 0;
}
