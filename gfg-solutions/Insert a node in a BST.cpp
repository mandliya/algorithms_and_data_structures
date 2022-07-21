// https : // practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1#

Node *
insert(Node *root, int Key)
{

    if (root == NULL)
    {
        root = new Node(Key);
        return root;
    }

    if (root->data == Key)
    {
        return root;
    }
    else if (root->data > Key)
    {
        root->left = insert(root->left, Key);
    }
    else if (root->data < Key)
    {
        root->right = insert(root->right, Key);
    }

    return root;
}