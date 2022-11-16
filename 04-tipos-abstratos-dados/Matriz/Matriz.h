#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz {
private:
    int lin;     // numero de linhas da matriz
    int col;    // numero de colunas da matriz
    int **mat;   // ponteiro para matriz de inteiros (deve ser alocada dinamicamente)
    
public:
    // Construtor: aloca matriz com m linhas e n colunas
    Matriz(int m, int n);

    // Destrutor: libera memoria alocada
    ~Matriz(); 

    // Retorna o numero de linhas da matriz
    int linhas();

    // Retorna o numero de colunas da matriz
    int colunas();  

    // Retorna o valor contido na celula [i][j] da matriz
    int getValor(int i, int j); 

    // Atribui o valor v a celula [i][j] da matriz
    void setValor(int v, int i, int j); 

    // Imprimir a matriz 
    void print();

    //Soma as matrizes, caso o número de linhas e colunas sejam iguais
    Matriz *soma(Matriz& B); 
    
    //Multiplica as matrizes, caso o número de colunas da primeira seja igual ao número de linhas da segunda
    Matriz *multiplica(Matriz& B); 

    //Deleta o construtor, não podendo inicializar uma matriz passando outra
    Matriz(const Matriz& m) = delete;  
};

#endif