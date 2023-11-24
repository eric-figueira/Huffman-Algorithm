#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE

#include "TreeNode.h"
#include "ByteFrequency.h"

class PriorityQueue {
  private:
    unsigned int SIZE = 256;
    TreeNode<ByteFrequency>* vector;
    unsigned int used_size;

  public:
    PriorityQueue();

    unsigned int get_used_size() const;
    bool is_empty() const;

    void add_in_pos(char pos, TreeNode<ByteFrequency> data);
    Data dequeue();
    void order_vector();
};

#endif 