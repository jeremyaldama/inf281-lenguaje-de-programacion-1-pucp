/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConEnteros.h
 * Author: Alonso Oswaldo Acosta Gonzales
 * Codigo del Alumno: 20170809
 * Created on 11 de junio de 2021, 08:11 AM
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H
#include <fstream>
using namespace std;

void * leenum(ifstream &archDatos);
int cmpnum(const void *regA, const void *regB);
void imprimenum(ofstream &archReporte, void *reg, void *&regAnterior);

#endif /* LISTACONENTEROS_H */

