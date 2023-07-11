/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.cpp
 * Author: alulab14
 * 
 * Created on 16 de junio de 2023, 08:14 AM
 */

#include "Tesoreria.h"

Tesoreria::Tesoreria() {
}

Tesoreria::Tesoreria(const Tesoreria& orig) {
}

Tesoreria::~Tesoreria() {
}

void Tesoreria::cargaescalas() {
    ifstream arch("escalas.csv", ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR ESCALAS.CSV";
        exit(1);
    }
    
    int escala, i = 0;
    double precio;
    while (1) {
        arch >> escala;
        if (arch.eof()) break;
        arch.get();
        arch >> precio;
        lescala[i].SetCodigo(escala);
        lescala[i].SetPrecio(precio);
        i++;
    }
}

void Tesoreria::cargaalumnos() {
    ifstream arch("alumnos.csv", ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR ALUMNOS.CSV" << endl;
        exit(1);
    }
    
    char tipo, nombre[100], licencia[100], c, i_p = 0, i_s = 0, i_v = 0;
    int codigo, escala;
    double desc_rec;
    
    while (1) {
        arch >> tipo;
        if (arch.eof()) break;
        arch >> c >> codigo >> c;
        arch.getline(nombre, 100, ',');
        if (tipo == 'V') {
            arch.getline(licencia, 100, ',');
        } else arch >> desc_rec >> c;
        arch >> escala;
        
        if (tipo == 'P') lpresencial[i_p++].asignar(desc_rec, codigo, nombre,
                escala);
        else if (tipo == 'S') lsemipresencial[i_s++].asignar(desc_rec, codigo,
                nombre, escala);
        else lvirtual[i_v++].asignar(licencia, codigo, nombre, escala);
    }
}

void Tesoreria::actualiza(double can_cred) {
    actualizaPresencial(can_cred);
    actualizaSemipresencial(can_cred);
    actualizaVirtual(can_cred);
}

void Tesoreria::actualizaPresencial(double can_cred) {
    for (int i=0; lpresencial[i].GetCodigo(); i++) {
        double valor_escala = BuscarPrecioEscala(lpresencial[i].GetEscala());
        
        lpresencial[i].SetTotal(valor_escala*can_cred*
                                lpresencial[i].GetRecargo()/100);
        lpresencial[i].Alumno::SetTotal(valor_escala*can_cred + 
                    lpresencial[i].GetTotal());
    }
}

void Tesoreria::actualizaSemipresencial(double can_cred) {
    for (int i=0; lsemipresencial[i].GetCodigo(); i++) {
        double valor_escala = BuscarPrecioEscala(lsemipresencial[i].GetEscala());
        
        lsemipresencial[i].SetTotal(valor_escala*can_cred*
                                lsemipresencial[i].GetDescuento()/100);
        // en semipresencial se le tiene que restar su descuento
        lsemipresencial[i].Alumno::SetTotal(valor_escala*can_cred - 
                    lsemipresencial[i].GetTotal());
    }
}

void Tesoreria::actualizaVirtual(double can_cred) {
    for (int i=0; lvirtual[i].GetCodigo(); i++) {
        double valor_escala = BuscarPrecioEscala(lvirtual[i].GetEscala());
        
        // en el caso de la licencia siempre sera de 100
        lvirtual[i].Alumno::SetTotal(valor_escala*can_cred +
                    lvirtual[i].GetTotal());
    }
}


double Tesoreria::BuscarPrecioEscala(int esc) {
    for (int i=0; lescala[i].GetCodigo(); i++) {
        if (lescala[i].GetCodigo() == esc) return lescala[i].GetPrecio();
    }
}

void Tesoreria::imprime() {
    ofstream arch("ReporteAlumnos.txt", ios::out);
    if (!arch) {
        cout << "No se pudo abrir ReporteAlumnos.txt";
        exit(1);
    }
    
    arch << setprecision(2) << fixed;
    arch << left << setw(20) << "Codigo" << setw(60) << "Nombre" << setw(12) <<
            "Escala" << setw(20) << "Licencia" << "Total" << endl;
    imprimirLinea(arch, '=', 120);
    arch << endl << "PRESENCIAL: " << endl;
    for (int i=0; lpresencial[i].GetCodigo(); i++) {
        lpresencial[i].imprimir(arch);
    }
    arch << endl << "SEMIPRESENCIAL: " << endl;
    for (int i=0; lsemipresencial[i].GetCodigo(); i++){
        lsemipresencial[i].imprimir(arch);
    }
    arch << endl << "VIRTUAL: " << endl;
    for (int i=0; lvirtual[i].GetCodigo(); i++){
        lvirtual[i].imprimir(arch);
    }
}

void Tesoreria::imprimirLinea(ofstream&arch, char c, int n) {
    for (int i=0; i<n; i++) arch << c;
    arch << endl;
}
