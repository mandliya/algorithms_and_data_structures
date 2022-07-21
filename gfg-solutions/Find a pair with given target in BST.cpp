// https : // practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1#

class Solution
{
public:
    void inorder_traversal(Node *root, vector<int> &inorder)
    {
        if (!root)
            return;

        inorder_traversal(root->left, inorder);
        inorder.push_back(root->data);
        inorder_traversal(root->right, inorder);
    }

    int isPairPresent(struct Node *root, int target)
    {
        vector<int> inorder;
        inorder_traversal(root, inorder);

        int i = 0, j = inorder.size() - 1;

        while (i < j)
        {
            if (inorder[i] + inorder[j] == target)
                return 1;
            else if (inorder[i] + inorder[j] < target)
                i++;
            else
                j--;
        }

        return 0;
    }
};