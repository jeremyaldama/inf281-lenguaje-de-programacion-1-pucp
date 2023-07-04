/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Escala.h
 * Author: Danie
 *
 * Created on 22 de junio de 2023, 23:00
 */

#ifndef ESCALA_H
#define ESCALA_H

class Escala {
public:
    Escala();
    Escala(const Escala& orig);
    virtual ~Escala();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
private:
    int codigo;
    double precio;
};

#endif /* ESCALA_H */

