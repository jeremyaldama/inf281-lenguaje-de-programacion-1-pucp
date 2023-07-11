/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listas_genericas.h
 * Author: alulab14
 *
 * Created on 2 de junio de 2023, 09:00 AM
 */

#ifndef LISTAS_GENERICAS_H
#define LISTAS_GENERICAS_H
#include <fstream>
using namespace std;

void crear_lista_heroes(void*arreglo_heroes, void*&lista_heroes, 
        void*(*leer_heroe)(void*, int ));
void InsertarNodo(void**&lista_aux, void*nodo, void**&sig);
void* CrearNodo(void*reg);

void*leer_heroe(void*arreglo_heroes, int i);
void imprimir_lista_heroes(void*lista_heroes, void(*imprimir_registro_heroe)
    (ofstream&, void*));
void eliminar_lista_heroes_repetidos(void*&lista_heroes, 
        void(*eliminar_registro)(void*) );
#endif /* LISTAS_GENERICAS_H */

