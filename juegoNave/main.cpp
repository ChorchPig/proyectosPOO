#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "prototipos.h"

using namespace std;

//TO DO: hacer que aparezcan más asteroides en función de los puntos, hacer que algunos asteroides tengan trayectorias aleatorias
//TO DO: agregar una tabla con las 10 mejores puntuaciones históricas
//Chat me dice que trate de usar <vector> en lugar de <list>, pero el juego explota si hago el cambio sin cambiar nada en la implementación

int main() {
    int x = 10, y = 15, puntos = 0;
    bool gameOver = false;

    int mejor=leerMejorPuntaje();

    ocultarCursor();
    pintarLimites();
    pintarPuntaje(puntos);
    pintarMejorPuntaje(mejor);

    Nave nave(x, y, VIDASINI);
    nave.pintar();
    nave.mostrarVidas();

    list<Asteroid> asteroides;
    asteroides.emplace_back(x + 7, LIM_SUP + 1, 200);
    asteroides.emplace_back(LIM_DER - 7, LIM_SUP + 3, 200);
    asteroides.emplace_back(x + 15, LIM_SUP + 5, 200);
    asteroides.emplace_back(x + 2, LIM_SUP + 20, 200);
    asteroides.emplace_back(LIM_DER-3, LIM_SUP + 2, 200);

    while (!gameOver) {
        nave.moverBalas();
        for (auto& ast : asteroides)
            ast.mover();

        if (nave.choqueNaveAst(asteroides)) {
            nave.perderVida();
            nave.mostrarVidas();
        }
        if(nave.choqueBalaAst(asteroides)){
            puntos++;
            pintarPuntaje(puntos);
        }

        gameOver=!nave.getVidas();

        if (kbhit()) {
            char tecla = getch();
            if (tecla == 'q' || tecla == 'Q' || tecla == ESC)
                gameOver = true;
            else
                nave.actuar(tecla);
        }

        for(auto& ast : asteroides)
            ast.setIntervaloMs(puntos);

        Sleep(50); // ~20FPS según Chat
    }
    guardarMejorPuntaje(puntos);
    return 0;
}
