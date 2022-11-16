#include <iostream>
using namespace std;

void hanoi(int qte, char ini, char aux1, char aux2, char fim){
    if(qte == 0) return;
    if(qte == 1){
        cout << ini << " -> " << fim << endl;
        return;
    }
    
    hanoi(qte-2, ini, aux2, fim, aux1);
    cout << ini << " -> " << aux2 << endl;
    cout << ini << " -> " << fim << endl;
    cout << aux2 << " -> " << fim << endl;
    hanoi(qte-2, aux1, ini, aux2, fim);
}

int main(){
    int qte;
    cin >> qte;
    hanoi(qte, 'A', 'B', 'C', 'D');
    return 0;
}
