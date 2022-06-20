// https : // practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/0/#

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution
{
public:
    // Function to check whether the list is palindrome.

    Node *reverseList(Node *head)
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

    bool isPalindrome(Node *head)
    {

        if (head == NULL or head->next == NULL)
        {
            return true;
        }

        Node *slow = head;
        Node *fast = head;

        while (fast->next != NULL and fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow->next = reverseList(slow->next);
        slow = slow->next;

        while (slow != NULL)
        {
            if (slow->data != head->data)
            {
                return false;
            }

            slow = slow->next;
            head = head->next;
        }

        return true;
    }
};
