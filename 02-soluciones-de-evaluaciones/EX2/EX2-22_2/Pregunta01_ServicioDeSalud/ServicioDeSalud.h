/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServicioDeSalud.h
 * Author: Danie
 *
 * Created on 7 de julio de 2023, 16:16
 */

#ifndef SERVICIODESALUD_H
#define SERVICIODESALUD_H

#include "Medicina.h"
#include "Paciente_Medicina.h"

class ServicioDeSalud {
public:
    void abrirArchivoLectura(ifstream&arch, const char*);
    void abrirArchivoEscritura(ofstream&arch, const char*);

    ServicioDeSalud();
    ServicioDeSalud(const ServicioDeSalud& orig);
    virtual ~ServicioDeSalud();
    void leerMedicinas(const char*);
    void imprimirMedicinas(const char*cad);

    void leerConsultas(const char*);
    list<Paciente_Medicina>::iterator buscarPaciente(
            const class Paciente&pac);
    void imprimePacientes(const char*cad);
    void totalizar();
private:
    map<int, Medicina> medicina;
    list<Paciente_Medicina> paciente_medicina;
};

#endif /* SERVICIODESALUD_H */

