// https : // leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode *swapPairs(ListNode *head)
    {

        if (head == NULL or head->next == NULL)
        {
            return head;
        }

        ListNode *first = head;
        ListNode *second = head;

        while (first != NULL and first->next != NULL)
        {
            second = second->next;
            swap(first->val, second->val);
            first = first->next->next;
            second = second->next;
        }

        return head;
    }
};

// Recursive Approach

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {

        if (head == NULL or head->next == NULL)
        {
            return head;
        }

        ListNode *first = head->next;
        ListNode *second = head->next->next;
        first->next = head;
        head->next = second;
        head->next = swapPairs(second);
        return first;
    }
};