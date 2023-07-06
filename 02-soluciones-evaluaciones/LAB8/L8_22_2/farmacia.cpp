/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   farmacia.cpp
 * Author: Danie
 * 
 * Created on 12 de junio de 2023, 9:57
 */

#include "farmacia.h"

farmacia::farmacia() {
}

farmacia::farmacia(const farmacia& orig) {
}

farmacia::~farmacia() {
}

void farmacia::cargamedico() {
    ifstream arch("medicos.csv", ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR MEDICOS.CSV" << endl;
        exit(1);
    }

    int i = 0;
    class medico med;
    while (1) {
        med.LeeMedico(arch);
        if (arch.eof()) break;
        lmedico[i].CopiaMedico(med);
        i++;
    }
}

void farmacia::leerecetas() {
    ifstream arch("recetas.csv", ios::in);

    int i_c = 0, i_s = 0;
    int dd, mm, aa, dni, cod_med, fecha;
    char nom_cli[100], c;

    while (1) {
        arch >> dd;
        if (arch.eof()) break;
        arch >> c >> mm >> c >> aa >> c >> dni >> c;
        arch.getline(nom_cli, 100, ',');
        arch >> cod_med;
        fecha = aa * 10000 + mm * 100 + dd;

        LeerReceta(arch, fecha, cod_med, dni, nom_cli, i_c, i_s);
    }
}

void farmacia::LeerReceta(ifstream&arch, const int &fecha, const int &cod_med,
        int dni, char*nom_cli, int &i_c, int &i_s) {
    char c, especialidad[100];
    int medicamento, cantidad;
    class conreceta conrec;
    class sinreceta sinrec;
    while (arch.get(c)) {
        // puede que falte un eof
        if (c == '\n') {
            break;
        } else {
            arch >> medicamento >> c >> cantidad;
            class medicamento medicamentou;
            // codigo, precio y nombre a medicamento
            medicamentou.BuscarMedicamento(medicamento);

            medicamentou.SetCantidad(cantidad);
            medicamentou.SetFecha(fecha);
            // PAR
            if ((medicamento % 10000) % 2 == 0) {

                lconreceta[i_c].SetCodmed(cod_med);
                ObtenerEspecialidad(cod_med, especialidad);
                lconreceta[i_c].SetEspecialidad(especialidad);
                lconreceta[i_c].SetMedicamento(medicamentou);

                i_c++;
            } else {
                lsinreceta[i_s].SetDni(dni);
                lsinreceta[i_s].SetNombre(nom_cli);
                lsinreceta[i_s].SetMedicamento(medicamentou);

                i_s++;
            }
        }
    }
}

void farmacia::ObtenerEspecialidad(int codigo, char*esp) {
    for (int i = 0; lmedico[i].GetCodigo(); i++) {
        if (lmedico[i].GetCodigo() == codigo) {
            char n[100];
            lmedico[i].GetEspecialidad(n);
            strcpy(esp, n);
            break;
        }
    }
}

void farmacia::imprimirrecetas() {
    ofstream arch("Reporte.txt", ios::out);
    ImprimirSinRecetas(arch);
    ImprimirConRecetas(arch);
}

void farmacia::ImprimirSinRecetas(ofstream&arch) {
    arch << "CODIGO" << left << setw(4) << "" << setw(60) << "Descripcion del Med." << setw(10) <<
            "Cant." << setw(20) << "DNI" << setw(20) << "Nombre" << endl;
    ImprimeLinea(arch, '=', 120);
    char n[100];
    for (int i = 0; lsinreceta[i].GetCodigo(); i++) {
        lsinreceta[i].medicamento::GetNombre(n);
        arch << right << lsinreceta[i].GetCodigo() << setw(5) << "" << left <<
                setw(60) << n << setw(10) << lsinreceta[i].GetCantidad() <<
                setw(15) << lsinreceta[i].GetDni();
        lsinreceta[i].GetNombre(n);
        arch << n << endl;

    }
}

void farmacia::ImprimirConRecetas(ofstream&arch) {
    arch << endl;
    arch << "CODIGO" << left << setw(4) << "" << setw(60) <<
            "Descripcion del Med." << setw(10) << "Cant." << setw(20) <<
            "Cod. Medico" << setw(20) << "Especialidad" << endl;
    ImprimeLinea(arch, '=', 120);
    char n[100];
    for (int i = 0; lconreceta[i].GetCodigo(); i++) {
        // aca da lo mismo si ponemos el ambito medicamento,
        // pues solo hay un GetNombre
        lconreceta[i].medicamento::GetNombre(n);
        arch << right << lconreceta[i].GetCodigo() << setw(5) << "" << left <<
                setw(60) << n << setw(10) << lconreceta[i].GetCantidad() <<
                setw(15) << lconreceta[i].GetCodmed();
        lconreceta[i].GetEspecialidad(n);
        arch << n << endl;
    }
}

void farmacia::ImprimeLinea(ofstream&arch, char c, int n) {
    for (int i = 0; i < n; i++) arch << c;
    arch << endl;
}