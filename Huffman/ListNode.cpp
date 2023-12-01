#include <iostream>
#include "ListNode.h"


ListNode::ListNode() : data(0), next(nullptr) {}

ListNode::ListNode(unsigned char data) : data(data), next(nullptr) {}

ListNode::ListNode(unsigned char data, ListNode* next) : data(data), next(next) {
    if (next == nullptr)
    {
        cerr << "[ListNode]: Missing Paramerers";
        exit(-5);
    }
}

unsigned char ListNode::get_data() const { return data; }

void ListNode::set_data(unsigned char new_data) { data = new_data; }

void ListNode::set_next(ListNode* n)  { next = n; }

ListNode* ListNode::get_next() const { return next; }