#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE


#include "TreeNode.h"
#include "ByteFrequency.h"

using namespace std;

class PriorityQueue {
private:
    unsigned int SIZE = 256;
    TreeNode<ByteFrequency>* vector;
    char used_size; // char because the max is 256 -> 1 byte

public:
    PriorityQueue();

    char get_used_size() const;
    TreeNode<ByteFrequency>* get_vector() const;
    bool is_empty() const;

    void add(char pos);
    void add_by_priority(TreeNode<ByteFrequency> node);
    TreeNode<ByteFrequency> dequeue();
    void order_vector();
};

#endif 