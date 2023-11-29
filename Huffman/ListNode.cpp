#include <iostream>
#include "ListNode.h"


ListNode::ListNode() : data(0), next(nullptr) {}

ListNode::ListNode(char data) : data(data), next(nullptr) {}

ListNode::ListNode(char data, ListNode* next) : data(data), next(next) {
    if (next == nullptr)
    {
        cerr << "[ListNode]: Missing Paramerers";
        exit(-5);
    }
}

ListNode::~ListNode()
{
    /*for (ListNode* current = next; next != nullptr; current = next)
    {
        next = next->get_next();
        delete current;
    }*/
    ListNode* current = next;
    while (current != nullptr)
    {
        ListNode* next_node = current->get_next();
        delete current;
        current = next_node;
    }
}

char ListNode::get_data() const { return data; }

void ListNode::set_data(char new_data) { data = new_data; }

void ListNode::set_next(ListNode* n)  { next = n; }

ListNode* ListNode::get_next() const { return next;  }