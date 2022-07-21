// https : // practice.geeksforgeeks.org/problems/inorder-traversal/0/#

class Solution
{
public:
    void inOrderTraversal(Node *root, vector<int> &ds)
    {
        if (root == NULL)
        {
            return;
        }

        inOrderTraversal(root->left, ds);
        ds.push_back(root->data);
        inOrderTraversal(root->right, ds);
    }

    vector<int> inOrder(Node *root)
    {

        vector<int> ds;

        inOrderTraversal(root, ds);

        return ds;
    }
};