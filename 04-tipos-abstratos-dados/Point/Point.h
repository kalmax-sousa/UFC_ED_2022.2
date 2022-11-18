#ifndef POINT_H
#define POINT_H

class Point {
private:
    // atributos
    double x {0.0};
    double y {0.0};
public:
    // Construtor padrao
    Point();

    // Construtor com dois argumentos
    Point(double x, double y);

    // Construtor de copia
    Point(const Point& point);

    // Destrutor
    ~Point();

    //imprime o ponto
    void print();

    // getters: retornam o valor da coordenada x e y
    double getX();
    double getY();

    // setters: mudam os valores das coordenadas
    void setX(double x);
    void setY(double y);
    
    // retorna a distancia entre dois pontos
    double distancia(const Point& p);
};

#endif