/* 
 * Archivo:   Laboratorio04_Funciones.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 9 de octubre de 2020, 08:01 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Laboratorio04_Funciones.h"
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

void cargarMedicos (char **&codigoMed, char **&medicos, double *&tarifas) {
    ifstream arch = abrirArchL("RelacionMedicos.csv");
    char *buffNomb[100], *buffCod[100], *nomb, *cod, *esp;
    double monto, tarifa[100];
    int numDat = 0;
    while (1) {
        cod = leeCadena(arch,',');
        if (cod == nullptr) break;
        nomb = leeCadena(arch,',');
        esp = leeCadena(arch,',');
        arch >> monto;
        arch.get();
        buffCod[numDat] = cod;
        buffNomb[numDat] = nomb;
        tarifa[numDat] = monto;
        numDat++;
    }
    codigoMed = new char *[numDat+1];
    medicos = new char *[numDat];
    tarifas = new double[numDat];
    for (int i = 0; i < numDat; i++) {
        codigoMed[i] = buffCod[i];
        medicos[i] = buffNomb[i];
        tarifas[i] = tarifa[i];
    }
    codigoMed[numDat] = nullptr;
}

void reporteMedicos(char **codigoMed, char **medicos, double *tarifas) {
    ofstream arch = abrirArchE("ReporteMedicos.txt");
    arch.precision(2); arch << fixed;
    arch << "CODIGO" << setw(35) << "NOMBRE" << setw(25) << "TARIFA" << endl;
    imprimeLinea('=',70,arch);
    for (int i = 0; codigoMed[i]; i++) {
        arch << codigoMed[i]
                << setw(5) << " "
                << left << setw(45) << medicos[i]
                << right << setw(10) << tarifas[i] << endl;
    }
}

void reporteDeIngresos (char **codigoMed, char **medicos, double *tarifas) { 
    ifstream archMed = abrirArchL("Medicos.csv");
    ofstream archRep = abrirArchE("ReporteFinal.txt");
    archRep.precision(2); archRep << fixed;
    int *codigoPac, *veces;
    char **pacientes, codMed[7];
    double *porcentajes;
    while (1) {
        archMed >> codMed;
        if (archMed.eof()) break;
        cargarPacientes(codMed,codigoPac,pacientes,porcentajes,veces);
        reporteDelMedico(codMed,codigoMed,medicos,tarifas,codigoPac,pacientes,
                porcentajes,veces,archRep);
        liberarEspacios(codigoPac,pacientes,porcentajes,veces);
    }
}

void cargarPacientes (char *codMed, int *&codigoPac, char **&pacientes, 
        double *&porcentajes, int *&veces) {
    ifstream arch = abrirArchL("Pacientes-Atencion.csv");
    char *fecha, estado, car, *buffPac[200], *nomb, *aux;
    int codPac[200], rep[200] = {0}, codigo;
    int numDat = 0, flag;
    double porc, porcen[200];
    while (1) {
        fecha = leeCadena(arch,',');
        if (fecha == nullptr) break;
        while (1) {
            arch >> estado >> car >> codigo >> car;
            nomb = leeCadena(arch,',');
            arch >> porc >> car;
            aux = leeMedico(arch,',',flag);
            if (estado == 'A') {
                if (!esta(codigo,codPac,numDat) && strcmp(codMed,aux) == 0) {
                    codPac[numDat] = codigo;
                    buffPac[numDat] = nomb;
                    porcen[numDat] = porc;
                    rep[numDat]++;
                    numDat++;
                } else if (esta(codigo,codPac,numDat) && strcmp(codMed,aux) == 0)
                    rep[numDat]++;     
            }
            if (flag) break;
        }
    }
    codigoPac = new int [numDat+1];
    pacientes = new char * [numDat];
    porcentajes = new double [numDat];
    veces = new int [numDat];
    for (int i = 0; i < numDat; i++) {
        codigoPac[i] = codPac[i];
        pacientes[i] = buffPac[i];
        porcentajes[i] = porcen[i];
        veces[i] = rep[i];
    }
    codigoPac[numDat] = -1;
}

int esta (int codigo, int *codPac, int num) {
    for (int i = 0; i < num; i++) {
        if (codigo == codPac[i]) return 1;
    }
    return 0;
}

char * leeMedico(ifstream &arch, char car, int &flag) {
    int i = 0, len;
    char buff[10], *cad, carr;
    flag = 0;
    while (1) {   
        carr = arch.get();
        if (carr == car || carr == '\n') {
            if (carr == '\n') flag = 1;
            break;
        } else arch.unget();
        buff[i] = arch.get();
        i++;
    }
    buff[i] = '\0';
    len = strlen(buff);
    cad = new char[len+1];
    strcpy(cad,buff);
    return cad;
}

void reporteDelMedico (char *codMed, char **codigoMed, char **medicos, double *tarifas,
        int *codigoPac, char **pacientes, double *porcentajes, int *veces,
        ofstream &arch) {
    char *nomb;
    int cant = 0;
    double tarifa, montoT = 0, montoS = 0;
    nomb = buscarMedico(codMed,codigoMed,medicos);
    tarifa = buscarTarifa(codMed,codigoMed,tarifas);
    arch << "Medico: " << nomb << endl
            << "Codigo: " << codMed << endl
            << "Honorarios por cita: " << tarifa << endl;
    imprimeLinea('=',100,arch);
    arch << "Pacientes atendidos:" << endl;
    imprimeLinea('-',100,arch);
    arch << "No." << setw(20) << "Paciente" << setw(20) << "Pago"
            << setw(20) << "Seguro" << setw(15) << "Veces" << endl;
    for (int i = 0; codigoPac[i] != -1; i++) {
        arch << setw(2) << i+1 << ')'
                << setw(15) << codigoPac[i]
                << setw(25) << (porcentajes[i]*tarifa/100)*veces[i]
                << setw(20) << ((100-porcentajes[i])*tarifa/100)*veces[i]
                << setw(15) << veces[i] << endl;
        montoT += (porcentajes[i]*tarifa/100)*veces[i];
        montoS += ((100-porcentajes[i])*tarifa/100)*veces[i];
        cant++;
    }
    imprimeLinea('=',100,arch);
    arch << left << setw(40) << "Monto total recibido por pacientes: "
            << montoT << endl
            << setw(40) << "Monto a solicitar al seguro: " << montoS << endl
            << setw(40) << "Total de citas atendidas: " << cant << right << endl;
    imprimeLinea('=',100,arch);
}

char * buscarMedico (char *codMed, char **codigoMed, char **medicos) {
    for (int i = 0; codigoMed[i]; i++) {
        if (strcmp(codMed,codigoMed[i]) == 0) return medicos[i];
    }
}

double buscarTarifa (char *codMed, char **codigoMed, double *tarifas) {
    for (int i = 0; codigoMed[i]; i++) {
        if (strcmp(codMed,codigoMed[i]) == 0) return tarifas[i];
    }
}

void liberarEspacios (int *&codigoPac, char **&pacientes, double *&porcentajes, int *&veces) {
    delete codigoPac;
    delete pacientes;
    delete porcentajes;
    delete veces;
}