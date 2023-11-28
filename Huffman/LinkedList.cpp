#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "ListNode.h"


LinkedList::LinkedList() : begin(NULL), end(NULL), current(NULL), previous(NULL) {}

LinkedList::LinkedList(ListNode* begin, ListNode* end) : begin(begin), end(end), current(begin), previous(NULL)
{
    if (begin == NULL || end == NULL)
    {
        cerr << "[LinkedList]: Missing arguments";
        exit(-1);
    }
}

ListNode* LinkedList::get_begin() const
{
    return begin;
}

ListNode* LinkedList::get_end() const
{
    return end;
}

ListNode* LinkedList::get_current() const
{
    return current;
}

ListNode* LinkedList::get_previous() const
{
    return previous;
}

unsigned int LinkedList::get_size() const
{
    return size;
}

void LinkedList::set_begin(ListNode* data)
{
    begin = data;
}

void LinkedList::set_end(ListNode* data)
{
    end = data;
}

void LinkedList::set_current(ListNode* data)
{
    current = data;
}

void LinkedList::set_previous(ListNode* data)
{
    previous = data;
}

bool LinkedList::exists(char data)
{
    for (current = begin; current != NULL; previous = current, current = current->get_next()) {
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
        if (current == NULL)
            push(data);
        current = current->get_next();
    }
    current->set_data(data);
}

void LinkedList::add(char data)
{
    if (exists(data))
    {
        cerr << "[LinkedList]: char already exists";
        exit(-1);
    }
    else {
        if (begin == NULL)
        {
            begin->set_data(data);
            end = begin;
        }
        else {
            ListNode* p_new_data = new ListNode(data);

            if (previous == NULL)
                begin = p_new_data;
            else
                previous->set_next(p_new_data);
            p_new_data->set_next(current);
            if (current == NULL)
                end = p_new_data;

            delete p_new_data;
        }

        size += 1;
    }
}

void LinkedList::push(char data)
{
    if (begin == NULL)
    {
        begin->set_data(data);
        end = begin;
    }
    else {
        ListNode* p_new_data = new ListNode(data);

        end->set_next(p_new_data);
        end = p_new_data;

        delete p_new_data;
    }

    size += 1;
}

void LinkedList::remove(char data)
{
    if (!exists(data)) {
        cerr << "[LinkedList]: char does not exist";
        exit(-1);
    }
    else {
        if (previous == NULL)
            begin = current->get_next();
        else
            previous->set_next(current->get_next());
        if (current == end)
            end = previous;
        current->set_next(NULL);

        size -= 1;
    }
}

ofstream& operator<<(ofstream& os, const LinkedList& list)
{
    const ListNode* current = list.get_begin();

    while (current != NULL)
    {
        os << current->get_data();
        current = current->get_next();
    }

    return os;
}