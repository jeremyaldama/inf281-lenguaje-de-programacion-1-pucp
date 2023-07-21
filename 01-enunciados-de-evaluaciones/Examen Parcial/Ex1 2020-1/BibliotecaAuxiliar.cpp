/* 
 * Archivo:   BibliotecaAuxiliar.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 17 de octubre de 2020, 01:30 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibliotecaAuxiliar.h"
#define INCREMENTO 5
using namespace std;

/* pregunta 1*/

void leerDatos (char ***&cursos, int *&codProfesores, char **&profesores) {
    ifstream archC = abrirArchL("Cursos.csv");
    ifstream archP = abrirArchL("Profesores.csv");  
    cursos = nullptr, codProfesores = nullptr;
    leeCursos(cursos,archC);
    leeProfesores(codProfesores,profesores,archP);
}

void leeCursos (char ***&cursos, ifstream &archC) {
    char *codCur, *nombCur, *esp;
    int capC = 0, numCursos = 0;
    while (1) {
        codCur = leeCadena(archC,',');
        if (codCur == nullptr) break;
        nombCur = leeCadena(archC,',');
        esp = leeCadena(archC,'\n');
        if (archC.eof()) break;
        if (capC == numCursos) 
            incrementarEspaciosC(cursos,numCursos,capC);
        cursos[numCursos] = nullptr;
        cursos[numCursos-1] = asignaInfoCurso(codCur,nombCur,esp);
        numCursos++;
    }
}

void leeProfesores (int *&codProfesores, char **&profesores, ifstream &archP) {
    char *nombP, car;
    int capP = 0, numProf = 0, codP;
    while (1) {
        archP >> codP;
        if (archP.eof()) break;
        archP >> car;
        nombP = leeCadena(archP,'\n');
        if (archP.eof()) break;
        if (capP == numProf) incrementarEspaciosP(codProfesores,profesores,numProf,capP);
        codProfesores[numProf] = -1;
        profesores[numProf] = nullptr;
        codProfesores[numProf-1] = codP;
        profesores[numProf-1] = nombP;
        numProf++;
    }
}

void incrementarEspaciosC (char ***&cursos, int &numCursos, int &capC) {
    char ***aux;
    capC += INCREMENTO;
    if (cursos == nullptr) {
        cursos = new char **[capC];
        cursos[0] = nullptr;
        numCursos = 1;
    } else {
        aux = new char **[capC];
        for (int i = 0; i < numCursos ; i++) aux[i] = cursos[i];
        delete cursos;
        cursos = aux;
    }
}

char ** asignaInfoCurso (char *codCur, char *nombCur, char *esp) {
    char **info;
    info = new char *[3];
    info[0] = codCur;
    info[1] = nombCur;
    info[2] = esp;
    return info;
}

void incrementarEspaciosP (int *&codProfesores, char **&profesores, int &numProf, 
        int &capP) {
    int *auxCod;
    char **auxP;
    capP += INCREMENTO;
    if (codProfesores == nullptr) {
        codProfesores = new int [capP];
        profesores = new char *[capP];
        codProfesores[0] = -1;
        profesores[0] = nullptr;
        numProf = 1;
    } else {
        auxCod = new int [capP];
        auxP = new char *[capP];
        for (int i = 0; i < numProf ; i++) {
            auxCod[i] = codProfesores[i];
            auxP[i] = profesores[i];
        } 
        delete codProfesores;
        delete profesores;
        codProfesores = auxCod;
        profesores = auxP;
    }
}

void imprimirDatos (char ***cursos, int *codProfesores, char **profesores) {
    ofstream arch = abrirArchE("ReportePregunta1.txt");
    arch << setw(50) << "CURSOS DE LA INSTITUCION" << endl
            << setw(12) << "CODIGO"
            << setw(15) << "CURSO"
            << setw(50) << "ESPECIALIDAD" << endl;
    for (int i = 0; cursos[i] ; i++) {
        arch << setw(2) << i+1 << ')'
                << setw(10) << cursos[i][0]
                << setw(5) << " "  << left
                << setw(40) << cursos[i][1]
                << cursos[i][2] << right << endl;
    }
    arch << endl << setw(50) << "PROFESORES DE LA INSTITUCION" << endl
            << setw(12) << "CODIGO"
            << setw(15) << "NOMBRE" << endl;
    for (int i = 0; codProfesores[i] != -1 ; i++) {
        arch << setw(2) << i+1 << ')'
                << setw(10) << codProfesores[i]
                << setw(5) << " " 
                << setw(10) << profesores[i] << endl;
    }
}

/* pregunta 2*/

enum Reg {CURSO,HORARIO,NUM_ALUMNOS,PROFESOR,SESIONES};

