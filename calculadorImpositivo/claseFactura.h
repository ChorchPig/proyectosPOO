#ifndef CLASEFACTURA_H_INCLUDED
#define CLASEFACTURA_H_INCLUDED

#include <iostream>

using namespace std;

class Factura{
private:
    string contribuyente, ID, cliente;
    double monto;
//    Fecha de emisión
public:
    Factura(string contribuyente="\0", string ID="\0", string cliente="\0", double monto=0.0);
    virtual ~Factura();
    void setContribuyente(std::string);
    std::string getContribuyente()const;
    void setCliente(std::string);
    std::string getCliente()const;
    void setID(std::string);
    std::string getID()const;
    void setMonto(double);
    double getMonto()const;
};

#endif // CLASEFACTURA_H_INCLUDED
