#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node
{
    T value;
    Node *next;

    Node(const T& val, Node* nxt){
        this->value = val;
        this->next = nxt;
    }

    ~Node(){
        delete next;
    }
};


#endif