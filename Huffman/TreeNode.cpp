#include <iostream>

#include "TreeNode.h"
#include "ByteFrequency.h"

TreeNode::TreeNode(ByteFrequency d, TreeNode* l, TreeNode* r) : data(d), left(l), right(r), size(0), under(new byte[SIZE]) {
    if (data.is_empty() || l == nullptr || r == nullptr) {
        cerr << "[TreeNode]: Missing Parameters";
        exit(-7);
    }
}

TreeNode::TreeNode(ByteFrequency d) : data(d), left(nullptr), right(nullptr), size(0), under(new byte[SIZE]) {}

TreeNode::TreeNode() : data(ByteFrequency()), left(nullptr), right(nullptr), size(0), under(new byte[SIZE]) {}

TreeNode::TreeNode(const TreeNode& other)
{
    left = other.left;
    right = other.right;
    data = other.data;
    under = new byte[SIZE];
    size = other.size;

    for (unsigned short int i = 0; i < size; i++)
        under[i] = other.under[i];
}

TreeNode::~TreeNode()
{
    delete[] under;
}

TreeNode* TreeNode::get_left() const {   return left; }

TreeNode* TreeNode::get_right() const { return right; }

ByteFrequency TreeNode::get_data() const { return data; }

byte* TreeNode::get_under() const { return under; }

unsigned short int TreeNode::get_size() const
{
    return size;
}

void TreeNode::set_data(ByteFrequency d) { data = d; }

void TreeNode::append_under(byte* under, unsigned short int size)
{
    for (unsigned short int i = 0; i < size; i++) {
        this->under[this->size] = under[i];
        this->size++;
    }
}

void TreeNode::append_under(byte under)
{
    this->under[this->size] = under;
    this->size++;
}

bool TreeNode::is_empty() { return data.is_empty() && left == nullptr && right == nullptr; }