/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

void*leer_registro_heroe(ifstream&arch) {
    int codigo;
    char nombre[100], rol[100], cat[100], c;
    double puntaje;
    
    arch >> codigo;
    if (arch.eof()) return nullptr;
    arch >> c;
    arch.getline(nombre, 100, ',');
    arch.getline(rol, 100, ',');
    arch.getline(cat, 100, ',');
    arch >> c >> puntaje;
    void **reg = new void*[5];
    
    reg[0] = new int{codigo};
    char *nom = new char[strlen(nombre)+1];
    strcpy(nom, nombre);
    reg[1] = nom;
//    cout << (char*)reg[1] << endl;
    char *rol2 = new char[strlen(rol)+1];
    strcpy(rol2, rol);
    reg[2] = rol2;
    char *categoria = new char[strlen(cat)+1];
    strcpy(categoria, cat);
    reg[3] = categoria;
    reg[4] = new double{puntaje};
    
    return reg;
}

void imprimir_registro_heroe (ofstream&arch, void*reg) {
    void**registro = (void**)reg;
    arch << setprecision(2) << fixed;
    arch << left << setw(15) << (char*)registro[1] << setw(10) << 
            (char*)registro[2] <<
            setw(10) << (char*)registro[3] << setw(10) << *(double*)registro[4] <<
            *(int*)registro[0] << endl;
}