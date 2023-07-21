/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * Proyecto: LAB06_ArbolPrioridad
 * File:   FunPedidos.h
 * Author: Gianella Lilian Lope Sainz
 * Código: 20191408
 * Created on 3 de junio de 2022, 8:03
 */

#ifndef FUNPEDIDOS_H
#define FUNPEDIDOS_H

#include <fstream>
using namespace std;

void * leepedido(ifstream &arch);
int cmppedido(const void *perI, const void *perJ);
void imprimepedido(void *reg, ofstream &arch);
void imprimirFecha(ofstream &arch, int fecha);

#endif /* FUNPEDIDOS_H */
