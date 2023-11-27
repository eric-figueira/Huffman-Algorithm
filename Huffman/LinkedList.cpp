#include <iostream>
#include "LinkedList.h"
#include "ListNode.h"

using namespace std;

template <typename Data>
LinkedList<Data>::LinkedList() : begin(NULL), end(NULL), current(NULL), previous(NULL) {}

template <typename Data>
LinkedList<Data>::LinkedList(ListNode<Data>* begin, ListNode<Data>* end) : begin(begin), end(end), current(begin), previous(NULL)
{
    if (begin == NULL || end == NULL)
    {
        cerr << "[LinkedList]: Missing arguments";
        exit(-1);
    }
}

template <typename Data>
ListNode<Data>* LinkedList<Data>::get_begin() const
{
    return begin;
}

template <typename Data>
ListNode<Data>* LinkedList<Data>::get_end() const
{
    return end;
}

template <typename Data>
ListNode<Data>* LinkedList<Data>::get_current() const
{
    return current;
}

template <typename Data>
ListNode<Data>* LinkedList<Data>::get_previous() const
{
    return previous;
}

template <typename Data>
unsigned int LinkedList<Data>::get_size() const
{
    return size;
}

template <typename Data>
void LinkedList<Data>::set_begin(ListNode<Data>* data)
{
    begin = data;
}

template <typename Data>
void LinkedList<Data>::set_end(ListNode<Data>* data)
{
    end = data;
}

template <typename Data>
void LinkedList<Data>::set_current(ListNode<Data>* data)
{
    current = data;
}

template <typename Data>
void LinkedList<Data>::set_previous(ListNode<Data>* data)
{
    previous = data;
}

template <typename Data>
bool LinkedList<Data>::exists(Data data) const
{
    for (current = begin; current != NULL; previous = current, current = current->next) {
        if (current.data == data) {
            return true;
        }
    }
    return false;
}

template <typename Data>
Data LinkedList<Data>::get(unsigned int pos) const
{
    current = begin;
    for (unsigned int i = 0; i < pos; i++)
        current = current->next;
    return current->get_data();
}

template <typename Data>
void LinkedList<Data>::set(unsigned int pos, Data data)
{
    current = begin;
    for (unsigned int i = 0; i < pos; i++)
    {
        if (current == NULL)
            push(data);
        current = current->next;
    }
    current->set_data(data);
}

template <typename Data>
void LinkedList<Data>::add(Data data)
{
    if (exists(data))
    {
        cerr << "[LinkedList]: Data already exists";
        exit(-1);
    }
    else {
        if (begin == NULL)
        {
            begin->data = data;
            end = begin;
        }
        else {
            ListNode<Data>* new_data;
            *(new_data) = ListNode<Data>(data);

            if (previous == NULL)
                begin = new_data;
            else
                previous->next = new_data;
            *(new_data)->next = current;
            if (current == NULL)
                end = new_data;
        }

        size += 1;
    }
}

template <typename Data>
void LinkedList<Data>::push(Data data)
{
    if (begin == NULL)
    {
        begin->data = data;
        end = begin;
    }
    else {
        ListNode<Data>* new_data;
        *(new_data) = ListNode<Data>(data);

        end->next = new_data;
        end = new_data;
    }

    size += 1;
}

template <typename Data>
void LinkedList<Data>::remove(Data data)
{
    if (!exists(data)) {
        cerr << "[LinkedList]: Data does not exist";
        exit(-1);
    }
    else {
        if (previous == NULL)
            begin = current->next;
        else
            previous->next = current->next;
        if (current == end)
            end = previous;
        current->next = NULL;

        size -= 1;
    }
}

template <typename Data>
ofstream& operator<< (ofstream& os, const LinkedList<Data> list)
{
    list.set_current(list.get_begin());
    while (list.get_current() != NULL)
    {
        list.set_current(list.get_current()->get_next());
        os << list.get_current()->get_data();
    }
    return os;
}