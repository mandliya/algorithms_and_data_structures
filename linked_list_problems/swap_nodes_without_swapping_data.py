
#  Problem : Given a linked list, and two data values, x and y. 
#  Goal:     Swap the nodes of linkedlist by swapping pointers 
#            (and not swapping data) such that nodes with data x will contain y and vice versa.


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
        """Pushes new data to the head of the list"""
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def print_list(self):
        """Prints a linked list"""
        itr = self.head
        while itr:
            if itr.next is None:
                print(itr.data)
            else:
                print(str(itr.data) + '-->', end = ' ')
            itr = itr.next

    def print_list_addr(self):
        """Prints a list with address of the next pointer"""
        itr = self.head
        while itr:
            if itr.next is None:
                print(str(itr.data) + '(' + str(hex(id(itr))) + ')')
            else:
                print(str(itr.data) + '(' + str(hex(id(itr))) + ') --> ', end=' ')
            itr = itr.next

    def swap_nodes_without_swapping_data(self, x, y):
        """Swap the nodes of linked without swapping pointers i.e.
        swap nodes such that nodes with data x will contain y and vice versa."""

        # We are making assumption that nodes in linked list are unique
        if x == y:
            return

        curr_x = self.head
        curr_y = self.head
        prev_x = None
        prev_y = None

        # find node with data x
        while curr_x and curr_x.data != x:
            prev_x = curr_x
            curr_x = curr_x.next

        # find node with data y
        while curr_y and curr_y.data != y:
            prev_y = curr_y
            curr_y = curr_y.next

        # x or y is not there
        if curr_x is None or curr_y is None:
            return

        # if x is not head of the linked list.
        if prev_x is not None:
            prev_x.next = curr_y
        else: # if x was head, make y the head of the linked list.
            self.head = curr_y

        # if y is not head of the linked list
        if prev_y is not None:
            prev_y.next = curr_x
        else: # if y was head, make x the head of the linked list.
            self.head = curr_x

        # now swap the next pointers.
        temp = curr_x.next
        curr_x.next = curr_y.next
        curr_y.next = temp

if __name__ == "__main__":
    lst = LinkedList()
    lst.push(5)
    lst.push(1)
    lst.push(3)
    lst.push(2)
    lst.push(4)

    print("List before (with and without addr):")
    lst.print_list()
    lst.print_list_addr()

    lst.swap_nodes_without_swapping_data(1, 4)
    print("List after (with and without addr):")
    lst.print_list()
    lst.print_list_addr()