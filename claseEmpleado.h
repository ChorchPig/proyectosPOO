#ifndef CLASEEMPLEADO_H_INCLUDED
#define CLASEEMPLEADO_H_INCLUDED

#include "claseFecha.h"

using namespace std;

class Empleado{
private:
    string nombre, apellido;
    Fecha *nacimiento, *contratado;
public:
    Empleado();
    ~Empleado();
    void setNombre(string);
    void setApellido(string);
    void setNacimiento(int, int, int);
    void setContratado(int, int, int);
    string getNombre();
    string getApellido();
    Fecha getNacimiento();
    Fecha getContratado();
    void imprimirEmpleado();
};


#endif // CLASEEMPLEADO_H_INCLUDED
