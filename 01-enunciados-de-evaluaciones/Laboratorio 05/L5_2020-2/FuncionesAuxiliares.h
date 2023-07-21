/* 
 * Archivo:   FuncionesAuxiliares.h
 * Author: Oscar Dueñas Damian Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 16 de octubre de 2020, 08:02 AM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
#include <fstream>
using namespace std;

ifstream abrirArchL (const char *);
ofstream abrirArchE (const char *);
void imprimeLinea (char , int , ofstream &);
char * leeCadena (ifstream &, char );
char * asignaCadenaExacta (char *);
void leerMedicos (char **&, char **&, double *&);
void imprimirMedicos (char **, char **, double *);
void leeAtenciones (char **, int **&, char ***&, double **&, int **&);
void repDeIngresos (char **, char **, double *, int **codPac, 
        char ***, double **, int **);
int buscarMedico (char **, char *);
int buscarPaciente (int *, int , int );
void incrementarEspacios (int *&, char **&, double *&, int *&, int *, int *, int );
void asignarInfoPacientes (int *&, char **&, double *&, int *&, int , char *, 
        double , int , int , int*);
void imprimirCabecera (char *, char *, double , ofstream &);

#endif /* FUNCIONESAUXILIARES_H */

