/* 
 * Archivo:   FuncionesAuxiliares.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 16 de octubre de 2020, 08:02 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesAuxiliares.h"
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

void leerMedicos (char **&codMed, char **&nombMed, double *&tarifas) {
    ifstream arch = abrirArchL("RelacionMedicos.csv");
    char *cod, *nomb, *esp, *buffCod[100], *buffNomb[100];
    double tar, buffTar[100];
    int numDat = 0;
    while (1) {
        cod = leeCadena(arch,',');
        if (cod == nullptr) break;
        nomb = leeCadena(arch,',');
        esp = leeCadena(arch,',');
        arch >> tar;
        buffCod[numDat] = cod;
        buffNomb[numDat] = nomb;
        buffTar[numDat] = tar;
        numDat++;
        arch.get();
    }
    codMed = new char *[numDat+1];
    nombMed = new char *[numDat];
    tarifas = new double [numDat];
    for (int i = 0; i < numDat ; i++) {
        codMed[i] = buffCod[i];
        nombMed[i] = buffNomb[i];
        tarifas[i] = buffTar[i];
    }
    codMed[numDat] = nullptr;
}

void imprimirMedicos (char **codMed, char **nombMed, double *tarifas) {
    ofstream arch = abrirArchE("ReporteMedicos.txt");
    arch.precision(2); arch << fixed;
    arch << "CODIGO" << setw(35) << "NOMBRE" << setw(25) << "TARIFA" << endl;
    imprimeLinea('=',70,arch);
    for (int i = 0; codMed[i]; i++) {
        arch << codMed[i]
                << setw(5) << " "
                << left << setw(45) << nombMed[i]
                << right << setw(10) << tarifas[i] << endl;
    }
}

void leeAtenciones (char **codMed, int **&codPac, char ***&nombPac, double **&porcPac, 
        int **&veces) {
    ifstream arch = abrirArchL("Pacientes-Atencion.csv");
    char *fecha, tipo, *nomb, car, codM[7];
    double porc;
    int cod, pos, cant, cap[100] = {0}, cantPac[100] = {0}, ind;
    for (cant = 0; codMed[cant] ; cant++);
    codPac = new int *[cant];
    nombPac = new char **[cant];
    porcPac = new double *[cant];
    veces = new int *[cant];
    while (1) {
        fecha = leeCadena(arch,',');
        if (fecha == nullptr) break;
        while (1) {
            arch >> tipo >> car >> cod >> car;
            nomb = leeCadena(arch,',');
            arch >> porc >> car;
            arch.get(codM,7,',');
            if (tipo == 'A') {
                pos = buscarMedico(codMed,codM);
                if (pos != -1) {
                    if (cantPac[pos] == cap[pos]) 
                    incrementarEspacios(codPac[pos],nombPac[pos],porcPac[pos],
                            veces[pos],cantPac,cap,pos);
                    ind = buscarPaciente(codPac[pos],cod,cantPac[pos]);
                    asignarInfoPacientes(codPac[pos],nombPac[pos],porcPac[pos],
                            veces[pos],cod,nomb,porc,pos,ind,cantPac);    
                }
            }
            if (arch.get() == '\n') break;
        }
    }
}

int buscarMedico (char **codMed, char *codM) {
    for (int i = 0; codMed[i] ; i++) {
        if (strcmp(codMed[i],codM) == 0) return i;
    }
    return -1;
}

void incrementarEspacios (int *&codPac, char **&nombPac, double *&porcPac, 
        int *&veces, int *cantPac, int *cap, int pos) {
    char **auxNomb;
    int *auxCod, *auxVez;
    double *auxPorc;
    cap[pos] += INCREMENTO;
    if (cantPac[pos] == 0) {
        codPac = new int [cap[pos]];
        nombPac = new char *[cap[pos]];
        porcPac = new double [cap[pos]];
        veces = new int [cap[pos]];
        codPac[0] = -1;  nombPac[0] = nullptr;
        porcPac[0] = -1; veces[0] = -1;
        cantPac[pos] = 1;
    } else {
        auxCod = new int [cap[pos]];
        auxNomb = new char *[cap[pos]];
        auxPorc = new double [cap[pos]];
        auxVez = new int [cap[pos]];
        for (int i = 0; i < cantPac[pos]; i++) {
            auxCod[i] = codPac[i];  
            auxNomb[i] = nombPac[i];
            auxPorc[i] = porcPac[i]; 
            auxVez[i] = veces[i];
        }
        delete codPac; delete nombPac; delete porcPac; delete veces;
        codPac = auxCod; nombPac = auxNomb; porcPac = auxPorc; veces = auxVez;
    }
}

int buscarPaciente (int *codPac, int cod, int cantPac) {
    for (int i = 0; i < cantPac ; i++) {
        if (codPac[i] == cod) return i;
    }
    return -1;
}

void asignarInfoPacientes (int *&codPac, char **&nombPac, double *&porcPac, 
        int *&veces, int cod, char *nomb, double porc, int pos, int ind, int *cantPac) {
    if (ind == -1) {
        codPac[cantPac[pos]] = -1;
        codPac[cantPac[pos]-1] = cod;
        nombPac[cantPac[pos]] = nullptr;
        nombPac[cantPac[pos]-1] = nomb;
        porcPac[cantPac[pos]] = -1;
        porcPac[cantPac[pos]-1] = porc;
        veces[cantPac[pos]] = -1;
        veces[cantPac[pos]-1] = 1;
        cantPac[pos]++;
    } else {
        veces[ind] += 1;
    }
}

void repDeIngresos (char **codMed, char **nombMed, double *tarifas, int **codPac, 
        char ***nombPac, double **porcPac, int **veces) {
    ifstream arch = abrirArchL("Medicos.csv");
    ofstream archRep = abrirArchE("ReporteDeIngresos.txt");
    archRep.precision(2); archRep << fixed;
    char *codM;
    int ind, cant;
    double montoT, montoS;
    while (1) {
        codM = leeCadena(arch,'\n');
        if (codM == nullptr) break;
        ind = buscarMedico(codMed,codM);
        imprimirCabecera(nombMed[ind],codM,tarifas[ind],archRep);
        montoT = 0; montoS = 0; cant = 0;
        for (int i = 0; codPac[ind][i] != -1 ; i++) {
            archRep << setw(2) << i+1 << ')'
                    << setw(20) << codPac[ind][i]
                    << setw(20) << veces[ind][i]
                    << setw(23) << (porcPac[ind][i]*tarifas[ind]/100)*veces[ind][i]
                    << setw(15) << ((100-porcPac[ind][i])*tarifas[ind]/100)*veces[ind][i] 
                    << endl;
            montoT += (porcPac[ind][i]*tarifas[ind]/100)*veces[ind][i];
            montoS += ((100-porcPac[ind][i])*tarifas[ind]/100)*veces[ind][i];
            cant++;
        }
        imprimeLinea('=',100,archRep);
        archRep << left << setw(40) << "Monto total recibido por pacientes: "
            << montoT << endl
            << setw(40) << "Monto a solicitar al seguro: " << montoS << endl
            << setw(40) << "Total de citas atendidas: " << cant << right << endl;
        imprimeLinea('=',100,archRep);
    }
}

void imprimirCabecera (char *nombMed, char *codM, double tarifa, ofstream &archRep) {
    archRep << "Medico: " << nombMed << endl
            << "Codigo: " << codM << endl
            << "Honorarios por cita: " << tarifa << endl;
        imprimeLinea('=',100,archRep);
        archRep << "Pacientes atendidos:" << endl;
        imprimeLinea('-',100,archRep);
        archRep << "No." << setw(20) << "Paciente" << setw(20) << "Veces"
                << setw(20) << "Pago" << setw(18) << "Seguro" << endl;
}