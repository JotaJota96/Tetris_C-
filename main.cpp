#include <iostream>
using namespace std;

#include "Tablero.h"

int main(){
    Tablero* t = new Tablero(10,5);
    t->mostrar();
    delete t;

}





