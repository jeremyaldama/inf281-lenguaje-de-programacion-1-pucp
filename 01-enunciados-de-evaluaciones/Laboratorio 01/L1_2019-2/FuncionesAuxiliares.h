/* 
 * Archivo:   FuncionesAuxiliares.h
 * Author: Oscar Dueñas Damian Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 20 de noviembre de 2020, 02:03 PM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
#include <fstream>
using namespace std;

void imprimeLinea (char , int );
void leerCliente (double &, char &);
void imprimeCabeceraCliente();
void minuscula (char *);
void imprimeCabeceraMovimientos (char );
void procesarMovimientos (double , char , double , double );
void procesarTransaccion (double &, double &, double &, double , double , char , int &, int &);
double hallar_factor (char , char , double , double );
void imprimirResumen (int , int , double ,double , double , double , char );

#endif /* FUNCIONESAUXILIARES_H */

