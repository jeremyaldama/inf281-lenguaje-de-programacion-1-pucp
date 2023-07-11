/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RegistroUsuario.h
 * Author: Danie
 *
 * Created on 9 de julio de 2023, 17:43
 */

#ifndef REGISTROUSUARIO_H
#define REGISTROUSUARIO_H
#include <iostream>
#include <cstring>
#include "Usuario.h"
#include "RegistroPrestamo.h"
#include "Libro.h"
#include <vector>

class RegistroUsuario {
public:
    RegistroUsuario();
    RegistroUsuario(const RegistroUsuario& orig);
    virtual ~RegistroUsuario();
    
    void leerUsuario(ifstream&arch);
    void leerPrestamo(ifstream&arch);
    void leerPrestamo(ifstream&arch, vector<Libro>&libros);
    
    void imprimirUsuarioPrestamos(ofstream&arch);
    void operator=(const class RegistroUsuario&reg);
    
    void obtenerCodigoUltimoPrestamo(char* cad) const;
    int obtenerCodigo() const;
    void imprimirSuspendido(ofstream&arch, int fecha);
    
private:
    class Usuario usuario;
    vector<RegistroPrestamo> prestamos;
};

#endif /* REGISTROUSUARIO_H */

