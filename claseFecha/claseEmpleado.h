#ifndef CLASEEMPLEADO_H_INCLUDED
#define CLASEEMPLEADO_H_INCLUDED

#include "claseFecha.h"

using namespace std;

class Empleado{
private:
    char *nombre, *apellido;
    Fecha *nacimiento, *contratado;
public:
    Empleado();//modificar para que el constructor tome los valores en los parámetros
    virtual ~Empleado();
    void setNombre(char*); //modificar para que los datos almacenados estén en el heap
    void setApellido(char*); //modificar para que los datos almacenados estén en el heap
    void setNacimiento(int, int, int);
    void setContratado(int, int, int);
    char* getNombre();
    char* getApellido();
    Fecha getNacimiento();
    Fecha getContratado();
    void imprimirEmpleado();
};


#endif // CLASEEMPLEADO_H_INCLUDED
