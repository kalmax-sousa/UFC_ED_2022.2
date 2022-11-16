#ifndef LIST_H
#define LIST_H
#include "Node.h"

template<typename T>
class List{
    private:
        Node<T> *m_head {nullptr};
        int m_size {0};

    public:
        class iterator{
            private:
                Node<T> *ptr;
            public:
                iterator(Node<T> *pointer){
                    this->ptr = pointer;
                }

                bool operator!=(const iterator& it){
                    return this->ptr != it.ptr;
                }

                T& operator*(){
                    return this->ptr->value;
                }

                iterator& operator++(){
                   this->ptr = this->ptr->next;
                   return *this;
                }
        };

        iterator begin(){
            return iterator(this->m_head->next);
        }

        iterator end(){
            return iterator(this->m_head);

        }

        List(){
            this->m_head = new Node<T>(0, nullptr, nullptr);
            this->m_head->next = this->m_head;
            this->m_head->prev = this->m_head;
        }

        void push_back(const T& val){ //O(1)
            Node<T> *aux = new Node<T>(val, this->m_head->prev, this->m_head);
            this->m_head->prev = aux;
            aux->prev->next = aux;
            this->m_size++;
        }

        T& operator[](int index){
            Node<T> *aux = this->m_head->next;

            for (int i = 0; i < index; i++){
                aux = aux->next;
            }
            
            return aux->value;

        }

        const T& operator[](int index) const{
            Node<T> *aux = this->m_head->next;

            for (int i = 0; i < index; i++){
                aux = aux->next;
            }
            
            return aux->value;
        }

        int size() const{
            return this->m_size;
        }
        
        bool empty() const{
            return this->m_size == 0;
        }

        void pop_back(){
            if(!empty()){ //O(1)
                Node<T> *aux = m_head->prev;
                this->m_head->prev = aux->prev;
                aux->prev->next = this->m_head;

                delete aux;
                this->m_size--;
            }
        }

        void clear(){
            Node<T> *aux = this->m_head->prev;

            while(aux != this->m_head){
                Node<T> *temp = aux;
                aux = temp->prev;
                delete temp;
            }

            this->m_head->next = this->m_head->prev = this->m_head;
        }

        ~List(){
            clear();
            delete this->m_head;
        }
};

#endif