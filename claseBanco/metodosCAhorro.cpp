#include "claseCuenta.hpp"

using namespace std;

cAhorro::cAhorro(string nombre, double monto){
    setTitular(nombre);
    setSaldo(monto);
    setExtracciones(0);
}

cAhorro::~cAhorro(){  }

void cAhorro::extraer(double monto){
    if(getSaldo()-monto<0&&getExtracciones()<MAXEXTRAC){
        setSaldo(getSaldo()-monto);
        setExtracciones(getExtracciones()+1);
    }
    else
        cout<<"No es posible realizar la extracción\n";
}

void cAhorro::setExtracciones(int extrac){ extracciones=extrac; }
int cAhorro::getExtracciones()const{ return extracciones; }
