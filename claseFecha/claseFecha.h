#ifndef CLASEFECHA_H_INCLUDED
#define CLASEFECHA_H_INCLUDED

class Fecha{
private:
    int day, month, year;
public:
    Fecha(int, int, int);
    ~Fecha();
    void setDay();
    void setMonth();
    void setYear();
    int getDay();
    int getMonth();
    int getYear();
    validarFecha();
    mesLetras();
    imprimirFecha();
};

#endif // CLASEFECHA_H_INCLUDED
