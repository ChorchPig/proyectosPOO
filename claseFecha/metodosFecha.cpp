#include <iostream>
#include "claseFecha.h"

using namespace std;

Fecha::Fecha(){
    day=0;
    month=0;
    year=0;
}

Fecha::Fecha(int dd, int mm, int aa){
    day=dd;
    month=mm;
    year=aa;
}

Fecha::~Fecha(){}

void Fecha::setDay(int dd){ day=dd; }
void Fecha::setMonth(int mm){ month=mm; }
void Fecha::setYear(int aa){ year=aa; }

void Fecha::setDatos(int dd, int mm, int aa){
    setDay(dd);
    setMonth(mm);
    setYear(aa);
}

int Fecha::getDay()const { return day; }
int Fecha::getMonth() const { return month; }
int Fecha::getYear()const { return year; }

bool Fecha::validarFecha(int dd, int mm, int aa){
    return (getDay()==dd&&getMonth()==mm&&getYear()==aa);
}

void Fecha::imprimirFecha(){
    cout<<getDay()<<"/"<<getMonth()<<"/"<<getYear()<<endl;
}

int Fecha::getMaxDays(int month)const{ //no considera la existencia de años bisiestos
    int maxDays;
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        maxDays=31;
    else if(month==4||month==6||month==9||month==11)
        maxDays=30;
    else maxDays=28;
    return maxDays;
}

void Fecha::agregarUnDia(){
    int maxDays=getMaxDays(getMonth());
    if(getDay()==maxDays){
        setDay(1);
        int mes=getMonth()+1;
        setMonth(mes);
        if(mes>12){
            setMonth(1);
            setYear(getYear()+1);
        }
    }
    else setDay(getDay()+1);
}
