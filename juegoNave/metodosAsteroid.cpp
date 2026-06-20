#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

using namespace std;

Asteroid::Asteroid(int _x, int _y, int intervalo){
    coordX=_x;
    coordY=_y;
    intervaloMs=intervalo;
    ultimoMovimiento=chrono::steady_clock::now();
}

Asteroid::~Asteroid(){}

void Asteroid::pintar(){
    goToXY(coordX, coordY);
    printf("%c", 184);
}

void Asteroid::mover(){
    auto ahora = chrono::steady_clock::now();
    auto delta = chrono::duration_cast<chrono::milliseconds>(ahora - ultimoMovimiento).count();
    if (delta >= intervaloMs){
        goToXY(coordX, coordY);
        printf(" ");
        coordY++;
        if(coordY>LIM_INF-1)
            reiniciarPosicion();
        goToXY(coordX, coordY);
        printf("%c", 184);
        ultimoMovimiento = ahora;
    }
}

void Asteroid::reiniciarPosicion(){
    coordX=rand()%(LIM_DER-LIM_IZQ-1)+LIM_IZQ+1; //rand() es función de <stflib.h>
    coordY=LIM_SUP+1;
    ultimoMovimiento=chrono::steady_clock::now();
}

int Asteroid::getX()const { return coordX; }
int Asteroid::getY()const {return coordY; }

void Asteroid::setIntervaloMs(int puntos){
    intervaloMs= 200-puntos*2;
    if(intervaloMs<50)
        intervaloMs=50;
}

/* Propuestas de Chat para aumentar la dificultad con los puntos
if(puntos % 50 == 0)
    asteroides.emplace_back(randomX, LIM_SUP);

Asteroid::Asteroid(int x, int y)
{
    coordX = x;
    coordY = y;

    dirX = rand()%3 - 1;  // -1, 0, 1
}

void Asteroid::mover()
{
    goToXY(coordX, coordY);
    cout << " ";

    coordY++;

    coordX += dirX;

    if(coordX <= LIM_IZQ || coordX >= LIM_DER)
        dirX *= -1;

    goToXY(coordX, coordY);
    cout << "*";
}

class Asteroid{
    int coordX, coordY;
    int size;

public:
    Asteroid(int x, int y, int s = 3);

    int getSize() const;
};

Asteroid::Asteroid(int x, int y, int s)
{
    coordX = x;
    coordY = y;
    size = s;
}

void Asteroid::pintar()
{
    goToXY(coordX, coordY);

    if(size == 3) cout << "O";
    else if(size == 2) cout << "o";
    else cout << ".";
}

if(itBala->getX() == itAst->getX() &&
   itBala->getY() == itAst->getY())
{
    int s = itAst->getSize();

    if(s > 1)
    {
        asteroides.emplace_back(itAst->getX(), itAst->getY(), s-1);
        asteroides.emplace_back(itAst->getX(), itAst->getY(), s-1);
    }

    itAst = asteroides.erase(itAst);
}

*/
