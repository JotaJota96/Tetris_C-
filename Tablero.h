#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
using namespace std;

#include "Pieza.h"
#include "Coordenada.h"

class Tablero{
private:
    int** tablero;
    int alto;
    int ancho;
    Pieza* pieza;
    Coordenada* cxy;
public:
    Tablero(const int _alto, const int _ancho);
    ~Tablero();

    int get(int x, int y);
    int getAlto();
    int getAncho();
    Pieza* getPieza();
    Coordenada* getCoordenada();
    void nuevaPieza();
    void bajarPieza();
    void fijarPieza();
    bool piezaPuedeBajar();
    void eliminarUltimaFila();
};

#endif // TABLERO_H
