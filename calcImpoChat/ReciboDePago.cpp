#include "ReciboDePago.h"
#include <algorithm>

ReciboDePago::ReciboDePago(Contribuyente contribuyente)
    : contribuyente(contribuyente), montoVariable(0), primeraFactura(-1), ultimaFactura(-1) {}

void ReciboDePago::calcularImpuesto(int numeroFacturaInicio, int numeroFacturaFin) {
    // Solo reiniciar monto variable
    montoVariable = 0;
    // Obtener la categoría del contribuyente
    Categoria categoria = contribuyente.getCategoria();
    // Recorrer las facturas para calcular el monto variable según las reglas
    for (const Factura& factura : contribuyente.getFacturas()) {
        int numFactura=factura.getNumero();
        if (numFactura>=numeroFacturaInicio && numFactura<=numeroFacturaFin){
            if (primeraFactura==-1)
                primeraFactura=numFactura;
            ultimaFactura=numFactura;
            double montoFactura=factura.getMonto();
            switch(categoria){
                case Categoria::Limitado:
                    montoVariable+=montoFactura*0.005;
                    break;
                case Categoria::Completo:
                    if (montoFactura>5000)
                        montoVariable+=montoFactura*0.50;
                    break;
                case Categoria::Extendido:
                    if(montoFactura > 5000)
                        montoVariable+=montoFactura*0.50+10;
                    break;
                default: // En caso de que la categoría sea desconocida
                    break;
            }
        }
    }
}

double ReciboDePago::montoTotal() const { return montoFijo+montoVariable; }
double ReciboDePago::montoFijoTotal() const { return montoFijo; }
double ReciboDePago::montoVariableTotal() const { return montoVariable; }
int ReciboDePago::primeraFacturaConsiderada() const { return primeraFactura;}
int ReciboDePago::ultimaFacturaConsiderada() const { return ultimaFactura; }
