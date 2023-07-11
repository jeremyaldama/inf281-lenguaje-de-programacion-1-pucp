/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NUsuario.h
 * Author: Danie
 *
 * Created on 8 de julio de 2023, 22:31
 */

#ifndef NUSUARIO_H
#define NUSUARIO_H
#include "Estudiante.h"
#include "Administrativo.h"
#include "Docente.h"
#include "Usuario.h"

class NUsuario {
public:
    NUsuario();
    // no es necesario el constructor porque solo va a asignar la direccion
    // de memoria por default
    NUsuario(const NUsuario& orig);
    virtual ~NUsuario();
    
    void leerUsuario(ifstream&arch);
private:
    // falta inicializar pusuario
    class Usuario *pusuario;
};

#endif /* NUSUARIO_H */

