#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream> //¿es realmente necesaria esta inclusión?
#include "prototipos.h"

using namespace std;

void goToXY(int x, int y){
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); //función de <windows.h>
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hCon, dwPos); //función de <windows.h>
}

void ocultarCursor(){
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize=10;
    cci.bVisible=false; //con esto hacemos que el cursor no sea visible
    SetConsoleCursorInfo(hCon, &cci);
}

void imprimirLimites(){
    for(int i=LIM_IZQ; i<LIM_DER; i++){
        goToXY(i, LIM_SUP);
        printf("%c", 205);
        goToXY(i, LIM_INF);
        printf("%c", 205);
    }
    for(int j=LIM_SUP; j<LIM_INF; j++){
        goToXY(LIM_IZQ, j);
        printf("%c", 186);
        goToXY(LIM_DER, j);
        printf("%c", 186);
    }
    goToXY(LIM_IZQ, LIM_SUP);
    printf("%c", 201);
    goToXY(LIM_IZQ, LIM_INF);
    printf("%c", 200);
    goToXY(LIM_DER, LIM_SUP);
    printf("%c", 187);
    goToXY(LIM_DER, LIM_INF);
    printf("%c", 188);
}

void imprimirPuntaje(int puntos){
    goToXY(LIM_IZQ+2, LIM_SUP-1);
    printf("Puntaje:        ");
    goToXY(LIM_IZQ+11, LIM_SUP-1);
    printf("%i", puntos);
}

int leerMejorPuntaje() {
    ifstream file("highscore.bin", ios::binary);
    int mejorPuntaje = 0;
    if (file.is_open()) {
        file.read(reinterpret_cast<char*>(&mejorPuntaje), sizeof(mejorPuntaje));
        file.close();
    }
    return mejorPuntaje;
}

void guardarMejorPuntaje(int nuevoPuntaje) {
    int mejorActual = leerMejorPuntaje();
    if (nuevoPuntaje > mejorActual) {
        ofstream file("highscore.bin", ios::binary | ios::trunc);
        if (file.is_open()) {
            file.write(reinterpret_cast<char*>(&nuevoPuntaje),sizeof(nuevoPuntaje));
            file.close();
        }
    }
}

void imprimirMejorPuntaje(int mejor){
    goToXY((LIM_IZQ+LIM_DER)/2-5, LIM_SUP-1);
    printf("Mejor:        ");
    goToXY((LIM_IZQ+LIM_DER)/2+3, LIM_SUP-1);
    printf("%i", mejor);
}

/*
*/
