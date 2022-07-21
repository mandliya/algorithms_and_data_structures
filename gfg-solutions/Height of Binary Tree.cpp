// https : // practice.geeksforgeeks.org/problems/height-of-binary-tree/0/#

class Solution
{
public:
    int height(struct Node *node)
    {

        if (node == NULL)
        {
            return 0;
        }

        int lh = height(node->left);
        int rh = height(node->right);

        return 1 + max(lh, rh);
    }
};