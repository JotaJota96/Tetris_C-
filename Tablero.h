#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
using namespace std;

class Tablero{
private:
    int** tablero;
    int alto;
    int ancho;
public:
    Tablero(const int _alto, const int _ancho);
    ~Tablero();

    void mostrar();

};

#endif // TABLERO_H
