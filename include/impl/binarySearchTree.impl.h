#ifndef BINARY_SEARCH_TREE_IMPL_H
#define BINARY_SEARCH_TREE_IMPL_H

#include <stdexcept>
#include <generic.h>

//for pretty printing tree
#include <iomanip>
#include <deque>

namespace algo {

    // default constructor
    template <typename T>
    BinarySearchTree<T>::BinarySearchTree( ) : root{ nullptr }
    { }

    // copy constructor
    template<typename T>
    BinarySearchTree<T>::BinarySearchTree( const BinarySearchTree & rhs )
        : root { nullptr }
    {
        root = __copy( rhs.root );
    }

    // move constructor
    template<typename T>
    BinarySearchTree<T>::BinarySearchTree( BinarySearchTree && rhs )
        : root { rhs.root }
    {
        rhs.root = nullptr;
    }


    //copy assignment
    template<typename T>
    BinarySearchTree<T>  & BinarySearchTree<T>::operator= ( const BinarySearchTree & rhs )
    {
        BinarySearchTree copy = rhs;
        algo::swap( *this, copy );
        return *this;
    }

    // move assignment
    template<typename T>
    BinarySearchTree<T> & BinarySearchTree<T>::operator= ( BinarySearchTree && rhs )
    {
        swap( root, rhs.root );
        return *this;
    }

    // destructor
    template<typename T>
    BinarySearchTree<T>::~BinarySearchTree( )
    {
        clear();
    }

    // Smallest item in Tree
    template <typename T>
    const T & BinarySearchTree<T>::findMin() const
    {
        if ( empty() )
            throw std::underflow_error("Empty Tree");
        return __findMin( root )->element;
    }

    // Largest item in Tree
    template <typename T>
    const T & BinarySearchTree<T>::findMax() const
    {
        if ( empty() )
            throw std::underflow_error("Empty Tree");
        return __findMax( root )->element;
    }

    // does tree contain obj
    template <typename T>
    bool BinarySearchTree<T>::contains( const T & obj ) const
    {
        return __contains( root, obj );
    }

    // isTreeEmpty
    template <typename T>
    bool BinarySearchTree<T>::empty( ) const
    {
        return ( root == nullptr );
    }

    // print the content of tree in sorted order
    template <typename T>
    void BinarySearchTree<T>::printTree(std::ostream & out ) const
    {
        if ( empty( ) ) {
            std::cout << "Empty Tree\n";
        } else {
            __printTree( root, out );
        }
    }

    // clear the tree
    template <typename T>
    void BinarySearchTree<T>::clear() const
    {
        __clear( root );
    }

    // insert element to tree, duplicates ignored
    template <typename T>
    void BinarySearchTree<T>::insert( const T & obj )
    {
        __insert( root, obj );
    }

    // move insert element to tree, duplicates ignored
    template <typename T>
    void BinarySearchTree<T>::insert( T && obj )
    {
        __insert( root, std::move( obj ) );
    }

    // remove element from tree
    template <typename T>
    void BinarySearchTree<T>::remove( const T & obj )
    {
        __remove( root, obj );
    }

    //get the height of tree
    template <typename T>
    const int BinarySearchTree<T>::height() const
    {
        return __height(root);
    }

    //pretty print the tree
    template <typename T>
    void BinarySearchTree<T>::prettyPrint( ) const
    {
        __prettyPrint(root);
    }

    template<typename T>
    typename BinarySearchTree<T>::BinaryNode* BinarySearchTree<T>::getRoot( ) const
    {
        return root;
    }

    template <typename T>
    const T & BinarySearchTree<T>::__findMin( BinaryNode *node ) const
    {
        if ( node == nullptr )
            return nullptr;
        else if ( node->left == nullptr )
            return node;
        else 
            return __findMin( node->left ); 
    }

    template <typename T>
    const T & BinarySearchTree<T>::__findMax( BinaryNode *node ) const
    {
        if ( node == nullptr )
            return nullptr;
        else if ( node->right == nullptr )
            return node;
        else
            return __findMax( node->right );
    }


    template <typename T>
    bool BinarySearchTree<T>::__contains( BinaryNode *node, const T & obj ) const
    {
        if ( node == nullptr )
            return false;
        else if ( obj < node->element )
            return __contains( node->left, obj );
        else if ( obj > node->element )
            return __contains( node->right, obj );
        else
            return true;
    }


