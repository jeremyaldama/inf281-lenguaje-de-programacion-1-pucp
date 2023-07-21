/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Danie
 *
 * Created on 7 de julio de 2023, 13:00
 */

#include <cstdlib>

using namespace std;
#include "ServicioDeSalud.h"
/*
 * 
 */
int main(int argc, char** argv) {
    class ServicioDeSalud servicioDeSalud;
    
    servicioDeSalud.leerMedicinas("Medicinas-Preg01.csv");
    servicioDeSalud.imprimirMedicinas("ReporteMedicinas.txt");
    servicioDeSalud.leerConsultas("Consultas-Preg01.csv");
    servicioDeSalud.imprimePacientes("PruebaConsultas.txt");
    servicioDeSalud.totalizar();
    servicioDeSalud.imprimePacientes("PruebaConsultasTotal.txt");
    cout << "EJECUTA DESTRUCTORES" << endl;
    return 0;
}

