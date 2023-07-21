/* 
 * Archivo:   FuncionesActividad04.h
 * Author: Oscar Dueñas Damian Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 5 de octubre de 2020, 06:56 PM
 */

#ifndef FUNCIONESACTIVIDAD04_H
#define FUNCIONESACTIVIDAD04_H
#include <fstream>
using namespace std;

void leerAlumnos(int *&, char **&, char ***&);
void imprimirAlumnos(int *, char **);
void leerCursos(int *&, char ***&);
void imprimirReporte(int *, char **, char ***);
void imprimeLinea (char , int , ofstream &);
ifstream abrirArchL (const char *);
ofstream abrirArchE (const char *);
char * leeCadena (ifstream &arch, char );
void agregarCurso (char ***&, char *, int , int *);
int buscarAlumno (int *, int );

#endif /* FUNCIONESACTIVIDAD04_H */

