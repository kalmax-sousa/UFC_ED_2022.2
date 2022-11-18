#include <sstream>
#include <string>
#include "Node.h" 
#include "CircularList.h" 

void CircularList::push_back(const Item& val) { 
    if(this->empty()){
        this->m_head = new Node(val, nullptr);
        this->m_head->next = this->m_head;
    } else{
        Node* aux = this->m_head;
        while (aux->next != this->m_head){
            aux = aux->next;
        }
        
        aux->next = new Node(val, this->m_head);
    }

    this->m_size++;
}

void CircularList::pop_back() {
    if(this->empty()) return;
    else if(this->m_head == this->m_head->next){
        delete this->m_head;
        this->m_head = nullptr;
    }
    else{
        Node* aux = this->m_head;
        while (aux->next->next != this->m_head){
            aux = aux->next;
        }

        delete aux->next;
        aux->next = this->m_head;    
    }
    
    this->m_size--;
}

void CircularList::insert(int index, const Item& val){
    if(index < 0 || index > this->m_size){
        throw  std::range_error("indice inválido");
    } 
    
    if(empty()){
        this->m_head = new Node(val, nullptr);
        this->m_head->next = this->m_head;
        this->m_size++;
    } 
    else if(index == 0){
        Node* novo = new Node(val, this->m_head);
        Node* aux = this->m_head;
        while(aux->next != this->m_head){
            aux = aux->next;
        }
        aux->next = novo;
        this->m_head = novo;

        this->m_size++;
    }
    else {
        Node* aux = this->m_head;

        for (int i = 0; i < index-1; i++)
            aux = aux->next;

        Node* temp = new Node(val, aux->next);
        aux->next = temp;

        this->m_size++;
    }
}

void CircularList::remove(const Item& val){
    if(this->empty()) return;
    if(this->m_size == 1){
        if(this->m_head->value == val){
            delete this->m_head;
            this->m_head = nullptr;
            this->m_size = 0;
        }
    }
    else{
        if(this->m_head->value == val){
            Node* aux = this->m_head;

            while(aux->next != this->m_head){
                aux = aux->next;
            }

            aux->next = this->m_head->next;
            delete this->m_head;
            this->m_head = aux->next;
            this->m_size--;
        } 
        else{
            Node* aux = this->m_head;
            while(aux->next->value == val && aux->next != this->m_head){
                aux = aux->next;
            }

            if(aux->next != m_head){
                Node* temp = aux->next;
                aux->next = temp->next;
                delete temp;
                this->m_size--;
            }
        }

    }
}

std::string CircularList::toString() const {
    std::stringstream ss;
    ss << "[";

    Node* current = this->m_head;
    if(current != nullptr){
        ss << current->value << " ";
        while(current->next != this->m_head){
            current = current->next;
            ss << current->value << " ";
        }
    }

    ss << "]";
    return ss.str();
}

Item& CircularList::operator[](int index) {
    Node* aux = this->m_head;
    for (int i = 0; i < index; i++){
        aux = aux->next;
    }
    return aux->value;
}

const Item& CircularList::operator[](int index) const {
    Node* aux = this->m_head;
    for (int i = 0; i < index; i++){
        aux = aux->next;
    }
    return aux->value;
}

void clear_recursive(Node* current, Node* initial){
    if(current->next == initial){
        delete current;
    } 
    else {
        clear_recursive(current->next, initial);
        delete current;
    }
}

void CircularList::clear_recursivo(){
    if(!this->empty()){
        clear_recursive(this->m_head, this->m_head);
        this->m_head = nullptr;
        this->m_size = 0;
    }
}

void CircularList::clear_iterativo(){
    if(!this->empty()){
        Node* aux1 = this->m_head->next;
        Node* aux2 = this->m_head->next;

        while(aux1 != this->m_head){
            aux2 = aux2->next;
            delete aux1;
            aux1 = aux2;
        }

        delete this->m_head;
        this->m_head = nullptr;
        this->m_size = 0;
    }
}

CircularList::~CircularList() {
    this->clear_iterativo();
}

