#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Pos{
    int l;
    int c;
};

//retorna um vetor com todos os vizinhos da posição p
vector<Pos> get_vizinhos(Pos p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

vector<Pos> vizinhos_validos(vector<Pos> vec, const vector<string>& matriz){
    for(int i = 0; i < (int)vec.size();){
        if(matriz[vec[i].l][vec[i].c] == '#' ||
           matriz[vec[i].l][vec[i].c] == '.'){
            vec.erase(vec.begin() + i);
        }else {
            i++;
        }
    }
    
    return vec;
}

void marca_caminho(vector<string>& mat, const Pos& ini, const Pos& fim){
    vector<string> matriz = mat;
    stack<Pos> caminho;
    caminho.push(ini);
    
    while(!caminho.empty()){
        matriz[caminho.top().l][caminho.top().c] = '.';
        
        if(caminho.top().c == fim.c && caminho.top().l == fim.l) {
            while(!caminho.empty()){
                mat[caminho.top().l][caminho.top().c] = '.';
                caminho.pop();
            }
            return;
        }
        
        vector<Pos> vizinhos = vizinhos_validos(get_vizinhos(caminho.top()), matriz);
        
        if(vizinhos.empty()){
            caminho.pop();
        }
        else {
            caminho.push(vizinhos.front());
        }
        
    }
}


int main(){
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    vector<string> mat(nl, ""); //começa com nl strings ""
    getchar();//remove \n after nc
    Pos inicio, fim;

    //carregando matriz
    for(int i = 0; i < nl; i++)
        getline(cin, mat[i]);

    //procurando inicio e fim e colocando ' ' nas posições iniciais
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == 'I'){
                mat[l][c] = ' ';
                inicio = Pos {l, c};
            }
            if(mat[l][c] == 'F'){
                mat[l][c] = ' ';
                fim = Pos {l, c};
            }
        }
    }
    
    marca_caminho(mat, inicio, fim);

    for(string line : mat)
        cout << line << endl;
    /*
    cout << "       nl=" << nl << " nc=" << nc << "\n";
    cout << "inicio: l=" << inicio.l << " , c=" << inicio.c << endl;
    cout << "   fim: l=" << fim.l << " , c=" << fim.c << endl;
    */
}