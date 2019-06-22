"""
We have two numbers represented by a linked list, 
where each node contains a single digit. The digits are stored in reverse order,
such that the 1's digit is at the head of the list.
Write a function that adds the two numbers and returns the sum as a linked list.
Example:

Given 7->1->6 + 5->9->2. That is, 617 + 295.
Return 2->1->9. That is 912.

Given 3->1->5 and 5->9->2, return 8->0->8.
"""

class Node:
    """Representation of a linked list node"""
    def __init__(self, data):
        self.data = data
        self.next = None

def add_two_numbers_lists(list1, list2):
    """ Adds two numbers represented as a linked list and 
    returns the sum as a linked list
    Example:
        7->1->6 + 5->9->2 = 2->1->9
        (617 + 295 = 912)
    Params:
        list1 : list representing first number
        list2 : list representing second number
    """
    list3 = None
    prev = None
    carry = 0
    while list1 is not None or list2 is not None:
        res = carry
        res += 0 if list1 is None else list1.data
        res += 0 if list2 is None else list2.data
        carry = 1 if res >= 10 else 0
        res = res % 10
        newNode = Node(res)

        if list3 is None:
            list3 = newNode
        else:
            prev.next = newNode

        prev = newNode

        if list1 is not None:
            list1 = list1.next
        if list2 is not None:
            list2 = list2.next

    return list3

def print_list(head):
    while head:
        if head.next is None:
            print(head.data)
        else:
            print(str(head.data)+ '-->', end = ' ')
        head = head.next


if __name__ == '__main__':
    print("List 1:")
    list1 = Node(7)
    list1.next = Node(1)
    list1.next.next = Node(6)
    print_list(list1)

    print("List 2:")
    list2 = Node(5)
    list2.next = Node(9)
    list2.next.next = Node(2)
    print_list(list2)

    print("Result List:")
    list3 = add_two_numbers_lists(list1, list2)
    print_list(list3)

    print("Example 2: ")
    print("List 1:")
    list1 = Node(3)
    list1.next = Node(1)
    list1.next.next = Node(5)
    print_list(list1)

    print("List 2:")
    list2 = Node(5)
    list2.next = Node(9)
    list2.next.next = Node(2)
    print_list(list2)

    print("Result List:")
    list3 = add_two_numbers_lists(list1, list2)
    print_list(list3)