#ifndef CLASECONTRIBUYENTE_H_INCLUDED
#define CLASECONTRIBUYENTE_H_INCLUDED

#include "claseRecibo.h"
#include "claseFactura.h"
#include <vector>
#define MONTOFIJO 5

class Contribuyente{
private:
    string nombre;
    vector <Factura*>facturas;
public:
    Contribuyente();
    virtual ~Contribuyente();
    void agregarFactura(Factura*);
    Factura* eliminarFactura(string facID);
    Factura* getFactura(string facturaID);
    double calcularMontoFijo();
    virtual double calcularMontoVar()=0;
    Recibo calcularImpuestosTotales();
};

class Limitado: public Contribuyente{
public:
    Limitado();
    virtual ~Limitado();
    virtual double calcularMontoVar();
};

class Completo: public Contribuyente{
public:
    Completo();
    virtual ~Completo();
    virtual double calcularMontoVar();
};

class Extendido: public Completo{
public:
    Extendido();
    virtual ~Extendido();
    virtual double calcularMontoVar();
};

#endif // CLASECONTRIBUYENTE_H_INCLUDED
