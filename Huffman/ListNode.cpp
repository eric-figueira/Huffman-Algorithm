#include <iostream>
#include "ListNode.h"

using namespace std;

template <typename Data>
ListNode<Data>::ListNode() : data(NULL), next(NULL) {}

template <typename Data>
ListNode<Data>::ListNode(Data data) : data(data), next(NULL) {
    if (data == NULL)
    {
        cerr << "[ListNode]: Data should not be NULL";
        exit(-1);
    }
}

template <typename Data>
ListNode<Data>::ListNode(Data data, ListNode<Data>* next) : data(data), next(next) {
    if (data == NULL || next == NULL)
    {
        cerr << "[ListNode]: Missing Paramerers";
        exit(-1);
    }
}

template <typename Data>
Data ListNode<Data>::get_data() const
{
    return data;
}

template <typename Data>
void ListNode<Data>::set_data(Data data)
{
    this->data = data;
}

template <typename Data>
ListNode<Data>* ListNode<Data>::get_next() const
{
    return next;
}