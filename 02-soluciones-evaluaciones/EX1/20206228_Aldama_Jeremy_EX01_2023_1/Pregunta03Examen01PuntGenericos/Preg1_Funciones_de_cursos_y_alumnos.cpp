/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// Jeremy Aldama Giraldo 20206228
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include <cstring>
#define INCREMENTO 5
#include "Preg1_Funciones_de_cursos_y_alumnos.h"

void cargarCursosYEscalas(char***&cursos, double*&cursos_cred, double*escalas,
        const char*nom_cur, const char*nom_esc) {
    ifstream arch_cur(nom_cur, ios::in);
    if (!arch_cur) {
        cout << "NO SE PUDO ABRIR Cursos.csv";
        exit(1);
    }
    ifstream arch_esc(nom_esc, ios::in);
    if (!arch_esc) {
        cout << "NO SE PUDO ABRIR Escalas.csv";
        exit(1);
    }

    char cod_cur[20], nombre_cur[100], nombre_prof[100], c;
    double creditos;
    int cod_prof, num_cur = 0, cap_cur = 0;
    cursos = nullptr;
    while (1) {
        arch_cur.getline(cod_cur, 20, ',');
        if (arch_cur.eof()) break;
        arch_cur.getline(nombre_cur, 100, ',');
        arch_cur >> creditos >> c >> cod_prof >> c;
        arch_cur.getline(nombre_prof, 100);
        if (num_cur == cap_cur) {
            IncrementarCursos(cursos, cursos_cred, num_cur, cap_cur);
        }
        cursos[num_cur - 1] = new char*[3];
        char**cur = cursos[num_cur - 1];
        cur[0] = new char[strlen(cod_cur) + 1];
        strcpy(cur[0], cod_cur);
        cur[1] = new char[strlen(nombre_cur) + 1];
        strcpy(cur[1], nombre_cur);
        cur[2] = new char[strlen(nombre_prof) + 1];
        strcpy(cur[2], nombre_prof);
        cursos_cred[num_cur - 1] = creditos;
        num_cur++;
    }
    LeerEscalas(arch_esc, escalas);
}

void LeerEscalas(ifstream&arch, double*escalas) {
    int n, i = 0;
    char c;
    while (1) {
        arch >> c;
        if (arch.eof()) break;
        arch >> n >> c;
        arch >> escalas[i];
    }
}

void IncrementarCursos(char***&cursos, double*&cursos_cred, int&num,
        int&cap) {
    cap += INCREMENTO;
    if (cursos == nullptr) {
        cursos = new char**[cap] {
        };
        cursos_cred = new double[cap] {
        };
        num = 1;
    } else {
        char***aux = new char**[cap] {
        };
        double*aux2 = new double[cap] {
        };
        for (int i = 0; cursos[i]; i++) {
            aux[i] = cursos[i];
            aux2[i] = cursos_cred[i];
        }
        delete cursos;
        delete cursos_cred;
        cursos = aux;
        cursos_cred = aux2;
    }
}

void pruebaDeCargaDeCursos(char***cursos, double*cursos_cred, const char*nom) {
    ofstream arch(nom, ios::out);
    if (!arch) {
        cout << "NO SE PUDO ABRIR PruebaCursos.txt";
        exit(1);
    }
    arch << left << setw(10) << "CODIGO" << setw(60) << "NOMBRE" << setw(60) <<
            "PROFESOR" << "CREDITOS" << endl;
    for (int i = 0; cursos[i]; i++) {
        arch << setw(10) << cursos[i][0] << setw(60) << cursos[i][1] << setw(60)
                << cursos[i][2] << cursos_cred[i] << endl;
    }
}

void cargarAlumnos(int*&alumnos_cod, const char*nom) {
    ifstream arch(nom, ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR Alumnos.csv";
        exit(1);
    }
    int cod, porcentaje, escala, num=0, cap=0;
    char nombre[100], c, mod;
    alumnos_cod = nullptr;
    while (1){
        arch >> cod;
        if (arch.eof()) break;
        arch >> c;
        arch.getline(nombre, 100, ',');
        arch >> c;
        porcentaje = 0;
        // PRESENCIAL
        if (c == 'G'){
            arch >> escala;
            mod = 'P';
        }
        else if (c == 'V'){
            arch >> c >> c >> escala;
            mod = 'V';
        }
        else{
            arch >> c >> porcentaje >> c >> c >> escala;
            mod = 'S';
        }
        
        if (num == cap){
            IncrementarAlumnos(alumnos_cod,
                    num, cap);
        }
        
        AgregarAlumnos(alumnos_cod, cod, num-1);
        num++;
    }
}

void AgregarAlumnos(int*alumnos_cod,
        int cod, int i){
    alumnos_cod[i] = cod;
    
//    if (mod != 'S') alumnos[i] = new int[2];
//    else alumnos[i] = new int[3];
//    int*alumno = alumnos[i];
//    alumno[0] = cod;
//    alumno[1] = escala;
//    if (mod == 'S') alumno[2] = porcentaje;
//    
//    alumnos_nom_mod[i] = new char*[2];
//    char**al = alumnos_nom_mod[i];
//    al[0] = new char[strlen(nombre)+1];
//    strcpy(al[0], nombre);
//    al[1] = new char[2]{mod};
}

void IncrementarAlumnos(int*&alumnos_cod,
                    int&num, int&cap){
    cap += INCREMENTO;
    if (alumnos_cod == nullptr){
        alumnos_cod = new int[cap]{};
//        alumnos = new int*[cap]{};
//        alumnos_nom_mod = new char **[cap]{};
        num = 1;
    } else {
        int *aux = new int[cap]{};
//        int **aux2 = new int*[cap]{};
//        char ***aux3 = new char**[cap]{};
        for (int i=0; alumnos_cod[i]; i++){
            aux[i] = alumnos_cod[i];
//            aux2[i] = alumnos[i];
//            aux3[i] = alumnos_nom_mod[i];
        }
        delete alumnos_cod;
//        delete alumnos;
//        delete alumnos_nom_mod;
        alumnos_cod = aux;
//        alumnos = aux2;
//        alumnos_nom_mod = aux3;
    }
}

void pruebaDeCargaDeAlumnos(int*alumnos_cod, int**alumnos,
        char***alumnos_nom_mod, const char*nom) {
    ofstream arch(nom, ios::out);
    if (!arch) {
        cout << "NO SE PUDO ABRIR PruebaAlumnos.txt";
        exit(1);
    }
    arch << left << setw(12) << "CODIGO 1" << setw(12) << "CODIGO 2" <<
            setw(10) << "ESCALA"  << setw(60) <<
            "NOMBRE" << setw(12) << "MODALIDAD"  << "PORCENTAJE" << endl;
    for (int i=0; alumnos[i]; i++){
        arch << setw(12) << alumnos_cod[i] << setw(12) << alumnos[i][0] <<
                setw(10) << alumnos[i][1];
        arch << setw(60) << alumnos_nom_mod[i][0] << setw(12) <<
                alumnos_nom_mod[i][1];
        if (alumnos_nom_mod[i][1][0]=='S'){
            arch << alumnos[i][2] << endl;
        }
        else arch << endl;
    }
}