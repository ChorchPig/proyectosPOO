#include <iostream>
#include "claseFecha.h"

using namespace std;

Fecha::Fecha(int dd, int mm, int aa){
    day=dd;
    month=mm;
    year=aa;
}

Fecha::~Fecha(){}

void Fecha::setDay(int dd){ day=dd; }
void Fecha::setMonth(int mm){ month=mm; }
void Fecha::setYear(int aa){ year=aa; }

int Fecha::getDay(){ return this->day; }
int Fecha::getMonth(){ return this->month; }
int Fecha::getYear(){ return this->year; }

bool Fecha::validarFecha(int dd, int mm, int aa){
    return (this->day==dd&&this->month==mm&&this->year==aa);
}

void Fecha::imprimirFecha(){
    cout<<getDay()<<"/"<<getMonth()<<"/"<<getYear()<<endl;
}
