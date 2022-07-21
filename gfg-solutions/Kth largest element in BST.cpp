// https : // practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1/?company[]=SAP%20Labs&page=1&query=company[]SAP%20Labspage1#

class Solution
{
public:
    void inorderTraversal(Node *root, vector<int> &inorder)
    {
        if (root == NULL)
            return;

        inorderTraversal(root->right, inorder);
        inorder.push_back(root->data);
        inorderTraversal(root->left, inorder);
    }

    int kthLargest(Node *root, int K)
    {
        vector<int> inorder;
        inorderTraversal(root, inorder);

        return inorder[K - 1];
    }
};