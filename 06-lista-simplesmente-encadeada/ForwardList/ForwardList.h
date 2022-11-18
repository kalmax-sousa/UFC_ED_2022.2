#ifndef FORWARDLIST_H
#define FORWARDLIST_H

#include <iostream>
#include  <string>
#include <sstream>
#include <vector>
#include "Node.h"

using Item = int;

class ForwardList{
private:
    Node* m_head {nullptr};
    int m_size {0};
    
public:
    ForwardList();

    ForwardList(const ForwardList& list);

    bool empty() const;

    int size() const;
    
    void clear();

    ~ForwardList();

    std::string toString();

    Item& operator[](int index);
    const Item& operator[](int index) const;
    void insert_at(int index, const Item& val);
    void remove_at(int index);

    Item& front();
    const Item& front() const;
    void push_front(const Item& value);
    void pop_front();

    Item& back();
    const Item& back() const;
    void push_back(const Item& value);
    void pop_back();

    void concat(ForwardList& list);

    void remove(const Item& list);

    ForwardList* clone();

    void appendVector(const std::vector<Item>& vec);

    void swap(ForwardList& lst);

    bool equals(const ForwardList& lst) const;

    void reverse();

    Item& get(int index);
    const Item& get(int index) const;
};

#endif