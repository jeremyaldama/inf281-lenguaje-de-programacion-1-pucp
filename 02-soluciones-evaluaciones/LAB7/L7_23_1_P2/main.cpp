/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 11 de junio de 2023, 11:23
 */

#include <iostream>
#include <iomanip>
#include "Funciones.h"
#include "alumno.h"
#include "alumnonota.h"

using namespace std;

int main(int argc, char** argv) {
    alumno lalumnos[100];
    alumnonota lnotas[200];
    cargaralumnos(lalumnos);
    carganotas(lnotas);
    
    actualizanotas(lalumnos, lnotas);
    
    imprimealumnos(lalumnos);
    
    nota p1;
    char cad[100], cad2[100];
    
    p1.SetCiclo(-1);
    p1.SetCodcurso("prueba");
    p1.GetCodcurso(cad);
    cout << p1.GetCiclo() << " " << cad << endl;
    nota p2;
    cout << p2.GetCiclo() << endl;
    p2 = p1;
    p2.GetCodcurso(cad2);
    cout << p2.GetCiclo() << " " << cad2 << endl;
    nota p3 = p2;
    return 0;
}

