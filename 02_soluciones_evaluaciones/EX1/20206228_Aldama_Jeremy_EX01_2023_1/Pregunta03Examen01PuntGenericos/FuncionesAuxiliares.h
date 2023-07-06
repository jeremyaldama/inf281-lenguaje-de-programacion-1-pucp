/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: alulab14
 *
 * Created on 16 de mayo de 2023, 10:35 AM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
#include <fstream>
using namespace std;
void CargaCursos(int*alumnos_cod, void*&alumnoveces, const char*nom);

void*LeerRegistro(ifstream&arch);

#endif /* FUNCIONESAUXILIARES_H */

