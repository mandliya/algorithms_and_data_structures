/*
 * Problem : Given a linked list, and two data values, x and y. 
 * Goal:     Swap the nodes of linkedlist by swapping pointers 
 *           (and not swapping data) such that nodes with data x will contain y and vice versa.
 *
 */


#include <iostream>


struct Node {
  int data;
  Node* next;
  Node(int d) : data{d}, next{nullptr} { }
};


/**** Algorithm Function ****/
void swapSpecial(Node* & head, int x, int y) {

  //empty list
  if (head == nullptr) {
    return;
  }

  //nothing to do if both are values are same.
  if ( x == y ) {
    return;
  }

  Node * prevx = nullptr;
  Node * currx = head;
  Node * prevy = nullptr;
  Node * curry = head;

  //search for x
  while ( currx && currx->data != x ) {
    prevx = currx;
    currx = currx->next;
  }
  //search for y
  while ( curry && curry->data != y ) {
    prevy = curry;
    curry = curry->next;
  }
  //x or y not found
  if ( currx == nullptr || curry == nullptr ) {
    return;
  }

  //if x is not head
  if ( prevx != nullptr ) {
    prevx->next = curry;
  } else {
    head = curry;
  }

  //similarly if y is not head
  if ( prevy != nullptr) {
    prevy->next = currx;
  } else {
    head = currx;
  }

  //now lets swap the next pointers
  Node *temp = curry->next;
  curry->next = currx->next;
  currx->next = temp;
}

void insert(Node* & head, int data) {
  if (head == nullptr) {
    head = new Node(data);
    return;
  }
  Node *temp = head;
  while(temp->next != nullptr) {
    temp = temp->next;
  }
  temp->next = new Node(data);
}

void printList(Node * head) {
  while (head) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "null" << std::endl;
}

int main() {
  Node *head = nullptr;
  insert(head, 10);
  insert(head, 15);
  insert(head, 12);
  insert(head, 13);
  insert(head, 20);
  insert(head, 14);
  printList(head);
  std::cout << "Replacing 12 with 20 and 20 with 12:\n";
  swapSpecial(head, 12, 20);
  printList(head);

  return 0;
}
