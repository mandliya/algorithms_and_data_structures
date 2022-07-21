// https : // practice.geeksforgeeks.org/problems/search-a-node-in-bst/1#

// Recursive

bool search(Node *root, int x)
{
    if (root == NULL)
        return false;
    if (root->data == x)
        return true;
    else if (root->data < x)
        return search(root->right, x);
    else
        search(root->left, x);
}

// Iterative

bool search(Node *root, int x)
{
    while (root != NULL)
    {
        if (root->data == x)
            return true;
        else if (root->data < x)
            root = root->right;
        else
            root = root->left;
    }

    return false;
}
