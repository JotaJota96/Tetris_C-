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
    Pieza* colaDePiezas[3];
    Coordenada* cxy;
public:
    Tablero(const int _alto, const int _ancho);
    ~Tablero();

    int getAlto();
    int getAncho();
    int get(int x, int y);
    Coordenada* getCoordenada();
    Pieza* getPieza();
    Pieza** getColaDePiezas(int &tam);

    bool nuevaPieza();
    void fijarPieza();

    bool piezaPuedeExistir();
    void piezaMover(Direccion dir);
    void piezaRotar(bool sentidoHorario);

    void alternarPieza();
    int eliminarFilasCompletas();
};

#endif // TABLERO_H
