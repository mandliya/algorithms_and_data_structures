// https : // practice.geeksforgeeks.org/problems/count-nodes-of-linked-list/0/#

class Solution
{
public:
    int getCount(struct Node *head)
    {

        struct Node *curr = head;

        int cnt = 1;

        while (curr->next != NULL)
        {
            curr = curr->next;
            cnt++;
        }

        return cnt;
    }
};
