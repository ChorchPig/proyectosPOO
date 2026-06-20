#include "claseEmpleado.h"

ostream& operator<<(ostream& Cout, const Empleado& valor){
    cout<<valor.getNombre()<<" "<<valor.getApellido();
    cout<<"\nDNI: "<<valor.getDNI()<<"\nSueldo: "<<valor.getSueldo();
    cout<<"\nAntigüedad: "<<valor.getAntiguedad()<<" años"<<endl;
    return Cout;
}

Empleado::Empleado(string Nombre, string Apellido, unsigned Dni, unsigned Antiguedad, double Sueldo){
    nombre=Nombre;
    apellido=Apellido;
    dni=Dni;
    antiguedad=Antiguedad;
    sueldo=Sueldo;
}

Empleado::~Empleado(){  }

string Empleado::getNombre()const{ return nombre; }
string Empleado::getApellido()const{ return apellido; }
unsigned int Empleado::getDNI()const{ return dni; }
unsigned int Empleado::getAntiguedad()const{ return antiguedad; }
double Empleado::getSueldo()const{ return sueldo; }

bool Empleado::operator<(const Empleado &referencia)const{
    return (dni<referencia.getDNI())? true : false;
}
