/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.cpp
 * Author: cueva
 * 
 * Created on 6 de junio de 2022, 05:41 PM
 */
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Pedido.h"

using namespace std;


Pedido::Pedido() {
    codigo=0;
    cantidad=0;
    dni=0;
    fecha=0;
    total=0;
  //  despacho=0;
    orden=0;
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
}

void Pedido::iniPedido() {
    codigo=0;
    cantidad=0;
    dni=0;
    fecha=0;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::setTotal(double total) {
    this->total = total;
}

double Pedido::getTotal() const {
    return total;
}
/*
void Pedido::setDespacho(int despacho) {
    this->despacho = despacho;
}

int Pedido::getDespacho() const {
    return despacho;
}
*/
void Pedido::setOrden(int orden) {
    this->orden = orden;
}

int Pedido::getOrden() const {
    return orden;
}

/*
118050,8,8,79475585,16/12/2019
118050,5,5,79475585,30/04/2020
118050,11,11,81114108,09/03/2020
*/
ifstream &operator >> (ifstream &arch, Pedido &f){
    char c;
    int  dni,codigo,cant,fecha,dd,mm,aa;
    double total;
    arch >> codigo;
    if(!arch.eof()){
        arch.get();
        f.SetCodigo(codigo);
        arch >> cant;
        arch.get();
        f.SetCantidad(cant);
        arch >> total;
        f.setTotal(total);
        arch.get();
        arch >> dni;
        f.SetDni(dni);
        arch.get();
        arch >> dd >>c>>mm>>c>>aa;
        arch.get();
        fecha=aa*10000+mm*100+dd;
        f.SetFecha(fecha);
       
    }
    return arch;
}

ofstream &operator << (ofstream &arch, Pedido &f){
    char obs[50];
    
    arch <<setw(15)<<f.GetFecha();
    arch <<setw(20)<<f.GetCodigo();
    arch <<setw(10)<<f.GetCantidad();
    arch <<setprecision(2)<<fixed;
    arch <<setw(10)<<f.getTotal();
    //arch <<setw(10)<<f.getDespacho();
    arch <<setw(10)<<f.getOrden()<<endl;
    return arch;
}