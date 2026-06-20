#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#include <list>
#include <chrono>

constexpr int VIDASINI  = 3;
constexpr int ARRIBA    = 72;
constexpr int ABAJO     = 80;
constexpr int IZQUIERDA = 75;
constexpr int DERECHA   = 77;
constexpr int ESC       = 27;
constexpr int ESPACIO   = 32;

constexpr int LIM_SUP = 4;
constexpr int LIM_INF = 28;
constexpr int LIM_IZQ = 3;
constexpr int LIM_DER = 75;

constexpr int delayAst= 3;

void goToXY(int x, int y);
void ocultarCursor();
void pintarLimites();
void pintarPuntaje(int puntos);
int leerMejorPuntaje();
void guardarMejorPuntaje(int nuevoPuntaje);
void pintarMejorPuntaje(int mejor);

class Asteroid{
    int coordX, coordY;
    std::chrono::steady_clock::time_point ultimoMovimiento;
    int intervaloMs;
public:
    Asteroid(int _x, int _y, int intervalo);
    ~Asteroid();
    void mover();
    void pintar();
    void reiniciarPosicion();
    int getX()const;
    int getY()const;
    void setIntervaloMs(int puntos); //para aumentar la velocidad con los puntos
};

class Bala {
    int coordX, coordY;
public:
    Bala(int _x, int _y);
    ~Bala();
    void mover();
    bool fuera();
    int getX()const;
    int getY()const;
};

class Nave {
    int coordX, coordY, vidas;
    std::list<Bala> balas;
public:
    Nave(int _x, int _y, int _vidas);
    ~Nave();
    void actuar(char tecla);
    void borrar();
    void pintar();
    void mostrarVidas();
    void perderVida();
    int getVidas()const;
    int getX()const;
    int getY()const;
    bool choqueNaveAst(std::list<Asteroid> &asteroirdes);
    void moverBalas();
    bool choqueBalaAst(std::list<Asteroid> &asteroirdes);
};

/*
class Dificultad{
    int nivel = 1;
public:
    void actualizar(int puntos, std::list<Asteroid>& asteroides){
        int nuevoNivel = 1;
        if(puntos > 200) nuevoNivel = 3;
        else if(puntos > 100) nuevoNivel = 2;
        if(nuevoNivel == nivel)
            return;
        nivel = nuevoNivel;
        int intervalo = 150 / nivel;
        for(auto& ast : asteroides)
            ast.setIntervalo(intervalo);
    }
};
*/

#endif // PROTOTIPOS_H_INCLUDED
