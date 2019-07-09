#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
using namespace std;

#include "Pieza.h"
#include "Coordenada.h"

class Tablero{
private:
    bool** tablero;
    int alto;
    int ancho;
    Pieza* pieza;
    Coordenada* cxy;
public:
    Tablero(const int _alto, const int _ancho);
    ~Tablero();

    Pieza* getPieza();
    Coordenada* getCoordenada();
    void nuevaPieza();
    void bajarPieza();
};

#endif // TABLERO_H
