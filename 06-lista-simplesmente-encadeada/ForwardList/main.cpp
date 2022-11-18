#include <iostream>
#include "ForwardList.h"

int main(){
    ForwardList fl{};
    fl.push_front(12);
    fl.push_front(1);
    fl.push_front(23);
    fl.push_front(145);
    fl.push_front(0);

    std::cout << fl.toString() << std::endl;

    fl.push_back(4);
    fl.push_back(3);
    
    std::cout << fl.toString() << std::endl;

    fl.pop_front();

    std::cout << fl.toString() << std::endl;
}