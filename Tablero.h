#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
using namespace std;

#include "Pieza.h"
#include "Coordenada.h"

enum Direccion {ARRIBA, ABAJO, DERECHA, IZQUIERDA};

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
    void fijarPieza();

    bool piezaPuedeExistir();
    void piezaMover(Direccion dir);

    void piezaRotar(bool sentidoHorario);
    int eliminarFilasCompletas();
};

#endif // TABLERO_H
