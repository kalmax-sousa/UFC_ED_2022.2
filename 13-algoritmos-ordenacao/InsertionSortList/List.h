// Lista duplamente encadeada circular com node sentinela
#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include <iostream>

class List {
private:
    Node *m_head {nullptr}; // ponteiro para o node sentinela
    int m_size {0}; // numero de elementos na lista atualmente

public:
    // Construtor default: cria uma lista vazia, ou sejaaa, 
    // com o ponteiro m_head apontando para o node sentinela
    List() { // O(1)
        m_head = new Node(0, nullptr, nullptr);
        m_head->prev = m_head->next = m_head;
    }

    // insere um elemento no final da lista
    void push_back(const int& val) { // O(1)
        Node *aux = new Node(val, m_head->prev, m_head);
        aux->prev->next = aux;
        m_head->prev = aux;
        m_size++;
    }

    // retorna o numero de elementos na lista
    int size() const { // O(1)
        return m_size;
    }

    // retorna true se e somente se lista eh vazia
    bool empty() const { // O(1)
        return m_size == 0;
    }

    // deixa a lista vazia novamente, liberando memoria
    void clear() { // O(n)
        Node *aux = m_head->prev;
        while(aux != m_head) {
            Node *temp = aux;
            aux = aux->prev;
            delete temp;
        }
        m_head->prev = m_head->next = m_head;
        m_size = 0;
    }

    // Destrutor
    ~List() { // O(n)
        clear();
        delete m_head;
    }

    // iterador para a lista
    class iterator {
    private:
        Node *pointer {nullptr};
    public:
        iterator(Node *ptr) {
            pointer = ptr;
        }
        iterator& operator++() {
            pointer = pointer->next;
            return *this;
        }
        bool operator!=(const iterator& it) {
            return this->pointer != it.pointer;
        }
        int& operator*() {
            return pointer->value;
        }
    };

    // retorna um iterador para o primeiro elemento da lista
    iterator begin() {
        return iterator(m_head->next);
    }

    // retorna um iterador para uma posicao apos o ultimo elemento
    iterator end() {
        return iterator(m_head);
    }

    void insertionsort() {
        Node *aux = this->m_head->next;
        for (int i = 1; i <= this->m_size-1; i++, aux = aux->next){
            int key = aux->next->value;
            int j = i-1;
            Node *temp = aux;
            while(j >= 0 && temp->value > key){
                temp->next->value = temp->value;
                j--;
                temp = temp->prev;
            }
            temp->next->value = key;
        }
    }
};

#endif