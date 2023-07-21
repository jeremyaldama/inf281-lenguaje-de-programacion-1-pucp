/* 
 * Archivo:   FuncionesAuxiliares.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 27 de noviembre de 2020, 09:05 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Medico.h"
#include "Paciente.h"
#include "FuncionesAuxiliares.h"
using namespace std;

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

void llenarMedicos (Medico *medico, ifstream &arch, int &cant) {
    while (1) {
        arch >> medico[cant];
        if (arch.eof()) break;
        cant++;
    }
}

void imprimirMedicos (Medico *medico, ofstream &arch, int cant) {
    for (int i = 0; i < cant; i++) {
        arch << medico[i];
    }
}

void leerPacientes (Medico *medico, ifstream &arch, int cant) {
    class Paciente paciente;
    char codMed[10], car;
    int pos, dd, mm, aa, f;
    while (1) {
        arch >> dd;
        if (arch.eof()) break;
        arch >> car >> mm >> car >> aa; 
        f = aa*10000+mm*100+dd;
        while (arch.get() != '\n') {
            arch >> paciente >> codMed;
            paciente.SetFecha(f);
            pos = buscarMedico(medico,codMed,cant);
            if (pos != -1) medico[pos]+paciente; 
        }                  
    }
}

int buscarMedico (Medico *medico, char *codMed, int cant) {   
    for (int i = 0; i < cant; i++) {
        char codigo[10];
        medico[i].GetCodigo(codigo);
        if (strcmp(codigo,codMed) == 0) return i;
    }
    return -1;
}

void leerOperaciones (Medico *medico, ifstream &arch, int cant) {
    int op, pos, dd, mm, aa, f, ind;
    char car, codMed[10], nomb[50];
    ofstream archRepIm = abrirArchE("ReporteImpresion.txt");
    archRepIm.precision(2); archRepIm << fixed;  
    while (1) {
        arch >> op;
        if (arch.eof()) break;                  
        if (op == 1 || op == 2) {
            arch >> codMed;
            pos = buscarMedico(medico,codMed,cant);
            while (arch.get() != '\n') {
                arch >> dd >> car >> mm >> car >> aa; 
                f = aa*10000+mm*100+dd;
                if (pos != -1) {
                    if (op == 1) medico[pos]*f;
                    else medico[pos]-f;
                }
            }
        } else {
            while (arch.get() != '\n') {
                arch >> codMed;
                pos = buscarMedico(medico,codMed,cant);
                if (pos != -1) {
                    if (op == 3) ++medico[pos];      
                    else archRepIm << medico[pos];
                }
            }
        }
    }
}