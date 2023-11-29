#include <iostream>

#include "TreeNode.h"
#include "ByteFrequency.h"

TreeNode::TreeNode(ByteFrequency d, TreeNode* l, TreeNode* r) : data(d), left(l), right(r) {
    if (data.is_empty() || l == nullptr || r == nullptr) {
        cerr << "[TreeNode]: Missing Parameters";
        exit(-1);
    }
}

TreeNode::TreeNode(ByteFrequency d) : data(d), left(nullptr), right(nullptr) {}

TreeNode::TreeNode() : data(ByteFrequency()), left(nullptr), right(nullptr) {}

TreeNode::~TreeNode()
{
    delete left;
    delete right;
}

TreeNode* TreeNode::get_left() const {   return left; }

TreeNode* TreeNode::get_right() const { return right; }

ByteFrequency TreeNode::get_data() const { return data; }

void TreeNode::set_data(ByteFrequency d) { data = d; }

bool TreeNode::is_empty() { return data.is_empty() && left == nullptr && right == nullptr; }