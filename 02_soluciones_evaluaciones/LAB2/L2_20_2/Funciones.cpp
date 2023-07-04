/* 
 * File:   Funciones.cpp
 * Author: Jeremy Aldama 20206228
 * 
 * Created on 20 de abril de 2023, 23:12
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Funciones.h"

using namespace std;

void TransferirInformacion(){
    ofstream arch_notas_finales_bin("NotasFinales.bin", ios::out | ios::binary);
    if (!arch_notas_finales_bin){
        cout << "NO SE PUDO ABRIR NOTASFINALES.BIN";
        exit(1);
    }
    
    ifstream arch_alumnos_cursos("Alumnos-Cursos.txt", ios::in);
    if (!arch_alumnos_cursos){
        cout << "NO SE PUDO ABRIR ALUMNOS-CURSOS.TXT";
        exit(1);
    }
    
    // 989-2018-12   MEC269   12   1   15   14/07/2017   INF248   55   5   14   15/12/2013   MAT241   1920   3   16   12/09/2013
    int codigo_alumno, anio_ingreso, facultad_alumno, facultad_curso,
            nota_curso, anio_evaluacion, semestre_evaluacion, dd, mm;
    char codigo_curso[10], c;
    double creditos_curso;
    
    while(1){
        arch_alumnos_cursos >> codigo_alumno;
        if (arch_alumnos_cursos.eof()) break;
        if (arch_alumnos_cursos.fail()){
            arch_alumnos_cursos.clear();
            arch_alumnos_cursos >> codigo_curso >> facultad_curso >>
                    creditos_curso >> nota_curso >> dd >> c >> mm >> c >> 
                    anio_evaluacion;
            
            if (anio_evaluacion >= anio_ingreso){
                arch_notas_finales_bin.write(
                    reinterpret_cast<const char*>(&codigo_curso), sizeof(char)*10);
                arch_notas_finales_bin.write(
                        reinterpret_cast<const char*>(&facultad_curso), sizeof(int));
                arch_notas_finales_bin.write(
                        reinterpret_cast<const char*>(&creditos_curso), sizeof(double));
                arch_notas_finales_bin.write(
                        reinterpret_cast<const char*>(&nota_curso), sizeof(int));
                arch_notas_finales_bin.write(
                        reinterpret_cast<const char*>(&anio_evaluacion), sizeof(int));
                if (mm >= 1 && mm <= 2) semestre_evaluacion = 0;
                else if(mm >=3 && mm <= 7) semestre_evaluacion = 1;
                else semestre_evaluacion = 2;
            }
        }
        else{
            arch_alumnos_cursos >> c >> anio_ingreso >> c >> facultad_alumno;
            
            // ESCRITURA DEL ALUMNO EN EL BINARIO
            arch_notas_finales_bin.write(
                    reinterpret_cast<const char*>(&codigo_alumno), sizeof(int));
            arch_notas_finales_bin.write(
                    reinterpret_cast<const char*>(&anio_ingreso), sizeof(int));
            arch_notas_finales_bin.write(
                    reinterpret_cast<const char*>(&facultad_alumno), sizeof(int));
        }
        
    }
}