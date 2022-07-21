/*
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void inorder_traversal(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
        {
            return;
        }

        inorder_traversal(root->left, inorder);
        inorder.push_back(root->val);
        inorder_traversal(root->right, inorder);
    }

    int getMinimumDifference(TreeNode *root)
    {
        vector<int> inorder;

        inorder_traversal(root, inorder);

        int min_val = INT_MAX;

        for (int i = 0; i < inorder.size() - 1; i++)
        {
            min_val = min(min_val, inorder[i + 1] - inorder[i]);
        }

        return min_val;
    }
};