/*
 * https://leetcode.com/problems/delete-node-in-a-bst/
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
    TreeNode *helper(TreeNode *root)
    {
        if (root->left == NULL)
        {
            return root->right;
        }
        else if (root->right == NULL)
        {
            return root->left;
        }

        TreeNode *right_child = root->right;
        TreeNode *left_right_max = root->left;

        while (left_right_max->right != NULL)
        {
            left_right_max = left_right_max->right;
        }

        left_right_max->right = right_child;

        return root->left;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;
        if (root->val == key)
            return helper(root);

        TreeNode *curr = root;

        while (curr != NULL)
        {
            if (curr->val < key)
            {
                if (curr->right != NULL and curr->right->val == key)
                {
                    curr->right = helper(curr->right);
                    break;
                }
                else
                {
                    curr = curr->right;
                }
            }
            else
            {
                if (curr->left != NULL and curr->left->val == key)
                {
                    curr->left = helper(curr->left);
                    break;
                }
                else
                {
                    curr = curr->left;
                }
            }
        }

        return root;
    }
};