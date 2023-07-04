/* 
 * File:   funciones.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 5 de abril de 2023, 10:22
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void genera_alumnos_bin(){
    char tipo, nombre[100], esp[100], fac[4];
    int codigo, carnet;
    
    ifstream arch("Alumnos.txt",ios::in);
    if (!arch){
        cout << "No se pudo abrir el archivo Alumnos.txt";
        exit(1);
    }
    
    ofstream arch_bin("AlumnosBin.bin", ios::out | ios::binary);
    if (!arch_bin){
        cout << "No se pudo abrir el binary";
        exit(1);
    }
    
    while (1){
        arch >> tipo;
        if (arch.eof()) break;
        arch >> codigo >> nombre >> carnet;
        if (arch.fail()){
            carnet = 0;
            arch.clear();
        }
        arch >> esp >> fac;
        arch_bin.write(reinterpret_cast<const char*>(&codigo), sizeof(int));
        arch_bin.write(reinterpret_cast<const char*>(nombre), sizeof(char)*100);
        arch_bin.write(reinterpret_cast<const char*>(&tipo), sizeof(char));
        arch_bin.write(reinterpret_cast<const char*>(&carnet), sizeof(int));
        arch_bin.write(reinterpret_cast<const char*>(fac), sizeof(char)*4);
        arch_bin.write(reinterpret_cast<const char*>(esp), sizeof(char)*100);
    }
}

void generar_consolidado(){
    char tipo, nombre[100], esp[100], fac[4];
    int codigo, carnet, suma_nota=0, estado=0, cant_cur=0;
    double cant_cred=0.0, cred_cur=0.0;
    
    ifstream arch_bin("AlumnosBin.bin", ios::in | ios::binary);
    if (!arch_bin){
        cout << "No se pudo abrir el archivo AlumnosBin";
        exit(1);
    }
    
    ofstream arch_conso("Consolidado.bin", ios::out | ios::binary);
    if (!arch_conso){
        cout << "No se pudo abrir el archivo Alumnos.txt";
        exit(1);
    }
    while (1){
        arch_bin.read(reinterpret_cast<char*>(&codigo), sizeof(int));
        if (arch_bin.eof()) break;
        arch_bin.read(reinterpret_cast<char*>(nombre), sizeof(char)*100);
        arch_bin.read(reinterpret_cast<char*>(&tipo), sizeof(char));
        arch_bin.read(reinterpret_cast<char*>(&carnet), sizeof(int));
        arch_bin.read(reinterpret_cast<char*>(fac), sizeof(char)*4);
        arch_bin.read(reinterpret_cast<char*>(esp), sizeof(char)*100);
        
        arch_conso.write(reinterpret_cast<const char*>(&codigo), sizeof(int));
        arch_conso.write(reinterpret_cast<const char*>(nombre), sizeof(char)*100);
        arch_conso.write(reinterpret_cast<const char*>(&cred_cur), sizeof(double));
        arch_conso.write(reinterpret_cast<const char*>(&cant_cred), sizeof(double));
        arch_conso.write(reinterpret_cast<const char*>(&suma_nota), sizeof(int));
        arch_conso.write(reinterpret_cast<const char*>(&cant_cur), sizeof(int));
        arch_conso.write(reinterpret_cast<const char*>(fac), sizeof(char)*4);
        arch_conso.write(reinterpret_cast<const char*>(&estado), sizeof(int));
    }
}

void act_consolidado(){
    char tipo, nombre[100], esp[100], fac[4], otros[10];
    int codigo, carnet, suma_nota=0, estado=0, cant_cur=0, cod_al, nota;
    double cant_cred=0.0, cred_cur=0.0, cred;
    
    ifstream arch_cursos("Cursos.txt", ios::in);
    if (!arch_cursos){
        cout << "No se pudo abrir el archivo Cursos.txt";
        exit(1);
    }
    
    fstream arch_cons("Consolidado.bin", ios::in | ios::out | ios::binary);
    if (!arch_cons){
        cout << "No se pudo abrir el archivo Consolidad.bin";
        exit(1);
    }
    
    int size=sizeof(int)*4 + sizeof(char)*104 + sizeof(double)*2;
    // lo mando al final el cursor
    arch_cons.seekg(0, ios::end);
    // para saber cuantos bytes hay hasta la posición del cursor
    int total = arch_cons.tellg();
    int num_reg = total/size;
    
    while (1){
        // 20110165 FIS111 19 2018-0 3.5
        arch_cursos >> cod_al;
        if (arch_cursos.eof()) break;
        arch_cursos >> otros >> nota >> otros >> cred;
        
        // para poner el cursor al inicio, en vez de 0 también puede
        // ponerse begin
        arch_cons.seekg(0, ios::beg);
        
        for (int i=0; i<num_reg; i++){
            
        }
    }
}


void imprimir_consolidado(){
    char tipo, nombre[100], esp[100], fac[4];
    int codigo, carnet, suma_nota=0, estado=0, cant_cur=0;
    double cant_cred=0.0, cred_cur=0.0;
    
    ifstream arch_bin("Consolidado.bin", ios::in | ios::binary);
    if (!arch_bin){
        cout << "No se pudo abrir el archivo AlumnosBin";
        exit(1);
    }
    
    ofstream reporte("Consolidado.txt", ios::out);
    if (!reporte){
        cout << "No se pudo abrir el archivo Reporte.txt";
        exit(1);
    }
    while (1){
        if (arch_bin.eof()) break;
        
        arch_bin.read(reinterpret_cast<char*>(&codigo), sizeof(int));
        arch_bin.read(reinterpret_cast<char*>(nombre), sizeof(char)*100);
        
        arch_bin.read(reinterpret_cast<char*>(&cred_cur), sizeof(double));
        arch_bin.read(reinterpret_cast<char*>(&cant_cred), sizeof(double));
        arch_bin.read(reinterpret_cast< char*>(&suma_nota), sizeof(int));
        arch_bin.read(reinterpret_cast< char*>(&cant_cur), sizeof(int));
        arch_bin.read(reinterpret_cast< char*>(fac), sizeof(char)*4);
        arch_bin.read(reinterpret_cast< char*>(&estado), sizeof(int));
        
        reporte << left << setw(10) << codigo << setw(50) << nombre <<
                setw(5) << cred_cur << setw(5) << cant_cred << setw(5) <<
                suma_nota << setw(5) << cant_cur << setw(8) << fac <<
                estado << endl;
    }
}