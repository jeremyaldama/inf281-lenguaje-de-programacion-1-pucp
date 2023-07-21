/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConEnteros.cpp
 * Author: Alonso Oswaldo Acosta Gonzales
 * Codigo del Alumno: 20170809
 * Created on 11 de junio de 2021, 08:09 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "ListaConEnteros.h"

void * leenum(ifstream &archDatos){
    int licencia,dd,mm,aa,codInfraccion, *fecha;
    char placa[50],car;
    
    archDatos>>licencia;
    if(archDatos.eof()) return nullptr;
    archDatos.get();
    archDatos.getline(placa,50,',');
    archDatos>>dd>>car>>mm>>car>>aa;
    fecha=new int;
    *fecha=aa*10000+mm*100+dd;
    archDatos.get();
    archDatos>>codInfraccion;
    
    return fecha;
}

int cmpnum(const void *regA, const void *regB){
    int *fechaA=(int *)regA;
    int *fechaB=(int *)regB;
    
    return *fechaA-*fechaB;
}

void imprimenum(ofstream &archReporte, void *reg, void *&regAnterior){
    int *fecha=(int *)reg, *fechaAnt;
    
    if(regAnterior==nullptr){
        fechaAnt=new int;
        *fechaAnt=0;
        regAnterior=fechaAnt;
    }
    else{
        fechaAnt=(int *)regAnterior;
    }
    
    if(*fechaAnt!=*fecha){
        archReporte<<*fecha<<endl;
    }
    regAnterior=fecha;
}