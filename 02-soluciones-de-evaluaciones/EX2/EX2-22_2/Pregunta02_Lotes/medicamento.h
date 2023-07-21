/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   medicamento.h
 * Author: Danie
 *
 * Created on 8 de julio de 2023, 12:05
 */

#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class medicamento {
public:
    medicamento();
    medicamento(const medicamento& orig);
    virtual ~medicamento();
    void SetEstado(int estado);
    int GetEstado() const;
    void SetFechavenc(int fechavenc);
    int GetFechavenc() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void lee(ifstream&arch, const char*cad, int);
    virtual void imprime(ofstream&arch);
    virtual void registrarDatos(const medicamento &med,
            int, const char*inspector);
private:
    int codigo;
    char *nombre;
    int stock;
    int fechavenc;
    int estado; // 1 activo, 0 vencido
};

#endif /* MEDICAMENTO_H */

