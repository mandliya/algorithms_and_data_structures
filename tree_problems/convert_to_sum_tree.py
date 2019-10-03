"""
Convert a given tree to to sum tree.
Given : A tree with positive and negative data values.
Convert this to a tree where each node contains the sum of the left and right sub trees in the original tree.
The values of leaf nodes are changed to 0.
           10                             20
        /      \                       /       \
      -2        6          ---->     4         12
     /   \      /  \               /   \      /  \
   8     -4    7    5             0    0     0    0
 """

class TreeNode:
    """Representation of a binary tree node"""
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def to_sum_tree(root):
    """Converts a given binary tree to a sum tree
    params:
        root: Root of the binary tree
    """
    if not root:
        return 0

    previous_val = root.data
    root.data = to_sum_tree(root.left) + to_sum_tree(root.right)
    return root.data + previous_val

def inorder(root):
    """Prints inorder traversal of the binary tree
    params:
        root: Root of the binary tree
    """
    if not root:
        return
    inorder(root.left)
    print(root.data, end=' ')
    inorder(root.right)


if __name__ == '__main__':
    root = TreeNode(10)
    root.left = TreeNode(-2)
    root.right = TreeNode(6)
    root.left.left = TreeNode(8)
    root.left.right = TreeNode(-4)
    root.right.left = TreeNode(7)
    root.right.right = TreeNode(5)
    print("Inorder traversal of the tree: ")
    inorder(root)
    to_sum_tree(root);
    print("\nInorder traversal of the sum tree: ")
    inorder(root)