    template <typename T>
    void BinarySearchTree<T>::__insert( BinaryNode * & node, const T & obj )
    {
        if ( node == nullptr ) {
            node = new BinaryNode( obj, nullptr, nullptr );
        } else if ( obj < node->element ) {
            __insert( node->left, obj );
        } else if ( obj > node->element ) {
            __insert( node->right, obj );
        } else {
            //ignore case of duplicate
        }
    }


    template <typename T>
    void BinarySearchTree<T>::__insert( BinaryNode * & node, T && obj )
    {
        if ( node == nullptr ) {
            node = new BinaryNode( std::move( obj ), nullptr, nullptr );
            return;
        }
        BinaryNode * currNode = node;
        bool flag = true;
        while (flag) {
            if ( currNode->element > obj ) {
                if ( currNode->left == nullptr ) {
                    currNode->left = new BinaryNode( std::move( obj ), nullptr, nullptr );
                    flag = false;
                } else {
                    currNode = currNode->left;
                }
            } else if (currNode->element < obj ) {
                if (currNode->right == nullptr) {
                    currNode->right = new BinaryNode( std::move( obj ), nullptr, nullptr );
                    flag = false;
                } else {
                    currNode = currNode->right;
                }
            } else {
                flag = false;
                //case of duplicate
            }
        }
    }


    template <typename T>
    void BinarySearchTree<T>::__remove( BinaryNode *node, const T & obj ) {
        if ( node == nullptr ) {
            return;
        }
        
        if ( obj < node->element ) {
            __remove( node->left, obj );
        } else if ( obj > node->element ) {
            __remove( node->right, obj );
        } else {
            if ( node->left != nullptr &&
                 node->right != nullptr ) {
                 node->element = __findMin(node->right)->element;
                 __remove( node->right, node->element);
            } else {
                BinaryNode *oldNode = node;
                node = ( node->left != nullptr ) ? node->left : node->right;
                delete oldNode;
            }

        }
    }


    template <typename T>
    void BinarySearchTree<T>::__clear( BinaryNode *node ) const
    {
        if ( node != nullptr ) {
            __clear( node->left );
            __clear( node->right );
            delete node;
        }
    }


    template <typename T>
    void BinarySearchTree<T>::__printTree( BinaryNode *node, std::ostream& out ) const
    {
        if ( node != nullptr ) {
            __printTree( node->left, out );
            out << node->element << " ";
            __printTree( node->right, out );
        }
    }


    template <typename T>
    typename BinarySearchTree<T>::BinaryNode* BinarySearchTree<T>::__copy( BinaryNode *node ) {
        if ( node == nullptr ) {
            return nullptr;
        }
        return new BinaryNode( node->element,
                               __copy( node->left ),
                               __copy( node->right) );
    }

    template <typename T>
    void BinarySearchTree<T>::__prettyPrint( BinaryNode *node, int indent, std::ostream & out ) const
    {
        if ( node != nullptr ) {
            if ( node->right != nullptr )
                __prettyPrint( node->right, indent + 4, out);

            if ( indent ) 
                out << std::setw(indent) << ' ';
            
            if ( node->right != nullptr )
                out<<" /\n" << std::setw(indent) << ' ';

            out << node->element << std::endl;

            if ( node->left != nullptr ) {
                out << std::setw(indent) << ' ' <<" \\\n";
                __prettyPrint (node->left, indent + 4, out);
            }
        }
    }

    //private function to get tree height
    template <typename T>
    const int BinarySearchTree<T>::__height( BinaryNode * node )
    {
        if ( node == nullptr ) {
            return 0;
        }
        int leftHeight = __height( node->left );
        int rightHeight = __height( node->right );
        return ( ( leftHeight > rightHeight ) ? leftHeight + 1 : rightHeight + 1 );
    }

    template <typename T>
    void BinarySearchTree<T>::mirror( )
    {
        __mirror(root);

    }

    template <typename T>
    void BinarySearchTree<T>::__mirror(BinaryNode * & node) 
    {
        if (node != nullptr)
        {
            __mirror(node->left);
            __mirror(node->right);
            swap(node->left, node->right);
        }
    }

} //end of namespace algo
#endif //end of BINARY_SEARCH_TREE_IMPL
