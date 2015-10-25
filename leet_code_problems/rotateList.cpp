/**
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL
 */

#include <iostream>

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};


void printList(ListNode * node) {
	std::cout << "List: ";
	while( node ) {
		std::cout << node->val << " ";
		node = node->next;
	}
	std::cout << std::endl;
}

void insert(ListNode* &  head, int data ) {

	ListNode * newNode = new ListNode(data);
	if ( head == nullptr ) {
		head = newNode;
	} else {
		ListNode * curr = head;
		while ( curr->next != nullptr ) {
			curr = curr->next;
		}
		curr->next = newNode;
	}
}

int length(ListNode * head) {
	int count = 0;
	while( head ) {
		head = head->next;
		++count;
	}
	return count;
}


ListNode* rotateRight(ListNode* head, int k) {
	if ( head == nullptr ||  head->next == nullptr) {
		return head;
	}
	int len = length(head);
	k = k % len;
	if ( k == 0) {
		return head;
	}
	ListNode * ptr1 = head;
	ListNode * ptr2 = head;
	int c = 0;
	while( ptr1 && c < k ) {
		ptr1 = ptr1->next;
		c++;
	}
	if (!ptr1) {
		return nullptr;
	}
	while( ptr1 && ptr1->next != nullptr ) {
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	ListNode * newHead = ptr2->next;
	ptr2->next = nullptr;
	ptr1->next = head;
	return newHead;
}


int main() {
	ListNode * head = nullptr;
	insert( head, 1);
	insert( head, 2);
	insert( head, 3);
	insert( head, 4);
	insert( head, 5);
	printList(head);
	head = rotateRight(head, 2);
	printList(head);
	return 0;
}
