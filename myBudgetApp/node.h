#ifndef __NODE_H__
#define __NODE_H__

#include <stddef.h>

template <class T>
class Node {
  public:
    Node();
    Node( T );
    ~Node();

    T value;
    Node * left;
    Node * right;
};

#endif

template <class T>
Node<T>::Node() {
    value = 0;
    left = right = NULL;
}

template <class T>
Node<T>::Node( T v ) {
    value = v;
    left = right = NULL;
}

template <class T>
Node<T>::~Node() {
    if ( left != NULL ) {
        delete left;
    }
    
    if ( right != NULL ) {
        delete right;
    }
    
    left = right = NULL;
}