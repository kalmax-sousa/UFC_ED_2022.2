#ifndef VECTOR_H
#define VECTOR_H
#include <string>

// classe que implementa uma lista redimensionável
class Vector {
    private:
        int m_capacity {0}; //esse {} é o modo de inicializar default do c++ a partir do c++11
        int m_size {0};
        int * m_data {nullptr}; //inicializar pra não conter lixo

public:
	// construtor vazio
    Vector();

	// construtor
    Vector(int capacity);

	// destrutor
    ~Vector();

	int size();

	int capacity();

    Vector(Vector& other);

    const Vector& operator = (const Vector& other);

    void push_back(int value);

    int pop_back();

    std::string toString();
};

#endif