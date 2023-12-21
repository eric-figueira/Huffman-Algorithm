#ifndef TREENODE
#define TREENODE

#include "ByteFrequency.h"


using namespace std;

class TreeNode
{
    private:
        unsigned int SIZE = 256;
        TreeNode* left;
        TreeNode* right;
        ByteFrequency data;
        byte* under;
        unsigned short int size;

    public:
        TreeNode();
        TreeNode(ByteFrequency d, TreeNode* l, TreeNode* r);
        TreeNode(ByteFrequency d);
        TreeNode(const TreeNode& other);
        ~TreeNode();

        TreeNode* get_left()  const;
        TreeNode* get_right() const;
        ByteFrequency get_data() const;
        byte* get_under() const;
        unsigned short int get_size() const;

        void set_data(ByteFrequency d);
        void append_under(byte* under, unsigned short int size);
        void append_under(byte under);
        bool is_empty();
};

#endif
