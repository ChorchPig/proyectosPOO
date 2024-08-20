#ifndef CLASEVEHICULO_H_INCLUDED
#define CLASEVEHICULO_H_INCLUDED

using namespace std;

class Vehiculo{
private:
    string marca;
    int puertas, cilindrada;
    float kilometraje, velocidad;
    bool motorEncendido;
public:
    static float valorPatente;
    //crear dos objetos, modificar este valor en uno y comprobar si es posible acceder a este valor sin crear instancias
    Vehiculo(string, int, int, float);
    ~Vehiculo();
    void encenderMotor(); //modificar para que intercale entre las funciones de encendido y apagado
    bool motorFuncionando();
    void cambiarVelocidad(float);
    string getMarca();
    int getPuertas();
    int getCilindrada();
    float getKilometraje();
    float getVelocidad();
};

#endif // CLASEVEHICULO_H_INCLUDED
