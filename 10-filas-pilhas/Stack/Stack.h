#ifndef STACK_H
#define STACK_H
#include <stdexcept>
#include "Node.h"

template <typename T>
class Stack{
    private:
        Node<T> *m_top {nullptr};
        int m_size {0};
    
    public:
        Stack() = default;

        bool empty() const {
            return this->m_top == nullptr;
        }

        int size() const {
            return this->m_size;
        }

        T& top(){
            if(empty()){
                throw std::underflow_error("empty stack");
            }
            return this->m_top->value;
        }

        const T& top() const {
            if(empty()){
                throw std::underflow_error("empty stack");
            }
            return this->m_top->value;
        }

        void push(const T& val){
            this->m_top = new Node<T>(val, this->m_top);
            this->m_size++;
        }

        void pop(){
            if(!empty()){
                Node<T> *temp = this->m_top;
                this->m_top = temp->next;
                delete temp;
                this->m_size--;
            }
        }

        ~Stack(){
            while(this->m_top != nullptr){
                Node<T> *aux = this->m_top;
                this->m_top = aux->next;
                delete aux;
            }

            this->m_size = 0;
        }
};

#endif