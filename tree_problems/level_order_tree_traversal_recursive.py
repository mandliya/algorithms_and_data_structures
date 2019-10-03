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

    def height_util(self, node):
        """Utility function for recursive calculation of the height of the tree"""
        if not node:
            return 0
        else:
            lheight = self.height_util(node.left)
            rheight = self.height_util(node.right)
            return lheight+1 if lheight > rheight else rheight + 1
    
    def height(self):
        """Height of the tree"""
        return self.height_util(self.root)
        
    def print_level(self, node, level):
        """Prints current level of the tree"""
        if not node:
            return
        if level == 1:
            print(node.data, end=' ')
        elif level > 1:
            self.print_level(node.left, level-1)
            self.print_level(node.right, level-1)
    
    def level_order(self):
        """Print level order traversal of the tree in recursive manner"""
        h = self.height()
        for i in range(1, h+1):
            self.print_level(self.root, i)



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

    print()
