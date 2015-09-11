#include <iostream>

struct Node {
  int data;
  Node * next;
  Node( int d ) : data{ d }, next{ nullptr } { }
};

void push( Node * & head, int data ) {
  Node *newNode = new Node(data);
  if ( head == nullptr ) {
    head = newNode;
  } else {
    Node *curr = head;
    while( curr->next != nullptr ) {
      curr = curr->next;
    }
    curr->next = newNode;
  }
}

void printList( Node * head ) {
  while( head ) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "NULL" << std::endl;
}

void reverseIter( Node * & head ) {
  //length of list is less than 2
  if ( head == nullptr || ( head != nullptr && head->next == nullptr )) {
    return;
  }
  Node *newHead = nullptr;
  Node *curr = head;
  Node *prev = nullptr;
  while( curr != nullptr ) {
    prev = curr;
    curr = curr->next;
    prev->next = newHead;
    newHead = prev;
  }
  head = newHead;
}

void reverseRecur( Node * & head ) {
  if ( head == nullptr || ( head != nullptr && head->next == nullptr ) ) {
    return;
  }
  Node * first = head;
  Node * rest = head->next;
  reverseRecur( rest );
  first->next->next = first;
  first->next = nullptr;
  head = rest;
}

int main() {
  Node *head = nullptr;
  push( head, 1 );
  push( head, 2 );
  push( head, 3 );
  push( head, 4 );
  push( head, 5 );
  std::cout << "Before Reversing Linkedlist:      ";
  printList( head );
  reverseIter( head );
  std::cout << "After Reversing Linkedlist once:  ";
  printList( head );
  reverseRecur( head );
  std::cout << "After Reversing Linkedlist twice: ";
  printList( head );
  return 0;
}
