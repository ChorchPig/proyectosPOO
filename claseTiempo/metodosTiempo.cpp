#include <iostream>
#include "claseTiempo.h"

using namespace std;

Tiempo::Tiempo(int hs, int minu,  int seg){
    horas=hs;
    minutos=minu;
    segundos=seg;
}

Tiempo::~Tiempo(){  }

void Tiempo::setHoras(int hs){ horas=hs; }
void Tiempo::setMinutos(int minu){ minutos=minu; }
void Tiempo::setSegundos(int seg){ segundos=seg; }

int Tiempo::getHoras(){ return this->horas; }
int Tiempo::getMinutos(){ return this->minutos; }
int Tiempo::getSegundos(){ return this->segundos; }

void Tiempo::mostrarFmtEstandar(){
    cout<<getHoras()<<":"<<getMinutos()<<":"<<getSegundos()<<"\n";
}
void Tiempo::mostrarFmtUniversal(){
    cout<<getHoras()-3<<":"<<getMinutos()<<":"<<getSegundos()<<" UTC\n";
}
