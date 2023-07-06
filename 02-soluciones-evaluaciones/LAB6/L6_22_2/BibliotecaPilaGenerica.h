/* 
 * File:   BibliotecaPilaGenerica.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 1 de junio de 2023, 0:17
 */

#ifndef BIBLIOTECAPILAGENERICA_H
#define BIBLIOTECAPILAGENERICA_H

#include <fstream>

using namespace std;

void cargaarreglo(void*&arreglo, int (*cmp)(const void*, const void*),
        void* (*lee)(ifstream&), const char *nom);
void cargapila(void*&pilaini, void*arreglo);
void muevepila(void*pilaini, void*&pilafin);
void push(void*pila, void*dato);
void* pop(void*pilaini);

void Hanoi(int n, void*pilaini, void*aux, void*pilafin);
#endif /* BIBLIOTECAPILAGENERICA_H */
