/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * Proyecto: LAB06_ArbolPrioridad
 * File:   BibGenerica.h
 * Author: Gianella Lilian Lope Sainz
 * Código: 20191408
 * Created on 3 de junio de 2022, 8:03
 */

#ifndef BIBGENERICA_H
#define BIBGENERICA_H

#include <fstream>
using namespace std;

void creaarbol(void *&, void*(*)(ifstream&),int (*)(const void*, const void*), const char *);
int arbolvacio(void *);
void insertanodo(void *&, void *,int (*)(const void*, const void*));
void muestraarbol(void *, void (*)(void *, ofstream &), const char *);
void enorden(void *, void (*)(void *, ofstream &), ofstream &);

#endif /* BIBGENERICA_H */
