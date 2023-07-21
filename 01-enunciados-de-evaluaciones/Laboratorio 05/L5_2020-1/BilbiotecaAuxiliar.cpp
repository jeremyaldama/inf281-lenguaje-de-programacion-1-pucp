/* 
 * Archivo:   BilbiotecaAuxiliar.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 20 de octubre de 2020, 04:25 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibliotecaAuxiliar.h"
#define INCREMENTO 5
using namespace std;

enum alumno {CODIGO,NOMBRE,CRED,CRED_AP,NUM_CURSOS,NOTAS,LISTA_CURSOS_AP};

void leerAlumnos (void *&alumnos) {
    ifstream arch = abrirArchL("Alumnos.csv");
    void *al, *buffAl[200], **alumno;
    int cantAl = 0;
    while (1) {
        al = leeAlumno(arch);
        if (al == nullptr) break;
        buffAl[cantAl] = al;
        cantAl++;
    }
    buffAl[cantAl] = nullptr;
    cantAl++;
    alumno = new void *[cantAl];
    for (int i = 0; i < cantAl ; i++) alumno[i] = buffAl[i];
    alumnos = alumno;
}

void *leeAlumno (ifstream &arch) {
    void **infoAlumno;
    int cod, *codigo, *num_cursos;
    double *cred, *cred_ap, *suma_notas;
    char tipo, car, *nomb, buff[100];
    arch >> tipo;
    if (arch.eof()) return nullptr;
    arch >> car >> cod >> car;
    codigo = new int; *codigo = cod; 
    cred_ap = new double; cred = new double; 
    num_cursos = new int; suma_notas = new double;
    *cred = 0, *cred_ap = 0, *num_cursos = 0, *suma_notas = 0;
    nomb = leeCadena(arch,',');
    arch >> buff; arch.get();
    infoAlumno = new void *[7];
    infoAlumno[CODIGO] = codigo;   
    infoAlumno[NOMBRE] = nomb;   
    infoAlumno[CRED] = cred;   
    infoAlumno[CRED_AP] = cred_ap;   
    infoAlumno[NUM_CURSOS] = num_cursos;   
    infoAlumno[NOTAS] = suma_notas;   
    infoAlumno[LISTA_CURSOS_AP] = nullptr;  
    return infoAlumno;
}

void imprimirAlumnos (void *alumnos) {
    ofstream arch = abrirArchE("ReporteAlumnos.txt");
    arch.precision(2); arch << fixed;
    void **alumno = (void **)alumnos;
    arch << setw(10) << "CODIGO" << setw(20) << "NOMBRE"
            << setw(35) << "CANT. CRED"
            << setw(20) << "CANT. CRED. AP"
            << setw(15) << "NUM. CURSOS"
            << setw(22) << "SUMA POND. DE NOTAS" << endl;
    imprimeLinea('=',120,arch);
    for (int i = 0; alumno[i] ; i++) {
        imprimeAlumno(alumno[i],arch);
    }
}

void imprimeAlumno (void *alum, ofstream &arch) {
    void **alumno = (void **)alum;
    int *codigo = (int *)alumno[CODIGO];
    char *nombre = (char *)alumno[NOMBRE];
    double *cred = (double *)alumno[CRED];
    double *credap = (double *)alumno[CRED_AP];
    int *cant = (int *)alumno[NUM_CURSOS];
    double *suma = (double *)alumno[NOTAS];
    arch << setw(10) << *codigo
            << setw(5) << " "
            << left << setw(35) << nombre
            << right << setw(12) << *cred
            << setw(17) << *credap
            << setw(17) << *cant
            << setw(17) << *suma << endl;
}

void leerCursos (void *alumnos) {
    ifstream arch = abrirArchL("Cursos.csv");
    int codigo, nota, ciclo, num, pos, cap[200] = {0};
    double cred;
    char *codCur, car;
    void **alumno = (void **)alumnos;
    while (1) {
        arch >> codigo;
        if (arch.eof()) break;
        arch >> car;
        codCur = leeCadena(arch,',');
        arch >> nota >> car >> num >> car >> num >> car >> cred >> car >> car;
        pos = buscarAlumno(alumnos,codigo);
        if (pos != -1) {
            agregarCurso(alumno[pos],cap[pos],codCur,nota,cred);
        }
    }
}

int buscarAlumno (void *alumnos, int codAl) {
    void **alumno = (void **)alumnos;
    int *codAlumno;
    for (int i = 0; alumno[i] ; i++) {
        if (igual_codigo(alumno[i],codAl)) return i;
    }
    return -1;
}

bool igual_codigo (void *alum, int codAl) {
    void **alumno = (void **)alum;
    int *codigo = (int *)alumno[CODIGO];
    return *codigo == codAl;
}

void agregarCurso (void *alum, int &cap, char *codCur, int nota, double credito) {
    void **alumno = (void **)alum;
    int *numCursos = (int *)alumno[NUM_CURSOS];
    double *cred = (double *)alumno[CRED];
    double *cred_ap = (double *)alumno[CRED_AP];
    double *suma_notas = (double *)alumno[NOTAS];
    char **listaDeCursos = (char **)(alumno[LISTA_CURSOS_AP]);    
    if (nota >= 11) {
        if (*numCursos == 0 || *numCursos == cap) 
            incrementarEspacios(listaDeCursos,numCursos,cap);
        listaDeCursos[*numCursos] = codCur;
        *cred_ap += credito;
        (*numCursos)++;
    }      
    *cred += credito;  
    *suma_notas += nota*credito;
    alumno[NUM_CURSOS] = numCursos;
    alumno[CRED] = cred;
    alumno[CRED_AP] = cred_ap;
    alumno[NOTAS] = suma_notas;
    alumno[LISTA_CURSOS_AP] = listaDeCursos;
}

void incrementarEspacios (char **&listaDeCursos, int *numCursos, int &cap) {
    char **aux;
    cap += INCREMENTO;
    if (listaDeCursos == nullptr) {
        listaDeCursos = new char *[cap];
    } else {
        aux = new char *[cap];
        for (int i = 0; i < *numCursos ; i++) {
            aux[i] = listaDeCursos[i];
        }
        delete listaDeCursos;
        listaDeCursos = aux;
    }
}

void consolidado (void *alumnos) {
    ofstream arch = abrirArchE("ReporteConsolidado.txt");
    arch.precision(2); arch << fixed;
    void **alumno = (void **)alumnos;
    for (int i = 0; alumno[i]; i++) {
        imprimirAlumno(alumno[i],arch);
    }
}

void imprimirAlumno(void *alum, ofstream &arch) {
    void **alumno = (void **)alum;
    int *codigo = (int *)alumno[CODIGO];
    char *nombre = (char *)alumno[NOMBRE];
    int *numCursos = (int *)alumno[NUM_CURSOS];
    double *cred = (double *)alumno[CRED];
    double *cred_ap = (double *)alumno[CRED_AP];
    double *suma_notas = (double *)alumno[NOTAS];
    char **listaDeCursos = (char **)(alumno[LISTA_CURSOS_AP]);
    arch << "Codigo: " << setw(17) << " ";
    arch.fill('0'); arch << setw(8) << *codigo; arch.fill(' ');
    arch << setw(5) << " " 
            << "Nombre: " << left << setw(35) << nombre
            << right << setw(10) << "Cred: "
            << setw(5) << *cred << setw(15) << "Cred. Apro: " << setw(5) << *cred_ap
            << setw(15) << "Prom. Gene.: " << setw(5) << (*suma_notas)/(*cred) << endl
            << "Cursos Aprobados: " << setw(5) << " ";
    for (int i = 0; i < *numCursos; i++) {
        arch << setw(8) << listaDeCursos[i];
    }
    arch << endl << endl;
}

/* funciones auxiliares */

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
