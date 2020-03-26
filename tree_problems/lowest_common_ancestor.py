"""
 Given a binary search tree, determine the lowest common ancestor of two given nodes with data
 key1 and key2. Assumption is key1 and key2 exists in tree
 Example
           20
       /        \
       8        22
   /      \
   4        12
         /     \
       10     14
In the above tree, LCA of 10 and 14 is 12
similarly 4 and 22 will have LCA 20
"""

class Node:
    def __init__(self, data):
        """Binary Search Tree Node representation"""
        self.data = data
        self.left = None
        self.right = None


def LCA(root, key1, key2):
    if root is None:
        return None

    if root.data > key1 and root.data > key2:
        return LCA(root.left, key1, key2)

    elif root.data < key1 and root.data < key2:
        return LCA(root.right, key1, key2)

    return root

def inorder(root):
    if root is None:
        return
    inorder(root.left)
    print(root.data, end =' ')
    inorder(root.right)



if __name__ == "__main__":
    root = Node(20)
    root.right = Node(22)
    root.left = Node(8)
    root.left.left = Node(4)
    root.left.right= Node(12)
    root.left.right.right = Node(14)
    root.left.right.left = Node(10)
    print("Inorder traversal of the tree:")
    inorder(root);
    print()
    print("LCA of nodes with data 10 and 14 is :")
    print(LCA(root, 14, 10).data);
    print("LCA of nodes with data 14 and 8 is :")
    print(LCA(root, 14, 8).data);
    print("LCA of root with data 4 and 22 is :")
    print(LCA(root, 4, 22).data);
    print("LCA of root with data 14 and 10 is :")
    print(LCA(root, 10, 14).data);
