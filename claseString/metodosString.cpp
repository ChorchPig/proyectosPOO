#include <iostream>
#include "claseString.h"

myString::myString(){
    theString=NULL;
    longitud=0;
}

myString::myString(const char *str){
    setString(str);
}

myString::~myString(){
    delete[]theString;
}

void myString::setString(const char *str){
    longitud=strlen(str); //crear int longitudString(const char *);
    if(theString)
        delete[]theString;
    theString=new char[longitud+1];
    for(int i=0; i<longitud; i++)
        theString[i]=str[i];
}

myString& myString::operator=(const char *str){
    setString(str);
    return *this;
}

void imprimirString(myString &str){ std::cout<<str.theString<<std::endl; }

char* myString::getString(){
    char* copia=new char[longitud];
    strcpy(copia, theString);
    return copia;
}

int myString::getLongitud(){ return longitud; }

bool myString::estaVacio(){
    return (theString)? true : false;
}

bool myString::sonIguales(const char *str){
    int longitudStr=sizeof(str), i=0;
    bool iguales=(longitudStr==longitud);
    while(i<longitud&&iguales){
        iguales=(theString[i]==str[i]);
        i++;
    }
    return iguales;
}

bool myString::operator==(const char *str){
    bool resultado=sonIguales(str);
    return resultado;
}

int myString::encontrarSubString(const char *str){ //actualmente incompleta
    int position=-1;

    return position;
}

void myString::copiarString(const char *str){ setString(str); }

void myString::concatenarString(const char *str){
    int nuevaLongitud=longitud+strlen(str); //crear int longitudString(const char *);
    int i=0, j=0;
    char* nuevoString=new char[nuevaLongitud];
    while(i<longitud){
        nuevoString[i]=theString[i];
        i++;
    }
    while(i<nuevaLongitud+1){
        nuevoString[i]=str[j];
        i++;
        j++;
    }
    if(theString)
        delete[]theString;
    theString=nuevoString;
    longitud=nuevaLongitud;
}

myString& myString::operator+=(const char *str){
    concatenarString(str);
    return *this;
}
