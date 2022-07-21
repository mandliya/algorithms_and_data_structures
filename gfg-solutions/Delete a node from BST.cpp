// https : // practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1#

Node *
helper(Node *root)
{
    if (root->left == NULL)
    {
        return root->right;
    }
    else if (root->right == NULL)
    {
        return root->left;
    }

    Node *right_child = root->right;
    Node *left_right_max = root->left;

    while (left_right_max->right != NULL)
    {
        left_right_max = left_right_max->right;
    }

    left_right_max->right = right_child;

    return root->left;
}

Node *deleteNode(Node *root, int X)
{
    if (root == NULL)
        return NULL;
    if (root->data == X)
        return helper(root);

    Node *curr = root;

    while (curr != NULL)
    {
        if (curr->data < X)
        {
            if (curr->right != NULL and curr->right->data == X)
            {
                curr->right = helper(curr->right);
                break;
            }
            else
            {
                curr = curr->right;
            }
        }
        else
        {
            if (curr->left != NULL and curr->left->data == X)
            {
                curr->left = helper(curr->left);
                break;
            }
            else
            {
                curr = curr->left;
            }
        }
    }

    return root;
}