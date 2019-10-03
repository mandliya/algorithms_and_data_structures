"""
Given a list with next and random pointer, clone this list
"""

class Node:
    def __init__(self, data):
        """Representation of a linked list Node"""
        self.data = data
        self.next = None
        self.random = None

    def set_random(self, random_node):
        self.random = random_node


class LinkedList:
    def __init__(self):
        """Representation of a linked list"""
        self.head = None

    def push(self, data):
        """ Pushes a node at the top of linked list and make it head"""
        node = Node(data)
        node.next = self.head
        self.head = node


    def get_head(self):
        return self.head

    def set_head(self, head):
        self.head = head

    def print_list(self):
        """ Prints a list, random node pointers are enclosed in brackets """
        itr = self.head
        while itr:
            random_data = 'None' if itr.random is None else str(itr.random.data)
            if itr.next is None:
                print(str(itr.data) + '('+ random_data +')')
            else:
                print(str(itr.data) + '('+ random_data +') -->', end=' ')
            itr = itr.next

    def clone(self):
        """ Clones a list with random pointers and return a new list back"""

        # add a new node after each node with same data.
        new_list = LinkedList()
        itr = self.head
        while itr:
            new_node = Node(itr.data)
            next_node = itr.next
            itr.next = new_node
            new_node.next = next_node
            itr = next_node

        # create random pointers for the new nodes.
        itr = self.head
        while itr:
            itr.next.random = None if itr.random is None else itr.random.next
            itr = itr.next.next

        # separte the lists now.
        new_head = self.head.next
        itr1 = self.head
        itr2 = self.head.next
        while itr1.next and itr2.next:
            itr1.next = itr1.next.next
            itr2.next = itr2.next.next
            itr1 = itr1.next
            itr2 = itr2.next

        new_list.set_head(new_head)
        return new_list

    def verify_clone(self, list2):
        itr1 = self.head
        itr2 = list2.get_head()

        while itr1 and itr2:
            if itr1.data != itr2.data:
                return False
            if (itr1.random and not itr2.random) or \
            (itr2.random and not itr1.random):
                return False
            if itr1.random and itr2.random:
                if itr1.random.data != itr2.random.data:
                    return False
            itr1 = itr1.next
            itr2 = itr2.next

        return True


if __name__ == "__main__":
    list1 = LinkedList()
    list1.push(5)
    list1.push(4)
    list1.push(3)
    list1.push(2)
    list1.push(1)

    head = list1.get_head()
    head.random = head.next.next
    head.next.random = head
    head.next.next.random = head.next.next.next.next
    head.next.next.next.random = head.next.next
    head.next.next.next.next.random = head.next
    print("Original list:")
    list1.print_list()

    print("New list:")
    list2 = list1.clone()
    list2.print_list()

    print("Are lists identical? : ", list1.verify_clone(list2))