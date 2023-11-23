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
bool PriorityQueue<Data>::exists(Data data) const 
{
  for (current = first, previous = NULL; current != NULL; previous = current, current = current -> next) {
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
    cerr << "[PriorityQueue]: Data already exists";
    exit(-1);
  }
  else {
    QueueNode<Data> newNode = new QueueNode<Data>(data);

    current = first;
    previous = NULL;

    while (current != NULL) {
      if (data < current -> data)
        break;
  
      previous = current;
      current = current -> data;
    }

    if (previous == NULL)
      first = &newNode;
    else 
      previous -> next = &newNode;

    newNode -> next = current;

    if (current == NULL)
      last = &newNode;
  }
}

template <typename Data>
Data PriorityQueue<Data>::dequeue()
{
  if (!is_empty()) {
    Data d = first -> data;
    first = first -> next;
    if (first == NULL)
      last = NULL;

    return d;
  }
  cerr << "[PriorityQueue]: Tried to deque from empty queue";
  exit(-1);
}