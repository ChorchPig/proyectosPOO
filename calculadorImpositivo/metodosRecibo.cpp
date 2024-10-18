#include "claseRecibo.h"

Recibo::Recibo(string contribuyenye, double total, double fijo, double variable){
    setNombre(contribuyenye);
    setMontoFijo(fijo);
    setMontoTotal(total);
    setMontoVar(variable);
}
Recibo::~Recibo(){  }

void Recibo::setNombre(string nombreContri){ nombreContribuyente=nombreContri; }
string Recibo::getNombre(){ return this->nombreContribuyente; }

void Recibo::setMontoTotal(double total){ montoTotal=total; }
double Recibo::getMontoTotal()const{ return montoTotal; }

void Recibo::setMontoFijo(double fijo){ montoFijo=fijo; }
double Recibo::getMontoFijo()const{ return montoFijo; }

void Recibo::setMontoVar(double variable){ montoVariable=variable; }
double Recibo::getMontoVar()const{ return montoVariable; }

//    void getPrimeraFactura()const;
//    void getUltimaFactura()const;
