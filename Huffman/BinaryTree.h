#ifndef BINARYTREE
#define BINARYTREE

#include "TreeNode.h"
#include "PriorityQueue.h"
#include "ByteFrequency.h"
#include "CharCode.h"
#include "Code.h"


using namespace std;

class BinaryTree
{
    private:
        TreeNode* root, *current, *previous;
        unsigned int n_nodes;

        int count_nodes(TreeNode* node);

    public:
        BinaryTree();
        ~BinaryTree();

        unsigned int get_n_nodes() const;

        void create_tree_from_priority_queue(PriorityQueue queue);

        CharCode* visit_and_generate_codes();
        void visit_and_generate_codes_helper(TreeNode* node, bool** currentCode, unsigned int size);
        LinkedList generate_bytes_from_code(Code code);
};


#endif