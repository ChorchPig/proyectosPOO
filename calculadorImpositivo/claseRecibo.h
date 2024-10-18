#ifndef CLASERECIBO_H_INCLUDED
#define CLASERECIBO_H_INCLUDED

#include <iostream>

using namespace std;

class Recibo{
private:
    string nombreContribuyente;
    double montoTotal, montoFijo, montoVariable;
public:
    Recibo(string contribuyenye="\0", double total=0.0, double fijo=0.0, double variable=0.0);
    virtual ~Recibo();
    void setNombre(string);
    string getNombre();
    void setMontoTotal(double);
    double getMontoTotal()const;
    void setMontoFijo(double);
    double getMontoFijo()const;
    void setMontoVar(double);
    double getMontoVar()const;

//    void getPrimeraFactura()const;
//    void getUltimaFactura()const;
};

#endif // CLASERECIBO_H_INCLUDED
