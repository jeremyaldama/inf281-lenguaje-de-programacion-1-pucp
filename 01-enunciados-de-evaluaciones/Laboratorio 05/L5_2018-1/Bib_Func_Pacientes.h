/* 
 * Archivo:   Bib_Func_Pacientes.h
 * Author: Oscar Dueñas Damian Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 10 de octubre de 2020, 07:06 PM
 */

#ifndef BIB_FUNC_PACIENTES_H
#define BIB_FUNC_PACIENTES_H
#include <fstream>
using namespace std;

void leerPacientes (char ***&, double **&, char **, char ****);
void imprimirPacientes (char ***, double **, char **);
char *leeCadenaEnd (ifstream &, char , int &);
int buscarPaciente (char *, char ***, int );
double buscarTarifa (char *, char ****, int &);

#endif /* BIB_FUNC_PACIENTES_H */

