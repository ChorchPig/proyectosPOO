#include "Contribuyente.h"

Contribuyente::Contribuyente(string nombre, Categoria categoria)
    : nombre(nombre), categoria(categoria) {}

void Contribuyente::agregarFactura(Factura factura){ facturas.push_back(factura); }
string Contribuyente::getNombre()const{ return nombre; }
Categoria Contribuyente::getCategoria()const{ return categoria; }
const vector<Factura>& Contribuyente::getFacturas()const{ return facturas; }
