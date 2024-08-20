#include <iostream>
#include "claseEmpleado.h"

Empleado::Empleado(){
    nombre="Rayo";
    apellido="McQueen";
    nacimiento=new Fecha(6, 4, 2006);
    contratado=new Fecha(5, 12, 2019);
}

Empleado::~Empleado(){
    delete nacimiento;
    delete contratado;
}

void Empleado::setNombre(string Nombre){ nombre=Nombre; }
void Empleado::setApellido(string Apellido){ apellido=Apellido; }
void Empleado::setNacimiento(int dd, int mm, int aa){ nacimiento=new Fecha(dd, mm, aa); }
void Empleado::setContratado(int dd, int mm, int aa){ nacimiento=new Fecha(dd, mm, aa); }

Fecha Empleado::getNacimiento(){ return *nacimiento; }
Fecha Empleado::getContratado(){ return *contratado; }
string Empleado::getNombre(){ return this->nombre; }
string Empleado::getApellido(){ return this->apellido; }

void Empleado::imprimirEmpleado(){
    cout<<"Nombre: "<<getNombre()<<endl;
    cout<<"Apellido: "<<getApellido()<<endl;
    cout<<"Nacimiento: "; getNacimiento().imprimirFecha();
    cout<<"Contratado: "; getContratado().imprimirFecha();
}
