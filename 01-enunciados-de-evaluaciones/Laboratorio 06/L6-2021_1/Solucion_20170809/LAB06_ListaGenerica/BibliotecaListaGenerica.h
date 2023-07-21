/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaListaGenerica.h
 * Author: Alonso Oswaldo Acosta Gonzales
 * Codigo del Alumno: 20170809
 * Created on 11 de junio de 2021, 08:10 AM
 */

#ifndef BIBLIOTECALISTAGENERICA_H
#define BIBLIOTECALISTAGENERICA_H
#include <fstream>
using namespace std;

void creaLista(void *&lista,void *(*leenum)(ifstream &),int (*cmpnum)(const void *, const void *),const char *nombreArch);
void inicializarLista(void *&lista);
void insertarLista(void *lista,void *dato,int (*cmpnum)(const void *, const void *));
void imprimeLista(void *lista,void (*imprimenum)(ofstream &,void *,void *&),const char *nombreArch);
bool listavacia(void *lista);
void uneLista(void *lista1, void *lista2);


#endif /* BIBLIOTECALISTAGENERICA_H */

