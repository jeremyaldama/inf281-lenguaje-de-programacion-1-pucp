/* 
 * Archivo:   Bib_Func_Medicos.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 10 de octubre de 2020, 01:09 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Bib_Func_Medicos.h"
#define INCREMENTO 5
using namespace std;

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

char * leeCadena (ifstream &arch, char car) {
    char buff[200], *cad;
    arch.getline(buff,200,car);
    if (arch.eof()) return nullptr;
    cad = new char [strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

char * asignaCadenaExacta (char *cadena){
    int len;
    char *cad;
    len = strlen(cadena);
    cad = new char[len+1];
    strcpy(cad,cadena);
    return cad;
}

void leerMedicos (char **&especialidad, char ****&medicos) {
    ifstream arch = abrirArchL("Medicos.csv");
    char *esp, *cod, *nomb, *ap, *cad, *monto, *buffCod[100], *buffEsp[100], 
            *tarifa[100], *nombComp, ***buffMed[100], ***infoMed;
    int numDat = 0, pos, cantMed[100] = {0}, cap[100] = {0};
    while (1) {
        cod = leeCadena(arch,',');
        if (cod == nullptr) break;
        ap = leeCadena(arch,',');        
        nomb = leeCadena(arch,',');     
        nombComp = concantenar(nomb,ap);
        esp = leeCadena(arch,',');
        monto = leeCadena(arch,'\n');
        pos = buscarEspecialidad(esp,buffEsp,numDat);
        if (pos == -1) {
            buffEsp[numDat] = esp;
            AsignarInfoDelMedico(cod,nombComp,monto,cantMed,cap,numDat,buffMed);
            numDat++; 
        } else AsignarInfoDelMedico(cod,nombComp,monto,cantMed,cap,pos,buffMed);       
    } 
    especialidad = new char *[numDat+1];
    medicos = new char ***[numDat];
    for (int i = 0; i < numDat; i++) {
        especialidad[i] = buffEsp[i];
        medicos[i] = buffMed[i];
    }
    especialidad[numDat] = nullptr;  
}

void imprimirMedicos (char **especialidad, char ****medicos) {
    ofstream arch = abrirArchE("ReporteMedicos.txt");
    arch.precision(2); arch << fixed;
    arch << setw(60) << "INSTITUTO DE SALUD" << endl 
            << setw(60) << "PERSONAL MEDICO" << endl;
    for (int i = 0; especialidad[i]; i++) {
        imprimeLinea('=',100,arch);
        arch << "ESPECIALIDAD: " << especialidad[i] << endl;
        imprimeLinea('-',100,arch);
        arch << setw(25) << "MEDICO"
                << setw(50) << "TARIFA" << endl;
        imprimeLinea('-',100,arch);
        for (int j = 0; medicos[i][j]; j++) {
            arch << setw(2) << j+1 
                    << setw(10) << medicos[i][j][0]
                    << setw(5) << " "
                    << left << setw(50) << medicos[i][j][1]
                    << right << setw(10) << atof(medicos[i][j][2]) << endl;
        }
    }
}

char * concantenar (char *cad1, char *cad2) {
    char *dest, buff[200] = "\0";
    strcat(buff,cad1);
    strcat(buff," ");
    strcat(buff,cad2);
    dest = asignaCadenaExacta(buff);
    return dest;
}

int buscarEspecialidad (char *esp, char **buffEsp, int cant) {
    for (int i = 0; i < cant; i++) {
        if (strcmp(esp,buffEsp[i]) == 0) return i;
    }
    return -1;
}

void AsignarInfoDelMedico (char *cod, char *nombComp, char *monto, 
        int *cantMed, int *cap, int pos, char ****buffMed) {
    char **arrDef, ***infoMed;
    infoMed = nullptr;
    arrDef = new char *[3];
    arrDef[0] = cod;
    arrDef[1] = nombComp;
    arrDef[2] = monto;
    if (cantMed[pos] > 0) infoMed = buffMed[pos];
    if (cantMed[pos] == cap[pos]) incrementarEspacios(infoMed,cantMed,cap,pos);
    infoMed[cantMed[pos]] = nullptr;      
    infoMed[cantMed[pos]-1] = arrDef; 
    cantMed[pos]++;
    buffMed[pos] = infoMed;
}

void incrementarEspacios (char ***&infoMed, int *cantMed, int *cap, int pos) {
    char ***aux;
    cap[pos] += INCREMENTO;
    if (infoMed == nullptr) {
        infoMed = new char **[cap[pos]];
        infoMed[0] = nullptr;
        cantMed[pos] = 1;
    } else {
        aux = new char **[cap[pos]];
        for (int i = 0; i < cantMed[pos]; i++) aux[i] = infoMed[i];
        delete infoMed;
        infoMed = aux;    
    }
}