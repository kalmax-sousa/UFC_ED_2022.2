#include <iostream>
using namespace std;

int main(){
    string str;
    
    getline(cin, str);
    
    for(int i = 0; i < (int) str.length(); i++){
        if((str[i] == 'a' || str[i] == 'e' || str[i] == 'o' || str[i] == 'i' || str[i] == 'u') && str[i+1] == ' ' && str[i] == str[i+2]){
            cout << str[i];
            char vogal = str[i];
            while(str[i] == vogal || str[i] == ' ') i++;
            i--;
        } else{
            cout << str[i];
        }
    }
}