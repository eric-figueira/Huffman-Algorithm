#ifndef BYNARYTREE
#define BYNARYTREE

#include "TreeNode.h"

template <typename T>
class BynaryTree
{
  private:
    TreeNode<T> *first, *current, *previous;

  public:
    BynaryTree();

    void insert_node(T data);
};


#endif