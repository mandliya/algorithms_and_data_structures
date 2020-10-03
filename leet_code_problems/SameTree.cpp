/* An algorithm to check if two binary trees are equal or not */
/* Equal means both the tree should have of same structure and equal value */

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
class Solution {
public:
    bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
        if(p == q)
            return true;
        else if(p == NULL || q == NULL)
            return false;
        else if(p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else
            return false;
        
    }
};