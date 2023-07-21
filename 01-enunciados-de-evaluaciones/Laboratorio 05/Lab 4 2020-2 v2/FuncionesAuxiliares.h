/* 
 * Archivo:   FuncionesAuxiliares.h
 * Author: Oscar Dueñas Damian Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 14 de octubre de 2020, 11:49 AM
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
void cargarMedicosEspecialidad (char **&, char ***&, char ***&);
int buscarEspecialidad (char **, char *, int );
void incrementarEspaciosEsp (char **&, char ***&, int &, int &);
void incrementarEspaciosLista (char **&, int *, int *, int );
void incrementarEspaciosMed (char ***&,int &, int &);
void reporteMedicos (char **, char ***, char ***);
void buscarInfoMed (char *, char *, double &, char ***);
void cargarPacientes (char ***, char ***&, double ***&);
int buscarPaciente (char ***, char *, int );
void incrementarEspaciosPac (char ***&, int &, int &);
int buscarInfoMedico (char ***, char *, double &);
void incrementarEspaciosTar (double **&, int , int );
void reportePacientesPorMedico (char **, char ***, char ***, char ***, double ***);
int buscarMed (char ***, char *);

#endif /* FUNCIONESAUXILIARES_H */

