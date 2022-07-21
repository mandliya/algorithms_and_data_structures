// https : // practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1/?page=1&category[]=Linked%20List&curated[]=1&sortBy=submissions#

class Solution
{
public:
    bool detectLoop(Node *head)
    {
        if (head == NULL or head->next == NULL)
        {
            return false;
        }

        Node *slow = head;
        Node *fast = head;

        while (fast != NULL and fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
            {
                return true;
            }
        }

        return false;
    }
};