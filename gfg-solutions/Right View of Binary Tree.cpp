// https : // practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1#

class Solution
{
public:
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        vector<vector<int>> ds;

        if (root == NULL)
        {
            return ans;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> tmp(size);

            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();

                if (node->left != NULL)
                {
                    q.push(node->left);
                }

                if (node->right != NULL)
                {
                    q.push(node->right);
                }

                tmp[size - i - 1] = node->data;
            }

            ds.push_back(tmp);
        }

        for (int i = 0; i < ds.size(); i++)
        {
            for (int j = 0; j < ds[i].size(); j++)
            {
                ans.push_back(ds[i][0]);
                break;
            }
        }

        return ans;
    }
};

// Recursive

class Solution
{
public:
    void getRightView(Node *root, vector<int> &ans, int lvl)
    {
        if (root == NULL)
        {
            return;
        }

        if (lvl == ans.size())
        {
            ans.push_back(root->data);
        }

        getRightView(root->right, ans, lvl + 1);
        getRightView(root->left, ans, lvl + 1);
    }

    vector<int> rightView(Node *root)
    {
        vector<int> ans;

        getRightView(root, ans, 0);

        return ans;
    }
};