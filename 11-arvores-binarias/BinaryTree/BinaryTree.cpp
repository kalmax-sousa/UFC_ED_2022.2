#include <iostream>
#include <string>
#include <sstream>
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

Node* deserialization_rec(stringstream& ss){
    string c;
    ss >> c;
    if(c == "#") return nullptr;
    else{
        Node *aux = new Node(stoi(c), nullptr, nullptr);
        aux->left = deserialization_rec(ss);
        aux->right = deserialization_rec(ss);
        return aux;
    }
}

BinaryTree::BinaryTree(std::string serial){
    stringstream ss {serial};
    this->root = deserialization_rec(ss);
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


void print_keys_recursivo(Node *node){
    if(node != nullptr){
        cout << node->key << " ";
        print_keys_recursivo(node->left);
        print_keys_recursivo(node->right);
    }
}
void BinaryTree::print_keys() const {
    print_keys_recursivo(this->root);
    cout << endl;
}

Node* clear_recursivo(Node *node){
    if(node != nullptr){
        node->left = clear_recursivo(node->left);
        node->right = clear_recursivo(node->right);
        delete node;
    }

    return nullptr;
}
void BinaryTree::clear() {
    this->root = clear_recursivo(this->root);
}

BinaryTree::~BinaryTree() {
    clear();
}

void preordem_rec(Node *node){
    if(node != nullptr){
        cout << node->key << " ";
        preordem_rec(node->left);
        preordem_rec(node->right);
    }
}
void BinaryTree::preordem() const {
    preordem_rec(this->root);
    cout << endl;
}

void posordem_rec(Node *node){
    if(node != nullptr){
        posordem_rec(node->left);
        posordem_rec(node->right);
        cout << node->key << " ";
    }
}
void BinaryTree::posordem() const {
    posordem_rec(this->root);
    cout << endl;
}

void ordemsimetrica_rec(Node *node){
    if(node != nullptr){
        ordemsimetrica_rec(node->left);
        cout << node->key << " ";
        ordemsimetrica_rec(node->right);
    }
}
void BinaryTree::ordemsimetrica() const {
    ordemsimetrica_rec(this->root);
    cout << endl;
}

void serialization_rec(Node *node, stringstream& ss){
    if(node == nullptr){
        ss << '#' << " ";
    } 
    else{
        ss << node->key << " ";
        serialization_rec(node->left, ss);
        serialization_rec(node->right, ss);
    }
}

std::string BinaryTree::serialization() const {
    stringstream ss;
    serialization_rec(this->root, ss);
    return ss.str();
}