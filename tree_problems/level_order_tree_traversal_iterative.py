# Program to implement level order traversal - recursive version

class TreeNode:
    """Representation of a binary tree node"""
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Tree:
    """Representation of a binary tree"""
    def __init__(self):
        self.root = None

    def in_order(self):
        """In order traversal of the tree"""
        current = self.root
        stack = []
        done = False
        while not done:
            if current is not None:
                stack.append(current)
                current = current.left

            elif stack:
                current = stack.pop()
                print(current.data, end=' ')
                current = current.right
            else:
                done = True
        print()

    def level_order(self):
        """Prints level order tree traversal iterative way"""
        #an empty queue
        queue = []
        queue.append(self.root)
        while queue:
            curr = queue.pop(0)
            print(curr.data, end=' ')
            if curr.left:
                queue.append(curr.left)
            if curr.right:
                queue.append(curr.right)
        
        print()


if __name__ == "__main__":
    tree = Tree()
    tree.root = TreeNode(1)
    tree.root.left = TreeNode(2)
    tree.root.right = TreeNode(3)
    tree.root.left.left = TreeNode(4)
    tree.root.left.right = TreeNode(5)
    tree.root.right.left = TreeNode(6)
    tree.root.right.right = TreeNode(7)

    print("Inorder: ")
    tree.in_order()
    print("Level order:")
    tree.level_order()