void leerSesiones (void *&sesiones) {
    ifstream arch = abrirArchL("Sesiones.txt");
    void *buff[200], *sesion, **STsesion;
    int numSesiones = 0;
    while (1) {
        sesion = leeSesion(arch);
        if (sesion == nullptr) break;
        buff[numSesiones] = sesion;       
        numSesiones++;
    }
    buff[numSesiones] = nullptr;
    numSesiones++;
    STsesion = new void *[numSesiones+1];
    for (int i = 0; i < numSesiones ; i++) {
        STsesion[i] = buff[i];
    }
    sesiones = STsesion;
}

void *leeSesion (ifstream &arch) {
    char cod[10], *codCurso, codH[10], *codHorario;
    int codP, num, *codProf, *numAl, *horas;
    void **sesiones;
    arch >> cod;
    if (arch.eof()) return nullptr;
    
    codCurso = asignaCadenaExacta(cod);
    arch >> codH >> num >> codP;
    codHorario = asignaCadenaExacta(codH);
    numAl = new int; codProf = new int;
    *numAl = num; *codProf = codP;
    horas = leeHorariosSesion(arch);
    
    sesiones = new void *[5];
    sesiones[CURSO] = codCurso;
    sesiones[HORARIO] = codHorario;
    sesiones[NUM_ALUMNOS] = numAl;
    sesiones[PROFESOR] = codProf;
    sesiones[SESIONES] = horas;
    return sesiones;
}

int * leeHorariosSesion (ifstream &arch) {
    int *horario, buffHorario[10];
    int dia, hi, mi, hf, mf, numSesiones = 0;
    char car;  
    while (1) {
        arch >> dia >> hi >> car >> mi >> hf >> car >> mf;
        buffHorario[numSesiones] = dia*100000000 + hi*1000000 + mi*10000 + hf*100 + mf;
        numSesiones++;
        if (arch.get() == '\n') break;
    }   
    buffHorario[numSesiones] = -1;
    numSesiones++;
    horario = new int [10];
    for (int i = 0; i < numSesiones ; i++) horario[i] = buffHorario[i];
    return horario;
}

void imprimirSesiones (void *sesiones) {
    void **sesion = (void**)sesiones;
    ofstream arch = abrirArchE("ReportePregunta2.txt");
    arch << setw(50) << "SESIONES DE CLASE" << endl;
    for (int i = 0; sesion[i] ; i++) {
        imprimirSesion(sesion[i],arch,i);
    }
}

void imprimirSesion (void *clase, ofstream &arch, int i) {
    void **s = (void**)clase;
    char *codCurso = (char *)(s[CURSO]);
    char *codHorario = (char *)(s[HORARIO]);
    int *numAl = (int *)(s[NUM_ALUMNOS]);
    int *codProf = (int *)(s[PROFESOR]);
    int *horas = (int *)s[SESIONES];
    
    arch << setw(2) << i+1 << ')' << setw(10) << "CODIGO: "
            << codCurso
            << setw(15) << "HORARIO: "
            << codHorario
            << setw(20) << "No. Alumnos: "
            << *numAl
            << setw(15) << "PROFESOR: "
            << *codProf << endl << setw(14) << "SESIONES:" << endl;
    imprimeHoras(horas,arch);
    arch << endl;
}

void imprimeHoras (int *horas, ofstream &arch) {
    for (int i = 0; horas[i] != -1 ; i++) {
        formatoHorario(horas[i],arch);
    }
}

void formatoHorario (int datoNum, ofstream &arch) {
    int mf = datoNum%100;
    datoNum /= 100;
    int hf = datoNum%100;
    datoNum /= 100;
    int mi = datoNum%100;
    datoNum /= 100;
    int hi = datoNum%100;
    datoNum /= 100;
    int dia = datoNum;
    arch << setw(10) << "DIA: " << left;
    if (dia == 1) arch << setw(10) << "LUNES";
    else if (dia == 2) arch << setw(10) << "MARTES";
    else if (dia == 3) arch << setw(10) << "MIERCOLES";
    else if (dia == 4) arch << setw(10) << "JUEVES";
    else if (dia == 5) arch << setw(10) << "VIERNES";
    else if (dia == 6) arch << setw(10) << "SABADO";
    else arch << setw(10) << "DOMINGO";
    arch << right << setw(20) << "INICIO: ";
    arch.fill('0');
    arch << setw(2) << hi << ':' << setw(2) << mi;
    arch.fill(' ');
    arch << setw(15) << "FIN: ";
    arch.fill('0');
    arch << setw(2) << hf << ':' << setw(2) << mf;
    arch.fill(' ');
    arch << endl;
}

/* pregunta 3 */

