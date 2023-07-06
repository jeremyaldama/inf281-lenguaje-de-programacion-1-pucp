/* 
 * File:   BigGenerica.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 23 de mayo de 2023, 19:13
 */

#ifndef BIGGENERICA_H
#define BIGGENERICA_H
#include <fstream>
using namespace std;

void creaarbol(void*&arbol, void*(*lee)(ifstream&), int(*cmp)(void*, void*),
        const char*nom);

void insertanodo(void*&arbol, int(*cmp)(void*, void*), void*nodo);

int arbolvacio(void*arbol);

void muestraarbol(void*arb, void(*imprime)(ofstream&, void*), const char*nom) ;

void enorden(ofstream&arch, void**arbol, void(*imprime)(ofstream&, void*));

#endif /* BIGGENERICA_H */
