/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.cpp
 * Author: cueva
 * 
 * Created on 26 de junio de 2022, 09:39 PM
 */
#include <iostream>
#include <fstream>
#include <vector>
#include "Lista.h"
#include "Pedido.h"
#include "Nodo.h"


using namespace std;

Lista::Lista() {
    lini = NULL;
    lfin = NULL;
}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
}

int Lista::ListaVacia(){
    if(lini==NULL)
        return 1;
    return 0;
}

void Lista::inserta(ifstream& arch){
    int codigo;
    Nodo *p = lini,*nuevo,*rec=NULL;
        
    nuevo = new Nodo;
    nuevo->sig = NULL;
    
    arch >> nuevo->ped;
    if(arch.eof()) return;        
    
    while(p){
        if(p->ped.GetFecha()>nuevo->ped.GetFecha()) break;
        rec=p;
        p=p->sig;
    }
    nuevo->sig = p;
    if(rec == NULL) {
        if(p==NULL) lfin = nuevo;
        lini = nuevo;
    }
    else{   rec->sig = nuevo;
            if(rec == lfin) lfin = nuevo;
    }    
}    

void Lista::muestra(ofstream& arch){
    class Nodo *p;

    p=lini;
        
    while(p)
    {   arch << p->ped;
        p=p->sig;
    }        

}
void Lista::imprimelista(){
    ofstream arch("Replista.txt",ios::out);
    if(!arch){
        cout << "No se pudo abrir el archivo Pedidos";
        exit(1);
    }
    muestra(arch);
}

void Lista::cargalista(){
    ifstream arch("Pedidos4.csv",ios::in);
    if(!arch){
        cout << "No se pudo abrir el archivo Pedidos";
        exit(1);
    }
    while(1){
        inserta(arch);
        if(arch.eof()) break;
    }    
}
