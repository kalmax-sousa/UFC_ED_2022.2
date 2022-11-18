#ifndef NODE_H
#define NODE_H

using Item = int;

class Node {
    friend class ForwardList;
private:
    Item value;
    Node* next;

public:
    Node(const Item& value, Node* ptrNext = nullptr){
        this->value = value;
        this->next = ptrNext;
    }
};

#endif