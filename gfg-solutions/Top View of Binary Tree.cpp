// https : // practice.geeksforgeeks.org/problems/top-view-of-binary-tree/0/#

class Solution
{
public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;

        if (root == NULL)
        {
            return ans;
        }

        map<int, int> m;
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            pair<Node *, int> p = q.front();
            q.pop();

            Node *node = p.first;
            int vertical = p.second;

            if (m.find(vertical) == m.end())
            {
                m[vertical] = node->data;
            }

            if (node->left != NULL)
            {
                q.push({node->left, vertical - 1});
            }

            if (node->right != NULL)
            {
                q.push({node->right, vertical + 1});
            }
        }

        for (auto i : m)
        {
            ans.push_back(i.second);
        }

        return ans;
    }
};