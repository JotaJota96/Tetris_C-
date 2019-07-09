#include "Coordenada.h"


Coordenada::Coordenada(){
    this->x = 0;
    this->y = 0;
}
Coordenada::Coordenada(int x, int y){
    this->x = x;
    this->y = y;
}
Coordenada::~Coordenada(){

}

int Coordenada::getX(){
    return this->x;
}
int Coordenada::getY(){
    return this->y;
}
void Coordenada::setX(int x){
    this->x = x;
}
void Coordenada::setY(int y){
    this->y = y;

}

void Coordenada::down(){
    y++;
}
void Coordenada::up(){
    y--;
}
void Coordenada::left(){
    x--;
}
void Coordenada::right(){
    x++;
}
