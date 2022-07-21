// https : // practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1#

// Iterative

class Solution
{
public:
    int minDiff(Node *root, int K)
    {
        int min_val = INT_MAX;

        while (root != NULL)
        {

            if (root->data == K)
            {
                return 0;
            }

            else if (root->data > K)
            {
                min_val = min(min_val, abs(K - root->data));
                root = root->left;
            }
            else
            {
                min_val = min(min_val, abs(K - root->data));
                root = root->right;
            }
        }

        return min_val;
    }
};

// Recursive

class Solution
{
public:
    void helper(Node *root, int K, int &min_val)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->data == K)
        {
            min_val = 0;
            return;
        }

        else if (root->data < K)
        {
            min_val = min(min_val, abs(root->data - K));
            return helper(root->right, K, min_val);
        }
        else
        {
            min_val = min(min_val, abs(root->data - K));
            return helper(root->left, K, min_val);
        }
    }

    int minDiff(Node *root, int K)
    {
        int min_val = INT_MAX;

        helper(root, K, min_val);

        return min_val;
    }
};