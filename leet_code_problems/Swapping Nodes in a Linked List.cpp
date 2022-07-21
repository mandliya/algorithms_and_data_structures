// https : // leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    ListNode *swapNodes(ListNode *head, int k)
    {

        ListNode *kth;
        ListNode *tmp1 = head;
        ListNode *tmp2 = head;

        while (--k)
        {
            tmp1 = tmp1->next;
        }

        kth = tmp1;
        tmp1 = tmp1->next;

        while (tmp1 != NULL)
        {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }

        swap(kth->val, tmp2->val);

        return head;
    }
};