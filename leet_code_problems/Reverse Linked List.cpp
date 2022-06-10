/* https://leetcode.com/problems/reverse-linked-list/

// Iterative Approach
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
    ListNode *reverseList(ListNode *head)
    {

        ListNode *dummy = NULL;

        while (head != NULL)
        {
            ListNode *n = head->next;
            head->next = dummy;
            dummy = head;
            head = n;
        }

        return dummy;
    }
};

// Recursive Approach
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
    ListNode *reverseList(ListNode *head)
    {

        if (head == NULL or head->next == NULL)
        {
            return head;
        }

        ListNode *newHead = reverseList(head->next);
        ListNode *headNext = head->next;
        headNext->next = head;
        head->next = NULL;
        return newHead;
    }
};