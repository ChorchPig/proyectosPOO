#ifndef FACTURA_H
#define FACTURA_H

#include <string>

using namespace std;

class Factura {
    int numero;
    string detalle;
    double monto;
public:
    Factura(int numero, string detalle, double monto);
    int getNumero() const;
    string getDetalle() const;
    double getMonto() const;
};

#endif
