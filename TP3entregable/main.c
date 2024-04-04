#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(){

    return 0;
}

void contarNumerosNegativos(matrix* Matrix, Vector *vector, int fila){
    int filas=getMatrixRows(Matrix);
    if(filas==fila)return;
    int totalEnFila=0, columnas=getMatrixColumns(Matrix);
    for(int i=0; i<columnas; i++){
        if(getValueIn(Matrix, fila, i)<0)totalEnFila++;
    }
    agregarAlVector(vector, totalEnFila);
    contarNumerosNegativos(Matrix, vector, fila+1);
}

void contarCeros(matrix* Matrix, Vector *vector, int columna){
    int columnas=getMatrixColumns(Matrix);
    if(columna==columnas)return;
    int totalEnColumna=0, filas=getMatrixRows(Matrix);
    for(int i=0; i<filas; i++){
        if(getValueIn(Matrix, i, columna)==0)totalEnColumna++;
    }
    agregarAlVector(vector, totalEnColumna);
    contarCeros(Matrix, vector, columna+1);
}
