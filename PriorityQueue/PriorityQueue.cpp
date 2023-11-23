#include <iostream>
#include "PriorityQueue.h"

using namespace std;

template <typename Data>
PriorityQueue<Data>::PriorityQueue(): first(NULL), last(NULL), current(NULL), previous(NULL), size(0) {}

template <typename Data>
unsigned int PriorityQueue<Data>::get_size() const { return size; }

template <typename Data>
bool PriorityQueue<Data>::is_empty() const { return first == NULL; }

template <typename Data>
Data PriorityQueue<Data>::get_first() const
{
  if (is_empty()) {
    cerr << "[PriorityQueue]: Queue is empty";
    exit(-1);
  }
 
  return first -> data;
}

template <typename Data>
Data PriorityQueue<Data>::get_last() const
{
  if (is_empty()) {
    cerr << "[PriorityQueue]: Queue is empty";
    exit(-1);
  }
 
  return last -> data;
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
void PriorityQueue<Data>::enqueue(Data data) 
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
Data PriorityQueue<Data>::dequeue()
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