#include <iostream>
#include <vector>
using namespace std;

void right_rotation(vector<int>& vet, int nrot){
    for (int i = 0; i < nrot; i++) {
        int lastIndex = (int) vet.size() - 1;
        int aux = vet[lastIndex];
        
        for (int j = lastIndex; j >= 0; j--) {
            if(j == 0) vet[j] = aux;
            else{
                vet[j] = vet[j-1];
            }
        }
    }
}

void show(vector<int> &vet) {
    cout << "[ ";
    for(int value : vet)
        cout << value << " ";
    cout << "]\n";
}

int main(){
    int size, nrot;
    cin >> size >> nrot;
    vector<int> vet(size);
    for(int i = 0; i < size; i++)
        cin >> vet[i];
    
    right_rotation(vet, nrot);
    show(vet);
}