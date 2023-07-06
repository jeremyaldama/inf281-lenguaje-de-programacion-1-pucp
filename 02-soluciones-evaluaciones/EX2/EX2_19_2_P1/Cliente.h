/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Cliente.h
 * Author: Danie
 *
 * Created on 14 de junio de 2023, 23:45
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
 
class Cliente {
private:
    int dni;
    char *nombre;
    int hora;
    int minuto;
    int segundo;
    double tTrans;
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetTTrans(double tTrans);
    double GetTTrans() const;
    void SetSegundo(int segundo);
    int GetSegundo() const;
    void SetMinuto(int minuto);
    int GetMinuto() const;
    void SetHora(int hora);
    int GetHora() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetDni(int dni);
    int GetDni() const;
    void operator = (const class Cliente &);
};

void operator <<(ofstream&, const class Cliente&);
void operator >>(ifstream&, class Cliente &);

#endif /* CLIENTE_H */

