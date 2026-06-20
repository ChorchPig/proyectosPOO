#include <iostream>
#include <map>
#include "claseEmpleado.h"

template <class K, class V> void vPrintMp(map<K, V> mp){
    typename map<K, V>::iterator ForIter;
    ForIter = mp.begin();                       // puntero al primer elemento
    cout << endl;
    while (ForIter != mp.end() ){                // mientras no sea el último elemento
        cout << ForIter->second << endl; //cout << ForIter->first << "  " << ForIter->second << endl;
        ForIter++;                              // aumento el iterador
    }
    cout << "\n\n";
}

int main(){
    map<unsigned, Empleado> mapEmpleados;
    Empleado empleado1("Pedro", "Picapiedra", 12345678, 3, 1203.5),
            empleado2("Pablo", "Picapiedra", 87654321, 4, 4012.75),
            empleado3("Vilma", "Picapiedra", 45612378, 1, 502.25);

    mapEmpleados.insert(pair<unsigned, Empleado>(empleado1.getDNI(), empleado1));
    mapEmpleados.insert(pair<unsigned, Empleado>(empleado2.getDNI(), empleado2));
    mapEmpleados.insert(pair<unsigned, Empleado>(empleado3.getDNI(), empleado3));

    cout << "MAP DE PERSONAS:\n\n";
    vPrintMp(mapEmpleados);

    return 0;
}

/*
    cout << "La persona con documento 1122 es: \n" << persm.find(1122)->second << endl;
    cout << "Acceso mediante el operador []: \n" << persm[2341] << endl << endl;
    persm[1234] = pab;              // modifico los datos de la persona
    vPrintMp(persm);
*/
