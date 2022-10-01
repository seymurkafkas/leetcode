#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;

        invert_all_subtrees(root);
        return root;
    }

private:
    void swap_children(TreeNode *node)
    {
        TreeNode *left = node->left;
        node->left = node->right;
        node->right = left;
    }

    void invert_all_subtrees(TreeNode *node)
    {
        if (!node)
            return;

        swap_children(node);
        invert_all_subtrees(node->left);
        invert_all_subtrees(node->right);
    }
};
