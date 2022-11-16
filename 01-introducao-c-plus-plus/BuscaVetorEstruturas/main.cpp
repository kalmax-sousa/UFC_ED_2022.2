#include <iostream>
using namespace std;

struct Aluno {
    int matricula {0};
    string nome;
    double nota;
};

Aluno scan_aluno(){
    Aluno aluno;
    
    cin >> aluno.matricula;
    cin.ignore();
    getline(cin, aluno.nome);
    cin >> aluno.nota;
    
    return aluno;
}

void print_aluno(Aluno aluno){
    
    if(aluno.matricula == 0)
         cout << "NAO ENCONTRADA";
    else{
        cout.precision(1);
        cout << aluno.nome << endl;
        cout << fixed << aluno.nota;
    }
}

Aluno encontra_aluno(Aluno alunos[], int tam, int matricula){
    for (int i = 0; i < tam; i++)
        if(alunos[i].matricula == matricula)
            return alunos[i];
    
    Aluno a;
    return a;
}

int main(){
    Aluno alunos[50];
    int numeroAlunos, matricula;
    
    cin >> numeroAlunos;
    
    for (int i = 0; i < numeroAlunos; i++)
        alunos[i] = scan_aluno();
    
    cin >> matricula;
    
    Aluno aluno = encontra_aluno(alunos, numeroAlunos, matricula);
    print_aluno(aluno);
}