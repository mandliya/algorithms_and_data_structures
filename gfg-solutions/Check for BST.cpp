// https: // practice.geeksforgeeks.org/problems/check-for-bst/1#

class Solution
{
public:
    bool helper(Node *root, long min_val, long max_val)
    {
        if (root == NULL)
            return true;
        if (root->data <= min_val or root->data >= max_val)
            return false;
        return helper(root->left, min_val, root->data) and helper(root->right, root->data, max_val);
    }

    bool isBST(Node *root)
    {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};