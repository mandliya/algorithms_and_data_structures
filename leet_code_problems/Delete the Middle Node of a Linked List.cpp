// https : // leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {

        if (head->next == NULL)
        {
            delete head;
            return NULL;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;
        ListNode *prev;

        while (fast != NULL and fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast == NULL)
        {
            prev->next = slow->next;
            slow->next = NULL;
            delete slow;
            return head;
        }

        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
};