/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 9 de junio de 2023, 11:34
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "alumno.h"
#include "nota.h"
#include "alumnonota.h"

int main(int argc, char** argv) {
    // LECTURA
    ifstream arch_al("Alumnos.csv", ios::in);
    // alumno
    alumno al;
    arch_al >> al;
    char n[100];
    al.GetNombre(n);
    cout << al.GetCodigo() << " " << n << endl;
    // registro
    ifstream arch_notas("Notas.csv", ios::in);
    alumnonota al_nota;
    char cod_cur[100];
    arch_notas >> al_nota;
    al_nota.GetCodcurso(cod_cur);
    cout << al_nota.GetCodigo() << " " << cod_cur << " " << al_nota.GetCiclo() 
            << " " << al_nota.GetNota() << endl;

    // AGREGACION Y TOTALIZACION
    class nota nota_obj;
    al_nota & nota_obj;
    cout << nota_obj.GetCiclo() << " " << nota_obj.GetNota() << endl;
  
    al += nota_obj;
    const class nota *notas = al.GetLnotas();
    cout << "notas: " << notas[0].GetCiclo() << endl;
    
    // IMPRESION
    ofstream arch_rep("Reporte.txt", ios::out);
    arch_rep << al;
    return 0;
}

