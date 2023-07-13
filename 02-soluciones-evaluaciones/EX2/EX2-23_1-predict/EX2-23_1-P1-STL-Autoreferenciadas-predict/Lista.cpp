/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.cpp
 * Author: Danie
 * 
 * Created on 9 de julio de 2023, 23:37
 */

#include "Lista.h"

Lista::Lista() {
    ini = fin = nullptr;
}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
    cout << "ELIMINA LISTA" << endl;
    Nodo *p = ini, *sale;
    while (p) {
        sale = p;
        p = p->sig;
        delete sale;
    }
}

void Lista::cargarAlumnos(ifstream& arch) {
    Alumno_Curso alum;

    while (true) {
        alum.leerAlumno(arch);
        if (arch.eof()) break;
        cout << "Procede a insertar: " << endl;
        insertar(alum);
    }
}

void Lista::insertar(const Alumno_Curso& alu) {
    Nodo *p = ini, *ant = nullptr, * nuevo;
    nuevo = new Nodo;
    nuevo->alumno = alu;
    // Insertamos ordenado por nombre de alumno
    char nom1[100], nom2[100];
    while (p) {
        p->alumno.obtenerNombre(nom1);
        nuevo->alumno.obtenerNombre(nom2);
        if (strcmp(nom1, nom2) > 0) break;
        ant = p;
        p = p->sig;
    }
    nuevo->sig = p;
    nuevo->ant = ant;

    if (ant) ant->sig = nuevo;
    else ini = nuevo;

    if (p) p->ant = nuevo;
    else fin = nuevo;
}

void Lista::mostrarLista(ofstream& arch) {
    Nodo* p = ini;
    while (p) {
        p->alumno.imprimirAlumno(arch);
        p = p->sig;
    }
}

void Lista::cargarNotas(ifstream& arch) {
    int codigoAlumno;
    Nodo *alumnoBuscado;
    while (true) {
        arch >> codigoAlumno;
        if (arch.eof()) break;
        arch.get();
        alumnoBuscado = buscarAlumno(codigoAlumno);
        if (alumnoBuscado) {
            alumnoBuscado->alumno.leerCursoDelAlumno(arch);
        }
    }
}

Nodo* Lista::buscarAlumno(int codigo) {
    // no olvidarse de inicializar el puntero cuando se hara busqueda
    Nodo *p = ini;

    while (p) {
        if (p->alumno.obtenerCodigoAlumno() == codigo) return p;
        p = p->sig;
        cout << "P SIG" << endl;
    }
    cout << "NULLPTR" << endl;
    return nullptr;
}

void Lista::actualizarCostos(const vector<Curso>& cursos, 
        const vector<Escala>& escalas) {
    Nodo *p = ini;
    int escala;
    double precio;
    while (p) {
        escala = p->alumno.obtenerEscalaAlumno();
        precio = buscarPrecio(escala, escalas);
        p->alumno.actualizarCostos(cursos, precio);
        p = p->sig;
    }
}

double Lista::buscarPrecio(int escala, const vector<Escala>& escalas) {
    for (int i=0; i<escalas.size(); i++) {
        if (escalas[i].GetCodigo() == escala) return escalas[i].GetPrecio();
    }
}
