#include <iostream>
#include "claseString.h"

myString::myString(){
    theString=NULL;
    longitud=0;
}

myString::myString(char *str){
    longitud=sizeof(str);
    theString=new char[longitud];
    strcpy(theString, str);
}

myString::~myString(){
    delete[]theString;
}

void myString::setString(const char *str){
    longitud=sizeof(str);
    if(theString)
        delete[]theString;
    theString = new char[longitud];
    strcpy(theString, str);
}

myString* myString::operator=(const char *str){
    setString(str);
    return this;
}

char* myString::getString(){
    char* copia=new char[longitud];
    strcpy(copia, theString);
    return copia;
}

int myString::getLongitud(){ return longitud; }

void myString::concatenarString(const char *str){
    longitud += sizeof(str);
    strcat(theString, str);
}

myString myString::operator+=(const char *str){
    concatenarString(str);
    return (*this);
}

bool myString::estaVacio(){
    return (theString)? true : false;
}

bool myString::sonIguales(const char *str){ //actualmente incompleta
    bool iguales=true;

    return iguales;
}

bool myString::operator==(const char *str){
    return sonIguales(str);
}

int myString::encontrarSubString(const char *str){ //actualmente incompleta
    int position=0;

    return position;
}

void myString::imprimirString(){
    char *valorGetter=getString();
    std::cout<<valorGetter<<std::endl;
    delete []valorGetter;
}
