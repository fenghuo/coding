// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cassert>
#include <iostream>
#include <random>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::pair;
using std::random_device;
using std::unique_ptr;
using std::string;
using std::uniform_int_distribution;
using std::unordered_map;
using std::unordered_set;

class Trie {
 public:
  virtual ~Trie() { Clear(); }
  bool Insert(const string& s) {
    auto* p = root_.get();
    for (const char& c : s) {
      if (p->leaves.find(c) == p->leaves.cend()) {
        p->leaves[c] = unique_ptr<TrieNode>(new TrieNode);
      }
      p = p->leaves[c].get();
    }

    // s already existed in this trie.
    if (p->isString) {
      return false;
    } else {               // p->isString == false.
      p->isString = true;  // Inserts s into this trie.
      return true;
    }
  }

  string GetShortestUniquePrefix(const string& s) {
    auto* p = root_.get();
    string prefix;
    for (const char& c : s) {
      prefix += c;
      if (p->leaves.find(c) == p->leaves.cend()) {
        return prefix;
      }
      p = p->leaves[c].get();
    }
    return {};
  }
  void Clear() { Clear(&root_); }

 private:
  struct TrieNode {
    bool isString = false;
    unordered_map<char, unique_ptr<TrieNode>> leaves;
  };

  unique_ptr<TrieNode> root_ = unique_ptr<TrieNode>(new TrieNode);
  // @exclude
  void Clear(unique_ptr<TrieNode>* p) {
    for (auto& e : (*p)->leaves) {
      if (e.second) {
        Clear(&(e.second));
      }
    }
    p->reset(nullptr);
  }
  // @include
};

