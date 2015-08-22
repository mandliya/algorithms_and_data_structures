#include <binarySearchTree.h>
using namespace algo;

int doublei(int i) {
    //int j = 2 * i;
    return 2 * i;
}

int main( )
{
    BinarySearchTree<int> Tree;

    //insert 10 random int between 1 and 12
    for ( int i = 1; i <= 10; ++i ) {
        Tree.insert( random_range(1, 12 ) );
    }

    //print the tree
    Tree.printTree();
    std::cout << std::endl;

    //lets create a copy of tree;
    BinarySearchTree<int> anTree = Tree;

    //printing Tree 2
    anTree.printTree();
    std::cout << std::endl;

    //check if tree contains element from 1 to 5
    for ( int i = 1; i <= 5; ++i ) {
        if ( Tree.contains(i) ) {
            std::cout << "Tree contains " << i << std::endl;
        } else {
            std::cout << "Tree does not contain " << i << std::endl;
        }
    }


    //mirror of a tree

    //before mirror
    std::cout << "Mirror of Tree\n";
    std::cout << "Before Mirror\n";
    Tree.prettyPrint();

    //mirror
    Tree.mirror();

    //after mirror
    std::cout << "After Mirror\n";
    Tree.prettyPrint();




    return 0;

}// end of main
