#ifndef NODE_H
#define NODE_H
#include <iostream>

struct Node {
    int   key;    // valor a ser guardado
    Node* left;   // ponteiro para filho esquerdo
    Node* right;  // ponteiro para filho direito

    // Construtor do struct Node
    Node(int k, Node *l, Node *r) {
        this->key = k;
        this->left = l;
        this->right = r;
    }

    ~Node() {
        std::cout << this->key << " deleted\n";
    }
};

#endif