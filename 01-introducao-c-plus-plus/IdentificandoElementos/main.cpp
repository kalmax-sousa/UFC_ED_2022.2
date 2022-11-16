#include <iostream>
#include <sstream>
using namespace std;

string typeText(string s){
    bool isLetter = false;
    bool isPoint = false;
    for(int i = 0; i < (int) s.length(); i++){
        if(s[i] >= 97 && s[i] <= 122){
            isLetter = true;
            break;
        } else if(s[i] == '.'){
            isPoint = true;
        }
    }
    
    if(isLetter) return "str";
    else if(isPoint) return "float";
    else return "int";
}

int main(){
    char frase[100];
    
    cin.get(frase , 100);
    
    stringstream ss;
    ss << frase;
    
    for (int i = 0; frase[i] != '\0'; i++) {
        if(i == 0){
            string aux;
            ss >> aux;
            cout << typeText(aux) << " ";
            
        } else if(frase[i] == ' '){
            string aux;
            ss >> aux;
            cout << typeText(aux) << " ";
        }
    }
}