/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Empresa.cpp
 * Author: Danie
 * 
 * Created on 25 de junio de 2023, 22:57
 */


#include "Empresa.h"

void Empresa::abrirArchivoLectura(ifstream&arch, const char*nom) {
    arch.open(nom, ios::in);
    if (!arch) {
        cout << "ERROR: Error no se pudo abrir " << nom;
        exit(1);
    }
}

void Empresa::abrirArchivoEscritura(ofstream&arch, const char*nom) {
    arch.open(nom, ios::out);
    if (!arch) {
        cout << "ERROR: Error no se pudo abrir " << nom;
        exit(1);
    }
}

void Empresa::leerClientes(const char*nom) {
    ifstream arch;
    abrirArchivoLectura(arch, nom);

    class Cliente cli;
    class RegCliente regCli;
    while (1) {
        cli.leerDatos(arch);
        if (arch.eof()) break;
        asignarDescuento(cli);
        regCli.asignarCliente(cli);
        lstClientes.push_back(regCli);
    }
}

void Empresa::asignarDescuento(class Cliente&cli) {
    char tipo;
    tipo = cli.GetTipo();

    if (tipo == 'A') cli.SetDescuento(23.5);
    else if (tipo == 'B') cli.SetDescuento(16.8);
    else if (tipo == 'C') cli.SetDescuento(0.0);
    else cli.SetDescuento(0.0);
}

void Empresa::imprimirClientes(const char*nom) {
    ofstream arch;
    abrirArchivoEscritura(arch, nom);

    for (list<class RegCliente>::iterator it = lstClientes.begin();
            it != lstClientes.end(); it++) {
        it->imprimirRegistro(arch);
    }
}

void Empresa::leerPedidos(const char*cad) {
    ifstream arch;
    abrirArchivoLectura(arch, cad);
    class Producto prod;
    class Pedido ped;
    int cod_prod, ind_cod_prod, dni_cli;
    while (true) {
        prod.leerDatos(arch);
        if (arch.eof()) break;
        // los 3 ultimos datos
        dni_cli = ped.leerDatos(arch);
        cout << prod.GetPrecioUnitario() << endl;
        ped.SetSubTotal(prod.GetPrecioUnitario() * ped.GetCantidad());

        ind_cod_prod = BuscarProducto(cod_prod);
        if (!ind_cod_prod) {
            lstProductos.push_back(prod);
        }

        for (list<class RegCliente>::iterator it = lstClientes.begin();
                it != lstClientes.end(); it++) {
            if (it->ObtenerDNI() == dni_cli) {
                it->asignarPedidoACliente(ped);
                break;
            }
        }
    }
}

int Empresa::BuscarProducto(int cod) {
    for (Producto prod : lstProductos) {
        if (prod.GetCodigo() == cod) return 1;
    }
    return 0;
}

void Empresa::ordenarPedidos() {
    for (list<class RegCliente>::iterator it = lstClientes.begin();
            it != lstClientes.end(); it++) {
        it->ordenarPedidos();
    }
}

void Empresa::imprimirProductos(const char*nomb) {
    ofstream arch;
    abrirArchivoEscritura(arch, nomb);
    for (Producto prod : lstProductos) {
        prod.imprimirDatos(arch);
    }
}