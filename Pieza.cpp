#include "Pieza.h"


Pieza::Pieza(TipoPieza tp){
    this->tipo = tp;
    switch (tp){
    case L:
        dimensiones = 3;
        pieza = new bool*[dimensiones];
        pieza[0] = new bool[dimensiones]{0,1,0};
        pieza[1] = new bool[dimensiones]{0,1,0};
        pieza[2] = new bool[dimensiones]{0,1,1};
        break;
    case J:
        dimensiones = 3;
        pieza = new bool*[dimensiones];
        pieza[0] = new bool[dimensiones]{0,1,0};
        pieza[1] = new bool[dimensiones]{0,1,0};
        pieza[2] = new bool[dimensiones]{1,1,0};
        break;
    case Z:
        dimensiones = 3;
        pieza = new bool*[dimensiones];
        pieza[0] = new bool[dimensiones]{1,1,0};
        pieza[1] = new bool[dimensiones]{0,1,1};
        pieza[2] = new bool[dimensiones]{0,0,0};
        break;
    case S:
        dimensiones = 3;
        pieza = new bool*[dimensiones];
        pieza[0] = new bool[dimensiones]{0,1,1};
        pieza[1] = new bool[dimensiones]{1,1,0};
        pieza[2] = new bool[dimensiones]{0,0,0};
        break;
    case I:
        dimensiones = 4;
        pieza = new bool*[dimensiones];
        pieza[0] = new bool[dimensiones]{0,0,0,0};
        pieza[1] = new bool[dimensiones]{1,1,1,1};
        pieza[2] = new bool[dimensiones]{0,0,0,0};
        pieza[3] = new bool[dimensiones]{0,0,0,0};
        break;
    case O:
        dimensiones = 2;
        pieza = new bool*[dimensiones];
        pieza[0] = new bool[dimensiones]{1,1};
        pieza[1] = new bool[dimensiones]{1,1};
        break;
    case T:
        dimensiones = 3;
        pieza = new bool*[dimensiones];
        pieza[0] = new bool[dimensiones]{0,0,0};
        pieza[1] = new bool[dimensiones]{1,1,1};
        pieza[2] = new bool[dimensiones]{0,1,0};
        break;
    }
}

Pieza::~Pieza(){
    for (int i = 0; i < dimensiones; i++){
        delete pieza[i];
    }
    delete pieza;
}

TipoPieza Pieza::getTipo(){
    return this->tipo;
}
int Pieza::getDimensiones(){
    return this->dimensiones;
}
int Pieza::getColor(){
    return this->tipo;
}

void Pieza::rotar(){
    int aux[dimensiones][dimensiones];

    for (int i = 0; i < dimensiones; i++){
        for (int j = 0; j < dimensiones; j++){
            aux[i][j] = pieza[i][j];
        }
    }

    for (int i = 0; i < dimensiones; i++){
        for (int j = 0; j < dimensiones; j++){
            pieza[j][dimensiones-1-i] = aux[i][j];
        }
    }
}

bool Pieza::existeEn(int x, int y){
    return this->pieza[y][x];
}


