#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "ListNode.h"


LinkedList::LinkedList() : begin(nullptr), end(nullptr), current(nullptr), previous(nullptr), size(0) {}

LinkedList::LinkedList(ListNode* begin, ListNode* end) : begin(begin), end(end), current(begin), previous(nullptr), size(0)
{
    if (begin == nullptr || end == nullptr)
    {
        cerr << "[LinkedList]: Missing arguments";
        exit(-4);
    }
}

//LinkedList::~LinkedList()
//{
//    ListNode* current_node = begin;
//    ListNode* next_node = nullptr;
//
//    while (current_node != nullptr) {
//        next_node = current_node->get_next();
//        delete current_node;
//        current_node = next_node;
//    }
//}

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

bool LinkedList::exists(char data)
{
    for (current = begin; current != nullptr; previous = current, current = current->get_next()) {
        if (current->get_data() == data) {
            return true;
        }
    }
    return false;
}

char LinkedList::get(unsigned int pos)
{
    current = begin;
    for (unsigned int i = 0; i < pos; i++)
        current = current->get_next();
    return current->get_data();
}

void LinkedList::set(unsigned int pos, char data)
{
    current = begin;
    for (unsigned int i = 0; i < pos; i++)
    {
        current = current->get_next();
    }
    current->set_data(data);
}

void LinkedList::add(char data)
{
    if (exists(data))
    {
        cerr << "[LinkedList]: char already exists";
        exit(-4);
    }
    else {
        ListNode* p_new_data = new ListNode(data);
        if (begin == nullptr)
        {
            begin = p_new_data;
            end = begin;
        }
        else {
            if (previous == nullptr)
                begin = p_new_data;
            else
                previous->set_next(p_new_data);
            p_new_data->set_next(current);
            if (current == nullptr)
                end = p_new_data;
        }

        size += 1;
    }
}

void LinkedList::push(char data)
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

void LinkedList::remove(char data)
{
    if (!exists(data)) {
        cerr << "[LinkedList]: char does not exist";
        exit(-4);
    }
    else {
        if (previous == nullptr)
            begin = current->get_next();
        else
            previous->set_next(current->get_next());
        if (current == end)
            end = previous;
        current->set_next(nullptr);

        size -= 1;
    }
}

ofstream& operator<<(ofstream& os, const LinkedList& list)
{
    ListNode* current = list.get_begin();

    while (current != nullptr)
    {
        os << current->get_data();
        current = current->get_next();
    }

    return os;
}