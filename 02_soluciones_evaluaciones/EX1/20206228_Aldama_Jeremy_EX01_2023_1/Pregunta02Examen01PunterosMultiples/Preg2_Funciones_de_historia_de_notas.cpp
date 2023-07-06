/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include <cstring>
#include "Preg2_Funciones_de_historia_de_notas.h"
#define MAX_CUR 100

void cargarNotas(char***&cursos_cod, int***&cursos_nota_sem_veces, 
        double**&costos, int**alumnos, char***alumnos_nom_mod, double*escalas, 
        char***cursos, double*cursos_cred, const char*nom){
    ifstream arch(nom, ios::in);
    if (!arch){
        cout << "NO SE PUDO ABRIR HistoriaDeNotas.csv";
        exit(1);
    }
    
    int cod_al, ciclo, nota, num_al, ind_al, ind_cur;
    for (num_al=0; alumnos[num_al]; num_al++);
    cout << "NUM AL: " << num_al << endl;
    int n_cur_al[num_al]={}, **cur_no_se_v_aux[num_al+1]{};
    char cod_cur[20], **cur_cod_aux[num_al+1]{}, c;
    double *costo_aux[num_al+1]{};
    while (1){
        arch >> cod_al;
        if (arch.eof()) break;
        arch >> c;
        arch.getline(cod_cur, 20, ',');
        arch >> c >> ciclo >> c >> nota;
        
        ind_al = BuscarAlumno(alumnos, cod_al);
        
        if (cur_cod_aux[ind_al] == 0){
            cur_cod_aux[ind_al] = new char*[MAX_CUR]{};
            cur_no_se_v_aux[ind_al] = new int*[MAX_CUR]{};
            costo_aux[ind_al] = new double[MAX_CUR]{};
        }
        ind_cur = BuscarCursoAlumno(cur_cod_aux[ind_al], cod_cur);
        if (ind_cur == -1){
            char**cursos = cur_cod_aux[ind_al];
            cursos[n_cur_al[ind_al]] = new char[strlen(cod_cur)+1];
            strcpy(cursos[n_cur_al[ind_al]], cod_cur);
            cout << cursos[n_cur_al[ind_al]] << endl;
            
            int**infos = cur_no_se_v_aux[ind_al];
            infos[n_cur_al[ind_al]] = new int[3]{};
            int *info = infos[n_cur_al[ind_al]];
            info[0] = nota;
            info[1] = ciclo;
            info[2] = 1;
            
            double *costos = costo_aux[ind_al];
//            costo = ObtenerCosto(cod_cur, )
//            costos[n_cur_al[ind_al]] += 
            
            n_cur_al[ind_al]++;
        }
        else{
            int**infos = cur_no_se_v_aux[ind_al];
            int *info = infos[ind_cur];
            info[0] = nota;
            info[1] = ciclo;
            info[2]++;
        }
        cout << endl;
    }
    
//    AgregarCursos(cursos_cod, cursos_nota_sem_veces, costos, cur_cod_aux,
//            cur_no_se_v_aux, costo_aux, n_cur_al, num_al);
}

void AgregarCursos(char***&cursos_cod, int***&cursos_nota_sem_veces, 
        double**&costos, char***cur_cod_aux, int***cur_no_se_v_aux, 
        double**costo_aux, int*n_cur_al, int n){
    cursos_cod = new char**[n+1]{};
    cursos_nota_sem_veces = new int**[n+1]{};
    costos = new double*[n+1]{};
    int n_c;
    for (int i=0; i<n; i++){
//        cout << "ALUMNO: " << 
        n_c = ObtenerNumCursos(cur_cod_aux[i]);
        cursos_cod[i] = new char*[n_c+1]{};
        char**curso = cursos_cod[i];
        char **curso_aux = cur_cod_aux[i];
//        for (int j = 0; j<n_c; j++){
//            curso[j] = curso_aux[j];
//        }
        delete cur_cod_aux[i];
    }
}

int ObtenerNumCursos(char**cur_cod){
    int i;
    for (i=0; cur_cod[i]; i++){
//        cout << cur_cod[i] << endl;
    }
//    cout << "fin " << i << endl;
    return i;
}

int BuscarCursoAlumno(char**cur_cod, char*cod_cur){
    for (int i=0; cur_cod[i]; i++){
        if (strcmp(cur_cod[i], cod_cur) == 0) return i;
    }
    return -1;
}

int BuscarAlumno(int**alumnos, int cod_al){
    for (int i=0; alumnos[i]; i++){
        int*al = alumnos[i];
        if (al[0] == cod_al) return i;
    }
    return -1;
}

void pruebaDeCargaDeNotas(char***cursos_cod, int***cursos_nota_sem_veces, 
        double**costos, int**alumnos, char***alumnos_nom_mod, const char*nom){
    ofstream arch(nom, ios::out);
    if (!arch){
        cout << "NO SE PUDO ABRIR PruebaDeNotas.txt";
        exit(1);
    }
    
    arch << left << setw(12) << "CODIGO 2" <<
            setw(10) << "ESCALA"  << setw(60) <<
            "NOMBRE" << setw(12) << "MODALIDAD"  << "PORCENTAJE" << endl;
    for (int i=0; alumnos[i]; i++){
        arch << setw(12) << setw(12) << alumnos[i][0] <<
                setw(10) << alumnos[i][1];
        arch << setw(60) << alumnos_nom_mod[i][0] << setw(12) <<
                alumnos_nom_mod[i][1];
        if (alumnos_nom_mod[i][1][0]=='S'){
            arch << alumnos[i][2] << endl;
        }
        else arch << endl;
        
        arch << "CURSOS: " << endl;
        
//        for (int j = 0; cursos_cod)
    }
}