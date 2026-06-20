#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "prototipos.h"

using namespace std;

int main(){
    bool gameOver = false;
    Serpiente snake;
    Manzana manzana((LIM_IZQ + LIM_DER)/2+8, (LIM_SUP + LIM_INF)/2);
    ocultarCursor();
    imprimirLimites();
    manzana.imprimir();
    int puntos=0, mejorPuntaje=leerMejorPuntaje();
    imprimirPuntaje(puntos);
    imprimirMejorPuntaje(mejorPuntaje);
    while(!gameOver){
        bool crecer = snake.vaAComer(manzana);
        snake.mover(crecer);
        if(crecer){
            manzana.reubicar(snake.getCuerpo());
            puntos++;
            imprimirPuntaje(puntos);
        }
        if (kbhit()) {
            char tecla = getch();
            if (tecla == 'q' || tecla == 'Q' || tecla == ESC)
                gameOver = true;
            else{
                snake.cambiarDireccion(tecla);
                gameOver = snake.choque();
            }
        }
        Sleep(70);
    }
    guardarMejorPuntaje(puntos);
    return 0;
}
