/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tienda.cpp
 * Author: Danie
 * 
 * Created on 12 de junio de 2023, 23:11
 */

#include "Tienda.h"

Tienda::Tienda() {
}

Tienda::Tienda(const Tienda& orig) {
}

Tienda::~Tienda() {
}

void Tienda::carga() {
    CargaPedidos();
    CargaClientes();
}

void Tienda::CargaPedidos() {
    ifstream arch("pedidos3.csv", ios::in);
    
    int codigo, cantidad, dni, dd, mm, aa, fecha, i_p = 0;
    char c;
    while (1) {
        arch >> codigo;
        if (arch.eof()) break;
        arch >> c >> cantidad >> c >> dni >> c >> dd >> c >> mm >> c >> aa;
        fecha = aa*10000+mm*100+dd;
        
        lpedidos[i_p].SetCodigo(codigo);
        lpedidos[i_p].SetCantidad(cantidad);
        lpedidos[i_p].SetDni(dni);
        lpedidos[i_p].SetFecha(fecha);
        lpedidos[i_p].AsignarProducto(codigo);
        
        i_p++;
    }
}

void Tienda::CargaClientes() {
    ifstream arch("clientes2.csv", ios::in);
    
    int i = 0;
    int dni;
    char categoria, c, nombre[100];
    while (1) {
        arch >> dni;
        if (arch.eof()) break;
        arch >> c;
        arch.getline(nombre, 100, ',');
        arch >> categoria;
        
        lclientes[i].SetNombre(nombre);
        lclientes[i].SetCategoria(categoria);
        lclientes[i].SetDni(dni);
        cout << lclientes[i].GetDni() << endl;
        cout << categoria << endl;
        
        i++;
    }
}

void Tienda::actualiza(int min_stock) {
    
    for (int i=0; lpedidos[i].GetCodigo(); i++) {
        cout << "inicia: " << lpedidos[i].GetCodprod() / 100000 << endl;
        cout << "stock: " << lpedidos[i].GetStock() << endl;
        if ((lpedidos[i].GetCodprod() / 100000) == 4 && 
                lpedidos[i].GetStock()>=min_stock) {
            int descuento = BuscarDescuento(lpedidos[i].GetDni());
            cout << descuento << endl;
            if (descuento!=-1) {
                double precio = lpedidos[i].GetPrecio();
                double cantidad = lpedidos[i].GetCantidad();
                if (descuento == 10) {
                    lpedidos[i].SetObs("Descuento Especial de 10%");
                    lpedidos[i].SetTotal(0.9*precio*cantidad);
                } else if (descuento == 20) {
                    lpedidos[i].SetObs("Descuento Especial de 20%");
                    lpedidos[i].SetTotal(0.8*precio*cantidad);
                } else {
                    lpedidos[i].SetObs("Descuento Especial de 30%");
                    lpedidos[i].SetTotal(0.7*precio*cantidad);
                }
            }
        } 
    }
}

int Tienda::BuscarDescuento(int cod_buscar) {
    cout << "entra" << endl;
    for (int i=0; lclientes[i].GetDni(); i++) {
        if (lclientes[i].GetDni() == cod_buscar) {
            cout << "encontrado" << endl;
            char c = lclientes[i].GetCategoria();
            cout << "cat<. " << c << endl;
            if (c == 'A') return 50;
            else if (c == 'B') return 30;
            else return 10;
        }
    }
    return -1;
}

void Tienda::muestra() {
    ofstream arch("Reporte.txt", ios::out);
    
    arch << left << setw(15) << "Fecha" << setw(15) << "Codigo" << setw(45) <<
            "Descripcion del prod." << setw(10) << "Cant." << setw(10) <<
            "Precio" << setw(10) << "Total" << "Observaciones" << endl;
    
    int dd, mm, aa, fecha;
    char cad[100];
    arch << setprecision(2) << fixed;
    for (int i=0; lpedidos[i].GetDni(); i++) {
        fecha = lpedidos[i].GetFecha();
        dd = fecha % 100;
        mm = (fecha % 10000) / 100;
        aa = fecha / 10000;
        
        lpedidos[i].GetNombre(cad);
        arch << right << setw(2) << setfill('0') << dd << '/' << setw(2) <<
                mm << '/' << setfill(' ') << left << setw(10) << aa << setw(10) <<
                lpedidos[i].GetCodigo() << left << setw(45) << cad;
        lpedidos[i].GetObs(cad);
        arch << lpedidos[i].GetCantidad() << right << setw(10) <<
                lpedidos[i].GetPrecio() << setw(10) <<
                lpedidos[i].GetTotal() << setw(10) << "" << cad << endl;
                
    }
}