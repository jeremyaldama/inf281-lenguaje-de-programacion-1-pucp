/* 
 * Archivo:   FuncionesAuxiliares.h
 * Author: Oscar Dueñas Damian Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 26 de noviembre de 2020, 12:00 AM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
#include <fstream>
using namespace std;

ifstream abrirArchL (const char *);
ofstream abrirArchE (const char *);
void imprimeLinea (char , int , ofstream &);
void llenarMedicos (Medico *, ifstream &, int &);
void imprimirMedicos (Medico *, ofstream &, int );
void leerPacientes (Medico *, ifstream &, int );
int buscarMedico (Medico *, char *, int ); 
void leerOperaciones (Medico *, ifstream &, int );

#endif /* FUNCIONESAUXILIARES_H */

