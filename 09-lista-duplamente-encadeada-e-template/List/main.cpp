#include <iostream>
#include "List.h"
using namespace std;

void print(List<float>& lst){
    for (int i = 0; i < lst.size(); i++)
    {
        cout << lst[i] << " ";
    }
    cout << endl;
}

int main(){
    List<int> list;

    for (int i = 1; i <= 9; i++)
        list.push_back(i);

    for (List<int>::iterator it = list.begin(); it != list.end(); ++it){
        cout << *it << " ";
    }

    cout << endl;
}

/*
int main(){
    List<float> list;

    for (int i = 1; i <= 9; i++){
        list.push_back(i);
    }

    print(list);

    for (int i = 20; i <= 27; i++){
        list.push_back(i);
    }

    print(list);

    list.clear();
    
}
*/