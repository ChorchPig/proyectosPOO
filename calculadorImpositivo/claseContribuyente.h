#ifndef CLASECONTRIBUYENTE_H_INCLUDED
#define CLASECONTRIBUYENTE_H_INCLUDED

#include "claseFactura.h"
#include <vector>

enum{
    LIMITADO=1, COMPLETO=2, EXTENDIDO=3
};

class Contribuyente{
    double impuestoFijo=5.0;
protected:
    std::string nombre;
    std::vector <Factura*> facturas;
public:
    Contribuyente(std::string nombre="\0");
    virtual ~Contribuyente();
    double calcularMontoFijo(int numFac1, int numFac2);
    virtual double calcularMontoVariable(int numFac1, int numFac2)=0;
    void agregarFactura(Factura*);
    Factura* eliminarFactura(int numFactura);
//    Factura* getFactura(int numFactura)const;
    std::string getNombre()const;
};

class Limitado: public Contribuyente{
public:
    Limitado(std::string nombre="\0");
    virtual ~Limitado();
    virtual double calcularMontoVariable(int numFac1, int numFac2);
};

class Completo: public Contribuyente{
public:
    Completo(std::string nombre="\0");
    virtual ~Completo();
    virtual double calcularMontoVariable(int numFac1, int numFac2);
};

class Extendido: public Completo{
private:
    double impuestoExtendido=10.0;
public:
    Extendido(std::string nombre="\0");
    virtual ~Extendido();
    virtual double calcularMontoVariable(int numFac1, int numFac2);
};

#endif // CLASECONTRIBUYENTE_H_INCLUDED
