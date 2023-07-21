/* 
 * Archivo:   Bib_Func_Medicos.h
 * Author: Oscar Dueñas Damian Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 10 de octubre de 2020, 01:09 PM
 */

#ifndef BIB_FUNC_MEDICOS_H
#define BIB_FUNC_MEDICOS_H
#include <fstream>
using namespace std;

ifstream abrirArchL (const char *);
ofstream abrirArchE (const char *);
void imprimeLinea (char , int , ofstream &);
char * leeCadena (ifstream &, char );
char * asignaCadenaExacta (char *);
void leerMedicos (char **&, char ****&);
void imprimirMedicos (char **, char ****);
char * concantenar (char *, char *);
int buscarEspecialidad (char *, char **, int );
void AsignarInfoDelMedico (char *, char *, char *, int *, int *, int ,char****);
void incrementarEspacios (char ***&, int *, int *, int );

#endif /* BIB_FUNC_MEDICOS_H */

