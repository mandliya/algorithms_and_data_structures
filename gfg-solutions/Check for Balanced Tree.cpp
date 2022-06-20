// https : // practice.geeksforgeeks.org/problems/check-for-balanced-tree/1#

class Solution
{
public:
    // Function to check whether a binary tree is balanced or not.

    int height(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = height(root->left);

        if (lh == -1)
        {
            return -1;
        }

        int rh = height(root->right);

        if (rh == -1)
        {
            return -1;
        }

        if (abs(lh - rh) > 1)
        {
            return -1;
        }

        return max(lh, rh) + 1;
    }

    bool isBalanced(Node *root)
    {
        return height(root) != -1;
    }
};