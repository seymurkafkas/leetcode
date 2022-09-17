struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    int get_value()
    {
        return val;
    }
};

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;

        if (p == nullptr || q == nullptr)
            return false;

        bool are_values_equal = p->val == q->val;
        bool is_left_subtree_equal = isSameTree(p->left, q->left);
        bool is_right_subtree_equal = isSameTree(p->right, q->right);
        return are_values_equal && is_left_subtree_equal && is_right_subtree_equal;
    }
};