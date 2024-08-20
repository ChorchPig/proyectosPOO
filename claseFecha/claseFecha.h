#ifndef CLASEFECHA_H_INCLUDED
#define CLASEFECHA_H_INCLUDED

class Fecha{
private:
    int day, month, year;
public:
    Fecha(int, int, int);
    ~Fecha();
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    int getDay();
    int getMonth();
    int getYear();
    bool validarFecha(int, int, int);
    std::string mesLetras();
    void imprimirFecha();
};

#endif // CLASEFECHA_H_INCLUDED
