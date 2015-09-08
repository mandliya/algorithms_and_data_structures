/*
 * Given a linked list, reverse alternate nodes and append at the end
 * Examples:
 * Input List:  1->2->3->4->5->6
 * Output List: 1->3->5->6->4->2
 *
 * Input List:  12->14->16->18->20
 * Output List: 12->16->20->18->14
 */

#include <iostream>

struct Node {
  int data;
  Node * next;
  Node(int d) : data{ d }, next{ nullptr } { }
};

void insertAtHead( Node * & head, Node * node ) {
  if ( head != nullptr ) {
    node->next = head;
  }
  head = node;
}

void insert( Node * & head, int data ) {
  Node * newNode = new Node(data);
  if ( head == nullptr ) {
    head = newNode;
  } else {
    Node * curr = head;
    while( curr->next ) {
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

 /* Algorithm function */
 void rearrange( Node * & head ) {
   if ( head == nullptr ) {
     return;
   }
   Node * curr = head;
   Node * forw = head->next;
   if ( forw == nullptr ) {
     return;
   }
   Node * backHead = nullptr;
   while ( curr != nullptr && forw != nullptr ) {
     curr->next = forw->next;
     forw->next = nullptr;
     insertAtHead( backHead, forw );
     curr = curr->next;
     if (curr != nullptr ) {
       forw = curr->next;
     }
   }
   //adding the backlist to mainlist again.
   curr = head;
   while ( curr->next != nullptr ) {
     curr = curr->next;
   }
   curr->next = backHead;
 }

 int main() {
  Node * head = nullptr;
  insert( head, 1 );
  insert( head, 2 );
  insert( head, 3 );
  insert( head, 4 );
  insert( head, 5 );
  insert( head, 6 );
  std::cout << "List before rearrange: ";
  printList( head );
  rearrange( head );
  std::cout << "List after  rearrange: ";
  printList( head );

  Node * head2 = nullptr;
  insert( head2, 12 );
  insert( head2, 14 );
  insert( head2, 16 );
  insert( head2, 18 );
  insert( head2, 20 );
  std::cout << "List before rearrange: ";
  printList( head2 );
  rearrange( head2 );
  std::cout << "List after  rearrange: ";
  printList( head2 );

  return 0;
 }
