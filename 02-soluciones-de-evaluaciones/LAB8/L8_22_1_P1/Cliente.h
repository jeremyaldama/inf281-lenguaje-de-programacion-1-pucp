/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Cliente.h
 * Author: Danie
 *
 * Created on 12 de junio de 2023, 22:59
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetNombre(char* nombre);
    void GetNombre(char *) const;
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
private:
    int dni;
    char categoria;
    char *nombre;
};

#endif /* CLIENTE_H */

