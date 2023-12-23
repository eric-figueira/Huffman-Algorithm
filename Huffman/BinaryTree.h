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

        void destructor(TreeNode* node);
        void create_codes(TreeNode* node, CharCode* codes, TreeNode* newNode, unsigned short int *index, bool val);
        //void visit_and_generate_codes_helper(TreeNode* node, bool* currentCode, unsigned int size);

    public:
        BinaryTree();
        ~BinaryTree();

        unsigned int get_n_nodes() const;

        void create_tree_from_priority_queue(PriorityQueue* queue, CharCode* codes = nullptr);
        //CharCode* visit_and_generate_codes();

        LinkedList generate_bytes_from_code(Code code);
};


#endif