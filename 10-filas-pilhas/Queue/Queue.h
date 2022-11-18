#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include <stdexcept>

template<typename T>
class Queue{
    private:
        Node<T> *m_first {nullptr};
        Node<T> *m_last {nullptr};
        int m_size {0};
    
    public:
        //Construtor
        Queue() = default;

        //Verifica  see a fila está vazia
        bool empty() const{
            return this->m_first == nullptr;
        }

        //Retorna o número de elementos da fila
        int size() const{
            return this->m_size;
        }

        //Retorna uma referencia para primeiro valor
        T& front(){
            if(empty())
                throw std::underflow_error("Fila vazia");

            return this->m_first->value;
        }

        //Retorna uma referencia constante para primeiro valor
        const T& front() const{
            if(empty())
                throw std::underflow_error("Fila vazia");

            return this->m_first->value;
        }
        
        //Retorna uma referencia para ultimo valor
        T& back(){
            if(empty())
                throw std::underflow_error("Fila vazia");

            return this->m_last->value;
        }

        //Retorna uma referencia constante para ultimo valor
        const T& back() const{
            if(empty())
                throw std::underflow_error("Fila vazia");

            return this->m_last->value;
        }

        //Insere valor no final da lista
        void push(const T& val){
            if(empty()){
                this->m_first = this->m_last = new Node<T>(val, nullptr);

            } else{
                this->m_last->next = new Node<T>(val, nullptr);
                this->m_last = this->m_last->next;
            }

            this->m_size++;
        }
        void pop(){
            if(!empty()){
                Node<T> *aux = this->m_first;
                this->m_first = aux->next;
                aux->next = nullptr;
                delete aux;
                this->m_size--;
                
                if(size() == 0){
                    this->m_last = nullptr;
                }

            }
        }
};

#endif