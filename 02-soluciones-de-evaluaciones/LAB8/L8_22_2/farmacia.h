/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   farmacia.h
 * Author: Danie
 *
 * Created on 12 de junio de 2023, 9:57
 */

#ifndef FARMACIA_H
#define FARMACIA_H
#include "medico.h"
#include "sinreceta.h"
#include "conreceta.h"

class farmacia {
public:
    farmacia();
    farmacia(const farmacia& orig);
    virtual ~farmacia();
    void cargamedico();
    void leerecetas();
    void ObtenerMedicamento(int, class medicamento&);
    void ObtenerEspecialidad(int, char*);
    void imprimirrecetas();
    void ImprimirSinRecetas(ofstream&);
    void ImprimirConRecetas(ofstream&);
    void ImprimeLinea(ofstream&arch, char c, int n);
    void LeerReceta(ifstream&arch, const int &fecha, const int &cod_med,
        int dni, char*nom_cli, int &i_c, int &i_s);
private:
    class medico lmedico[1000];
    class sinreceta lsinreceta[1000];
    class conreceta lconreceta[1000];
};

#endif /* FARMACIA_H */

