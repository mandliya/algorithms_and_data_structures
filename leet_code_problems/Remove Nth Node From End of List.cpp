/**https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode *slow = head;
        ListNode *fast = head;

        while (n > 0)
        {
            fast = fast->next;
            n--;
        }

        if (fast == NULL)
        {
            return slow->next;
        }

        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *tmp = slow->next;
        slow->next = tmp->next;
        tmp->next = NULL;
        delete tmp;

        return head;
    }
};