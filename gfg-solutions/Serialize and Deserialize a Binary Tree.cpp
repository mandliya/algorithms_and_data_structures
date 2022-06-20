// https : // practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1#

class Solution
{
public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        vector<int> ans;

        if (root == NULL)
        {
            return ans;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();

            if (node == NULL)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(node->data);
            }

            if (node != NULL)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }

        return ans;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &A)
    {
        if (A.size() == 0)
        {
            return NULL;
        }

        reverse(A.begin(), A.end());
        int i = 1;

        Node *root = new Node(A[A.size() - i]);
        queue<Node *> q;
        q.push(root);
        i++;

        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();

            if (A[A.size() - i] == -1)
            {
                node->left = NULL;
                i++;
            }
            else
            {
                Node *leftNode = new Node(A[A.size() - i]);
                i++;
                node->left = leftNode;
                q.push(leftNode);
            }

            if (A[A.size() - i] == -1)
            {
                node->right == NULL;
                i++;
            }
            else
            {
                Node *rightNode = new Node(A[A.size() - i]);
                i++;
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};
