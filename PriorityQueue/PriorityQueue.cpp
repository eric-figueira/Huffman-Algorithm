#include <iostream>

#include "PriorityQueue.h"
#include "ByteFrequency.h"
#include "TreeNode.h"

using namespace std;

PriorityQueue::PriorityQueue(): used_size(0), vector(new TreeNode<ByteFrequency>[SIZE]) {
  for (unsigned short int i = 0; i < SIZE; i++)
    vector[i] = NULL;
} 

unsigned int PriorityQueue::get_used_size() const { return used_size; }

void PriorityQueue::add_in_pos(char pos, TreeNode<ByteFrequency> data) 
{
  if (pos >= 0 && data != NULL) {
    vector[pos] = data;
  }
}

TreeNode<ByteFrequency> PriorityQueue::dequeue()
{
  if (!is_empty()) {
    TreeNode<ByteFrequency> info = vector[0];

    for (unsigned short int i = 0, i < used_size; i++)
      vector[i] = vector[i+1];

    vector[used_size] = NULL;
    used_size--;

    return info;
  }
  cerr << "[PriorityQueue]: Tried to deque from empty queue";
  exit(-1);
}

void PriorityQueue::order_vector() 
{
  // Keep the non-null data on the left of vector
  unsigned short int i = 0;
  for (unsigned short int j = 0; j < SIZE; j++) {
    if (vector[j] != NULL) {
      vector[i] = vector[j];
      if (i != j)
        vector[j] = NULL;
      i++;
    }
  }

  // Order non-null data by frequency
  for (unsigned short int a = 0; a < used_size - 1; a++) {
    for (unsigned short int b = 0; b < used_size - a - 1; b++) {
      if (vector[b].get_data().get_frequency < vector[b + 1].get_data().get_frequency()) {
        TreeNode<ByteFrequency> temp = vector[b];
        vector[b] = vector[b + 1];
        vector[b + 1] = temp;
      }
    }
  }
}