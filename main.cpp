#include <iostream>
using namespace std;

#include "Tablero.h"
#include "Pieza.h"

int main(){
    Pieza* p[7];
     p[0] = new Pieza(L);
     p[1] = new Pieza(J);
     p[2] = new Pieza(Z);
     p[3] = new Pieza(S);
     p[4] = new Pieza(I);
     p[5] = new Pieza(O);
     p[6] = new Pieza(T);

     for (int i = 0; i < 7; i++){
         p[i]->mostrar();
         cout << "----------------"<< endl;
     }
}





