#include <iostream>
#include "PriorityQueue.h"

using namespace std;

template <typename Data>
PriorityQueue<Data>::PriorityQueue(): priorityQueue() {}

template <typename Data>
LinkedList<Data> PriorityQueue<Data>::get_priorityQueue() const
{
  return priorityQueue;
}

template <typename Data>
unsigned int PriorityQueue<Data>::get_size() const
{
  return size;
}

template <typename Data>
ListNode<Data> PriorityQueue<Data>::get_begin() const
{
  return priorityQueue.get_end();
}

template <typename Data>
ListNode<Data> PriorityQueue<Data>::get_end() const
{
  return priorityQueue.get_begin();
}

template <typename Data>
void PriorityQueue<Data>::enqueue(Data data) 
{
  priorityQueue.add(data);
}

template <typename Data>
void PriorityQueue<Data>::dequeue()
{
  priorityQueue.pop();
}