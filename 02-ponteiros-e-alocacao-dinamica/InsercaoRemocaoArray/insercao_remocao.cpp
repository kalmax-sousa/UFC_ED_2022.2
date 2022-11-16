#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct aluno {
    int matricula;
    char nome[50];
    float media;
};

aluno le_aluno(){
    aluno a;
    cin >> a.matricula;
    cin.ignore(); 
    cin.get(a.nome, 50);
    cin >> a.media;
    return a;
}

aluno* insere_aluno(aluno *v, int *n, aluno novo){
    aluno *aux = v;
    v = new aluno[*n+1];
    
    if(v == 0)
        return 0;
    
    if(*n > 0)
        for (int i = 0; i < *n; i++)
            v[i] = aux[i];
        
    v[*n] = novo;
    *n = *n + 1;
    return v;
}

aluno* remove_aluno(aluno *v, int *n, int matricula){
    for(int i = 0; i < *n; i++){
        if(matricula == v[i].matricula){
            aluno *aux = v;
            
            v = new aluno[*n-1];
            
            for (int j = 0, k = 0; j < *n; j++) {
                if(aux[j].matricula != matricula){
                    v[k] = aux[j];
                    k++;
                }
            }
            
            *n -= 1;
            break;
        }
    }

    return v;
}

int main(){
    int num_oper = 0, i, n = 0;
    cin >> num_oper;
    aluno *v = new aluno[n];

    for (i = 0; i < num_oper; i++) {
        cin.ignore(); // lê e descarta o caractere '\n' do buffer 
        char oper;
        cin >> oper;
        if (oper == 'i') {
            aluno a = le_aluno();
            v = insere_aluno(v, &n, a);
        } else {
            int mat;
            cin >> mat;
            v = remove_aluno(v, &n, mat);
        }
    }
    for (i = 0; i < n; i++) {
        cout << v[i].matricula << "\n" << v[i].nome << "\n" << std::fixed << setprecision(1) << v[i].media << "\n";
    }
   
    delete[] v;
    return 0;
}