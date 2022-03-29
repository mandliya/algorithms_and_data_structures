/*

 * https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        ListNode *newHead = NULL;

        if (list1 == NULL)
        {
            return list2;
        }
        if (list2 == NULL)
        {
            return list1;
        }

        if (list1->val < list2->val)
        {
            newHead = list1;
            list1->next = mergeTwoLists(list1->next, list2);
        }
        else
        {
            newHead = list2;
            list2->next = mergeTwoLists(list1, list2->next);
        }
        return newHead;
    }
};