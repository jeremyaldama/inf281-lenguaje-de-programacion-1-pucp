/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Faltante.h
 * Author: Danie
 *
 * Created on 17 de junio de 2023, 16:40
 */

#ifndef FALTANTE_H
#define FALTANTE_H
#include <fstream>
using namespace std;

class Faltante {
private:
    int codigo;
    int cantidad;
public:
    Faltante();
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
};

ofstream& operator <<(ofstream&, Faltante&);

#endif /* FALTANTE_H */

