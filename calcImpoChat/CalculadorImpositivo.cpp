#include "CalculadorImpositivo.h"

CalculadorImpositivo::CalculadorImpositivo(string nombre, Categoria categoria)
    : contribuyente(nombre, categoria) {}

void CalculadorImpositivo::agregarFactura(int numero, string detalle, double monto) {
    Factura factura(numero, detalle, monto);
    contribuyente.agregarFactura(factura);
}

ReciboDePago CalculadorImpositivo::calcularImpuesto(int numeroFacturaInicio, int numeroFacturaFin) {
    ReciboDePago recibo(contribuyente);
    recibo.calcularImpuesto(numeroFacturaInicio, numeroFacturaFin);
    return recibo;
}
