#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE

#include "TreeNode.h"
#include "ByteFrequency.h"


using namespace std;

class PriorityQueue 
{
    private:
        unsigned int SIZE = 256;
        TreeNode* vector;
        char used_size; // char because the max is 256 -> 1 byte

    public:
        PriorityQueue();
        //~PriorityQueue();

        char get_used_size() const;
        TreeNode* get_vector() const;
        bool is_empty() const;

        void add(char pos);
        void add_by_priority(TreeNode node);
        TreeNode dequeue();
        void order_vector();
};

#endif 