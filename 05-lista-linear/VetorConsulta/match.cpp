#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> matchingStrings(vector<string> consulta, vector<string> busca){
    vector<int> matches;
    for (int i = 0; i < (int) busca.size(); i++) {
        int count = 0;
        for (int j = 0; j < (int) consulta.size(); j++) {
            if(busca[i] == consulta[j]) {
                count++;
            }
        }
        matches.push_back(count);
    }
    return matches;
}

int main(){
    int n;
    cin >> n;
    vector<string> consulta;
    for (int i = 0; i < n; i++){
        string aux;
        cin >> aux;
        consulta.push_back(aux);
    }
    
    int m;
    cin >> m;
    vector<string> busca;
    for (int i = 0; i < m; i++){
        string aux;
        cin >> aux;
        busca.push_back(aux);
    }
    
    vector<int> matches = matchingStrings(consulta, busca);
    
    for (int i = 0; i < (int)matches.size(); i++) {
        if(i != 0) cout << " ";
        cout << matches[i];
    }
    cout << endl;
}