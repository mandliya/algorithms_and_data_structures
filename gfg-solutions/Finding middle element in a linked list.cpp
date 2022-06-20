// https : // practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/0/

/* Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */
class Solution
{
public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {

        if (head == NULL or head->next == NULL)
        {
            return head->data;
        }
        // Your code here

        Node *fast = head;
        Node *slow = head;

        while (fast != NULL and fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow->data;
    }
};
