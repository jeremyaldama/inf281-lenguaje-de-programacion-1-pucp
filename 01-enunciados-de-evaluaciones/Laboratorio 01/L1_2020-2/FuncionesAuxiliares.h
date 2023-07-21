/* 
 * Archivo:   FuncionesAuxiliares.h
 * Author: Oscar Dueñas Damian Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 29 de octubre de 2020, 11:48 PM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
#include <fstream>
using namespace std;

void imprimeLinea (char , int );
void formato (char *);
void leerAlumno (int , int &);
void imprimeCabecera ();
void procesarCursos (int &, int );
void imprimirRegistro (int &, double &, double &, double &, double &, int &, int , 
        int , int , int , char *, int , double , int );
void imprimirResumen (int , double , double , double , double , int );

#endif /* FUNCIONESAUXILIARES_H */

