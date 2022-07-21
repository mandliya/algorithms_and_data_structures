/*

 * https://leetcode.com/problems/validate-binary-search-tree/
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
    bool helper(TreeNode *root, long long minVal = -10000000000, long long maxVal = 10000000000)
    {
        if (root == NULL)
        {
            return true;
        }

        bool left = helper(root->left, minVal, root->val);
        bool right = helper(root->right, root->val, maxVal);

        if (left && right && root->val > minVal && root->val < maxVal)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isValidBST(TreeNode *root)
    {

        return helper(root);
    }
};