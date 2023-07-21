/* 
 * File:   Funciones.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 25 de abril de 2023, 0:07
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <fstream>
#include "Estructuras.h"
using namespace std;

ifstream& operator >>(ifstream&, struct Estructura_ClienteRegistrado&);
void operator +=(struct Estructura_ClienteRegistrado *, const struct Estructura_ClienteRegistrado);
void operator +=(struct Estructura_ClienteRegistrado &cliente, const struct Estructura_PedidoRealizado);
void operator +=(struct Estructura_ProductosEnAlmacen *arreglo,
        const struct Estructura_ProductosEnAlmacen producto);
void operator <<(ofstream &arch, struct Estructura_ClienteRegistrado cliente);

#endif /* FUNCIONES_H */
