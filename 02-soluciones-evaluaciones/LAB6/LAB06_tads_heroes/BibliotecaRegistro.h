/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaRegistro.h
 * Author: alulab14
 *
 * Created on 2 de junio de 2023, 08:13 AM
 */

#ifndef BIBLIOTECAREGISTRO_H
#define BIBLIOTECAREGISTRO_H
#include <fstream>
using namespace std;

void*leer_registro_heroe(ifstream&arch);
void imprimir_registro_heroe (ofstream&arch, void*reg);
#endif /* BIBLIOTECAREGISTRO_H */

