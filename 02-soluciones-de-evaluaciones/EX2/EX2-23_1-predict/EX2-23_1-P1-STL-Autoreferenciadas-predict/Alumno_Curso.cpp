/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno_Curso.cpp
 * Author: Danie
 * 
 * Created on 9 de julio de 2023, 23:31
 */

#include <algorithm>

#include "Alumno_Curso.h"

Alumno_Curso::Alumno_Curso() {
    totalGastado = 0.0;
}

Alumno_Curso::~Alumno_Curso() {
    cout << "ELIMINA ALUMNO-CURSO" << endl;
}


void Alumno_Curso::leerAlumno(ifstream& arch) {
    alumno.leer(arch);
}

void Alumno_Curso::obtenerNombre(char* cad) {
    char nom[100];
    alumno.GetNombre(nom);
    strcpy(cad, nom);
}

void Alumno_Curso::imprimirAlumno(ofstream& arch) {
    alumno.imprimir(arch);
    sort(cursos.begin(), cursos.end());
    for (int i = 0; i < cursos.size(); i++) {
        cursos[i].imprimirCurso(arch);
    }
    arch << "TOTAL GASTADO: " << totalGastado << endl;
    arch << endl;
}

//void Alumno_Curso::operator=(const Alumno_Curso& alu_cur) {
//    // si no ponemos este operador por defecto va a ir a la copia del alumno
//    // no es necesario
//    cout << "COPIA DE ALUMNO_CURSO" << endl;
//    alumno = alu_cur.alumno;
//}

int Alumno_Curso::obtenerCodigoAlumno() {
    return alumno.GetCodigo();
}

void Alumno_Curso::leerCursoDelAlumno(ifstream& arch) {
    Curso_Nota cursoNota;
    cursoNota.leerCursoNota(arch);
    char codCur[100], codCurLeido[100];
    cursoNota.GetCodCurso(codCurLeido);
    for (int i = 0; i < cursos.size(); i++) {
        cursos[i].GetCodCurso(codCur);
        if (strcmp(codCur, codCurLeido) == 0) {
            // FALTA COSTO DEL CURSO
            if (cursos[i].GetUltimoSemestre() < cursoNota.GetUltimoSemestre()) {
                cursos[i].SetUltimaNota(cursoNota.GetUltimaNota());
                cursos[i].SetUltimoSemestre(cursoNota.GetUltimoSemestre());
            }
            cursos[i].SetVeces(cursos[i].GetVeces() + 1);
            return;
        }
    }
    cursos.push_back(cursoNota);
}

void Alumno_Curso::actualizarCostos(const vector<Curso>& cursosVec, 
        double precio) {
    char cad[100];
    double creditos, total;
    for (int i=0; i<cursos.size(); i++) {
        cursos[i].GetCodCurso(cad);
        creditos = buscarCreditosCurso(cursosVec, cad);
        total = cursos[i].GetVeces()*creditos*precio;
        cursos[i].SetCostoCurso(total);
        totalGastado += total;
    }
}

double Alumno_Curso::buscarCreditosCurso(const vector<Curso>& cursos, 
        const char*cad) {
    char codigo[100];
    for (int i=0; i<cursos.size(); i++) {
        cursos[i].GetCodigo(codigo);
        if (strcmp(codigo, cad)==0) return cursos[i].GetCreditos();
    }
}

int Alumno_Curso::obtenerEscalaAlumno() {
    return alumno.GetEscala();
}
