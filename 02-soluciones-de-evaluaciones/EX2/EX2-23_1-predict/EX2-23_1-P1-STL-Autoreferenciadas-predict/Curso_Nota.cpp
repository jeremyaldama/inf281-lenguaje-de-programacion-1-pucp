/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso_Nota.cpp
 * Author: Danie
 * 
 * Created on 9 de julio de 2023, 23:33
 */

#include "Curso_Nota.h"

Curso_Nota::Curso_Nota() {
    codCurso =nullptr;
    veces = 0;
}

Curso_Nota::Curso_Nota(const Curso_Nota& orig) {
    codCurso = nullptr;
    *this = orig;
}

Curso_Nota::~Curso_Nota() {
    cout << "ELIMINA CURSO-NOTA" << endl;
    if (codCurso) delete codCurso;
}

void Curso_Nota::SetCostoCurso(double costoCurso) {
    this->costoCurso = costoCurso;
}

double Curso_Nota::GetCostoCurso() const {
    return costoCurso;
}

void Curso_Nota::SetVeces(int veces) {
    this->veces = veces;
}

int Curso_Nota::GetVeces() const {
    return veces;
}

void Curso_Nota::SetUltimoSemestre(int ultimoSemestre) {
    this->ultimoSemestre = ultimoSemestre;
}

int Curso_Nota::GetUltimoSemestre() const {
    return ultimoSemestre;
}

void Curso_Nota::SetUltimaNota(int ultimaNota) {
    this->ultimaNota = ultimaNota;
}

int Curso_Nota::GetUltimaNota() const {
    return ultimaNota;
}

void Curso_Nota::SetCodCurso(const char* cad) {
    if (codCurso) delete codCurso;
    codCurso = new char[strlen(cad)+1];
    strcpy(codCurso, cad); 
}

void Curso_Nota::GetCodCurso(char *cad) const {
    if (codCurso) strcpy(cad, codCurso);
    else cad[0] = 0;
}

void Curso_Nota::leerCursoNota(ifstream& arch) {
    char c, cad[100];
    arch.getline(cad, 100, ',');
    SetCodCurso(cad);
    arch >> ultimoSemestre >> c >> ultimaNota;
    veces = 1;
}

void Curso_Nota::operator=(const Curso_Nota& cursoNota) {
    SetCodCurso(cursoNota.codCurso);
    ultimaNota = cursoNota.ultimaNota;
    ultimoSemestre =  cursoNota.ultimoSemestre;
    veces = cursoNota.veces;
    costoCurso = cursoNota.costoCurso;
}

void Curso_Nota::imprimirCurso(ofstream& arch) {
    arch << left << setw(12) << codCurso << setw(8) << ultimaNota << setw(8) <<
            ultimoSemestre << setw(8) << veces << costoCurso << endl;
}

bool Curso_Nota::operator<(const Curso_Nota& curNota) {
    return (ultimaNota < curNota.ultimaNota || 
            (ultimaNota == curNota.ultimaNota) && 
            (ultimoSemestre < curNota.ultimoSemestre));
}
