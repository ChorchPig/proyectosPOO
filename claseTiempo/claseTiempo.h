#ifndef CLASETIEMPO_H_INCLUDED
#define CLASETIEMPO_H_INCLUDED

class Tiempo{
private:
    int horas, minutos, segundos;
public:
    Tiempo(int, int, int);
    ~Tiempo();
    void setHoras(int);
    void setMinutos(int);
    void setSegundos(int);
    int getHoras();
    int getMinutos();
    int getSegundos();
    void mostrarFmtEstandar();
    void mostrarFmtUniversal();
};

#endif // CLASETIEMPO_H_INCLUDED
