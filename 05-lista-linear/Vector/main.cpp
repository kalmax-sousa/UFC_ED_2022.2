#include <iostream>
#include <sstream>
#include "Vector.h"
using namespace std;

int main(){
    string line, cmd;
    int value;
    Vector v(0);
    while(true){
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        } else if(cmd == "init"){
            ss >> value;
            v = Vector(value);
        } else if(cmd == "status"){
            cout << "size:" << v.size() << " capacity:" << v.capacity() << "\n";
        } else if(cmd == "push_back"){
            while(ss >> value)
                v.push_back(value);
        } else if(cmd == "pop_back"){
            ss >> value;
            cout << "popped: ";
            for(int i = 0; i < value; ++i)
                cout << v.pop_back() << " ";
            cout << endl;
        } else if(cmd == "show"){
            cout << v.toString() << endl;
        } else {
            cout << "fail: comando invalido\n";
        }
    }
}