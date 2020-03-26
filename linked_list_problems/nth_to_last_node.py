"""
Find nth to last node in a linked list.
"""

class Node:
    def __init__(self, data):
        """Representation of a linked list node"""
        self.data = data
        self.next = None


def nth_to_last(head, n):
    """ Find nth to last node of a linked list
    Params:
        head : head of the linked list
        n: the distance of target node from the end of linkedlist.
    """
    itr1 = head
    itr2 = head
    i = 1

    # First move the first iterator to nth node from beginning.
    while itr1 and i <= n:
        itr1 = itr1.next
        i += 1
    
    # Now move the second iterator from head, till the first iterator reaches end.
    # If we need to find nth node from the last, we need to find l-nth node from the
    # beginning, where l is the length of the list.
    while itr1:
        itr1 = itr1.next
        itr2 = itr2.next

    return itr2.data


def print_list(head):
    """ Prints a linked list.
    Params:
        head: head of the linked list
    """
    while head:
        if not head.next:
            print(head.data)
        else:
            print(str(head.data) + " --> ", end = " ")
        head = head.next


if __name__ == "__main__":
    root = Node(3)
    root.next = Node(2)
    root.next.next = Node(1)
    root.next.next.next = Node(5)
    root.next.next.next.next = Node(4)
    print_list(root)
    print("4th node from the last of the list is: ", nth_to_last(root, 4))