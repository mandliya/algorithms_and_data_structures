// https : // practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/0/#

/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
    if (head == NULL)
    {
        return -1;
    }

    Node *dummy = head;

    int len = 0;

    while (dummy != NULL)
    {
        dummy = dummy->next;
        len++;
    }

    if (n > len)
    {
        return -1;
    }

    len = len - n;

    while (len--)
    {
        head = head->next;
    }

    return head->data;
}
