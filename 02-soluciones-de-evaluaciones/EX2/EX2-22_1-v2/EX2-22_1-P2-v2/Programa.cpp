/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Programa.cpp
 * Author: Danie
 * 
 * Created on 6 de julio de 2023, 16:37
 */

#include "Programa.h"

void Programa::abrirArchivoEscritura(ofstream& arch, const char*cad) {
    arch.open(cad, ios::out);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << cad;
        exit(1);
    }
}

void Programa::abrirArchivoLectura(ifstream& arch, const char*cad) {
    arch.open(cad, ios::in);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << cad;
        exit(1);
    }
}

void Programa::carga() {
    CargaProductos();
    CargaLista();
}

void Programa::CargaProductos() {
    ifstream arch;
    abrirArchivoLectura(arch, "productos4.csv");
    
    class NProductos prod;
    int i = 0;
    while (1) {
        prod.leer(arch);
        if (arch.eof()) break;
        // ACA ES COMO HACER
        // class NProductos nprod = prod;
        // por tanto se usara el constructor copia, pero no se puedo destruir
        // porque al terminar el metodo push_back se va a destruir ese
        // NProductos copia
        vproductos.push_back(prod);
        cout << "termina push back " << ++i << endl << endl;
    }
    cout << "size: " << vproductos.size() << endl;
    cout << "capacity: " << vproductos.capacity() << endl;
}

void Programa::CargaLista() {
    ifstream arch;
    abrirArchivoLectura(arch, "pedidos4.csv");
    
    lpedidos.cargarLista(arch);
}

void Programa::muestra() {
    ImprimeProductos();
    ImprimeLista();
}

void Programa::ImprimeProductos() {
    ofstream arch;
    abrirArchivoEscritura(arch, "ReporteProductos.txt");
    arch << setprecision(2) << fixed;
    
    arch << left << setw(5) << " " << setw(10) << "CODIGO" << setw(50) <<
            "NOMBRE" << setw(10) << "STOCK" << setw(10) << "PRIORIDAD" << 
            "DESCUENTO" << endl;
    for (int i=0; i<vproductos.size(); i++) {
        vproductos[i].imprime(arch);
    }
}

void Programa::ImprimeLista() {
    ofstream arch;
    abrirArchivoEscritura(arch, "ReporteLista.txt");
    
    lpedidos.mostrarLista(arch);
}

void Programa::actualiza() {
    lpedidos.actualiza(vproductos);
}

void Programa::ordenarProductos() {
    cout << endl << "empieza ordenar: " << endl;
    sort(vproductos.begin(), vproductos.end());
    cout << endl << "empieza a eliminar: " << endl;
//    vproductos.erase(vproductos.begin(), vproductos.begin()+3);
    
//    for (int i=0; i<3; i++) {
//        vproductos.erase(vproductos.begin()+i);
//    }
    
    class NProductos nodo;
    nodo.setear();
    vproductos.insert(vproductos.begin()+3, nodo);
    cout << "termina de eliminar" << endl;
}
