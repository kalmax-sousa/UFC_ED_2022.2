#ifndef BST_H
#define BST_H
#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    Node *parent;

    // Construtor
    Node(int k, Node* l = nullptr, Node* r = nullptr, Node* p = nullptr) {
        this->key = k;
        this->left = l;
        this->right = r;
        this->parent = p;
    }
    // Destrutor
    ~Node() {
        cout << "Node removed: " << this->key << endl;
    }
};

class BST {
public:
    BST();
    BST(int k);
    void bshow();
    bool add(int k);
    bool contains(int k);
    void inorderParent();
    ~BST();
private:
    Node *root;
    void bshow(Node *node, std::string heranca);
    Node *clear(Node *node); 
    Node *search(int k); // ---> Implementar
};

// Constructor 1
BST::BST() {
    root = nullptr;
}

// Constructor 2
BST::BST(int k) {
    root = new Node(k);
}

void BST::bshow(){
    bshow(root, "");
}

void BST::bshow(Node *node, std::string heranca) {
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        bshow(node->right , heranca + "r");
    for(int i = 0; i < (int) heranca.size() - 1; i++)
        std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
    if(heranca != "")
        std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
    if(node == nullptr){
        std::cout << "#" << std::endl;
        return;
    }
    std::cout << node->key << std::endl;
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        bshow(node->left, heranca + "l");
}

Node *BST::clear(Node *node) {
    if(node != nullptr) {
        node->left = clear(node->left);
        node->right = clear(node->right);
        delete node;
    }
    return nullptr;
}

BST::~BST() {
    root = clear(root);
}

// Percorre os nos da arvore em ordem simetrica, imprimindo os pais
void BST::inorderParent() {
    stack<Node*> p; // Cria pilha do tipo Node* (ponteiro para Node)
    if(root != nullptr)
        p.push(root);
    while(!p.empty()) {
        Node *no = p.top();
        p.pop();
        if(no->parent != nullptr) cout << no->parent->key << " ";
        if(no->right != nullptr) p.push(no->right);
        if(no->left != nullptr) p.push(no->left);
    }
}

bool BST::add(int k) {
    if(root == nullptr){
        root = new Node(k, nullptr, nullptr, nullptr);
        return true;
    }
    
    Node *aux = root;
    while(aux != nullptr){
        if(aux->key > k){
            if(aux->left == nullptr){
                Node *temp = new Node(k, nullptr, nullptr, aux);
                aux->left = temp;
                return true;
            }
            else{
                aux = aux->left;
            }
        }
        else if(aux->key < k){
            if(aux->right == nullptr){
                Node *temp = new Node(k, nullptr, nullptr, aux);
                aux->right = temp;
                return true;
            }
            else{
                aux = aux->right;
            }
        }
        else return false;
    }
    return false;
}

Node *BST::search(int k) {
    Node *aux = root;
    
    while(aux != nullptr){
        if(aux->key > k)
            aux = aux->left;
        else if(aux->key < k)
            aux = aux->right;
        else
            break;
    }
    return aux;
}

bool BST::contains(int k) {
    return search(k) != nullptr;
}

#endif 