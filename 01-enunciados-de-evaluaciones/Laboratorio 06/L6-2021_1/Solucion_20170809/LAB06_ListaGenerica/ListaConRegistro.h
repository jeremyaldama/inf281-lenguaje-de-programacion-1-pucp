/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConRegistro.h
 * Author: Alonso Oswaldo Acosta Gonzales
 * Codigo del Alumno: 20170809
 * Created on 11 de junio de 2021, 08:11 AM
 */

#ifndef LISTACONREGISTRO_H
#define LISTACONREGISTRO_H
#include <fstream>
using namespace std;

void * leeregistro(ifstream &archDatos);
char *leerCadena(ifstream &archDatos);
int cmpregistro(const void *regA, const void *regB);
void imprimeregistro(ofstream &archReporte,void *reg,void *&fechaCabecera);
void transformarFecha(int &dd,int &mm,int &aa,int fecha);
void imprimirLinea(char c,int cant,ofstream &arch);
char * obtenerNombreConductor(int codLicencia);


#endif /* LISTACONREGISTRO_H */

