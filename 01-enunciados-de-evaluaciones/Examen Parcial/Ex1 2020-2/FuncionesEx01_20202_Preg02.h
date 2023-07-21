/* 
 * Archivo:   FuncionesEx01_20202_Preg02.h
 * Author: Oscar Dueñas Damian Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 27 de octubre de 2020, 08:04 AM
 */

#ifndef FUNCIONESEX01_20202_PREG02_H
#define FUNCIONESEX01_20202_PREG02_H
#include <fstream>
using namespace std;

ifstream abrirArchL (const char *);
ofstream abrirArchE (const char *);
void imprimeLinea (char , int , ofstream &);
char * leeCadena (ifstream &, char );
char * asignaCadenaExacta (char *);
void leerDatos (char **&, int ***&, char ***&);
void imprimirDatos (char **, int ***, char ***);
void incrementarEspaciosClientes (char **&, int ***&, char ***&, int &, int &);
void incrementarEspaciosCliente(int **&, char **&, int &, int &);
int buscarProducto (int **, int , int );
void agregarProducto (int **&, char **&, int , char *, int , int &);
void ordenarPedidos (char **, int ***, char ***);
void ordenar (int **, char **, int , int );
void cambiarINT (int **, int , int );
void cambiarSTR (char **, int , int );

#endif /* FUNCIONESEX01_20202_PREG02_H */

