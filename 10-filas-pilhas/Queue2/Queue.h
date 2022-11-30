#ifndef QUEUE_H
#define QUEUE_H
#include <stack>

class Queue{
    private: 
        std::stack<int> f1;
        std::stack<int> f2;
    
    public:
        Queue() = default;
        int first();
        void push(const int& val);
        void pop();
};

#endif