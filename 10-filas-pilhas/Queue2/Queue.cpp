#include "Queue.h"
#include <iostream>

int Queue::first(){
    if(this->f2.empty()){
        while(!this->f1.empty()){
        
            int val = this->f1.top();
            this->f2.push(val);
            this->f1.pop();
        }
    }
    
    return this->f2.top();
}

void Queue::push(const int& val){
    this->f1.push(val);
}

void Queue::pop(){
    if(this->f2.empty()){
        while(!this->f1.empty()){
            this->f2.push(this->f1.top());
            this->f1.pop();
        }
    }

    this->f2.pop();
}