/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "Preg1_Funciones_de_cursos_y_alumnos.h"
#include "FuncionesAuxiliares.h"

void CargaCursos(int*alumnos_cod, void*&alumnoveces, const char*nom){
    ifstream arch(nom, ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR HistoriaDeNotas.csv";
        exit(1);
    }
    int na, i=0;
    for (na = 0; alumnos_cod[na]; na++);
    void *al_v[na+1]{}, *reg;
    alumnoveces = nullptr;
    while (1){
        reg = LeerRegistro(arch);
        if (!reg) break;
        al_v[i] = reg;
        i++;
    }
}

void*LeerRegistro(ifstream&arch){
    int cod_al, ciclo, nota;
    char cod_cur[20], c;
    arch >> cod_al;
    if (arch.eof()) nullptr;
    arch >> c;
    arch.getline(cod_cur, 20, ',');
    arch >> c >> ciclo >> c >> nota;
    
    void **reg = new void*[7]{};
    reg[0] = new int{cod_al};
    cout << *(int*)reg[0] << endl;
    return reg;
}