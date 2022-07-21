// https : // practice.geeksforgeeks.org/problems/preorder-traversal-iterative/0/#

class Solution
{
public:
    vector<int> preOrder(Node *root)
    {
        vector<int> dfs_preorder;

        Node *curr = root;

        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                dfs_preorder.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                Node *prev = curr->left;

                while (prev->right != NULL and prev->right != curr)
                {
                    prev = prev->right;
                }

                if (prev->right == NULL)
                {
                    prev->right = curr;
                    dfs_preorder.push_back(curr->data);
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return dfs_preorder;
    }
};