#include "Factura.h"

Factura::Factura(int numero, string detalle, double monto)
    : numero(numero), detalle(detalle), monto(monto) {}

int Factura::getNumero() const { return numero; }
string Factura::getDetalle() const { return detalle; }
double Factura::getMonto() const { return monto; }
