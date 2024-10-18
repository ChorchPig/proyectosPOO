#include "claseFactura.h"

Factura::Factura(string contribuyente, string ID, string cliente, double monto){
    setContribuyente(contribuyente);
    setCliente(cliente);
    setMonto(monto);
}

Factura::~Factura(){  }

void Factura::setContribuyente(string nombreCont){ contribuyente=nombreCont; }
string Factura::getContribuyente()const{ return contribuyente; }

void Factura::setCliente(string nombreCli){ cliente=nombreCli; }
string Factura::getCliente()const{ return cliente; }

void Factura::setID(string facID){ ID=facID; }
string Factura::getID()const{ return ID; }

void Factura::setMonto(double montoFacturado){ monto=montoFacturado; }
double Factura::getMonto()const{ return monto; }
