/* 
 * File:   Funciones.cpp
 * Author: Jeremy Aldama 20206228
 * 
 * Created on 11 de junio de 2023, 13:43
 */

#include <iostream>
#include <iomanip>
#include "Funciones.h"

using namespace std;

void cargaralumnos(alumno *lalumnos) {
    ifstream arch("Alumnos.csv", ios::in);
    int i = 0;
    while (1) {
        arch >> lalumnos[i];
        if (arch.eof()) break;
        cout << lalumnos[i].GetCodigo() << endl;
        i++;
    }
}

void carganotas(alumnonota* lnotas) {
    ifstream arch("Notas.csv", ios::in);

    int i = 0;
    while (1) {
        arch >> lnotas[i];
        if (arch.eof()) break;
        cout << lnotas[i].GetCiclo() << endl;
        i++;
    }
}

void actualizanotas(alumno *lalumnos, alumnonota *lnotas) {
    nota grade;
    int ind_alumno;

    for (int i = 0; lnotas[i].GetCodigo(); i++) {
        ind_alumno = BuscarAlumno(lalumnos, lnotas[i].GetCodigo());
        if (ind_alumno != -1) {
            //            if (lalumnos[ind_alumno].GetCodigo() == 202123703) {
            cout << "NOTA PASADA " << endl;
            lnotas[i] & grade;
            cout << "CICLO: " << grade.GetCiclo() << " " << grade.GetNota() << "  ";
            char a[100];
            grade.GetCodcurso(a);
            cout << a << endl;
            lalumnos[ind_alumno] += grade;
            //            }

            ActualizarAtributosAprobacion(grade, lalumnos[ind_alumno]);
        }
    }

}

void ActualizarAtributosAprobacion(class nota &grade, alumno& al) {
    const nota *notas = al.GetLnotas();
    int num_veces = BuscarVecesCurso(grade, notas);
    
    
    al.SetNumcursos(al.GetNumcursos() + 1);
    if (grade.GetNota() >= 11) {
        al.SetNumaprobados(al.GetNumaprobados() + 1);
    } else {

    }
}

int BuscarVecesCurso(class nota &grade, const nota *notas) {
    char n[100];
    grade.GetCodcurso(n);
    char n2[100];
    int num = 0;
    for (int i=0; notas[i].GetCiclo(); i++) {
        notas[i].GetCodcurso(n2);
        if (strcmp(n2, n)==0) num++;
    }
    return num;
}

int BuscarAlumno(alumno*lalumnos, int codigo) {
    for (int i = 0; lalumnos[i].GetCodigo(); i++)
        if (lalumnos[i].GetCodigo() == codigo) return i;
    return -1;
}

void imprimealumnos(alumno*lalumnos) {
    ofstream arch("ReporteAlumnos.txt", ios::out);
    for (int i = 0; lalumnos[i].GetCodigo(); i++) {
        arch << lalumnos[i];
    }
}