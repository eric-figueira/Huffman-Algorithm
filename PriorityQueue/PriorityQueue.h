#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE

#include "QueueNode.h"

template <typename Data>
class PriorityQueue {
  private:
    QueueNode<Data> *first, *last, *current, *previous;
    unsigned int size;

  public:
    PriorityQueue();

    unsigned int get_size() const;
    bool is_empty() const;

    void enqueue(Data data);
    Data dequeue();

    Data get_first() const;
    Data get_last()  const;
};

#endif 