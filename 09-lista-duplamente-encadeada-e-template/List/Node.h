#ifndef NODE_H
#define NODE_H
#include <iostream>

template< typename T>
struct Node
{
    T value;
    Node *next;
    Node *prev;

    Node(const T& val, Node *prv, Node *nxt){
        value = val;
        next = nxt;
        prev = prv;
    }
    ~Node(){
        std::cout<<"Node " << value <<" liberado" << std::endl;
    }
};

#endif