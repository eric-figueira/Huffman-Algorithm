#include <iostream>

#include "PriorityQueue.h"
#include "ByteFrequency.h"
#include "TreeNode.h"


PriorityQueue::PriorityQueue() : used_size(0), vector(new TreeNode[SIZE]) {
    for (unsigned short int i = 0; i < SIZE; i++)
        vector[i] = TreeNode();
}

PriorityQueue::~PriorityQueue()
{
    free(vector);
}

char PriorityQueue::get_used_size() const { return used_size; }

TreeNode* PriorityQueue::get_vector() const { return vector; }

bool PriorityQueue::is_empty() const { return used_size == 0; }

void PriorityQueue::add(char byte_code)
{
    TreeNode node = vector[byte_code];

    if (node.is_empty())
        vector[byte_code] = TreeNode(ByteFrequency(1, byte_code));
    else
        node.set_data(ByteFrequency(node.get_data().get_frequency() + 1, node.get_data().get_byte_code()));

    used_size++;
}

void PriorityQueue::add_by_priority(TreeNode node)
{
    char i = used_size - 1;
    while (node.get_data().get_frequency() < vector[i].get_data().get_frequency())
        i++;

    char j;
    for (j = used_size; j > i; j--)
        vector[j] = vector[j - 1];

    vector[(int)j] = node;
    used_size++;
}

TreeNode PriorityQueue::dequeue()
{
    if (!is_empty()) {
        TreeNode info = vector[0];

        for (unsigned short int i = 0; i < used_size; i++)
            vector[i] = vector[i + 1];

        vector[used_size] = TreeNode();
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
        if (!vector[j].is_empty()) {
            vector[i] = vector[j];
            if (i != j)
                vector[j] = TreeNode();
            i++;
        }
    }

    // Order non-null data by frequency
    for (unsigned short int a = 0; a < used_size - 1; a++) {
        for (unsigned short int b = a + 1; b < used_size - 1; b++) {
            if (vector[a].get_data().get_frequency() > vector[b].get_data().get_frequency())
            {
                TreeNode temp = vector[b];
                vector[b] = vector[a];
                vector[a] = temp;
            }
        }
    }
}