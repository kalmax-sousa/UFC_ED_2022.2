#include <iostream>
#include <string>
#include <sstream>
//#include <stack>
#include "Stack.h"
using namespace std;

string inverter_palavras(string str){
    Stack<char> pilha;
    string resultado = "";

    for (int i = 0; i <= (int) str.size(); i++){
        if(str[i] != ' ' && str[i] != '\0'){
            pilha.push(str[i]);
        }
        else{
            while(!pilha.empty()){
                resultado += pilha.top();
                pilha.pop();
            }
            resultado += str[i] == '\0' ? "" : " ";
        }
    }

    return resultado;
}
int main(){
    string tes = "xamlaK sod sotnaS asuoS";
    string res = inverter_palavras(tes);

    cout << res << endl;

    Stack<string> pilha;

    string line;
    cout << "Digite as palavras separadas por espaço: ";
    getline(cin, line);
    stringstream ss {line};

    string word;
    while(ss >> word){
        pilha.push(word);
        cout << pilha.top() << endl;
    }

}