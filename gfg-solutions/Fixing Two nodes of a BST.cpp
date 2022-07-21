// https : // practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1#

class Solution
{
private:
    struct Node *prev;
    struct Node *first;
    struct Node *middle;
    struct Node *last;

public:
    void helper(struct Node *root)
    {
        if (!root)
            return;

        helper(root->left);

        if (prev != NULL and prev->data > root->data)
        {
            if (!first)
            {
                first = prev;
                middle = root;
            }
            else
                last = root;
        }

        prev = root;

        helper(root->right);
    }

    void correctBST(struct Node *root)
    {
        first = middle = last = NULL;

        prev = new Node(INT_MIN);

        helper(root);

        if (first and last)
            swap(first->data, last->data);
        else
            swap(first->data, middle->data);
    }
};
