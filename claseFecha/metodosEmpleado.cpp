#include <iostream>
#include<cstring>
#include "claseEmpleado.h"

Empleado::Empleado(){
    nombre=new char[25];
    cout<<"Introducir un nombre (25 caracteres max): ";
    cin.getline(nombre, 25);
    cout<<endl;
    apellido=new char[25];
    cout<<"Introducir un apellido (25 caracteres max): ";
    cin.getline(apellido, 25);
    cout<<endl;
    nacimiento=new Fecha(6, 4, 2006);
    contratado=new Fecha(5, 12, 2019);
}

Empleado::~Empleado(){
    delete []nombre;
    delete []apellido;
    delete nacimiento;
    delete contratado;
}

void Empleado::setNombre(char* Nombre){ nombre=Nombre; }
void Empleado::setApellido(char* Apellido){ apellido=Apellido; }
void Empleado::setNacimiento(int dd, int mm, int aa){ nacimiento=new Fecha(dd, mm, aa); }
void Empleado::setContratado(int dd, int mm, int aa){ nacimiento=new Fecha(dd, mm, aa); }

Fecha Empleado::getNacimiento(){ return *nacimiento; }
Fecha Empleado::getContratado(){ return *contratado; }
char* Empleado::getNombre(){ return this->nombre; }
char* Empleado::getApellido(){ return this->apellido; }

void Empleado::imprimirEmpleado(){
    cout<<"Nombre: "<<getNombre()<<endl;
    cout<<"Apellido: "<<getApellido()<<endl;
    cout<<"Nacimiento: "; getNacimiento().imprimirFecha();
    cout<<"Contratado: "; getContratado().imprimirFecha();
}
