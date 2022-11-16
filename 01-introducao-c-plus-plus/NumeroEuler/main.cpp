#include <iostream>
using namespace std;

double fatorial(int n){
    double fator = 1;
    
    for(int i = n; i > 0; i--){
        fator *= i;
    }
    
    return fator;
}

double euler(int e){
    double number = 1;
    
    for(int i = e; i > 0; i--){
        number += 1/fatorial(i);
    }
    
    return number;
}

int main(){
    
    int n = 0;
    
    cin >> n;
    
    cout << fixed << euler(n);
    
    return 1; 
}