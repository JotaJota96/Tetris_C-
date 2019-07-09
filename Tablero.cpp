#include "Tablero.h"
#include<stdlib.h>
#include<time.h>

Tablero::Tablero(const int _alto, const int _ancho){
    this->alto = _alto;
    this->ancho = _ancho;
    this->pieza = NULL;
    this->cxy = new Coordenada();

    tablero = new bool*[alto];
    for (int i = 0; i < alto; i++){
        tablero[i] = new bool[ancho];
        for (int j = 0; j < ancho; j++){
            tablero[i][j] = false;
        }
    }
    srand(time(NULL));
}

Tablero::~Tablero(){
    for (int i = 0; i < alto; i++){
        delete this->tablero[i];
    }
    delete this->tablero;
    delete this->cxy;
}

Coordenada* Tablero::getCoordenada(){
    return this->cxy;
}

Pieza* Tablero::getPieza(){
    return this->pieza;
}

void Tablero::nuevaPieza(){
    if (this->pieza != NULL){
        delete this->pieza;
    }
    if (this->cxy == NULL){
        this->cxy = new Coordenada();
    }

    switch (rand()%7) {
    case 0: this->pieza = new Pieza(L); break;
    case 1: this->pieza = new Pieza(J); break;
    case 2: this->pieza = new Pieza(Z); break;
    case 3: this->pieza = new Pieza(S); break;
    case 4: this->pieza = new Pieza(I); break;
    case 5: this->pieza = new Pieza(O); break;
    case 6: this->pieza = new Pieza(T); break;
    }

    this->cxy->setX(ancho /2 - this->pieza->getDimensiones() /2);
    this->cxy->setY(0);
}

void Tablero::bajarPieza(){
    this->cxy->down();
}



