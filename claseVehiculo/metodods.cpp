#include <iostream>
#include "claseVehiculo.h"

Vehiculo::Vehiculo(string marca1, int puertas1, int cilindrada1, float kilometraje1){
    marca=marca1;
    puertas=puertas1;
    cilindrada=cilindrada1;
    kilometraje=kilometraje1;
    velocidad=0;
    motorEncendido=false;
}

void Vehiculo::encenderMotor(){
    if(!motorEncendido){
        motorEncendido=true;
    }
    else (velocidad==0)? motorEncendido=false : motorEncendido=true;
}

bool Vehiculo::motorFuncionando(){ return motorEncendido; }

void Vehiculo::cambiarVelocidad(float nuevaVelocidad){
    velocidad=nuevaVelocidad;
}

Vehiculo::~Vehiculo(){}

int Vehiculo::getPuertas(){ return puertas; }
