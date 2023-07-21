/* 
 * Archivo:   Bib_Func_Pacientes.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 10 de octubre de 2020, 07:06 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Bib_Func_Medicos.h"
#include "Bib_Func_Pacientes.h"
using namespace std;

void leerPacientes (char ***&pacientes, double **&gastos, char **especialidad, 
        char ****medicos) {
    ifstream arch = abrirArchL("Consultas.csv");
    char *fecha, *esp, *nomb, *cod, **buffPaciente[200], **infoPac;
    int flag, numDat = 0, pos, n, ind;
    double *gasto, tar, *buffGasto[200];
    for (n = 0; especialidad[n]; n++);
    while (1) {
        fecha = leeCadena(arch,',');
        if (fecha == nullptr) break;
        esp = leeCadena(arch,','); 
        tar = buscarTarifa(esp,medicos,ind);
        while (1) {
            nomb = leeCadena(arch,',');
            cod = leeCadenaEnd(arch,',',flag);
            pos = buscarPaciente(cod,buffPaciente,numDat);         
            if (pos == -1) {
                infoPac = new char *[2]; gasto = new double [n];
                infoPac[0] = cod; infoPac[1] = nomb; 
                for (int i = 0; i < n; i++) gasto[i] = 0;
                gasto[ind] += tar; 
                buffPaciente[numDat] = infoPac; buffGasto[numDat] = gasto;
                numDat++;
            } else buffGasto[pos][ind] += tar;
            if (flag) break;
        }
    }
    pacientes = new char **[numDat+1];
    gastos = new double *[numDat];
    for (int i = 0; i < numDat; i++) {
        pacientes[i] = buffPaciente[i];
        gastos[i] = buffGasto[i];
    }
    pacientes[numDat] = nullptr;
}

void imprimirPacientes (char ***pacientes, double **gastos, char **especialidad) {
    ofstream arch = abrirArchE("ReportePacientes.txt");
    arch.precision(2); arch << fixed;
    arch << setw(50) << "INSTITUTO DE SALUD" << endl 
            << setw(60) << "REGISTRO DE GASTOS MEDICOS POR PACIENTE" << endl;
    for (int i = 0; pacientes[i]; i++) {
        imprimeLinea('=',90,arch);
        arch << setw(15) << "PACIENTE: "
                << left << setw(40) << pacientes[i][1]
                << right << setw(20) << "CODIGO: "
                <<  pacientes[i][0] << endl;
        imprimeLinea('-',90,arch);
        arch << setw(15) << "ESPECIALIDAD"
                << setw(70) << "MONTO GASTADO" << endl;
        for (int j = 0; especialidad[j]; j++) {
            arch << setw(3) << " " << left << setw(25) << especialidad[j]
                    << right << setw(55) << gastos[i][j] << endl;
        }
    }
}

char *leeCadenaEnd (ifstream &arch, char car, int &flag) {
    char buff[100], *cad;
    int i = 0;
    flag = 0;
    while (1) {
        buff[i] = arch.get();
        if (buff[i] == car) break;
        if (buff[i] == '\n') {
            flag = 1;
            break;
        }
        i++;
    }
    buff[i] = '\0';
    cad = asignaCadenaExacta(buff);
    return cad;
}

int buscarPaciente (char *cod, char ***buffPaciente, int cant) {
    for (int i = 0; i < cant; i++) {
        if (strcmp(cod,buffPaciente[i][0]) == 0) return i;
    }
    return -1;
}

double buscarTarifa (char *esp, char ****medicos, int &ind) {
    for (int i = 0; medicos[i]; i++) {
        for (int j = 0; medicos[i][j]; j++) {
            if (strcmp(esp,medicos[i][j][0]) == 0) {
                ind = i;
                return atof(medicos[i][j][2]);
            }
        }
    }
    ind = -1;
    return -1;
}