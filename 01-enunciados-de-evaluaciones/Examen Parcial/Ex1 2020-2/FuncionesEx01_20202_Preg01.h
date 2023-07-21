/* 
 * Archivo:   FuncionesEx01_20202_Preg01.h
 * Author: Oscar Dueñas Damian Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 27 de octubre de 2020, 09:02 AM
 */

#ifndef FUNCIONESEX01_20202_PREG01_H
#define FUNCIONESEX01_20202_PREG01_H
#include <fstream>
using namespace std;

ifstream abrirArchL (const char *);
ofstream abrirArchE (const char *);
void imprimeLinea (char , int , ofstream &);
char * leeCadena (ifstream &, char );
char * asignaCadenaExacta (char *);
void leerDatos (void *&, void *&);
void leerPedidos (void *&, ifstream &);
void leerStock (void *&, ifstream &);
void * asignarInfoPedido (int , int , int , char *, int , ifstream &);
void * leerSt (ifstream &);
void imprimirPedidos (void *, ofstream &);
void imprimePedido (void *, ofstream &);
void imprimirStock (void *, ofstream &);
void imprimeStock (void *, ofstream &);
void atiende (void *, void *);
void ordenarPedidos (void * , int );
void qsortPedidos (void **, int , int , int );
void cambiar (void *&, void *&);
int comparar (void *, void *, int );
void atenderPedido (void *, void *);
int actualizarStock (int , int , void *);
void imprimirDatos (void *);
void imprimePedidoF (int , int , int , char *, int , int ,ofstream &);

#endif /* FUNCIONESEX01_20202_PREG01_H */

