/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Disponible.h
 * Author: Danie
 *
 * Created on 22 de junio de 2023, 0:55
 */

#ifndef DISPONIBLE_H
#define DISPONIBLE_H
#include "Libro.h"

class Disponible : public Libro {
public:
    Disponible();
    Disponible(const Disponible& orig);
    virtual ~Disponible();
    void SetZona(int zona);
    int GetZona() const;
    void AsignaCopia(const char*codigo, const char*descrip, const char*autor, 
                    int aa, int cantidad, double precio, int zona, int num);
    void Imprimir(ofstream&);
private:
    int zona;
};

#endif /* DISPONIBLE_H */

