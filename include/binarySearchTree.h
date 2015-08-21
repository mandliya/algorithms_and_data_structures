#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <stdexcept>
#include <generic.h>
#include <iomanip>

namespace algo {
    template <typename Comparable>
    class BinarySearchTree {
        public:

            // default constructor
            BinarySearchTree( ) : root{ nullptr }
            { }

            // copy constructor
            BinarySearchTree( const BinarySearchTree & rhs )
                : root { nullptr }
            {
                root = __copy( rhs.root );
            }

            // move constructor
            BinarySearchTree( BinarySearchTree && rhs )
                : root { rhs.root }
            {
                rhs.root = nullptr;
            }
            
            // copy assignment
            BinarySearchTree & operator= ( const BinarySearchTree & rhs )
            {
                BinarySearchTree copy = rhs;
                algo::swap( *this, copy );
                return *this;
            }

            // move assignment
            BinarySearchTree & operator= ( BinarySearchTree && rhs )
            {
                algo::swap( root, rhs.root );
                return *this;
            }

            // destructor
            ~BinarySearchTree( )
            {
                clear();
            }

            // Smallest item in Tree
            const Comparable & findMin() const
            {
                if ( empty() )
                    throw std::underflow_error("Empty Tree");
                return __findMin( root )->element;
            }

            // Largest item in Tree
            const Comparable & findMax() const
            {
                if ( empty() )
                    throw std::underflow_error("Empty Tree");
                return __findMax( root )->element;
            }

            // does tree contain obj
            bool contains( const Comparable & obj ) const
            {
                return __contains( root, obj );
            }

            // isTreeEmpty
            bool empty( ) const
            {
                return ( root == nullptr );
            }

            // print the content of tree in sorted order
            void printTree(std::ostream & out = std::cout) const
            {
                if ( empty( ) ) {
                    std::cout << "Empty Tree\n";
                } else {
                    __printTree( root, out );
                }
            }

            // clear the tree
            void clear() const
            {
                __clear( root );
            }

            // insert element to tree, duplicates ignored
            void insert( const Comparable & obj )
            {
                __insert( root, obj );
            }

            // move insert element to tree, duplicates ignored
            void insert( Comparable && obj )
            {
                __insert( root, std::move( obj ) );
            }

            // remove element from tree
            void remove( const Comparable & obj )
            {
                __remove( root, obj );
            }

            void prettyPrintTree( ) {
                __prettyPrintTree(root);
            }

        private:
            struct BinaryNode {
                Comparable element;
                BinaryNode *left;
                BinaryNode *right;

                BinaryNode( const Comparable & obj = Comparable(),
                            BinaryNode *lptr = nullptr,
                            BinaryNode *rptr = nullptr )
                    : element{ obj }, left { lptr }, right { rptr }
                { }

                BinaryNode( Comparable && obj, BinaryNode *lptr,
                            BinaryNode *rptr )
                    : element{ std::move(obj) }, left{ lptr }, right{ rptr }
                { }
            }; // end of struct BinaryNode

            BinaryNode *root;

            const Comparable & __findMin( BinaryNode *node ) const
            {
                if ( node == nullptr )
                    return nullptr;
                else if ( node->left == nullptr )
                    return node;
                else 
                    return __findMin( node->left ); 
            }

            const Comparable & __findMax( BinaryNode *node ) const
            {
                if ( node == nullptr )
                    return nullptr;
                else if ( node->right == nullptr )
                    return node;
                else
                    return __findMax( node->right );
            }

            bool __contains( BinaryNode *node, const Comparable & obj ) const
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

            void __insert( BinaryNode * & node, const Comparable & obj )
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

            void __insert( BinaryNode * & node, Comparable && obj )
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

            void __remove( BinaryNode *node, const Comparable & obj ) {
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

            void __clear( BinaryNode *node ) const
            {
                if ( node != nullptr ) {
                    __clear( node->left );
                    __clear( node->right );
                    delete node;
                }
            }

            void __printTree( BinaryNode *node, std::ostream& out ) const
            {
                if ( node != nullptr ) {
                    __printTree( node->left, out );
                    out << node->element << " ";
                    __printTree( node->right, out );
                }
            }

            BinaryNode* __copy( BinaryNode *node ) {
                if ( node == nullptr ) {
                    return nullptr;
                }
                return new BinaryNode( node->element,
                                       __copy( node->left ),
                                       __copy( node->right) );
            }

            //pretty print post order
            void __prettyPrintTree( BinaryNode *node, int indent = 0, std::ostream & out = std::cout)
            {
                if ( node != nullptr ) {
                    if ( node->right != nullptr )
                        __prettyPrintTree( node->right, indent + 4, out);

                    if ( indent ) 
                        out << std::setw(indent) << ' ';
                    
                    if ( node->right != nullptr )
                        out<<" /\n" << std::setw(indent) << ' ';

                    out << node->element << std::endl;

                    if ( node->left != nullptr ) {
                        out << std::setw(indent) << ' ' <<" \\\n";
                        __prettyPrintTree( node->left, indent + 4, out);
                    }
                }
            }

    }; // end of class BinarySearchTree
} // end of namespace algo

#endif
