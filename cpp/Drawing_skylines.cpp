// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>
#include<queue>

using namespace std;

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;

struct Skyline;
void MergeIntersectSkylines(vector<Skyline>* merged, Skyline* a, int* a_idx,
                            Skyline* b, int* b_idx);
vector<Skyline> MergeSkylines(vector<Skyline>* L, vector<Skyline>* R);
vector<Skyline> DrawingSkylinesHelper(const vector<Skyline>& skylines,
                                      int start, int end);

// @include
struct Skyline {
  int left, right, height;
};

struct Endpoint{
	int pos;
	int height;
	bool start;
	bool valid;
	Endpoint*left;
	Endpoint(int a,int b,bool c):pos(a),height(b),start(c),valid(true),left(NULL){}

bool operator<(const Endpoint&r) const{
		return pos<r.pos;
	}
	
	bool operator==(const Endpoint&r) const{
		return pos==r.pos;
	}
};

struct Compare{
	bool operator()(const Endpoint&l,const Endpoint&r) const{
		return l.height<r.height;
	}
};
// 21:48
vector<Skyline> drawing_skylines(vector<Skyline> skylines) {
	vector<Endpoint> points;
	vector<Skyline> res;
	priority_queue<Endpoint, vector<Endpoint>, Compare> pq;
	for(auto&line:skylines){
		points.push_back(Endpoint(line.left,line.height,true));
		points.push_back(Endpoint(line.right,line.height,false));
		points[points.size()-1].left=&(points[points.size()-2]);
	}
	sort(points.begin(),points.end());
	int pos=0;
	int height=0;
	cout<<points.size()<<endl;
	for(size_t i=0;i<points.size();i++){
		Endpoint&p=points[i];
		if(p.start){
			pq.emplace(p);
			if (pq.top().height>height){
				if(height && p.pos-pos)
					res.push_back(Skyline{pos, p.pos, height});
				pos=p.pos;
				height=p.height;
			}
		} else {
			cout<<p.left->valid<<" ? "<<endl;
			p.left->valid=false;
			cout<<p.left->valid<<" ? "<<endl;
			for(auto&s:points)if(s.pos==p.left->pos)cout<<&s<<","<<p.left<<endl;
			while(!pq.empty() && !pq.top().valid){
				pq.pop();
				cout<<pq.size()<<" = "<<endl;
			}
			if(pq.empty() || pq.top().height<height){
				if(height && p.pos-pos)
					res.push_back(Skyline{pos, p.pos, height});
				pos=p.pos;
				height=pq.empty()?0:pq.top().height;
			}
		}
	}
	return res;
}

vector<Skyline> S_drawing_skylines(vector<Skyline> skylines) {
  return DrawingSkylinesHelper(skylines, 0, skylines.size());
}

vector<Skyline> DrawingSkylinesHelper(const vector<Skyline>& skylines,
                                      int start, int end) {
  if (end - start <= 1) {  // 0 or 1 skyline, just copy it.
    return {skylines.cbegin() + start, skylines.cbegin() + end};
  }
  int mid = start + ((end - start) / 2);
  auto L = DrawingSkylinesHelper(skylines, start, mid);
  auto R = DrawingSkylinesHelper(skylines, mid, end);
  return MergeSkylines(&L, &R);
}

vector<Skyline> MergeSkylines(vector<Skyline>* L, vector<Skyline>* R) {
  int i = 0, j = 0;
  vector<Skyline> merged;

  while (i < L->size() && j < R->size()) {
    if ((*L)[i].right < (*R)[j].left) {
      merged.emplace_back((*L)[i++]);
    } else if ((*R)[j].right < (*L)[i].left) {
      merged.emplace_back((*R)[j++]);
    } else if ((*L)[i].left <= (*R)[j].left) {
      MergeIntersectSkylines(&merged, &(*L)[i], &i, &(*R)[j], &j);
    } else {  // L[i].left > R[j].left.
      MergeIntersectSkylines(&merged, &(*R)[j], &j, &(*L)[i], &i);
    }
  }

  copy(L->cbegin() + i, L->cend(), back_inserter(merged));
  copy(R->cbegin() + j, R->cend(), back_inserter(merged));
  return merged;
}

void MergeIntersectSkylines(vector<Skyline>* merged, Skyline* a, int* a_idx,
                            Skyline* b, int* b_idx) {
  if (a->right <= b->right) {
    if (a->height > b->height) {
      if (b->right != a->right) {
        merged->emplace_back(*a), ++*a_idx;
        b->left = a->right;
      } else {
        ++*b_idx;
      }
    } else if (a->height == b->height) {
      b->left = a->left, ++*a_idx;
    } else {  // a->height < b->height.
      if (a->left != b->left) {
        merged->emplace_back(Skyline{a->left, b->left, a->height});
      }
      ++*a_idx;
    }
  } else {  // a->right > b->right.
    if (a->height >= b->height) {
      ++*b_idx;
    } else {
      if (a->left != b->left) {
        merged->emplace_back(Skyline{a->left, b->left, a->height});
      }
      a->left = b->right;
      merged->emplace_back(*b), ++*b_idx;
    }
  }
}
// @exclude

int main(int argc, char* argv[]) {
  default_random_engine gen((random_device())());
  for (int times = 0; times < 2000; ++times) {
    int n;
    if (argc == 2) {
      n = atoi(argv[1]);
    } else {
      uniform_int_distribution<int> dis(1, 15);
      n = dis(gen);
    }
    vector<Skyline> A;
    for (int i = 0; i < n; ++i) {
      uniform_int_distribution<int> left_dis(0, 999);
      int left = left_dis(gen);
      uniform_int_distribution<int> right_dis(left, left + 200);
      int right = right_dis(gen);
      uniform_int_distribution<int> height_dis(0, 99);
      int height = height_dis(gen);
      A.emplace_back(Skyline{left, right, height});
    }
    vector<Skyline> ans = drawing_skylines(A);
    vector<Skyline> S_ans = S_drawing_skylines(A);
	
	cout<<ans.size()<<" . "<<S_ans.size()<<endl;
	return 100;
    for(size_t i=10;i<ans.size();i++){
	cout<<"left: "<<ans[i].left<<" - "<<ans[i].height<<" - "<<ans[i].right<<endl;
	cout<<"righ: "<<S_ans[i].left<<" - "<<S_ans[i].height<<" - "<<S_ans[i].right<<endl;
	cout<<endl;
    }
    cout << "n = " << n << endl;
    // Just check there is no overlap.
    for (int i = 0; i < ans.size(); ++i) {
      assert(ans[i].left <= ans[i].right);
      if (i > 0) {
        assert(ans[i - 1].right <= ans[i].left);
        assert(ans[i - 1].right != ans[i].left ||
               ans[i - 1].height != ans[i].height);
      }
    }
  }
  return 0;
}
