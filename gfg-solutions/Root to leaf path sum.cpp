// https : // practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1#

class Solution
{
public:
    bool hasPathSum(Node *root, int S)
    {

        if (root == NULL)
        {
            return false;
        }

        S = S - root->data;

        if (S == 0 and root->left == NULL and root->right == NULL)
        {
            return true;
        }

        return hasPathSum(root->left, S) or hasPathSum(root->right, S);
    }
};