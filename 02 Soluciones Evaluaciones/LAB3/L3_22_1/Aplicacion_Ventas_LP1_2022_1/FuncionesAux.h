/* 
 * File:   FuncionesAux.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 25 de abril de 2023, 20:20
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
#include <fstream>
#include "Estructuras.h"
using namespace std;

void LeerDatosClientes(struct Estructura_ClienteRegistrado *clientes);

void LeerPedidos(struct Estructura_ClienteRegistrado *clientes, 
        struct Estructura_ProductosEnAlmacen *productos);
void CrearProducto(struct Estructura_ProductosEnAlmacen &producto, 
        char*codigo, char*descripcion, double precio_uni, double descuento);
int BuscarProducto(struct Estructura_ProductosEnAlmacen *productos, 
        char*codigo);
int BuscarCliente(struct Estructura_ClienteRegistrado *clientes, 
        int dni_cliente);

void ImprimirReporte(struct Estructura_ClienteRegistrado *clientes, 
        struct Estructura_ProductosEnAlmacen *productos);

#endif /* FUNCIONESAUX_H */
