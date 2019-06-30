"""
Given two linked lists, they both merge at some point.
Find out the merging point

1-->2-->3-->4-->5
        ^
        |
7-->8-->9

List 1 and List 2 intereset at 3
"""

class Node:
    def __init__(self, data):
        """Represents a linked list node."""
        self.next = None
        self.data = data

    def print(self):
        """Prints the node's data with its address."""
        print(self.data, '(', hex(id(self)), ')', end=' ')

def len(head):
    """Length of the list."""
    count = 0
    itr = head
    while itr:
        count += 1
        itr = itr.next
    return count

def intersect(head1, head2):
    len1 = len(head1)
    len2 = len(head2)
    smaller = head1 if len1 < len2 else head2
    larger = head1 if len1 > len2 else head2

    diff = abs(len1-len2)
    i = 0
    while larger and i < diff:
        i += 1
        larger = larger.next

    itr1 = smaller
    itr2 = larger
    while itr1 and itr2:
        if itr1 == itr2:
            return itr1
        itr1 = itr1.next
        itr2 = itr2.next
    return None

def print_list(node):
    while node:
        node.print()
        print('-->', end=' ')
        node = node.next
    print('None')


if __name__ == "__main__":
    head = Node(1)
    head.next = Node(2)
    head.next.next = Node(3)
    head.next.next.next = Node(4)
    head.next.next.next.next = Node(5)

    print("List 1:")
    print_list(head)

    head2 = Node(7)
    head2.next = Node(8)
    head2.next.next = Node(9)
    head2.next.next.next = head.next.next

    print("List 2:")
    print_list(head2)

    print("Intersection of list1 and list2:")
    intersect(head, head2).print()

