#ifndef CLASEFECHA_H_INCLUDED
#define CLASEFECHA_H_INCLUDED

class Fecha{
private:
    int day, month, year;
    void setDay(int);
    void setMonth(int);
    void setYear(int);
public:
    Fecha();
    Fecha(int, int, int);
    virtual ~Fecha();
    void setDatos(int, int, int);
    int getDay()const;
    int getMonth()const;
    int getYear()const;
    int getMaxDays(int)const;
    bool validarFecha(int, int, int);
    std::string mesLetras();
    void imprimirFecha();
    void agregarUnDia();
};

#endif // CLASEFECHA_H_INCLUDED
