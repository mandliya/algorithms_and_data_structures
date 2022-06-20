// https : // practice.geeksforgeeks.org/problems/level-order-traversal/1#

class Solution
{
public:
    vector<int> levelOrder(Node *root)
    {
        vector<int> level;

        if (root == NULL)
        {
            return level;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();

            Node *n = q.front();
            q.pop();

            if (n->left != NULL)
            {
                q.push(n->left);
            }

            if (n->right != NULL)
            {
                q.push(n->right);
            }

            level.push_back(n->data);
        }

        return level;
    }
};