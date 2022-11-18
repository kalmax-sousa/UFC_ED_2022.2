#include <iostream>
#include "Node.h"
#include "BinaryTree.h"
using namespace std;

BinaryTree::BinaryTree() {
    this->root = nullptr;
}

BinaryTree::BinaryTree(int value, BinaryTree& lchild, BinaryTree& rchild) {
    this->root = new Node(value, lchild.root, rchild.root);
    lchild.root = rchild.root = nullptr;
}

bool BinaryTree::is_empty() const {
    return this->root == nullptr;
}

bool BinaryTree::is_leaf() const {
    return (!is_empty()) && this->root->left == nullptr && this->root->right == nullptr;
}

bool contains_recursive(Node *node, int value){
    if(node == nullptr) return false;
    
    if(node->key == value) return true;
    
    return contains_recursive(node->left, value) || contains_recursive(node->right, value);
}

bool BinaryTree::contains(int value) const {
    return contains_recursive(this->root, value);
}

void BinaryTree::print_keys() const {
    
}

void BinaryTree::clear() {
    
}

BinaryTree::~BinaryTree() {
    
}