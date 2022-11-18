#include <iostream>
#include <cmath>
#include "Point.h"

// Construtor padrão
Point::Point() {
    std::cout << "construtor padrao foi invocado" << std::endl; 
}

// Construtor com dois argumentos
Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
    std::cout << "construtor com dois argumentos foi invocado" << std::endl; 
}

// Construtor de cópia
Point::Point(const Point& point) {
    this->x = point.x;
    this->y = point.y;
    std::cout << "construtor de cópia foi invocado" << std::endl; 
}

// Destrutor
Point::~Point() {
    std::cout << "(" << x << "," << y << ") foi liberado" << std::endl;
}

void Point::print() {
    std::cout << "(" << x << "," << y << ")" << std::endl;
}

double Point::getX() {
    return x;
}

double Point::getY() {
    return y;
}
    
void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}

double Point::distancia(const Point& p) {
    double dx = (p.x - this->x) * (p.x - this->x);
    double dy = (p.y - this->y) * (p.y - this->y);
    return sqrt( dx + dy );
}