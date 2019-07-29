#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

#include "Tablero.h"

// Parametros del tablero de juego
#define ANCHO           12
#define ALTO            16
#define BORDE_SUPERIOR  1
#define BORDE_INFERIOR BORDE_SUPERIOR + ALTO + 1
#define BORDE_IZQUIERDO 2
#define BORDE_DERECHO   BORDE_IZQUIERDO + (ANCHO*2) +2

// Teclas de interaccion
#define FLECHA_ARRIBA         72
#define FLECHA_ABAJO          80
#define FLECHA_DERECHA        77
#define FLECHA_IZQUIERDA      75
#define TECLA_ROTAR_iZQUIERDA 97
#define TECLA_ROTAR_DERECHA  100
#define TECLA_FIJAR_PIEZA     115
#define TECLA_CAMBIAR_PIEZA   119


class Juego{
private:
    Coordenada* posTablero;
    Tablero* tablero;
public:
    Juego();
    void jugarPartida();

    void dibujarPieza();
    void borrarPieza();

    void mostrarTablero();
    void mostrarGameOver();
    void mostrarPuntaje(int puntaje);
    void mostrarColaDePiezas();

    void GoToXY(int x, int y);
    void OcultarCursor();
    void cambiarColor(int color);
};

#endif // JUEGO_H
