#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include <windows.h>
using namespace std;

#include "Tablero.h"

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
};

#endif // JUEGO_H
