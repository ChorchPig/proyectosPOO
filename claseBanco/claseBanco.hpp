#ifndef CLASEBANCO_H_INCLUDED
#define CLASEBANCO_H_INCLUDED

#include "claseCuenta.hpp"
#include <vector>

class Banco{
private:
    std::vector <Cuenta*>cuentas;
public:
    Banco();
    ~Banco();
    void crearCuenta();
    Cuenta* eliminarCuenta();
    //Cuenta* getCuenta(string titular);
    double calcularActivo();
};

#endif // CLASEBANCO_H_INCLUDED
