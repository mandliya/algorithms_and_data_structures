// https : // practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1#

int countLeaves(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL and root->right == NULL)
    {
        return 1;
    }

    return countLeaves(root->left) + countLeaves(root->right);
}