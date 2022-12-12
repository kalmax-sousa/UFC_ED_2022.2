#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include "bst.h"
using namespace std;

int main(){
	BST arv;
	string skeys;
	
	getline(cin, skeys);

	stringstream ss { skeys };
	int value;

	while(ss >> value) {
		arv.add(value);
	}

	cout << "minimo: " << arv.minimum() << endl;
	cout << "maximo: " << arv.maximum() << endl;

    int v;
	cin >> v;

    try
    {
        int pred = arv.predecessor(v);
        cout << "antecessor(" << v << ") = " << pred << endl;
    }
    catch(const std::runtime_error& e)
    {
        cout << v << " nao tem antecessor ou nao esta na arvore" << endl;
    }

    try
    {
        int succ = arv.successor(v);
        cout << "sucessor(" << v << ") = " << succ << endl;
    }
    catch(const std::runtime_error& e)
    {
        cout << v << " nao tem sucessor ou nao esta na arvore" << endl;
    }
    
	return 0;
}