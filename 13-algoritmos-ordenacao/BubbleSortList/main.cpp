#include <iostream>
#include "List.h"
using namespace std;

int main() {
    List list;

    int value;
    while(cin >> value) 
        list.push_back(value);

    for(auto it = list.begin(); it != list.end(); ++it) 
        cout << *it << " ";
    cout << endl;

    list.bubblesort();

    for(auto it = list.begin(); it != list.end(); ++it) 
        cout << *it << " ";
    cout << endl;
}