/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   almacen.cpp
 * Author: alulab14
 * 
 * Created on 25 de noviembre de 2022, 08:11 AM
 */
#define MAXCANTLINEA 135
#include "almacen.h"
#include "generico.h"
#include "marca.h"

void AbrirArchivo(const char *nomb,ifstream &arch);
void AbrirArchivo(const char *nomb,ofstream &arch);

void AbrirArchivo(const char *nomb,ifstream &arch){
    arch.open(nomb,ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo"<<nomb;
        exit(1);
    }
}

void AbrirArchivo(const char *nomb,ofstream &arch){
    arch.open(nomb,ios::out);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo"<<nomb;
        exit(1);
    }
}

void almacen::carga() {
    ifstream arch;
    AbrirArchivo("medicamentos.csv",arch);
    medicamento *med;
    while(1){
        leeMedicamento(med,arch);
        if(arch.eof())break;
        arbolalma.insertar(med);
    }
}

void almacen::leeMedicamento(medicamento*& med, ifstream& arch) {
    int cod;
    char c;
    arch>>cod>>c;
    if(arch.eof())return;
    if(cod==0){
        med = new class generico;
    }else{
        med = new class marca;
    }
    med->lee(arch);
}



void almacen::actualiza() {

}

void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}

void almacen::imprime() {
    ofstream arch;
    AbrirArchivo("Reporte.txt",arch);
    arch<<setw(70)<<right<<"REPORTE DE MEDICAMENTOS"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
    arch<<setw(10)<<left<<"Codigo"<<setw(55)<<left<<"Nombre del medicamento"
            <<setw(9)<<left<<"Stock"
            <<setw(8)<<left<<"Precio"<<setw(40)<<left<<"Pais/Laboratorio"
            <<left<<"Lote"<<endl;
    imprimeLinea(arch,MAXCANTLINEA,'=');
    arch.precision(2);
    arch<<fixed;
    arbolalma.imprimir(arch);
}



