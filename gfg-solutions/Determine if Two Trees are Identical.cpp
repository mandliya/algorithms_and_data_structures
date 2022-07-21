// https : // practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/0/#

class Solution
{
public:
    bool isIdentical(Node *r1, Node *r2)
    {
        if (r1 == NULL and r2 == NULL)
        {
            return true;
        }

        if ((r1 == NULL and r2 != NULL) or (r1 != NULL and r2 == NULL))
        {
            return false;
        }

        if (r1->data != r2->data)
        {
            return false;
        }

        bool leftCheck = isIdentical(r1->left, r2->left);
        bool rightCheck = isIdentical(r1->right, r2->right);

        return leftCheck and rightCheck;
    }
};