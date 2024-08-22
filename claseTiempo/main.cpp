#include <iostream>
#include "claseTiempo.h"

using namespace std;

int main(){
    Tiempo *tiempo=new Tiempo(8, 52, 00);
    tiempo->mostrarFmtEstandar();
    tiempo->mostrarFmtUniversal();
    delete tiempo;
    return 0;
}
