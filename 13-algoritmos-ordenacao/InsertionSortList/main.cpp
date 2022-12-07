#include <iostream>
#include "List.h"
using namespace std;

int main() {
    List list; // cria lista vazia

    int value;
    while(cin >> value) 
        list.push_back(value);

    // imprime a lista original na tela 
    for(auto it = list.begin(); it != list.end(); ++it) 
        cout << *it << " ";
    cout << endl;

    list.insertionsort(); // ordena a lista

    // imprime a lista ordenada
    for(auto it = list.begin(); it != list.end(); ++it) 
        cout << *it << " ";
    cout << endl;
}