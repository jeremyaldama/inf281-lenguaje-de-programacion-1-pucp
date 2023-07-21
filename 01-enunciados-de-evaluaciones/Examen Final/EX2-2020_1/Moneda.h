/* 
 * Archivo:   Moneda.h
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 14 de diciembre de 2020, 12:07 PM
 */

#ifndef MONEDA_H
#define MONEDA_H
#include <fstream>
using namespace std;

class Moneda {
private:

    char simbolo;
    double equivalencia;
    char *nombre;

public:

    Moneda();
    Moneda(const Moneda& orig);
    virtual ~Moneda();
    
    void SetNombre(const char* nomb);
    void GetNombre(char *nomb) const;
    void SetEquivalencia(double equivalencia);
    double GetEquivalencia() const;
    void SetSimbolo(char simbolo);
    char GetSimbolo() const;
    
    void operator =(const Moneda& orig);

};

ifstream& operator >> (ifstream& arch, Moneda &moneda);

#endif /* MONEDA_H */
