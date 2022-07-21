// https : // practice.geeksforgeeks.org/problems/reverse-a-linked-list/0/#

/* Linked List Node structure:
struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
public:
    struct Node *reverseList(struct Node *head)
    {
        Node *dummy = NULL;

        while (head != NULL)
        {
            Node *node = head->next;
            head->next = dummy;
            dummy = head;
            head = node;
        }

        return dummy;
    }
};