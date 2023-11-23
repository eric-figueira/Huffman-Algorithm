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
void PriorityQueue<Data>::enqueue(Data data) 
{
  // TODO: Use compare to in order to add as the priority
}

template <typename Data>
Data PriorityQueue<Data>::dequeue()
{
  priorityQueue.pop();
}