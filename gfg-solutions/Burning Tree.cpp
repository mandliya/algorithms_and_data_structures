// https : // practice.geeksforgeeks.org/problems/burning-tree/1#

class Solution
{
public:
    Node *getTarget(Node *root, int target)
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();

            if (node->data == target)
            {
                return node;
            }

            if (node->left != NULL)
            {
                q.push(node->left);
            }

            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
    }

    void mark_parents(Node *root, unordered_map<Node *, Node *> &m)
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();

            if (node->left != NULL)
            {
                q.push(node->left);
                m[node->left] = node;
            }

            if (node->right != NULL)
            {
                q.push(node->right);
                m[node->right] = node;
            }
        }
    }

    int minTime(Node *root, int target)
    {
        Node *new_target = getTarget(root, target);

        unordered_map<Node *, Node *> m;
        mark_parents(root, m);

        int min_time = 0;

        unordered_map<Node *, bool> visited;

        queue<Node *> q;
        q.push(new_target);
        visited[new_target] = true;

        while (!q.empty())
        {
            int size = q.size();
            int flag = 0;

            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();

                if (node->left != NULL and !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left] = true;
                    flag = 1;
                }

                if (node->right != NULL and !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right] = true;
                    flag = 1;
                }

                if (m[node] != NULL and !visited[m[node]])
                {
                    q.push(m[node]);
                    visited[m[node]] = true;
                    flag = 1;
                }
            }

            if (flag == 1)
            {
                min_time++;
            }
        }

        return min_time;
    }
};