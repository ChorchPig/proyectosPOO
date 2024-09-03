#ifndef CLASESTRING_H_INCLUDED
#define CLASESTRING_H_INCLUDED

#include <cstring>

class myString{
private:
    char *theString;
    int longitud;
public:
    myString();
    myString(char*);
    ~myString();
    void setString(const char*);
    myString * operator=(const char*);
    void imprimirString();
    char* getString(); //reserva memoria en el heap
    int getLongitud();
    void concatenarString(const char*);
    myString operator+=(const char*);
    bool estaVacio();
    bool sonIguales(const char*);
    bool operator==(const char*);
    int encontrarSubString(const char*);
};

#endif // CLASESTRING_H_INCLUDED
