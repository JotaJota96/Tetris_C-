#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

#include "Tablero.h"


#define ANCHO           12
#define ALTO            16
#define BORDE_SUPERIOR  1
#define BORDE_INFERIOR BORDE_SUPERIOR + ALTO + 1
#define BORDE_IZQUIERDO 2
#define BORDE_DERECHO   BORDE_IZQUIERDO + (ANCHO*2) +2

#define FLECHA_ARRIBA    72
#define FLECHA_ABAJO     80
#define FLECHA_DERECHA   77
#define FLECHA_IZQUIERDA 75
#define TECLA_ESPACIO    32


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
    void mostrarGameOver();

};

#endif // JUEGO_H
