/* 
 * File:   MetodoDinamicoExacto.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 2 de mayo de 2023, 12:52
 */

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include "MetodoDinamicoExacto.h"
using namespace std;

void lecturaDeMedicos(const char* nomb_arch, int*&med_Codigo,
        char** &med_Nombre, char** &med_Especialidad, double* &med_Tarifa) {
    ifstream arch(nomb_arch, ios::in);
    int i = 0, codigos[100];
    char nombre[500], c, especialidad[100], *nombres[100], *especialidades[100];
    double tarifas[100];

    while (1) {
        arch >> codigos[i];
        if (arch.eof()) break;
        arch >> c;
        // getline extrae ',' pero no lo asigna a cad0
        arch.getline(nombre, 500, ',');
        ObtenerEspecialidad(nombre, especialidad);
        arch >> tarifas[i];

        especialidades[i] = new char[strlen(especialidad) + 1];
        nombres[i] = new char[strlen(nombre) + 1];
        strcpy(especialidades[i], especialidad);
        strcpy(nombres[i], nombre);

        i++;
    }
    med_Codigo = new int[i+1]{};
    med_Nombre = new char*[i+1]{};
    med_Especialidad = new char*[i+1]{};
    med_Tarifa = new double[i]{};
    for (int j = 0; j < i; j++) {
        med_Codigo[j] = codigos[j];
        med_Nombre[j] = nombres[j];
        med_Especialidad[j] = especialidades[j];
        med_Tarifa[j] = tarifas[j];
    }
}

void ObtenerEspecialidad(char*nombre, char*especialidad) {
    char c;
    int flag = 0, j = 0;
    for (int i = 0; nombre[i]; i++) {
        if (flag) {
            especialidad[j] = nombre[i];
            j++;
        }
        c = nombre[i + 2];
        if (c >= 'a' && c <= 'z') {
            nombre[i] = 0;
            flag = 1;
        }
    }
    especialidad[j] = 0;
}

void pruebaDeLecturaDeMedicos(const char *nom_arch, int*med_Codigo,
        char**med_Nombre, char**med_Especialidad, double*med_Tarifa) {
    ofstream arch(nom_arch, ios::out);
    arch << left << setw(15) << "CODIGO" << setw(60) << "NOMBRE" <<
            setw(30) << "ESPECIALIDAD" << "TARIFA" << endl;
    for (int i = 0; med_Nombre[i]; i++) {
        arch << setw(15) << med_Codigo[i] << setw(60) << med_Nombre[i] <<
                setw(30) << med_Especialidad[i] << med_Tarifa[i] << endl;
    }
}

void lecturaDeCitas(const char*nom_arch, int* &pac_Dni, char**&pac_Nombre,
        int**&pac_Citas) {
    ifstream arch(nom_arch, ios::in);
    if (!arch){
        cout << "NO SE PUDO ABRIR CITAS.CSV";
        exit(1);
    }
    int i=0, dnis[500] = {}, *citas[500], dni, i_dni, codigo, dd, mm, aa, fecha;
    char nombre[100], *nombres[500], c;
    
    while (1){
        arch >> dni;
        if (arch.eof()) break;
        arch >> c;
        arch.getline(nombre, 100, ',');
        arch >> codigo >> c >> dd >> c >> mm >> c >> aa;
        fecha = dd + mm*100 + aa*10000;
        i_dni = BuscarIndiceDNI(dnis, dni);
        cout << i_dni << endl;
        // NO ENCONTRADO
        if (i_dni == -1){
            dnis[i] = dni;
            nombres[i] = new char[strlen(nombre)+1];
            strcpy(nombres[i], nombre);
            // max 100 citas
            citas[i] = new int[500]{};
            citas[i][0] = codigo;
            citas[i][1] = fecha;
            i++;
        }
        // ENCONTRADO
        else{
            // buscamos la ultima cita donde se quedo el paciente
            int j;
            for (j=0; citas[i_dni][j]; j+=2);
            citas[i_dni][j] = codigo;
            citas[i_dni][j+1] = fecha;
        }
    }
    pac_Dni = new int[i+1]{};
    pac_Nombre = new char*[i+1];
    pac_Citas = new int*[i+1];
    int j;
    for (int k=0; k<i; k++){
        pac_Dni[k] = dnis[k];
        pac_Nombre[k] = nombres[k];
        
        for (j=0; citas[k][j]; j+=2);
        pac_Citas[k] = new int[j+2]{};
        for (j=0; citas[k][j]; j+=2){
            pac_Citas[k][j] = citas[k][j];
            pac_Citas[k][j+1] = citas[k][j+1];
        }
        delete[] citas[k];
    }
}

int BuscarIndiceDNI(int*dnis, int dni){
    for (int i=0; dnis[i]; i++)
        if (dnis[i] == dni) return i;
    return -1;
}

void pruebaDeLecturaDeCitas(const char*nom_arch, int* pac_Dni, char**pac_Nombre,
        int**pac_Citas) {
    ofstream arch(nom_arch, ios::out);
    for (int i=0; pac_Dni[i]; i++){
        arch << "DNI: " << pac_Dni[i] << endl << "NOMBRE: " << 
                pac_Nombre[i] << endl;
        
        arch << "CITAS: " << endl;
        
        for (int j=0; pac_Citas[i][j]; j+=2){
            arch << setw(10) << " " << setw(10) << pac_Citas[i][j] <<
                    pac_Citas[i][j+1] << endl;
        }
        arch << endl;
    }
}

void reporteDeIngresosMedicosYGastosDeLosPacientes(
        const char*nom_arch, int*med_Codigo,
        char**med_Nombre, char**med_Especialidad, double*med_Tarifa,
        int* pac_Dni, char**pac_Nombre,
        int**pac_Citas) {
    
}