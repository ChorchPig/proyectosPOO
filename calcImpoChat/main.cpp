#include <iostream>
#include "CalculadorImpositivo.h"

Categoria stringToCategoria(const string& categoria);

int main() {
    float rendimiento=1;
    for(int i=0; i<365; i++)
        rendimiento*=1.01;
    cout<<rendimiento<<endl;
}

Categoria stringToCategoria(const string& categoria) {
    if (categoria == "Limitado") {
        return Categoria::Limitado;
    }
    else if (categoria == "Completo") {
        return Categoria::Completo;
    }
    else if (categoria == "Extendido") {
        return Categoria::Extendido;
    }
    else {
        throw invalid_argument("Categoría no válida");
    }
}

