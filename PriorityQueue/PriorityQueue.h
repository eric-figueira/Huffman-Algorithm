#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE

#include "LinkedList.h"

template <typename Data>
class PriorityQueue {
  private:
    LinkedList<Data> priorityQueue;
    unsigned int size;

  public:
    PriorityQueue();

    LinkedList<Data> get_priorityQueue() const;
    unsigned int get_size() const;
    ListNode<Data> get_begin() const;
    ListNode<Data> get_end() const;

    void enqueue(Data data);
    void dequeue();
};

#endif 