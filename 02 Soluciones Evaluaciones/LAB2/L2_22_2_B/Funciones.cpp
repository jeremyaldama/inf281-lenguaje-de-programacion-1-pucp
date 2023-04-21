/* 
 * File:   Funciones.cpp
 * Author: Jeremy Aldama 20206228
 * 
 * Created on 20 de abril de 2023, 21:10
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Funciones.h"

using namespace std;

void CompletarGastoXPaciente(){
    fstream arch_pacientes_bin("Pacientes.bin", ios::out | ios::in | ios::binary);
    if (!arch_pacientes_bin){
        cout << "NO SE PUDO ABRIR PACIENTES.BIN";
        exit(1);
    }
    ifstream arch_consultas("Consultas.txt", ios::in);
    if (!arch_consultas){
        cout << "NO SE PUDO ABRIR CONSULTAS.TXT";
        exit(1);
    }
    ifstream arch_medicinas("Medicinas.bin", ios::in);
    if (!arch_medicinas){
        cout << "NO SE PUDO ABRIR MEDICINAS.BIN";
        exit(1);
    }
    
    int dni_paciente, cantidad_medicinas, codigo_medicina;
    char codigo_medico[10], fecha[12];
    double precio_medicina, precio_total = 0.0;
    
    while (1){
        arch_consultas >> dni_paciente;
        if (arch_consultas.eof()) break;
        
        arch_consultas >> codigo_medico >> fecha >> cantidad_medicinas;
        
        for (int i=0; i<cantidad_medicinas; i++){
            arch_consultas >> codigo_medicina;
            precio_medicina = BuscarPrecioMedicina(arch_medicinas, codigo_medicina);
            precio_total += precio_medicina;
        }
        ActualizarPaciente(arch_pacientes_bin, dni_paciente, precio_total);
        precio_total = 0.0;
    }
}

void ActualizarPaciente(fstream &arch_pacientes_bin, int dni_paciente,
        double precio_total){
    arch_pacientes_bin.seekg(0, ios::beg);
    int dni;
    double gasto;
    while(1){
        arch_pacientes_bin.read(reinterpret_cast<char*>(&dni), sizeof(int));
        if (arch_pacientes_bin.eof()) break;
        if (dni == dni_paciente){
            arch_pacientes_bin.seekg(sizeof(char)*100, ios::cur);
            arch_pacientes_bin.read(reinterpret_cast<char*>(&gasto), sizeof(double));
            gasto += precio_total;
            int mov = -1*sizeof(double);
            arch_pacientes_bin.seekg(mov, ios::cur);
            arch_pacientes_bin.write(reinterpret_cast<const char*>(&gasto),
                    sizeof(double));
            break;
        }
        else{
            arch_pacientes_bin.seekg(sizeof(char)*100 + sizeof(double), 
                    ios::cur);
        }
    }
}

double BuscarPrecioMedicina(ifstream &arch_medicinas, int codigo_medicina){
    arch_medicinas.seekg(0, ios::beg);
    int codigo;
    double precio;
    while(1){
        arch_medicinas.read(reinterpret_cast<char*>(&codigo), sizeof(int));
        if (arch_medicinas.eof()) break;
        arch_medicinas.seekg(sizeof(char)*100, ios::cur);
        arch_medicinas.read(reinterpret_cast<char*>(&precio), sizeof(double));
        if (codigo == codigo_medicina) return precio;
    }
}

void VerificarCreacion(const char*nombre_arch, 
        const char*nombre_arch_out){
    ifstream arch(nombre_arch, ios::in | ios::binary);
    if (!arch){
        cout << "No se pudo abrir *.bin para verificar" << endl;
        exit(1);
    }
    ofstream arch_prueba(nombre_arch_out, ios::out);
    int entero;
    char nombre[100];
    double flotante;
    while(1){
        arch.read(reinterpret_cast<char*>(&entero), sizeof(int));
        if (arch.eof()) break;
        arch.read(reinterpret_cast<char*>(nombre), sizeof(char)*100);
        arch.read(reinterpret_cast<char*>(&flotante), sizeof(double));
        arch_prueba << left << setw(14) << entero << setw(50) << nombre <<
                flotante << endl;
    }
}

