#include <iostream>
#include "LinkedList.h"
#include "ListNode.h"

using namespace std;

template <typename Data>
LinkedList<Data>::LinkedList() : begin(NULL), end(NULL), current(NULL), previous(NULL) {}

template <typename Data>
LinkedList<Data>::LinkedList(ListNode<Data>* begin, ListNode<Data>* end): begin(begin), end(end), current(begin), previous(NULL) 
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
bool LinkedList<Data>::exists(Data data) const 
{
  for (current = begin; current != NULL; previous = current, current = current -> next) {
    if (current.data == data)
      return true;
    else if (current.data > data)
      return false;
  }
  return false;
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
      begin -> data = data;
      end = begin;
    }
    else {
      ListNode<Data>* new_data;
      *(new_data) = ListNode<Data>(data);
      
      if (previous == NULL)
        begin = new_data;
      else 
        previous -> next = new_data;
      *(new_data) -> next = current;
      if (current == NULL)
        end = new_data;
    }
  }
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
      begin = current -> next;
    else
      previous -> next = current -> next;
      if (current == end)
        end = previous;
    current -> next = NULL;
  }
}

template <typename Data>
void LinkedList<Data>::pop() 
{
  remove(*end);
}