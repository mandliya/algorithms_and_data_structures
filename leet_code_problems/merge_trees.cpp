/*
Given two binary trees and imagine that when you put one of them to cover the other, some nodes
of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then
sum node values up as the new value of the merged node.
Otherwise, the NOT null node will be used as the node of new tree.

    Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7

*/


#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val):
        value{val}, left{nullptr}, right{nullptr}{}
};

Node* mergeTrees(Node* t1, Node* t2)
{
    if (!t1)
    {
        return t2;
    }

    if (!t2)
    {
        return t1;
    }
    t1->value += t2->value;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}

void preOrder(Node* t1)
{
    if (t1)
    {
        std::cout << t1->value << " ";
        if (t1->left)
        {
            preOrder(t1->left);
        }
        else
        {
            std::cout << "null" << " ";
        }
        if (t1->right)
        {
            preOrder(t1->right);
        }
        else
        {
            std::cout << "null" << " ";
        }
    }
}

int main()
{
    Node* t1 = new Node(1);
    t1->left = new Node(3);
    t1->right = new Node(2);
    t1->left->left = new Node(5);
    std::cout << "Tree 1:";
    preOrder(t1);
    std::cout << std::endl;

    Node* t2 = new Node(2);
    t2->left = new Node(1);
    t2->right = new Node(3);
    t2->left->right = new Node(4);
    t2->right->right = new Node(7);
    std::cout << "Tree 2:";
    preOrder(t2);
    std::cout << std::endl;

    Node* t3 = mergeTrees(t1, t2);
    std::cout << "Tree 3:";
    preOrder(t3);
    std::cout << std::endl;

    return 0;
}