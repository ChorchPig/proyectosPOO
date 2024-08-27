#ifndef CLASEEMPLEADO_H_INCLUDED
#define CLASEEMPLEADO_H_INCLUDED

#include "claseFecha.h"

using namespace std;

class Empleado{
private:
    char *nombre, *apellido;
    Fecha *nacimiento, *contratado;
public:
    Empleado();//crear otro constructor que asigne valores al ser invocado
    virtual ~Empleado();
    void setNombre(char*);
    void setApellido(char*);
    void setNacimiento(int, int, int);
    void setContratado(int, int, int);
    char* getNombre(); //reserva memoria en el heap
    char* getApellido(); //reserva memoria en el heap
    Fecha getNacimiento();
    Fecha getContratado();
    void imprimirEmpleado();
};


#endif // CLASEEMPLEADO_H_INCLUDED
