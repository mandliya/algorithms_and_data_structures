// https : // leetcode.com/problems/increasing-order-search-tree/

/**
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
    TreeNode *solve(TreeNode *root, TreeNode *tmp2)
    {
        if (root == NULL)
        {
            return tmp2;
        }

        tmp2 = solve(root->left, tmp2);
        tmp2->right = root;
        root->left = NULL;
        tmp2 = root;
        return solve(root->right, tmp2);
    }

    TreeNode *increasingBST(TreeNode *root)
    {

        TreeNode *tmp1 = new TreeNode(0);
        TreeNode *tmp2 = tmp1;

        solve(root, tmp2);

        return tmp1->right;
    }
};