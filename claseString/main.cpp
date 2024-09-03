#include <iostream>
#include "claseString.h"

using namespace std;

int main(){
    myString *string1= new myString();
    string1->setString("Hola mundo");
    string1->imprimirString();
    string1->concatenarString("\nValor concatendado");
    string1->imprimirString();
    myString string2;
    string2="Operador = sobrecargado";
    string2.imprimirString();
    delete string1;
    return 0;
}
