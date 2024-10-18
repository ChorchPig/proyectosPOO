#include "claseContribuyente.h"

Contribuyente::Contribuyente(){ }

Contribuyente::~Contribuyente(){
    Factura* aux=NULL;
    while(!facturas.empty()){
        aux=facturas[0];
        eliminarFactura(aux->getID());
        delete aux;
    }
}

void Contribuyente::agregarFactura(Factura *factura){
    facturas.push_back(factura);
}

Factura* Contribuyente::eliminarFactura(string facID){
    Factura* aux=NULL;
    int longitud=facturas.size(), i=0;
    bool flag=false;
    while(!flag&&i<longitud){
        aux=facturas[i];
        flag=(aux->getID()==facID);
        if(!flag)
            i++;
    }
    if(flag)
        facturas.erase(facturas.begin()+i);
    return (flag)? aux : NULL;
}

Factura* Contribuyente::getFactura(string facID){
    Factura* aux=NULL;
    int longitud=facturas.size(), i=0;
    bool flag=false;
    while(!flag&&i<longitud){
        aux=facturas[i];
        flag=(aux->getID()==facID);
        if(!flag)
            i++;
    }
    return (flag)? aux : NULL;
}

double Contribuyente::calcularMontoFijo(){ return facturas.size()*MONTOFIJO; }

//Recibo Contribuyente::calcularImpuestosTotales(){
//
//}
