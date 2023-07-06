/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   alumno.h
 * Author: Danie
 *
 * Created on 11 de junio de 2023, 12:23
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include "nota.h"

class alumno {
public:
    alumno();
    alumno(const alumno& orig);
    virtual ~alumno();
    const class nota* GetLnotas() const;
    void SetNumtercera(int numtercera);
    int GetNumtercera() const;
    void SetNumsegunda(int numsegunda);
    int GetNumsegunda() const;
    void SetNumprimera(int numprimera);
    int GetNumprimera() const;
    void SetNumaprobados(int numaprobados);
    int GetNumaprobados() const;
    void SetNumcursos(int numcursos);
    int GetNumcursos() const;
    void SetNombre(char* nombre);
    void GetNombre(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void operator += (class nota&);
private:
    int codigo;
    char *nombre;
    int numcursos;
    int numaprobados;
    int numprimera;
    int numsegunda;
    int numtercera;
    class nota lnotas[100];
};

ifstream& operator>>(ifstream&, alumno&);
ofstream& operator<<(ofstream&, alumno&);

#endif /* ALUMNO_H */