void reporteCargaHorariaDeProf (char ***cursos, int *codProfesores, char **profesores,
        void *sesiones) {
    ofstream arch = abrirArchE("ReportePregunta3.txt");
    void **sesion = (void**)sesiones;    
    arch << setw(60) << "CARGA HORARIA DE PROFESORES" << endl;
    for (int i = 0; codProfesores[i] != -1 ; i++) {
        arch << "Codigo: " << codProfesores[i]
                << setw(15) << "Nombre: " << profesores[i] << endl
                << "Horarios asignados:" << endl
                << "No." << setw(10) << "Curso" 
                << setw(38) << "Codigo"
                << setw(22) << "Especialidad" << endl;
        int cont = 0;
        for (int j = 0; sesion[j] ; j++) {
            imprimirSesionProfesor(sesion[j],cont,codProfesores[i],cursos,arch);
        }
        arch << endl;
    }
}

void imprimirSesionProfesor (void *clase, int &cont, int codP, char ***cursos, 
        ofstream &arch) {
    void **s = (void**)clase;
    char *codCurso = (char *)(s[CURSO]);
    char *codHorario = (char *)(s[HORARIO]);
    int *numAl = (int *)(s[NUM_ALUMNOS]);
    int *codProf = (int *)(s[PROFESOR]);
    int *horas = (int *)s[SESIONES];
    if (*codProf == codP) {
        int pos = buscarCurso(codCurso,cursos);
        arch << setw(2) << cont+1 << ")  " 
                << left << setw(40) << cursos[pos][1]
                << setw(15) << codCurso
                << cursos[pos][2] << endl
                << right << setw(15) << "Horario: " << codHorario << endl;
        imprimirHorasProfesor(horas,*numAl,arch);
        cont++;
    }
}

int buscarCurso (char *codCurso, char ***cursos) {
    for (int i = 0; cursos[i] ; i++) {
        if (strcmp(codCurso,cursos[i][0]) == 0) return i;
    }
}

void imprimirHorasProfesor (int *horas, int numAl, ofstream &arch) {
    int totalHoras = 0;
    for (int i = 0; horas[i] != -1 ; i++) {
        arch << setw(6) << i+1 << ") ";
        formatoHorarioProfesor(horas[i],arch,totalHoras);       
    }
    arch << setw(5) << " " << "Horas dictadas: ";
    arch.fill('0');
    arch << setw(2) << totalHoras/60 << ':' << setw(2) << totalHoras%60 << endl;
    arch.fill(' ');
    arch << setw(5) << " " << "Matriculados: " << numAl << endl << endl;
}

void formatoHorarioProfesor (int datoNum, ofstream &arch, int &totalHoras) {
    int mf = datoNum%100;
    datoNum /= 100;
    int hf = datoNum%100;
    datoNum /= 100;
    int mi = datoNum%100;
    datoNum /= 100;
    int hi = datoNum%100;
    datoNum /= 100;
    int dia = datoNum;
    arch << left;
    if (dia == 1) arch << setw(10) << "Lunes";
    else if (dia == 2) arch << setw(10) << "Martes";
    else if (dia == 3) arch << setw(10) << "Miercoles";
    else if (dia == 4) arch << setw(10) << "Jueves";
    else if (dia == 5) arch << setw(10) << "Viernes";
    else if (dia == 6) arch << setw(10) << "Sabado";
    else arch << setw(10) << "Domingo";
    arch << right;
    arch.fill('0');
    arch << setw(2) << hi << ':' << setw(2) << mi;
    arch.fill(' '); 
    arch << setw(5) << " ";
    arch.fill('0');
    arch << setw(2) << hf << ':' << setw(2) << mf;
    arch.fill(' ');
    arch << endl;
    totalHoras += (hf*60+mf)-(hi*60+mi);
}

/* funciones auxliares */

void imprimeLinea (char car, int num, ofstream &arch) {
    for (int i = 0; i < num; i++) arch.put(car);
    arch << endl;
}

ifstream abrirArchL (const char *nombre) {
    ifstream arch;
    arch.open(nombre, ios::in);
    if (!arch) {
        cout << "ERROR: no se pudo abrir el archivo " << nombre << endl;
        exit(1);
    }
    return arch;
} 

ofstream abrirArchE (const char *nombre) {
    ofstream arch;
    arch.open(nombre, ios::out);
    if (!arch) {
        cout << "ERROR: no se pudo abrir el archivo " << nombre << endl;
        exit(1);
    }
    return arch;
} 

char * leeCadena (ifstream &arch, char car) {
    char buff[200], *cad;
    arch.getline(buff,200,car);
    if (arch.eof()) return nullptr;
    cad = new char [strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

char * asignaCadenaExacta (char *cadena){
    int len;
    char *cad;
    len = strlen(cadena);
    cad = new char[len+1];
    strcpy(cad,cadena);
    return cad;
}