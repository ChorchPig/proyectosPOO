#ifndef CLASEBANCO_H_INCLUDED
#define CLASEBANCO_H_INCLUDED

#include "claseCuenta.h"
#include <vector>

class Banco{
private:
    vector <Cuenta*>cuentas;
public:
    Banco();
    virtual ~Banco();
    void crearCuenta(Cuenta* nuevaCuenta);
    Cuenta* eliminarCuenta(string titular);
    Cuenta* getCuenta(string titular);
    double calcularActivo();
};

#endif // CLASEBANCO_H_INCLUDED
