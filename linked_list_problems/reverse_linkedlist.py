"""
Reverse a linked list
"""

class Node:
    """Representation of a linked list node"""
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    """Representation of a linked list"""
    def __init__(self):
        self.head = None

    def push(self, data):
        """Pushes a new node with data at the head of the list"""
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def print(self):
        """Prints the linked list"""
        itr = self.head
        while itr:
            if itr.next is None:
                print(itr.data)
            else:
                print(str(itr.data), '-->', end=' ')
            itr = itr.next

    def _reverse_recur(self, node):
        """Utility function to recursively reverse a list"""
        if node is None:
            return

        if node.next is None:
            self.head = node
            return 
    
        first = node
        rest = node.next
        self._reverse_recur(rest)
        first.next.next = first
        first.next = None

    def reverse_r(self):
        """Recursively reverses a list"""
        self._reverse_recur(self.head)

    def reverse_i(self):
        """Iteratively reverses a list"""
        if (self.head is None) or \
            (self.head and self.head.next is None):
            return

        prev = None
        curr = self.head
        new_head = None
        while curr:
            prev = curr
            curr = curr.next
            prev.next = new_head
            new_head = prev
        self.head = new_head
            


if __name__ == "__main__":
    ll = LinkedList()
    ll.push(5)
    ll.push(4)
    ll.push(3)
    ll.push(2)
    ll.push(1)
    ll.print()

    ll.reverse_i()
    ll.print()
    ll.reverse_r()
    ll.print()