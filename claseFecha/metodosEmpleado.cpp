#include <iostream>
#include <cstring>
#include "claseEmpleado.h"

Empleado::Empleado(){
    this->nombre=new char[25];
    this->apellido=new char[25];
}

Empleado::~Empleado(){
    delete []nombre;
    delete []apellido;
}

void Empleado::setNombre(char* Nombre){ strcpy(nombre, Nombre); }
void Empleado::setApellido(char* Apellido){ strcpy(apellido, Apellido); }
void Empleado::setNacimiento(int dd, int mm, int aa){ this->nacimiento.setDatos(dd, mm, aa); }
void Empleado::setContratado(int dd, int mm, int aa){ this->contratado.setDatos(dd, mm, aa); }

Fecha Empleado::getNacimiento(){ return nacimiento; }
Fecha Empleado::getContratado(){ return contratado; }
char* Empleado::getNombre(){
    char* str=new char[25];
    strcpy(str, nombre);
    return str;
}
char* Empleado::getApellido(){
    char* str=new char[25];
    strcpy(str, apellido);
    return str;
}

void Empleado::imprimirEmpleado(){
    char* str1=getNombre(), *str2=getApellido();
    cout<<"Nombre: "<<str1<<endl;
    cout<<"Apellido: "<<str2<<endl;
    cout<<"Nacimiento: "; getNacimiento().imprimirFecha();
    cout<<"Contratado: "; getContratado().imprimirFecha();
    delete []str1;
    delete []str2;
}

unsigned int Empleado::calcularAntiguedad(const Fecha& fechaActual){
    unsigned int daysDif=0;
    int dd=fechaActual.getDay(), mm=fechaActual.getMonth(), aa=fechaActual.getYear();
    Fecha aux=contratado;
    while(!aux.validarFecha(dd, mm, aa)){
        daysDif++;
        aux.agregarUnDia();
    }
    return daysDif;
}
