/*
 * https://leetcode.com/problems/rotate-list/
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
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (head == NULL or head->next == NULL or k == 0)
        {
            return head;
        }

        ListNode *dummy = head;
        int length = 1;

        while (dummy->next != NULL)
        {
            dummy = dummy->next;
            length++;
        }

        dummy->next = head;
        k = k % length;
        k = length - k;

        while (k--)
        {
            dummy = dummy->next;
        }

        head = dummy->next;
        dummy->next = NULL;

        return head;
    }
};