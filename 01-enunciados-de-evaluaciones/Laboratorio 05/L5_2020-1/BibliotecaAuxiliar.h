/* 
 * Archivo:   BibliotecaAuxiliar.h
 * Author: Oscar Dueñas Damian Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 20 de octubre de 2020, 04:25 PM
 */

#ifndef BIBLIOTECAAUXILIAR_H
#define BIBLIOTECAAUXILIAR_H
#include <fstream>
using namespace std;

ifstream abrirArchL (const char *);
ofstream abrirArchE (const char *);
void imprimeLinea (char , int , ofstream &);
char * leeCadena (ifstream &, char );
char * asignaCadenaExacta (char *);
void leerAlumnos (void *&);
void imprimirAlumnos (void *);
void *leeAlumno (ifstream &);
void imprimeAlumno (void *, ofstream &);
void leerCursos (void *);
int buscarAlumno (void *, int );
bool igual_codigo (void *, int );
void agregarCurso (void *, int &, char *, int , double );
void incrementarEspacios (char **&, int *, int &);
void consolidado (void *);
void imprimirAlumno(void *, ofstream &);

#endif /* BIBLIOTECAAUXILIAR_H */

