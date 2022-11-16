#include <iostream>
#include <sstream>
using namespace std;



int main(){
    string str;
    getline(cin, str);
    
    stringstream ss;
    ss << str;
    
    string word = " ";
    ss >> word;
    
    bool isOrder = true;
    
    for(int i = 0; i < (int) str.length(); i++){
        if(i > 0 && str.at(i) == ' ') {
            string temp;
            ss >> temp;
            
            if(word < temp){
                word = temp;
            }
            else{
                isOrder = false;
                break;
            }
        }
    }
    
    if(isOrder) cout << "sim";
    else cout << "nao";
}