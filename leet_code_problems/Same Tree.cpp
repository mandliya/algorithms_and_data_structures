/*
 * https://leetcode.com/problems/same-tree/
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {

        if (p == NULL or q == NULL)
        {
            return p == q;
        }

        return p->val == q->val and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};