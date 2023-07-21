/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Paciente_Medicina.h
 * Author: Danie
 *
 * Created on 7 de julio de 2023, 16:09
 */

#ifndef PACIENTE_MEDICINA_H
#define PACIENTE_MEDICINA_H
#include <iostream>
#include <iomanip>
#include "Paciente.h"
#include "Medicina_Cantidad.h"
#include "Medicina.h"
#include <list>
#include <map>
using namespace std;

class Paciente_Medicina {
public:
    Paciente_Medicina();
    Paciente_Medicina(const Paciente_Medicina& orig);
    virtual ~Paciente_Medicina();
    void SetTotalDeGastos(double totalDeGastos);
    double GetTotalDeGastos() const;
    int obtenerDNI() const;
    
    list<Medicina_Cantidad>::iterator buscarMedicina(
            const class Medicina_Cantidad&med);
    void setPaciente(const class Paciente&pac);
    void leerMedicinas(ifstream&arch);
    bool operator>(const class Paciente&pac);
    void imprimirPaciente(ofstream&arch);
    void operator=(const Paciente_Medicina&pac_med);
    // por que no pasa por referencia?
    void totalizar(map<int, Medicina>med);
private:
    class Paciente paciente;
    list<class Medicina_Cantidad> medicina_cantidad;
    double totalDeGastos;
};

#endif /* PACIENTE_MEDICINA_H */

