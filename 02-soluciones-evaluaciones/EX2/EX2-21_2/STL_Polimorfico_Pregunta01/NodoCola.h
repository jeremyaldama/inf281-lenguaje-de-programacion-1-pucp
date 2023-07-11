/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoCola.h
 * Author: Danie
 *
 * Created on 8 de julio de 2023, 22:31
 */

#ifndef NODOCOLA_H
#define NODOCOLA_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class NodoCola {
public:
    NodoCola();
    NodoCola(const NodoCola& orig);
    virtual ~NodoCola();
    
    void leer(ifstream&arch);
    void setCarne(int carne);
    int getCarne() const;
    void setLibsol(const char* libsol);
    void getLibsol(char*) const;
    
    friend class ColaSol;
private:
    char* libsol;
    int carne; // id del usuario que solicita el libro
    class NodoCola *sig;
};

#endif /* NODOCOLA_H */

