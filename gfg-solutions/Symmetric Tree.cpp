// https : // practice.geeksforgeeks.org/problems/symmetric-tree/1#

class Solution
{
public:
    bool helper(Node *root1, Node *root2)
    {
        if (root1 == NULL or root2 == NULL)
        {
            return root1 == root2;
        }

        if (root1->data != root2->data)
        {
            return false;
        }

        return helper(root1->left, root2->right) and helper(root1->right, root2->left);
    }

    bool isSymmetric(struct Node *root)
    {
        if (root == NULL)
        {
            return true;
        }

        return helper(root->left, root->right);
    }
};