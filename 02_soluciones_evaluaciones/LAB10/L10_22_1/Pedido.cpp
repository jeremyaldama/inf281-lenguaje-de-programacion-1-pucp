/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Danie
 * 
 * Created on 24 de junio de 2023, 23:14
 */

#include "Pedido.h"

Pedido::Pedido() {
    nombre = nullptr;
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
    if (nombre) delete nombre;
}

void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetNombre(const char* cad) {
    if (nombre) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre, cad);
}

void Pedido::GetNombre(char *cad) const {
    if (nombre) strcpy(cad, nombre);
    else cad[0] = 0;
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::lee(ifstream&arch) {
    char nombre[100], c;
    arch.getline(nombre, 100, ',');
    SetNombre(nombre);
    int dd, mm, aa, fecha;
    arch >> cantidad >> c >> total >> c >> dni >> c >> dd >> c >> mm >> c >>
            aa;
    fecha = aa*10000+mm*100+dd;
    SetFecha(fecha);
}

int Pedido::operator >(const class Pedido&ped) {
    return (dni > ped.dni) || ((dni > ped.dni) && (fecha > ped.fecha));
}

//void Pedido::operator =(const class Pedido&ped) {
//    cantidad = ped.cantidad;
//    codigo = ped.codigo;
//    dni = ped.dni;
//    fecha = ped.fecha;
//    SetNombre(ped.nombre);
//    total = ped.total;
//}

void Pedido::imprime(ofstream& arch) {
    int dd, mm, aa;
    dd = fecha % 100;
    mm = (fecha % 10000) / 100;
    aa = fecha / 10000;
    
    arch << setprecision(2) << fixed;
    arch << right << setfill('0') << setw(2) << dd << '/' << setw(2) << mm <<
            '/' << setfill(' ') << aa << endl;
    arch << codigo << "    " << nombre << endl;
    arch << "DNI: " << dni << endl;
    arch << "Monto Total: " << total << endl;
}