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
    char* valorGetter=trabajador->getNombre();
    cout<<valorGetter<<endl;
    delete []str;
    delete []valorGetter;
    delete trabajador;
    return 0;
}
