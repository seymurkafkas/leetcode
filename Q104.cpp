#include <algorithm>

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
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        int left_subtree_max_depth = maxDepth(root->left);
        int right_subtree_max_depth = maxDepth(root->right);

        int max_depth = std::max(left_subtree_max_depth, right_subtree_max_depth) + 1;
        return max_depth;
    }
};