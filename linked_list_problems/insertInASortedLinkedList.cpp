/**
 *  Given a sorted linkedlist, insert a new node in it, so that list remains sorted.
 */

#include <iostream>

struct Node {
  int data;
  Node * next;
  Node ( int d ) : data{ d }, next{ nullptr } { }
};

void sortedInsert( Node * & head, int data )
{
  Node * newNode = new Node( data );
  if ( head == nullptr ||
       ((head != nullptr) && (head->data >= newNode->data))) {
      newNode->next = head;
      head = newNode;
  } else {
    Node * currNode = head;
    while ( currNode->next != nullptr && (currNode->next->data < newNode->data)) {
      currNode = currNode->next;
    }
    newNode->next = currNode->next;
    currNode->next = newNode;
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

int main()
{
  Node * head = nullptr;
  std::cout << "Inserting 3 to the List, List becomes\n";
  sortedInsert( head,  3 );
  printList( head );
  std::cout << "Inserting 1 to the List, List becomes\n";
  sortedInsert( head,  1 );
  printList( head );
  std::cout << "Inserting 2 to the List, List becomes\n";
  sortedInsert( head,  2 );
  printList( head );
  std::cout << "Inserting 5 to the List, List becomes\n";
  sortedInsert( head,  5 );
  printList( head );
  std::cout << "Inserting 4 to the List, List becomes\n";
  sortedInsert( head,  4 );
  printList( head );
  std::cout << "Inserting 2 to the List, List becomes\n";
  sortedInsert( head,  2 );
  printList( head );
  std::cout << "Inserting 6 to the List, List becomes\n";
  sortedInsert( head,  6 );
  printList( head );
  return 0;
}
