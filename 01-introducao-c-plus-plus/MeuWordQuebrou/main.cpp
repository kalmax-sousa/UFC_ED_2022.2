#include <iostream>
#include <limits>
using namespace std;

string transfStr(string s, char c){
    if(c == 'M')
        for (int i = 0; i < (int) s.length(); i++)
            s[i] = toupper(s[i]);
    else if(c == 'm')
        for (int i = 0; i < (int) s.length(); i++)
            s[i] = tolower(s[i]);
    else if(c == 'i')
        for(int i = 0; i < (int) s.length(); i++){
            if(islower(s[i]))
                s[i] = toupper(s[i]);
            else if(isupper(s[i]))
                s[i] = tolower(s[i]);
        }
    else if(c == 'p')
        for (int i = 0; i < (int) s.length(); i++) {
            if((s[i-1] == ' ' || i == 0) && s[i+1] != ' ' )
                s[i] = toupper(s[i]);
            else
                s[i] = tolower(s[i]);
        }
        
    return s;
}

int main(){
    string str;
    char comand;
    
    getline(cin, str);
    cin.get(comand);
    
    str = transfStr(str, comand);
    cout << str;
}