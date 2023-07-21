/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pallet.h
 * Author: Danie
 *
 * Created on 17 de junio de 2023, 13:21
 */

#ifndef PALLET_H
#define PALLET_H
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Pallet {
private:
    char *id;
public:
    Pallet();
    virtual ~Pallet();
    void SetId(const char* id);
    void GetId(char*) const;
    void lee(ifstream&);
    virtual void imprime(ofstream&) = 0;
    virtual char tipo(void) = 0;
    virtual int peso(void) = 0;
};

#endif /* PALLET_H */

