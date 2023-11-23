#include <iostream>
#include "QueueNode.h"

using namespace std;

template <typename Data>
QueueNode<Data>::QueueNode() : data(NULL), next(NULL) {}

template <typename Data>
QueueNode<Data>::QueueNode(Data data) : data(data), next(NULL) {
  if (data == NULL)
  {
    cerr << "[QueueNode]: Data should not be NULL";
    exit(-1);
  }
}

template <typename Data>
QueueNode<Data>::QueueNode(Data data, QueueNode<Data>* next) : data(data), next(next) {
  if (data == NULL || next == NULL)
  {
    cerr << "[QueueNode]: Missing Paramerers";
    exit(-1);
  }
}

template <typename Data>
Data QueueNode<Data>::get_data() const
{
  return data;
}

template <typename Data>
QueueNode* QueueNode<Data>::get_next() const 
{
  return next;
}
