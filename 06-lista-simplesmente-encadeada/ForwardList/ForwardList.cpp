#include  <string>
#include <sstream>
#include "Node.h"
#include "ForwardList.h"

ForwardList::ForwardList(){
    this->m_head = new Node(0, nullptr);
}

ForwardList::ForwardList(const ForwardList& list){
    this->m_head = new Node(0, nullptr);
    this->m_size = list.m_size;
    Node *listCurrent = list.m_head->next;
    Node *thisLast = m_head;
    while(listCurrent != nullptr) {
        thisLast->next = new Node(listCurrent->value, nullptr);
        listCurrent = listCurrent->next;
        thisLast = thisLast->next;
    }
}

bool ForwardList::empty() const{
    return this->m_head->next == nullptr;
}

int ForwardList::size() const{
    return this->m_size;
}

void ForwardList::clear(){
    while (this->m_head->next != nullptr){
        Node* temp = this->m_head->next;
        this->m_head->next = temp->next;
        delete temp;
    }

    this->m_size = 0;
}

ForwardList::~ForwardList(){
    clear();
    delete this->m_head;
}

Item& ForwardList::operator[](int index) {
    int count = 0;
    Node *current = this->m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

const Item& ForwardList::operator[](int index) const {
    int count = 0;
    Node *current = this->m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

void ForwardList::insert_at(int index, const Item& val) {
    int count = 0;
    Node *current = this->m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *newNode = new Node(val, current->next);
    current->next = newNode;
    m_size++;
}

void ForwardList::remove_at(int index) {
    int count = 0;
    Node *current = this->m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    m_size--;
}

std::string ForwardList::toString(){
    std::stringstream ss;
    ss << "[";

    Node* currentPtr = this->m_head->next;
    while (currentPtr != nullptr)
    {
        ss << currentPtr->value;
        if(currentPtr->next != nullptr)
            ss << " ";

        currentPtr = currentPtr->next;
    }
    ss << "]";
    return ss.str();
}

Item& ForwardList::front() {
    return this->m_head->next->value;
}

const Item& ForwardList::front() const {
    return this->m_head->next->value;
}

void ForwardList::push_front(const Item& value){
    this->m_head->next = new Node(value, this->m_head->next);
    this->m_size++;
}

void ForwardList::pop_front(){
    if(this->m_head->next != nullptr){
        Node* aux  = this->m_head->next->next;
        delete this->m_head->next;
        this->m_head->next = aux;
    }
}

Item& ForwardList::back() {
    Node* aux = this->m_head->next;
    while(aux->next != nullptr){
        aux = aux->next;
    }
    
    return aux->value;
}

const Item& ForwardList::back() const {
    Node* aux = this->m_head->next;
    while(aux->next != nullptr){
        aux = aux->next;
    }
    
    return aux->value;
}

void ForwardList::push_back(const Item& value){
    Node* aux = this->m_head;
    while(aux->next != nullptr){
        aux = aux->next;
    }

    aux->next = new Node(value, nullptr);
    this->m_size++;
}

void ForwardList::pop_back() {
    Node* aux = this->m_head;
    while(aux->next->next != nullptr){
        aux = aux->next;
    }

    delete aux->next;
    aux->next = nullptr;
    this->m_size--;
}

void ForwardList::concat(ForwardList& lst) {
    Node* atual = this->m_head;
    
    while(atual->next != nullptr)
        atual = atual->next;
        
    while(lst.m_head->next != nullptr){
        atual->next = new Node(lst.m_head->next->value, nullptr);
        atual = atual->next;
        
        Node* temp = lst.m_head->next;
        lst.m_head->next = temp->next;
        delete temp;
    }
}

void ForwardList::remove(const Item& val) {
    if(this->m_head->next != nullptr){
        Node* aux = this->m_head;
        
        while(aux->next != nullptr){
            if(aux->next->value == val){
                Node* temp = aux->next->next;
                delete aux->next;
                aux->next = temp;
            } else{
                aux = aux->next;
            }
        }
    }
}

ForwardList* ForwardList::clone() {
    ForwardList* cop = new ForwardList();
    Node* atual = this->m_head;
    Node* aux = cop->m_head;
    
    while(atual->next != nullptr){
        aux->next = new Node(atual->next->value, nullptr);
        aux = aux->next;
        atual = atual->next;
    }
    
    cop->m_size = this->m_size;
    return cop;
}

void ForwardList::appendVector(const std::vector<Item>& vec) {
    Node* aux = this->m_head;
    
    while(aux->next != nullptr)
        aux = aux->next;
        
    for (int i = 0; i < vec.size(); i++) {
        aux->next = new Node(vec[i], nullptr);
        aux = aux->next;
    }
    
    this->m_size += vec.size();
}

void ForwardList::swap(ForwardList& lst) {
    ForwardList temp {lst};
    
    int tempSize = this->m_size;
    this->m_size = temp.m_size;
    lst.m_size = tempSize;
    
    lst.m_head = this->m_head;
    this->m_head = temp.m_head;
    
}

bool ForwardList::equals(const ForwardList& lst) const {
    if(this->m_size != lst.m_size){
        return false;
        
    }
    
    Node* atual = this->m_head;
    Node* aux = lst.m_head;
    
    while(atual->next != nullptr){
        if(atual->next->value != aux->next->value){
            return false;
        }
        
        atual = atual->next;
        aux = aux->next;
    }
    
    return true;
}

void ForwardList::reverse() {
    Node* p = nullptr;
    Node* aux = this->m_head->next;
    Node* n = nullptr;
    
    while(aux != nullptr){
        n = aux->next;
        aux->next = p;
        p = aux;
        aux = n;
    }
    
    this->m_head->next = p;
}

Item& ForwardList::get(int index) {
    if(index < 0 || index > this->m_size){
        throw std::range_error("index out of range");
    }
    
    Node *aux = this->m_head->next;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    
    return aux->value;
}

const Item& ForwardList::get(int index) const {
    if(index < 0 || index > this->m_size){
        throw std::range_error("index out of range");
    }
    
    Node *aux = this->m_head->next;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    
    return aux->value;
}