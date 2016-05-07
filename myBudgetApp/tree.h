#ifndef __TREE_H__
#define __TREE_H__

#include <iostream>
#include <algorithm>

using namespace std;

#include "node.h"

template <class T>
class Tree {
private:
    Node<T> * root;
    
    int height( Node<T> * );
    int size( Node<T> * );
    void insert( Node<T> *, T );
    bool search( Node<T> *, T );
    
    void preorder_traversal( Node<T> * );
    void inorder_traversal( Node<T> * );
    void postorder_traversal( Node<T> * );
    
public:
    Tree();
    ~Tree();

    void insert( T );
    bool search( T );
    T* find( T );
    int height();
    int size();

    void preorder_traversal();
    void inorder_traversal();
    void postorder_traversal();
};

#endif

/*************************************
 * constructor/destructor
 *************************************/

template <class T>
Tree<T>::Tree() {
    root = NULL;
} // end constructor

template <class T>
Tree<T>::~Tree() {
    if ( root != NULL ) {
        delete root;
    }
    
    root = NULL;
} // end destructor

/*************************************
 * getters and setters
 *************************************/

template <class T>
int Tree<T>::height() {
    return height( root );
} // end height [public]

template <class T>
int Tree<T>::height( Node<T> * node ) {
    if ( node == NULL ) {
        return 0;
    } else {
        return 1 + std::max( height( node->left ), height( node->right ));
    }
} // end height [private]

template <class T>
int Tree<T>::size() {
    return size( root );
} // end size [public]

template <class T>
int Tree<T>::size( Node<T> * node ) {
    if ( node == NULL ) {
        return 0;
    } else {
        return 1 + size( node->left ) + size( node->right );
    }
} // end size [private]

/*************************************
 * helper functions
 *************************************/

template <class T>
void Tree<T>::insert( T value ) {
    if ( root == NULL ) {
        root = new Node<T>( value );
    } else {
        insert( root, value );
    }
} // end insert [public]

template <class T>
void Tree<T>::insert( Node<T> * node, T value ) {
    if ( value < node->value ) {
        if( node->left == NULL ) {
            node->left = new Node<T>( value );
        } else {
            insert( node->left, value );
        }
    } else {
        if( node->right == NULL ) {
            node->right = new Node<T>( value );
        } else {
            insert( node->right, value );
        }
    }
} // end insert [private]

template <class T>
bool Tree<T>::search( T value ) {
    return search( root, value );
} // end search [public]

template <class T>
bool Tree<T>::search( Node<T> * node, T value ) {
    if ( node == NULL ) {
        return false;
    }
    
    if( node->value == value ) {
        return true;
    } else if( value < node->value ) {
        return search( node->left, value );
    } else {
        return search( node->right, value );
    }
} // end search [private]

template <class T>
T* Tree<T>::find(T value){
    return(search(value).node);
} // end find

template <class T>
void Tree<T>::preorder_traversal() {
    preorder_traversal( root );
    cout << endl;
} // end preorder_traversal [public]

template <class T>
void Tree<T>::inorder_traversal() {
    inorder_traversal( root );
    cout << endl;
} // end inorder_traversal [public]

template <class T>
void Tree<T>::postorder_traversal() {
    postorder_traversal( root );
    cout << endl;
} // end postorder_traversal [public]

template <class T>
void Tree<T>::preorder_traversal( Node<T> * node ) {
    if( node != NULL ) {
        cout << node->value << " ";
        preorder_traversal( node->left );
        preorder_traversal( node->right );
    }
} // end preorder_traversal [private]

template <class T>
void Tree<T>::inorder_traversal( Node<T> * node ) {
    if( node != NULL ) {
        inorder_traversal( node->left );
        cout << node->value << " ";
        inorder_traversal( node->right );
    }
} // end inorder_traversal [private]

template <class T>
void Tree<T>::postorder_traversal( Node<T> * node ) {
    if( node != NULL ) {
        postorder_traversal( node->left );
        postorder_traversal( node->right );
        cout << node->value << " ";
    }
} // end postorder_traversal [private]