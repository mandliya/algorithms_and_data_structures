// https : // practice.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0/#

class Solution
{
public:
    Node *insertAtBegining(Node *head, int x)
    {

        Node *n = new Node(x);
        n->next = head;
        head = n;

        return head;
    }

    Node *insertAtEnd(Node *head, int x)
    {

        Node *node = new Node(x);

        if (head == NULL)
        {
            return node;
        }

        Node *tmp = head;

        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        tmp->next = node;

        return head;
    }
};
