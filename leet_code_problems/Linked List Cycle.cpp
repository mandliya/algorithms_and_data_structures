// https : // leetcode.com/problems/linked-list-cycle/

/*
 * Hashing
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
    bool hasCycle(ListNode *head)
    {

        unordered_map<ListNode *, int> m;
        ListNode *tmp = head;

        while (tmp != NULL)
        {
            m[tmp]++;
            tmp = tmp->next;

            if (m.find(tmp) != m.end())
            {
                return true;
            }
        }

        return false;
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
    bool hasCycle(ListNode *head)
    {

        if (head == NULL or head->next == NULL)
        {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != NULL and fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};