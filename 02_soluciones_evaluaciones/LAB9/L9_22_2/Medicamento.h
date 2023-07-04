/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Medicamento.h
 * Author: Danie
 *
 * Created on 20 de junio de 2023, 18:55
 */

#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class Medicamento {
public:
    Medicamento();
    Medicamento(const Medicamento& orig);
    virtual ~Medicamento();
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void leemedicamento(int cod_med, ifstream&arch);
    double ObtenerNombrePrecio(int cod_medicamento, char*);
    virtual void imprimedicamento(ofstream&);
    virtual void aplicadescuento();
private:
//    int cod_med, int cantidad, int fecha, int cod_doc, 
//        int dni, const char*nombre_pac
    int codigo;
    char *nombre;
    int cantidad;
    double precio;
    int fecha;
    double total;
};

#endif /* MEDICAMENTO_H */

