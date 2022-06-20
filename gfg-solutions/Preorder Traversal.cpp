// https : // practice.geeksforgeeks.org/problems/preorder-traversal/1/?page=2&category[]=Tree&sortBy=submissions#

void preOrderTraversal(Node *root, vector<int> &ds)
{
    if (root == NULL)
    {
        return;
    }
    ds.push_back(root->data);
    preOrderTraversal(root->left, ds);

    preOrderTraversal(root->right, ds);
}

vector<int> preorder(Node *root)
{

    vector<int> ds;

    preOrderTraversal(root, ds);

    return ds;
}