/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   medico.h
 * Author: Danie
 *
 * Created on 9 de junio de 2023, 0:24
 */
#include <fstream>
using namespace std;

#ifndef MEDICO_H
#define MEDICO_H

class medico {
private:
    int codigo;
    char *nombre;
    double tarifa;
public:
    medico();
    medico(const medico& orig);
    virtual ~medico();
    void SetTarifa(double tarifa);
    double GetTarifa() const;
    void SetNombre(char* );
    void GetNombre(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
};

ifstream& operator >> (ifstream&, medico&);
#endif /* MEDICO_H */