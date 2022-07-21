// https : // practice.geeksforgeeks.org/problems/children-sum-parent/1#

class Solution
{
public:
    int isSumProperty(Node *root)
    {
        if (root == NULL or (root->left == NULL and root->right == NULL))
        {
            return 1;
        }

        else
        {
            int child = 0;

            if (root->left != NULL)
            {
                child += root->left->data;
            }

            if (root->right != NULL)
            {
                child += root->right->data;
            }

            return root->data == child and isSumProperty(root->left) and isSumProperty(root->right);
        }
    }
};