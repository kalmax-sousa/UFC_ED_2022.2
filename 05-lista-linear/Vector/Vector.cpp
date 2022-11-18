#include <string>
#include <sstream>
#include "Vector.h"

Vector::Vector(){
    this->m_capacity = 10;
    this->m_data = new int[this->m_capacity];
}

// construtor
Vector::Vector(int capacity){
    this->m_capacity = capacity <= 0 ? 10 : capacity;
    this->m_data = new int[this->m_capacity];
}

// destrutor
Vector::~Vector(){
    delete[] m_data;
}

int Vector::size() {
    return this->m_size;
}

int Vector::capacity() {
    return this->m_capacity;
}

Vector::Vector(Vector& other){
    this->m_capacity = other.m_capacity;
    this->m_size = other.m_size;
    delete[] this->m_data;
    this->m_data = new int[other.m_capacity];
    
    for (int i = 0; i < other.m_size; i++) {
        this->m_data[i] = other.m_data[i];
    }
}

const Vector& Vector::operator = (const Vector& other){
    if(this != &other) {
        this->m_capacity = other.m_capacity;
        this->m_size = other.m_size;
        delete[] this->m_data;
        this->m_data = new int[other.m_capacity];
        
        for (int i = 0; i < other.m_size; i++) {
            this->m_data[i] = other.m_data[i];
        }
    }
    return *this;
}

void Vector::push_back(int value){
    if(this->m_size == this->m_capacity){
        this->m_capacity = 2*this->m_capacity;
        int* aux = this->m_data;
        this->m_data = new int[this->m_capacity];
        
        for (int i = 0; i < this->m_size; i++) {
            this->m_data[i] = aux[i];
        }
    }
        
    this->m_data[this->m_size] = value;
    this->m_size++;
}

int Vector::pop_back(){
    if(this->m_size == 0){
        throw std::runtime_error("lista vazia");
    }
    else {
        int aux = this->m_data[this->m_size-1]; 
        this->m_size--;
        
        if(this->m_size < this->m_capacity/2){
            this->m_capacity /= 2;
            int* temp = this->m_data;
            this->m_data = new int[this->m_capacity];

            for (int i = 0; i < this->m_size; i++) {
                this->m_data[i] = temp[i];
            }
            
            delete[] temp;
        }
        
        return aux;
    }
}

std::string Vector::toString(){
    std::stringstream ss;
    ss << "[";
    
    for (int i = 0; i < this->m_size; i++) {
        ss << " " << this->m_data[i];
    }
    
    ss << " ]";
    
    return ss.str();
}