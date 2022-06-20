// https : // practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

class Solution
{
public:
    static bool isLeaf(Node *root)
    {
        if (root->left == NULL and root->right == NULL)
        {
            return true;
        }

        return false;
    }

    void addLeft(Node *root, vector<int> &ans)
    {
        Node *curr = root->left;

        while (curr != NULL)
        {
            if (!isLeaf(curr))
            {
                ans.push_back(curr->data);
            }

            if (curr->left != NULL)
            {
                curr = curr->left;
            }

            else
            {
                curr = curr->right;
            }
        }
    }

    void addLeaves(Node *root, vector<int> &ans)
    {
        if (isLeaf(root))
        {
            ans.push_back(root->data);
            return;
        }

        if (root->left != NULL)
        {
            addLeaves(root->left, ans);
        }

        if (root->right != NULL)
        {
            addLeaves(root->right, ans);
        }
    }

    void addRight(Node *root, vector<int> &ans)
    {
        vector<int> tmp;
        Node *curr = root->right;

        while (curr != NULL)
        {
            if (!isLeaf(curr))
            {
                tmp.push_back(curr->data);
            }

            if (curr->right != NULL)
            {
                curr = curr->right;
            }

            else
            {
                curr = curr->left;
            }
        }

        for (int i = tmp.size() - 1; i >= 0; i--)
        {
            ans.push_back(tmp[i]);
        }
    }

    vector<int> boundary(Node *root)
    {
        vector<int> ans;

        if (root == NULL)
        {
            return ans;
        }

        if (!isLeaf(root))
        {
            ans.push_back(root->data);
        }

        addLeft(root, ans);
        addLeaves(root, ans);
        addRight(root, ans);

        return ans;
    }
};