/*

 * https://leetcode.com/problems/reverse-linked-list/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 */

// Iterative Approach
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *currHead = head;
        ListNode *prev = NULL;

        while (currHead != NULL)
        {
            ListNode *n = currHead->next;
            currHead->next = prev;
            prev = currHead;
            currHead = n;
        }

        return prev;
    }
};

// Recursive Approach

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        if (!head or !head->next)
        {
            return head;
        }

        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};