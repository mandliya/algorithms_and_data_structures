// https : // practice.geeksforgeeks.org/problems/perfect-binary-tree/1/#

class Solution
{
public:
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

        if (abs(lh - rh) >= 1)
        {
            return -1;
        }

        return 1 + max(lh, rh);
    }
    bool isPerfect(Node *root)
    {
        return height(root) != -1;
    }
};