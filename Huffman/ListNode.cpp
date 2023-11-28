#include <iostream>
#include "ListNode.h"


ListNode::ListNode() : data(NULL), next(NULL) {}

ListNode::ListNode(char data) : data(data), next(NULL) {
    if (data == NULL)
    {
        cerr << "[ListNode]: char should not be NULL";
        exit(-1);
    }
}

ListNode::ListNode(char data, ListNode* next) : data(data), next(next) {
    if (data == NULL || next == NULL)
    {
        cerr << "[ListNode]: Missing Paramerers";
        exit(-1);
    }
}

char ListNode::get_data() const
{
    return data;
}

void ListNode::set_data(char data)
{
    this->data = data;
}

void ListNode::set_next(ListNode* n) 
{
    this->next = n;
}

ListNode* ListNode::get_next() const
{
    return next;
}