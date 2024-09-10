#ifndef CLASERACIONAL_H_INCLUDED
#define CLASERACIONAL_H_INCLUDED

class CRacional{
private:
    int numerador, denominador;
public:
    CRacional();
    CRacional(int&);
    CRacional(int, int);
    ~CRacional();
    void setNumerador(int);
    void setDenominador(int);
    int getNumerador();
    int getDenominador();
    friend std::istream& operator>>(std::istream&, CRacional&);
    friend std::ostream& operator<<(std::ostream&, CRacional&);
    CRacional& operator+(CRacional&); //¿Hacen una gestión correcta de memoria estos operadores?
    CRacional& operator-(CRacional&);
    CRacional& operator*(CRacional&);
    CRacional& operator/(CRacional&);
    CRacional& operator=(CRacional&);
    CRacional& operator+=(CRacional&);
    CRacional& operator-=(CRacional&);
    CRacional& operator*=(CRacional&);
    CRacional& operator/=(CRacional&);
    bool operator==(CRacional&);
    bool operator<(CRacional&);
    bool operator>(CRacional&);
//    bool operator!(CRacional&);
    CRacional& operator++();
    CRacional& operator++(int);
    CRacional& operator--();
    CRacional& operator--(int);
};

#endif // CLASERACIONAL_H_INCLUDED
