/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arreglos_genericos.h
 * Author: alulab14
 *
 * Created on 2 de junio de 2023, 08:04 AM
 */

#ifndef ARREGLOS_GENERICOS_H
#define ARREGLOS_GENERICOS_H
#include <fstream>
using namespace std;

void llenar_arreglo_heroes(void*&arreglo_heroes, int&cantidad_total_heroes,
        void* (*leer) (ifstream&), const char*nom);
int cmp_multicriterio_void(const void*i, const void*j);
#endif /* ARREGLOS_GENERICOS_H */

