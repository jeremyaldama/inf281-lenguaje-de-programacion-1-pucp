/* 
 * Archivo:   FuncionesLaboratorio07.h
 * Author: Oscar Dueñas Damian Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 11 de noviembre de 2020, 11:49 PM
 */

#ifndef FUNCIONESLABORATORIO07_H
#define FUNCIONESLABORATORIO07_H
#include <fstream>
using namespace std;

ifstream abrirArchL (const char *);
ofstream abrirArchE (const char *);
void imprimeLinea (char , int , ofstream &);
char * leeCadena (ifstream &, char );
char * asignaCadenaExacta (char *);

void * leeRegistro (ifstream &);
int comparar (const void *, const void *);
void imprimeRegistro (ofstream &, void *);
int compararStr (const void *parametro1, const void *parametro2);
void eliminaReg (void *);

void crealista (void *&, void * (*)(ifstream &), int (*)(const void *, const void *));
void insertarLista (void *&, void *, int (*)(const void *, const void *));
void imprimelista (void *, void (*)(ofstream &,void *));
void eliminarDatoLista (void *&, void *, int (*)(const void *, const void *));
void * buscarDatoLista (void *, void *, int (*)(const void *, const void *));

void encola (void *&, void *);
void * desencola (void *&);
int esColaVacia (void *);

void despacha (void *&, void *&, int , char **);
void imprimedespachados (void *&, void (*)(ofstream &,void *));
void atender (void *&, void *&, char *, int , ofstream &);

#endif /* FUNCIONESLABORATORIO07_H */

