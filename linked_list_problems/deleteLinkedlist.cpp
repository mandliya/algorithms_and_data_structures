/**
 *  Write a simple function to delete a linkedList
 */

#include <iostream>

struct Node {
  int data;
  Node * next;
  Node( int d ) : data{ d }, next{ nullptr } { }
};

void insert( Node * & head, int data )
{
  Node * newNode = new Node( data );
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
   while( head ) {
     std::cout << head->data << "-->";
     head = head->next;
   }
   std::cout << "NULL" << std::endl;
 }

 void deleteList( Node * & head )
 {
    while( head ) {
      Node * nextNode = head->next;
      delete( head );
      head = nextNode;
    }
 }

 int main()
 {
   Node * head = nullptr;
  insert( head, 1 );
  insert( head, 2 );
  insert( head, 3 );
  std::cout << "Current  List: ";
  printList( head );
  std::cout << "Deleting List \n";
  deleteList( head );
  std::cout << "Printing List: ";
  printList( head );
  return 0;
 }
