#ifndef PIEZA_H
#define PIEZA_H
#include <iostream>
#include <windows.h>
using namespace std;

#define CHAR_PIEZA 219
// Notacion al final de este archivo
// El numero asociado al elemento es el color correspondiente a la pieza
enum TipoPieza {L = 2,
                J = 1,
                Z = 5,
                S = 6,
                I = 3,
                O = 4,
                T = 11};



class Pieza{
private:
    bool** pieza;
    int dimensiones;
    TipoPieza tipo;
public:
    Pieza(TipoPieza tp);
    ~Pieza();

    TipoPieza getTipo();
    int getDimensiones();
    int getColor();

    void rotar();
    bool existeEn(int x, int y);

};

#endif // PIEZA_H

/* Nomenclatura de las piezas:
 * Pieza : Nombre
 *
 * []
 * []     L
 * [][]
 *
 *   []
 *   []    J
 * [][]
 *
* [][]    Z
*   [][]
*
*   [][]   S
* [][]
*
* [][]   O
* [][]
*
* [][][][]   I
*
* [][][]    T
*   []
*
*/
