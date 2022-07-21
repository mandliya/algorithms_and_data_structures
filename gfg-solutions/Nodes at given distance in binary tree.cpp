// https : // practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1#

class Solution
{
private:
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

public:
    Node *lvlOrderTraversal(Node *root, int target)
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *n = q.front();
            q.pop();

            if (n->data == target)
            {
                return n;
            }

            if (n->left != NULL)
            {
                q.push(n->left);
            }

            if (n->right != NULL)
            {
                q.push(n->right);
            }
        }

        return NULL;
    }

    vector<int> KDistanceNodes(Node *root, int t, int k)
    {
        Node *target = lvlOrderTraversal(root, t);

        unordered_map<Node *, Node *> m;
        mark_parents(root, m);

        unordered_map<Node *, bool> visited;
        queue<Node *> q;
        q.push(target);
        visited[target] = true;

        int has_reached_k = 0;

        while (!q.empty())
        {
            int size = q.size();

            if (has_reached_k == k)
            {
                break;
            }

            has_reached_k++;

            for (int i = 0; i < size; i++)
            {
                Node *current = q.front();
                q.pop();

                if (current->left != NULL and !visited[current->left])
                {
                    q.push(current->left);
                    visited[current->left] = true;
                }

                if (current->right != NULL and !visited[current->right])
                {
                    q.push(current->right);
                    visited[current->right] = true;
                }

                if (m[current] != NULL and !visited[m[current]])
                {
                    q.push(m[current]);
                    visited[m[current]] = true;
                }
            }
        }

        vector<int> ans;

        while (!q.empty())
        {
            ans.push_back(q.front()->data);
            q.pop();
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};