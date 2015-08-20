#ifndef BST_H
#define BST_H

#include <iostream>
#include <stdexcept>
#include <generic.h>

namespace algo {

    template <typename Comparable>
    class BinarySearchTree {
        public:
                BinarySearchTree( ) : root { nullptr }
                {
                }

                //Copy Constructor
                BinarySearchTree( const BinarySearchTree& rhs )
                    : root { nullptr }
                {
                    root = __copy( rhs.root );
                }

                //Move Constructor
                BinarySearchTree( BinarySearchTree && rhs )
                    : root { rhs.root }
                {
                    rhs.root = nullptr;
                }

                //Destructor
                ~BinarySearchTree( )
                {
                    clear( );
                }

                // Copy Assignment
                BinarySearchTree& operator= ( const BinarySearchTree & rhs )
                {
                    BinarySearchTree copy = rhs;
                    algo::swap(*this, copy );
                    return *this;
                }

                //Move assignment
                BinarySearchTree & operator= ( BinarySearchTree  && rhs )
                {
                    algo::swap( root, rhs.root );
                    return *this;
                }

                // smallest item in tree
                const Comparable & findMin( ) const
                {
                    if ( empty( ) )
                        throw std::underflow_error("Empty Tree");
                    return __findMin( root )->element;
                }

                // largest item in tree
                const Comparable & findMax( ) const
                {
                    if ( empty( ) )
                        throw std::underflow_error("Empty Tree");
                    return __findMax( root )->element;
                }

                // is obj there?
                bool contains( const Comparable & obj ) const
                {
                    return __contains( root, obj);
                }

                // is tree empty?
                bool empty( ) const
                {
                    return ( root == nullptr );
                }

                // printTree in sorted order ( inorder)
                void printTree( std::ostream& out = std::cout ) const
                {
                    if ( empty( ) ) {
                        out << "Empty Tree" << std::endl;
                    } else {
                        __printTree( root, out );
                    }
                }

                // empty the tree
                void clear( )
                {
                    __clear( root );
                }

                // insert obj into tree, duplicate ignored
                void insert( const Comparable & obj )
                {
                    __insert( root, obj );
                }

                // insert (move) into tree, duplicate ignored
                void insert( Comparable && obj )
                {
                    __insert( root, std::move( obj ) );
                }

                void remove ( const Comparable & obj )
                {
                    __remove( root, obj );
                }

            private:
                struct BinaryNode {
                    Comparable element;
                    BinaryNode *left;
                    BinaryNode *right;
                    
                    BinaryNode( const Comparable & obj = Comparable( ),
                                BinaryNode *lptr = nullptr,
                                BinaryNode *rptr = nullptr )
                        : element{ obj }, left{ lptr }, right{ rptr }
                    { }

                    BinaryNode ( Comparable && obj, BinaryNode *lptr, BinaryNode *rptr )
                        : element{ std::move( obj ) } , left{ lptr }, right{ rptr }
                    { }
                };

                BinaryNode * root;

                // Internal routine to add element to tree
                // using a reference to pointer rather than pointer to pointer, as we will just 
                // modify pointer not object pointed by it.
                void   __insert( BinaryNode * &node, const Comparable& obj )
                {
                    if ( node == nullptr ) {
                            node = new BinaryNode { obj, nullptr, nullptr };
                    } else if ( node->element > obj ) {
                            __insert( node->left, obj );
                    } else if ( node->element < obj ){
                            __insert( node->right, obj );
                    } else {
                            //do nothing, case of duplicate
                    }
                    
                }

                void  __insert( BinaryNode * & node, Comparable && obj )
                {
                    if ( node == nullptr ) {
                        node = new BinaryNode{ std::move( obj ), nullptr, nullptr };
                    } else if ( node->element > obj ) {
                            __insert( node->left, std::move( obj ) );
                    } else if ( node->element < obj ){
                            __insert( node->right, std::move( obj ) );
                    } else {
                            //do nothing, case of duplicate
                    }
                    
                }

                //Internal method to remove element from subtree
                void __remove( BinaryNode* node, const Comparable & obj )
                {
                    if ( node == nullptr ) {
                        return; //no item in tree
                    } else if ( node->element > obj ) {
                        __remove( node->left, obj );
                    } else if ( node->element < obj ) {
                        __remove( node->right, obj );
                    } else if ( node->left != nullptr &&
                                node->right != nullptr ) {
                        node->element = __findMin( node->right )->element;
                        __remove( node->right, node->element);
                    } else {
                        BinaryNode *oldNode = node;
                        node = ( node->left != nullptr ) ? node->left : node->right;
                        delete oldNode;
                    }
                }

                BinaryNode* __findMin( BinaryNode *node ) const
                {
                    if ( node == nullptr) {
                        return node;
                    } 
                    if ( node->left == nullptr ) {
                        return node;
                    } 
                    return __findMin( node->left );
                }

                BinaryNode* __findMax( BinaryNode *node ) const
                {
                    if ( node == nullptr ) {
                        return node;
                    }
                    if ( node->right == nullptr ) {
                        return node;
                    }
                    return __findMax ( root->right );
                }

                bool __contains( BinaryNode *node, const Comparable & obj ) const
                {
                    if ( node == nullptr )
                        return false;
                    if ( node->element > obj )
                        return __contains( node->left, obj );
                    if ( node->element < obj )
                        return __contains( node->right, obj );

                    return true; //it matches
                }

                void  __clear( BinaryNode *node )
                {
                    if ( node != nullptr ) {
                        __clear( node->left );
                        __clear( node->right );
                        delete node;
                    }
                    node = nullptr;
                }

                void __printTree( BinaryNode *node, std::ostream& out) const
                {
                    if ( node != nullptr ) {
                        __printTree( node->left, out );
                        out << node->element << std::endl;
                        __printTree( node->right, out );
                    }
                }

                BinaryNode* __copy( BinaryNode *node )
                {
                    if ( node == nullptr )
                        return nullptr;
                    return new BinaryNode{ node->element, __copy( node->left ), __copy( node->right ) } ;

                }


        }; //end of class BinarySearchTree


}
#endif
