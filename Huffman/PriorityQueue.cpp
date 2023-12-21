#include <iostream>

#include "PriorityQueue.h"
#include "ByteFrequency.h"
#include "TreeNode.h"
#include "Types.h"


PriorityQueue::PriorityQueue() : used_size(0), vector(new TreeNode*[SIZE]) {
    for (unsigned short int i = 0; i < SIZE; i++)
        vector[i] = nullptr;
}

PriorityQueue::~PriorityQueue()
{
    for (unsigned short int i = 0; i < SIZE; i++)
        delete vector[i];
    delete[] vector;
}

unsigned short int PriorityQueue::get_used_size() const { return used_size; }

TreeNode** PriorityQueue::get_vector() const { return vector; }

bool PriorityQueue::is_empty() const { return used_size == 0; }

void PriorityQueue::add(byte byte_code)
{
    if (used_size < SIZE)
    {
        TreeNode* node = vector[byte_code];

        if (node == nullptr) {
            vector[byte_code] = new TreeNode(ByteFrequency(1, byte_code));
            used_size++;
        }
        else
            (*(vector[byte_code])).set_data(ByteFrequency((*node).get_data().get_frequency() + 1, byte_code));
    }
    else {
        cerr << "[PriorityQueue]: Tried to enqueue in a full queue";
        exit(-8);
    }
}

void PriorityQueue::add_by_priority(TreeNode* node)
{
    if (used_size < SIZE) {
        if (used_size != 0) {
            unsigned short int i = used_size - 1;
            while (i > 0 && (*node).get_data().get_frequency() < (*(vector[i])).get_data().get_frequency()) {
                i--;
            }

            for (unsigned short int j = used_size; j > i + 1; j--)
                vector[j] = vector[j - 1];
            vector[i + 1] = node;
        }
        else {
            vector[0] = node;
        }
        used_size++;
    }
    else {
        cerr << "[PriorityQueue]: Tried to enqueue in a full queue";
        exit(-8);
    }
}

TreeNode* PriorityQueue::dequeue()
{
    if (!is_empty()) {
        TreeNode* info = new TreeNode(*(vector[0]));

        delete vector[0];
        for (unsigned short int i = 0; i < used_size - 1; i++)
            vector[i] = vector[i + 1];

        vector[used_size] = nullptr;
        if (used_size == 1)
            vector[0] = nullptr;
        used_size--;

        return info;
    }
    cerr << "[PriorityQueue]: Tried to dequeue from an empty queue";
    exit(-6);
}

void PriorityQueue::order_vector()
{
    // Keep the non-null data on the left of vector
    unsigned short int i = 0;
    for (unsigned short int j = 0; j < SIZE; j++) {
        if (vector[j] != nullptr) {
            vector[i] = vector[j];
            if (i != j)
                vector[j] = nullptr;
            i++;
        }
    }

    // Order non-null data by frequency
    for (unsigned short int a = 0; a < used_size; a++) {
        for (unsigned short int b = a + 1; b < used_size; b++) {
            if ((*(vector[a])).get_data().get_frequency() > (*(vector[b])).get_data().get_frequency())
            {
                TreeNode* temp = new TreeNode(*(vector[a]));
                delete vector[a];
                vector[a] = vector[b];
                vector[b] = temp;
            }
        }
    }
}