#ifndef CALCULADORIMPOSITIVO_H
#define CALCULADORIMPOSITIVO_H

#include "Contribuyente.h"
#include "ReciboDePago.h"

using namespace std;

class CalculadorImpositivo {
    Contribuyente contribuyente;
public:
    CalculadorImpositivo(string nombre, Categoria categoria);
    void agregarFactura(int numero, string detalle, double monto);
    ReciboDePago calcularImpuesto(int numeroFacturaInicio, int numeroFacturaFin);
};

#endif
