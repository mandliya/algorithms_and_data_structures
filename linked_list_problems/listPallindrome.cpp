/**
 *  Given a linkedList, determine the data it has are in pallindrome
 *  a->b->c->c->b->a
 *  r->a->d->a->r
 */

#include <iostream>

struct Node {
  char data;
  Node * next;
  Node( char c ) : data{ c }, next{ nullptr } { }
};

void insert( Node * & head, char c )
{
  Node * newNode = new Node(c);
  if ( head == nullptr ) {
    head = newNode;
  } else {
    Node * temp = head;
    while ( temp->next != nullptr ) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void printList( Node * head )
{
  while( head ) {
    std::cout << head->data << " --> ";
    head = head->next;
  }
  std::cout << " NULL" << std::endl;
}

void reverseList( Node * & head )
{
  if ( head == nullptr ||
       (head && (head->next == nullptr))) {
      return;
  }
  Node * nextNode = nullptr;
  Node * newHead = nullptr;
  while ( head ) {
    nextNode = head->next;
    head->next = newHead;
    newHead = head;
    head = nextNode;
  }
  head = newHead;
}

bool isPallindrome( Node * head )
{
  if ( head == nullptr || (head && head->next == nullptr)) {
    return true;
  }
  Node * slowPtr = head;
  Node * fastPtr = head;
  while ( slowPtr && fastPtr && fastPtr->next )
  {
    fastPtr = fastPtr->next->next;
    slowPtr = slowPtr->next;
  }
  //case of odd number of data, we skip the middle node.
  if ( fastPtr && fastPtr->next == nullptr ) {
    slowPtr = slowPtr->next;
  }

  //reversing second half of list
  reverseList( slowPtr );

  Node * ptr1 = head;
  Node * ptr2 = slowPtr;


  while( ptr1 && ptr2 && ptr1->data == ptr2->data) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  //reversing second half back
  reverseList( slowPtr );
  if ( ptr2 == nullptr ) {
    return true;
  } else {
    return false;
  }
}

int main()
{
  Node * head1 = nullptr;
  insert( head1, 'a' );
  insert( head1, 'b' );
  insert( head1, 'c' );
  insert( head1, 'c' );
  insert( head1, 'b' );
  insert( head1, 'a' );
  std::cout << "List 1: ";
  printList( head1 );
  if ( isPallindrome( head1 ) ) {
    std::cout << "List 1 is pallindrome list\n";
  } else {
    std::cout << "List 1 is not a pallindrome list\n";
  }

  std::cout << "List 1: ";
  printList( head1 );

  Node * head2 = nullptr;
  insert( head2, 'r');
  insert( head2, 'a');
  insert( head2, 'd');
  insert( head2, 'a');
  insert( head2, 'r');
  std::cout << "List 2: ";
  printList( head2 );

  if ( isPallindrome( head2 ) ) {
    std::cout << "List 2 is pallindrome list\n";
  } else {
    std::cout << "List 2 is not a pallindrome list\n";
  }

  std::cout << "List 2: ";
  printList( head2 );

  Node * head = nullptr;
  insert( head, 'a' );
  insert( head, 'b' );
  insert( head, 'c' );
  insert( head, 'b' );
  insert( head, 'd' );
  std::cout << "List 3: ";
  printList( head );

  if ( isPallindrome( head ) ) {
    std::cout << "List 3 is pallindrome list\n";
  } else {
    std::cout << "List 3 is not a pallindrome list\n";
  }
  std::cout << "List 3: ";
  printList( head );

  return 0;
}
