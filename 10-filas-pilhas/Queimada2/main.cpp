#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Ponto{
    int l;
    int c;
};

vector<Ponto> get_vizinhos(Ponto p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

void queimar(vector<string>& matriz, const Ponto& inicio){
    stack<Ponto> fogo;
    fogo.push(inicio);
    
    while(!fogo.empty()){
        if(matriz[fogo.top().l][fogo.top().c] == '.') return;
        matriz[fogo.top().l][fogo.top().c] = 'o';
        
        vector<Ponto> vizinhos = get_vizinhos(fogo.top());
        for(int i = 0; i < (int)vizinhos.size();){
            if(vizinhos[i].l < 0 || vizinhos[i].c < 0 || 
               vizinhos[i].l >= (int)matriz.size() || vizinhos[i].c >= (int)matriz[0].size() ||
               matriz[vizinhos[i].l][vizinhos[i].c] == '.' || 
               matriz[vizinhos[i].l][vizinhos[i].c] == 'o'){
                vizinhos.erase(vizinhos.begin() + i);
            }else {
                i++;
            }
        }
        if(vizinhos.empty()){
            fogo.pop();
        }
        else {
            for(int i = 0; i < (int) vizinhos.size(); i++){
                fogo.push(vizinhos[i]);
            }
        }
        
    }
}

int main(){
    int nl = 0, nc = 0, fl, fc;
    cin >> nl >> nc >> fl >> fc;
    vector<string> mat(nl, "");
    cin.ignore();

    for(int i = 0; i < nl; i++)
        getline(cin, mat[i]);
        
    queimar(mat, {fl, fc});

    for(string line : mat)
        cout << line << endl;
}