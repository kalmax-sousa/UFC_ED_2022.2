#ifndef BST_H
#define BST_H
#include "Node.h"

class BST{
    public:
        BST();
        ~BST();
        void add(int key);
        void remove(int key);
        bool contains(int key);
        int minimum();
        int maximum();
        int successor(int k);
        int predecessor(int k);
        void inorder();
    
    private:
        Node *root;
        Node *add(Node *node, int key);
        Node *search(Node *node, int key);
        Node *clear(Node *node);
        Node *minimum(Node *node);
        Node *maximum(Node *node);
        Node *ancestral_successor(Node *x, Node *raiz);
        Node *ancestral_predecessor(Node *x, Node *raiz);
        Node *successor(Node *x, Node *raiz);
        Node *predecessor(Node *node, int k);
        Node *remove(int k, Node *node);
        Node *removeRoot(Node *node);
        void inorder(Node *node);
};

#endif