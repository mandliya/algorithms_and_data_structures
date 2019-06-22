/*
 * We have two numbers represented by a linked list, 
 * where each node contains a single digit. The digits are stored in reverse order,
 * such that the 1's digit is at the head of the list.
 * Write a function that adds the two numbers and returns the sum as a linked list.
 *
 * Example
 * Given 7->1->6 + 5->9->2. That is, 617 + 295.
 *
 * Return 2->1->9. That is 912.
 *
 * Given 3->1->5 and 5->9->2, return 8->0->8.
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v): val(v), next(nullptr)
    { }
};

ListNode * addLists( ListNode * list1, ListNode *list2 )
{
    ListNode *list3 = nullptr;
    ListNode *curr = nullptr;
    int carry = 0;

    // both list1 and list2 are not null
    while ( list1 && list2 ) {
        int x = list1->val + list2->val + carry;
        if ( x  > 9 ) {
            carry = 1;
            x -= 10;
        } else {
            carry = 0;
        }
        if (list3 == nullptr) {
            list3 = new ListNode(x);
            curr = list3;
        } else {
            curr->next = new ListNode(x);
            curr = curr->next;
        }
        list1 = list1->next;
        list2 = list2->next;
    }

    // list2 is null
    while(list1) {
        int x = list1->val + carry;
        if ( x  > 9 ) {
            carry = 1;
            x -= 10;
        } else {
            carry = 0;
        }
        curr->next = new ListNode(x);
        curr = curr->next;
        list1 = list1->next;
    }

    // list1 is null
    while(list2) {
        int x = list2->val + carry;
        if ( x  > 9 ) {
            carry = 1;
            x -= 10;
        } else {
            carry = 0;
        }
        curr->next = new ListNode(x);
        curr = curr->next;
        list2 = list2->next;
    }
    if (carry > 0) {
        curr->next = new ListNode(carry);
        curr  = curr->next;
    }
    return list3;
}

void iterate(ListNode *node) {
    while (node) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main()
{
    ListNode *list1, *list2;
    list1 = new ListNode(9);
    list1->next = new  ListNode(9);

    list2 = new ListNode(5);
    list2->next = new ListNode(9);
    list2->next->next = new ListNode(2);

    iterate(list1);
    iterate(list2);
    ListNode *list3 = addLists(list1, list2);
    iterate(list3);
    return 0;
}
