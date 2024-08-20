#include <iostream>
#include "claseEmpleado.h"

using namespace std;

int main(){
    Fecha* fecha=new Fecha(2, 3, 2002);
    fecha->imprimirFecha();
    cout<<fecha->validarFecha(02, 03, 2001)<<endl<<fecha->validarFecha(02, 03, 2002)<<endl;
    delete fecha;
    Empleado* trabajador=new Empleado();
    trabajador->imprimirEmpleado();
    delete trabajador;
    return 0;
}
