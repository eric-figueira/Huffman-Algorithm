#include <iostream>
#include <fstream>

#include "LinkedList.h"
#include "ListNode.h"
#include "Types.h"


LinkedList::LinkedList() : begin(nullptr), end(nullptr), current(nullptr), previous(nullptr), size(0) {}

LinkedList::LinkedList(ListNode* begin, ListNode* end) : begin(begin), end(end), current(begin), previous(nullptr), size(0)
{
    if (begin == nullptr || end == nullptr)
    {
        cerr << "[LinkedList]: Missing arguments";
        exit(-4);
    }
}

LinkedList::LinkedList(const LinkedList& other)
{
    begin = nullptr;
    end = nullptr;
    current = nullptr;
    previous = nullptr;
    size = other.size;

    ListNode* b = other.begin;
    ListNode** current = &b;

    while (*current != nullptr)
    {
        ListNode* node = new ListNode();
        *node = **current;

        if (begin == nullptr) {
            begin = node;
            end = begin;
        }
        else {
            end->set_next(node);
            end = end->get_next();
        }

        *current = (*current)->get_next();
    } 
}

LinkedList::~LinkedList()
{
    for (ListNode* current = begin; current != nullptr; )
    {
        ListNode* aux = current->get_next();
        delete current;
        current = aux;
    }
}

ListNode* LinkedList::get_begin() const
{
    return begin;
}

ListNode* LinkedList::get_end() const { return end; }

ListNode* LinkedList::get_current() const { return current; }

ListNode* LinkedList::get_previous() const { return previous; }

unsigned int LinkedList::get_size() const { return size; }

void LinkedList::set_begin(ListNode* data) { begin = data; }

void LinkedList::set_end(ListNode* data) { end = data; }

void LinkedList::set_current(ListNode* data) { current = data; }

void LinkedList::set_previous(ListNode* data) { previous = data; }

byte LinkedList::get(unsigned int pos)
{
    current = begin;
    for (unsigned int i = 0; i < pos; i++)
        current = current->get_next();
    return current->get_data();
}

void LinkedList::set(unsigned int pos, byte data)
{
    current = begin;
    for (unsigned int i = 0; i < pos; i++)
    {
        current = current->get_next();
    }
    current->set_data(data);
}

void LinkedList::push(byte data)
{
    ListNode* p_new_data = new ListNode(data);
    if (begin == nullptr)
    {
        begin = p_new_data;
        end = begin;
    }
    else {
        end->set_next(p_new_data);
        end = p_new_data;
    }

    size += 1;
}

ofstream& operator<<(ofstream& os, const LinkedList& list)
{
    ListNode* current = new ListNode();
    *current = *list.get_begin();

    while (current != nullptr)
    {
        os << current->get_data();
        current = current->get_next();
    }

    delete current;

    return os;
}