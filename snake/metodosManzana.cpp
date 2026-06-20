#include <iostream>
#include <algorithm>
#include "prototipos.h"

using namespace std;

Manzana::Manzana(int _xInicial, int _yInicial){
    coordX=_xInicial;
    coordY=_yInicial;
}

void Manzana::reubicar(const vector<Segmento>& cuerpo) {
    do {
        coordX = rand() % (LIM_DER - LIM_IZQ - 1) + LIM_IZQ + 1;
        coordY = rand() % (LIM_INF - LIM_SUP - 1) + LIM_SUP + 1;
    } while (find(cuerpo.begin(), cuerpo.end(),
                       Segmento{coordX, coordY}) != cuerpo.end());
    imprimir();
}

int Manzana::getCoordX() const{ return coordX; }
int Manzana::getCoordY() const{ return coordY; }

void Manzana::imprimir(){
    goToXY(coordX, coordY);
    cout<<"O";
}
