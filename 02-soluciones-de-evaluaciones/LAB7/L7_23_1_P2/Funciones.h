/* 
 * File:   Funciones.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 11 de junio de 2023, 13:43
 */
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "alumno.h"
#include "alumnonota.h"
#include "nota.h"
using namespace std;

#ifndef FUNCIONES_H
#define FUNCIONES_H

void cargaralumnos(alumno *lalumnos);
void carganotas(alumnonota* lnotas);
void PasarNota(nota &grade, alumnonota&grade2);
void actualizanotas(alumno *lalumnos, alumnonota *lnotas);
int BuscarVecesCurso(class nota &grade, const nota *notas);
int BuscarUltimoNotaAlumno(alumno &al);
int BuscarAlumno(alumno*lalumnos, int codigo);
void ActualizarAtributosAprobacion(class nota &grade, alumno& al);
void imprimealumnos(alumno*lalumnos);
#endif /* FUNCIONES_H */
