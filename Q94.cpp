#include <vector>
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
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::vector<int> traversal_results;
        traverse(root, traversal_results);
        return traversal_results;
    }

    void traverse(TreeNode *element, std::vector<int> &out_result)
    {
        if (!element)
            return;

        traverse(element->left, out_result);
        out_result.push_back(element->val);
        traverse(element->right, out_result);
    }
};