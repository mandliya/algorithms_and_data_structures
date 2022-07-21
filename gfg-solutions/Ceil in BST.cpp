// https : // practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/0/?category[]=Binary%20Search%20Tree&page=1&sortBy=accuracy&query=category[]Binary%20Search%20Treepage1sortByaccuracy#

// Iterative

int findCeil(Node *root, int input)
{
    int ceil = -1;

    while (root != NULL)
    {
        if (root->data == input)
        {
            ceil = root->data;
            return ceil;
        }
        else if (root->data < input)
            root = root->right;
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }

    return ceil;
}

// Recursive

int helper(Node *root, int input, int ceil)
{
    if (root == NULL)
    {
        return ceil;
    }

    else if (root->data == input)
    {
        return root->data;
    }

    else if (root->data < input)
    {
        helper(root->right, input, ceil);
    }

    else
    {
        ceil = root->data;
        helper(root->left, input, ceil);
    }
}
int findCeil(Node *root, int input)
{
    int ceil = -1;

    return helper(root, input, ceil);
}