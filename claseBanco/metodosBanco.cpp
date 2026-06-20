#include "claseBanco.h"

Banco::Banco(){ }

Banco::~Banco(){
    Cuenta* aux=NULL;
    while(!cuentas.empty()){
        aux=cuentas[0];
        eliminarCuenta(aux->getTitular());
        delete aux;
    }
}

void Banco::crearCuenta(Cuenta* nuevaCuenta){
//    Cuenta* nuevaCuenta=new <tipo de cuenta>(datos de la cuenta);
    cuentas.push_back(nuevaCuenta);
}

Cuenta* Banco::eliminarCuenta(string titular){
    Cuenta* aux=NULL;
    int longitud=cuentas.size(), i=0;
    bool titularEncontrado=false;
    while(!titularEncontrado&&i<longitud){
        aux=cuentas[i];
        titularEncontrado=(aux->getTitular()==titular);
        if(!titularEncontrado)
            i++;
    }
    if(titularEncontrado)
        cuentas.erase(cuentas.begin()+i);
    return (titularEncontrado)? aux : NULL;
}

Cuenta* Banco::getCuenta(string titular){
    Cuenta* resultado=NULL;
    int longitud=cuentas.size(), i=0;
    bool titularEncontrado=false;
    while(!titularEncontrado&&i<longitud){
        resultado=cuentas[i];
        titularEncontrado=(resultado->getTitular()==titular);
        if(!titularEncontrado)
            i++;
    }
    return (titularEncontrado)? resultado : NULL;
}

double Banco::calcularActivo(){
    double total=0.0;
    Cuenta* aux=NULL;
    int longitud=cuentas.size();
    for (int i=0; i<longitud; i++){
        aux=cuentas[i];
        total+=aux->getSaldo();
    }
    return total;
}
