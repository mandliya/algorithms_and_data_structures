// https: // practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1#

class Solution
{
public:
    int KthSmallestElement(Node *root, int K)
    {
        int find_k = K;
        int kth_smallest = -1;

        Node *curr = root;

        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                find_k--;

                if (find_k == 0)
                {
                    kth_smallest = curr->data;
                }

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
                    curr = curr->left;
                }
                else
                {
                    find_k--;

                    if (find_k == 0)
                    {
                        kth_smallest = curr->data;
                    }

                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return kth_smallest;
    }
};
