#include <iostream>
#include "claseEmpleado.h"

using namespace std;

int main(){
    char *str=new char[25];
    cout<<"Nombre: ";
    cin.getline(str, 25);
    Empleado* trabajador=new Empleado();
    trabajador->setNombre(str);
    cout<<"\nApellido: ";
    cin.getline(str, 25);
    trabajador->setApellido(str);
    cout<<endl;
    trabajador->setNacimiento(6, 5, 2006);
    trabajador->setContratado(5, 12, 2019);
    trabajador->imprimirEmpleado();
    Fecha *diaActual=new Fecha(1, 1, 2020);
    cout<<trabajador->calcularAntiguedad(*diaActual)<<endl;
    delete []str;
    delete trabajador;
    delete diaActual;
    return 0;
}
