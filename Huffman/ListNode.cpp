#include <iostream>

#include "ListNode.h"
#include "Types.h"

ListNode::ListNode() : data(0), next(nullptr) {}

ListNode::ListNode(byte data) : data(data), next(nullptr) {}

ListNode::ListNode(byte data, ListNode* next) : data(data), next(next) {
    if (next == nullptr)
    {
        cerr << "[ListNode]: Missing Paramerers";
        exit(-5);
    }
}

byte ListNode::get_data() const { return data; }

void ListNode::set_data(byte new_data) { data = new_data; }

void ListNode::set_next(ListNode* n)  { next = n; }

ListNode* ListNode::get_next() const { return next; }