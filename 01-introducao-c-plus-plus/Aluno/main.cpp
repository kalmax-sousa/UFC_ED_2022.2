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

void print_aluno(Aluno aluno){
    if(aluno.nota >= 7)
        cout << aluno.nome << " aprovado(a) em " << aluno.disciplina;
    else
        cout << aluno.nome << " reprovado(a) em " << aluno.disciplina;
}

int main(){
    Aluno a = scan_aluno();
    print_aluno(a);
}