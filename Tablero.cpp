#include "Tablero.h"

Tablero::Tablero(const int _alto, const int _ancho){
    this->alto = _alto;
    this->ancho = _ancho;

    tablero = new int*[alto];
    for (int i = 0; i < alto; i++){
        tablero[i] = new int[ancho];
        for (int j = 0; j < ancho; j++){
            tablero[i][j] = 0;
        }
    }
}

Tablero::~Tablero(){
    for (int i = 0; i < alto; i++){
        delete tablero[i];
    }
    delete tablero;
}


void Tablero::mostrar(){
    for (int i = 0; i < alto; i++){
        for (int j = 0; j < ancho; j++){
            cout << tablero[i][j] << "\t";
        }
        cout  << endl;
    }
}




