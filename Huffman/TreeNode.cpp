#include "TreeNode.h"
#include <iostream>


template <typename Data>
TreeNode<Data>::TreeNode(Data d, TreeNode* l, TreeNode* r) : data(d), left(l), right(r) {
    if (l == nullptr || r == nullptr) {
        cerr << "[TreeNode]: Missing Parameters";
        exit(-1);
    }
}

template <typename Data>
TreeNode<Data>::TreeNode(Data d) : data(d), left(nullptr), right(nullptr) {}

template <typename Data>
TreeNode<Data>::TreeNode() :left(nullptr), right(nullptr) {}

template <typename Data>
TreeNode<Data>* TreeNode<Data>::get_left() const {
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

template <typename Data>
void TreeNode<Data>::set_data(Data d) {
    data = d;
}

template <typename Data>
bool TreeNode<Data>::is_empty() {
    return left == nullptr && right == nullptr;
}