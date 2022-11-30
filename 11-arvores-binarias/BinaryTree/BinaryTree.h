#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <string>
#include "Node.h"

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree();
    BinaryTree(int, BinaryTree&, BinaryTree&);
    BinaryTree(std::string serial);
    bool is_empty() const;
    bool is_leaf() const;
    bool contains(int) const;
    void print_keys() const;
    void clear();
    ~BinaryTree();

    void preordem() const;
    void posordem() const;
    void ordemsimetrica() const;

    std::string serialization() const;
};

#endif