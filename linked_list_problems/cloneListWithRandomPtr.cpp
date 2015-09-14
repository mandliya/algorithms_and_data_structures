#include <iostream>

struct Node {
  int data;
  Node * next;
  Node * random;
  Node( int d ) : data{ d }, next{ nullptr }, random{ nullptr } { }
};

void printList( Node * head )
{
  std::cout << "List in format (Node data, Random Node data) : \n";
  while( head ) {
    std::cout << "(" << head->data << ", " << head->random->data << ")-->";
    head = head->next;
  }
  std::cout << "NULL" << std::endl;
}

Node * clone ( Node * head )
{
  if ( head == nullptr || ((head != nullptr) && (head->next == nullptr))){
    return head;
  }
  Node * newNode = nullptr;
  Node * nextNode = nullptr;
  Node * currNode = head;
  /**
   *  Adding a new node after each node with same data
   *  1->2->3 becomes 1->1->2->2->3->3
   */
  while( currNode ) {
    nextNode = currNode->next;
    newNode  = new Node(currNode->data);
    newNode->next = currNode->next;
    currNode->next = newNode;
    currNode = nextNode;
  }

  //Now copying random pointer to all newly added node.
  currNode = head;
  while( currNode && (currNode->next != nullptr) ) {
    currNode->next->random = currNode->random->next;
    currNode = currNode->next->next;
  }

  //splitting the list back
  Node * list1ptr = head;
  Node * list2ptr = head->next;
  Node * cloneHead = head->next;
  while( list1ptr->next && list2ptr->next ) {
    list1ptr->next = list1ptr->next->next;
    list2ptr->next = list2ptr->next->next;
    list1ptr = list1ptr->next;
    list2ptr = list2ptr->next;
  }
  return cloneHead;
}

bool verifyClone( Node * list1, Node * list2 )
{
  while( list1 && list2 ) {
    if ( (list1->data != list2->data) ||
         (list1->random->data != list2->random->data) ) {
        return false;
    }
    list1 = list1->next;
    list2 = list2->next;
  }
  return true;
}



int main()
{
   Node * head = new Node(1);
   head->next = new Node(2);
   head->next->next = new Node(3);
   head->next->next->next = new Node(4);
   head->next->next->next->next = new Node(5);

   head->random = head->next->next;
   head->next->random = head;
   head->next->next->random = head->next->next->next->next;
   head->next->next->next->random = head->next->next;
   head->next->next->next->next->random = head->next;

   printList(head);
   Node *cloneHead = clone(head);
   std::cout << "Are list cloned (0 for no, 1 for yes): "
             << verifyClone(head, cloneHead) << std::endl;
   printList(cloneHead);
   return 0;

}
