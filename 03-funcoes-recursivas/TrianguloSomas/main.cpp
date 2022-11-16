#include <iostream>
using namespace std;

void print_triangulo_somas(int *v, int n){
    if(n == 1){
        cout << "[" << v[n-1] << "]" << endl;
    }
    else{
        int *aux = new int[n-1];
        for(int i = 1; i < n; i++){
            aux[i-1] = v[i-1] + v[i];
        }
        
        print_triangulo_somas(aux, n-1);
        
        cout << "[";
        for(int i = 0; i < n; i++){
            if(i != 0)
                cout << ", ";
                
            cout << v[i];
        }
        cout << "]" << endl;
        
        delete[] aux;
    }
}

int main(){
    int n = 0;
    cin >> n;
    
    int *v = new int[n];
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    print_triangulo_somas(v, n);
    
    delete[] v;
}