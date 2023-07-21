/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * Proyecto: LAB06_ArbolPrioridad
 * File:   FunNumeros.h
 * Author: Gianella Lilian Lope Sainz
 * Código: 20191408
 * Created on 3 de junio de 2022, 8:03
 */

#ifndef FUNNUMEROS_H
#define FUNNUMEROS_H

#include <fstream>
using namespace std;

void * leenumero(ifstream &arch) ;
int cmpnumero(const void *d1, const void *d2);
void imprimenumero(void *dato, ofstream &arch);

#endif /* FUNNUMEROS_H */
