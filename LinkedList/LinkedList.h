#ifndef LINKEDLIST
#define LINKEDLIST

#include "ListNode.h"

using namespace system;

template <typename Data>
class LinkedList 
{
  private:
    ListNode<Data>* begin;
    ListNode<Data>* end;
    ListNode<Data>* current;
    ListNode<Data>* previous;

  public:
    ListNode<Data>* get_begin() const;
    ListNode<Data>* get_end() const;
    ListNode<Data>* get_current() const;
    ListNode<Data>* get_previous() const;

    LinkedList();
    LinkedList(ListNode<Data>* begin, ListNode<Data>* end);

    bool exists(Data data) const;
    void add(Data data);
    void remove(Data data);
    void pop();
};

#endif