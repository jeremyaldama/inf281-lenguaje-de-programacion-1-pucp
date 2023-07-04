/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Cliente.cpp
 * Author: Danie
 * 
 * Created on 14 de junio de 2023, 23:45
 */

#include <iomanip>

#include "Cliente.h"

Cliente::Cliente() {
    dni = 0;
    nombre = nullptr;
}

Cliente::Cliente(const Cliente& orig) {
//    nombre = nullptr;
    *this = orig;
}

Cliente::~Cliente() {
    if (nombre != nullptr) delete nombre;
}

void Cliente::SetTTrans(double tTrans) {
    this->tTrans = tTrans;
}

double Cliente::GetTTrans() const {
    return tTrans;
}

void Cliente::SetSegundo(int segundo) {
    this->segundo = segundo;
}

int Cliente::GetSegundo() const {
    return segundo;
}

void Cliente::SetMinuto(int minuto) {
    this->minuto = minuto;
}

int Cliente::GetMinuto() const {
    return minuto;
}

void Cliente::SetHora(int hora) {
    this->hora = hora;
}

int Cliente::GetHora() const {
    return hora;
}

void Cliente::SetNombre(const char* n) {
    if (nombre != nullptr) delete nombre;
    nombre = new char[strlen(n) + 1];
    strcpy(nombre, n);
}

void Cliente::GetNombre(char*n) const {
    if (nombre == nullptr) n[0] = 0;
    else strcpy(n, nombre);
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::operator =(const class Cliente &orig) {
    char nomb[100];
    orig.GetNombre(nomb);
    dni = orig.GetDni();
    hora = orig.GetHora();
    minuto = orig.GetMinuto();
    segundo = orig.GetSegundo();
    SetNombre(nomb);
    tTrans = orig.tTrans;
}

void operator>>(ifstream&arch, class Cliente &cli) {
    int dni, hh, mm, ss;
    char n[100], c;
    double tTrans;
    arch >> dni;
    if (arch.eof()) return;
    arch.get();
    arch.getline(n, 100, ',');
    arch >> hh >> c >> mm >> c >> ss >> c >> tTrans;
    cli.SetDni(dni);
    cli.SetNombre(n);
    cli.SetHora(hh);
    cli.SetMinuto(mm);
    cli.SetSegundo(ss);
    cli.SetTTrans(tTrans);
}

void operator<<(ofstream&arch, const class Cliente&cli) {
    char n[100];
    arch << setprecision(2) << fixed;
    arch << setfill('0') << setw(8) << cli.GetDni() << setfill(' ');
    cli.GetNombre(n);
    arch << "   " << left << setw(40) << n;
    arch << setfill('0') << setw(2) << cli.GetHora() << ':' << setw(2) <<
            cli.GetMinuto() << setw(2) << cli.GetSegundo();
    arch << setfill(' ');
    arch << right << setw(10) << cli.GetTTrans() << endl;
}
