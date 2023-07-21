/* 
 * Archivo:   BibliotecaAuxiliar.h
 * Author: Oscar Dueñas Damian Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 17 de octubre de 2020, 01:30 PM
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
void leerDatos (char ***&, int *&, char **&);
void imprimirDatos (char ***, int *, char **);
void leeCursos (char ***&, ifstream &);
void leeProfesores (int *&, char **&, ifstream &);
void incrementarEspaciosC (char ***&, int &, int &);
char ** asignaInfoCurso (char *, char *, char *);
void incrementarEspaciosP (int *&, char **&, int &, int &);
void leerSesiones (void *&);
void imprimirSesiones (void *);
void *leeSesion (ifstream &);
int * leeHorariosSesion (ifstream &);
void imprimirSesion (void *, ofstream &, int );
void imprimeHoras (int *, ofstream &);
void formatoHorario (int , ofstream &);
void reporteCargaHorariaDeProf (char ***, int *, char **, void *);
void imprimirSesionProfesor (void *, int &, int , char ***, ofstream &);
int buscarCurso (char *, char ***);
void imprimirHorasProfesor (int *, int , ofstream &);
void formatoHorarioProfesor (int , ofstream &, int &);

#endif /* BIBLIOTECAAUXILIAR_H */

