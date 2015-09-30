/**
 * Given a singly linked list L0 -> L1 -> … -> Ln-1 -> Ln.
 * Rearrange the nodes in the list so that the new formed list is : L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 …
 * Example:
 * Input:  1 -> 2 -> 3 -> 4
 * Output: 1 -> 4 -> 2 -> 3
 * Input:  1 -> 2 -> 3 -> 4 -> 5
 * Output: 1 -> 5 -> 2 -> 4 -> 3 
 */

#include <iostream>

struct Node {
  int data;
  Node * next;
  Node( int d )
    : data{ d }, next{ nullptr } { }
};

void printList( Node * node )
{
  while( node ) {
    std::cout << node->data << "-->";
    node = node->next;
  }
  std::cout << "NULL" << std::endl;
}

void reverse( Node * & head )
{
  Node * nextNode = nullptr;
  Node * newHead = nullptr;
  Node * curr = head;
  while( curr ) {
    nextNode = curr->next;
    curr->next = newHead;
    newHead = curr;
    curr = nextNode;
  }
  head = newHead;
}

Node * middleNode( Node * head )
{
  Node * slowPtr = head;
  Node * fastPtr = head;
  while( fastPtr && fastPtr->next ) {
    fastPtr = fastPtr->next->next;
    slowPtr = slowPtr->next;
  }
  return slowPtr;
}

void rearrange( Node * & head )
{
  //step 1 split the list in two lists first half and second half
  Node * midNode = middleNode(head);
  Node * itr1 = head;
  Node * itr2 = midNode->next;
  midNode->next = nullptr;

  //step 2 reverse the second half
  reverse(itr2);

  //step 3 - merge the alternate nodes of these two list in one list.
  //dummy node as head
  Node * newHead = new Node(0);
  Node * curr = newHead;
  while( itr1 || itr2 ) {
    if (itr1) {
      curr->next = itr1;
      curr = curr->next;
      itr1 = itr1->next;
    }
    if (itr2) {
      curr->next = itr2;
      curr = curr->next;
      itr2 = itr2->next;
    }
  }

  //update the head
  head = newHead->next;
}


int main()
{
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);
  printList(head);
  rearrange(head);
  printList(head);
  return 0;
}
