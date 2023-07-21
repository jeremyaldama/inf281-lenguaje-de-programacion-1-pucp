/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesAuxiliares.h
 * Author: Gianella Lope Sainz
 *
 * Created on 8 de abril de 2022, 8:04
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void imprimirFecha(int dd, int mm, int aa);
void imprimirLinea(char car, int cantVeces);
char categoriaCliente(char *nombre);
int cantidadLetras(char *palabra);
void cambioPalabra(char *palabra);
void imprimirCabeceraCliente(int dniCliente, char *nombre, int telefono, char categoria, double descuento);
void calcularDescuentoCliente(double &dscto, char categCliente, double porcA, double porcB, double porcC);
void imprimirProducto(int cantProductos, char *codProducto, char *descripcionProd, 
        double precUni, double cantidad, double total, 
        double descuentoAnadido, double dscto, double pago, double descuentoPago);
void copiarNombre(char *nombreCliente, char *nombreClienteMasDescuento);
int compararCadenas(char *cadena1, char *cadena2);

#endif /* FUNCIONESAUXILIARES_H */
