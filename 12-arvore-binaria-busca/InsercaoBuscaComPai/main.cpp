#include <iostream>
#include <string>
#include <sstream>
#include "bst.h"
using namespace std;

int main(){
	BST arv;
	string keys;
	getline(cin, keys);

	stringstream ss { keys };
	int value;

	while(ss >> value) 
		arv.add(value);

	arv.inorderParent();

	cout << endl;

	if(arv.contains(5))
		cout << "Contem 5" << endl;
	else
		cout << "Nao contem 5" << endl;

	if(arv.contains(78))
		cout << "Contem 78" << endl;
	else
		cout << "Nao contem 78" << endl;

	if(arv.contains(0))
		cout << "Contem 0" << endl;
	else
		cout << "Nao contem 0" << endl;
	
	return 0;
}