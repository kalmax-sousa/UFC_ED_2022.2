#include "bst.h"
#include <iostream>

BST::BST(){
    root = nullptr;
}

BST::~BST(){
    root = clear(root);
}

Node *BST::clear(Node *node){
    if(node != nullptr){
        node->left = clear(node->left);
        node->right = clear(node->right);
        delete node;
    }
    return nullptr;
}

Node *BST::search(Node *node, int key){
    if(node == nullptr || key == node->key)
        return node;
    else if(key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

bool BST::contains(int key){
    return search(root, key) != nullptr;
}

Node *BST::add(Node *node, int key){
    if(node == nullptr){
        node = new Node(key, nullptr, nullptr);
        return node;
    }
    
    if(key < node->key)
        node->left = add(node->left, key);
    else if(key > node->key)
        node->right = add(node->right, key);
    return node;
}

void BST::add(int key){
    root = add(root, key);
}

Node *BST::minimum(Node *node){
    if(node->left != nullptr)
        return minimum(node->left);

    return node;
}

int BST::minimum(){
    if(root == nullptr)
        throw std::runtime_error("erro: arvore vazia");
    else
        return minimum(root)->key;
}

Node *BST::maximum(Node *node){
    if(node->right != nullptr)
        return maximum(node->right);

    return node;
}

int BST::maximum(){
    if(root == nullptr)
        throw std::runtime_error("erro: arvore vazia");
    else
        return maximum(root)->key;
}

Node *BST::sucessor(Node *x, Node *raiz) {
    if(x == nullptr || raiz == nullptr)
        return nullptr;
    else if(x->right != nullptr)
        return minimum(x->right);
    else
        return ancestral_sucessor(x, raiz);
}

Node *BST::ancestral_sucessor(Node *x, Node *raiz) {
    if(x == nullptr || raiz == nullptr)
        return nullptr;
    
    Node *successor = nullptr;
    while(raiz != x){
        if(x->key > raiz->key){
            raiz = raiz->right;
        }
        
        if(x->key < raiz->key){
            successor = raiz;
            raiz = raiz->left;
        }
    }
    
    return successor;
}

int BST::successor(int k) {
    Node *temp = search(root, k);
    if(temp != nullptr){
        Node *succ = sucessor(temp, root);
        if(succ != nullptr)
            return succ->key;
        else
            throw std::runtime_error("nao existe sucessor");
    }
    else throw std::runtime_error("chave inexistente");
}

Node* BST::predecessor(Node *x, Node* raiz) {
    if(x == nullptr || raiz == nullptr)
        return nullptr;
    else if(x->left != nullptr)
        return maximum(x->left);
    else
        return ancestral_predecessor(x, raiz);
}

Node *BST::ancestral_predecessor(Node *x, Node* raiz) {
    if(x == nullptr || raiz == nullptr)
        return nullptr;
    
    Node *predecessor = nullptr;
    while(raiz != x){
        if(x->key < raiz->key){
            raiz = raiz->left;
        }
        
        if(x->key > raiz->key){
            predecessor = raiz;
            raiz = raiz->right;
        }
    }
    
    return predecessor;
}

int BST::predecessor(int k) {
    Node *temp = search(root, k);
    if(temp != nullptr){
        Node *pred = predecessor(temp, root);
        if(pred != nullptr)
            return pred->key;
        else
            throw std::runtime_error("nao existe antecessor");
    }
    else throw std::runtime_error("chave inexistente");
}

void BST::remove(int key){
    remove(key, root);
}

Node *BST::remove(int k, Node *node){
    if(node == nullptr)
        return nullptr;

    if(key == node->key)
        return removeRoot(node);

    if(key < node->key)
        node->left = remove(k, node->left);
    else
        node->right = remove(k, node->right);

    return node;
}

Node *BST::removeRoot(Node *node){
    Node *pai, *q;
    if(node->right == nullptr)
        q =node->left;
    else{
        pai = node;
        q = node->right;
        while(q->left != nullptr){
            pai = q;
            q = q->left;
        }
        if(pai != node){
            pai->left = q->right;
            q->right = node->right;
        }
        q->left = node->left;
    }
    delete node;
    return 1;
}

void BST::inorder(){
    inorder(root);
}

void BST::inorder(Node *node){
    if(node != nullptr){
        inorder(node->left);
        std::cout << node->key << " ";
        inorder(node->right);
    }
}