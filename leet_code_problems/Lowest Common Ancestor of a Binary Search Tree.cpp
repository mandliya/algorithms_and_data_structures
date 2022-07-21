/*
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while (root != NULL)
        {
            if (p->val < root->val and q->val < root->val)
            {
                root = root->left;
            }
            else if (p->val > root->val and q->val > root->val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }

        return NULL;
    }
};