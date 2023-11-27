#ifndef TREENODE
#define TREENODE


template <typename Data>
class TreeNode
{
private:
    TreeNode* left;
    TreeNode* right;
    Data data;

public:
    TreeNode* get_left()  const;
    TreeNode* get_right() const;
    Data      get_data()  const;

    void set_data(Data d);
    bool is_empty();

    TreeNode(Data d, TreeNode* l, TreeNode* r);
    TreeNode(Data d);
    TreeNode();
};

#endif
