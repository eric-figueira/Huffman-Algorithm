#ifndef BINARYTREE
#define BINARYTREE

#include "TreeNode.h"
#include "PriorityQueue.h"
#include "ByteFrequency.h"
#include "CharCode.h"

class BinaryTree
{
  private:
    TreeNode<ByteFrequency> *first, *current, *previous;
    unsigned int n_nodes;

  public:
    BinaryTree();

    unsigned int get_n_nodes() const;

    void create_tree_from_priority_queue(PriorityQueue queue);
    CharCode* visit_and_generate_codes();
};


#endif