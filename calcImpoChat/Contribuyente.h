#ifndef CONTRIBUYENTE_H
#define CONTRIBUYENTE_H

#include <string>
#include <vector>
#include "Factura.h"

using namespace std;

enum class Categoria{
    Limitado,
    Completo,
    Extendido
};

class Contribuyente{
    string nombre;
    Categoria categoria;
    vector<Factura> facturas;
public:
    Contribuyente(string nombre, Categoria categoria);
    void agregarFactura(Factura factura);
    string getNombre() const;
    Categoria getCategoria() const;  // Devolvemos un valor de tipo enum
    const vector<Factura>& getFacturas() const;
};

#endif
