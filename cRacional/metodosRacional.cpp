#include <iostream>
#include "claseRacional.h"

using namespace std;

void CRacional::setNumerador(int num){
    numerador=num;
}

void CRacional::setDenominador(int den){
    if(den==0){
        denominador=1;
        std::cout<<"El denominador no puede ser cero, para evitar errores denominador=1.\n";
    }
    else denominador=den;
}

int CRacional::getNumerador(){ return numerador; }
int CRacional::getDenominador(){ return denominador; }

CRacional::CRacional(){
    setNumerador(0);
    setDenominador(1);
}

CRacional::CRacional(int num, int den){
    setNumerador(num);
    setDenominador(den);
}

CRacional::CRacional(int &referencia){
    setNumerador(referencia);
    setDenominador(1);
}

CRacional::~CRacional(){  }

istream& operator>>(istream& cin, CRacional &referencia){
    int numero;
    cout<<"Ingrese numerador: ";
    cin>>numero;
    referencia.setNumerador(numero);
    cout<<"\nIngrese denominador: ";
    cin>>numero;
    referencia.setDenominador(numero);
    return cin;
}

ostream& operator<<(ostream& Cout, CRacional &referencia){
    cout<<referencia.getDenominador()<<"/"<<referencia.getDenominador()<<endl;
    return Cout;
}

CRacional& CRacional::operator+(CRacional &valor){
    CRacional *suma=new CRacional();
    suma->setNumerador(numerador*valor.getDenominador()+valor.getNumerador()*denominador);
    suma->setDenominador(denominador*valor.getDenominador());
    return *suma;
}

CRacional& CRacional::operator-(CRacional &valor){
    CRacional *resta=new CRacional();
    resta->setNumerador(numerador*valor.getDenominador()-valor.getNumerador()*denominador);
    resta->setDenominador(denominador*valor.getDenominador());
    return *resta;
}

CRacional& CRacional::operator*(CRacional &valor){
    CRacional *producto=new CRacional();
    producto->setNumerador(numerador*valor.getNumerador());
    producto->setDenominador(denominador*valor.getDenominador());
    return *producto;
}

CRacional& CRacional::operator/(CRacional &valor){
    CRacional *resultado=new CRacional();
    resultado->setNumerador(numerador*valor.getDenominador());
    resultado->setDenominador(denominador*valor.getNumerador());
    return *resultado;
}

CRacional& CRacional::operator=(CRacional &valor){
    setNumerador(valor.getNumerador());
    setDenominador(valor.getDenominador());
    return *this;
}

CRacional& CRacional::operator+=(CRacional &valor){
    setNumerador(numerador*valor.getDenominador()+valor.getNumerador()*denominador);
    setDenominador(denominador*valor.getDenominador());
    return *this;
}

CRacional& CRacional::operator-=(CRacional &valor){
    setNumerador(numerador*valor.getDenominador()-valor.getNumerador()*denominador);
    setDenominador(denominador*valor.getDenominador());
    return *this;
}

CRacional& CRacional::operator*=(CRacional &valor){
    setNumerador(numerador*valor.getNumerador());
    setDenominador(denominador*valor.getDenominador());
    return *this;

}

CRacional& CRacional::operator/=(CRacional &valor){
    setNumerador(numerador/valor.getNumerador());
    setDenominador(denominador*valor.getDenominador());
    return *this;
}

bool CRacional::operator==(CRacional &valor){
    int entero1, entero2;
    entero1=numerador*valor.getDenominador();
    entero2=denominador*valor.getNumerador();
    return (entero1==entero2);
}

bool CRacional::operator<(CRacional &valor){
    int entero1, entero2;
    entero1=numerador*valor.getDenominador();
    entero2=denominador*valor.getNumerador();
    return (entero1<entero2);
}

bool CRacional::operator>(CRacional &valor){
    int entero1, entero2;
    entero1=numerador*valor.getDenominador();
    entero2=denominador*valor.getNumerador();
    return (entero1>entero2);
}

//bool CRacional::operator!(CRacional&);
CRacional& CRacional::operator++(){
    setNumerador(getNumerador()+getDenominador());
    return *this;
}

CRacional& CRacional::operator++(int num){
    setNumerador(getNumerador()+getDenominador());
    return *this;
}

CRacional& CRacional::operator--(){
    setNumerador(getNumerador()-getDenominador());
    return *this;
}

CRacional& CRacional::operator--(int num){
    setNumerador(getNumerador()-getDenominador());
    return *this;
}
