#include "Tablero.h"
#include<stdlib.h>
#include<time.h>

Tablero::Tablero(const int _alto, const int _ancho){
    this->alto = _alto;
    this->ancho = _ancho;
    this->pieza = NULL;
    this->cxy = new Coordenada();
    tipoPiezaAnterior = -1;

    tablero = new int*[alto];
    for (int i = 0; i < alto; i++){
        tablero[i] = new int[ancho];
        for (int j = 0; j < ancho; j++){
            tablero[i][j] = 0;
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

///////////////////////////////////////////////////////////////////////////////////
Coordenada* Tablero::getCoordenada(){
    return this->cxy;
}
int Tablero::getAlto(){
    return alto;
}
int Tablero::getAncho(){
    return ancho;
}
int Tablero::get(int x, int y){
    return tablero[y][x];
}
Pieza* Tablero::getPieza(){
    return this->pieza;
}

///////////////////////////////////////////////////////////////////////////////////
bool Tablero::nuevaPieza(){
    if (this->pieza != NULL){
        delete this->pieza;
    }
    if (this->cxy == NULL){
        this->cxy = new Coordenada();
    }

    int nueva;
    do {
        nueva = rand()%7;
    }while (nueva == tipoPiezaAnterior);

    tipoPiezaAnterior = nueva;

    switch (nueva) {
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

    if ( ! piezaPuedeExistir()){
        delete pieza;
        return false;
    }
    return true;
}

void Tablero::fijarPieza(){
    for (int y = 0; y < pieza->getDimensiones(); y++){
        for (int x = 0; x < pieza->getDimensiones(); x++){
            if (pieza->existeEn(x, y)){
                tablero[cxy->getY() + y][cxy->getX() + x] = pieza->getColor();
            }
        }
    }
    delete pieza;
    pieza = NULL;
}

///////////////////////////////////////////////////////////////////////////////////
bool Tablero::piezaPuedeExistir(){
    for (int y = 0; y < pieza->getDimensiones(); y++){
        for (int x = 0; x < pieza->getDimensiones(); x++){
            if (pieza->existeEn(x, y)){
                if (cxy->getY() + y >= alto ||
                        cxy->getY() + y < 0 ||
                        cxy->getX() + x < 0 ||
                        cxy->getX() + x >= ancho ||
                        tablero[cxy->getY() + y][cxy->getX() + x] != 0){
                    return false;
                }
            }
        }
    }
    return true;
}

void Tablero::piezaMover(Direccion dir){
    // cambia de lugar la pieza
    // si la pieza puede existir en la nueva ubicacion finaliza
    // de lo contrario deshace el movimiento

    switch (dir) {
    case ARRIBA:
        this->cxy->up();
        if ( ! piezaPuedeExistir()){
            this->cxy->down();
        }
        break;
    case ABAJO:
        this->cxy->down();
        if ( ! piezaPuedeExistir()){
            this->cxy->up();
        }
        break;
    case DERECHA:
        this->cxy->right();
        if ( ! piezaPuedeExistir()){
            this->cxy->left();
        }
        break;
    case IZQUIERDA:
        this->cxy->left();
        if ( ! piezaPuedeExistir()){
            this->cxy->right();
        }
        break;
    }
}

///////////////////////////////////////////////////////////////////////////////////
void Tablero::piezaRotar(bool sentidoHorario){
    if (sentidoHorario){
        pieza->rotar();
        if ( ! piezaPuedeExistir()){
            pieza->rotar();
            pieza->rotar();
            pieza->rotar();
        }
    }else{
        pieza->rotar();
        pieza->rotar();
        pieza->rotar();
        if ( ! piezaPuedeExistir()){
            pieza->rotar();
        }
    }
}

int Tablero::eliminarFilasCompletas(){
    bool sePuedeBorrar;
    int lineasEliminadas = 0;

    for (int y = alto-1; y > 0; y--){
        sePuedeBorrar = true;
        for (int x = 0; sePuedeBorrar && x < ancho; x++){
            sePuedeBorrar = tablero[y][x];
        }

        if (sePuedeBorrar){
            lineasEliminadas++;
            for (int i = y; i > 0; i--){
                for (int j = 0; j < ancho; j++){
                    tablero[i][j] = tablero[i-1][j];
                }
            }
            for (int j = 0; j < ancho; j++){
                tablero[0][j] = 0;
            }
            y++;
        }

    }
    return lineasEliminadas;
}






