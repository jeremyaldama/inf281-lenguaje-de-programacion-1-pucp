/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConRegistro.cpp
 * Author: Alonso Oswaldo Acosta Gonzales
 * Codigo del Alumno: 20170809
 * Created on 11 de junio de 2021, 08:10 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "ListaConRegistro.h"
#define MAX_LINEA 200
enum Conductor{CODLICENCIA,PLACA,FECHA,CODINFRACCION};

void * leeregistro(ifstream &archDatos){
    int aux, *codLicencia,dd,mm,aa,*fecha,*codInfraccion;
    char *placa,car;
   
    archDatos>>aux;
    if(archDatos.eof()) return nullptr;
    codLicencia=new int;
    *codLicencia=aux;
    archDatos.get();
    placa=leerCadena(archDatos);
    archDatos>>dd>>car>>mm>>car>>aa;
    fecha=new int;
    *fecha=aa*10000+mm*100+dd;
    archDatos.get();
    codInfraccion=new int;
    archDatos>>*codInfraccion;
    
    void **registro;
    registro=new void*[4];
    registro[CODLICENCIA]=codLicencia;
    registro[PLACA]=placa;
    registro[FECHA]=fecha;
    registro[CODINFRACCION]=codInfraccion;
    
    return registro;
}

char *leerCadena(ifstream &archDatos){
    char aux[200], *ptAux;
    archDatos.getline(aux,200,',');
    if(archDatos.eof()) return nullptr;
    ptAux=new char[strlen(aux)+1];
    strcpy(ptAux,aux);
    return ptAux;
}

int cmpregistro(const void *regA, const void *regB){
    void **registroConductorA=(void **)regA;
    void **registroConductorB=(void **)regB;
    
    int *fechaA,*fechaB;
    fechaA=(int *)registroConductorA[FECHA];
    fechaB=(int *)registroConductorB[FECHA];
    
    return *fechaA-*fechaB;
}

void imprimeregistro(ofstream &archReporte,void *reg,void *&fechaCabecera){
    void **registroConductor=(void **)reg;
    int *codLicencia,*fecha,*fechaAnt, *codInfraccion,dd,mm,aa;
    char *placa, *nombre;
   
    if(fechaCabecera==nullptr){
        fechaAnt=new int;
        *fechaAnt=0;
        fechaCabecera=fechaAnt;
    }
    else{
        fechaAnt=(int *)fechaCabecera;
        (*fechaAnt)=(*fechaAnt)/100;
    }
    
    //enum Conductor{CODLICENCIA,PLACA,FECHA,CODINFRACCION};
    codLicencia=(int *)registroConductor[CODLICENCIA];
    placa=(char *)registroConductor[PLACA];
    fecha=(int *)registroConductor[FECHA];
    codInfraccion=(int *)registroConductor[CODINFRACCION];
    
    transformarFecha(dd,mm,aa,*fecha);
    if(*fechaAnt!=((*fecha)/100)){
        if(*fechaAnt!=0) 
            imprimirLinea('=',MAX_LINEA,archReporte);
        archReporte<<endl<<endl<<"Año: "<<aa<<" Mes: "<<mm<<endl<<endl;
        archReporte<<"FECHA"<<setw(20)<<"LICENCIA"<<setw(30)<<"NOMBRE"<<setw(30)<<"FALTA"<<endl;
        imprimirLinea('=',MAX_LINEA,archReporte);
    }
    fechaCabecera=fecha;
    
    nombre=obtenerNombreConductor(*codLicencia);
    if(nombre!=nullptr){
        archReporte<<setfill('0')<<setw(4)<<aa<<"/"<<setw(2)<<mm<<"/"<<setw(2)<<dd<<setfill(' ')<<setw(15)<<*codLicencia<<setw(5)<<" "
                <<left<<setw(50)<<nombre<<right<<setw(5)<<" "<<setw(15)<<*codInfraccion<<endl;
        delete nombre;
    }
}

void transformarFecha(int &dd,int &mm,int &aa,int fecha){
    aa=fecha/10000;
    fecha%=10000;
    mm=fecha/100;
    dd=fecha%100;
}

void imprimirLinea(char c,int cant,ofstream &arch){
    for(int i=0;i<cant;i++){
        arch<<c;
    }
    arch<<endl;
}

char * obtenerNombreConductor(int codLicencia){
    ifstream archConductores("Conductores.csv",ios::in);
    if(!archConductores){
        cout<<"ERROR: NO se puede abrir el archivo archConductores.csv"<<endl;
        exit(1);
    }
    
    int codLicenciaArch;
    char nombreArch[200], *ptAux;
    
    while(1){
        archConductores>>codLicenciaArch;
        if(archConductores.eof()) break;
        archConductores.get();
        archConductores.getline(nombreArch,200);
        if(codLicencia=codLicenciaArch){
            ptAux=new char[strlen(nombreArch)+1];
            strcpy(ptAux,nombreArch);
            return ptAux;
        }
    }
    return nullptr;
}