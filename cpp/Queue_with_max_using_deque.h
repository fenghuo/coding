// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#ifndef SOLUTIONS_QUEUE_WITH_MAX_USING_DEQUE_H_
#define SOLUTIONS_QUEUE_WITH_MAX_USING_DEQUE_H_

#include <algorithm>
#include <deque>
#include <queue>
#include <stdexcept>

using std::deque;
using std::length_error;
using std::queue;

// @include
template <typename T>
class Queue {
 public:
  void Enqueue(const T& x) {
    Q_.emplace(x);
    while (!D_.empty() && D_.back() < x) {
      D_.pop_back();
    }
    D_.emplace_back(x);
  }

  T Dequeue() {
    if (!Q_.empty()) {
      T ret = Q_.front();
      if (ret == D_.front()) {
        D_.pop_front();
      }
      Q_.pop();
      return ret;
    }
    throw length_error("empty queue");
  }

  const T& Max() const {
    if (!D_.empty()) {
      return D_.front();
    }
    throw length_error("empty queue");
  }
  // @exclude
  T& Head() { return Q_.front(); }

  const T& Head() const { return Q_.front(); }
  // @include

 private:
  queue<T> Q_;
  deque<T> D_;
};
// @exclude
#endif  // SOLUTIONS_QUEUE_WITH_MAX_USING_DEQUE_H_


class A_Queue{
private:
	queue<int> Q;
	deque<int> M;
public:
	void enqeue(int&v){
		Q.push(v);
		while(!M.empty() && M.back()<v)
			M.pop_back();
		M.push_back(v);
	}

	void dequeue(int&v){
		auto top=Q.front();
		Q.pop();
		if(top==M.front())
			M.pop_front();
	}
	
	int max(){
		return M.front();
	}
};
