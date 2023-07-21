/* 
 * Archivo:   Laboratorio04_Funciones.h
 * Author: Oscar Dueñas Damian Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 9 de octubre de 2020, 08:15 AM
 */

#ifndef LABORATORIO04_FUNCIONES_H
#define LABORATORIO04_FUNCIONES_H
#include <fstream>
using namespace std;

ifstream abrirArchL (const char *);
ofstream abrirArchE (const char *);
void imprimeLinea (char , int , ofstream &);
char * leeCadena (ifstream &, char );
char * asignaCadenaExacta (char *);
void cargarMedicos (char **&, char **&, double *&);
void reporteMedicos(char **, char **, double *);
void reporteDeIngresos (char **, char **, double *);
void cargarPacientes (char *, int *&, char **&, 
        double *&, int *&);
char * buscarMedico (char *, char **, char **);
void reporteDelMedico (char *, char **, char **, double *,
        int *, char **, double *, int *,
        ofstream &);
double buscarTarifa (char *, char **, double *);
void liberarEspacios (int *&, char **&, double *&, int *&);
char * leeMedico(ifstream &, char , int &);
int esta (int , int *, int );


#endif /* LABORATORIO04_FUNCIONES_H */

