#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Node.h"

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree();
    BinaryTree(int, BinaryTree&, BinaryTree&);
    bool is_empty() const;
    bool is_leaf() const;
    bool contains(int) const;
    void print_keys() const;
    void clear();
    ~BinaryTree();
};

#endif