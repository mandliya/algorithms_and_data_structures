'''
Given a non-empty binary search tree and a target value, 
find the value in the BST that is closest to the target.
Also, to note that the target value is a floating point.
There will be only one unique value which is closest to the target.
'''

import sys


class TreeNode:
    '''
    A tree's node representation
    '''
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def closest_diff_util(node, target, min_diff, min_diff_data):
    ''' Util function to find the node closest to target
    Params:
    node -- node in the current BST tree
    target -- The value to which closest node needs to be found.
    min_diff -- minimum difference between target and the nodes we have iterated so far
    min_diff_data -- the value of node which is closest to target so far.
    '''
    if node == None:
        return

    # If the target itself is present in the tree.
    if node.data == target:
        min_diff_data[0] = target
        return

    if min_diff > abs(node.data - target):
        min_diff = abs(node.data - target)
        min_diff_data[0] = node.data

    if target < node.data:
        closest_diff_util(node.left, target, min_diff, min_diff_data)
    else:
        closest_diff_util(node.right, target, min_diff, min_diff_data)

def closest_diff(root, target):
    '''Function to find the node closest to target
    Params:
        root -- the root node of the tree
        target -- the value to which closest node needs to be found.
    '''
    min_diff, min_diff_data = sys.maxsize, [-1]
    closest_diff_util(root, target, min_diff, min_diff_data)
    return min_diff_data[0]

def closest_diff_iter(root, target):
    '''Function to find the node closest to target iteratively
    Params:
        root -- the root node of the tree
        target -- the value to which closest node needs to be found.
    '''
    if not root:
        return sys.maxsize
    closest = root.data
    while root:
        if abs(target - closest) >= abs(target - root.data):
            closest = root.data
        root = root.left if target < root.data else root.right
    return closest

def inorder(root):
    """Print inorder traversal of the tree.
    Param:
        root -- root of the tree.
    """
    if not root:
        return
    inorder(root.left)
    print(root.data, end=" ")
    inorder(root.right)

if __name__ == '__main__':
    root = TreeNode(10);
    root.left = TreeNode(5);
    root.right = TreeNode(15);
    root.left.left = TreeNode(2);
    root.left.right = TreeNode(7);
    root.right.left = TreeNode(12);
    root.right.right = TreeNode(16);

    print("Inorder traversal of the tree:")
    inorder(root)

    print()
    print("Closest value in the tree (recursively) to 6.6779 : ", closest_diff(root, 6.6779))
    print("Closest value in the tree (iteratively) to 6.6779 : ", closest_diff_iter(root, 6.6779))