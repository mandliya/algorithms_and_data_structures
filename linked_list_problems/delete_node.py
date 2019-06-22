# Problem: Only given a node of the linked list, delete the node.


class Node:
    """Representation of a node of a linked list"""
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    """Representation of a linked list"""
    def __init__(self):
        self.head = None

    def push(self, data):
        """Pushes a new node to the linkedlist, the new node becomes head
        Params:
            data of the new node.
        """
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def print_list(self):
        """Prints the linked list"""
        itr = self.head
        while itr:
            if itr.next is None:
                print(itr.data)
            else:
                print(str(itr.data)+ "-->", end=" ")
            itr = itr.next

    def delete_node(self, node):
        """Deletes a given node from the linked list
        Params:
            node: node to be deleted
        """
        itr = self.head
        while itr.next != node:
            itr = itr.next
        if itr is not None:
            itr.next = node.next

        node.next = None

    def get_head(self):
        return self.head


if __name__ == '__main__':
    linkedList = LinkedList()
    linkedList.push(1)
    linkedList.push(2)
    linkedList.push(3)
    linkedList.push(4)
    linkedList.push(4)
    print("List before deleting:")
    linkedList.print_list()

    # Delete second node from the list.
    linkedList.delete_node(linkedList.get_head().next)
    print("List after deleting:")
    linkedList.print_list() 