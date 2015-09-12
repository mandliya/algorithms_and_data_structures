/**
 *  Print middle node of linkedlist in one iteration.
 */

#include <iostream>

struct Node {
  int data;
  Node * next;
  Node( int d ) : data{ d }, next{ nullptr } { }
};

void insert( Node * & head, int data )
{
  Node * newNode  = new Node( data );
  if ( head == nullptr ) {
    head = newNode;
  } else {
    Node * temp = head;
    while( temp->next != nullptr ) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void printList( Node * head )
{
  while ( head ) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "NULL" << std::endl;
}

Node * middleNode( Node * head )
{
  Node * fastPtr = head;
  Node * slowPtr = head;
  while ( fastPtr != nullptr && fastPtr->next != nullptr) {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }
  return slowPtr;
}

int main()
{
  Node * head = nullptr;
  insert( head, 1 );
  insert( head, 2 );
  insert( head, 3 );
  insert( head, 4 );
  insert( head, 5 );
  printList( head );
  std::cout << "Middle node is : ";
  Node * mid = middleNode( head );
  std::cout << mid->data << std::endl;
  return 0;
}
