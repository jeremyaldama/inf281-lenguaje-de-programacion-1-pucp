/* 
 * File:   Funciones.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 25 de abril de 2023, 9:49
 */

#ifndef METODOEXACTO_H
#define METODOEXACTO_H
#include <fstream>
using namespace std;

void cargaclientes(int *&cli_dni, char **&cli_nombre, char *&cli_categoria);
void leercadena(ifstream &arch, char*&cad);
void imprimirclientes(int *cli_dni, char **cli_nombre, char *cli_categoria);

#endif /* FUNCIONES_H */
