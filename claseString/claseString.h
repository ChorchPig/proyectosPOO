#ifndef CLASESTRING_H_INCLUDED
#define CLASESTRING_H_INCLUDED

#include <cstring>
#include <iostream>

class myString{
private:
    char *theString;
    int longitud;
public:
    myString();
    myString(const char*);
    ~myString();
    void setString(const char*);
    myString& operator=(const char*);
    friend void imprimirString(myString&);
    char* getString(); //reserva memoria en el heap
    int getLongitud();
    void copiarString(const char*);
    void concatenarString(const char*);
    myString& operator+=(const char*);
    bool estaVacio();
    bool sonIguales(const char*);
    bool operator==(const char*);
    int encontrarSubString(const char*); //actualmente incompleta
    friend std::istream operator>>(std::istream&, myString&);
    friend std::ofstream operator<<(std::ofstream&, myString&);
};

void imprimirString(myString*);

#endif // CLASESTRING_H_INCLUDED
