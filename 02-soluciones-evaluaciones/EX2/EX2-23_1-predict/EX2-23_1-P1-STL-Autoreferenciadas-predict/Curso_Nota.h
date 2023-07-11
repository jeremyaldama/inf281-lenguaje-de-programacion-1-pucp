/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Curso_Nota.h
 * Author: Danie
 *
 * Created on 9 de julio de 2023, 23:33
 */

#ifndef CURSO_NOTA_H
#define CURSO_NOTA_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class Curso_Nota {
public:
    Curso_Nota();
    Curso_Nota(const Curso_Nota& orig);
    virtual ~Curso_Nota();
    void SetCostoCurso(double costoCurso);
    double GetCostoCurso() const;
    void SetVeces(int veces);
    int GetVeces() const;
    void SetUltimoSemestre(int ultimoSemestre);
    int GetUltimoSemestre() const;
    void SetUltimaNota(int ultimaNota);
    int GetUltimaNota() const;
    void SetCodCurso(const char* codCurso);
    void GetCodCurso(char* ) const;
    
    void leerCursoNota(ifstream&arch);
    void imprimirCurso(ofstream&arch);
    void operator=(const Curso_Nota&cursoNota);
    // para el sort
    bool operator<(const Curso_Nota&curNota);
private:
    char* codCurso;
    int ultimaNota;
    int ultimoSemestre;
    int veces;
    double costoCurso;
};

#endif /* CURSO_NOTA_H */

