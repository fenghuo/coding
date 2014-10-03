// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cassert>
#include <memory>

#include "./BST_prototype.h"

using std::unique_ptr;

// @include
BSTNode<int>* FindFirstEqualK(const unique_ptr<BSTNode<int>>& T, int k) {
  if (!T) {
    return nullptr;  // No match.
  } else if (T->data == k) {
    // Recursively searches the left subtree for first one == k.
    auto* node = FindFirstEqualK(T->left, k);
    return node ? node : T.get();
  }
  // Searches left or right tree according to T->data and k.
  return FindFirstEqualK(T->data < k ? T->right : T->left, k);
}
// @exclude

int main(int argc, char* argv[]) {
  //    3
  //  2   6
  // 1   4 6
  auto root = unique_ptr<BSTNode<int>>(new BSTNode<int>{3});
  root->left = unique_ptr<BSTNode<int>>(new BSTNode<int>{2});
  root->left->left =
      unique_ptr<BSTNode<int>>(new BSTNode<int>{1});
  root->right =
      unique_ptr<BSTNode<int>>(new BSTNode<int>{6});
  root->right->left =
      unique_ptr<BSTNode<int>>(new BSTNode<int>{4});
  root->right->right =
      unique_ptr<BSTNode<int>>(new BSTNode<int>{6});
  assert(!FindFirstEqualK(root, 7));
  assert(FindFirstEqualK(root, 6)->data == 6 &&
         FindFirstEqualK(root, 6)->right->data == 6);
  return 0;
}
