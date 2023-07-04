/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   medicamento.h
 * Author: Danie
 *
 * Created on 12 de junio de 2023, 9:54
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H

class medicamento {
public:
    medicamento();
    medicamento(const medicamento& orig);
    virtual ~medicamento();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(char* nombre);
    void GetNombre(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void BuscarMedicamento(int medicamento);
private:
    int codigo;
    char* nombre;
    int cantidad;
    double precio;
    // aaaammdd 
    int fecha;
};

#endif /* MEDICAMENTO_H */

