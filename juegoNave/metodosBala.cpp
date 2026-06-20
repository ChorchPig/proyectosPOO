#include <stdio.h>
#include "prototipos.h"

Bala::Bala(int _x, int _y){
    coordX=_x;
    coordY=_y;
}

Bala::~Bala(){ }

void Bala::mover(){
    goToXY(coordX, coordY);
    printf(" ");
    coordY--;
    goToXY(coordX, coordY);
    printf("'");
}

bool Bala::fuera(){ return (coordY==LIM_SUP+1); }

int Bala::getX()const { return coordX; }
int Bala::getY()const {return coordY; }
