#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include <windows.h>
using namespace std;

#include "Tablero.h"


#define ANCHO           7
#define ALTO            10
#define BORDE_SUPERIOR  1
#define BORDE_INFERIOR BORDE_SUPERIOR + ALTO + 1
#define BORDE_IZQUIERDO 2
#define BORDE_DERECHO   BORDE_IZQUIERDO + (ANCHO*2) +2

class Juego{
private:
    Coordenada* posTablero;
    Tablero* tablero;
public:
    Juego();
    void pruebas();

    void dibujarPieza();
    void borrarPieza();

    void GoToXY(int x, int y);
    void OcultarCursor();

    void mostrarTablero();

};

#endif // JUEGO_H
