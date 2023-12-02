#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE

#include "TreeNode.h"
#include "ByteFrequency.h"
#include "Types.h"


using namespace std;

class PriorityQueue 
{
    private:
        unsigned int SIZE = 256;
        TreeNode* vector;
        unsigned short int used_size;

    public:
        PriorityQueue();

        unsigned short int get_used_size() const;
        TreeNode* get_vector() const;
        bool is_empty() const;

        void add(byte pos);
        void add_by_priority(TreeNode node);
        TreeNode dequeue();
        void order_vector();
};

#endif 