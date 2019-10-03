
# Given a binary Tree
# 		    1
# 		 /     \
# 	     2	     3
# 	    / \ 	/ \
#  	   4  5    6   7
# Print zig-zag level order traversal
# 1 3 2 4 5 6 7
#

class TreeNode:
    def __init__(self, data):
        """Representation of a binary tree node"""
        self.data = data
        self.left = None
        self.right = None


class Tree:
    def __init__(self):
        """Reprentation of a binary tree"""
        self.root = None

    def _print_level(self, node, level, zig):
        """Utility function to print the level, level starts with 1"""
        if node is None:
            return
        if level == 1:
            print(node.data, end=' ')
            return
        else:
            if zig:
                self._print_level(node.left, level-1, zig)
                self._print_level(node.right, level-1, zig)
            else:
                self._print_level(node.right, level-1, zig)
                self._print_level(node.left, level-1, zig)

    def _height(self, node):
        """Gets the height of the tree from node"""
        if node is None:
            return 0
        else:
            return max(self._height(node.left), self._height(node.right)) + 1

    def print_zig_zag(self):
        """Prints the zig zag level order"""
        if self.root is None:
            return
        h = self._height(self.root)
        zig = True
        for i in range(1, h+1):
            self._print_level(self.root, i, not zig)
            print()
    
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

if __name__ == "__main__":
    tree = Tree()
    tree.root = TreeNode(1)
    tree.root.left = TreeNode(2)
    tree.root.right = TreeNode(3)
    tree.root.left.left = TreeNode(4)
    tree.root.left.right = TreeNode(5)
    tree.root.right.left = TreeNode(6)
    tree.root.right.right = TreeNode(7)

    print("In order:")
    tree.in_order()

    print("Zig zag level order:")
    tree.print_zig_zag()
