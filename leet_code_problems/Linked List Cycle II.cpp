/*
 * https://leetcode.com/problems/linked-list-cycle-ii/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        unordered_map<ListNode *, bool> m;

        while (head != NULL)
        {
            if (m[head])
            {
                return head;
            }

            m[head] = true;
            head = head->next;
        }

        return NULL;
    }
};

/*
 * SC: O(1)
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        if (head == NULL or head->next == NULL)
        {
            return NULL;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *dummy = head;

        while (fast->next != NULL and fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                while (dummy != slow)
                {
                    slow = slow->next;
                    dummy = dummy->next;
                }

                return dummy;
            }
        }

        return NULL;
    }
};