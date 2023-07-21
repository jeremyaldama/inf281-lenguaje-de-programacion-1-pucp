/* 
 * Archivo:   main.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 13 de diciembre de 2020, 11:34 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Paper.h"
#include "ConferencePaper.h"
#include "JournalPaper.h"

int main(int argc, char** argv) {
    class Paper * lstPapers[100];
    ifstream archIn("Papers.csv", ios::in);
    if (!archIn) {
        cout << "ERROR: No se pudo abrir el archivo Papers.csv" << endl;
        exit(1);
    }
    ofstream archOut("Reporte.txt", ios::out);
    if (!archOut) {
        cout << "ERROR: No se pudo abrir el archivo Reporte.txt" << endl;
        exit(1);
    }
    int i = 0;
    char tipo;
    while (1) {
        archIn >> tipo;
        if (archIn.eof()) break;
        archIn.get();
        if (tipo == 'C') {           
            lstPapers[i] = new ConferencePaper;
            lstPapers[i]->leer_datos(archIn);
        } else {
            lstPapers[i] = new JournalPaper;
            lstPapers[i]->leer_datos(archIn);
        }
        i++;
    }
    for (int j = 0; j < i ; j++) {
        lstPapers[j]->citar(archOut);
        archOut << endl;
    }
    return (EXIT_SUCCESS);
}
