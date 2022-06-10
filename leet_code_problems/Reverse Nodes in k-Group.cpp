/*
 * https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        if (head == NULL or k == 1)
        {
            return head;
        }

        ListNode *dummy = new ListNode(0);

        dummy->next = head;

        ListNode *curr = dummy;
        ListNode *prev = dummy;
        ListNode *nex = dummy;

        int cnt = 0;

        while (curr->next != NULL)
        {
            curr = curr->next;
            cnt++;
        }

        while (cnt >= k)
        {
            curr = prev->next;
            nex = curr->next;

            for (int i = 1; i < k; i++)
            {
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }

            prev = curr;
            cnt -= k;
        }

        return dummy->next;
    }
};