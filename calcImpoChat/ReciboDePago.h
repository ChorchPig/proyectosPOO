#ifndef RECIBODEPAGO_H
#define RECIBODEPAGO_H

#include "Contribuyente.h"

class ReciboDePago {
    Contribuyente contribuyente;
    double montoFijo=5.0;
    double montoVariable;
    int primeraFactura;
    int ultimaFactura;
public:
    ReciboDePago(Contribuyente contribuyente);
    void calcularImpuesto(int numeroFacturaInicio, int numeroFacturaFin);
    double montoTotal() const;
    double montoFijoTotal() const;
    double montoVariableTotal() const;
    int primeraFacturaConsiderada() const;
    int ultimaFacturaConsiderada() const;
};

#endif
