#include <iostream>
using namespace std;

struct Aluno {
    char nome[80];
    int matricula;
    char disciplina[120];
    double nota;
};

Aluno scan_aluno(){
    Aluno aluno;
    cin >> aluno.nome;
    cin >> aluno.matricula;
    cin.ignore();
    cin >> aluno.disciplina;
    cin >> aluno.nota;
    
    return aluno;
}

void print_maior_nota(Aluno a1, Aluno a2){
    cout.precision(1);
    if(a1.nota > a2.nota)
        cout << a1.nome << " , " << fixed << a1.nota;
    else if (a1.nota < a2.nota)
        cout << a2.nome << " , " << fixed << a2.nota;
    else 
        cout << a1.nome << " e " << a2.nome << " , " << fixed << a1.nota;
}

int main(){
    Aluno a1 = scan_aluno();
    cin.ignore();
    Aluno a2 = scan_aluno();
    print_maior_nota(a1, a2);
}