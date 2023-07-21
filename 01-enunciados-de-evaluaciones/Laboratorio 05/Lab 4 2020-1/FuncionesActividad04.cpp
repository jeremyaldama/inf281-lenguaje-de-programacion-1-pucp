/* 
 * Archivo:   FuncionesActividad04.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 5 de octubre de 2020, 06:56 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesActividad04.h"
using namespace std;

void leerAlumnos(int *&codigos, char **&nombres, char ***&cursos) {
    int buffCod[200], numDat = 0;
    char *nombAl, car, *buffNomb[200], *buffExtra;
    ifstream arch = abrirArchL("Alumnos.csv");
    while (1) {
        arch >> car;
        if (arch.eof()) break;
        arch >> car >> buffCod[numDat] >> car;
        nombAl = leeCadena(arch,',');       
        buffNomb[numDat] = nombAl;
        buffExtra = leeCadena(arch,'\n');
        numDat++;       
    }
    buffCod[numDat] = -1;
    codigos = new int [numDat+1];
    nombres = new char * [numDat];
    cursos = new char ** [numDat];
    for (int i = 0; i < numDat; i++) {
        codigos[i] = buffCod[i];
        nombres[i] = buffNomb[i];
    }
    codigos[numDat] = buffCod[numDat];
}

char * leeCadena (ifstream &arch, char car) {
    char buff[200], *cad;
    arch.getline(buff,200,car);
    cad = new char [strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void imprimirAlumnos(int *codigos, char **nombres) {
    ofstream arch = abrirArchE("ReporteAlumnos.txt");
    arch << "CODIGOS " << setw(20) << "NOMBRES" << endl;
    imprimeLinea('=',60,arch);
    for (int i = 0; codigos[i] != -1; i++) {
        arch.fill('0');
        arch << setw(8) << codigos[i];
        arch.fill(' ');
        arch << setw(5) << " "
                << left << setw(40) << nombres[i] << endl;
    }
}

void leerCursos(int *&codigos, char ***&cursos) {
    int codigo, pos, numDatxAlumno[50] = {0}, nota;
    char *buffExtra, car, *nombCur, **buffNone;
    buffNone = new char *[1]; buffNone[0] = nullptr;
    for (int i = 0; codigos[i] != -1; i++) cursos[i] = buffNone;
    ifstream arch = abrirArchL("Cursos.csv");
    while (1) {
        arch >> codigo;
        if (arch.eof()) break;
        arch >> car;
        nombCur = leeCadena(arch,',');
        arch >> nota;
        pos = buscarAlumno(codigos,codigo);
        if (nota >= 11) agregarCurso(cursos,nombCur,pos,numDatxAlumno);
        buffExtra = leeCadena(arch,'\n');
    }
}

void agregarCurso (char ***&cursos, char *nombCur, int pos, int *numDatxAlumno) {
    int ind = numDatxAlumno[pos], i;
    char **buffAux;
    buffAux = new char *[ind+2];
    for (i = 0; i < ind; i++) {
        buffAux[i] = cursos[pos][i];
    }
    buffAux[i] = nombCur;
    buffAux[i+1] = nullptr;
    cursos[pos] = buffAux;
    numDatxAlumno[pos]++;
}

int buscarAlumno (int *codigos, int codigo) {
    for (int i = 0; codigos[i] != -1; i++) {
        if (codigos[i] == codigo) return i;
    }
}
void imprimirReporte(int *codigos, char **nombres, char ***cursos) {
    ofstream arch = abrirArchE("ReporteFinal.txt");
    for (int i = 0; codigos[i] != -1; i++) {
        arch << "Codigo:" << setw(10) << " ";
        arch.fill('0');
        arch << setw(8) << codigos[i];
        arch.fill(' ');
        arch << "    Nombre:  " <<  left << nombres[i] << right << endl;
        imprimeLinea('-',125,arch);
        arch << "Cursos aprobados: ";
        for (int j = 0; cursos[i][j]; j++) {
            arch << cursos[i][j] << " ";
        }
        arch << endl << endl;
    }
}

/* funciones auxiliares */

void imprimeLinea (char car, int num, ofstream &arch) {
    for (int i = 0; i < num; i++) arch.put(car);
    arch << endl;
}

ifstream abrirArchL (const char *nombre) {
    ifstream arch;
    arch.open(nombre, ios::in);
    if (!arch) {
        cout << "ERROR: no se pudo abrir el archivo " << nombre << endl;
        exit(1);
    }
    return arch;
} 

ofstream abrirArchE (const char *nombre) {
    ofstream arch;
    arch.open(nombre, ios::out);
    if (!arch) {
        cout << "ERROR: no se pudo abrir el archivo " << nombre << endl;
        exit(1);
    }
    return arch;
} 
