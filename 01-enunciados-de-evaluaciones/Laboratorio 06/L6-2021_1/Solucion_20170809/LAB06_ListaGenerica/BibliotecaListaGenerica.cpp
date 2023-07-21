/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibliotecaListaGenerica.cpp
 * Author: Alonso Oswaldo Acosta Gonzales
 * Codigo del Alumno: 20170809
 * Created on 11 de junio de 2021, 08:09 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "BibliotecaListaGenerica.h"
enum Lista{PRIMERO,ULTIMO};
enum Nodo{DATO,SGTE};

void creaLista(void *&lista,void *(*leenum)(ifstream &),int (*cmpnum)(const void *, const void *),const char *nombreArch){
    
    ifstream archDatos(nombreArch,ios::in);
    if(!archDatos){
        cout<<"ERROR: NO se puede abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    
    void *dato;
    lista=nullptr;
    
    inicializarLista(lista);
    
    while(1){
        dato=leenum(archDatos);
        if(archDatos.eof()) break;
        insertarLista(lista,dato,cmpnum);
    }
}

void inicializarLista(void *&lista){
    void **registro;
    registro=new void*[2];
    registro[PRIMERO]=nullptr;
    registro[ULTIMO]=nullptr;
    
    lista=registro;
}

void insertarLista(void *lista,void *dato,int (*cmpnum)(const void *, const void *)){
    void **registroLista= (void **)lista;
    void **nuevoNodo, **ptActual, **ptAnt=nullptr;
    nuevoNodo=new void *[2];
    nuevoNodo[DATO]=dato;
    nuevoNodo[SGTE]=nullptr;
    
    //enum Lista{PRIMERO,ULTIMO};
    //enum Nodo{DATO,SGTE};
   
    if(registroLista[PRIMERO]==nullptr){
        registroLista[PRIMERO]=nuevoNodo;
        registroLista[ULTIMO]=nuevoNodo;
    }
    else{
        ptActual=(void **)registroLista[PRIMERO];
        while(ptActual!=nullptr){
            if(cmpnum(ptActual[DATO],dato)>0) break;
            ptAnt=ptActual;
            ptActual=(void **)ptActual[SGTE];
        }
        if(ptAnt==nullptr) {
            nuevoNodo[SGTE]=ptActual;
            registroLista[PRIMERO]=nuevoNodo;
        }
        else{
            nuevoNodo[SGTE]=ptActual;
            ptAnt[SGTE]=nuevoNodo;
            if(ptActual==nullptr) registroLista[ULTIMO]=nuevoNodo;           
        } 
    }
}

void imprimeLista(void *lista,void (*imprimenum)(ofstream &,void *,void *&),const char *nombreArch){
    
    ofstream archReporte(nombreArch,ios::out);
    if(!archReporte){
        cout<<"ERROR: NO se puede abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    
    archReporte.precision(2);
    archReporte<<fixed;
    
    //enum Lista{PRIMERO,ULTIMO};
    //enum Nodo{DATO,SGTE};
    
    void **registroLista=(void **)lista;
    void **ptActual=(void **)registroLista[PRIMERO], *ptAnt=nullptr;
    
    while(ptActual!=nullptr){
        imprimenum(archReporte,ptActual[DATO],ptAnt);
        ptActual=(void **)ptActual[SGTE];
    }
}

bool listavacia(void *lista){
    if(lista==nullptr)
        return true;
    else return false;
}

void uneLista(void *lista1, void *lista2){
    void **registroLista1=(void **)lista1;
    void **ptLista1Ultimo=(void **)registroLista1[ULTIMO];
    
    void **registroLista2=(void **)lista2;
    
    ptLista1Ultimo[SGTE]=registroLista2[PRIMERO];
}