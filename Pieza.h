#ifndef PIEZA_H
#define PIEZA_H
#include <iostream>
using namespace std;

#define C 219
// Notacion al final de este archivo
enum TipoPieza {L, J, Z, S, I, O, T};

class Pieza{
private:
    int** pieza;
    int dimensiones;
public:
    Pieza(TipoPieza tp);
    ~Pieza();

    void mostrar();


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
