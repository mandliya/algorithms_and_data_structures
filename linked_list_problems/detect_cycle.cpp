#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        bool done = false;
        while (head) {
            if (seen.find(head) != seen.end()) {
                return true;
            }
            seen.insert(head);
            head = head->next;
        }
        return false;
    }
    void printList(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main () {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    Solution solver;
    if (solver.hasCycle(head->next)) {
        cout << "The list has cycle." << endl;
    } else {
        cout << "The list does not have a cycle!" << endl;
    }
}