#include <iostream>
#include "Point.h"
using namespace std;

int main() {
    Point p1(2,3);
    Point p2(6,7);

    cout << p1.distancia(p2) << endl;
    cout << p2.distancia(p1) << endl;
}