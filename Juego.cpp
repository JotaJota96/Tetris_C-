#include "Juego.h"

Juego::Juego(){
    this->tablero = new Tablero(ALTO, ANCHO);
    this->posTablero = new Coordenada(BORDE_IZQUIERDO+2,BORDE_SUPERIOR+1);

    OcultarCursor();

    GoToXY(BORDE_IZQUIERDO, BORDE_SUPERIOR); printf(" %c", 220);
    GoToXY(BORDE_DERECHO,   BORDE_SUPERIOR); printf("%c ", 220);
    GoToXY(BORDE_IZQUIERDO, BORDE_INFERIOR); printf(" %c", 223);
    GoToXY(BORDE_DERECHO,   BORDE_INFERIOR); printf("%c ", 223);

    for (int i = BORDE_IZQUIERDO+2; i < BORDE_DERECHO; i+=2){
        GoToXY(i, BORDE_SUPERIOR); printf("%c%c", 219, 219);
        GoToXY(i, BORDE_INFERIOR); printf("%c%c", 219, 219);
    }
    for (int i = BORDE_SUPERIOR+1; i < BORDE_INFERIOR; i++){
        GoToXY(BORDE_IZQUIERDO, i); printf("%c%c", 219, 219);
        GoToXY(BORDE_DERECHO,   i); printf("%c%c", 219, 219);
    }
    GoToXY(BORDE_IZQUIERDO, BORDE_INFERIOR+1);
}

void Juego::pruebas(){
    tablero->nuevaPieza();

    for (int i = 0; i < 30; i++){
        dibujarPieza();
        Sleep(500);
        if (tablero->piezaPuedeBajar()){
            borrarPieza();
            tablero->bajarPieza();
        }else{
            tablero->fijarPieza();
            tablero->eliminarUltimaFila();
            mostrarTablero();
            tablero->nuevaPieza();
        }
    }

}

void Juego::dibujarPieza(){
    Coordenada* pCord = this->tablero->getCoordenada();
    Pieza* p = this->tablero->getPieza();
    int dimPieza = p->getDimensiones();

    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, p->getTipo());

    for (int y = 0; y < dimPieza; y++){
        for (int x = 0; x < dimPieza; x++){
            if (p->existeEn(x, y)){
                GoToXY(BORDE_IZQUIERDO+2 + (pCord->getX()+x)*2, BORDE_SUPERIOR+1 + pCord->getY()+y);
                printf("%c%c", CHAR_PIEZA, CHAR_PIEZA);
            }
        }
    }


    SetConsoleTextAttribute(hConsole, 15);
}

void Juego::borrarPieza(){
    Coordenada* pCord = this->tablero->getCoordenada();
    Pieza* p = this->tablero->getPieza();
    int dimPieza = p->getDimensiones();

    for (int y = 0; y < dimPieza; y++){
        for (int x = 0; x < dimPieza; x++){
            if (p->existeEn(x, y)){
                GoToXY(BORDE_IZQUIERDO+2 + (pCord->getX()+x)*2, BORDE_SUPERIOR+1 + pCord->getY()+y);
                printf("%c%c", 32, 32);
            }
        }
    }
}

void Juego::mostrarTablero(){
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int y = tablero->getAlto()-1; y >= 0; y--){
    //for (int y = 0; y < tablero->getAlto(); y++){
        for (int x = 0; x < tablero->getAncho(); x++){
            GoToXY(posTablero->getX()+(x*2), posTablero->getY()+y);
            if (tablero->get(x,y) != 0){
                SetConsoleTextAttribute(hConsole, static_cast<WORD>(tablero->get(x,y)));
                printf("%c%c", 219, 219);
                //Sleep(20);
            }else{
                printf("%c%c", 32, 32);
            }
        }
    }
    SetConsoleTextAttribute(hConsole, 15);
}



//---------------------------------------------------------------------------------
void Juego::GoToXY(int x, int y){		// Coloca el cursor en la ordenada indicada
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = static_cast<short>(x);
    dwPos.Y = static_cast<short>(y);;
    SetConsoleCursorPosition(hCon, dwPos);
}
void Juego::OcultarCursor(){			// Oculta el cursor
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hCon, &cci);
}

