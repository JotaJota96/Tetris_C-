#include "Juego.h"

Juego::Juego(){
    this->tablero = new Tablero(10,7);
    this->posTablero = new Coordenada(1,1);
}

void Juego::pruebas(){
    OcultarCursor();
    tablero->nuevaPieza();

    for (int i = 0; i < 100; i++){
        dibujarPieza();
        Sleep(500);
        borrarPieza();
        if (i % 5 == 0)
            tablero->getPieza()->rotar();
        tablero->bajarPieza();
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
                GoToXY((pCord->getX()+x)*2, pCord->getY()+y);
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
                GoToXY((pCord->getX()+x)*2, pCord->getY()+y);
                printf("%c%c", 32, 32);
            }
        }
    }
}


//---------------------------------------------------------------------------------
void Juego::GoToXY(int x, int y){		// Coloca el cursor en la ordenada indicada
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}
void Juego::OcultarCursor(){			// Oculta el cursor
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hCon, &cci);
}

