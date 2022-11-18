// Nao mexa, ja esta terminado
#ifndef CLIST_H
#define CLIST_H
#include <string>
#include "Node.h"

class CircularList {
private:
    Node *m_head {nullptr};     // ponteiro para o primeiro node da lista
    int m_size {0};             // guarda o numero de elementos da lista

public:
    CircularList() = default; 
    bool empty() const { return m_head == nullptr; } 
    int size() const { return m_size; }

    void push_back(const Item& val);
    void pop_back();
    void insert(int index, const Item& val);
    void remove(const Item& val);
    Item& operator[](int index);
    const Item& operator[](int index) const;
    std::string toString() const;
    void clear_iterativo();
    void clear_recursivo();
    ~CircularList();
};

#endif