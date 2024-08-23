#include <iostream>
#include "claseEmpleado.h"

using namespace std;

int main(){
    char *str=new char[25];
    cin.getline(str, 25);
    Empleado* trabajador=new Empleado();
    trabajador->setNombre(str);
    cin.getline(str, 25);
    trabajador->setApellido(str);
    trabajador->imprimirEmpleado();
    delete []str;
    delete trabajador;
    return 0;
}
