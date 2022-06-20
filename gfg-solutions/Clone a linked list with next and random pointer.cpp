// https : // practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1#

class Solution
{
public:
    Node *copyList(Node *head)
    {
        Node *curr = head;
        Node *front = head;

        while (curr != NULL)
        {
            front = curr->next;
            Node *copy = new Node(curr->data);
            curr->next = copy;
            copy->next = front;
            curr = front;
        }

        curr = head;

        while (curr != NULL)
        {
            if (curr->arb != NULL)
            {
                curr->next->arb = curr->arb->next;
            }

            curr = curr->next->next;
        }

        curr = head;
        Node *dummy = new Node(0);
        Node *copy = dummy;

        while (curr != NULL)
        {
            front = curr->next->next;

            copy->next = curr->next;
            curr->next = front;
            copy = copy->next;
            curr = front;
        }

        return dummy->next;
    }
};