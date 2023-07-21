/* 
 * Archivo:   FuncionesAuxiliares.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 29 de octubre de 2020, 11:48 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesAuxiliares.h"
#define MAX_CAR 140
using namespace std;

void imprimeLinea (char car, int num) { // ============================
    for (int i = 0; i < num; i++) 
        cout.put(car);
    cout << endl;
}

void formato (char *cadena) { // Oscar/Duenas -> Oscar Duenas
    int len = strlen(cadena);
    for (int i = 0; i < len; i++) {
        if (cadena[i] == '/' || cadena[i] == '-') cadena[i] = ' ';
    }
}

void leerAlumno (int codAl, int &anioIngreso) {
    char nombre[50], car;
    int codAlumno;
    if (codAl == -1) cin >> codAlumno;
    else codAlumno = codAl;
    cin >> car >> anioIngreso >> nombre;
    formato(nombre);
    imprimeLinea('=',MAX_CAR);
    cout << setw(15) << "Alumno: " << left << setw(50) << nombre
            << right << setw(30) << "Codigo: " << anioIngreso
            << '-' << setfill('0') << setw(4) << codAlumno << setfill(' ') << endl; 
    imprimeCabecera();
}

void imprimeCabecera () {
    imprimeLinea('-',MAX_CAR);
    cout << setw(30) << "CURSOS APROBADOS" 
            << setw(70) << "CURSOS DESAPROBADOS"
            << setw(35) << "OBSERVACION" << endl 
            << "No." << setw(10) << "CODIGO"
            << setw(15) << "CREDITOS"
            << setw(10) << "NOTA"
            << setw(15) << "FECHA"
            << setw(20) << "CODIGO"
            << setw(15) << "CREDITOS"
            << setw(10) << "NOTA"
            << setw(15) << "FECHA" << endl;
    imprimeLinea('-',MAX_CAR);
}

void procesarCursos (int &codAl, int anioIngreso) {
    char curso[10], car;
    double cred, creditos_aprobados = 0, total_creditos = 0, promedio_general = 0, 
            promedio_aprobados = 0;
    int nota, dd, mm, aa, cursos_matriculados = 0, error = 0, No = 1;
    while (1) {
        cin >> codAl;
        // si es fin de archivo o cambiamos de alumno, acaba la iteracion
        if (cin.eof()) break;
        if (cin.fail()) {
            cin.clear();
            cin >> curso >> cred >> nota >> dd >> car >> mm >> car >> aa;
            imprimirRegistro(cursos_matriculados,creditos_aprobados,total_creditos,
                promedio_general,promedio_aprobados,error,dd,mm,aa,anioIngreso,
                curso,nota,cred,No);
            No++;
        } else break;     
    }
    imprimeLinea('=',MAX_CAR);
    imprimirResumen(cursos_matriculados,creditos_aprobados,total_creditos,
            promedio_general,promedio_aprobados,error);
}

void imprimirRegistro (int &cursos_matriculados, double &creditos_aprobados, 
        double &total_creditos, double &promedio_general, double &promedio_aprobados, 
        int &error, int dd, int mm, int aa, int anioIngreso, char *curso, int nota, 
        double cred, int No) {
    cout << setfill('0') << setw(3) << No << setfill(' '); 
    if (nota < 11) cout << setw(60) << " ";
    cout << setw(10) << curso << setw(12) << cred
            << setw(10) << nota
            << setw(15) << aa << '/'
            << setfill('0') << setw(2) << mm << '/'
            << setw(2) << dd << setfill(' ');
    if (anioIngreso > aa) { // error
        error++;
        if (nota >= 11) cout << setw(60) << " ";
        cout << setw(20) << "ERROR FECHA";
    } else { 
        // solo tomamos en cuenta registros con anios validos
        if (nota >= 11) {
            creditos_aprobados += cred; 
            promedio_aprobados += nota*cred; // promedio ponderado
        }       
        cursos_matriculados++;
        promedio_general += nota*cred;
        total_creditos += cred;
    }
    cout << endl;
}

void imprimirResumen (int cursos_matriculados, double creditos_aprobados, 
        double total_creditos, double promedio_general, double promedio_aprobados,
        int error) {
    cout << setw(16) << "RESUMEN:" << endl
            << setw(8) << " " << "Cursos matriculados:  "
            << left << setw(20) << cursos_matriculados
            << setw(30) << "Total de creditos: " << total_creditos << endl
            << setw(8) << " " << "Creditos aprobados:   "
            << setw(20) << creditos_aprobados
            <<  setw(30) << "Creditos desaprobados: " 
            << total_creditos-creditos_aprobados << endl
            << setw(8) << " " << "Creditos aprobados/matriculados: ";
    if (total_creditos == 0) cout << "NA" << '%' << endl;
    else cout << creditos_aprobados/total_creditos*100 << '%' << endl;
    imprimeLinea('-',MAX_CAR);
    cout << setw(8) << " "  << setw(35) << "Promedio general: ";
    if (total_creditos == 0) cout << "NA" << endl;
    else cout << promedio_general/total_creditos << endl;
    cout << setw(8) << " " << setw(35) << "Promedio general de aprobados: ";
    if (creditos_aprobados == 0) cout << "NA" << endl;
    else cout<< promedio_aprobados/creditos_aprobados << endl;
    imprimeLinea('-',MAX_CAR);
    cout << setw(8) << " " << setw(30) << "Cursos con error no considerados: "
             << setfill('0') << right << setw(2) << error << setfill(' ') << endl;
}