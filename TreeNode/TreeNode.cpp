#include "TreeNode.h"
#include <iostream>

using namespace std;

template <typename Data>
TreeNode<Data>::TreeNode(Data d, TreeNode* l, TreeNode * r) : data(d), left(l), right(r) {
  if (d == NULL || l == NULL || r == NULL) {
    cerr << "[TreeNode]: Missing Parameters";
    exit(-1);
  }
}

template <typename Data>
TreeNode<Data>::TreeNode(Data d) : data(d), left(NULL), right(NULL) {
  if (d == NULL) {
    cerr << "[TreeNode]: Data should not be NULL";
    exit(-1);
  }
}

template <typename Data>
TreeNode<Data>::TreeNode() : data(NULL), left(NULL), right(NULL) {}

template <typename Data>
TreeNode<Data>* TreeNode<Data>::get_left() const{
  return left;
}

template <typename Data>
TreeNode<Data>* TreeNode<Data>::get_right() const {
  return right;
}

template <typename Data>
Data TreeNode<Data>::get_data() const {
  return data;
}
