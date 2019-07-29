#include "Tablero.h"
#include<stdlib.h>
#include<time.h>

Tablero::Tablero(const int _alto, const int _ancho){
    // inicializa las dimensiones del tablero y la coordenada para la pieza actual
    this->alto = _alto;
    this->ancho = _ancho;
    this->cxy = new Coordenada();
    // inicializa el arreglo de planificacion de piezas
    for (int i = 0; i < 3; i++){
        colaDePiezas[i] =NULL;
    }

    // genera el tablero con las dimensiones necesarias
    tablero = new int*[alto]; // array de filas
    for (int i = 0; i < alto; i++){ // para cada fila
        tablero[i] = new int[ancho]; // crea el array de columnas
        for (int j = 0; j < ancho; j++){  // nicializa todo el arreglo en 0
            tablero[i][j] = 0;
        }
    }
    srand(time(NULL)); // inicializa la generacion de numeros aleatorios

    TipoPieza tipoNuevaPieza; // tipo de la nueva pieza
    bool seguirBuscandoNuevaPieza = true;
    for (int i = 0; i < 3; i++){
        do {
            seguirBuscandoNuevaPieza = false;
            switch (rand()%7) {
            case 0: tipoNuevaPieza = L; break;
            case 1: tipoNuevaPieza = J; break;
            case 2: tipoNuevaPieza = Z; break;
            case 3: tipoNuevaPieza = S; break;
            case 4: tipoNuevaPieza = I; break;
            case 5: tipoNuevaPieza = O; break;
            case 6: tipoNuevaPieza = T; break;
            }

            for (int i = 0; i < 3; i++){
                if (this->colaDePiezas[i] != NULL && tipoNuevaPieza == this->colaDePiezas[i]->getTipo()){
                    seguirBuscandoNuevaPieza = true;
                    break;
                }
            }
        } while (seguirBuscandoNuevaPieza);

        colaDePiezas[i] = new Pieza(tipoNuevaPieza);
    }
}

Tablero::~Tablero(){
    // elimina el tablero
    for (int i = 0; i < alto; i++){
        delete this->tablero[i];
    }
    delete this->tablero;
    // elimina la coordenada
    delete this->cxy;
    // elimina el arreglo de planificacion de piezas
    for (int i = 0; i < 3; i++){
        if (colaDePiezas[i] != NULL){
            delete this->colaDePiezas[i];
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////
int Tablero::getAlto(){
    return alto;
}
int Tablero::getAncho(){
    return ancho;
}
int Tablero::get(int x, int y){
    return tablero[y][x];
}
Coordenada* Tablero::getCoordenada(){
    return this->cxy;
}
Pieza* Tablero::getPieza(){
    return this->colaDePiezas[0];
}
Pieza** Tablero::getColaDePiezas(int &tam){
    tam = 3;
    return &colaDePiezas[0];
}

///////////////////////////////////////////////////////////////////////////////////
bool Tablero::nuevaPieza(){
    // si no hay instancia de Coordenada, genera una
    if (this->cxy == NULL){
        this->cxy = new Coordenada();
    }

    // el tipo de la nueva pieza debe ser diferente a las que se encuentran actualmente en la cola de  proximas piezas
    TipoPieza tipoNuevaPieza; // tipo de la nueva pieza
    bool seguirBuscandoNuevaPieza = true;
    do {
        seguirBuscandoNuevaPieza = false;
        switch (rand()%7) {
        case 0: tipoNuevaPieza = L; break;
        case 1: tipoNuevaPieza = J; break;
        case 2: tipoNuevaPieza = Z; break;
        case 3: tipoNuevaPieza = S; break;
        case 4: tipoNuevaPieza = I; break;
        case 5: tipoNuevaPieza = O; break;
        case 6: tipoNuevaPieza = T; break;
        }

        for (int i = 0; i < 3; i++){
            if (tipoNuevaPieza == this->colaDePiezas[i]->getTipo()){
                seguirBuscandoNuevaPieza = true;
                break;
            }
        }
    } while (seguirBuscandoNuevaPieza);

    delete colaDePiezas[0];
    for (int i = 1; i < 3; i++){
        colaDePiezas[i-1] = colaDePiezas[i];
    }
    colaDePiezas[2] = new Pieza(tipoNuevaPieza);

    this->cxy->setX(ancho /2 - this->colaDePiezas[0]->getDimensiones() /2);
    this->cxy->setY(0);

    if ( ! piezaPuedeExistir()){
        return false;
    }
    return true;
}

void Tablero::fijarPieza(){
    for (int y = 0; y < this->colaDePiezas[0]->getDimensiones(); y++){
        for (int x = 0; x < this->colaDePiezas[0]->getDimensiones(); x++){
            if (this->colaDePiezas[0]->existeEn(x, y)){
                tablero[cxy->getY() + y][cxy->getX() + x] = this->colaDePiezas[0]->getColor();
            }
        }
    }
    delete this->colaDePiezas[0];
}

///////////////////////////////////////////////////////////////////////////////////
bool Tablero::piezaPuedeExistir(){
    for (int y = 0; y < this->colaDePiezas[0]->getDimensiones(); y++){
        for (int x = 0; x < this->colaDePiezas[0]->getDimensiones(); x++){
            if (this->colaDePiezas[0]->existeEn(x, y)){
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

void Tablero::piezaRotar(bool sentidoHorario){
    if (sentidoHorario){
        this->colaDePiezas[0]->rotar();
        if ( ! piezaPuedeExistir()){
            this->colaDePiezas[0]->rotar();
            this->colaDePiezas[0]->rotar();
            this->colaDePiezas[0]->rotar();
        }
    }else{
        this->colaDePiezas[0]->rotar();
        this->colaDePiezas[0]->rotar();
        this->colaDePiezas[0]->rotar();
        if ( ! piezaPuedeExistir()){
            this->colaDePiezas[0]->rotar();
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////
void Tablero::alternarPieza(){
    Pieza* aux;
    do{
        aux = this->colaDePiezas[0];
        for (int i = 1; i < 3; i++){
            this->colaDePiezas[i-1] = this->colaDePiezas[i];
        }
        this->colaDePiezas[2] = aux;
    } while ( ! piezaPuedeExistir());
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






