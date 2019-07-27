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
    int tipoPiezaAnterior;
public:
    Tablero(const int _alto, const int _ancho);
    ~Tablero();

    int get(int x, int y);
    int getAlto();
    int getAncho();
    Pieza* getPieza();
    Coordenada* getCoordenada();
    bool nuevaPieza();
    void bajarPieza();
    void fijarPieza();

    bool piezaPuedeBajar();
    bool piezaPuedeExistir();

    bool piezaPuedeIrAArriba();
    bool piezaPuedeIrAAbajo();
    bool piezaPuedeIrALaIzquierda();
    bool piezaPuedeIrALaDerecha();

    void piezaRotar(bool sentidoHorario);
    void eliminarFilasCompletas();
};

#endif // TABLERO_H
