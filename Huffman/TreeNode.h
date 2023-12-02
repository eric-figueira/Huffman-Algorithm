#ifndef TREENODE
#define TREENODE

#include "ByteFrequency.h"


using namespace std;

class TreeNode
{
    private:
        TreeNode* left;
        TreeNode* right;
        ByteFrequency data;

    public:
        TreeNode* get_left()  const;
        TreeNode* get_right() const;
        ByteFrequency get_data() const;

        void set_data(ByteFrequency d);
        bool is_empty();

        TreeNode(ByteFrequency d, TreeNode* l, TreeNode* r);
        TreeNode(ByteFrequency d);
        TreeNode();
};

#endif
