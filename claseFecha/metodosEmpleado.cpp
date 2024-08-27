#include <iostream>
#include<cstring>
#include "claseEmpleado.h"

Empleado::Empleado(){
    nombre=new char[25];
    apellido=new char[25];
    nacimiento=NULL;
    contratado=NULL;
}

Empleado::~Empleado(){
    delete []nombre;
    delete []apellido;
    delete nacimiento;
    delete contratado;
}

void Empleado::setNombre(char* Nombre){ strcpy(nombre, Nombre); }
void Empleado::setApellido(char* Apellido){ strcpy(apellido, Apellido); }
void Empleado::setNacimiento(int dd, int mm, int aa){
    if(!nacimiento)nacimiento=new Fecha(dd, mm, aa);
    else{
        nacimiento->setDay(dd);
        nacimiento->setMonth(mm);
        nacimiento->setYear(aa);
    }
}
void Empleado::setContratado(int dd, int mm, int aa){
    if(!contratado)contratado=new Fecha(dd, mm, aa);
    else{
        contratado->setDay(dd);
        contratado->setMonth(mm);
        contratado->setYear(aa);
    }
}

Fecha Empleado::getNacimiento(){ return *nacimiento; }
Fecha Empleado::getContratado(){ return *contratado; }
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
