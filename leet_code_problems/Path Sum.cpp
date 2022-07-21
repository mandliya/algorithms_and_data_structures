// https: // leetcode.com/problems/path-sum/

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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
        {
            return false;
        }

        targetSum = targetSum - root->val;

        if (targetSum == 0 and root->left == NULL and root->right == NULL)
        {
            return true;
        }

        return (hasPathSum(root->left, targetSum) or hasPathSum(root->right, targetSum));
    }
};